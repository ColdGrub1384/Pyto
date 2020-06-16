/*      driver for lmdif example. */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <cminpack.h>
#define real __cminpack_real__

#define TEST_COVAR

/* the following struct defines the data points */
typedef struct  {
    int m;
    real *y;
} fcndata_t;

int fcn(void *p, int m, int n, const real *x, real *fvec, int iflag);

int main()
{
#if defined(__MINGW32__) || (defined(_MSC_VER) && (_MSC_VER < 1900))
  _set_output_format(_TWO_DIGIT_EXPONENT);
#endif
  int i, j, maxfev, mode, nprint, info, nfev, ldfjac;
  int ipvt[3];
  real ftol, xtol, gtol, epsfcn, factor, fnorm;
  real x[3], fvec[15], diag[3], fjac[15*3], qtf[3], 
    wa1[3], wa2[3], wa3[3], wa4[15];
  int k;
  const int m = 15;
  const int n = 3;
  /* auxiliary data (e.g. measurements) */
  real y[15] = {1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 2.9e-1, 3.2e-1, 3.5e-1,
                  3.9e-1, 3.7e-1, 5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};
#ifdef TEST_COVAR
  real covfac;
  real fjac1[15*3];
#endif

  fcndata_t data;
  data.m = m;
  data.y = y;

/*      the following starting values provide a rough fit. */

  x[0] = 1.;
  x[1] = 1.;
  x[2] = 1.;

  ldfjac = 15;

  /*      set ftol and xtol to the square root of the machine */
  /*      and gtol to zero. unless high solutions are */
  /*      required, these are the recommended settings. */

  ftol = sqrt(__cminpack_func__(dpmpar)(1));
  xtol = sqrt(__cminpack_func__(dpmpar)(1));
  gtol = 0.;

  maxfev = 800;
  epsfcn = 0.;
  mode = 1;
  factor = 1.e2;
  nprint = 0;

  info = __cminpack_func__(lmdif)(fcn, &data, m, n, x, fvec, ftol, xtol, gtol, maxfev, epsfcn, 
	 diag, mode, factor, nprint, &nfev, fjac, ldfjac, 
	 ipvt, qtf, wa1, wa2, wa3, wa4);

  fnorm = __cminpack_func__(enorm)(m, fvec);

  printf("      final l2 norm of the residuals%15.7g\n\n", (double)fnorm);
  printf("      number of function evaluations%10i\n\n", nfev);
  printf("      exit parameter                %10i\n\n", info);
  printf("      final approximate solution\n");
  for (j=0; j<n; ++j) {
    printf("%s%15.7g", j%3==0?"\n     ":"", (double)x[j]);
  }
  printf("\n");
  ftol = __cminpack_func__(dpmpar)(1);
#ifdef TEST_COVAR
  /* test the original covar from MINPACK */
  covfac = fnorm*fnorm/(m-n);
  memcpy(fjac1, fjac, sizeof(fjac));
  __cminpack_func__(covar)(n, fjac1, ldfjac, ipvt, ftol, wa1);
  /*
  printf("      covariance (using covar)\n");
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j)
      printf("%s%15.7g", j%3==1?"\n     ":"", (double)fjac1[i*ldfjac+j]*covfac);
  }
  printf("\n");
  */
#endif
  /* test covar1, which also estimates the rank of the Jacobian */
  k = __cminpack_func__(covar1)(m, n, fnorm*fnorm, fjac, ldfjac, ipvt, ftol, wa1);
  printf("      covariance\n");
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j)
      printf("%s%15.7g", j%3==0?"\n     ":"", (double)fjac[i*ldfjac+j]);
  }
  printf("\n");
  (void)k;
#ifdef TEST_COVAR
  if (k == n) {
    /* comparison only works if covariance matrix has full rank */
    for (i=0; i<n; ++i) {
      for (j=0; j<n; ++j) {
        if (fjac[i*ldfjac+j] != fjac1[i*ldfjac+j]*covfac) {
          printf("component (%d,%d) of covar and covar1 differ: %g != %g\n", i, j, (double)fjac[i*ldfjac+j], (double)(fjac1[i*ldfjac+j]*covfac));
        }
      }
    }
  }
#endif
  /* printf("      rank(J) = %d\n", k != 0 ? k : n); */
  return 0;
}

int fcn(void *p, int m, int n, const real *x, real *fvec, int iflag)
{

/*      subroutine fcn for lmdif example. */

  int i;
  real tmp1, tmp2, tmp3;
  const real *y = ((fcndata_t*)p)->y;
  assert(m == 15 && n == 3);

  if (iflag == 0) {
    /*      insert print statements here when nprint is positive. */
    /* if the nprint parameter to lmdif is positive, the function is
       called every nprint iterations with iflag=0, so that the
       function may perform special operations, such as printing
       residuals. */
    return 0;
  }
  
  /* compute residuals */
  for (i = 0; i < 15; ++i) {
    tmp1 = i + 1;
    tmp2 = 15 - i;
    tmp3 = (i > 7) ? tmp2 : tmp1;
    fvec[i] = y[i] - (x[0] + tmp1/(x[1]*tmp2 + x[2]*tmp3));
  }
  return 0;
}
