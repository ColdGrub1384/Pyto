/* Internal header file for cminpack, by Frederic Devernay. */
#ifndef __MINPACKP_H__
#define __MINPACKP_H__

#ifndef __CMINPACK_H__
#error "minpackP.h in an internal cminpack header, and must be included after all other headers (including cminpack.h)"
#endif

#include <float.h>

#define double_EPSILON DBL_EPSILON
#define double_MIN DBL_MIN
#define double_MAX DBL_MAX
#define long_double_EPSILON LDBL_EPSILON
#define long_double_MIN LDBL_MIN
#define long_double_MAX LDBL_MAX
#define float_EPSILON FLT_EPSILON
#define float_MIN FLT_MIN
#define float_MAX FLT_MAX
#define half_EPSILON HALF_EPSILON
#define half_MIN HALF_NRM_MIN
#define half_MAX HALF_MAX

#define real __cminpack_real__
#ifdef __cminpack_long_double__
#define realm long_double
#define fabs(x) fabsl(x)
#define sqrt(x) sqrtl(x)
#define log(x) logl(x)
#define exp(x) expl(x)
#define sin(x) sinl(x)
#define cos(x) cosl(x)
#define tan(x) tanl(x)
#define asin(x) asinl(x)
#define acos(x) acosl(x)
#define atan(x) atanl(x)
#define floor(x) floorl(x)
#define ceil(x) ceill(x)
extern long double floorl ( long double );
extern long double ellpkl ( long double );
#else
#define realm real
#endif
#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define TRUE_ (1)
#define FALSE_ (0)

#endif /* !__MINPACKP_H__ */
