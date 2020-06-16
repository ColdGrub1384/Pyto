/* Header file for cminpack, by Frederic Devernay.
   The documentation for all functions can be found in the file
   minpack-documentation.txt from the distribution, or in the source
   code of each function. */

#ifndef __CMINPACK_H__
#define __CMINPACK_H__

/* The default floating-point type is "double" for C/C++ and "float" for CUDA,
   but you can change this by defining one of the following symbols when
   compiling the library, and before including cminpack.h when using it:
   __cminpack_long_double__ for long double (requires compiler support)
   __cminpack_double__ for double
   __cminpack_float__ for float
   __cminpack_half__ for half from the OpenEXR library (in this case, you must
                     compile cminpack with a C++ compiler)
*/
#ifdef __cminpack_long_double__
#define __cminpack_real__ long double
#endif

#ifdef __cminpack_double__
#define __cminpack_real__ double
#endif

#ifdef __cminpack_float__
#define __cminpack_real__ float
#endif

#ifdef __cminpack_half__
#include <OpenEXR/half.h>
#define __cminpack_real__ half
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Cmake will define cminpack_EXPORTS on Windows when it
configures to build a shared library. If you are going to use
another build system on windows or create the visual studio
projects by hand you need to define cminpack_EXPORTS when
building a DLL on windows.
*/
#if defined (__GNUC__)
#define CMINPACK_DECLSPEC_EXPORT  __declspec(__dllexport__)
#define CMINPACK_DECLSPEC_IMPORT  __declspec(__dllimport__)
#endif
#if defined (_MSC_VER) || defined (__BORLANDC__)
#define CMINPACK_DECLSPEC_EXPORT  __declspec(dllexport)
#define CMINPACK_DECLSPEC_IMPORT  __declspec(dllimport)
#endif
#ifdef __WATCOMC__
#define CMINPACK_DECLSPEC_EXPORT  __export
#define CMINPACK_DECLSPEC_IMPORT  __import
#endif
#ifdef __IBMC__
#define CMINPACK_DECLSPEC_EXPORT  _Export
#define CMINPACK_DECLSPEC_IMPORT  _Import
#endif

#if !defined(CMINPACK_NO_DLL) && (defined(__WIN32__) || defined(WIN32) || defined (_WIN32))
#if defined(cminpack_EXPORTS) || defined(CMINPACK_EXPORTS) || defined(CMINPACK_DLL_EXPORTS)
    #define  CMINPACK_EXPORT CMINPACK_DECLSPEC_EXPORT
  #else
    #define  CMINPACK_EXPORT CMINPACK_DECLSPEC_IMPORT
  #endif /* cminpack_EXPORTS */
#else /* defined (_WIN32) */
 #define CMINPACK_EXPORT
#endif

#if defined(__CUDA_ARCH__) || defined(__CUDACC__)
#define __cminpack_attr__ __device__
#ifndef __cminpack_real__
#define __cminpack_float__
#define __cminpack_real__ float
#endif
#define __cminpack_type_fcn_nn__        __cminpack_attr__ int fcn_nn
#define __cminpack_type_fcnder_nn__     __cminpack_attr__ int fcnder_nn
#define __cminpack_type_fcn_mn__        __cminpack_attr__ int fcn_mn
#define __cminpack_type_fcnder_mn__     __cminpack_attr__ int fcnder_mn
#define __cminpack_type_fcnderstr_mn__  __cminpack_attr__ int fcnderstr_mn
#define __cminpack_decl_fcn_nn__
#define __cminpack_decl_fcnder_nn__
#define __cminpack_decl_fcn_mn__
#define __cminpack_decl_fcnder_mn__
#define __cminpack_decl_fcnderstr_mn__
#define __cminpack_param_fcn_nn__
#define __cminpack_param_fcnder_nn__
#define __cminpack_param_fcn_mn__
#define __cminpack_param_fcnder_mn__
#define __cminpack_param_fcnderstr_mn__
#else
#define __cminpack_attr__
#ifndef __cminpack_real__
#define __cminpack_double__
#define __cminpack_real__ double
#endif
#define __cminpack_type_fcn_nn__        typedef int (*cminpack_func_nn)
#define __cminpack_type_fcnder_nn__     typedef int (*cminpack_funcder_nn)
#define __cminpack_type_fcn_mn__        typedef int (*cminpack_func_mn)
#define __cminpack_type_fcnder_mn__     typedef int (*cminpack_funcder_mn)
#define __cminpack_type_fcnderstr_mn__  typedef int (*cminpack_funcderstr_mn)
#define __cminpack_decl_fcn_nn__        cminpack_func_nn fcn_nn,
#define __cminpack_decl_fcnder_nn__     cminpack_funcder_nn fcnder_nn,
#define __cminpack_decl_fcn_mn__        cminpack_func_mn fcn_mn,
#define __cminpack_decl_fcnder_mn__     cminpack_funcder_mn fcnder_mn,
#define __cminpack_decl_fcnderstr_mn__  cminpack_funcderstr_mn fcnderstr_mn,
#define __cminpack_param_fcn_nn__       fcn_nn,
#define __cminpack_param_fcnder_nn__    fcnder_nn,
#define __cminpack_param_fcn_mn__       fcn_mn,
#define __cminpack_param_fcnder_mn__    fcnder_mn,
#define __cminpack_param_fcnderstr_mn__ fcnderstr_mn,
#endif

