
#ifndef _ROCBLAS_FORTRAN_HPP_
#define _ROCBLAS_FORTRAN_HPP_

/*!\file
 *  This file interfaces with our Fortran BLAS interface.
 */

/*
 * ============================================================================
 *     Fortran functions
 * ============================================================================
 */
extern "C" {
// scal
rocblas_status
    rocblas_sscal_fortran(rocblas_handle handle, int n, const float* alpha, float* x, int incx);

rocblas_status
    rocblas_dscal_fortran(rocblas_handle handle, int n, const double* alpha, double* x, int incx);

rocblas_status rocblas_cscal_fortran(rocblas_handle               handle,
                                     int                          n,
                                     const rocblas_float_complex* alpha,
                                     rocblas_float_complex*       x,
                                     int                          incx);

rocblas_status rocblas_zscal_fortran(rocblas_handle                handle,
                                     int                           n,
                                     const rocblas_double_complex* alpha,
                                     rocblas_double_complex*       x,
                                     int                           incx);

rocblas_status rocblas_csscal_fortran(
    rocblas_handle handle, int n, const float* alpha, rocblas_float_complex* x, int incx);

rocblas_status rocblas_zdscal_fortran(
    rocblas_handle handle, int n, const double* alpha, rocblas_double_complex* x, int incx);

// scal_batched
rocblas_status rocblas_sscal_batched_fortran(
    rocblas_handle handle, int n, const float* alpha, float* const x[], int incx, int batch_count);

rocblas_status rocblas_dscal_batched_fortran(rocblas_handle handle,
                                             int            n,
                                             const double*  alpha,
                                             double* const  x[],
                                             int            incx,
                                             int            batch_count);

rocblas_status rocblas_cscal_batched_fortran(rocblas_handle               handle,
                                             int                          n,
                                             const rocblas_float_complex* alpha,
                                             rocblas_float_complex* const x[],
                                             int                          incx,
                                             int                          batch_count);

rocblas_status rocblas_zscal_batched_fortran(rocblas_handle                handle,
                                             int                           n,
                                             const rocblas_double_complex* alpha,
                                             rocblas_double_complex* const x[],
                                             int                           incx,
                                             int                           batch_count);

rocblas_status rocblas_csscal_batched_fortran(rocblas_handle               handle,
                                              int                          n,
                                              const float*                 alpha,
                                              rocblas_float_complex* const x[],
                                              int                          incx,
                                              int                          batch_count);

rocblas_status rocblas_zdscal_batched_fortran(rocblas_handle                handle,
                                              int                           n,
                                              const double*                 alpha,
                                              rocblas_double_complex* const x[],
                                              int                           incx,
                                              int                           batch_count);

// scal_strided_batched
rocblas_status rocblas_sscal_strided_batched_fortran(rocblas_handle handle,
                                                     int            n,
                                                     const float*   alpha,
                                                     float*         x,
                                                     int            incx,
                                                     rocblas_stride stride_x,
                                                     int            batch_count);

rocblas_status rocblas_dscal_strided_batched_fortran(rocblas_handle handle,
                                                     int            n,
                                                     const double*  alpha,
                                                     double*        x,
                                                     int            incx,
                                                     rocblas_stride stride_x,
                                                     int            batch_count);

rocblas_status rocblas_cscal_strided_batched_fortran(rocblas_handle               handle,
                                                     int                          n,
                                                     const rocblas_float_complex* alpha,
                                                     rocblas_float_complex*       x,
                                                     int                          incx,
                                                     rocblas_stride               stride_x,
                                                     int                          batch_count);

rocblas_status rocblas_zscal_strided_batched_fortran(rocblas_handle                handle,
                                                     int                           n,
                                                     const rocblas_double_complex* alpha,
                                                     rocblas_double_complex*       x,
                                                     int                           incx,
                                                     rocblas_stride                stride_x,
                                                     int                           batch_count);

rocblas_status rocblas_csscal_strided_batched_fortran(rocblas_handle         handle,
                                                      int                    n,
                                                      const float*           alpha,
                                                      rocblas_float_complex* x,
                                                      int                    incx,
                                                      rocblas_stride         stride_x,
                                                      int                    batch_count);

rocblas_status rocblas_zdscal_strided_batched_fortran(rocblas_handle          handle,
                                                      int                     n,
                                                      const double*           alpha,
                                                      rocblas_double_complex* x,
                                                      int                     incx,
                                                      rocblas_stride          stride_x,
                                                      int                     batch_count);

// copy
rocblas_status rocblas_scopy_fortran(rocblas_handle handle,
                                     rocblas_int    n,
                                     const float*   x,
                                     rocblas_int    incx,
                                     float*         y,
                                     rocblas_int    incy);

rocblas_status rocblas_dcopy_fortran(rocblas_handle handle,
                                     rocblas_int    n,
                                     const double*  x,
                                     rocblas_int    incx,
                                     double*        y,
                                     rocblas_int    incy);

rocblas_status rocblas_ccopy_fortran(rocblas_handle               handle,
                                     rocblas_int                  n,
                                     const rocblas_float_complex* x,
                                     rocblas_int                  incx,
                                     rocblas_float_complex*       y,
                                     rocblas_int                  incy);

rocblas_status rocblas_zcopy_fortran(rocblas_handle                handle,
                                     rocblas_int                   n,
                                     const rocblas_double_complex* x,
                                     rocblas_int                   incx,
                                     rocblas_double_complex*       y,
                                     rocblas_int                   incy);

// copy_batched
rocblas_status rocblas_scopy_batched_fortran(rocblas_handle     handle,
                                             rocblas_int        n,
                                             const float* const x[],
                                             rocblas_int        incx,
                                             float* const       y[],
                                             rocblas_int        incy,
                                             rocblas_int        batch_count);

rocblas_status rocblas_dcopy_batched_fortran(rocblas_handle      handle,
                                             rocblas_int         n,
                                             const double* const x[],
                                             rocblas_int         incx,
                                             double* const       y[],
                                             rocblas_int         incy,
                                             rocblas_int         batch_count);

rocblas_status rocblas_ccopy_batched_fortran(rocblas_handle                     handle,
                                             rocblas_int                        n,
                                             const rocblas_float_complex* const x[],
                                             rocblas_int                        incx,
                                             rocblas_float_complex* const       y[],
                                             rocblas_int                        incy,
                                             rocblas_int                        batch_count);

rocblas_status rocblas_zcopy_batched_fortran(rocblas_handle                      handle,
                                             rocblas_int                         n,
                                             const rocblas_double_complex* const x[],
                                             rocblas_int                         incx,
                                             rocblas_double_complex* const       y[],
                                             rocblas_int                         incy,
                                             rocblas_int                         batch_count);

// copy_strided_batched
rocblas_status rocblas_scopy_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     const float*   x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stridex,
                                                     float*         y,
                                                     rocblas_int    incy,
                                                     rocblas_stride stridey,
                                                     rocblas_int    batch_count);

