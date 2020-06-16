/* lmstr.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "minpack.h"
#include <math.h>
#include "minpackP.h"


__minpack_attr__
void __minpack_func__(lmstr)(__minpack_decl_fcnderstr_mn__ const int *m, const int *n, real *x, 
	real *fvec, real *fjac, const int *ldfjac, const real *ftol,
	const real *xtol, const real *gtol, const int *maxfev, real *
	diag, const int *mode, const real *factor, const int *nprint, int *
	info, int *nfev, int *njev, int *ipvt, real *qtf, 
	real *wa1, real *wa2, real *wa3, real *wa4)
{
    /* Table of constant values */

    const int c__1 = 1;
    const int c_true = TRUE_;

    /* Initialized data */

#define p1 .1
#define p5 .5
#define p25 .25
#define p75 .75
#define p0001 1e-4

    /* System generated locals */
    int fjac_dim1, fjac_offset, i__1, i__2;
    real d__1, d__2, d__3;

    /* Local variables */
    int i__, j, l;
    real par, sum;
    int sing;
    int iter;
    real temp, temp1, temp2;
    int iflag;
    real delta;
    real ratio;
    real fnorm, gnorm, pnorm, xnorm = 0, fnorm1, actred, dirder, 
	    epsmch, prered;

/*     ********** */

/*     subroutine lmstr */

/*     the purpose of lmstr is to minimize the sum of the squares of */
/*     m nonlinear functions in n variables by a modification of */
/*     the levenberg-marquardt algorithm which uses minimal storage. */
/*     the user must provide a subroutine which calculates the */
/*     functions and the rows of the jacobian. */

/*     the subroutine statement is */

/*       subroutine lmstr(fcn,m,n,x,fvec,fjac,ldfjac,ftol,xtol,gtol, */
/*                        maxfev,diag,mode,factor,nprint,info,nfev, */
/*                        njev,ipvt,qtf,wa1,wa2,wa3,wa4) */

/*     where */

/*       fcn is the name of the user-supplied subroutine which */
/*         calculates the functions and the rows of the jacobian. */
/*         fcn must be declared in an external statement in the */
/*         user calling program, and should be written as follows. */

/*         subroutine fcn(m,n,x,fvec,fjrow,iflag) */
/*         integer m,n,iflag */
/*         double precision x(n),fvec(m),fjrow(n) */
/*         ---------- */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. */
/*         if iflag = i calculate the (i-1)-st row of the */
/*         jacobian at x and return this vector in fjrow. */
/*         ---------- */
/*         return */
/*         end */

/*         the value of iflag should not be changed by fcn unless */
/*         the user wants to terminate execution of lmstr. */
/*         in this case set iflag to a negative integer. */

/*       m is a positive integer input variable set to the number */
/*         of functions. */

/*       n is a positive integer input variable set to the number */
/*         of variables. n must not exceed m. */

/*       x is an array of length n. on input x must contain */
/*         an initial estimate of the solution vector. on output x */
/*         contains the final estimate of the solution vector. */

/*       fvec is an output array of length m which contains */
/*         the functions evaluated at the output x. */

/*       fjac is an output n by n array. the upper triangle of fjac */
/*         contains an upper triangular matrix r such that */

/*                t     t           t */
/*               p *(jac *jac)*p = r *r, */

/*         where p is a permutation matrix and jac is the final */
/*         calculated jacobian. column j of p is column ipvt(j) */
/*         (see below) of the identity matrix. the lower triangular */
/*         part of fjac contains information generated during */
/*         the computation of r. */

/*       ldfjac is a positive integer input variable not less than n */
/*         which specifies the leading dimension of the array fjac. */

/*       ftol is a nonnegative input variable. termination */
/*         occurs when both the actual and predicted relative */
/*         reductions in the sum of squares are at most ftol. */
/*         therefore, ftol measures the relative error desired */
/*         in the sum of squares. */

/*       xtol is a nonnegative input variable. termination */
/*         occurs when the relative error between two consecutive */
/*         iterates is at most xtol. therefore, xtol measures the */
/*         relative error desired in the approximate solution. */

/*       gtol is a nonnegative input variable. termination */
/*         occurs when the cosine of the angle between fvec and */
/*         any column of the jacobian is at most gtol in absolute */
/*         value. therefore, gtol measures the orthogonality */
/*         desired between the function vector and the columns */
/*         of the jacobian. */

/*       maxfev is a positive integer input variable. termination */
/*         occurs when the number of calls to fcn with iflag = 1 */
/*         has reached maxfev. */