#ifdef __cminpack_double__
#define __cminpack_func__(func) func
#define __cminpack_cblas__(func) cblas_d ## func
#define __cminpack_lapack__(func) d ## func
#endif

#ifdef __cminpack_long_double__
#define __cminpack_func__(func) ld ## func
#endif

#ifdef __cminpack_float__
#define __cminpack_func__(func) s ## func
#define __cminpack_cblas__(func) cblas_s ## func
#define __cminpack_lapack__(func) s ## func
#endif

#ifdef __cminpack_half__
#define __cminpack_func__(func) h ## func
#endif

/* Declarations for minpack */

/* Function types: */
/* The first argument can be used to store extra function parameters, thus */
/* avoiding the use of global variables. */
/* the iflag parameter is input-only (with respect to the FORTRAN */
/*  version), the output iflag value is the return value of the function. */
/* If iflag=0, the function shoulkd just print the current values (see */
/* the nprint parameters below). */
  
/* for hybrd1 and hybrd: */
/*         calculate the functions at x and */
/*         return this vector in fvec. */
/* return a negative value to terminate hybrd1/hybrd */
__cminpack_type_fcn_nn__(void *p, int n, const __cminpack_real__ *x, __cminpack_real__ *fvec, int iflag );

/* for hybrj1 and hybrj */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. do not alter fjac. */
/*         if iflag = 2 calculate the jacobian at x and */
/*         return this matrix in fjac. do not alter fvec. */
/* return a negative value to terminate hybrj1/hybrj */
__cminpack_type_fcnder_nn__(void *p, int n, const __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ *fjac,
                                  int ldfjac, int iflag );

/* for lmdif1 and lmdif */
/*         calculate the functions at x and */
/*         return this vector in fvec. */
/*         if iflag = 1 the result is used to compute the residuals. */
/*         if iflag = 2 the result is used to compute the Jacobian by finite differences. */
/*         Jacobian computation requires exactly n function calls with iflag = 2. */
/* return a negative value to terminate lmdif1/lmdif */
__cminpack_type_fcn_mn__(void *p, int m, int n, const __cminpack_real__ *x, __cminpack_real__ *fvec,
                               int iflag );

/* for lmder1 and lmder */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. do not alter fjac. */
/*         if iflag = 2 calculate the jacobian at x and */
/*         return this matrix in fjac. do not alter fvec. */
/* return a negative value to terminate lmder1/lmder */
__cminpack_type_fcnder_mn__(void *p, int m, int n, const __cminpack_real__ *x, __cminpack_real__ *fvec,
                                  __cminpack_real__ *fjac, int ldfjac, int iflag );

/* for lmstr1 and lmstr */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. */
/*         if iflag = i calculate the (i-1)-st row of the */
/*         jacobian at x and return this vector in fjrow. */
/* return a negative value to terminate lmstr1/lmstr */
__cminpack_type_fcnderstr_mn__(void *p, int m, int n, const __cminpack_real__ *x, __cminpack_real__ *fvec,
                                     __cminpack_real__ *fjrow, int iflag );






/* MINPACK functions: */
/* the info parameter was removed from most functions: the return */
/* value of the function is used instead. */
/* The argument 'p' can be used to store extra function parameters, thus */
/* avoiding the use of global variables. You can also think of it as a */
/* 'this' pointer a la C++. */

/* find a zero of a system of N nonlinear functions in N variables by
   a modification of the Powell hybrid method (Jacobian calculated by
   a forward-difference approximation) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(hybrd1)( __cminpack_decl_fcn_nn__ 
	       void *p, int n, __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ tol,
	       __cminpack_real__ *wa, int lwa );

/* find a zero of a system of N nonlinear functions in N variables by
   a modification of the Powell hybrid method (Jacobian calculated by
   a forward-difference approximation, more general). */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(hybrd)( __cminpack_decl_fcn_nn__
	      void *p, int n, __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ xtol, int maxfev,
	      int ml, int mu, __cminpack_real__ epsfcn, __cminpack_real__ *diag, int mode,
	      __cminpack_real__ factor, int nprint, int *nfev,
	      __cminpack_real__ *fjac, int ldfjac, __cminpack_real__ *r, int lr, __cminpack_real__ *qtf,
	      __cminpack_real__ *wa1, __cminpack_real__ *wa2, __cminpack_real__ *wa3, __cminpack_real__ *wa4);
  
