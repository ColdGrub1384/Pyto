/* hybrj.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "cminpack.h"
#include <math.h>
#include "cminpackP.h"

__cminpack_attr__
int __cminpack_func__(hybrj)(__cminpack_decl_fcnder_nn__ void *p, int n, real *x, real *
	fvec, real *fjac, int ldfjac, real xtol, int
	maxfev, real *diag, int mode, real factor, int
	nprint, int *nfev, int *njev, real *r, 
	int lr, real *qtf, real *wa1, real *wa2, 
	real *wa3, real *wa4)
{
    /* Initialized data */

#define p1 .1
#define p5 .5
#define p001 .001
#define p0001 1e-4

    /* System generated locals */
    int fjac_dim1, fjac_offset;
    real d1, d2;

    /* Local variables */
    int i, j, l, jm1, iwa[1];
    real sum;
    int sing;
    int iter;
    real temp;
    int iflag;
    real delta = 0.;
    int jeval;
    int ncsuc;
    real ratio;
    real fnorm;
    real pnorm, xnorm = 0., fnorm1;
    int nslow1, nslow2;
    int ncfail;
    real actred, epsmch, prered;
    int info;

/*     ********** */

/*     subroutine hybrj */

/*     the purpose of hybrj is to find a zero of a system of */
/*     n nonlinear functions in n variables by a modification */
/*     of the powell hybrid method. the user must provide a */
/*     subroutine which calculates the functions and the jacobian. */

/*     the subroutine statement is */

/*       subroutine hybrj(fcn,n,x,fvec,fjac,ldfjac,xtol,maxfev,diag, */
/*                        mode,factor,nprint,info,nfev,njev,r,lr,qtf, */
/*                        wa1,wa2,wa3,wa4) */

/*     where */

/*       fcn is the name of the user-supplied subroutine which */
/*         calculates the functions and the jacobian. fcn must */
/*         be declared in an external statement in the user */
/*         calling program, and should be written as follows. */

/*         subroutine fcn(n,x,fvec,fjac,ldfjac,iflag) */
/*         integer n,ldfjac,iflag */
/*         double precision x(n),fvec(n),fjac(ldfjac,n) */
/*         ---------- */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. do not alter fjac. */
/*         if iflag = 2 calculate the jacobian at x and */
/*         return this matrix in fjac. do not alter fvec. */
/*         --------- */
/*         return */
/*         end */

/*         the value of iflag should not be changed by fcn unless */
/*         the user wants to terminate execution of hybrj. */
/*         in this case set iflag to a negative integer. */

/*       n is a positive integer input variable set to the number */
/*         of functions and variables. */

/*       x is an array of length n. on input x must contain */
/*         an initial estimate of the solution vector. on output x */
/*         contains the final estimate of the solution vector. */

/*       fvec is an output array of length n which contains */
/*         the functions evaluated at the output x. */

/*       fjac is an output n by n array which contains the */
/*         orthogonal matrix q produced by the qr factorization */
/*         of the final approximate jacobian. */

/*       ldfjac is a positive integer input variable not less than n */
/*         which specifies the leading dimension of the array fjac. */

/*       xtol is a nonnegative input variable. termination */
/*         occurs when the relative error between two consecutive */
/*         iterates is at most xtol. */

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
/*         for printing. fvec and fjac should not be altered. */
/*         if nprint is not positive, no special calls of fcn */
/*         with iflag = 0 are made. */

/*       info is an integer output variable. if the user has */
/*         terminated execution, info is set to the (negative) */
/*         value of iflag. see description of fcn. otherwise, */
/*         info is set as follows. */

/*         info = 0   improper input parameters. */

/*         info = 1   relative error between two consecutive iterates */
/*                    is at most xtol. */

/*         info = 2   number of calls to fcn with iflag = 1 has */
/*                    reached maxfev. */

/*         info = 3   xtol is too small. no further improvement in */
/*                    the approximate solution x is possible. */

/*         info = 4   iteration is not making good progress, as */
/*                    measured by the improvement from the last */
/*                    five jacobian evaluations. */

/*         info = 5   iteration is not making good progress, as */
/*                    measured by the improvement from the last */
/*                    ten iterations. */

/*       nfev is an integer output variable set to the number of */
/*         calls to fcn with iflag = 1. */

/*       njev is an integer output variable set to the number of */
/*         calls to fcn with iflag = 2. */

/*       r is an output array of length lr which contains the */
/*         upper triangular matrix produced by the qr factorization */
/*         of the final approximate jacobian, stored rowwise. */

/*       lr is a positive integer input variable not less than */
/*         (n*(n+1))/2. */

/*       qtf is an output array of length n which contains */
/*         the vector (q transpose)*fvec. */

/*       wa1, wa2, wa3, and wa4 are work arrays of length n. */

/*     subprograms called */

/*       user-supplied ...... fcn */

/*       minpack-supplied ... dogleg,dpmpar,enorm, */
/*                            qform,qrfac,r1mpyq,r1updt */

