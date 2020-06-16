#include <math.h>
#include <assert.h>
#include "cminpack.h"
#include "vec.h"
#define real __cminpack_real__

static inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

static inline int min(int a, int b)
{
    return (a < b) ? a : b;
}

void vecjac(int n, const real *x, real *fjac, int ldfjac, int nprob)
{
    /* System generated locals */
    int fjac_offset;
    real d__1, d__2;

    /* Local variables */
    static real h__;
    static int i__, j, k, k1, k2, ml;
    static real ti, tj, tk;
    static int mu;
    static real tpi, sum, sum1, sum2, prod, temp, temp1, temp2, temp3, 
	    temp4;

/*     ********** */

/*     subroutine vecjac */

/*     this subroutine defines the jacobian matrices of fourteen */
/*     test functions. the problem dimensions are as described */
/*     in the prologue comments of vecfcn. */

/*     the subroutine statement is */

/*       subroutine vecjac(n,x,fjac,ldfjac,nprob) */

/*     where */

/*       n is a positive integer variable. */

/*       x is an array of length n. */

/*       fjac is an n by n array. on output fjac contains the */
/*         jacobian matrix of the nprob function evaluated at x. */

/*       ldfjac is a positive integer variable not less than n */
/*         which specifies the leading dimension of the array fjac. */

/*       nprob is a positive integer variable which defines the */
/*         number of the problem. nprob must not exceed 14. */

/*     subprograms called */

/*       fortran-supplied ... datan,dcos,dexp,dmin1,dsin,dsqrt, */
/*                            max0,min0 */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --x;
    fjac_offset = 1 + ldfjac;
    fjac -= fjac_offset;

    /* Function Body */

/*     jacobian routine selector. */
    assert(nprob >= 1 && nprob <=14);
    switch (nprob) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L50;
	case 4:  goto L60;
	case 5:  goto L90;
	case 6:  goto L100;
	case 7:  goto L200;
	case 8:  goto L230;
	case 9:  goto L290;
	case 10:  goto L320;
	case 11:  goto L350;
	case 12:  goto L380;
	case 13:  goto L420;
	case 14:  goto L450;
    }

/*     rosenbrock function. */

L10:
    fjac[1 * ldfjac + 1] = -1.;
    fjac[2 * ldfjac + 1] = 0.;
    fjac[1 * ldfjac + 2] = -20. * x[1];
    fjac[2 * ldfjac + 2] = 10.;
    goto L490;

/*     powell singular function. */

L20:
    for (k = 1; k <= 4; ++k) {
	for (j = 1; j <= 4; ++j) {
	    fjac[k + j * ldfjac] = 0.;
/* L30: */
	}
/* L40: */
    }
    fjac[1 * ldfjac + 1] = 1.;
    fjac[2 * ldfjac + 1] = 10.;
    fjac[3 * ldfjac + 2] = sqrt(5.);
    fjac[4 * ldfjac + 2] = -fjac[3 * ldfjac + 2];
    fjac[2 * ldfjac + 3] = 2. * (x[2] - 2. * x[3]);
    fjac[3 * ldfjac + 3] = -2. * fjac[2 * ldfjac + 3];
    fjac[1 * ldfjac + 4] = 2. * sqrt(10.) * (x[1] - x[4]);
    fjac[4 * ldfjac + 4] = -fjac[1 * ldfjac + 4];
    goto L490;

/*     powell badly scaled function. */

L50:
    fjac[1 * ldfjac + 1] = 1e4 * x[2];
    fjac[2 * ldfjac + 1] = 1e4 * x[1];
    fjac[1 * ldfjac + 2] = -exp(-x[1]);
    fjac[2 * ldfjac + 2] = -exp(-x[2]);
    goto L490;

/*     wood function. */

L60:
    for (k = 1; k <= 4; ++k) {
	for (j = 1; j <= 4; ++j) {
	    fjac[k + j * ldfjac] = 0.;
/* L70: */
	}
/* L80: */
    }
/* Computing 2nd power */
    d__1 = x[1];
    temp1 = x[2] - 3. * (d__1 * d__1);
