/* fdjac1.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "cminpack.h"
#include <math.h>
#include "cminpackP.h"

__cminpack_attr__
int __cminpack_func__(fdjac1)(__cminpack_decl_fcn_nn__ void *p, int n, real *x, const real *
	fvec, real *fjac, int ldfjac, int ml, 
	int mu, real epsfcn, real *wa1, real *wa2)
{
    /* System generated locals */
    int fjac_dim1, fjac_offset;

    /* Local variables */
    real h;
    int i, j, k;
    real eps, temp;
    int msum;
    real epsmch;
    int iflag = 0;

/*     ********** */

/*     subroutine fdjac1 */

/*     this subroutine computes a forward-difference approximation */
/*     to the n by n jacobian matrix associated with a specified */
/*     problem of n functions in n variables. if the jacobian has */
/*     a banded form, then function evaluations are saved by only */
/*     approximating the nonzero terms. */

/*     the subroutine statement is */

/*       subroutine fdjac1(fcn,n,x,fvec,fjac,ldfjac,iflag,ml,mu,epsfcn, */
/*                         wa1,wa2) */

/*     where */

/*       fcn is the name of the user-supplied subroutine which */
/*         calculates the functions. fcn must be declared */
/*         in an external statement in the user calling */
/*         program, and should be written as follows. */

/*         subroutine fcn(n,x,fvec,iflag) */
/*         integer n,iflag */
/*         double precision x(n),fvec(n) */
/*         ---------- */
/*         calculate the functions at x and */
/*         return this vector in fvec. */
/*         ---------- */
/*         return */
/*         end */

/*         the value of iflag should not be changed by fcn unless */
/*         the user wants to terminate execution of fdjac1. */
/*         in this case set iflag to a negative integer. */

/*       n is a positive integer input variable set to the number */
/*         of functions and variables. */

/*       x is an input array of length n. */

/*       fvec is an input array of length n which must contain the */
/*         functions evaluated at x. */

/*       fjac is an output n by n array which contains the */
/*         approximation to the jacobian matrix evaluated at x. */

/*       ldfjac is a positive integer input variable not less than n */
/*         which specifies the leading dimension of the array fjac. */

/*       iflag is an integer variable which can be used to terminate */
/*         the execution of fdjac1. see description of fcn. */

/*       ml is a nonnegative integer input variable which specifies */
/*         the number of subdiagonals within the band of the */
/*         jacobian matrix. if the jacobian is not banded, set */
/*         ml to at least n - 1. */

/*       epsfcn is an input variable used in determining a suitable */
/*         step length for the forward-difference approximation. this */
/*         approximation assumes that the relative errors in the */
/*         functions are of the order of epsfcn. if epsfcn is less */
/*         than the machine precision, it is assumed that the relative */
/*         errors in the functions are of the order of the machine */
/*         precision. */

/*       mu is a nonnegative integer input variable which specifies */
/*         the number of superdiagonals within the band of the */
/*         jacobian matrix. if the jacobian is not banded, set */
/*         mu to at least n - 1. */

/*       wa1 and wa2 are work arrays of length n. if ml + mu + 1 is at */
/*         least n, then the jacobian is considered dense, and wa2 is */
/*         not referenced. */

/*     subprograms called */

/*       minpack-supplied ... dpmpar */

/*       fortran-supplied ... dabs,dmax1,dsqrt */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --wa2;
    --wa1;
    --fvec;
    --x;
    fjac_dim1 = ldfjac;
    fjac_offset = 1 + fjac_dim1 * 1;
    fjac -= fjac_offset;

    /* Function Body */

/*     epsmch is the machine precision. */

    epsmch = __cminpack_func__(dpmpar)(1);

    eps = sqrt((max(epsfcn,epsmch)));
    msum = ml + mu + 1;
    if (msum >= n) {

/*        computation of dense approximate jacobian. */

        for (j = 1; j <= n; ++j) {
            temp = x[j];
            h = eps * fabs(temp);
            if (h == 0.) {
                h = eps;
            }
            x[j] = temp + h;
            /* the last parameter of fcn_nn() is set to 2 to differentiate
               calls made to compute the function from calls made to compute
               the Jacobian (see fcn() in examples/hybdrv.c, and how njev
               is used to compute the number of Jacobian evaluations) */
            iflag = fcn_nn(p, n, &x[1], &wa1[1], 2);
            if (iflag < 0) {
                return iflag;
            }
            x[j] = temp;
            for (i = 1; i <= n; ++i) {
                fjac[i + j * fjac_dim1] = (wa1[i] - fvec[i]) / h;
            }
        }
        return 0;
    }

/*        computation of banded approximate jacobian. */

    for (k = 1; k <= msum; ++k) {
	for (j = k; j <= n; j += msum) {
	    wa2[j] = x[j];
	    h = eps * fabs(wa2[j]);
	    if (h == 0.) {
		h = eps;
	    }
	    x[j] = wa2[j] + h;
	}
	iflag = fcn_nn(p, n, &x[1], &wa1[1], 1);
	if (iflag < 0) {
            return iflag;
	}
	for (j = k; j <= n; j += msum) {
	    x[j] = wa2[j];
	    h = eps * fabs(wa2[j]);
	    if (h == 0.) {
		h = eps;
	    }
	    for (i = 1; i <= n; ++i) {
		fjac[i + j * fjac_dim1] = 0.;
		if (i >= j - mu && i <= j + ml) {
		    fjac[i + j * fjac_dim1] = (wa1[i] - fvec[i]) / h;
		}
	    }
	}
    }
    return 0;

/*     last card of subroutine fdjac1. */

} /* fdjac1_ */

