/* qform.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "cminpack.h"
#include "cminpackP.h"

__cminpack_attr__
void __cminpack_func__(qform)(int m, int n, real *q, int
	ldq, real *wa)
{
    /* System generated locals */
    int q_dim1, q_offset;

    /* Local variables */
    int i, j, k, l, jm1, np1;
    real sum, temp;
    int minmn;

/*     ********** */

/*     subroutine qform */

/*     this subroutine proceeds from the computed qr factorization of */
/*     an m by n matrix a to accumulate the m by m orthogonal matrix */
/*     q from its factored form. */

/*     the subroutine statement is */

/*       subroutine qform(m,n,q,ldq,wa) */

/*     where */

/*       m is a positive integer input variable set to the number */
/*         of rows of a and the order of q. */

/*       n is a positive integer input variable set to the number */
/*         of columns of a. */

/*       q is an m by m array. on input the full lower trapezoid in */
/*         the first min(m,n) columns of q contains the factored form. */
/*         on output q has been accumulated into a square matrix. */

/*       ldq is a positive integer input variable not less than m */
/*         which specifies the leading dimension of the array q. */

/*       wa is a work array of length m. */

/*     subprograms called */

/*       fortran-supplied ... min0 */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --wa;
    q_dim1 = ldq;
    q_offset = 1 + q_dim1 * 1;
    q -= q_offset;

    /* Function Body */

/*     zero out upper triangle of q in the first min(m,n) columns. */

    minmn = min(m,n);
    if (minmn >= 2) {
        for (j = 2; j <= minmn; ++j) {
            jm1 = j - 1;
            for (i = 1; i <= jm1; ++i) {
                q[i + j * q_dim1] = 0.;
            }
        }
    }

/*     initialize remaining columns to those of the identity matrix. */

    np1 = n + 1;
    if (m >= np1) {
        for (j = np1; j <= m; ++j) {
            for (i = 1; i <= m; ++i) {
                q[i + j * q_dim1] = 0.;
            }
            q[j + j * q_dim1] = 1.;
        }
    }

/*     accumulate q from its factored form. */

    for (l = 1; l <= minmn; ++l) {
	k = minmn - l + 1;
	for (i = k; i <= m; ++i) {
	    wa[i] = q[i + k * q_dim1];
	    q[i + k * q_dim1] = 0.;
	}
	q[k + k * q_dim1] = 1.;
	if (wa[k] != 0.) {
            for (j = k; j <= m; ++j) {
                sum = 0.;
                for (i = k; i <= m; ++i) {
                    sum += q[i + j * q_dim1] * wa[i];
                }
                temp = sum / wa[k];
                for (i = k; i <= m; ++i) {
                    q[i + j * q_dim1] -= temp * wa[i];
                }
            }
        }
    }

/*     last card of subroutine qform. */

} /* qform_ */

