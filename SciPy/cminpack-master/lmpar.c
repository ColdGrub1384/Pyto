/* lmpar.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "cminpack.h"
#include <math.h>
#include "cminpackP.h"

__cminpack_attr__
void __cminpack_func__(lmpar)(int n, real *r, int ldr, 
	const int *ipvt, const real *diag, const real *qtb, real delta, 
	real *par, real *x, real *sdiag, real *wa1, 
	real *wa2)
{
    /* Initialized data */

#define p1 .1
#define p001 .001

    /* System generated locals */
    real d1, d2;

    /* Local variables */
    int j, l;
    real fp;
    real parc, parl;
    int iter;
    real temp, paru, dwarf;
    int nsing;
    real gnorm;
    real dxnorm;

/*     ********** */

/*     subroutine lmpar */

/*     given an m by n matrix a, an n by n nonsingular diagonal */
/*     matrix d, an m-vector b, and a positive number delta, */
/*     the problem is to determine a value for the parameter */
/*     par such that if x solves the system */

/*           a*x = b ,     sqrt(par)*d*x = 0 , */

/*     in the least squares sense, and dxnorm is the euclidean */
/*     norm of d*x, then either par is zero and */

/*           (dxnorm-delta) .le. 0.1*delta , */

/*     or par is positive and */

/*           abs(dxnorm-delta) .le. 0.1*delta . */

/*     this subroutine completes the solution of the problem */
/*     if it is provided with the necessary information from the */
/*     qr factorization, with column pivoting, of a. that is, if */
/*     a*p = q*r, where p is a permutation matrix, q has orthogonal */
/*     columns, and r is an upper triangular matrix with diagonal */
/*     elements of nonincreasing magnitude, then lmpar expects */
/*     the full upper triangle of r, the permutation matrix p, */
/*     and the first n components of (q transpose)*b. on output */
/*     lmpar also provides an upper triangular matrix s such that */

/*            t   t                   t */
/*           p *(a *a + par*d*d)*p = s *s . */

/*     s is employed within lmpar and may be of separate interest. */

/*     only a few iterations are generally needed for convergence */
/*     of the algorithm. if, however, the limit of 10 iterations */
/*     is reached, then the output par will contain the best */
/*     value obtained so far. */

/*     the subroutine statement is */

/*       subroutine lmpar(n,r,ldr,ipvt,diag,qtb,delta,par,x,sdiag, */
/*                        wa1,wa2) */

/*     where */

/*       n is a positive integer input variable set to the order of r. */

/*       r is an n by n array. on input the full upper triangle */
/*         must contain the full upper triangle of the matrix r. */
/*         on output the full upper triangle is unaltered, and the */
/*         strict lower triangle contains the strict upper triangle */
/*         (transposed) of the upper triangular matrix s. */

/*       ldr is a positive integer input variable not less than n */
/*         which specifies the leading dimension of the array r. */

/*       ipvt is an integer input array of length n which defines the */
/*         permutation matrix p such that a*p = q*r. column j of p */
/*         is column ipvt(j) of the identity matrix. */

/*       diag is an input array of length n which must contain the */
/*         diagonal elements of the matrix d. */

/*       qtb is an input array of length n which must contain the first */
/*         n elements of the vector (q transpose)*b. */

/*       delta is a positive input variable which specifies an upper */
/*         bound on the euclidean norm of d*x. */

/*       par is a nonnegative variable. on input par contains an */
/*         initial estimate of the levenberg-marquardt parameter. */
/*         on output par contains the final estimate. */

/*       x is an output array of length n which contains the least */
/*         squares solution of the system a*x = b, sqrt(par)*d*x = 0, */
/*         for the output par. */

/*       sdiag is an output array of length n which contains the */
/*         diagonal elements of the upper triangular matrix s. */

/*       wa1 and wa2 are work arrays of length n. */

/*     subprograms called */

/*       minpack-supplied ... dpmpar,enorm,qrsolv */

/*       fortran-supplied ... dabs,dmax1,dmin1,dsqrt */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */

/*     dwarf is the smallest positive magnitude. */

    dwarf = __cminpack_func__(dpmpar)(2);

/*     compute and store in x the gauss-newton direction. if the */
/*     jacobian is rank-deficient, obtain a least squares solution. */

    nsing = n;
    for (j = 0; j < n; ++j) {
	wa1[j] = qtb[j];
	if (r[j + j * ldr] == 0. && nsing == n) {
	    nsing = j;
	}
	if (nsing < n) {
	    wa1[j] = 0.;
	}
    }
# ifdef USE_CBLAS
    __cminpack_cblas__(trsv)(CblasColMajor, CblasUpper, CblasNoTrans, CblasNonUnit, nsing, r, ldr, wa1, 1);
# else
    if (nsing >= 1) {
        int k;
        for (k = 1; k <= nsing; ++k) {
            j = nsing - k;
            wa1[j] /= r[j + j * ldr];
            temp = wa1[j];
            if (j >= 1) {
                int i;
                for (i = 0; i < j; ++i) {
                    wa1[i] -= r[i + j * ldr] * temp;
                }
            }
        }
    }
# endif
    for (j = 0; j < n; ++j) {
	l = ipvt[j]-1;
	x[l] = wa1[j];
    }

