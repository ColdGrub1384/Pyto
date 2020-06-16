#ifndef __MINPACK_H__
#define __MINPACK_H__

#include "cminpack.h"

/* The default floating-point type is "double" for C/C++ and "float" for CUDA,
   but you can change this by defining one of the following symbols when
   compiling the library, and before including cminpack.h when using it:
   __cminpack_long_double__ for long double (requires compiler support)
   __cminpack_double__ for double
   __cminpack_float__ for float
   __cminpack_half__ for half from the OpenEXR library (in this case, you must
                     compile cminpack with a C++ compiler)
*/
#ifdef __cminpack_double__
#define __minpack_func__(func) func ## _
#endif

#ifdef __cminpack_long_double__
#define __minpack_func__(func) ld ## func ## _
#endif

#ifdef __cminpack_float__
#define __minpack_func__(func) s ## func ## _
#endif

#ifdef __cminpack_half__
#define __minpack_func__(func) h ## func ## _
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MINPACK_EXPORT CMINPACK_EXPORT

#define __minpack_real__  __cminpack_real__
#define __minpack_attr__  __cminpack_attr__
#if defined(__CUDA_ARCH__) || defined(__CUDACC__)
#define __minpack_type_fcn_nn__        __minpack_attr__ void fcn_nn
#define __minpack_type_fcnder_nn__     __minpack_attr__ void fcnder_nn
#define __minpack_type_fcn_mn__        __minpack_attr__ void fcn_mn
#define __minpack_type_fcnder_mn__     __minpack_attr__ void fcnder_mn
#define __minpack_type_fcnderstr_mn__  __minpack_attr__ void fcnderstr_mn
#define __minpack_decl_fcn_nn__
#define __minpack_decl_fcnder_nn__
#define __minpack_decl_fcn_mn__
#define __minpack_decl_fcnder_mn__
#define __minpack_decl_fcnderstr_mn__
#define __minpack_param_fcn_nn__
#define __minpack_param_fcnder_nn__
#define __minpack_param_fcn_mn__
#define __minpack_param_fcnder_mn__
#define __minpack_param_fcnderstr_mn__
#else
#define __minpack_type_fcn_nn__        typedef void (*minpack_func_nn)
#define __minpack_type_fcnder_nn__     typedef void (*minpack_funcder_nn)
#define __minpack_type_fcn_mn__        typedef void (*minpack_func_mn)
#define __minpack_type_fcnder_mn__     typedef void (*minpack_funcder_mn)
#define __minpack_type_fcnderstr_mn__  typedef void (*minpack_funcderstr_mn)
#define __minpack_decl_fcn_nn__        minpack_func_nn fcn_nn,
#define __minpack_decl_fcnder_nn__     minpack_funcder_nn fcnder_nn,
#define __minpack_decl_fcn_mn__        minpack_func_mn fcn_mn,
#define __minpack_decl_fcnder_mn__     minpack_funcder_mn fcnder_mn,
#define __minpack_decl_fcnderstr_mn__  minpack_funcderstr_mn fcnderstr_mn,
#define __minpack_param_fcn_nn__       fcn_nn,
#define __minpack_param_fcnder_nn__    fcnder_nn,
#define __minpack_param_fcn_mn__       fcn_mn,
#define __minpack_param_fcnder_mn__    fcnder_mn,
#define __minpack_param_fcnderstr_mn__ fcnderstr_mn,
#endif
#undef __cminpack_type_fcn_nn__
#undef __cminpack_type_fcnder_nn__
#undef __cminpack_type_fcn_mn__
#undef __cminpack_type_fcnder_mn__
#undef __cminpack_type_fcnderstr_mn__
#undef __cminpack_decl_fcn_nn__
#undef __cminpack_decl_fcnder_nn__
#undef __cminpack_decl_fcn_mn__
#undef __cminpack_decl_fcnder_mn__
#undef __cminpack_decl_fcnderstr_mn__
#undef __cminpack_param_fcn_nn__
#undef __cminpack_param_fcnder_nn__
#undef __cminpack_param_fcn_mn__
#undef __cminpack_param_fcnder_mn__
#undef __cminpack_param_fcnderstr_mn__

/* Declarations for minpack */

