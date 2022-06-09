/* ************************************************************************
 * Copyright (C) 2016-2022 Advanced Micro Devices, Inc. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell cop-
 * ies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IM-
 * PLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNE-
 * CTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ************************************************************************ */
#include "rocblas_herkx.hpp"
#include "logging.hpp"
#include "utility.hpp"

#define CHERKX_MIN_NB 32
#define ZHERKX_MIN_NB 32

namespace
{
    template <typename>
    constexpr char rocblas_herkx_name[] = "unknown";
    template <>
    constexpr char rocblas_herkx_name<rocblas_float_complex>[] = "rocblas_cherkx";
    template <>
    constexpr char rocblas_herkx_name<rocblas_double_complex>[] = "rocblas_zherkx";

    template <rocblas_int NB, typename T>
    rocblas_status rocblas_herkx_impl(rocblas_handle    handle,
                                      rocblas_fill      uplo,
                                      rocblas_operation trans,
                                      rocblas_int       n,
                                      rocblas_int       k,
                                      const T*          alpha,
                                      const T*          A,
                                      rocblas_int       lda,
                                      const T*          B,
                                      rocblas_int       ldb,
                                      const real_t<T>*  beta,
                                      T*                C,
                                      rocblas_int       ldc)
    {
        if(!handle)
            return rocblas_status_invalid_handle;

        RETURN_ZERO_DEVICE_MEMORY_SIZE_IF_QUERIED(handle);

        // Copy alpha and beta to host if on device. This is because gemm is called and it
        // requires alpha and beta to be on host
        T         alpha_h;
        real_t<T> beta_h;
        RETURN_IF_ROCBLAS_ERROR(
            copy_alpha_beta_to_host_if_on_device(handle, alpha, beta, alpha_h, beta_h, k));
        auto saved_pointer_mode = handle->push_pointer_mode(rocblas_pointer_mode_host);

        auto layer_mode     = handle->layer_mode;
        auto check_numerics = handle->check_numerics;
        if(layer_mode
           & (rocblas_layer_mode_log_trace | rocblas_layer_mode_log_bench
              | rocblas_layer_mode_log_profile))
        {
            auto uplo_letter   = rocblas_fill_letter(uplo);
            auto transA_letter = rocblas_transpose_letter(trans);

            if(layer_mode & rocblas_layer_mode_log_trace)
                log_trace(handle,
                          rocblas_herkx_name<T>,
                          uplo,
                          trans,
                          n,
                          k,
                          LOG_TRACE_SCALAR_VALUE(handle, alpha),
                          A,
                          lda,
                          B,
                          ldb,
                          LOG_TRACE_SCALAR_VALUE(handle, beta),
                          C,
                          ldc);

            if(layer_mode & rocblas_layer_mode_log_bench)
                log_bench(handle,
                          "./rocblas-bench -f herkx -r",
                          rocblas_precision_string<T>,
                          "--uplo",
                          uplo_letter,
                          "--transposeA",
                          transA_letter,
                          "-n",
                          n,
                          "-k",
                          k,
                          LOG_BENCH_SCALAR_VALUE(handle, alpha),
                          "--lda",
                          lda,
                          "--ldb",
                          ldb,
                          LOG_BENCH_SCALAR_VALUE(handle, beta),
                          "--ldc",
                          ldc);

            if(layer_mode & rocblas_layer_mode_log_profile)
                log_profile(handle,
                            rocblas_herkx_name<T>,
                            "uplo",
                            uplo_letter,
                            "trans",
                            transA_letter,
                            "N",
                            n,
                            "K",
                            k,
                            "lda",
                            lda,
                            "ldb",
                            ldb,
                            "ldc",
                            ldc);
        }

        static constexpr rocblas_int    batch_count = 1;
        static constexpr rocblas_stride offset_C = 0, offset_A = 0, offset_B = 0;
        static constexpr rocblas_stride stride_C = 0, stride_A = 0, stride_B = 0;

        rocblas_status arg_status = rocblas_her2k_arg_check(handle,
                                                            uplo,
                                                            trans,
                                                            n,
                                                            k,
                                                            alpha,
                                                            A,
                                                            offset_A,
                                                            lda,
                                                            stride_A,
                                                            B,
                                                            offset_B,
                                                            ldb,
                                                            stride_B,
                                                            beta,
                                                            C,
                                                            offset_C,
                                                            ldc,
                                                            stride_C,
                                                            batch_count);
        if(arg_status != rocblas_status_continue)
            return arg_status;

        static constexpr bool Hermetian = true;
        if(check_numerics)
        {
            bool           is_input = true;
            rocblas_status herkx_check_numerics_status
                = rocblas_her2k_syr2k_check_numerics<Hermetian>(rocblas_herkx_name<T>,
                                                                handle,
                                                                uplo,
                                                                trans,
                                                                n,
                                                                k,
                                                                A,
                                                                lda,
                                                                stride_A,
                                                                B,
                                                                ldb,
                                                                stride_B,
                                                                C,
                                                                ldc,
                                                                stride_C,
                                                                batch_count,
                                                                check_numerics,
                                                                is_input);

            if(herkx_check_numerics_status != rocblas_status_success)
                return herkx_check_numerics_status;
        }

        static constexpr bool BATCHED = false;
        rocblas_status        status  = rocblas_status_success;

        // passing in beta as the same type as alpha for easy code reuse
        const T beta_comp = {*beta, 0};
        status            = rocblas_internal_syrkx_herkx_template<NB, BATCHED, true, T>(handle,
                                                                             uplo,
                                                                             trans,
                                                                             n,
                                                                             k,
                                                                             alpha,
                                                                             A,
                                                                             offset_A,
                                                                             lda,
                                                                             stride_A,
                                                                             B,
                                                                             offset_B,
                                                                             ldb,
                                                                             stride_B,
                                                                             &beta_comp,
                                                                             C,
                                                                             offset_C,
                                                                             ldc,
                                                                             stride_C,
                                                                             batch_count);

        if(status != rocblas_status_success)
            return status;

        if(check_numerics)
        {
            bool           is_input = false;
            rocblas_status herkx_check_numerics_status
                = rocblas_her2k_syr2k_check_numerics<Hermetian>(rocblas_herkx_name<T>,
                                                                handle,
                                                                uplo,
                                                                trans,
                                                                n,
                                                                k,
                                                                A,
                                                                lda,
                                                                stride_A,
                                                                B,
                                                                ldb,
                                                                stride_B,
                                                                C,
                                                                ldc,
                                                                stride_C,
                                                                batch_count,
                                                                check_numerics,
                                                                is_input);

            if(herkx_check_numerics_status != rocblas_status_success)
                return herkx_check_numerics_status;
        }
        return status;
    }

}
/*
 * ===========================================================================
 *    C wrapper
 * ===========================================================================
 */