/*     initialize the iteration counter. */
/*     evaluate the function at the origin, and test */
/*     for acceptance of the gauss-newton direction. */

    iter = 0;
    for (j = 0; j < n; ++j) {
	wa2[j] = diag[j] * x[j];
    }
    dxnorm = __cminpack_enorm__(n, wa2);
    fp = dxnorm - delta;
    if (fp <= p1 * delta) {
	goto TERMINATE;
    }

/*     if the jacobian is not rank deficient, the newton */
/*     step provides a lower bound, parl, for the zero of */
/*     the function. otherwise set this bound to zero. */

    parl = 0.;
    if (nsing >= n) {
        for (j = 0; j < n; ++j) {
            l = ipvt[j]-1;
            wa1[j] = diag[l] * (wa2[l] / dxnorm);
        }
#     ifdef USE_CBLAS
        __cminpack_cblas__(trsv)(CblasColMajor, CblasUpper, CblasTrans, CblasNonUnit, n, r, ldr, wa1, 1);
#     else
        for (j = 0; j < n; ++j) {
            real sum = 0.;
            if (j >= 1) {
                int i;
                for (i = 0; i < j; ++i) {
                    sum += r[i + j * ldr] * wa1[i];
                }
            }
            wa1[j] = (wa1[j] - sum) / r[j + j * ldr];
        }
#     endif
        temp = __cminpack_enorm__(n, wa1);
        parl = fp / delta / temp / temp;
    }

/*     calculate an upper bound, paru, for the zero of the function. */

    for (j = 0; j < n; ++j) {
        real sum;
#     ifdef USE_CBLAS
        sum = __cminpack_cblas__(dot)(j+1, &r[j*ldr], 1, qtb, 1);
#     else
        int i;
        sum = 0.;
        for (i = 0; i <= j; ++i) {
            sum += r[i + j * ldr] * qtb[i];
        }
#     endif
        l = ipvt[j]-1;
        wa1[j] = sum / diag[l];
    }
    gnorm = __cminpack_enorm__(n, wa1);
    paru = gnorm / delta;
    if (paru == 0.) {
        paru = dwarf / min(delta,(real)p1) /* / p001 ??? */;
    }

/*     if the input par lies outside of the interval (parl,paru), */
/*     set par to the closer endpoint. */

    *par = max(*par,parl);
    *par = min(*par,paru);
    if (*par == 0.) {
        *par = gnorm / dxnorm;
    }

/*     beginning of an iteration. */

    for (;;) {
        ++iter;

/*        evaluate the function at the current value of par. */

        if (*par == 0.) {
            /* Computing MAX */
            d1 = dwarf, d2 = p001 * paru;
            *par = max(d1,d2);
        }
        temp = sqrt(*par);
        for (j = 0; j < n; ++j) {
            wa1[j] = temp * diag[j];
        }
        __cminpack_func__(qrsolv)(n, r, ldr, ipvt, wa1, qtb, x, sdiag, wa2);
        for (j = 0; j < n; ++j) {
            wa2[j] = diag[j] * x[j];
        }
        dxnorm = __cminpack_enorm__(n, wa2);
        temp = fp;
        fp = dxnorm - delta;

/*        if the function is small enough, accept the current value */
/*        of par. also test for the exceptional cases where parl */
/*        is zero or the number of iterations has reached 10. */

        if (fabs(fp) <= p1 * delta || (parl == 0. && fp <= temp && temp < 0.) || iter == 10) {
            goto TERMINATE;
        }

/*        compute the newton correction. */

#     ifdef USE_CBLAS
        for (j = 0; j < nsing; ++j) {
            l = ipvt[j]-1;
            wa1[j] = diag[l] * (wa2[l] / dxnorm);
        }
        for (j = nsing; j < n; ++j) {
            wa1[j] = 0.;
        }
        /* exchange the diagonal of r with sdiag */
        __cminpack_cblas__(swap)(n, r, ldr+1, sdiag, 1);
        /* solve lower(r).x = wa1, result id put in wa1 */
        __cminpack_cblas__(trsv)(CblasColMajor, CblasLower, CblasNoTrans, CblasNonUnit, nsing, r, ldr, wa1, 1);
        /* exchange the diagonal of r with sdiag */
        __cminpack_cblas__(swap)(n, r, ldr+1, sdiag, 1);
#     else /* !USE_CBLAS */
        for (j = 0; j < n; ++j) {
            l = ipvt[j]-1;
            wa1[j] = diag[l] * (wa2[l] / dxnorm);
        }
        for (j = 0; j < n; ++j) {
            wa1[j] /= sdiag[j];
            temp = wa1[j];
            if (n > j+1) {
                int i;
                for (i = j+1; i < n; ++i) {
                    wa1[i] -= r[i + j * ldr] * temp;
                }
            }
        }
#     endif /* !USE_CBLAS */
        temp = __cminpack_enorm__(n, wa1);
        parc = fp / delta / temp / temp;

/*        depending on the sign of the function, update parl or paru. */

        if (fp > 0.) {
            parl = max(parl,*par);
        }
        if (fp < 0.) {
            paru = min(paru,*par);
        }

/*        compute an improved estimate for par. */

        /* Computing MAX */
        d1 = parl, d2 = *par + parc;
        *par = max(d1,d2);

/*        end of an iteration. */

    }
TERMINATE:

/*     termination. */

    if (iter == 0) {
	*par = 0.;
    }

/*     last card of subroutine lmpar. */

} /* lmpar_ */

