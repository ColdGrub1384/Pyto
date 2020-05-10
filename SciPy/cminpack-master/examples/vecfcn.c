#include <math.h>
#include "cminpack.h"
#include "vec.h"
#define real __cminpack_real__

static inline real d_sign(real a, real b)
{
    real x;
    x = (a >= 0 ? a : -a);
    return( b >= 0 ? x : -x);
}

static inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

static inline int min(int a, int b)
{
    return (a < b) ? a : b;
}

void vecfcn(int n, const real *x, real *fvec, int nprob)
{
    /* System generated locals */
    real d__1, d__2;

    /* Local variables */
    static real h__;
    static int i__, j, k, k1, k2, ml;
    static real ti, tj, tk;
    static int mu, kp1, iev;
    static real tpi, sum, sum1, sum2, prod, temp, temp1, temp2;

/*     ********** */

/*     subroutine vecfcn */

/*     this subroutine defines fourteen test functions. the first */
/*     five test functions are of dimensions 2,4,2,4,3, respectively, */
/*     while the remaining test functions are of variable dimension */
/*     n for any n greater than or equal to 1 (problem 6 is an */
/*     exception to this, since it does not allow n = 1). */

/*     the subroutine statement is */

/*       subroutine vecfcn(n,x,fvec,nprob) */

/*     where */

/*       n is a positive integer input variable. */

/*       x is an input array of length n. */

/*       fvec is an output array of length n which contains the nprob */
/*         function vector evaluated at x. */

/*       nprob is a positive integer input variable which defines the */
/*         number of the problem. nprob must not exceed 14. */

/*     subprograms called */

/*       fortran-supplied ... datan,dcos,dexp,dsign,dsin,dsqrt, */
/*                            max0,min0 */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --fvec;
    --x;

    /* Function Body */

/*     problem selector. */

    switch (nprob) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L120;
	case 8:  goto L170;
	case 9:  goto L200;
	case 10:  goto L220;
	case 11:  goto L270;
	case 12:  goto L300;
	case 13:  goto L330;
	case 14:  goto L350;
    }

/*     rosenbrock function. */

L10:
    fvec[1] = 1. - x[1];
/* Computing 2nd power */
    d__1 = x[1];
    fvec[2] = 10. * (x[2] - d__1 * d__1);
    goto L380;

/*     powell singular function. */

L20:
    fvec[1] = x[1] + 10. * x[2];
    fvec[2] = sqrt(5.) * (x[3] - x[4]);
/* Computing 2nd power */
    d__1 = x[2] - 2. * x[3];
    fvec[3] = d__1 * d__1;
/* Computing 2nd power */
    d__1 = x[1] - x[4];
    fvec[4] = sqrt(10.) * (d__1 * d__1);
    goto L380;

/*     powell badly scaled function. */

L30:
    fvec[1] = 1e4 * x[1] * x[2] - 1.;
    fvec[2] = exp(-x[1]) + exp(-x[2]) - 1.0001;
    goto L380;

/*     wood function. */

L40:
/* Computing 2nd power */
    d__1 = x[1];
    temp1 = x[2] - d__1 * d__1;
/* Computing 2nd power */
    d__1 = x[3];
    temp2 = x[4] - d__1 * d__1;
    fvec[1] = -200. * x[1] * temp1 - (1. - x[1]);
    fvec[2] = 200. * temp1 + 20.2 * (x[2] - 1.) + 19.8 * (x[4] - 1.);
    fvec[3] = -180. * x[3] * temp2 - (1. - x[3]);
    fvec[4] = 180. * temp2 + 20.2 * (x[4] - 1.) + 19.8 * (x[2] - 1.);
    goto L380;

/*     helical valley function. */

L50:
    tpi = 8. * atan(1.);
    temp1 = d_sign(.25, x[2]);
    if (x[1] > 0.) {
	temp1 = atan(x[2] / x[1]) / tpi;
    }
    if (x[1] < 0.) {
	temp1 = atan(x[2] / x[1]) / tpi + .5;
    }
/* Computing 2nd power */
    d__1 = x[1];
/* Computing 2nd power */
    d__2 = x[2];
    temp2 = sqrt(d__1 * d__1 + d__2 * d__2);
    fvec[1] = 10. * (x[3] - 10. * temp1);
    fvec[2] = 10. * (temp2 - 1.);
    fvec[3] = x[3];
    goto L380;

/*     watson function. */

L60:
    for (k = 1; k <= n; ++k) {
	fvec[k] = 0.;
/* L70: */
    }
    for (i__ = 1; i__ <= 29; ++i__) {
	ti = (real) i__ / 29.;
	sum1 = 0.;
	temp = 1.;
	for (j = 2; j <= n; ++j) {
	    sum1 += (real) (j - 1) * temp * x[j];
	    temp = ti * temp;
/* L80: */
	}
	sum2 = 0.;
	temp = 1.;
	for (j = 1; j <= n; ++j) {
	    sum2 += temp * x[j];
	    temp = ti * temp;
/* L90: */
	}
/* Computing 2nd power */
	d__1 = sum2;
	temp1 = sum1 - d__1 * d__1 - 1.;
	temp2 = 2. * ti * sum2;
	temp = 1. / ti;
	for (k = 1; k <= n; ++k) {
	    fvec[k] += temp * ((real) (k - 1) - temp2) * temp1;
	    temp = ti * temp;
/* L100: */
	}
/* L110: */
    }