rocblas_status rocblas_dcopy_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     const double*  x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stridex,
                                                     double*        y,
                                                     rocblas_int    incy,
                                                     rocblas_stride stridey,
                                                     rocblas_int    batch_count);

rocblas_status rocblas_ccopy_strided_batched_fortran(rocblas_handle               handle,
                                                     rocblas_int                  n,
                                                     const rocblas_float_complex* x,
                                                     rocblas_int                  incx,
                                                     rocblas_stride               stridex,
                                                     rocblas_float_complex*       y,
                                                     rocblas_int                  incy,
                                                     rocblas_stride               stridey,
                                                     rocblas_int                  batch_count);

rocblas_status rocblas_zcopy_strided_batched_fortran(rocblas_handle                handle,
                                                     rocblas_int                   n,
                                                     const rocblas_double_complex* x,
                                                     rocblas_int                   incx,
                                                     rocblas_stride                stridex,
                                                     rocblas_double_complex*       y,
                                                     rocblas_int                   incy,
                                                     rocblas_stride                stridey,
                                                     rocblas_int                   batch_count);

// dot
rocblas_status rocblas_sdot_fortran(rocblas_handle handle,
                                    rocblas_int    n,
                                    const float*   x,
                                    rocblas_int    incx,
                                    const float*   y,
                                    rocblas_int    incy,
                                    float*         result);

rocblas_status rocblas_ddot_fortran(rocblas_handle handle,
                                    rocblas_int    n,
                                    const double*  x,
                                    rocblas_int    incx,
                                    const double*  y,
                                    rocblas_int    incy,
                                    double*        result);

rocblas_status rocblas_hdot_fortran(rocblas_handle      handle,
                                    rocblas_int         n,
                                    const rocblas_half* x,
                                    rocblas_int         incx,
                                    const rocblas_half* y,
                                    rocblas_int         incy,
                                    rocblas_half*       result);

rocblas_status rocblas_bfdot_fortran(rocblas_handle          handle,
                                     rocblas_int             n,
                                     const rocblas_bfloat16* x,
                                     rocblas_int             incx,
                                     const rocblas_bfloat16* y,
                                     rocblas_int             incy,
                                     rocblas_bfloat16*       result);

rocblas_status rocblas_cdotu_fortran(rocblas_handle               handle,
                                     rocblas_int                  n,
                                     const rocblas_float_complex* x,
                                     rocblas_int                  incx,
                                     const rocblas_float_complex* y,
                                     rocblas_int                  incy,
                                     rocblas_float_complex*       result);

rocblas_status rocblas_zdotu_fortran(rocblas_handle                handle,
                                     rocblas_int                   n,
                                     const rocblas_double_complex* x,
                                     rocblas_int                   incx,
                                     const rocblas_double_complex* y,
                                     rocblas_int                   incy,
                                     rocblas_double_complex*       result);

rocblas_status rocblas_cdotc_fortran(rocblas_handle               handle,
                                     rocblas_int                  n,
                                     const rocblas_float_complex* x,
                                     rocblas_int                  incx,
                                     const rocblas_float_complex* y,
                                     rocblas_int                  incy,
                                     rocblas_float_complex*       result);

rocblas_status rocblas_zdotc_fortran(rocblas_handle                handle,
                                     rocblas_int                   n,
                                     const rocblas_double_complex* x,
                                     rocblas_int                   incx,
                                     const rocblas_double_complex* y,
                                     rocblas_int                   incy,
                                     rocblas_double_complex*       result);

// dot_batched
rocblas_status rocblas_sdot_batched_fortran(rocblas_handle     handle,
                                            rocblas_int        n,
                                            const float* const x[],
                                            rocblas_int        incx,
                                            const float* const y[],
                                            rocblas_int        incy,
                                            rocblas_int        batch_count,
                                            float*             result);

rocblas_status rocblas_ddot_batched_fortran(rocblas_handle      handle,
                                            rocblas_int         n,
                                            const double* const x[],
                                            rocblas_int         incx,
                                            const double* const y[],
                                            rocblas_int         incy,
                                            rocblas_int         batch_count,
                                            double*             result);

rocblas_status rocblas_hdot_batched_fortran(rocblas_handle            handle,
                                            rocblas_int               n,
                                            const rocblas_half* const x[],
                                            rocblas_int               incx,
                                            const rocblas_half* const y[],
                                            rocblas_int               incy,
                                            rocblas_int               batch_count,
                                            rocblas_half*             result);

rocblas_status rocblas_bfdot_batched_fortran(rocblas_handle                handle,
                                             rocblas_int                   n,
                                             const rocblas_bfloat16* const x[],
                                             rocblas_int                   incx,
                                             const rocblas_bfloat16* const y[],
                                             rocblas_int                   incy,
                                             rocblas_int                   batch_count,
                                             rocblas_bfloat16*             result);

rocblas_status rocblas_cdotu_batched_fortran(rocblas_handle                     handle,
                                             rocblas_int                        n,
                                             const rocblas_float_complex* const x[],
                                             rocblas_int                        incx,
                                             const rocblas_float_complex* const y[],
                                             rocblas_int                        incy,
                                             rocblas_int                        batch_count,
                                             rocblas_float_complex*             result);

rocblas_status rocblas_zdotu_batched_fortran(rocblas_handle                      handle,
                                             rocblas_int                         n,
                                             const rocblas_double_complex* const x[],
                                             rocblas_int                         incx,
                                             const rocblas_double_complex* const y[],
                                             rocblas_int                         incy,
                                             rocblas_int                         batch_count,
                                             rocblas_double_complex*             result);

rocblas_status rocblas_cdotc_batched_fortran(rocblas_handle                     handle,
                                             rocblas_int                        n,
                                             const rocblas_float_complex* const x[],
                                             rocblas_int                        incx,
                                             const rocblas_float_complex* const y[],
                                             rocblas_int                        incy,
                                             rocblas_int                        batch_count,
                                             rocblas_float_complex*             result);

