#include <math.h>
#include "cminpack.h"
#include "vec.h"
#define real __cminpack_real__

void hybipt(int n, real *x, int nprob, real factor)
{
    /* Local variables */
    static real h__;
    static int j;
    static real tj;

/*     ********** */

/*     subroutine initpt */

/*     this subroutine specifies the standard starting points for */
/*     the functions defined by subroutine vecfcn. the subroutine */
/*     returns in x a multiple (factor) of the standard starting */
/*     point. for the sixth function the standard starting point is */
/*     zero, so in this case, if factor is not unity, then the */
/*     subroutine returns the vector  x(j) = factor, j=1,...,n. */

/*     the subroutine statement is */

/*       subroutine initpt(n,x,nprob,factor) */

/*     where */

/*       n is a positive integer input variable. */

/*       x is an output array of length n which contains the standard */
/*         starting point for problem nprob multiplied by factor. */

/*       nprob is a positive integer input variable which defines the */
/*         number of the problem. nprob must not exceed 14. */

/*       factor is an input variable which specifies the multiple of */
/*         the standard starting point. if factor is unity, no */
/*         multiplication is performed. */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --x;

    /* Function Body */

    /*     selection of initial point. */

    switch (nprob) {
	case 1:
            /*     rosenbrock function. */
            x[1] = -1.2;
            x[2] = 1.;
            break;
	case 2:
            /*     powell singular function. */
            x[1] = 3.;
            x[2] = -1.;
            x[3] = 0.;
            x[4] = 1.;
            break;
	case 3:
            /*     powell badly scaled function. */
            x[1] = 0.;
            x[2] = 1.;
            break;
	case 4:
            /*     wood function. */
            x[1] = -3.;
            x[2] = -1.;
            x[3] = -3.;
            x[4] = -1.;
            break;
	case 5:
            /*     helical valley function. */
            x[1] = -1.;
            x[2] = 0.;
            x[3] = 0.;
            break;
	case 6:
            /*     watson function. */
            for (j = 1; j <= n; ++j) {
                x[j] = 0.;
            }
            break;
	case 7:
            /*     chebyquad function. */
            h__ = 1. / (real) (n+1);
            for (j = 1; j <= n; ++j) {
                x[j] = (real) j * h__;
            }
            break;
	case 8:
            /*     brown almost-linear function. */
            for (j = 1; j <= n; ++j) {
                x[j] = .5;
            }
            break;
	case 9:
	case 10:
            /*     discrete boundary value and integral equation functions. */
            h__ = 1. / (real) (n+1);
            for (j = 1; j <= n; ++j) {
                tj = (real) j * h__;
                x[j] = tj * (tj - 1.);
            }
            break;
	case 11:
            /*     trigonometric function. */
            h__ = 1. / (real) (n);
            for (j = 1; j <= n; ++j) {
                x[j] = h__;
            }
            break;
	case 12:
            /*     variably dimensioned function. */
            h__ = 1. / (real) (n);
            for (j = 1; j <= n; ++j) {
                x[j] = 1. - (real) j * h__;
            }
            break;
	case 13:
        case 14:
            /*     broyden tridiagonal and banded functions. */
            for (j = 1; j <= n; ++j) {
                x[j] = -1.;
            }
            break;
    }

    /*     compute multiple of initial point. */

    if (factor == 1.) {
	return;
    }
    if (nprob == 6) {
        for (j = 1; j <= n; ++j) {
            x[j] = factor;
        }
    } else {
        for (j = 1; j <= n; ++j) {
            x[j] = factor * x[j];
        }
    }
} /* initpt_ */