/* find a zero of a system of N nonlinear functions in N variables by
   a modification of the Powell hybrid method (user-supplied Jacobian) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(hybrj1)( __cminpack_decl_fcnder_nn__ void *p, int n, __cminpack_real__ *x,
	       __cminpack_real__ *fvec, __cminpack_real__ *fjac, int ldfjac, __cminpack_real__ tol,
	       __cminpack_real__ *wa, int lwa );
          
/* find a zero of a system of N nonlinear functions in N variables by
   a modification of the Powell hybrid method (user-supplied Jacobian,
   more general) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(hybrj)( __cminpack_decl_fcnder_nn__ void *p, int n, __cminpack_real__ *x,
	      __cminpack_real__ *fvec, __cminpack_real__ *fjac, int ldfjac, __cminpack_real__ xtol,
	      int maxfev, __cminpack_real__ *diag, int mode, __cminpack_real__ factor,
	      int nprint, int *nfev, int *njev, __cminpack_real__ *r,
	      int lr, __cminpack_real__ *qtf, __cminpack_real__ *wa1, __cminpack_real__ *wa2,
	      __cminpack_real__ *wa3, __cminpack_real__ *wa4 );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (Jacobian calculated by a forward-difference approximation) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(lmdif1)( __cminpack_decl_fcn_mn__
	       void *p, int m, int n, __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ tol,
	       int *iwa, __cminpack_real__ *wa, int lwa );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (Jacobian calculated by a forward-difference approximation, more
   general) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(lmdif)( __cminpack_decl_fcn_mn__
	      void *p, int m, int n, __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ ftol,
	      __cminpack_real__ xtol, __cminpack_real__ gtol, int maxfev, __cminpack_real__ epsfcn,
	      __cminpack_real__ *diag, int mode, __cminpack_real__ factor, int nprint,
	      int *nfev, __cminpack_real__ *fjac, int ldfjac, int *ipvt,
	      __cminpack_real__ *qtf, __cminpack_real__ *wa1, __cminpack_real__ *wa2, __cminpack_real__ *wa3,
	      __cminpack_real__ *wa4 );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (user-supplied Jacobian) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(lmder1)( __cminpack_decl_fcnder_mn__
	       void *p, int m, int n, __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ *fjac,
	       int ldfjac, __cminpack_real__ tol, int *ipvt,
	       __cminpack_real__ *wa, int lwa );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (user-supplied Jacobian, more general) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(lmder)( __cminpack_decl_fcnder_mn__
	      void *p, int m, int n, __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ *fjac,
	      int ldfjac, __cminpack_real__ ftol, __cminpack_real__ xtol, __cminpack_real__ gtol,
	      int maxfev, __cminpack_real__ *diag, int mode, __cminpack_real__ factor,
	      int nprint, int *nfev, int *njev, int *ipvt,
	      __cminpack_real__ *qtf, __cminpack_real__ *wa1, __cminpack_real__ *wa2, __cminpack_real__ *wa3,
	      __cminpack_real__ *wa4 );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (user-supplied Jacobian, minimal storage) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(lmstr1)( __cminpack_decl_fcnderstr_mn__ void *p, int m, int n,
	       __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ *fjac, int ldfjac,
	       __cminpack_real__ tol, int *ipvt, __cminpack_real__ *wa, int lwa );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (user-supplied Jacobian, minimal storage, more general) */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(lmstr)(  __cminpack_decl_fcnderstr_mn__ void *p, int m,
	      int n, __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ *fjac,
	      int ldfjac, __cminpack_real__ ftol, __cminpack_real__ xtol, __cminpack_real__ gtol,
	      int maxfev, __cminpack_real__ *diag, int mode, __cminpack_real__ factor,
	      int nprint, int *nfev, int *njev, int *ipvt,
	      __cminpack_real__ *qtf, __cminpack_real__ *wa1, __cminpack_real__ *wa2, __cminpack_real__ *wa3,
	      __cminpack_real__ *wa4 );
 
__cminpack_attr__
void CMINPACK_EXPORT __cminpack_func__(chkder)( int m, int n, const __cminpack_real__ *x, __cminpack_real__ *fvec, __cminpack_real__ *fjac,
	       int ldfjac, __cminpack_real__ *xp, __cminpack_real__ *fvecp, int mode,
	       __cminpack_real__ *err  );

__cminpack_attr__
__cminpack_real__ CMINPACK_EXPORT __cminpack_func__(dpmpar)( int i );