rocblas_status rocblas_zdotc_batched_fortran(rocblas_handle                      handle,
                                             rocblas_int                         n,
                                             const rocblas_double_complex* const x[],
                                             rocblas_int                         incx,
                                             const rocblas_double_complex* const y[],
                                             rocblas_int                         incy,
                                             rocblas_int                         batch_count,
                                             rocblas_double_complex*             result);

// dot_strided_batched
rocblas_status rocblas_sdot_strided_batched_fortran(rocblas_handle handle,
                                                    rocblas_int    n,
                                                    const float*   x,
                                                    rocblas_int    incx,
                                                    rocblas_stride stridex,
                                                    const float*   y,
                                                    rocblas_int    incy,
                                                    rocblas_stride stridey,
                                                    rocblas_int    batch_count,
                                                    float*         result);

rocblas_status rocblas_ddot_strided_batched_fortran(rocblas_handle handle,
                                                    rocblas_int    n,
                                                    const double*  x,
                                                    rocblas_int    incx,
                                                    rocblas_stride stridex,
                                                    const double*  y,
                                                    rocblas_int    incy,
                                                    rocblas_stride stridey,
                                                    rocblas_int    batch_count,
                                                    double*        result);

rocblas_status rocblas_hdot_strided_batched_fortran(rocblas_handle      handle,
                                                    rocblas_int         n,
                                                    const rocblas_half* x,
                                                    rocblas_int         incx,
                                                    rocblas_stride      stridex,
                                                    const rocblas_half* y,
                                                    rocblas_int         incy,
                                                    rocblas_stride      stridey,
                                                    rocblas_int         batch_count,
                                                    rocblas_half*       result);

rocblas_status rocblas_bfdot_strided_batched_fortran(rocblas_handle          handle,
                                                     rocblas_int             n,
                                                     const rocblas_bfloat16* x,
                                                     rocblas_int             incx,
                                                     rocblas_stride          stridex,
                                                     const rocblas_bfloat16* y,
                                                     rocblas_int             incy,
                                                     rocblas_stride          stridey,
                                                     rocblas_int             batch_count,
                                                     rocblas_bfloat16*       result);

rocblas_status rocblas_cdotu_strided_batched_fortran(rocblas_handle               handle,
                                                     rocblas_int                  n,
                                                     const rocblas_float_complex* x,
                                                     rocblas_int                  incx,
                                                     rocblas_stride               stridex,
                                                     const rocblas_float_complex* y,
                                                     rocblas_int                  incy,
                                                     rocblas_stride               stridey,
                                                     rocblas_int                  batch_count,
                                                     rocblas_float_complex*       result);

rocblas_status rocblas_zdotu_strided_batched_fortran(rocblas_handle                handle,
                                                     rocblas_int                   n,
                                                     const rocblas_double_complex* x,
                                                     rocblas_int                   incx,
                                                     rocblas_stride                stridex,
                                                     const rocblas_double_complex* y,
                                                     rocblas_int                   incy,
                                                     rocblas_stride                stridey,
                                                     rocblas_int                   batch_count,
                                                     rocblas_double_complex*       result);

rocblas_status rocblas_cdotc_strided_batched_fortran(rocblas_handle               handle,
                                                     rocblas_int                  n,
                                                     const rocblas_float_complex* x,
                                                     rocblas_int                  incx,
                                                     rocblas_stride               stridex,
                                                     const rocblas_float_complex* y,
                                                     rocblas_int                  incy,
                                                     rocblas_stride               stridey,
                                                     rocblas_int                  batch_count,
                                                     rocblas_float_complex*       result);

rocblas_status rocblas_zdotc_strided_batched_fortran(rocblas_handle                handle,
                                                     rocblas_int                   n,
                                                     const rocblas_double_complex* x,
                                                     rocblas_int                   incx,
                                                     rocblas_stride                stridex,
                                                     const rocblas_double_complex* y,
                                                     rocblas_int                   incy,
                                                     rocblas_stride                stridey,
                                                     rocblas_int                   batch_count,
                                                     rocblas_double_complex*       result);

// swap
rocblas_status rocblas_sswap_fortran(
    rocblas_handle handle, rocblas_int n, float* x, rocblas_int incx, float* y, rocblas_int incy);

rocblas_status rocblas_dswap_fortran(
    rocblas_handle handle, rocblas_int n, double* x, rocblas_int incx, double* y, rocblas_int incy);

rocblas_status rocblas_cswap_fortran(rocblas_handle         handle,
                                     rocblas_int            n,
                                     rocblas_float_complex* x,
                                     rocblas_int            incx,
                                     rocblas_float_complex* y,
                                     rocblas_int            incy);

rocblas_status rocblas_zswap_fortran(rocblas_handle          handle,
                                     rocblas_int             n,
                                     rocblas_double_complex* x,
                                     rocblas_int             incx,
                                     rocblas_double_complex* y,
                                     rocblas_int             incy);

// swap_batched
rocblas_status rocblas_sswap_batched_fortran(rocblas_handle handle,
                                             rocblas_int    n,
                                             float*         x[],
                                             rocblas_int    incx,
                                             float*         y[],
                                             rocblas_int    incy,
                                             rocblas_int    batch_count);

rocblas_status rocblas_dswap_batched_fortran(rocblas_handle handle,
                                             rocblas_int    n,
                                             double*        x[],
                                             rocblas_int    incx,
                                             double*        y[],
                                             rocblas_int    incy,
                                             rocblas_int    batch_count);

rocblas_status rocblas_cswap_batched_fortran(rocblas_handle         handle,
                                             rocblas_int            n,
                                             rocblas_float_complex* x[],
                                             rocblas_int            incx,
                                             rocblas_float_complex* y[],
                                             rocblas_int            incy,
                                             rocblas_int            batch_count);

rocblas_status rocblas_zswap_batched_fortran(rocblas_handle          handle,
                                             rocblas_int             n,
                                             rocblas_double_complex* x[],
                                             rocblas_int             incx,
                                             rocblas_double_complex* y[],
                                             rocblas_int             incy,
                                             rocblas_int             batch_count);

// swap_strided_batched
rocblas_status rocblas_sswap_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     float*         x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stridex,
                                                     float*         y,
                                                     rocblas_int    incy,
                                                     rocblas_stride stridey,
                                                     rocblas_int    batch_count);

rocblas_status rocblas_dswap_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     double*        x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stridex,
                                                     double*        y,
                                                     rocblas_int    incy,
                                                     rocblas_stride stridey,
                                                     rocblas_int    batch_count);

