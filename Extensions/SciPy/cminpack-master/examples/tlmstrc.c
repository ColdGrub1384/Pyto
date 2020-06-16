/*      driver for lmstr example. */

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

int fcn(void *p, int m, int n, const real *x, real *fvec, real *fjrow, int iflag);

int main()
{
  int i, j, ldfjac, maxfev, mode, nprint, info, nfev, njev;
  int ipvt[3];
  real ftol, xtol, gtol, factor, fnorm;
  real x[3], fvec[15], fjac[3*3], diag[3], qtf[3], 
    wa1[3], wa2[3], wa3[3], wa4[15];
  int k;
  const int m = 15;
  const int n = 3;
  /* auxiliary data (e.g. measurements) */
  real y[15] = {1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 2.9e-1, 3.2e-1, 3.5e-1,
                  3.9e-1, 3.7e-1, 5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};
  fcndata_t data;
  data.m = m;
  data.y = y;

  /*      the following starting values provide a rough fit. */

  x[0] = 1.;
  x[1] = 1.;
  x[2] = 1.;

  ldfjac = 3;

  /*      set ftol and xtol to the square root of the machine */
  /*      and gtol to zero. unless high solutions are */
  /*      required, these are the recommended settings. */

  ftol = sqrt(__cminpack_func__(dpmpar)(1));
  xtol = sqrt(__cminpack_func__(dpmpar)(1));
  gtol = 0.;

  maxfev = 400;
  mode = 1;
  factor = 1.e2;
  nprint = 0;

  info = __cminpack_func__(lmstr)(fcn, &data, m, n, x, fvec, fjac, ldfjac, ftol, xtol, gtol, 
	maxfev, diag, mode, factor, nprint, &nfev, &njev, 
	ipvt, qtf, wa1, wa2, wa3, wa4);
  fnorm = __cminpack_func__(enorm)(m, fvec);

  printf("      final l2 norm of the residuals%15.7g\n\n", (double)fnorm);
  printf("      number of function evaluations%10i\n\n", nfev);
  printf("      number of Jacobian evaluations%10i\n\n", njev);
  printf("      exit parameter                %10i\n\n", info);
  printf("      final approximate solution\n");
  for (j=0; j<n; ++j) {
    printf("%s%15.7g", j%3==0?"\n     ":"", (double)x[j]);
  }
  printf("\n");
  ftol = __cminpack_func__(dpmpar)(1);
#ifdef TEST_COVAR
  {
      /* test the original covar from MINPACK */
      real covfac = fnorm*fnorm/(m-n);
      real fjac1[3*3];
      memcpy(fjac1, fjac, sizeof(fjac));
      __cminpack_func__(covar)(n, fjac1, ldfjac, ipvt, ftol, wa1);
      printf("      covariance (using covar)\n");
      for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
          printf("%s%15.7g", j%3==0?"\n     ":"", (double)fjac1[i*ldfjac+j]*covfac);
        }
      }
      printf("\n");
  }
#endif
  /* test covar1, which also estimates the rank of the Jacobian */
  k = __cminpack_func__(covar1)(m, n, fnorm*fnorm, fjac, ldfjac, ipvt, ftol, wa1);
  printf("      covariance\n");
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) {
      printf("%s%15.7g", j%3==0?"\n     ":"", (double)fjac[i*ldfjac+j]);
    }
  }
  printf("\n");
  (void)k;
  /* printf("      rank(J) = %d\n", k != 0 ? k : n); */

  return 0;
}

int fcn(void *p, int m, int n, const real *x, real *fvec, real *fjrow, int iflag)
{

  /*      subroutine fcn for lmstr example. */

  int i;
  real tmp1, tmp2, tmp3, tmp4;
  const real *y = ((fcndata_t*)p)->y;
  assert(m == 15 && n == 3);

  if (iflag == 0) {
    /*      insert print statements here when nprint is positive. */
    /* if the nprint parameter to lmder is positive, the function is
       called every nprint iterations with iflag=0, so that the
       function may perform special operations, such as printing
       residuals. */
    return 0;
  }
  
  if (iflag < 2) {
    /* compute residuals */
    for (i=0; i < 15; ++i) {
      tmp1 = i + 1;
      tmp2 = 15 - i;
      tmp3 = (i > 7) ? tmp2 : tmp1;
      fvec[i] = y[i] - (x[0] + tmp1/(x[1]*tmp2 + x[2]*tmp3));
    }
  } else {
    /* compute Jacobian row */
    i = iflag - 2;
    tmp1 = i + 1;
    tmp2 = 15 - i;
    tmp3 = (i > 7) ? tmp2 : tmp1;
    tmp4 = (x[1]*tmp2 + x[2]*tmp3); tmp4 = tmp4*tmp4;
    fjrow[0] = -1.;
    fjrow[1] = tmp1*tmp2/tmp4;
    fjrow[2] = tmp1*tmp3/tmp4;
  }
  return 0;
}
