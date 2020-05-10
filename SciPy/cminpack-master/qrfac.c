#include "cminpack.h"
#include <math.h>
#ifdef USE_LAPACK
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#endif
#include "cminpackP.h"

__cminpack_attr__
void __cminpack_func__(qrfac)(int m, int n, real *a, int
	lda, int pivot, int *ipvt, int lipvt, real *rdiag,
	 real *acnorm, real *wa)
{
#ifdef USE_LAPACK
    __CLPK_integer m_ = m;
    __CLPK_integer n_ = n;
    __CLPK_integer lda_ = lda;
    __CLPK_integer *jpvt;

    int i, j, k;
    real t;
    real* tau = wa;
    const __CLPK_integer ltau = m > n ? n : m;
    __CLPK_integer lwork = -1;
    __CLPK_integer info = 0;
    real* work;

    if (pivot) {
        assert( lipvt >= n );
        if (sizeof(__CLPK_integer) != sizeof(ipvt[0])) {
            jpvt = malloc(n*sizeof(__CLPK_integer));
        } else {
            /* __CLPK_integer is actually an int, just do a cast */
            jpvt = (__CLPK_integer *)ipvt;
        }
        /* set all columns free */
        memset(jpvt, 0, sizeof(int)*n);
    }
    
    /* query optimal size of work */
    lwork = -1;
    if (pivot) {
        __cminpack_lapack__(geqp3_)(&m_,&n_,a,&lda_,jpvt,tau,tau,&lwork,&info);
        lwork = (int)tau[0];
        assert( lwork >= 3*n+1  );
    } else {
        __cminpack_lapack__(geqrf_)(&m_,&n_,a,&lda_,tau,tau,&lwork,&info);
        lwork = (int)tau[0];
        assert( lwork >= 1 && lwork >= n );
    }
    
    assert( info == 0 );
    
    /* alloc work area */
    work = (real *)malloc(sizeof(real)*lwork);
    assert(work != NULL);
    
    /* set acnorm first (from the doc of qrfac, acnorm may point to the same area as rdiag) */
    if (acnorm != rdiag) {
        for (j = 0; j < n; ++j) {
            acnorm[j] = __cminpack_enorm__(m, &a[j * lda]);
        }
    }
    
    /* QR decomposition */
    if (pivot) {
        __cminpack_lapack__(geqp3_)(&m_,&n_,a,&lda_,jpvt,tau,work,&lwork,&info);
    } else {
        __cminpack_lapack__(geqrf_)(&m_,&n_,a,&lda_,tau,work,&lwork,&info);
    }
    assert(info == 0);
    
    /* set rdiag, before the diagonal is replaced */
    memset(rdiag, 0, sizeof(real)*n);
    for(i=0 ; i<n ; ++i) {
        rdiag[i] = a[i*lda+i];
    }
    
    /* modify lower trinagular part to look like qrfac's output */
    for(i=0 ; i<ltau ; ++i) {
        k = i*lda+i;
        t = tau[i];
        a[k] = t;
        for(j=i+1 ; j<m ; j++) {
            k++;
            a[k] *= t;
        }
    }
    
    free(work);
    if (pivot) {
        /* convert back jpvt to ipvt */
        if (sizeof(__CLPK_integer) != sizeof(ipvt[0])) {
            for(i=0; i<n; ++i) {
                ipvt[i] = jpvt[i];
            }
            free(jpvt);
        }
    }
#else /* !USE_LAPACK */
    /* Initialized data */

#define p05 .05

    /* System generated locals */
    real d1;

    /* Local variables */
    int i, j, k, jp1;
    real sum;
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
    (void)lipvt;

/*     epsmch is the machine precision. */

    epsmch = __cminpack_func__(dpmpar)(1);

/*     compute the initial column norms and initialize several arrays. */

    for (j = 0; j < n; ++j) {
	acnorm[j] = __cminpack_enorm__(m, &a[j * lda + 0]);
	rdiag[j] = acnorm[j];
	wa[j] = rdiag[j];
	if (pivot) {
	    ipvt[j] = j+1;
	}
    }

/*     reduce a to r with householder transformations. */

    minmn = min(m,n);
    for (j = 0; j < minmn; ++j) {
	if (pivot) {

/*        bring the column of largest norm into the pivot position. */

            int kmax = j;
            for (k = j; k < n; ++k) {
                if (rdiag[k] > rdiag[kmax]) {
                    kmax = k;
                }
            }
            if (kmax != j) {
                for (i = 0; i < m; ++i) {
                    temp = a[i + j * lda];
                    a[i + j * lda] = a[i + kmax * lda];
                    a[i + kmax * lda] = temp;
                }
                rdiag[kmax] = rdiag[j];
                wa[kmax] = wa[j];
                k = ipvt[j];
                ipvt[j] = ipvt[kmax];
                ipvt[kmax] = k;
            }
        }

/*        compute the householder transformation to reduce the */
/*        j-th column of a to a multiple of the j-th unit vector. */

	ajnorm = __cminpack_enorm__(m - (j+1) + 1, &a[j + j * lda]);
	if (ajnorm != 0.) {
            if (a[j + j * lda] < 0.) {
                ajnorm = -ajnorm;
            }
            for (i = j; i < m; ++i) {
                a[i + j * lda] /= ajnorm;
            }
            a[j + j * lda] += 1.;

/*        apply the transformation to the remaining columns */
/*        and update the norms. */

            jp1 = j + 1;
            if (n > jp1) {
                for (k = jp1; k < n; ++k) {
                    sum = 0.;
                    for (i = j; i < m; ++i) {
                        sum += a[i + j * lda] * a[i + k * lda];
                    }
                    temp = sum / a[j + j * lda];
                    for (i = j; i < m; ++i) {
                        a[i + k * lda] -= temp * a[i + j * lda];
                    }
                    if (pivot && rdiag[k] != 0.) {
                        temp = a[j + k * lda] / rdiag[k];
                        /* Computing MAX */
                        d1 = 1. - temp * temp;
                        rdiag[k] *= sqrt((max((real)0.,d1)));
                        /* Computing 2nd power */
                        d1 = rdiag[k] / wa[k];
                        if (p05 * (d1 * d1) <= epsmch) {
                            rdiag[k] = __cminpack_enorm__(m - (j+1), &a[jp1 + k * lda]);
                            wa[k] = rdiag[k];
                        }
                    }
                }
            }
        }
	rdiag[j] = -ajnorm;
    }

/*     last card of subroutine qrfac. */
#endif /* !USE_LAPACK */
} /* qrfac_ */

