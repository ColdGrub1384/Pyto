/* dogleg.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "minpack.h"
#include <math.h>
#include "minpackP.h"

/* Table of constant values */

__minpack_attr__
void __minpack_func__(dogleg)(const int *n, const real *r__, const int *lr, 
	const real *diag, const real *qtb, const real *delta, real *x, 
	real *wa1, real *wa2)
{
    /* System generated locals */
    int i__1, i__2;
    real d__1, d__2, d__3, d__4;

    /* Local variables */
    int i__, j, k, l, jj, jp1;
    real sum, temp, alpha, bnorm;
    real gnorm, qnorm, epsmch;
    real sgnorm;
    const int c__1 = 1;

/*     ********** */

/*     subroutine dogleg */

/*     given an m by n matrix a, an n by n nonsingular diagonal */
/*     matrix d, an m-vector b, and a positive number delta, the */
/*     problem is to determine the convex combination x of the */
/*     gauss-newton and scaled gradient directions that minimizes */
/*     (a*x - b) in the least squares sense, subject to the */
/*     restriction that the euclidean norm of d*x be at most delta. */

/*     this subroutine completes the solution of the problem */
/*     if it is provided with the necessary information from the */
/*     qr factorization of a. that is, if a = q*r, where q has */
/*     orthogonal columns and r is an upper triangular matrix, */
/*     then dogleg expects the full upper triangle of r and */
/*     the first n components of (q transpose)*b. */

/*     the subroutine statement is */

/*       subroutine dogleg(n,r,lr,diag,qtb,delta,x,wa1,wa2) */

/*     where */

/*       n is a positive integer input variable set to the order of r. */

/*       r is an input array of length lr which must contain the upper */
/*         triangular matrix r stored by rows. */

/*       lr is a positive integer input variable not less than */
/*         (n*(n+1))/2. */

/*       diag is an input array of length n which must contain the */
/*         diagonal elements of the matrix d. */

/*       qtb is an input array of length n which must contain the first */
/*         n elements of the vector (q transpose)*b. */

/*       delta is a positive input variable which specifies an upper */
/*         bound on the euclidean norm of d*x. */

/*       x is an output array of length n which contains the desired */
/*         convex combination of the gauss-newton direction and the */
/*         scaled gradient direction. */

/*       wa1 and wa2 are work arrays of length n. */

/*     subprograms called */

/*       minpack-supplied ... dpmpar,enorm */

/*       fortran-supplied ... dabs,dmax1,dmin1,dsqrt */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --wa2;
    --wa1;
    --x;
    --qtb;
    --diag;
    --r__;
    (void)lr;

    /* Function Body */

/*     epsmch is the machine precision. */

    epsmch = __minpack_func__(dpmpar)(&c__1);

/*     first, calculate the gauss-newton direction. */

    jj = *n * (*n + 1) / 2 + 1;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	j = *n - k + 1;
	jp1 = j + 1;
	jj -= k;
	l = jj + 1;
	sum = 0.;
	if (*n < jp1) {
	    goto L20;
	}
	i__2 = *n;
	for (i__ = jp1; i__ <= i__2; ++i__) {
	    sum += r__[l] * x[i__];
	    ++l;
/* L10: */
	}
L20:
	temp = r__[jj];
	if (temp != 0.) {
	    goto L40;
	}
	l = j;
	i__2 = j;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* Computing MAX */
	    d__2 = temp, d__3 = fabs(r__[l]);
	    temp = max(d__2,d__3);
	    l = l + *n - i__;
/* L30: */
	}
	temp = epsmch * temp;
	if (temp == 0.) {
	    temp = epsmch;
	}
L40:
	x[j] = (qtb[j] - sum) / temp;
/* L50: */
    }

/*     test whether the gauss-newton direction is acceptable. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	wa1[j] = 0.;
	wa2[j] = diag[j] * x[j];
/* L60: */
    }
    qnorm = __minpack_func__(enorm)(n, &wa2[1]);
    if (qnorm <= *delta) {
	/* goto L140; */
        return;
    }

/*     the gauss-newton direction is not acceptable. */
/*     next, calculate the scaled gradient direction. */

    l = 1;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	temp = qtb[j];
	i__2 = *n;
	for (i__ = j; i__ <= i__2; ++i__) {
	    wa1[i__] += r__[l] * temp;
	    ++l;
/* L70: */
	}
	wa1[j] /= diag[j];
/* L80: */
    }

/*     calculate the norm of the scaled gradient and test for */
/*     the special case in which the scaled gradient is zero. */

    gnorm = __minpack_func__(enorm)(n, &wa1[1]);
    sgnorm = 0.;
    alpha = *delta / qnorm;
    if (gnorm == 0.) {
	goto L120;
    }

/*     calculate the point along the scaled gradient */
/*     at which the quadratic is minimized. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	wa1[j] = wa1[j] / gnorm / diag[j];
/* L90: */
    }
    l = 1;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	sum = 0.;
	i__2 = *n;
	for (i__ = j; i__ <= i__2; ++i__) {
	    sum += r__[l] * wa1[i__];
	    ++l;
/* L100: */
	}
	wa2[j] = sum;
/* L110: */
    }
    temp = __minpack_func__(enorm)(n, &wa2[1]);
    sgnorm = gnorm / temp / temp;

/*     test whether the scaled gradient direction is acceptable. */

    alpha = 0.;
    if (sgnorm >= *delta) {
	goto L120;
    }

/*     the scaled gradient direction is not acceptable. */
/*     finally, calculate the point along the dogleg */
/*     at which the quadratic is minimized. */

    bnorm = __minpack_func__(enorm)(n, &qtb[1]);
    temp = bnorm / gnorm * (bnorm / qnorm) * (sgnorm / *delta);
/* Computing 2nd power */
    d__1 = sgnorm / *delta;
/* Computing 2nd power */
    d__2 = temp - *delta / qnorm;
/* Computing 2nd power */
    d__3 = *delta / qnorm;
/* Computing 2nd power */
    d__4 = sgnorm / *delta;
    temp = temp - *delta / qnorm * (d__1 * d__1) + sqrt(d__2 * d__2 + (1. - 
	    d__3 * d__3) * (1. - d__4 * d__4));
/* Computing 2nd power */
    d__1 = sgnorm / *delta;
    alpha = *delta / qnorm * (1. - d__1 * d__1) / temp;
L120:

/*     form appropriate convex combination of the gauss-newton */
/*     direction and the scaled gradient direction. */

    temp = (1. - alpha) * min(sgnorm,*delta);
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = temp * wa1[j] + alpha * x[j];
/* L130: */
    }
/* L140: */
    return;

/*     last card of subroutine dogleg. */

} /* dogleg_ */