extern "C" {

#ifdef IMPL
#error IMPL ALREADY DEFINED
#endif

#define IMPL(routine_name_, NB_, S_, T_)                                     \
    rocblas_status routine_name_(rocblas_handle    handle,                   \
                                 rocblas_fill      uplo,                     \
                                 rocblas_operation trans,                    \
                                 rocblas_int       n,                        \
                                 rocblas_int       k,                        \
                                 const T_*         alpha,                    \
                                 const T_*         A,                        \
                                 rocblas_int       lda,                      \
                                 const T_*         B,                        \
                                 rocblas_int       ldb,                      \
                                 const S_*         beta,                     \
                                 T_*               C,                        \
                                 rocblas_int       ldc)                      \
    try                                                                      \
    {                                                                        \
        return rocblas_herkx_impl<NB_>(                                      \
            handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc); \
    }                                                                        \
    catch(...)                                                               \
    {                                                                        \
        return exception_to_rocblas_status();                                \
    }

IMPL(rocblas_cherkx, CHERKX_MIN_NB, float, rocblas_float_complex);
IMPL(rocblas_zherkx, ZHERKX_MIN_NB, double, rocblas_double_complex);

#undef IMPL
#undef CHERKX_MIN_NB
#undef ZHERKX_MIN_NB

} // extern "C"