/*       diag is an array of length n. if mode = 1 (see */
/*         below), diag is internally set. if mode = 2, diag */
/*         must contain positive entries that serve as */
/*         multiplicative scale factors for the variables. */

/*       mode is an integer input variable. if mode = 1, the */
/*         variables will be scaled internally. if mode = 2, */
/*         the scaling is specified by the input diag. other */
/*         values of mode are equivalent to mode = 1. */

/*       factor is a positive input variable used in determining the */
/*         initial step bound. this bound is set to the product of */
/*         factor and the euclidean norm of diag*x if nonzero, or else */
/*         to factor itself. in most cases factor should lie in the */
/*         interval (.1,100.). 100. is a generally recommended value. */

/*       nprint is an integer input variable that enables controlled */
/*         printing of iterates if it is positive. in this case, */
/*         fcn is called with iflag = 0 at the beginning of the first */
/*         iteration and every nprint iterations thereafter and */
/*         immediately prior to return, with x and fvec available */
/*         for printing. if nprint is not positive, no special calls */
/*         of fcn with iflag = 0 are made. */

/*       info is an integer output variable. if the user has */
/*         terminated execution, info is set to the (negative) */
/*         value of iflag. see description of fcn. otherwise, */
/*         info is set as follows. */

/*         info = 0  improper input parameters. */

/*         info = 1  both actual and predicted relative reductions */
/*                   in the sum of squares are at most ftol. */

/*         info = 2  relative error between two consecutive iterates */
/*                   is at most xtol. */

/*         info = 3  conditions for info = 1 and info = 2 both hold. */

/*         info = 4  the cosine of the angle between fvec and any */
/*                   column of the jacobian is at most gtol in */
/*                   absolute value. */

/*         info = 5  number of calls to fcn with iflag = 1 has */
/*                   reached maxfev. */

/*         info = 6  ftol is too small. no further reduction in */
/*                   the sum of squares is possible. */

/*         info = 7  xtol is too small. no further improvement in */
/*                   the approximate solution x is possible. */

/*         info = 8  gtol is too small. fvec is orthogonal to the */
/*                   columns of the jacobian to machine precision. */

/*       nfev is an integer output variable set to the number of */
/*         calls to fcn with iflag = 1. */

/*       njev is an integer output variable set to the number of */
/*         calls to fcn with iflag = 2. */

/*       ipvt is an integer output array of length n. ipvt */
/*         defines a permutation matrix p such that jac*p = q*r, */
/*         where jac is the final calculated jacobian, q is */
/*         orthogonal (not stored), and r is upper triangular. */
/*         column j of p is column ipvt(j) of the identity matrix. */

/*       qtf is an output array of length n which contains */
/*         the first n elements of the vector (q transpose)*fvec. */

/*       wa1, wa2, and wa3 are work arrays of length n. */

/*       wa4 is a work array of length m. */

/*     subprograms called */

/*       user-supplied ...... fcn */

/*       minpack-supplied ... dpmpar,enorm,lmpar,qrfac,rwupdt */

/*       fortran-supplied ... dabs,dmax1,dmin1,dsqrt,mod */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, dudley v. goetschel, kenneth e. hillstrom, */
/*     jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --wa4;
    --fvec;
    --wa3;
    --wa2;
    --wa1;
    --qtf;
    --ipvt;
    --diag;
    --x;
    fjac_dim1 = *ldfjac;
    fjac_offset = 1 + fjac_dim1 * 1;
    fjac -= fjac_offset;

    /* Function Body */

/*     epsmch is the machine precision. */

    epsmch = __minpack_func__(dpmpar)(&c__1);

    *info = 0;
    iflag = 0;
    *nfev = 0;
    *njev = 0;

/*     check the input parameters for errors. */

    if (*n <= 0 || *m < *n || *ldfjac < *n || *ftol < 0. || *xtol < 0. || 
	    *gtol < 0. || *maxfev <= 0 || *factor <= 0.) {
	goto L340;
    }
    if (*mode != 2) {
	goto L20;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	if (diag[j] <= 0.) {
	    goto L340;
	}
/* L10: */
    }
L20:

/*     evaluate the function at the starting point */
/*     and calculate its norm. */

    iflag = 1;
    fcnderstr_mn(m, n, &x[1], &fvec[1], &wa3[1], &iflag);
    *nfev = 1;
    if (iflag < 0) {
	goto L340;
    }
    fnorm = __minpack_func__(enorm)(m, &fvec[1]);

/*     initialize levenberg-marquardt parameter and iteration counter. */

    par = 0.;
    iter = 1;

/*     beginning of the outer loop. */