__cminpack_attr__
__cminpack_real__ CMINPACK_EXPORT __cminpack_func__(enorm)( int n, const __cminpack_real__ *x );

/* compute a forward-difference approximation to the m by n jacobian
   matrix associated with a specified problem of m functions in n
   variables. */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(fdjac2)(__cminpack_decl_fcn_mn__
	     void *p, int m, int n, __cminpack_real__ *x, const __cminpack_real__ *fvec, __cminpack_real__ *fjac,
	     int ldfjac, __cminpack_real__ epsfcn, __cminpack_real__ *wa);

/* compute a forward-difference approximation to the n by n jacobian
   matrix associated with a specified problem of n functions in n
   variables. if the jacobian has a banded form, then function
   evaluations are saved by only approximating the nonzero terms. */
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(fdjac1)(__cminpack_decl_fcn_nn__
	     void *p, int n, __cminpack_real__ *x, const __cminpack_real__ *fvec, __cminpack_real__ *fjac, int ldfjac,
	     int ml, int mu, __cminpack_real__ epsfcn, __cminpack_real__ *wa1,
	     __cminpack_real__ *wa2);

/* compute inverse(JtJ) after a run of lmdif or lmder. The covariance matrix is obtained
   by scaling the result by enorm(y)**2/(m-n). If JtJ is singular and k = rank(J), the
   pseudo-inverse is computed, and the result has to be scaled by enorm(y)**2/(m-k). */
__cminpack_attr__
void CMINPACK_EXPORT __cminpack_func__(covar)(int n, __cminpack_real__ *r, int ldr, 
           const int *ipvt, __cminpack_real__ tol, __cminpack_real__ *wa);

/* covar1 estimates the variance-covariance matrix:
   C = sigma**2 (JtJ)**+
   where (JtJ)**+ is the inverse of JtJ or the pseudo-inverse of JtJ (in case J does not have full rank),
   and sigma**2 = fsumsq / (m - k)
   where fsumsq is the residual sum of squares and k is the rank of J.
   The function returns 0 if J has full rank, else the rank of J.
*/
__cminpack_attr__
int CMINPACK_EXPORT __cminpack_func__(covar1)(int m, int n, __cminpack_real__ fsumsq, __cminpack_real__ *r, int ldr, 
                           const int *ipvt, __cminpack_real__ tol, __cminpack_real__ *wa);

/* internal MINPACK subroutines */
__cminpack_attr__
void __cminpack_func__(dogleg)(int n, const __cminpack_real__ *r, int lr, 
             const __cminpack_real__ *diag, const __cminpack_real__ *qtb, __cminpack_real__ delta, __cminpack_real__ *x, 
             __cminpack_real__ *wa1, __cminpack_real__ *wa2);
__cminpack_attr__
void __cminpack_func__(qrfac)(int m, int n, __cminpack_real__ *a, int
            lda, int pivot, int *ipvt, int lipvt, __cminpack_real__ *rdiag,
            __cminpack_real__ *acnorm, __cminpack_real__ *wa);
__cminpack_attr__
void __cminpack_func__(qrsolv)(int n, __cminpack_real__ *r, int ldr, 
             const int *ipvt, const __cminpack_real__ *diag, const __cminpack_real__ *qtb, __cminpack_real__ *x, 
             __cminpack_real__ *sdiag, __cminpack_real__ *wa);
__cminpack_attr__
void __cminpack_func__(qform)(int m, int n, __cminpack_real__ *q, int
            ldq, __cminpack_real__ *wa);
__cminpack_attr__
void __cminpack_func__(r1updt)(int m, int n, __cminpack_real__ *s, int
             ls, const __cminpack_real__ *u, __cminpack_real__ *v, __cminpack_real__ *w, int *sing);
__cminpack_attr__
void __cminpack_func__(r1mpyq)(int m, int n, __cminpack_real__ *a, int
             lda, const __cminpack_real__ *v, const __cminpack_real__ *w);
__cminpack_attr__
void __cminpack_func__(lmpar)(int n, __cminpack_real__ *r, int ldr, 
            const int *ipvt, const __cminpack_real__ *diag, const __cminpack_real__ *qtb, __cminpack_real__ delta, 
            __cminpack_real__ *par, __cminpack_real__ *x, __cminpack_real__ *sdiag, __cminpack_real__ *wa1, 
            __cminpack_real__ *wa2);
__cminpack_attr__
void __cminpack_func__(rwupdt)(int n, __cminpack_real__ *r, int ldr, 
             const __cminpack_real__ *w, __cminpack_real__ *b, __cminpack_real__ *alpha, __cminpack_real__ *cos, 
             __cminpack_real__ *sin);
#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __CMINPACK_H__ */
