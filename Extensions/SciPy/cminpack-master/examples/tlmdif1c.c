

/*     driver for lmdif1 example. */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cminpack.h>
#define real __cminpack_real__

/* the following struct defines the data points */
typedef struct  {
    int m;
    real *y;
} fcndata_t;

int fcn(void *p, int m, int n, const real *x, real *fvec, int iflag);

int main()
{
  int info, lwa, iwa[3];
  real tol, fnorm, x[3], fvec[15], wa[75];
  const int m = 15;
  const int n = 3;
  /* auxiliary data (e.g. measurements) */
  real y[15] = {1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 2.9e-1, 3.2e-1, 3.5e-1,
                  3.9e-1, 3.7e-1, 5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};
  fcndata_t data;
  data.m = m;
  data.y = y;

  /* the following starting values provide a rough fit. */

  x[0] = 1.;
  x[1] = 1.;
  x[2] = 1.;

  lwa = 75;

  /* set tol to the square root of the machine precision.  unless high
     precision solutions are required, this is the recommended
     setting. */

  tol = sqrt(__cminpack_func__(dpmpar)(1));

  info = __cminpack_func__(lmdif1)(fcn, &data, m, n, x, fvec, tol, iwa, wa, lwa);

  fnorm = __cminpack_func__(enorm)(m, fvec);

  printf("      final l2 norm of the residuals%15.7g\n\n",(double)fnorm);
  printf("      exit parameter                %10i\n\n", info);
  printf("      final approximate solution\n\n %15.7g%15.7g%15.7g\n",
	 (double)x[0], (double)x[1], (double)x[2]);
  return 0;
}

int fcn(void *p, int m, int n, const real *x, real *fvec, int iflag)
{
  /* function fcn for lmdif1 example */

  int i;
  real tmp1,tmp2,tmp3;
  const real *y = ((fcndata_t*)p)->y;
  assert(m == 15 && n == 3);
  (void)iflag;

  for (i = 0; i < 15; ++i)
    {
      tmp1 = i + 1;
      tmp2 = 15 - i;
      tmp3 = (i > 7) ? tmp2 : tmp1;
      fvec[i] = y[i] - (x[0] + tmp1/(x[1]*tmp2 + x[2]*tmp3));
    }
  return 0;
}