L30:

/*        if requested, call fcn to enable printing of iterates. */

    if (*nprint <= 0) {
	goto L40;
    }
    iflag = 0;
    if ((iter - 1) % *nprint == 0) {
	fcnderstr_mn(m, n, &x[1], &fvec[1], &wa3[1], &iflag);
    }
    if (iflag < 0) {
	goto L340;
    }
L40:

/*        compute the qr factorization of the jacobian matrix */
/*        calculated one row at a time, while simultaneously */
/*        forming (q transpose)*fvec and storing the first */
/*        n components in qtf. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	qtf[j] = 0.;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    fjac[i__ + j * fjac_dim1] = 0.;
/* L50: */
	}
/* L60: */
    }
    iflag = 2;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fcnderstr_mn(m, n, &x[1], &fvec[1], &wa3[1], &iflag);
	if (iflag < 0) {
	    goto L340;
	}
	temp = fvec[i__];
	__minpack_func__(rwupdt)(n, &fjac[fjac_offset], ldfjac, &wa3[1], &qtf[1], &temp, &wa1[
		1], &wa2[1]);
	++iflag;
/* L70: */
    }
    ++(*njev);

/*        if the jacobian is rank deficient, call qrfac to */
/*        reorder its columns and update the components of qtf. */

    sing = FALSE_;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	if (fjac[j + j * fjac_dim1] == 0.) {
	    sing = TRUE_;
	}
	ipvt[j] = j;
	wa2[j] = __minpack_func__(enorm)(&j, &fjac[j * fjac_dim1 + 1]);
/* L80: */
    }
    if (! sing) {
	goto L130;
    }
    __minpack_func__(qrfac)(n, n, &fjac[fjac_offset], ldfjac, &c_true, &ipvt[1], n, &wa1[1], &
	    wa2[1], &wa3[1]);
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	if (fjac[j + j * fjac_dim1] == 0.) {
	    goto L110;
	}
	sum = 0.;
	i__2 = *n;
	for (i__ = j; i__ <= i__2; ++i__) {
	    sum += fjac[i__ + j * fjac_dim1] * qtf[i__];
/* L90: */
	}
	temp = -sum / fjac[j + j * fjac_dim1];
	i__2 = *n;
	for (i__ = j; i__ <= i__2; ++i__) {
	    qtf[i__] += fjac[i__ + j * fjac_dim1] * temp;
/* L100: */
	}
L110:
	fjac[j + j * fjac_dim1] = wa1[j];
/* L120: */
    }
L130:

/*        on the first iteration and if mode is 1, scale according */
/*        to the norms of the columns of the initial jacobian. */

    if (iter != 1) {
	goto L170;
    }
    if (*mode == 2) {
	goto L150;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	diag[j] = wa2[j];
	if (wa2[j] == 0.) {
	    diag[j] = 1.;
	}
/* L140: */
    }
L150:

/*        on the first iteration, calculate the norm of the scaled x */
/*        and initialize the step bound delta. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	wa3[j] = diag[j] * x[j];
/* L160: */
    }
    xnorm = __minpack_func__(enorm)(n, &wa3[1]);
    delta = *factor * xnorm;
    if (delta == 0.) {
	delta = *factor;
    }
L170:

/*        compute the norm of the scaled gradient. */

    gnorm = 0.;
    if (fnorm == 0.) {
	goto L210;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	l = ipvt[j];
	if (wa2[l] == 0.) {
	    goto L190;
	}
	sum = 0.;
	i__2 = j;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    sum += fjac[i__ + j * fjac_dim1] * (qtf[i__] / fnorm);
/* L180: */
	}
/* Computing MAX */
	d__2 = gnorm, d__3 = (d__1 = sum / wa2[l], abs(d__1));
	gnorm = max(d__2,d__3);
L190:
/* L200: */
	;
    }
L210:

/*        test for convergence of the gradient norm. */

    if (gnorm <= *gtol) {
	*info = 4;
    }
    if (*info != 0) {
	goto L340;
    }

/*        rescale if necessary. */

    if (*mode == 2) {
	goto L230;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
/* Computing MAX */
	d__1 = diag[j], d__2 = wa2[j];
	diag[j] = max(d__1,d__2);
/* L220: */
    }
L230:

/*        beginning of the inner loop. */

L240:

/*           determine the levenberg-marquardt parameter. */

    __minpack_func__(lmpar)(n, &fjac[fjac_offset], ldfjac, &ipvt[1], &diag[1], &qtf[1], &delta,
	     &par, &wa1[1], &wa2[1], &wa3[1], &wa4[1]);