/*       fortran-supplied ... dabs,dmax1,dmin1,mod */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --wa4;
    --wa3;
    --wa2;
    --wa1;
    --qtf;
    --diag;
    --fvec;
    --x;
    fjac_dim1 = ldfjac;
    fjac_offset = 1 + fjac_dim1 * 1;
    fjac -= fjac_offset;
    --r;

    /* Function Body */

/*     epsmch is the machine precision. */

    epsmch = __cminpack_func__(dpmpar)(1);

    info = 0;
    iflag = 0;
    *nfev = 0;
    *njev = 0;

/*     check the input parameters for errors. */

    if (n <= 0 || ldfjac < n || xtol < 0. || maxfev <= 0 || factor <= 
	    0. || lr < n * (n + 1) / 2) {
	goto TERMINATE;
    }
    if (mode == 2) {
        for (j = 1; j <= n; ++j) {
            if (diag[j] <= 0.) {
                goto TERMINATE;
            }
        }
    }

/*     evaluate the function at the starting point */
/*     and calculate its norm. */

    iflag = fcnder_nn(p, n, &x[1], &fvec[1], &fjac[fjac_offset], ldfjac, 1);
    *nfev = 1;
    if (iflag < 0) {
	goto TERMINATE;
    }
    fnorm = __cminpack_enorm__(n, &fvec[1]);

/*     initialize iteration counter and monitors. */

    iter = 1;
    ncsuc = 0;
    ncfail = 0;
    nslow1 = 0;
    nslow2 = 0;