/* Function types: */
/* the iflag parameter is input-only (with respect to the FORTRAN */
/*  version), the output iflag value is the return value of the function. */
/* If iflag=0, the function shoulkd just print the current values (see */
/* the nprint parameters below). */
  
/* for hybrd1 and hybrd: */
/*         calculate the functions at x and */
/*         return this vector in fvec. */
/* return a negative value to terminate hybrd1/hybrd */
__minpack_type_fcn_nn__(const int *n, const __minpack_real__ *x, __minpack_real__ *fvec, int *iflag );

/* for hybrj1 and hybrj */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. do not alter fjac. */
/*         if iflag = 2 calculate the jacobian at x and */
/*         return this matrix in fjac. do not alter fvec. */
/* return a negative value to terminate hybrj1/hybrj */
__minpack_type_fcnder_nn__(const int *n, const __minpack_real__ *x, __minpack_real__ *fvec, __minpack_real__ *fjac,
                                  const int *ldfjac, int *iflag );

/* for lmdif1 and lmdif */
/*         calculate the functions at x and */
/*         return this vector in fvec. */
/*         if iflag = 1 the result is used to compute the residuals. */
/*         if iflag = 2 the result is used to compute the Jacobian by finite differences. */
/*         Jacobian computation requires exactly n function calls with iflag = 2. */
/* return a negative value to terminate lmdif1/lmdif */
__minpack_type_fcn_mn__(const int *m, const int *n, const __minpack_real__ *x, __minpack_real__ *fvec,
                               int *iflag );

/* for lmder1 and lmder */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. do not alter fjac. */
/*         if iflag = 2 calculate the jacobian at x and */
/*         return this matrix in fjac. do not alter fvec. */
/* return a negative value to terminate lmder1/lmder */
__minpack_type_fcnder_mn__(const int *m, const int *n, const __minpack_real__ *x, __minpack_real__ *fvec,
                                  __minpack_real__ *fjac, const int *ldfjac, int *iflag );

/* for lmstr1 and lmstr */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. */
/*         if iflag = i calculate the (i-1)-st row of the */
/*         jacobian at x and return this vector in fjrow. */
/* return a negative value to terminate lmstr1/lmstr */
__minpack_type_fcnderstr_mn__(const int *m, const int *n, const __minpack_real__ *x, __minpack_real__ *fvec,
                                     __minpack_real__ *fjrow, int *iflag );

/* find a zero of a system of N nonlinear functions in N variables by
   a modification of the Powell hybrid method (Jacobian calculated by
   a forward-difference approximation) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(hybrd1)(  __minpack_decl_fcn_nn__
	       const int *n, __minpack_real__ *x, __minpack_real__ *fvec, const __minpack_real__ *tol, int *info,
	       __minpack_real__ *wa, const int *lwa );

/* find a zero of a system of N nonlinear functions in N variables by
   a modification of the Powell hybrid method (Jacobian calculated by
   a forward-difference approximation, more general). */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(hybrd)( __minpack_decl_fcn_nn__
	      const int *n, __minpack_real__ *x, __minpack_real__ *fvec, const __minpack_real__ *xtol, const int *maxfev,
	      const int *ml, const int *mu, const __minpack_real__ *epsfcn, __minpack_real__ *diag, const int *mode,
	      const __minpack_real__ *factor, const int *nprint, int *info, int *nfev,
	      __minpack_real__ *fjac, const int *ldfjac, __minpack_real__ *r, const int *lr, __minpack_real__ *qtf,
	      __minpack_real__ *wa1, __minpack_real__ *wa2, __minpack_real__ *wa3, __minpack_real__ *wa4);
  