/*           store the direction p and x + p. calculate the norm of p. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	wa1[j] = -wa1[j];
	wa2[j] = x[j] + wa1[j];
	wa3[j] = diag[j] * wa1[j];
/* L250: */
    }
    pnorm = __minpack_func__(enorm)(n, &wa3[1]);

/*           on the first iteration, adjust the initial step bound. */

    if (iter == 1) {
	delta = min(delta,pnorm);
    }

/*           evaluate the function at x + p and calculate its norm. */

    iflag = 1;
    fcnderstr_mn(m, n, &wa2[1], &wa4[1], &wa3[1], &iflag);
    ++(*nfev);
    if (iflag < 0) {
	goto L340;
    }
    fnorm1 = __minpack_func__(enorm)(m, &wa4[1]);

/*           compute the scaled actual reduction. */

    actred = -1.;
    if (p1 * fnorm1 < fnorm) {
/* Computing 2nd power */
	d__1 = fnorm1 / fnorm;
	actred = 1. - d__1 * d__1;
    }

/*           compute the scaled predicted reduction and */
/*           the scaled directional derivative. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	wa3[j] = 0.;
	l = ipvt[j];
	temp = wa1[l];
	i__2 = j;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    wa3[i__] += fjac[i__ + j * fjac_dim1] * temp;
/* L260: */
	}
/* L270: */
    }
    temp1 = __minpack_func__(enorm)(n, &wa3[1]) / fnorm;
    temp2 = sqrt(par) * pnorm / fnorm;
/* Computing 2nd power */
    d__1 = temp1;
/* Computing 2nd power */
    d__2 = temp2;
    prered = d__1 * d__1 + d__2 * d__2 / p5;
/* Computing 2nd power */
    d__1 = temp1;
/* Computing 2nd power */
    d__2 = temp2;
    dirder = -(d__1 * d__1 + d__2 * d__2);

/*           compute the ratio of the actual to the predicted */
/*           reduction. */

    ratio = 0.;
    if (prered != 0.) {
	ratio = actred / prered;
    }

/*           update the step bound. */

    if (ratio > p25) {
	goto L280;
    }
    if (actred >= 0.) {
	temp = p5;
    }
    if (actred < 0.) {
	temp = p5 * dirder / (dirder + p5 * actred);
    }
    if (p1 * fnorm1 >= fnorm || temp < p1) {
	temp = p1;
    }
/* Computing MIN */
    d__1 = delta, d__2 = pnorm / p1;
    delta = temp * min(d__1,d__2);
    par /= temp;
    goto L300;
L280:
    if (par != 0. && ratio < p75) {
	goto L290;
    }
    delta = pnorm / p5;
    par = p5 * par;
L290:
L300:

/*           test for successful iteration. */

    if (ratio < p0001) {
	goto L330;
    }

/*           successful iteration. update x, fvec, and their norms. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = wa2[j];
	wa2[j] = diag[j] * x[j];
/* L310: */
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fvec[i__] = wa4[i__];
/* L320: */
    }
    xnorm = __minpack_func__(enorm)(n, &wa2[1]);
    fnorm = fnorm1;
    ++iter;
L330:

/*           tests for convergence. */

    if (abs(actred) <= *ftol && prered <= *ftol && p5 * ratio <= 1.) {
	*info = 1;
    }
    if (delta <= *xtol * xnorm) {
	*info = 2;
    }
    if (abs(actred) <= *ftol && prered <= *ftol && p5 * ratio <= 1. && *info 
	    == 2) {
	*info = 3;
    }
    if (*info != 0) {
	goto L340;
    }

/*           tests for termination and stringent tolerances. */

    if (*nfev >= *maxfev) {
	*info = 5;
    }
    if (abs(actred) <= epsmch && prered <= epsmch && p5 * ratio <= 1.) {
	*info = 6;
    }
    if (delta <= epsmch * xnorm) {
	*info = 7;
    }
    if (gnorm <= epsmch) {
	*info = 8;
    }
    if (*info != 0) {
	goto L340;
    }

/*           end of the inner loop. repeat if iteration unsuccessful. */

    if (ratio < p0001) {
	goto L240;
    }

/*        end of the outer loop. */

    goto L30;
L340:

/*     termination, either normal or user imposed. */

    if (iflag < 0) {
	*info = iflag;
    }
    iflag = 0;
    if (*nprint > 0) {
	fcnderstr_mn(m, n, &x[1], &fvec[1], &wa3[1], &iflag);
    }
    return;

/*     last card of subroutine lmstr. */

} /* lmstr_ */

