/* r1updt.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "cminpack.h"
#include <math.h>
#include "cminpackP.h"

__cminpack_attr__
void __cminpack_func__(r1updt)(int m, int n, real *s, int
	ls, const real *u, real *v, real *w, int *sing)
{
    /* Initialized data */

#define p5 .5
#define p25 .25

    /* Local variables */
    int i, j, l, jj, nm1;
    real tan;
    int nmj;
    real cos, sin, tau, temp, giant, cotan;

/*     ********** */

/*     subroutine r1updt */

/*     given an m by n lower trapezoidal matrix s, an m-vector u, */
/*     and an n-vector v, the problem is to determine an */
/*     orthogonal matrix q such that */

/*                   t */
/*           (s + u*v )*q */

/*     is again lower trapezoidal. */

/*     this subroutine determines q as the product of 2*(n - 1) */
/*     transformations */

/*           gv(n-1)*...*gv(1)*gw(1)*...*gw(n-1) */

/*     where gv(i), gw(i) are givens rotations in the (i,n) plane */
/*     which eliminate elements in the i-th and n-th planes, */
/*     respectively. q itself is not accumulated, rather the */
/*     information to recover the gv, gw rotations is returned. */

/*     the subroutine statement is */

/*       subroutine r1updt(m,n,s,ls,u,v,w,sing) */

/*     where */

/*       m is a positive integer input variable set to the number */
/*         of rows of s. */

/*       n is a positive integer input variable set to the number */
/*         of columns of s. n must not exceed m. */

/*       s is an array of length ls. on input s must contain the lower */
/*         trapezoidal matrix s stored by columns. on output s contains */
/*         the lower trapezoidal matrix produced as described above. */

/*       ls is a positive integer input variable not less than */
/*         (n*(2*m-n+1))/2. */

/*       u is an input array of length m which must contain the */
/*         vector u. */

/*       v is an array of length n. on input v must contain the vector */
/*         v. on output v(i) contains the information necessary to */
/*         recover the givens rotation gv(i) described above. */

/*       w is an output array of length m. w(i) contains information */
/*         necessary to recover the givens rotation gw(i) described */
/*         above. */

/*       sing is a logical output variable. sing is set true if any */
/*         of the diagonal elements of the output s are zero. otherwise */
/*         sing is set false. */

/*     subprograms called */

/*       minpack-supplied ... dpmpar */

/*       fortran-supplied ... dabs,dsqrt */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more, */
/*     john l. nazareth */

/*     ********** */
    /* Parameter adjustments */
    --w;
    --u;
    --v;
    --s;
    (void)ls;

    /* Function Body */

/*     giant is the largest magnitude. */

    giant = __cminpack_func__(dpmpar)(3);

/*     initialize the diagonal element pointer. */

    jj = n * ((m << 1) - n + 1) / 2 - (m - n);

/*     move the nontrivial part of the last column of s into w. */

    l = jj;
    for (i = n; i <= m; ++i) {
	w[i] = s[l];
	++l;
    }

/*     rotate the vector v into a multiple of the n-th unit vector */
/*     in such a way that a spike is introduced into w. */

    nm1 = n - 1;
    if (nm1 >= 1) {
        for (nmj = 1; nmj <= nm1; ++nmj) {
            j = n - nmj;
            jj -= m - j + 1;
            w[j] = 0.;
            if (v[j] != 0.) {

/*        determine a givens rotation which eliminates the */
/*        j-th element of v. */

                if (fabs(v[n]) < fabs(v[j])) {
                    cotan = v[n] / v[j];
                    sin = p5 / sqrt(p25 + p25 * (cotan * cotan));
                    cos = sin * cotan;
                    tau = 1.;
                    if (fabs(cos) * giant > 1.) {
                        tau = 1. / cos;
                    }
                } else {
                    tan = v[j] / v[n];
                    cos = p5 / sqrt(p25 + p25 * (tan * tan));
                    sin = cos * tan;
                    tau = sin;
                }

/*        apply the transformation to v and store the information */
/*        necessary to recover the givens rotation. */

                v[n] = sin * v[j] + cos * v[n];
                v[j] = tau;

/*        apply the transformation to s and extend the spike in w. */

                l = jj;
                for (i = j; i <= m; ++i) {
                    temp = cos * s[l] - sin * w[i];
                    w[i] = sin * s[l] + cos * w[i];
                    s[l] = temp;
                    ++l;
                }
            }
        }
    }

/*     add the spike from the rank 1 update to w. */

    for (i = 1; i <= m; ++i) {
	w[i] += v[n] * u[i];
    }

/*     eliminate the spike. */

    *sing = FALSE_;
    if (nm1 >= 1) {
        for (j = 1; j <= nm1; ++j) {
            if (w[j] != 0.) {

/*        determine a givens rotation which eliminates the */
/*        j-th element of the spike. */

                if (fabs(s[jj]) < fabs(w[j])) {
                    cotan = s[jj] / w[j];
                    sin = p5 / sqrt(p25 + p25 * (cotan * cotan));
                    cos = sin * cotan;
                    tau = 1.;
                    if (fabs(cos) * giant > 1.) {
                        tau = 1. / cos;
                    }
                } else {
                    tan = w[j] / s[jj];
                    cos = p5 / sqrt(p25 + p25 * (tan * tan));
                    sin = cos * tan;
                    tau = sin;
                }

/*        apply the transformation to s and reduce the spike in w. */

                l = jj;
                for (i = j; i <= m; ++i) {
                    temp = cos * s[l] + sin * w[i];
                    w[i] = -sin * s[l] + cos * w[i];
                    s[l] = temp;
                    ++l;
                }

/*        store the information necessary to recover the */
/*        givens rotation. */

                w[j] = tau;
            }

/*        test for zero diagonal elements in the output s. */

            if (s[jj] == 0.) {
                *sing = TRUE_;
            }
            jj += m - j + 1;
        }
    }

/*     move w back into the last column of the output s. */

    l = jj;
    for (i = n; i <= m; ++i) {
	s[l] = w[i];
	++l;
    }
    if (s[jj] == 0.) {
	*sing = TRUE_;
    }

/*     last card of subroutine r1updt. */

} /* __minpack_func__(r1updt) */