/*     beginning of the outer loop. */

    for (;;) {
        jeval = TRUE_;

/*        calculate the jacobian matrix. */

        iflag = fcnder_nn(p, n, &x[1], &fvec[1], &fjac[fjac_offset], ldfjac, 2);
        ++(*njev);
        if (iflag < 0) {
            goto TERMINATE;
        }

/*        compute the qr factorization of the jacobian. */

        __cminpack_func__(qrfac)(n, n, &fjac[fjac_offset], ldfjac, FALSE_, iwa, 1,
              &wa1[1], &wa2[1], &wa3[1]);

/*        on the first iteration and if mode is 1, scale according */
/*        to the norms of the columns of the initial jacobian. */

        if (iter == 1) {
            if (mode != 2) {
                for (j = 1; j <= n; ++j) {
                    diag[j] = wa2[j];
                    if (wa2[j] == 0.) {
                        diag[j] = 1.;
                    }
                }
            }

/*        on the first iteration, calculate the norm of the scaled x */
/*        and initialize the step bound delta. */

            for (j = 1; j <= n; ++j) {
                wa3[j] = diag[j] * x[j];
            }
            xnorm = __cminpack_enorm__(n, &wa3[1]);
            delta = factor * xnorm;
            if (delta == 0.) {
                delta = factor;
            }
        }

/*        form (q transpose)*fvec and store in qtf. */

        for (i = 1; i <= n; ++i) {
            qtf[i] = fvec[i];
        }
        for (j = 1; j <= n; ++j) {
            if (fjac[j + j * fjac_dim1] != 0.) {
                sum = 0.;
                for (i = j; i <= n; ++i) {
                    sum += fjac[i + j * fjac_dim1] * qtf[i];
                }
                temp = -sum / fjac[j + j * fjac_dim1];
                for (i = j; i <= n; ++i) {
                    qtf[i] += fjac[i + j * fjac_dim1] * temp;
                }
            }
        }

/*        copy the triangular factor of the qr factorization into r. */

        sing = FALSE_;
        for (j = 1; j <= n; ++j) {
            l = j;
            jm1 = j - 1;
            if (jm1 >= 1) {
                for (i = 1; i <= jm1; ++i) {
                    r[l] = fjac[i + j * fjac_dim1];
                    l = l + n - i;
                }
            }
            r[l] = wa1[j];
            if (wa1[j] == 0.) {
                sing = TRUE_;
            }
        }

/*        accumulate the orthogonal factor in fjac. */

        __cminpack_func__(qform)(n, n, &fjac[fjac_offset], ldfjac, &wa1[1]);

/*        rescale if necessary. */

        if (mode != 2) {
            for (j = 1; j <= n; ++j) {
                /* Computing MAX */
                d1 = diag[j], d2 = wa2[j];
                diag[j] = max(d1,d2);
            }
        }

/*        beginning of the inner loop. */

        for (;;) {

/*           if requested, call fcn to enable printing of iterates. */

            if (nprint > 0) {
                iflag = 0;
                if ((iter - 1) % nprint == 0) {
                    iflag = fcnder_nn(p, n, &x[1], &fvec[1], &fjac[fjac_offset], ldfjac, 0);
                }
                if (iflag < 0) {
                    goto TERMINATE;
                }
            }

/*           determine the direction p. */

            __cminpack_func__(dogleg)(n, &r[1], lr, &diag[1], &qtf[1], delta, &wa1[1], &wa2[1], &wa3[1]);

/*           store the direction p and x + p. calculate the norm of p. */

            for (j = 1; j <= n; ++j) {
                wa1[j] = -wa1[j];
                wa2[j] = x[j] + wa1[j];
                wa3[j] = diag[j] * wa1[j];
            }
            pnorm = __cminpack_enorm__(n, &wa3[1]);

/*           on the first iteration, adjust the initial step bound. */

            if (iter == 1) {
                delta = min(delta,pnorm);
            }

/*           evaluate the function at x + p and calculate its norm. */

            iflag = fcnder_nn(p, n, &wa2[1], &wa4[1], &fjac[fjac_offset], ldfjac, 1);
            ++(*nfev);
            if (iflag < 0) {
                goto TERMINATE;
            }
            fnorm1 = __cminpack_enorm__(n, &wa4[1]);

/*           compute the scaled actual reduction. */

            actred = -1.;
            if (fnorm1 < fnorm) {
                /* Computing 2nd power */
                d1 = fnorm1 / fnorm;
                actred = 1. - d1 * d1;
            }

/*           compute the scaled predicted reduction. */

            l = 1;
            for (i = 1; i <= n; ++i) {
                sum = 0.;
                for (j = i; j <= n; ++j) {
                    sum += r[l] * wa1[j];
                    ++l;
                }
                wa3[i] = qtf[i] + sum;
            }
            temp = __cminpack_enorm__(n, &wa3[1]);
            prered = 0.;
            if (temp < fnorm) {
                /* Computing 2nd power */
                d1 = temp / fnorm;
                prered = 1. - d1 * d1;
            }

/*           compute the ratio of the actual to the predicted */
/*           reduction. */

            ratio = 0.;
            if (prered > 0.) {
                ratio = actred / prered;
            }

/*           update the step bound. */

            if (ratio < p1) {
                ncsuc = 0;
                ++ncfail;
                delta = p5 * delta;
            } else {
                ncfail = 0;
                ++ncsuc;
                if (ratio >= p5 || ncsuc > 1) {
                    /* Computing MAX */
                    d1 = pnorm / p5;
                    delta = max(delta,d1);
                }
                if (fabs(ratio - 1.) <= p1) {
                    delta = pnorm / p5;
                }
            }

/*           test for successful iteration. */

            if (ratio >= p0001) {

/*           successful iteration. update x, fvec, and their norms. */

                for (j = 1; j <= n; ++j) {
                    x[j] = wa2[j];
                    wa2[j] = diag[j] * x[j];
                    fvec[j] = wa4[j];
                }
                xnorm = __cminpack_enorm__(n, &wa2[1]);
                fnorm = fnorm1;
                ++iter;
            }

/*           determine the progress of the iteration. */

            ++nslow1;
            if (actred >= p001) {
                nslow1 = 0;
            }
            if (jeval) {
                ++nslow2;
            }
            if (actred >= p1) {
                nslow2 = 0;
            }

/*           test for convergence. */

            if (delta <= xtol * xnorm || fnorm == 0.) {
                info = 1;
            }
            if (info != 0) {
                goto TERMINATE;
            }

/*           tests for termination and stringent tolerances. */

            if (*nfev >= maxfev) {
                info = 2;
            }
            /* Computing MAX */
            d1 = p1 * delta;
            if (p1 * max(d1,pnorm) <= epsmch * xnorm) {
                info = 3;
            }
            if (nslow2 == 5) {
                info = 4;
            }
            if (nslow1 == 10) {
                info = 5;
            }
            if (info != 0) {
                goto TERMINATE;
            }

/*           criterion for recalculating jacobian. */

            if (ncfail == 2) {
                goto TERMINATE_INNER_LOOP;
            }

/*           calculate the rank one modification to the jacobian */
/*           and update qtf if necessary. */

            for (j = 1; j <= n; ++j) {
                sum = 0.;
                for (i = 1; i <= n; ++i) {
                    sum += fjac[i + j * fjac_dim1] * wa4[i];
                }
                wa2[j] = (sum - wa3[j]) / pnorm;
                wa1[j] = diag[j] * (diag[j] * wa1[j] / pnorm);
                if (ratio >= p0001) {
                    qtf[j] = sum;
                }
            }

/*           compute the qr factorization of the updated jacobian. */

            __cminpack_func__(r1updt)(n, n, &r[1], lr, &wa1[1], &wa2[1], &wa3[1], &sing);
            __cminpack_func__(r1mpyq)(n, n, &fjac[fjac_offset], ldfjac, &wa2[1], &wa3[1]);
            __cminpack_func__(r1mpyq)(1, n, &qtf[1], 1, &wa2[1], &wa3[1]);

/*           end of the inner loop. */

            jeval = FALSE_;
        }
TERMINATE_INNER_LOOP:
        ;
/*        end of the outer loop. */

    }
TERMINATE:

/*     termination, either normal or user imposed. */

    if (iflag < 0) {
	info = iflag;
    }
    if (nprint > 0) {
	fcnder_nn(p, n, &x[1], &fvec[1], &fjac[fjac_offset], ldfjac, 0);
    }
    return info;

/*     last card of subroutine hybrj. */

} /* hybrj_ */