rocblas_status rocblas_cswap_strided_batched_fortran(rocblas_handle         handle,
                                                     rocblas_int            n,
                                                     rocblas_float_complex* x,
                                                     rocblas_int            incx,
                                                     rocblas_stride         stridex,
                                                     rocblas_float_complex* y,
                                                     rocblas_int            incy,
                                                     rocblas_stride         stridey,
                                                     rocblas_int            batch_count);

rocblas_status rocblas_zswap_strided_batched_fortran(rocblas_handle          handle,
                                                     rocblas_int             n,
                                                     rocblas_double_complex* x,
                                                     rocblas_int             incx,
                                                     rocblas_stride          stridex,
                                                     rocblas_double_complex* y,
                                                     rocblas_int             incy,
                                                     rocblas_stride          stridey,
                                                     rocblas_int             batch_count);

// axpy
rocblas_status rocblas_haxpy_fortran(rocblas_handle      handle,
                                     const int           N,
                                     const rocblas_half* alpha,
                                     const rocblas_half* x,
                                     const int           incx,
                                     rocblas_half*       y,
                                     const int           incy);

rocblas_status rocblas_saxpy_fortran(rocblas_handle handle,
                                     const int      N,
                                     const float*   alpha,
                                     const float*   x,
                                     const int      incx,
                                     float*         y,
                                     const int      incy);

rocblas_status rocblas_daxpy_fortran(rocblas_handle handle,
                                     const int      N,
                                     const double*  alpha,
                                     const double*  x,
                                     const int      incx,
                                     double*        y,
                                     const int      incy);

rocblas_status rocblas_caxpy_fortran(rocblas_handle               handle,
                                     const int                    N,
                                     const rocblas_float_complex* alpha,
                                     const rocblas_float_complex* x,
                                     const int                    incx,
                                     rocblas_float_complex*       y,
                                     const int                    incy);

rocblas_status rocblas_zaxpy_fortran(rocblas_handle                handle,
                                     const int                     N,
                                     const rocblas_double_complex* alpha,
                                     const rocblas_double_complex* x,
                                     const int                     incx,
                                     rocblas_double_complex*       y,
                                     const int                     incy);

// axpy_batched
rocblas_status rocblas_haxpy_batched_fortran(rocblas_handle            handle,
                                             const int                 N,
                                             const rocblas_half*       alpha,
                                             const rocblas_half* const x[],
                                             const int                 incx,
                                             rocblas_half* const       y[],
                                             const int                 incy,
                                             const int                 batch_count);

rocblas_status rocblas_saxpy_batched_fortran(rocblas_handle     handle,
                                             const int          N,
                                             const float*       alpha,
                                             const float* const x[],
                                             const int          incx,
                                             float* const       y[],
                                             const int          incy,
                                             const int          batch_count);

rocblas_status rocblas_saxpy_batched_fortran(rocblas_handle     handle,
                                             const int          N,
                                             const float*       alpha,
                                             const float* const x[],
                                             const int          incx,
                                             float* const       y[],
                                             const int          incy,
                                             const int          batch_count);

rocblas_status rocblas_daxpy_batched_fortran(rocblas_handle      handle,
                                             const int           N,
                                             const double*       alpha,
                                             const double* const x[],
                                             const int           incx,
                                             double* const       y[],
                                             const int           incy,
                                             const int           batch_count);

rocblas_status rocblas_caxpy_batched_fortran(rocblas_handle                     handle,
                                             const int                          N,
                                             const rocblas_float_complex*       alpha,
                                             const rocblas_float_complex* const x[],
                                             const int                          incx,
                                             rocblas_float_complex* const       y[],
                                             const int                          incy,
                                             const int                          batch_count);

rocblas_status rocblas_zaxpy_batched_fortran(rocblas_handle                      handle,
                                             const int                           N,
                                             const rocblas_double_complex*       alpha,
                                             const rocblas_double_complex* const x[],
                                             const int                           incx,
                                             rocblas_double_complex* const       y[],
                                             const int                           incy,
                                             const int                           batch_count);

// axpy_strided_batched
rocblas_status rocblas_haxpy_strided_batched_fortran(rocblas_handle       handle,
                                                     const int            N,
                                                     const rocblas_half*  alpha,
                                                     const rocblas_half*  x,
                                                     const int            incx,
                                                     const rocblas_stride stride_x,
                                                     rocblas_half*        y,
                                                     const int            incy,
                                                     const rocblas_stride stride_y,
                                                     const int            batch_count);

rocblas_status rocblas_saxpy_strided_batched_fortran(rocblas_handle       handle,
                                                     const int            N,
                                                     const float*         alpha,
                                                     const float*         x,
                                                     const int            incx,
                                                     const rocblas_stride stride_x,
                                                     float*               y,
                                                     const int            incy,
                                                     const rocblas_stride stride_y,
                                                     const int            batch_count);

rocblas_status rocblas_daxpy_strided_batched_fortran(rocblas_handle       handle,
                                                     const int            N,
                                                     const double*        alpha,
                                                     const double*        x,
                                                     const int            incx,
                                                     const rocblas_stride stride_x,
                                                     double*              y,
                                                     const int            incy,
                                                     const rocblas_stride stride_y,
                                                     const int            batch_count);

rocblas_status rocblas_caxpy_strided_batched_fortran(rocblas_handle               handle,
                                                     const int                    N,
                                                     const rocblas_float_complex* alpha,
                                                     const rocblas_float_complex* x,
                                                     const int                    incx,
                                                     const rocblas_stride         stride_x,
                                                     rocblas_float_complex*       y,
                                                     const int                    incy,
                                                     const rocblas_stride         stride_y,
                                                     const int                    batch_count);

rocblas_status rocblas_zaxpy_strided_batched_fortran(rocblas_handle                handle,
                                                     const int                     N,
                                                     const rocblas_double_complex* alpha,
                                                     const rocblas_double_complex* x,
                                                     const int                     incx,
                                                     const rocblas_stride          stride_x,
                                                     rocblas_double_complex*       y,
                                                     const int                     incy,
                                                     const rocblas_stride          stride_y,
                                                     const int                     batch_count);

// asum
rocblas_status rocblas_sasum_fortran(
    rocblas_handle handle, rocblas_int n, const float* x, rocblas_int incx, float* result);

rocblas_status rocblas_dasum_fortran(
    rocblas_handle handle, rocblas_int n, const double* x, rocblas_int incx, double* result);

