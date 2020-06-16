#include <math.h>
#include "cminpack.h"
#include "ssq.h"
#define real __cminpack_real__

void ssqjac(int m, int n, const real *x, real *fjac, int ldfjac, int nprob)
{
    /* Initialized data */

    const real v[11] = { 4.,2.,1.,.5,.25,.167,.125,.1,.0833,.0714, .0625 };

    /* System generated locals */
    real d__1;

    /* Local variables */
    int i, j, k;
    real s2, dx, ti;
    int mm1, nm1;
    real div, tpi, tmp1, tmp2, tmp3, tmp4, prod, temp;

/*     ********** */

/*     subroutine ssqjac */

/*     this subroutine defines the jacobian matrices of eighteen */
/*     nonlinear least squares problems. the problem dimensions are */
/*     as described in the prologue comments of ssqfcn. */

/*     the subroutine statement is */

/*       subroutine ssqjac(m,n,x,fjac,ldfjac,nprob) */

/*     where */

/*       m and n are positive int input variables. n must not */
/*         exceed m. */

/*       x is an input array of length n. */

/*       fjac is an m by n output array which contains the jacobian */
/*         matrix of the nprob function evaluated at x. */

/*       ldfjac is a positive int input variable not less than m */
/*         which specifies the leading dimension of the array fjac. */

/*       nprob is a positive int variable which defines the */
/*         number of the problem. nprob must not exceed 18. */

/*     subprograms called */

/*       fortran-supplied ... datan,dcos,dexp,dsin,dsqrt */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --x;
    fjac -= 1 + ldfjac;

    /* Function Body */

/*     jacobian routine selector. */

    switch (nprob) {

/*     linear function - full rank. */

        case 1:
            temp = 2. / (real) m;
            for (j = 1; j <= n; ++j) {
                for (i = 1; i <= m; ++i) {
                    fjac[i + j * ldfjac] = -temp;
                }
                fjac[j + j * ldfjac] += 1.;
            }
            break;

/*     linear function - rank 1. */

        case 2:
            for (j = 1; j <= n; ++j) {
                for (i = 1; i <= m; ++i) {
                    fjac[i + j * ldfjac] = (real) i * (real) j;
                }
            }
            break;

/*     linear function - rank 1 with zero columns and rows. */

        case 3:
            for (j = 1; j <= n; ++j) {
                for (i = 1; i <= m; ++i) {
                    fjac[i + j * ldfjac] = 0.;
                }
            }
#if 0
    if (nm1 < 2) {
	goto L120;
    }
    for (j = 2; j <= nm1; ++j) {
	i__2 = mm1;
	for (i__ = 2; i__ <= mm1; ++i__) {
	    i__3 = i__ - 1;
	    fjac[i__ + j * fjac_dim1] = (doublereal) i__3 * (doublereal) j;
/* L100: */
	}
/* L110: */
    }
L120:
#else
            nm1 = n - 1;
            mm1 = m - 1;
            if (nm1 >= 2) {
                for (j = 2; j <= nm1; ++j) {
                    for (i = 2; i <= mm1; ++i) {
                        fjac[i + j * ldfjac] = (real) (i - 1) * (real) j;
                    }
                }
            }
#endif
            break;

/*     rosenbrock function. */

        case 4:
            fjac[1 + 1 * ldfjac] = -20. * x[1];
            fjac[1 + 2 * ldfjac] = 10.;
            fjac[2 + 1 * ldfjac] = -1.;
            fjac[2 + 2 * ldfjac] = 0.;
            break;

/*     helical valley function. */

        case 5:
            tpi = 8. * atan(1.);
            temp = x[1] * x[1] + x[2] * x[2];
            tmp1 = tpi * temp;
            tmp2 = sqrt(temp);
            fjac[1 + 1 * ldfjac] = 100. * x[2] / tmp1;
            fjac[1 + 2 * ldfjac] = -100. * x[1] / tmp1;
            fjac[1 + 3 * ldfjac] = 10.;
            fjac[2 + 1 * ldfjac] = 10. * x[1] / tmp2;
            fjac[2 + 2 * ldfjac] = 10. * x[2] / tmp2;
            fjac[2 + 3 * ldfjac] = 0.;
            fjac[3 + 1 * ldfjac] = 0.;
            fjac[3 + 2 * ldfjac] = 0.;
            fjac[3 + 3 * ldfjac] = 1.;
            break;

/*     powell singular function. */

        case 6:
            for (j = 1; j <= 4; ++j) {
                for (i = 1; i <= 4; ++i) {
                    fjac[i + j * ldfjac] = 0.;
                }
            }
            fjac[1 + 1 * ldfjac] = 1.;
            fjac[1 + 2 * ldfjac] = 10.;
            fjac[2 + 3 * ldfjac] = sqrt(5.);
            fjac[2 + 4 * ldfjac] = -fjac[2 + 3 * ldfjac];
            fjac[3 + 2 * ldfjac] = 2. * (x[2] - 2. * x[3]);
            fjac[3 + 3 * ldfjac] = -2. * fjac[3 + 2 * ldfjac];
            fjac[4 + 1 * ldfjac] = 2. * sqrt(10.) * (x[1] - x[4]);
            fjac[4 + 4 * ldfjac] = -fjac[4 + 1 * ldfjac];
            break;

/*     freudenstein and roth function. */

        case 7:
            fjac[1 + 1 * ldfjac] = 1.;
            fjac[1 + 2 * ldfjac] = x[2] * (10. - 3. * x[2]) - 2.;
            fjac[2 + 1 * ldfjac] = 1.;
            fjac[2 + 2 * ldfjac] = x[2] * (2. + 3. * x[2]) - 14.;
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
                /* Computing 2nd power */
                d__1 = x[2] * tmp2 + x[3] * tmp3;
                tmp4 = d__1 * d__1;
                fjac[i + 1 * ldfjac] = -1.;
                fjac[i + 2 * ldfjac] = tmp1 * tmp2 / tmp4;
                fjac[i + 3 * ldfjac] = tmp1 * tmp3 / tmp4;
            }
            break;

/*     kowalik and osborne function. */

        case 9:
            for (i = 1; i <= 11; ++i) {
                tmp1 = v[i - 1] * (v[i - 1] + x[2]);
                tmp2 = v[i - 1] * (v[i - 1] + x[3]) + x[4];
                fjac[i + 1 * ldfjac] = -tmp1 / tmp2;
                fjac[i + 2 * ldfjac] = -v[i - 1] * x[1] / tmp2;
                fjac[i + 3 * ldfjac] = fjac[i + 1 * ldfjac] * fjac[i + 2 * ldfjac];
                fjac[i + 4 * ldfjac] = fjac[i + 3 * ldfjac] / v[i - 1];
            }
            break;

/*     meyer function. */

        case 10:
            for (i = 1; i <= 16; ++i) {
                temp = 5. * (real) i + 45. + x[3];
                tmp1 = x[2] / temp;
                tmp2 = exp(tmp1);
                fjac[i + 1 * ldfjac] = tmp2;
                fjac[i + 2 * ldfjac] = x[1] * tmp2 / temp;
                fjac[i + 3 * ldfjac] = -tmp1 * fjac[i + 2 * ldfjac];
            }
            break;

/*     watson function. */

        case 11:
            for (i = 1; i <= 29; ++i) {
                div = (real) i / 29.;
                s2 = 0.;
                dx = 1.;
                for (j = 1; j <= n; ++j) {
                    s2 += dx * x[j];
                    dx = div * dx;
                }
                temp = 2. * div * s2;
                dx = 1. / div;
                for (j = 1; j <= n; ++j) {
                    fjac[i + j * ldfjac] = dx * ((real) (j - 1) - temp);
                    dx = div * dx;
                }
            }
            for (j = 1; j <= n; ++j) {
                for (i = 30; i <= 31; ++i) {
                    fjac[i + j * ldfjac] = 0.;
                }
            }
            fjac[30 + 1 * ldfjac] = 1.;
            fjac[31 + 1 * ldfjac] = -2. * x[1];
            fjac[31 + 2 * ldfjac] = 1.;
            break;

/*     box 3-dimensional function. */

        case 12:
            for (i = 1; i <= m; ++i) {
                temp = (real) i;
                tmp1 = temp / 10.;
                fjac[i + 1 * ldfjac] = -tmp1 * exp(-tmp1 * x[1]);
                fjac[i + 2 * ldfjac] = tmp1 * exp(-tmp1 * x[2]);
                fjac[i + 3 * ldfjac] = exp(-temp) - exp(-tmp1);
            }
            break;

/*     jennrich and sampson function. */

        case 13:
            for (i = 1; i <= m; ++i) {
                temp = (real) i;
                fjac[i + 1 * ldfjac] = -temp * exp(temp * x[1]);
                fjac[i + 2 * ldfjac] = -temp * exp(temp * x[2]);
            }
            break;

/*     brown and dennis function. */

        case 14:
            for (i = 1; i <= m; ++i) {
                temp = (real) i / 5.;
                ti = sin(temp);
                tmp1 = x[1] + temp * x[2] - exp(temp);
                tmp2 = x[3] + ti * x[4] - cos(temp);
                fjac[i + 1 * ldfjac] = 2. * tmp1;
                fjac[i + 2 * ldfjac] = temp * fjac[i + 1 * ldfjac];
                fjac[i + 3 * ldfjac] = 2. * tmp2;
                fjac[i + 4 * ldfjac] = ti * fjac[i + 3 * ldfjac];
            }
            break;

/*     chebyquad function. */

        case 15:
            dx = 1. / (real) (n);
            for (j = 1; j <= n; ++j) {
                tmp1 = 1.;
                tmp2 = 2. * x[j] - 1.;
                temp = 2. * tmp2;
                tmp3 = 0.;
                tmp4 = 2.;
                for (i = 1; i <= m; ++i) {
                    fjac[i + j * ldfjac] = dx * tmp4;
                    ti = 4. * tmp2 + temp * tmp4 - tmp3;
                    tmp3 = tmp4;
                    tmp4 = ti;
                    ti = temp * tmp2 - tmp1;
                    tmp1 = tmp2;
                    tmp2 = ti;
                }
            }
            break;

/*     brown almost-linear function. */

        case 16:
            prod = 1.;
            for (j = 1; j <= n; ++j) {
                prod = x[j] * prod;
                for (i = 1; i <= n; ++i) {
                    fjac[i + j * ldfjac] = 1.;
                }
                fjac[j + j * ldfjac] = 2.;
            }
            for (j = 1; j <= n; ++j) {
                temp = x[j];
                if (temp == 0.) {
                    temp = 1.;
                    prod = 1.;
                    for (k = 1; k <= n; ++k) {
                        if (k != j) {
                            prod = x[k] * prod;
                        }
                    }
                }
                fjac[n + j * ldfjac] = prod / temp;
            }
            break;

/*     osborne 1 function. */

        case 17:
            for (i = 1; i <= 33; ++i) {
                temp = 10. * (real) (i - 1);
                tmp1 = exp(-x[4] * temp);
                tmp2 = exp(-x[5] * temp);
                fjac[i + 1 * ldfjac] = -1.;
                fjac[i + 2 * ldfjac] = -tmp1;
                fjac[i + 3 * ldfjac] = -tmp2;
                fjac[i + 4 * ldfjac] = temp * x[2] * tmp1;
                fjac[i + 5 * ldfjac] = temp * x[3] * tmp2;
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
                fjac[i + 1 * ldfjac] = -tmp1;
                fjac[i + 2 * ldfjac] = -tmp2;
                fjac[i + 3 * ldfjac] = -tmp3;
                fjac[i + 4 * ldfjac] = -tmp4;
                fjac[i + 5 * ldfjac] = temp * x[1] * tmp1;
                /* Computing 2nd power */
                d__1 = temp - x[9];
                fjac[i + 6 * ldfjac] = x[2] * (d__1 * d__1) * tmp2;
                /* Computing 2nd power */
                d__1 = temp - x[10];
                fjac[i + 7 * ldfjac] = x[3] * (d__1 * d__1) * tmp3;
                /* Computing 2nd power */
                d__1 = temp - x[11];
                fjac[i + 8 * ldfjac] = x[4] * (d__1 * d__1) * tmp4;
                fjac[i + 9 * ldfjac] = -2. * x[2] * x[6] * (temp - x[9]) * tmp2;
                fjac[i + 10 * ldfjac] = -2. * x[3] * x[7] * (temp - x[10]) * tmp3;
                fjac[i + 11 * ldfjac] = -2. * x[4] * x[8] * (temp - x[11]) * tmp4;
            }
            break;
    }

/*     last card of subroutine ssqjac. */

} /* ssqjac_ */