/* Computing 2nd power */
    d__1 = x[3];
    temp2 = x[4] - 3. * (d__1 * d__1);
    fjac[1 * ldfjac + 1] = -200. * temp1 + 1.;
    fjac[2 * ldfjac + 1] = -200. * x[1];
    fjac[1 * ldfjac + 2] = -2. * 200. * x[1];
    fjac[2 * ldfjac + 2] = 200. + 20.2;
    fjac[4 * ldfjac + 2] = 19.8;
    fjac[3 * ldfjac + 3] = -180. * temp2 + 1.;
    fjac[4 * ldfjac + 3] = -180. * x[3];
    fjac[2 * ldfjac + 4] = 19.8;
    fjac[3 * ldfjac + 4] = -2. * 180. * x[3];
    fjac[4 * ldfjac + 4] = 180. + 20.2;
    goto L490;

/*     helical valley function. */

L90:
    tpi = 8. * atan(1.);
/* Computing 2nd power */
    d__1 = x[1];
/* Computing 2nd power */
    d__2 = x[2];
    temp = d__1 * d__1 + d__2 * d__2;
    temp1 = tpi * temp;
    temp2 = sqrt(temp);
    fjac[1 * ldfjac + 1] = 100. * x[2] / temp1;
    fjac[2 * ldfjac + 1] = -100. * x[1] / temp1;
    fjac[3 * ldfjac + 1] = 10.;
    fjac[1 * ldfjac + 2] = 10. * x[1] / temp2;
    fjac[2 * ldfjac + 2] = 10. * x[2] / temp2;
    fjac[3 * ldfjac + 2] = 0.;
    fjac[1 * ldfjac + 3] = 0.;
    fjac[2 * ldfjac + 3] = 0.;
    fjac[3 * ldfjac + 3] = 1.;
    goto L490;

/*     watson function. */

L100:
    for (k = 1; k <= n; ++k) {
	for (j = k; j <= n; ++j) {
	    fjac[k + j * ldfjac] = 0.;
/* L110: */
	}
/* L120: */
    }
    for (i__ = 1; i__ <= 29; ++i__) {
	ti = (real) i__ / 29.;
	sum1 = 0.;
	temp = 1.;
	for (j = 2; j <= n; ++j) {
	    sum1 += (real) (j-1) * temp * x[j];
	    temp = ti * temp;
/* L130: */
	}
	sum2 = 0.;
	temp = 1.;
	for (j = 1; j <= n; ++j) {
	    sum2 += temp * x[j];
	    temp = ti * temp;
/* L140: */
	}
/* Computing 2nd power */
	d__1 = sum2;
	temp1 = 2. * (sum1 - d__1 * d__1 - 1.);
	temp2 = 2. * sum2;
/* Computing 2nd power */
	d__1 = ti;
	temp = d__1 * d__1;
	tk = 1.;
	for (k = 1; k <= n; ++k) {
	    tj = tk;
	    for (j = k; j <= n; ++j) {
		fjac[k + j * ldfjac] += tj * (((real) (k-1) / ti - 
			temp2) * ((real) (j-1) / ti - temp2) - temp1);
		tj = ti * tj;
/* L150: */
	    }
	    tk = temp * tk;
/* L160: */
	}
/* L170: */
    }
/* Computing 2nd power */
    d__1 = x[1];
    fjac[1 * ldfjac + 1] = fjac[1 * ldfjac + 1] + 6. * (d__1 * d__1) - 2. * x[2] + 3.;
    fjac[2 * ldfjac + 1] -= 2. * x[1];
    fjac[2 * ldfjac + 2] += 1.;
    for (k = 1; k <= n; ++k) {
	for (j = k; j <= n; ++j) {
	    fjac[j + k * ldfjac] = fjac[k + j * ldfjac];
/* L180: */
	}
/* L190: */
    }
    goto L490;

/*     chebyquad function. */

L200:
    tk = 1. / (real) (n);
    for (j = 1; j <= n; ++j) {
	temp1 = 1.;
	temp2 = 2. * x[j] - 1.;
	temp = 2. * temp2;
	temp3 = 0.;
	temp4 = 2.;
	for (k = 1; k <= n; ++k) {
	    fjac[k + j * ldfjac] = tk * temp4;
	    ti = 4. * temp2 + temp * temp4 - temp3;
	    temp3 = temp4;
	    temp4 = ti;
	    ti = temp * temp2 - temp1;
	    temp1 = temp2;
	    temp2 = ti;
/* L210: */
	}
/* L220: */
    }
    goto L490;

/*     brown almost-linear function. */