rocblas_status rocblas_scasum_fortran(rocblas_handle               handle,
                                      rocblas_int                  n,
                                      const rocblas_float_complex* x,
                                      rocblas_int                  incx,
                                      float*                       result);

rocblas_status rocblas_dzasum_fortran(rocblas_handle                handle,
                                      rocblas_int                   n,
                                      const rocblas_double_complex* x,
                                      rocblas_int                   incx,
                                      double*                       result);

// asum_batched
rocblas_status rocblas_sasum_batched_fortran(rocblas_handle     handle,
                                             rocblas_int        n,
                                             const float* const x[],
                                             rocblas_int        incx,
                                             rocblas_int        batch_count,
                                             float*             results);

rocblas_status rocblas_dasum_batched_fortran(rocblas_handle      handle,
                                             rocblas_int         n,
                                             const double* const x[],
                                             rocblas_int         incx,
                                             rocblas_int         batch_count,
                                             double*             results);

rocblas_status rocblas_scasum_batched_fortran(rocblas_handle                     handle,
                                              rocblas_int                        n,
                                              const rocblas_float_complex* const x[],
                                              rocblas_int                        incx,
                                              rocblas_int                        batch_count,
                                              float*                             results);

rocblas_status rocblas_dzasum_batched_fortran(rocblas_handle                      handle,
                                              rocblas_int                         n,
                                              const rocblas_double_complex* const x[],
                                              rocblas_int                         incx,
                                              rocblas_int                         batch_count,
                                              double*                             results);

// asum_strided_batched
rocblas_status rocblas_sasum_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     const float*   x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stridex,
                                                     rocblas_int    batch_count,
                                                     float*         results);

rocblas_status rocblas_dasum_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     const double*  x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stridex,
                                                     rocblas_int    batch_count,
                                                     double*        results);

rocblas_status rocblas_scasum_strided_batched_fortran(rocblas_handle               handle,
                                                      rocblas_int                  n,
                                                      const rocblas_float_complex* x,
                                                      rocblas_int                  incx,
                                                      rocblas_stride               stridex,
                                                      rocblas_int                  batch_count,
                                                      float*                       results);

rocblas_status rocblas_dzasum_strided_batched_fortran(rocblas_handle                handle,
                                                      rocblas_int                   n,
                                                      const rocblas_double_complex* x,
                                                      rocblas_int                   incx,
                                                      rocblas_stride                stridex,
                                                      rocblas_int                   batch_count,
                                                      double*                       results);

// nrm2
rocblas_status rocblas_snrm2_fortran(
    rocblas_handle handle, rocblas_int n, const float* x, rocblas_int incx, float* result);

rocblas_status rocblas_dnrm2_fortran(
    rocblas_handle handle, rocblas_int n, const double* x, rocblas_int incx, double* result);

rocblas_status rocblas_scnrm2_fortran(rocblas_handle               handle,
                                      rocblas_int                  n,
                                      const rocblas_float_complex* x,
                                      rocblas_int                  incx,
                                      float*                       result);

rocblas_status rocblas_dznrm2_fortran(rocblas_handle                handle,
                                      rocblas_int                   n,
                                      const rocblas_double_complex* x,
                                      rocblas_int                   incx,
                                      double*                       result);

// nrm2_batched
rocblas_status rocblas_snrm2_batched_fortran(rocblas_handle     handle,
                                             rocblas_int        n,
                                             const float* const x[],
                                             rocblas_int        incx,
                                             rocblas_int        batch_count,
                                             float*             results);

rocblas_status rocblas_dnrm2_batched_fortran(rocblas_handle      handle,
                                             rocblas_int         n,
                                             const double* const x[],
                                             rocblas_int         incx,
                                             rocblas_int         batch_count,
                                             double*             results);

rocblas_status rocblas_scnrm2_batched_fortran(rocblas_handle                     handle,
                                              rocblas_int                        n,
                                              const rocblas_float_complex* const x[],
                                              rocblas_int                        incx,
                                              rocblas_int                        batch_count,
                                              float*                             results);

rocblas_status rocblas_dznrm2_batched_fortran(rocblas_handle                      handle,
                                              rocblas_int                         n,
                                              const rocblas_double_complex* const x[],
                                              rocblas_int                         incx,
                                              rocblas_int                         batch_count,
                                              double*                             results);

// nrm2_strided_batched
rocblas_status rocblas_snrm2_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     const float*   x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stridex,
                                                     rocblas_int    batch_count,
                                                     float*         results);

rocblas_status rocblas_dnrm2_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     const double*  x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stridex,
                                                     rocblas_int    batch_count,
                                                     double*        results);

rocblas_status rocblas_scnrm2_strided_batched_fortran(rocblas_handle               handle,
                                                      rocblas_int                  n,
                                                      const rocblas_float_complex* x,
                                                      rocblas_int                  incx,
                                                      rocblas_stride               stridex,
                                                      rocblas_int                  batch_count,
                                                      float*                       results);

rocblas_status rocblas_dznrm2_strided_batched_fortran(rocblas_handle                handle,
                                                      rocblas_int                   n,
                                                      const rocblas_double_complex* x,
                                                      rocblas_int                   incx,
                                                      rocblas_stride                stridex,
                                                      rocblas_int                   batch_count,
                                                      double*                       results);

// amax
rocblas_status rocblas_isamax_fortran(
    rocblas_handle handle, rocblas_int n, const float* x, rocblas_int incx, rocblas_int* result);

rocblas_status rocblas_idamax_fortran(
    rocblas_handle handle, rocblas_int n, const double* x, rocblas_int incx, rocblas_int* result);

rocblas_status rocblas_icamax_fortran(rocblas_handle               handle,
                                      rocblas_int                  n,
                                      const rocblas_float_complex* x,
                                      rocblas_int                  incx,
                                      rocblas_int*                 result);

rocblas_status rocblas_izamax_fortran(rocblas_handle                handle,
                                      rocblas_int                   n,
                                      const rocblas_double_complex* x,
                                      rocblas_int                   incx,
                                      rocblas_int*                  result);

// amax_batched
rocblas_status rocblas_isamax_batched_fortran(rocblas_handle     handle,
                                              rocblas_int        n,
                                              const float* const x[],
                                              rocblas_int        incx,
                                              rocblas_int        batch_count,
                                              rocblas_int*       result);

rocblas_status rocblas_idamax_batched_fortran(rocblas_handle      handle,
                                              rocblas_int         n,
                                              const double* const x[],
                                              rocblas_int         incx,
                                              rocblas_int         batch_count,
                                              rocblas_int*        result);

