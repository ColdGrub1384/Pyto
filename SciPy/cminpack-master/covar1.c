#include "cminpack.h"
#include <math.h>
#include "cminpackP.h"

/* covar1 estimates the variance-covariance matrix:
   C = sigma**2 (JtJ)**+
   where (JtJ)**+ is the inverse of JtJ or the pseudo-inverse of JtJ (in case J does not have full rank),
   and sigma**2 = fsumsq / (m - k)
   where fsumsq is the residual sum of squares and k is the rank of J.
*/
__cminpack_attr__
int __cminpack_func__(covar1)(int m, int n, real fsumsq, real *r, int ldr, 
	const int *ipvt, real tol, real *wa)
{
    /* Local variables */
    int i, j, k, l, ii, jj;
    int sing;
    real temp, tolr;

/*     ********** */

/*     subroutine covar */

/*     given an m by n matrix a, the problem is to determine */
/*     the covariance matrix corresponding to a, defined as */

/*                    t */
/*           inverse(a *a) . */

/*     this subroutine completes the solution of the problem */
/*     if it is provided with the necessary information from the */
/*     qr factorization, with column pivoting, of a. that is, if */
/*     a*p = q*r, where p is a permutation matrix, q has orthogonal */
/*     columns, and r is an upper triangular matrix with diagonal */
/*     elements of nonincreasing magnitude, then covar expects */
/*     the full upper triangle of r and the permutation matrix p. */
/*     the covariance matrix is then computed as */

/*                      t     t */
/*           p*inverse(r *r)*p  . */

/*     if a is nearly rank deficient, it may be desirable to compute */
/*     the covariance matrix corresponding to the linearly independent */
/*     columns of a. to define the numerical rank of a, covar uses */
/*     the tolerance tol. if l is the largest integer such that */

/*           abs(r(l,l)) .gt. tol*abs(r(1,1)) , */

/*     then covar computes the covariance matrix corresponding to */
/*     the first l columns of r. for k greater than l, column */
/*     and row ipvt(k) of the covariance matrix are set to zero. */

/*     the subroutine statement is */

/*       subroutine covar(n,r,ldr,ipvt,tol,wa) */

/*     where */

/*       n is a positive integer input variable set to the order of r. */

/*       r is an n by n array. on input the full upper triangle must */
/*         contain the full upper triangle of the matrix r. on output */
/*         r contains the square symmetric covariance matrix. */

/*       ldr is a positive integer input variable not less than n */
/*         which specifies the leading dimension of the array r. */

/*       ipvt is an integer input array of length n which defines the */
/*         permutation matrix p such that a*p = q*r. column j of p */
/*         is column ipvt(j) of the identity matrix. */

/*       tol is a nonnegative input variable used to define the */
/*         numerical rank of a in the manner described above. */

/*       wa is a work array of length n. */

/*     subprograms called */

/*       fortran-supplied ... dabs */

/*     argonne national laboratory. minpack project. august 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    tolr = tol * fabs(r[0]);

/*     form the inverse of r in the full upper triangle of r. */

    l = -1;
    for (k = 0; k < n; ++k) {
	if (fabs(r[k + k * ldr]) <= tolr) {
	    break;
	}
	r[k + k * ldr] = 1. / r[k + k * ldr];
	if (k > 0) {
            for (j = 0; j < k; ++j) {
                // coverity[copy_paste_error]
                temp = r[k + k * ldr] * r[j + k * ldr];
                r[j + k * ldr] = 0.;
                for (i = 0; i <= j; ++i) {
                    r[i + k * ldr] -= temp * r[i + j * ldr];
                }
            }
        }
	l = k;
    }

/*     form the full upper triangle of the inverse of (r transpose)*r */
/*     in the full upper triangle of r. */

    if (l >= 0) {
        for (k = 0; k <= l; ++k) {
            if (k > 0) {
                for (j = 0; j < k; ++j) {
                    temp = r[j + k * ldr];
                    for (i = 0; i <= j; ++i) {
                        r[i + j * ldr] += temp * r[i + k * ldr];
                    }
                }
            }
            temp = r[k + k * ldr];
            for (i = 0; i <= k; ++i) {
                r[i + k * ldr] *= temp;
            }
        }
    }

/*     form the full lower triangle of the covariance matrix */
/*     in the strict lower triangle of r and in wa. */

    for (j = 0; j < n; ++j) {
	jj = ipvt[j]-1;
	sing = j > l;
	for (i = 0; i <= j; ++i) {
	    if (sing) {
		r[i + j * ldr] = 0.;
	    }
	    ii = ipvt[i]-1;
	    if (ii > jj) {
		r[ii + jj * ldr] = r[i + j * ldr];
	    }
	    else if (ii < jj) {
		r[jj + ii * ldr] = r[i + j * ldr];
	    }
	}
	wa[jj] = r[j + j * ldr];
    }

/*     symmetrize the covariance matrix in r. */

    temp = fsumsq / (m - (l + 1));
    for (j = 0; j < n; ++j) {
	for (i = 0; i < j; ++i) {
            r[j + i * ldr] *= temp;
	    r[i + j * ldr] = r[j + i * ldr];
	}
	r[j + j * ldr] = temp * wa[j];
    }

/*     last card of subroutine covar. */
    if (l == (n - 1)) {
        return 0;
    }
    return l + 1;
} /* covar_ */