L230:
    prod = 1.;
    for (j = 1; j <= n; ++j) {
	prod = x[j] * prod;
	for (k = 1; k <= n; ++k) {
	    fjac[k + j * ldfjac] = 1.;
/* L240: */
	}
	fjac[j + j * ldfjac] = 2.;
/* L250: */
    }
    for (j = 1; j <= n; ++j) {
	temp = x[j];
	if (temp != 0.) {
	    goto L270;
	}
	temp = 1.;
	prod = 1.;
	for (k = 1; k <= n; ++k) {
	    if (k != j) {
		prod = x[k] * prod;
	    }
/* L260: */
	}
L270:
	fjac[n + j * ldfjac] = prod / temp;
/* L280: */
    }
    goto L490;

/*     discrete boundary value function. */

L290:
    h__ = 1. / (real) (n+1);
    for (k = 1; k <= n; ++k) {
/* Computing 2nd power */
	d__1 = x[k] + (real) k * h__ + 1.;
	temp = 3. * (d__1 * d__1);
	for (j = 1; j <= n; ++j) {
	    fjac[k + j * ldfjac] = 0.;
/* L300: */
	}
/* Computing 2nd power */
	d__1 = h__;
	fjac[k + k * ldfjac] = 2. + temp * (d__1 * d__1) / 2.;
	if (k != 1) {
	    fjac[k + (k - 1) * ldfjac] = -1.;
	}
	if (k != n) {
	    fjac[k + (k + 1) * ldfjac] = -1.;
	}
/* L310: */
    }
    goto L490;

/*     discrete integral equation function. */

L320:
    h__ = 1. / (real) (n+1);
    for (k = 1; k <= n; ++k) {
	tk = (real) k * h__;
	for (j = 1; j <= n; ++j) {
	    tj = (real) j * h__;
/* Computing 2nd power */
	    d__1 = x[j] + tj + 1.;
	    temp = 3. * (d__1 * d__1);
/* Computing MIN */
	    d__1 = tj * (1. - tk), d__2 = tk * (1. - tj);
	    fjac[k + j * ldfjac] = h__ * min(d__1,d__2) * temp / 2.;
/* L330: */
	}
	fjac[k + k * ldfjac] += 1.;
/* L340: */
    }
    goto L490;

/*     trigonometric function. */

L350:
    for (j = 1; j <= n; ++j) {
	temp = sin(x[j]);
	for (k = 1; k <= n; ++k) {
	    fjac[k + j * ldfjac] = temp;
/* L360: */
	}
	fjac[j + j * ldfjac] = (real) (j+1) * temp - cos(x[j]);
/* L370: */
    }
    goto L490;

/*     variably dimensioned function. */

L380:
    sum = 0.;
    for (j = 1; j <= n; ++j) {
	sum += (real) j * (x[j] - 1.);
/* L390: */
    }
/* Computing 2nd power */
    d__1 = sum;
    temp = 1. + 6. * (d__1 * d__1);
    for (k = 1; k <= n; ++k) {
	for (j = k; j <= n; ++j) {
	    fjac[k + j * ldfjac] = (real) (k*j) * temp;
	    fjac[j + k * ldfjac] = fjac[k + j * ldfjac];
/* L400: */
	}
	fjac[k + k * ldfjac] += 1.;
/* L410: */
    }
    goto L490;

/*     broyden tridiagonal function. */

L420:
    for (k = 1; k <= n; ++k) {
	for (j = 1; j <= n; ++j) {
	    fjac[k + j * ldfjac] = 0.;
/* L430: */
	}
	fjac[k + k * ldfjac] = 3. - 4. * x[k];
	if (k != 1) {
	    fjac[k + (k - 1) * ldfjac] = -1.;
	}
	if (k != n) {
	    fjac[k + (k + 1) * ldfjac] = -2.;
	}
/* L440: */
    }
    goto L490;

/*     broyden banded function. */

L450:
    ml = 5;
    mu = 1;
    for (k = 1; k <= n; ++k) {
	for (j = 1; j <= n; ++j) {
	    fjac[k + j * ldfjac] = 0.;
/* L460: */
	}
/* Computing MAX */
	k1 = max(1,k-ml);
/* Computing MIN */
	k2 = min(k+mu,n);
	for (j = k1; j <= k2; ++j) {
	    if (j != k) {
		fjac[k + j * ldfjac] = -(1. + 2. * x[j]);
	    }
/* L470: */
	}
/* Computing 2nd power */
	d__1 = x[k];
	fjac[k + k * ldfjac] = 2. + 15. * (d__1 * d__1);
/* L480: */
    }
L490:
    return;

/*     last card of subroutine vecjac. */

} /* vecjac_ */