rocblas_status rocblas_icamax_batched_fortran(rocblas_handle                     handle,
                                              rocblas_int                        n,
                                              const rocblas_float_complex* const x[],
                                              rocblas_int                        incx,
                                              rocblas_int                        batch_count,
                                              rocblas_int*                       result);

rocblas_status rocblas_izamax_batched_fortran(rocblas_handle                      handle,
                                              rocblas_int                         n,
                                              const rocblas_double_complex* const x[],
                                              rocblas_int                         incx,
                                              rocblas_int                         batch_count,
                                              rocblas_int*                        result);

// amax_strided_batched
rocblas_status rocblas_isamax_strided_batched_fortran(rocblas_handle handle,
                                                      rocblas_int    n,
                                                      const float*   x,
                                                      rocblas_int    incx,
                                                      rocblas_stride stridex,
                                                      rocblas_int    batch_count,
                                                      rocblas_int*   result);

rocblas_status rocblas_idamax_strided_batched_fortran(rocblas_handle handle,
                                                      rocblas_int    n,
                                                      const double*  x,
                                                      rocblas_int    incx,
                                                      rocblas_stride stridex,
                                                      rocblas_int    batch_count,
                                                      rocblas_int*   result);

rocblas_status rocblas_icamax_strided_batched_fortran(rocblas_handle               handle,
                                                      rocblas_int                  n,
                                                      const rocblas_float_complex* x,
                                                      rocblas_int                  incx,
                                                      rocblas_stride               stridex,
                                                      rocblas_int                  batch_count,
                                                      rocblas_int*                 result);

rocblas_status rocblas_izamax_strided_batched_fortran(rocblas_handle                handle,
                                                      rocblas_int                   n,
                                                      const rocblas_double_complex* x,
                                                      rocblas_int                   incx,
                                                      rocblas_stride                stridex,
                                                      rocblas_int                   batch_count,
                                                      rocblas_int*                  result);

// amin
rocblas_status rocblas_isamin_fortran(
    rocblas_handle handle, rocblas_int n, const float* x, rocblas_int incx, rocblas_int* result);

rocblas_status rocblas_idamin_fortran(
    rocblas_handle handle, rocblas_int n, const double* x, rocblas_int incx, rocblas_int* result);

rocblas_status rocblas_icamin_fortran(rocblas_handle               handle,
                                      rocblas_int                  n,
                                      const rocblas_float_complex* x,
                                      rocblas_int                  incx,
                                      rocblas_int*                 result);

rocblas_status rocblas_izamin_fortran(rocblas_handle                handle,
                                      rocblas_int                   n,
                                      const rocblas_double_complex* x,
                                      rocblas_int                   incx,
                                      rocblas_int*                  result);

// amin_batched
rocblas_status rocblas_isamin_batched_fortran(rocblas_handle     handle,
                                              rocblas_int        n,
                                              const float* const x[],
                                              rocblas_int        incx,
                                              rocblas_int        batch_count,
                                              rocblas_int*       result);

rocblas_status rocblas_idamin_batched_fortran(rocblas_handle      handle,
                                              rocblas_int         n,
                                              const double* const x[],
                                              rocblas_int         incx,
                                              rocblas_int         batch_count,
                                              rocblas_int*        result);

rocblas_status rocblas_icamin_batched_fortran(rocblas_handle                     handle,
                                              rocblas_int                        n,
                                              const rocblas_float_complex* const x[],
                                              rocblas_int                        incx,
                                              rocblas_int                        batch_count,
                                              rocblas_int*                       result);

rocblas_status rocblas_izamin_batched_fortran(rocblas_handle                      handle,
                                              rocblas_int                         n,
                                              const rocblas_double_complex* const x[],
                                              rocblas_int                         incx,
                                              rocblas_int                         batch_count,
                                              rocblas_int*                        result);

// amin_strided_batched
rocblas_status rocblas_isamin_strided_batched_fortran(rocblas_handle handle,
                                                      rocblas_int    n,
                                                      const float*   x,
                                                      rocblas_int    incx,
                                                      rocblas_stride stridex,
                                                      rocblas_int    batch_count,
                                                      rocblas_int*   result);

rocblas_status rocblas_idamin_strided_batched_fortran(rocblas_handle handle,
                                                      rocblas_int    n,
                                                      const double*  x,
                                                      rocblas_int    incx,
                                                      rocblas_stride stridex,
                                                      rocblas_int    batch_count,
                                                      rocblas_int*   result);

rocblas_status rocblas_icamin_strided_batched_fortran(rocblas_handle               handle,
                                                      rocblas_int                  n,
                                                      const rocblas_float_complex* x,
                                                      rocblas_int                  incx,
                                                      rocblas_stride               stridex,
                                                      rocblas_int                  batch_count,
                                                      rocblas_int*                 result);

rocblas_status rocblas_izamin_strided_batched_fortran(rocblas_handle                handle,
                                                      rocblas_int                   n,
                                                      const rocblas_double_complex* x,
                                                      rocblas_int                   incx,
                                                      rocblas_stride                stridex,
                                                      rocblas_int                   batch_count,
                                                      rocblas_int*                  result);

// rot
rocblas_status rocblas_srot_fortran(rocblas_handle handle,
                                    rocblas_int    n,
                                    float*         x,
                                    rocblas_int    incx,
                                    float*         y,
                                    rocblas_int    incy,
                                    const float*   c,
                                    const float*   s);

rocblas_status rocblas_drot_fortran(rocblas_handle handle,
                                    rocblas_int    n,
                                    double*        x,
                                    rocblas_int    incx,
                                    double*        y,
                                    rocblas_int    incy,
                                    const double*  c,
                                    const double*  s);

rocblas_status rocblas_crot_fortran(rocblas_handle               handle,
                                    rocblas_int                  n,
                                    rocblas_float_complex*       x,
                                    rocblas_int                  incx,
                                    rocblas_float_complex*       y,
                                    rocblas_int                  incy,
                                    const float*                 c,
                                    const rocblas_float_complex* s);

rocblas_status rocblas_csrot_fortran(rocblas_handle         handle,
                                     rocblas_int            n,
                                     rocblas_float_complex* x,
                                     rocblas_int            incx,
                                     rocblas_float_complex* y,
                                     rocblas_int            incy,
                                     const float*           c,
                                     const float*           s);

