/* qrfac.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "minpack.h"
#include <math.h>
#include "minpackP.h"


__minpack_attr__
void __minpack_func__(qrfac)(const int *m, const int *n, real *a, const int *
	lda, const int *pivot, int *ipvt, const int *lipvt, real *rdiag,
	 real *acnorm, real *wa)
{
    /* Initialized data */

#define p05 .05
    const int c__1 = 1;

    /* System generated locals */
    int a_dim1, a_offset, i__1, i__2, i__3;
    real d__1, d__2, d__3;

    /* Local variables */
    int i__, j, k, jp1;
    real sum;
    int kmax;
    real temp;
    int minmn;
    real epsmch;
    real ajnorm;

/*     ********** */

/*     subroutine qrfac */

/*     this subroutine uses householder transformations with column */
/*     pivoting (optional) to compute a qr factorization of the */
/*     m by n matrix a. that is, qrfac determines an orthogonal */
/*     matrix q, a permutation matrix p, and an upper trapezoidal */
/*     matrix r with diagonal elements of nonincreasing magnitude, */
/*     such that a*p = q*r. the householder transformation for */
/*     column k, k = 1,2,...,min(m,n), is of the form */

/*                           t */
/*           i - (1/u(k))*u*u */

/*     where u has zeros in the first k-1 positions. the form of */
/*     this transformation and the method of pivoting first */
/*     appeared in the corresponding linpack subroutine. */

/*     the subroutine statement is */

/*       subroutine qrfac(m,n,a,lda,pivot,ipvt,lipvt,rdiag,acnorm,wa) */

/*     where */

/*       m is a positive integer input variable set to the number */
/*         of rows of a. */

/*       n is a positive integer input variable set to the number */
/*         of columns of a. */

/*       a is an m by n array. on input a contains the matrix for */
/*         which the qr factorization is to be computed. on output */
/*         the strict upper trapezoidal part of a contains the strict */
/*         upper trapezoidal part of r, and the lower trapezoidal */
/*         part of a contains a factored form of q (the non-trivial */
/*         elements of the u vectors described above). */

/*       lda is a positive integer input variable not less than m */
/*         which specifies the leading dimension of the array a. */

/*       pivot is a logical input variable. if pivot is set true, */
/*         then column pivoting is enforced. if pivot is set false, */
/*         then no column pivoting is done. */

/*       ipvt is an integer output array of length lipvt. ipvt */
/*         defines the permutation matrix p such that a*p = q*r. */
/*         column j of p is column ipvt(j) of the identity matrix. */
/*         if pivot is false, ipvt is not referenced. */

/*       lipvt is a positive integer input variable. if pivot is false, */
/*         then lipvt may be as small as 1. if pivot is true, then */
/*         lipvt must be at least n. */

/*       rdiag is an output array of length n which contains the */
/*         diagonal elements of r. */

/*       acnorm is an output array of length n which contains the */
/*         norms of the corresponding columns of the input matrix a. */
/*         if this information is not needed, then acnorm can coincide */
/*         with rdiag. */

/*       wa is a work array of length n. if pivot is false, then wa */
/*         can coincide with rdiag. */

/*     subprograms called */

/*       minpack-supplied ... dpmpar,enorm */

/*       fortran-supplied ... dmax1,dsqrt,min0 */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --wa;
    --acnorm;
    --rdiag;
    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --ipvt;
    (void)lipvt;

    /* Function Body */

/*     epsmch is the machine precision. */

    epsmch = __minpack_func__(dpmpar)(&c__1);

/*     compute the initial column norms and initialize several arrays. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	acnorm[j] = __minpack_func__(enorm)(m, &a[j * a_dim1 + 1]);
	rdiag[j] = acnorm[j];
	wa[j] = rdiag[j];
	if (*pivot) {
	    ipvt[j] = j;
	}
/* L10: */
    }

/*     reduce a to r with householder transformations. */

    minmn = min(*m,*n);
    i__1 = minmn;
    for (j = 1; j <= i__1; ++j) {
	if (! (*pivot)) {
	    goto L40;
	}

/*        bring the column of largest norm into the pivot position. */

	kmax = j;
	i__2 = *n;
	for (k = j; k <= i__2; ++k) {
	    if (rdiag[k] > rdiag[kmax]) {
		kmax = k;
	    }
/* L20: */
	}
	if (kmax == j) {
	    goto L40;
	}
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    temp = a[i__ + j * a_dim1];
	    a[i__ + j * a_dim1] = a[i__ + kmax * a_dim1];
	    a[i__ + kmax * a_dim1] = temp;
/* L30: */
	}
	rdiag[kmax] = rdiag[j];
	wa[kmax] = wa[j];
	k = ipvt[j];
	ipvt[j] = ipvt[kmax];
	ipvt[kmax] = k;
L40:

/*        compute the householder transformation to reduce the */
/*        j-th column of a to a multiple of the j-th unit vector. */

	i__2 = *m - j + 1;
	ajnorm = __minpack_func__(enorm)(&i__2, &a[j + j * a_dim1]);
	if (ajnorm == 0.) {
	    goto L100;
	}
	if (a[j + j * a_dim1] < 0.) {
	    ajnorm = -ajnorm;
	}
	i__2 = *m;
	for (i__ = j; i__ <= i__2; ++i__) {
	    a[i__ + j * a_dim1] /= ajnorm;
/* L50: */
	}
	a[j + j * a_dim1] += 1.;

/*        apply the transformation to the remaining columns */
/*        and update the norms. */

	jp1 = j + 1;
	if (*n < jp1) {
	    goto L100;
	}
	i__2 = *n;
	for (k = jp1; k <= i__2; ++k) {
	    sum = 0.;
	    i__3 = *m;
	    for (i__ = j; i__ <= i__3; ++i__) {
		sum += a[i__ + j * a_dim1] * a[i__ + k * a_dim1];
/* L60: */
	    }
	    temp = sum / a[j + j * a_dim1];
	    i__3 = *m;
	    for (i__ = j; i__ <= i__3; ++i__) {
		a[i__ + k * a_dim1] -= temp * a[i__ + j * a_dim1];
/* L70: */
	    }
	    if (! (*pivot) || rdiag[k] == 0.) {
		goto L80;
	    }
	    temp = a[j + k * a_dim1] / rdiag[k];
/* Computing MAX */
/* Computing 2nd power */
	    d__3 = temp;
	    d__1 = 0., d__2 = 1. - d__3 * d__3;
	    rdiag[k] *= sqrt((max(d__1,d__2)));
/* Computing 2nd power */
	    d__1 = rdiag[k] / wa[k];
	    if (p05 * (d__1 * d__1) > epsmch) {
		goto L80;
	    }
	    i__3 = *m - j;
	    rdiag[k] = __minpack_func__(enorm)(&i__3, &a[jp1 + k * a_dim1]);
	    wa[k] = rdiag[k];
L80:
/* L90: */
	    ;
	}
L100:
	rdiag[j] = -ajnorm;
/* L110: */
    }
    return;

/*     last card of subroutine qrfac. */

} /* qrfac_ */