/* Computing 2nd power */
    d__1 = x[1];
    temp = x[2] - d__1 * d__1 - 1.;
    fvec[1] += x[1] * (1. - 2. * temp);
    fvec[2] += temp;
    goto L380;

/*     chebyquad function. */

L120:
    for (k = 1; k <= n; ++k) {
	fvec[k] = 0.;
/* L130: */
    }
    for (j = 1; j <= n; ++j) {
	temp1 = 1.;
	temp2 = 2. * x[j] - 1.;
	temp = 2. * temp2;
	for (i__ = 1; i__ <= n; ++i__) {
	    fvec[i__] += temp2;
	    ti = temp * temp2 - temp1;
	    temp1 = temp2;
	    temp2 = ti;
/* L140: */
	}
/* L150: */
    }
    tk = 1. / (real) (n);
    iev = -1;
    for (k = 1; k <= n; ++k) {
	fvec[k] = tk * fvec[k];
	if (iev > 0) {
/* Computing 2nd power */
	    d__1 = (real) k;
	    fvec[k] += 1. / (d__1 * d__1 - 1.);
	}
	iev = -iev;
/* L160: */
    }
    goto L380;

/*     brown almost-linear function. */

L170:
    sum = -((real) (n + 1));
    prod = 1.;
    for (j = 1; j <= n; ++j) {
	sum += x[j];
	prod = x[j] * prod;
/* L180: */
    }
    for (k = 1; k <= n; ++k) {
	fvec[k] = x[k] + sum;
/* L190: */
    }
    fvec[n] = prod - 1.;
    goto L380;

/*     discrete boundary value function. */

L200:
    h__ = 1. / (real) (n + 1);
    for (k = 1; k <= n; ++k) {
/* Computing 3rd power */
	d__1 = x[k] + (real) k * h__ + 1.;
	temp = d__1 * (d__1 * d__1);
	temp1 = 0.;
	if (k != 1) {
	    temp1 = x[k - 1];
	}
	temp2 = 0.;
	if (k != n) {
	    temp2 = x[k + 1];
	}
/* Computing 2nd power */
	d__1 = h__;
	fvec[k] = 2. * x[k] - temp1 - temp2 + temp * (d__1 * d__1) / 2.;
/* L210: */
    }
    goto L380;

/*     discrete integral equation function. */

L220:
    h__ = 1. / (real) (n + 1);
    for (k = 1; k <= n; ++k) {
	tk = (real) k * h__;
	sum1 = 0.;
	for (j = 1; j <= k; ++j) {
	    tj = (real) j * h__;
/* Computing 3rd power */
	    d__1 = x[j] + tj + 1.;
	    temp = d__1 * (d__1 * d__1);
	    sum1 += tj * temp;
/* L230: */
	}
	sum2 = 0.;
	kp1 = k + 1;
	if (n < kp1) {
	    goto L250;
	}
	for (j = kp1; j <= n; ++j) {
	    tj = (real) j * h__;
/* Computing 3rd power */
	    d__1 = x[j] + tj + 1.;
	    temp = d__1 * (d__1 * d__1);
	    sum2 += (1. - tj) * temp;
/* L240: */
	}
L250:
	fvec[k] = x[k] + h__ * ((1. - tk) * sum1 + tk * sum2) / 2.;
/* L260: */
    }
    goto L380;

/*     trigonometric function. */

L270:
    sum = 0.;
    for (j = 1; j <= n; ++j) {
	fvec[j] = cos(x[j]);
	sum += fvec[j];
/* L280: */
    }
    for (k = 1; k <= n; ++k) {
	fvec[k] = (real) (n + k) - sin(x[k]) - sum - (real) k * fvec[
		k];
/* L290: */
    }
    goto L380;

/*     variably dimensioned function. */

L300:
    sum = 0.;
    for (j = 1; j <= n; ++j) {
	sum += (real) j * (x[j] - 1.);
/* L310: */
    }
/* Computing 2nd power */
    d__1 = sum;
    temp = sum * (1. + 2. * (d__1 * d__1));
    for (k = 1; k <= n; ++k) {
	fvec[k] = x[k] - 1. + (real) k * temp;
/* L320: */
    }
    goto L380;

/*     broyden tridiagonal function. */

L330:
    for (k = 1; k <= n; ++k) {
	temp = (3. - 2. * x[k]) * x[k];
	temp1 = 0.;
	if (k != 1) {
	    temp1 = x[k - 1];
	}
	temp2 = 0.;
	if (k != n) {
	    temp2 = x[k + 1];
	}
	fvec[k] = temp - temp1 - 2. * temp2 + 1.;
/* L340: */
    }
    goto L380;

/*     broyden banded function. */

L350:
    ml = 5;
    mu = 1;
    for (k = 1; k <= n; ++k) {
/* Computing MAX */
	k1 = max(1,k-ml);
/* Computing MIN */
	k2 = min(k+mu,n);
	temp = 0.;
	for (j = k1; j <= k2; ++j) {
	    if (j != k) {
		temp += x[j] * (1. + x[j]);
	    }
/* L360: */
	}
/* Computing 2nd power */
	d__1 = x[k];
	fvec[k] = x[k] * (2. + 5. * (d__1 * d__1)) + 1. - temp;
/* L370: */
    }
L380:
    return;

/*     last card of subroutine vecfcn. */

} /* vecfcn_ */