rocblas_status rocblas_zrot_fortran(rocblas_handle                handle,
                                    rocblas_int                   n,
                                    rocblas_double_complex*       x,
                                    rocblas_int                   incx,
                                    rocblas_double_complex*       y,
                                    rocblas_int                   incy,
                                    const double*                 c,
                                    const rocblas_double_complex* s);

rocblas_status rocblas_zdrot_fortran(rocblas_handle          handle,
                                     rocblas_int             n,
                                     rocblas_double_complex* x,
                                     rocblas_int             incx,
                                     rocblas_double_complex* y,
                                     rocblas_int             incy,
                                     const double*           c,
                                     const double*           s);

// rot_batched
rocblas_status rocblas_srot_batched_fortran(rocblas_handle handle,
                                            rocblas_int    n,
                                            float* const   x[],
                                            rocblas_int    incx,
                                            float* const   y[],
                                            rocblas_int    incy,
                                            const float*   c,
                                            const float*   s,
                                            rocblas_int    batch_count);

rocblas_status rocblas_drot_batched_fortran(rocblas_handle handle,
                                            rocblas_int    n,
                                            double* const  x[],
                                            rocblas_int    incx,
                                            double* const  y[],
                                            rocblas_int    incy,
                                            const double*  c,
                                            const double*  s,
                                            rocblas_int    batch_count);

rocblas_status rocblas_crot_batched_fortran(rocblas_handle               handle,
                                            rocblas_int                  n,
                                            rocblas_float_complex* const x[],
                                            rocblas_int                  incx,
                                            rocblas_float_complex* const y[],
                                            rocblas_int                  incy,
                                            const float*                 c,
                                            const rocblas_float_complex* s,
                                            rocblas_int                  batch_count);

rocblas_status rocblas_csrot_batched_fortran(rocblas_handle               handle,
                                             rocblas_int                  n,
                                             rocblas_float_complex* const x[],
                                             rocblas_int                  incx,
                                             rocblas_float_complex* const y[],
                                             rocblas_int                  incy,
                                             const float*                 c,
                                             const float*                 s,
                                             rocblas_int                  batch_count);

rocblas_status rocblas_zrot_batched_fortran(rocblas_handle                handle,
                                            rocblas_int                   n,
                                            rocblas_double_complex* const x[],
                                            rocblas_int                   incx,
                                            rocblas_double_complex* const y[],
                                            rocblas_int                   incy,
                                            const double*                 c,
                                            const rocblas_double_complex* s,
                                            rocblas_int                   batch_count);

rocblas_status rocblas_zdrot_batched_fortran(rocblas_handle                handle,
                                             rocblas_int                   n,
                                             rocblas_double_complex* const x[],
                                             rocblas_int                   incx,
                                             rocblas_double_complex* const y[],
                                             rocblas_int                   incy,
                                             const double*                 c,
                                             const double*                 s,
                                             rocblas_int                   batch_count);

// rot_strided_batched
rocblas_status rocblas_srot_strided_batched_fortran(rocblas_handle handle,
                                                    rocblas_int    n,
                                                    float*         x,
                                                    rocblas_int    incx,
                                                    rocblas_stride stride_x,
                                                    float*         y,
                                                    rocblas_int    incy,
                                                    rocblas_stride stride_y,
                                                    const float*   c,
                                                    const float*   s,
                                                    rocblas_int    batch_count);

rocblas_status rocblas_drot_strided_batched_fortran(rocblas_handle handle,
                                                    rocblas_int    n,
                                                    double*        x,
                                                    rocblas_int    incx,
                                                    rocblas_stride stride_x,
                                                    double*        y,
                                                    rocblas_int    incy,
                                                    rocblas_stride stride_y,
                                                    const double*  c,
                                                    const double*  s,
                                                    rocblas_int    batch_count);

rocblas_status rocblas_crot_strided_batched_fortran(rocblas_handle               handle,
                                                    rocblas_int                  n,
                                                    rocblas_float_complex*       x,
                                                    rocblas_int                  incx,
                                                    rocblas_stride               stride_x,
                                                    rocblas_float_complex*       y,
                                                    rocblas_int                  incy,
                                                    rocblas_stride               stride_y,
                                                    const float*                 c,
                                                    const rocblas_float_complex* s,
                                                    rocblas_int                  batch_count);

rocblas_status rocblas_csrot_strided_batched_fortran(rocblas_handle         handle,
                                                     rocblas_int            n,
                                                     rocblas_float_complex* x,
                                                     rocblas_int            incx,
                                                     rocblas_stride         stride_x,
                                                     rocblas_float_complex* y,
                                                     rocblas_int            incy,
                                                     rocblas_stride         stride_y,
                                                     const float*           c,
                                                     const float*           s,
                                                     rocblas_int            batch_count);

rocblas_status rocblas_zrot_strided_batched_fortran(rocblas_handle                handle,
                                                    rocblas_int                   n,
                                                    rocblas_double_complex*       x,
                                                    rocblas_int                   incx,
                                                    rocblas_stride                stride_x,
                                                    rocblas_double_complex*       y,
                                                    rocblas_int                   incy,
                                                    rocblas_stride                stride_y,
                                                    const double*                 c,
                                                    const rocblas_double_complex* s,
                                                    rocblas_int                   batch_count);

rocblas_status rocblas_zdrot_strided_batched_fortran(rocblas_handle          handle,
                                                     rocblas_int             n,
                                                     rocblas_double_complex* x,
                                                     rocblas_int             incx,
                                                     rocblas_stride          stride_x,
                                                     rocblas_double_complex* y,
                                                     rocblas_int             incy,
                                                     rocblas_stride          stride_y,
                                                     const double*           c,
                                                     const double*           s,
                                                     rocblas_int             batch_count);

// rotg
rocblas_status rocblas_srotg_fortran(rocblas_handle handle, float* a, float* b, float* c, float* s);

rocblas_status
    rocblas_drotg_fortran(rocblas_handle handle, double* a, double* b, double* c, double* s);

rocblas_status rocblas_crotg_fortran(rocblas_handle         handle,
                                     rocblas_float_complex* a,
                                     rocblas_float_complex* b,
                                     float*                 c,
                                     rocblas_float_complex* s);

rocblas_status rocblas_zrotg_fortran(rocblas_handle          handle,
                                     rocblas_double_complex* a,
                                     rocblas_double_complex* b,
                                     double*                 c,
                                     rocblas_double_complex* s);

// rotg_batched
rocblas_status rocblas_srotg_batched_fortran(rocblas_handle handle,
                                             float* const   a[],
                                             float* const   b[],
                                             float* const   c[],
                                             float* const   s[],
                                             rocblas_int    batch_count);

