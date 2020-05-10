#include <math.h>
#include "cminpack.h"
#include "ssq.h"
#define real __cminpack_real__

void ssqfcn(int m, int n, const real *x, real *fvec, int nprob)
{
    /* Initialized data */

    const real v[11] = { 4.,2.,1.,.5,.25,.167,.125,.1,.0833,.0714, .0625 };
    const real y1[15] = { .14,.18,.22,.25,.29,.32,.35,.39,.37,.58,.73,
	    .96,1.34,2.1,4.39 };
    const real y2[11] = { .1957,.1947,.1735,.16,.0844,.0627,.0456,
	    .0342,.0323,.0235,.0246 };
    const real y3[16] = { 34780.,28610.,23650.,19630.,16370.,13720.,
	    11540.,9744.,8261.,7030.,6005.,5147.,4427.,3820.,3307.,2872. };
    const real y4[33] = { .844,.908,.932,.936,.925,.908,.881,.85,.818,
	    .784,.751,.718,.685,.658,.628,.603,.58,.558,.538,.522,.506,.49,
	    .478,.467,.457,.448,.438,.431,.424,.42,.414,.411,.406 };
    const real y5[65] = { 1.366,1.191,1.112,1.013,.991,.885,.831,.847,
	    .786,.725,.746,.679,.608,.655,.616,.606,.602,.626,.651,.724,.649,
	    .649,.694,.644,.624,.661,.612,.558,.533,.495,.5,.423,.395,.375,
	    .372,.391,.396,.405,.428,.429,.523,.562,.607,.653,.672,.708,.633,
	    .668,.645,.632,.591,.559,.597,.625,.739,.71,.729,.72,.636,.581,
	    .428,.292,.162,.098,.054 };

    /* System generated locals */
    real d__1;

    /* Local variables */
    static int i, j;
    static real s1, s2, dx, ti;
    static int nm1;
    static real div;
    static int iev;
    static real tpi, sum, tmp1, tmp2, tmp3, tmp4, prod, temp;

/*     ********** */

/*     subroutine ssqfcn */

/*     this subroutine defines the functions of eighteen nonlinear */
/*     least squares problems. the allowable values of (m,n) for */
/*     functions 1,2 and 3 are variable but with m .ge. n. */
/*     for functions 4,5,6,7,8,9 and 10 the values of (m,n) are */
/*     (2,2),(3,3),(4,4),(2,2),(15,3),(11,4) and (16,3), respectively. */
/*     function 11 (watson) has m = 31 with n usually 6 or 9. */
/*     however, any n, n = 2,...,31, is permitted. */
/*     functions 12,13 and 14 have n = 3,2 and 4, respectively, but */
/*     allow any m .ge. n, with the usual choices being 10,10 and 20. */
/*     function 15 (chebyquad) allows m and n variable with m .ge. n. */
/*     function 16 (brown) allows n variable with m = n. */
/*     for functions 17 and 18, the values of (m,n) are */
/*     (33,5) and (65,11), respectively. */

/*     the subroutine statement is */

/*       subroutine ssqfcn(m,n,x,fvec,nprob) */

/*     where */

/*       m and n are positive integer input variables. n must not */
/*         exceed m. */

/*       x is an input array of length n. */

/*       fvec is an output array of length m which contains the nprob */
/*         function evaluated at x. */

/*       nprob is a positive integer input variable which defines the */
/*         number of the problem. nprob must not exceed 18. */

/*     subprograms called */

/*       fortran-supplied ... datan,dcos,dexp,dsin,dsqrt,dsign */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --fvec;
    --x;

    /* Function Body */

/*     function routine selector. */

    switch (nprob) {

/*     linear function - full rank. */

        case 1:
            sum = 0.;
            for (j = 1; j <= n; ++j) {
                sum += x[j];
            }
            temp = 2. * sum / (real) (m) + 1.;
            for (i = 1; i <= m; ++i) {
                fvec[i] = -temp;
                if (i <= n) {
                    fvec[i] += x[i];
                }
            }
            break;

/*     linear function - rank 1. */

        case 2:
            sum = 0.;
            for (j = 1; j <= n; ++j) {
                sum += (real) j * x[j];
            }
            for (i = 1; i <= m; ++i) {
                fvec[i] = (real) i * sum - 1.;
            }
            break;

/*     linear function - rank 1 with zero columns and rows. */

        case 3:
            sum = 0.;
            nm1 = n - 1;
            if (nm1 >= 2) {
                for (j = 2; j <= nm1; ++j) {
                    sum += (real) j * x[j];
                }
            }
            for (i = 1; i <= m; ++i) {
                fvec[i] = (real) (i - 1) * sum - 1.;
            }
            fvec[m] = -1.;
            break;

/*     rosenbrock function. */

        case 4:
            fvec[1] = 10. * (x[2] - x[1] * x[1]);
            fvec[2] = 1. - x[1];
            break;

/*     helical valley function. */

        case 5:
            tpi = 8. * atan(1.);
            tmp1 = x[2] < 0. ? -.25 : .25;
            if (x[1] > 0.) {
                tmp1 = atan(x[2] / x[1]) / tpi;
            }
            if (x[1] < 0.) {
                tmp1 = atan(x[2] / x[1]) / tpi + .5;
            }
            tmp2 = sqrt(x[1] * x[1] + x[2] * x[2]);
            fvec[1] = 10. * (x[3] - 10. * tmp1);
            fvec[2] = 10. * (tmp2 - 1.);
            fvec[3] = x[3];
            break;

/*     powell singular function. */

        case 6:
            fvec[1] = x[1] + 10. * x[2];
            fvec[2] = sqrt(5.) * (x[3] - x[4]);
            /* Computing 2nd power */
            d__1 = x[2] - 2. * x[3];
            fvec[3] = d__1 * d__1;
            /* Computing 2nd power */
            d__1 = x[1] - x[4];
            fvec[4] = sqrt(10.) * (d__1 * d__1);
            break;

/*     freudenstein and roth function. */

        case 7:
            fvec[1] = -13. + x[1] + ((5. - x[2]) * x[2] - 2.) * x[2];
            fvec[2] = -29. + x[1] + ((1. + x[2]) * x[2] - 14.) * x[2];
            break;

/*     bard function. */

        case 8:
            for (i = 1; i <= 15; ++i) {
                tmp1 = (real) i;
                tmp2 = (real) (16 - i);
                tmp3 = tmp1;
                if (i > 8) {
                    tmp3 = tmp2;
                }
                fvec[i] = y1[i - 1] - (x[1] + tmp1 / (x[2] * tmp2 + x[3] * tmp3));
            }
            break;

/*     kowalik and osborne function. */

        case 9:
            for (i = 1; i <= 11; ++i) {
                tmp1 = v[i - 1] * (v[i - 1] + x[2]);
                tmp2 = v[i - 1] * (v[i - 1] + x[3]) + x[4];
                fvec[i] = y2[i - 1] - x[1] * tmp1 / tmp2;
            }
            break;

/*     meyer function. */

        case 10:
            for (i = 1; i <= 16; ++i) {
                temp = 5. * (real) i + 45. + x[3];
                tmp1 = x[2] / temp;
                tmp2 = exp(tmp1);
                fvec[i] = x[1] * tmp2 - y3[i - 1];
            }
            break;

/*     watson function. */

        case 11:
            for (i = 1; i <= 29; ++i) {
                div = (real) i / 29.;
                s1 = 0.;
                dx = 1.;
                for (j = 2; j <= n; ++j) {
                    s1 += (real) (j - 1) * dx * x[j];
                    dx = div * dx;
                }
                s2 = 0.;
                dx = 1.;
                for (j = 1; j <= n; ++j) {
                    s2 += dx * x[j];
                    dx = div * dx;
                }
                fvec[i] = s1 - s2 * s2 - 1.;
            }
            fvec[30] = x[1];
            fvec[31] = x[2] - x[1] * x[1] - 1.;
            break;

/*     box 3-dimensional function. */

        case 12:
            for (i = 1; i <= m; ++i) {
                temp = (real) i;
                tmp1 = temp / 10.;
                fvec[i] = exp(-tmp1 * x[1]) - exp(-tmp1 * x[2]) + (exp(-temp) - exp(-tmp1)) * x[3];
            }
            break;

/*     jennrich and sampson function. */

        case 13:
            for (i = 1; i <= m; ++i) {
                temp = (real) i;
                fvec[i] = 2. + 2. * temp - exp(temp * x[1]) - exp(temp * x[2]);
            }
            break;

/*     brown and dennis function. */

        case 14:
            for (i = 1; i <= m; ++i) {
                temp = (real) i / 5.;
                tmp1 = x[1] + temp * x[2] - exp(temp);
                tmp2 = x[3] + sin(temp) * x[4] - cos(temp);
                fvec[i] = tmp1 * tmp1 + tmp2 * tmp2;
            }
            break;

/*     chebyquad function. */

        case 15:
            for (i = 1; i <= m; ++i) {
                fvec[i] = 0.;
            }
            for (j = 1; j <= n; ++j) {
                tmp1 = 1.;
                tmp2 = 2. * x[j] - 1.;
                temp = 2. * tmp2;
                for (i = 1; i <= m; ++i) {
                    fvec[i] += tmp2;
                    ti = temp * tmp2 - tmp1;
                    tmp1 = tmp2;
                    tmp2 = ti;
                }
            }
            dx = 1. / (real) (n);
            iev = -1;
            for (i = 1; i <= m; ++i) {
                fvec[i] = dx * fvec[i];
                if (iev > 0) {
                    fvec[i] += 1. / (i * i - 1.);
                }
                iev = -iev;
            }
            break;

/*     brown almost-linear function. */

        case 16:
            sum = -((real) (n + 1));
            prod = 1.;
            for (j = 1; j <= n; ++j) {
                sum += x[j];
                prod = x[j] * prod;
            }
            for (i = 1; i <= n; ++i) {
                fvec[i] = x[i] + sum;
            }
            fvec[n] = prod - 1.;
            break;

/*     osborne 1 function. */

        case 17:
            for (i = 1; i <= 33; ++i) {
                temp = 10. * (real) (i - 1);
                tmp1 = exp(-x[4] * temp);
                tmp2 = exp(-x[5] * temp);
                fvec[i] = y4[i - 1] - (x[1] + x[2] * tmp1 + x[3] * tmp2);
            }
            break;

/*     osborne 2 function. */

        case 18:
            for (i = 1; i <= 65; ++i) {
                temp = (real) (i - 1) / 10.;
                tmp1 = exp(-x[5] * temp);
                /* Computing 2nd power */
                d__1 = temp - x[9];
                tmp2 = exp(-x[6] * (d__1 * d__1));
                /* Computing 2nd power */
                d__1 = temp - x[10];
                tmp3 = exp(-x[7] * (d__1 * d__1));
                /* Computing 2nd power */
                d__1 = temp - x[11];
                tmp4 = exp(-x[8] * (d__1 * d__1));
                fvec[i] = y5[i - 1] - (x[1] * tmp1 + x[2] * tmp2 + x[3] * tmp3 + x[4] * tmp4);
            }
            break;
    }


/*     last card of subroutine ssqfcn. */

} /* ssqfcn_ */

