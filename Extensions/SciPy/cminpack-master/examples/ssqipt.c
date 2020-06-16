#include <math.h>
#include "cminpack.h"
#include "ssq.h"
#define real __cminpack_real__

void lmdipt(int n, real *x, int nprob, real factor)
{
    /* Local variables */
    static real h;
    static int j;

/*     ********** */

/*     subroutine initpt */

/*     this subroutine specifies the standard starting points for the */
/*     functions defined by subroutine ssqfcn. the subroutine returns */
/*     in x a multiple (factor) of the standard starting point. for */
/*     the 11th function the standard starting point is zero, so in */
/*     this case, if factor is not unity, then the subroutine returns */
/*     the vector  x(j) = factor, j=1,...,n. */

/*     the subroutine statement is */

/*       subroutine initpt(n,x,nprob,factor) */

/*     where */

/*       n is a positive integer input variable. */

/*       x is an output array of length n which contains the standard */
/*         starting point for problem nprob multiplied by factor. */

/*       nprob is a positive integer input variable which defines the */
/*         number of the problem. nprob must not exceed 18. */

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

/*     linear function - full rank or rank 1. */

        case 1:
        case 2:
        case 3:
            for (j = 1; j <= n; ++j) {
                x[j] = 1.;
            }
            break;

/*     rosenbrock function. */

        case 4:
            x[1] = -1.2;
            x[2] = 1.;
            break;

/*     helical valley function. */

        case 5:
            x[1] = -1.;
            x[2] = 0.;
            x[3] = 0.;
            break;

/*     powell singular function. */

        case 6:
            x[1] = 3.;
            x[2] = -1.;
            x[3] = 0.;
            x[4] = 1.;
            break;

/*     freudenstein and roth function. */

        case 7:
            x[1] = .5;
            x[2] = -2.;
            break;

/*     bard function. */

        case 8:
            x[1] = 1.;
            x[2] = 1.;
            x[3] = 1.;
            break;

/*     kowalik and osborne function. */

        case 9:
            x[1] = .25;
            x[2] = .39;
            x[3] = .415;
            x[4] = .39;
            break;

/*     meyer function. */

        case 10:
            x[1] = .02;
            x[2] = 4e3;
            x[3] = 250.;
            break;

/*     watson function. */

        case 11:
            for (j = 1; j <= n; ++j) {
                x[j] = 0.;
            }
            break;

/*     box 3-dimensional function. */

        case 12:
            x[1] = 0.;
            x[2] = 10.;
            x[3] = 20.;
            break;

/*     jennrich and sampson function. */

        case 13:
            x[1] = .3;
            x[2] = .4;
            break;

/*     brown and dennis function. */


        case 14:
            x[1] = 25.;
            x[2] = 5.;
            x[3] = -5.;
            x[4] = -1.;
            break;

/*     chebyquad function. */

        case 15:
            h = 1. / (real) (n + 1);
            for (j = 1; j <= n; ++j) {
                x[j] = (real) j * h;
            }
            break;

/*     brown almost-linear function. */

        case 16:
            for (j = 1; j <= n; ++j) {
                x[j] = .5;
            }
            break;

/*     osborne 1 function. */

        case 17:
            x[1] = .5;
            x[2] = 1.5;
            x[3] = -1.;
            x[4] = .01;
            x[5] = .02;
            break;

/*     osborne 2 function. */

        case 18:
            x[1] = 1.3;
            x[2] = .65;
            x[3] = .65;
            x[4] = .7;
            x[5] = .6;
            x[6] = 3.;
            x[7] = 5.;
            x[8] = 7.;
            x[9] = 2.;
            x[10] = 4.5;
            x[11] = 5.5;
            break;
    }

/*     compute multiple of initial point. */

    if (factor != 1.) {
        if (nprob != 11) {
            for (j = 1; j <= n; ++j) {
                x[j] *= factor;
            }
        } else {
            for (j = 1; j <= n; ++j) {
                x[j] = factor;
            }
        }
    }

/*     last card of subroutine initpt. */

} /* initpt_ */