/* find a zero of a system of N nonlinear functions in N variables by
   a modification of the Powell hybrid method (user-supplied Jacobian) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(hybrj1)( __minpack_decl_fcnder_nn__ const int *n, __minpack_real__ *x,
	       __minpack_real__ *fvec, __minpack_real__ *fjec, const int *ldfjac, const __minpack_real__ *tol,
	       int *info, __minpack_real__ *wa, const int *lwa );
          
/* find a zero of a system of N nonlinear functions in N variables by
   a modification of the Powell hybrid method (user-supplied Jacobian,
   more general) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(hybrj)( __minpack_decl_fcnder_nn__ const int *n, __minpack_real__ *x,
	      __minpack_real__ *fvec, __minpack_real__ *fjec, const int *ldfjac, const __minpack_real__ *xtol,
	      const int *maxfev, __minpack_real__ *diag, const int *mode, const __minpack_real__ *factor,
	      const int *nprint, int *info, int *nfev, int *njev, __minpack_real__ *r,
	      const int *lr, __minpack_real__ *qtf, __minpack_real__ *wa1, __minpack_real__ *wa2,
	      __minpack_real__ *wa3, __minpack_real__ *wa4 );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (Jacobian calculated by a forward-difference approximation) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(lmdif1)( __minpack_decl_fcn_mn__
	       const int *m, const int *n, __minpack_real__ *x, __minpack_real__ *fvec, const __minpack_real__ *tol,
	       int *info, int *iwa, __minpack_real__ *wa, const int *lwa );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (Jacobian calculated by a forward-difference approximation, more
   general) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(lmdif)( __minpack_decl_fcn_mn__
	      const int *m, const int *n, __minpack_real__ *x, __minpack_real__ *fvec, const __minpack_real__ *ftol,
	      const __minpack_real__ *xtol, const __minpack_real__ *gtol, const int *maxfev, const __minpack_real__ *epsfcn,
	      __minpack_real__ *diag, const int *mode, const __minpack_real__ *factor, const int *nprint,
	      int *info, int *nfev, __minpack_real__ *fjac, const int *ldfjac, int *ipvt,
	      __minpack_real__ *qtf, __minpack_real__ *wa1, __minpack_real__ *wa2, __minpack_real__ *wa3,
	      __minpack_real__ *wa4 );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (user-supplied Jacobian) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(lmder1)( __minpack_decl_fcnder_mn__
	       const int *m, const int *n, __minpack_real__ *x, __minpack_real__ *fvec, __minpack_real__ *fjac,
	       const int *ldfjac, const __minpack_real__ *tol, int *info, int *ipvt,
	       __minpack_real__ *wa, const int *lwa );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (user-supplied Jacobian, more general) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(lmder)( __minpack_decl_fcnder_mn__
	      const int *m, const int *n, __minpack_real__ *x, __minpack_real__ *fvec, __minpack_real__ *fjac,
	      const int *ldfjac, const __minpack_real__ *ftol, const __minpack_real__ *xtol, const __minpack_real__ *gtol,
	      const int *maxfev, __minpack_real__ *diag, const int *mode, const __minpack_real__ *factor,
	      const int *nprint, int *info, int *nfev, int *njev, int *ipvt,
	      __minpack_real__ *qtf, __minpack_real__ *wa1, __minpack_real__ *wa2, __minpack_real__ *wa3,
	      __minpack_real__ *wa4 );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (user-supplied Jacobian, minimal storage) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(lmstr1)( __minpack_decl_fcnderstr_mn__ const int *m, const int *n,
	       __minpack_real__ *x, __minpack_real__ *fvec, __minpack_real__ *fjac, const int *ldfjac,
	       const __minpack_real__ *tol, int *info, int *ipvt, __minpack_real__ *wa, const int *lwa );

/* minimize the sum of the squares of nonlinear functions in N
   variables by a modification of the Levenberg-Marquardt algorithm
   (user-supplied Jacobian, minimal storage, more general) */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(lmstr)( __minpack_decl_fcnderstr_mn__ const int *m,
	      const int *n, __minpack_real__ *x, __minpack_real__ *fvec, __minpack_real__ *fjac,
	      const int *ldfjac, const __minpack_real__ *ftol, const __minpack_real__ *xtol, const __minpack_real__ *gtol,
	      const int *maxfev, __minpack_real__ *diag, const int *mode, const __minpack_real__ *factor,
	      const int *nprint, int *info, int *nfev, int *njev, int *ipvt,
	      __minpack_real__ *qtf, __minpack_real__ *wa1, __minpack_real__ *wa2, __minpack_real__ *wa3,
	      __minpack_real__ *wa4 );
 
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(chkder)( const int *m, const int *n, const __minpack_real__ *x, __minpack_real__ *fvec, __minpack_real__ *fjec,
	       const int *ldfjac, __minpack_real__ *xp, __minpack_real__ *fvecp, const int *mode,
	       __minpack_real__ *err  );

