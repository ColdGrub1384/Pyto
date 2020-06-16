/* enorm.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "minpack.h"
#include <math.h>

#include "minpackP.h"

/*
  About the values for rdwarf and rgiant.

  The original values, both in single-precision FORTRAN source code and in double-precision code were:
#define rdwarf 3.834e-20
#define rgiant 1.304e19
  See for example:
    http://www.netlib.org/slatec/src/denorm.f
    http://www.netlib.org/slatec/src/enorm.f
  However, rdwarf is smaller than sqrt(FLT_MIN) = 1.0842021724855044e-19, so that rdwarf**2 will
  underflow. This contradicts the constraints expressed in the comments below.

  We changed these constants to those proposed by the
  implementation found in MPFIT http://cow.physics.wisc.edu/~craigm/idl/fitting.html

 cmpfit-1.2 proposes the following definitions:
  rdwarf = sqrt(dpmpar(2)*1.5) * 10
  rgiant = sqrt(dpmpar(3)) * 0.1

 The half version does not really worked that way, so we use for half:
  rdwarf = sqrt(dpmpar(2)) * 2
  rgiant = sqrt(dpmpar(3)) * 0.5
 Any suggestion is welcome. Half CMINPACK is really only a
 proof-of-concept anyway.

 See the example/tenorm*c, which computes these values 
*/
#define double_dwarf (1.82691291192569e-153)
#define double_giant (1.34078079299426e+153)
#define long_double_dwarf (2.245696932951581572e-2465l)
#define long_double_giant (1.090748135619415929e+2465l)
#define float_dwarf (1.327871072777421e-18f)
#define float_giant (1.844674297419792e+18f)
#define half_dwarf (0.015625f)
#define half_giant (127.9375f)

#define dwarf(type) _dwarf(type)
#define _dwarf(type) type ## _dwarf
#define giant(type) _giant(type)
#define _giant(type) type ## _giant

#define rdwarf dwarf(realm)
#define rgiant giant(realm)

__minpack_attr__
real __minpack_func__(enorm)(const int *n, const real *x)
{
    /* System generated locals */
    int i__1;
    real ret_val, d__1;

    /* Local variables */
    int i__;
    real s1, s2, s3, xabs, x1max, x3max, agiant, floatn;

/*     ********** */

/*     function enorm */

/*     given an n-vector x, this function calculates the */
/*     euclidean norm of x. */

/*     the euclidean norm is computed by accumulating the sum of */
/*     squares in three different sums. the sums of squares for the */
/*     small and large components are scaled so that no overflows */
/*     occur. non-destructive underflows are permitted. underflows */
/*     and overflows do not occur in the computation of the unscaled */
/*     sum of squares for the intermediate components. */
/*     the definitions of small, intermediate and large components */
/*     depend on two constants, rdwarf and rgiant. the main */
/*     restrictions on these constants are that rdwarf**2 not */
/*     underflow and rgiant**2 not overflow. the constants */
/*     given here are suitable for every known computer. */

/*     the function statement is */

/*       double precision function enorm(n,x) */

/*     where */

/*       n is a positive integer input variable. */

/*       x is an input array of length n. */

/*     subprograms called */

/*       fortran-supplied ... dabs,dsqrt */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --x;

    /* Function Body */
    s1 = 0.;
    s2 = 0.;
    s3 = 0.;
    x1max = 0.;
    x3max = 0.;
    floatn = (real) (*n);
    agiant = rgiant / floatn;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xabs = fabs(x[i__]);
	if (xabs > rdwarf && xabs < agiant) {
	    goto L70;
	}
	if (xabs <= rdwarf) {
	    goto L30;
	}

/*              sum for large components. */

	if (xabs <= x1max) {
	    goto L10;
	}
/* Computing 2nd power */
	d__1 = x1max / xabs;
	s1 = 1. + s1 * (d__1 * d__1);
	x1max = xabs;
	goto L20;
L10:
/* Computing 2nd power */
	d__1 = xabs / x1max;
	s1 += d__1 * d__1;
L20:
	goto L60;
L30:

/*              sum for small components. */

	if (xabs <= x3max) {
	    goto L40;
	}
/* Computing 2nd power */
	d__1 = x3max / xabs;
	s3 = 1. + s3 * (d__1 * d__1);
	x3max = xabs;
	goto L50;
L40:
	if (xabs != 0.) {
/* Computing 2nd power */
	    d__1 = xabs / x3max;
	    s3 += d__1 * d__1;
	}
L50:
L60:
	goto L80;
L70:

/*           sum for intermediate components. */

/* Computing 2nd power */
	d__1 = xabs;
	s2 += d__1 * d__1;
L80:
/* L90: */
	;
    }

/*     calculation of norm. */

    if (s1 == 0.) {
	goto L100;
    }
    ret_val = x1max * sqrt(s1 + s2 / x1max / x1max);
    goto L130;
L100:
    if (s2 == 0.) {
	goto L110;
    }
    if (s2 >= x3max) {
	ret_val = sqrt(s2 * (1. + x3max / s2 * (x3max * s3)));
    } else {
	ret_val = sqrt(x3max * (s2 / x3max + x3max * s3));
    }
    goto L120;
L110:
    ret_val = x3max * sqrt(s3);
L120:
L130:
    return ret_val;

/*     last card of function enorm. */

} /* enorm_ */