rocblas_status rocblas_drotg_batched_fortran(rocblas_handle handle,
                                             double* const  a[],
                                             double* const  b[],
                                             double* const  c[],
                                             double* const  s[],
                                             rocblas_int    batch_count);

rocblas_status rocblas_crotg_batched_fortran(rocblas_handle               handle,
                                             rocblas_float_complex* const a[],
                                             rocblas_float_complex* const b[],
                                             float* const                 c[],
                                             rocblas_float_complex* const s[],
                                             rocblas_int                  batch_count);

rocblas_status rocblas_zrotg_batched_fortran(rocblas_handle                handle,
                                             rocblas_double_complex* const a[],
                                             rocblas_double_complex* const b[],
                                             double* const                 c[],
                                             rocblas_double_complex* const s[],
                                             rocblas_int                   batch_count);

// rotg_strided_batched
rocblas_status rocblas_srotg_strided_batched_fortran(rocblas_handle handle,
                                                     float*         a,
                                                     rocblas_stride stride_a,
                                                     float*         b,
                                                     rocblas_stride stride_b,
                                                     float*         c,
                                                     rocblas_stride stride_c,
                                                     float*         s,
                                                     rocblas_stride stride_s,
                                                     rocblas_int    batch_count);

rocblas_status rocblas_drotg_strided_batched_fortran(rocblas_handle handle,
                                                     double*        a,
                                                     rocblas_stride stride_a,
                                                     double*        b,
                                                     rocblas_stride stride_b,
                                                     double*        c,
                                                     rocblas_stride stride_c,
                                                     double*        s,
                                                     rocblas_stride stride_s,
                                                     rocblas_int    batch_count);

rocblas_status rocblas_crotg_strided_batched_fortran(rocblas_handle         handle,
                                                     rocblas_float_complex* a,
                                                     rocblas_stride         stride_a,
                                                     rocblas_float_complex* b,
                                                     rocblas_stride         stride_b,
                                                     float*                 c,
                                                     rocblas_stride         stride_c,
                                                     rocblas_float_complex* s,
                                                     rocblas_stride         stride_s,
                                                     rocblas_int            batch_count);

rocblas_status rocblas_zrotg_strided_batched_fortran(rocblas_handle          handle,
                                                     rocblas_double_complex* a,
                                                     rocblas_stride          stride_a,
                                                     rocblas_double_complex* b,
                                                     rocblas_stride          stride_b,
                                                     double*                 c,
                                                     rocblas_stride          stride_c,
                                                     rocblas_double_complex* s,
                                                     rocblas_stride          stride_s,
                                                     rocblas_int             batch_count);

// rotm
rocblas_status rocblas_srotm_fortran(rocblas_handle handle,
                                     rocblas_int    n,
                                     float*         x,
                                     rocblas_int    incx,
                                     float*         y,
                                     rocblas_int    incy,
                                     const float*   param);

rocblas_status rocblas_drotm_fortran(rocblas_handle handle,
                                     rocblas_int    n,
                                     double*        x,
                                     rocblas_int    incx,
                                     double*        y,
                                     rocblas_int    incy,
                                     const double*  param);

// rotm_batched
rocblas_status rocblas_srotm_batched_fortran(rocblas_handle     handle,
                                             rocblas_int        n,
                                             float* const       x[],
                                             rocblas_int        incx,
                                             float* const       y[],
                                             rocblas_int        incy,
                                             const float* const param[],
                                             rocblas_int        batch_count);

rocblas_status rocblas_drotm_batched_fortran(rocblas_handle      handle,
                                             rocblas_int         n,
                                             double* const       x[],
                                             rocblas_int         incx,
                                             double* const       y[],
                                             rocblas_int         incy,
                                             const double* const param[],
                                             rocblas_int         batch_count);

// rotm_strided_batched
rocblas_status rocblas_srotm_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     float*         x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stride_x,
                                                     float*         y,
                                                     rocblas_int    incy,
                                                     rocblas_stride stride_y,
                                                     const float*   param,
                                                     rocblas_stride stride_param,
                                                     rocblas_int    batch_count);

rocblas_status rocblas_drotm_strided_batched_fortran(rocblas_handle handle,
                                                     rocblas_int    n,
                                                     double*        x,
                                                     rocblas_int    incx,
                                                     rocblas_stride stride_x,
                                                     double*        y,
                                                     rocblas_int    incy,
                                                     rocblas_stride stride_y,
                                                     const double*  param,
                                                     rocblas_stride stride_param,
                                                     rocblas_int    batch_count);

// rotmg
rocblas_status rocblas_srotmg_fortran(
    rocblas_handle handle, float* d1, float* d2, float* x1, const float* y1, float* param);

rocblas_status rocblas_drotmg_fortran(
    rocblas_handle handle, double* d1, double* d2, double* x1, const double* y1, double* param);

// rotmg_batched
rocblas_status rocblas_srotmg_batched_fortran(rocblas_handle     handle,
                                              float* const       d1[],
                                              float* const       d2[],
                                              float* const       x1[],
                                              const float* const y1[],
                                              float* const       param[],
                                              rocblas_int        batch_count);

rocblas_status rocblas_drotmg_batched_fortran(rocblas_handle      handle,
                                              double* const       d1[],
                                              double* const       d2[],
                                              double* const       x1[],
                                              const double* const y1[],
                                              double* const       param[],
                                              rocblas_int         batch_count);

// rotmg_strided_batched
rocblas_status rocblas_srotmg_strided_batched_fortran(rocblas_handle handle,
                                                      float*         d1,
                                                      rocblas_stride stride_d1,
                                                      float*         d2,
                                                      rocblas_stride stride_d2,
                                                      float*         x1,
                                                      rocblas_stride stride_x1,
                                                      const float*   y1,
                                                      rocblas_stride stride_y1,
                                                      float*         param,
                                                      rocblas_stride stride_param,
                                                      rocblas_int    batch_count);

rocblas_status rocblas_drotmg_strided_batched_fortran(rocblas_handle handle,
                                                      double*        d1,
                                                      rocblas_stride stride_d1,
                                                      double*        d2,
                                                      rocblas_stride stride_d2,
                                                      double*        x1,
                                                      rocblas_stride stride_x1,
                                                      const double*  y1,
                                                      rocblas_stride stride_y1,
                                                      double*        param,
                                                      rocblas_stride stride_param,
                                                      rocblas_int    batch_count);
}

#endif