__minpack_attr__
__minpack_real__ MINPACK_EXPORT __minpack_func__(dpmpar)( const int *i );

__minpack_attr__
__minpack_real__ MINPACK_EXPORT __minpack_func__(enorm)( const int *n, const __minpack_real__ *x );

/* compute a forward-difference approximation to the m by n jacobian
   matrix associated with a specified problem of m functions in n
   variables. */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(fdjac2)(__minpack_decl_fcn_mn__
	     const int *m, const int *n, __minpack_real__ *x, const __minpack_real__ *fvec, __minpack_real__ *fjac,
	     const int *ldfjac, int *iflag, const __minpack_real__ *epsfcn, __minpack_real__ *wa);

/* compute a forward-difference approximation to the n by n jacobian
   matrix associated with a specified problem of n functions in n
   variables. if the jacobian has a banded form, then function
   evaluations are saved by only approximating the nonzero terms. */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(fdjac1)(__minpack_decl_fcn_nn__
	     const int *n, __minpack_real__ *x, const __minpack_real__ *fvec, __minpack_real__ *fjac, const int *ldfjac,
	     int *iflag, const int *ml, const int *mu, const __minpack_real__ *epsfcn, __minpack_real__ *wa1,
	     __minpack_real__ *wa2);

/* compute inverse(JtJ) after a run of lmdif or lmder. The covariance
   matrix is obtained by scaling the result by enorm(y)**2/(m-n). If
   JtJ is singular and k = rank(J), the pseudo-inverse is computed,
   and the result has to be scaled by enorm(y)**2/(m-k). */
__minpack_attr__
void MINPACK_EXPORT __minpack_func__(covar)(const int *n, __minpack_real__ *r, const int *ldr,
           const int *ipvt, const __minpack_real__ *tol, __minpack_real__ *wa);

/* internal MINPACK subroutines */
__minpack_attr__
void __minpack_func__(dogleg)(const int *n, const __minpack_real__ *r, const int *lr, 
             const __minpack_real__ *diag, const __minpack_real__ *qtb, const __minpack_real__ *delta, __minpack_real__ *x, 
             __minpack_real__ *wa1, __minpack_real__ *wa2);
__minpack_attr__
void __minpack_func__(qrfac)(const int *m, const int *n, __minpack_real__ *a, const int *
            lda, const int *pivot, int *ipvt, const int *lipvt, __minpack_real__ *rdiag,
            __minpack_real__ *acnorm, __minpack_real__ *wa);
__minpack_attr__
void __minpack_func__(qrsolv)(const int *n, __minpack_real__ *r, const int *ldr, 
             const int *ipvt, const __minpack_real__ *diag, const __minpack_real__ *qtb, __minpack_real__ *x, 
             __minpack_real__ *sdiag, __minpack_real__ *wa);
__minpack_attr__
void __minpack_func__(qform)(const int *m, const int *n, __minpack_real__ *q, const int *
            ldq, __minpack_real__ *wa);
__minpack_attr__
void __minpack_func__(r1updt)(const int *m, const int *n, __minpack_real__ *s, const int *
             ls, const __minpack_real__ *u, __minpack_real__ *v, __minpack_real__ *w, int *sing);
__minpack_attr__
void __minpack_func__(r1mpyq)(const int *m, const int *n, __minpack_real__ *a, const int *
             lda, const __minpack_real__ *v, const __minpack_real__ *w);
__minpack_attr__
void __minpack_func__(lmpar)(const int *n, __minpack_real__ *r, const int *ldr, 
            const int *ipvt, const __minpack_real__ *diag, const __minpack_real__ *qtb, const __minpack_real__ *delta, 
            __minpack_real__ *par, __minpack_real__ *x, __minpack_real__ *sdiag, __minpack_real__ *wa1, 
            __minpack_real__ *wa2);
__minpack_attr__
void __minpack_func__(rwupdt)(const int *n, __minpack_real__ *r, const int *ldr, 
             const __minpack_real__ *w, __minpack_real__ *b, __minpack_real__ *alpha, __minpack_real__ *cos, 
             __minpack_real__ *sin);
#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __MINPACK_H__ */
