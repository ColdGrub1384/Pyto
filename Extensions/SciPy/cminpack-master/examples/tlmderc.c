/*      driver for lmder example. */


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <cminpack.h>
#define real __cminpack_real__

#define TEST_COVAR

/* define the preprocessor symbol BOX_CONSTRAINTS to enable the simulated box constraints
   using a change of variables. */

/* the following struct defines the data points */
typedef struct  {
    int m;
    real *y;
#ifdef BOX_CONSTRAINTS
    real *xmin;
    real *xmax;
#endif
} fcndata_t;

int fcn(void *p, int m, int n, const real *x, real *fvec, real *fjac, 
	 int ldfjac, int iflag);

int main()
{
  int i, j, ldfjac, maxfev, mode, nprint, info, nfev, njev;
  int ipvt[3];
  real ftol, xtol, gtol, factor, fnorm;
  real x[3], fvec[15], fjac[15*3], diag[3], qtf[3], 
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
#ifdef BOX_CONSTRAINTS
  /* the minimum and maximum bounds for each variable. */
  real xmin[3] = {0., 0.1, 0.5};
  real xmax[3] = {2., 1.5, 2.3};
  /* the Jacobian factor for each line, used to compute the covariance matrix. */
  real jacfac[3];
#endif
  fcndata_t data;
  data.m = m;
  data.y = y;
#ifdef BOX_CONSTRAINTS
  data.xmin = xmin;
  data.xmax = xmax;
#endif

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
    
  maxfev = 400;
  mode = 1;
  factor = 1.e2;
  nprint = 0;

  info = __cminpack_func__(lmder)(fcn, &data, m, n, x, fvec, fjac, ldfjac, ftol, xtol, gtol, 
	maxfev, diag, mode, factor, nprint, &nfev, &njev, 
	ipvt, qtf, wa1, wa2, wa3, wa4);
#ifdef BOX_CONSTRAINTS
  /* compute the real x, using the same change of variable as in fcn */
  for (j = 0; j < 3; ++j) {
    real xmiddle = (xmin[j]+xmax[j])/2.;
    real xwidth = (xmax[j]-xmin[j])/2.;
    real th =  tanh((x[j]-xmiddle)/xwidth);
    x[j] = xmiddle + th * xwidth;
    jacfac[j] = 1. - th * th;
  }
#endif
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
  /* test the original covar from MINPACK */
  covfac = fnorm*fnorm/(m-n);
  memcpy(fjac1, fjac, sizeof(fjac));
  __cminpack_func__(covar)(n, fjac1, ldfjac, ipvt, ftol, wa1);
  /* printf("      covariance (using covar)\n"); */
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) {
#    ifdef BOX_CONSTRAINTS
      fjac1[i*ldfjac+j] *= jacfac[i] * jacfac[j];
#    endif
      /* printf("%s%15.7g", j%3==0?"\n     ":"", (double)fjac1[i*ldfjac+j]*covfac); */
    }
  }
  /* printf("\n"); */
#endif
  /* test covar1, which also estimates the rank of the Jacobian */
  k = __cminpack_func__(covar1)(m, n, fnorm*fnorm, fjac, ldfjac, ipvt, ftol, wa1);
  printf("      covariance\n");
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) {
#    ifdef BOX_CONSTRAINTS
      fjac[i*ldfjac+j] *= jacfac[i] * jacfac[j];
#    endif
      printf("%s%15.7g", j%3==0?"\n     ":"", (double)fjac[i*ldfjac+j]);
    }
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

int fcn(void *p, int m, int n, const real *x, real *fvec, real *fjac, 
	 int ldfjac, int iflag)
{      

  /*      subroutine fcn for lmder example. */

  int i;
  real tmp1, tmp2, tmp3, tmp4;
  const real *y = ((fcndata_t*)p)->y;
#ifdef BOX_CONSTRAINTS
  const real *xmin = ((fcndata_t*)p)->xmin;
  const real *xmax = ((fcndata_t*)p)->xmax;
  int j;
  real xb[3];
  real jacfac[3];
  real xmiddle, xwidth, th;

  for (j = 0; j < 3; ++j) {
    xmiddle = (xmin[j]+xmax[j])/2.;
    xwidth = (xmax[j]-xmin[j])/2.;
    th =  tanh((x[j]-xmiddle)/xwidth);
    xb[j] = (xmin[j]+xmax[j])/2. + th * xwidth;
    jacfac[j] = 1. - th * th;
  }
  x = xb;
#endif
  assert(m == 15 && n == 3);

  if (iflag == 0) {
    /*      insert print statements here when nprint is positive. */
    /* if the nprint parameter to lmder is positive, the function is
       called every nprint iterations with iflag=0, so that the
       function may perform special operations, such as printing
       residuals. */
    return 0;
  }

  if (iflag != 2) {
    /* compute residuals */
    for (i=0; i < 15; ++i) {
      tmp1 = i + 1;
      tmp2 = 15 - i;
      tmp3 = (i > 7) ? tmp2 : tmp1;
      fvec[i] = y[i] - (x[0] + tmp1/(x[1]*tmp2 + x[2]*tmp3));
    }
  } else {
    /* compute Jacobian */
    for (i=0; i<15; ++i) {
      tmp1 = i + 1;
      tmp2 = 15 - i;
      tmp3 = (i > 7) ? tmp2 : tmp1;
      tmp4 = (x[1]*tmp2 + x[2]*tmp3); tmp4 = tmp4*tmp4;
      fjac[i + ldfjac*0] = -1.;
      fjac[i + ldfjac*1] = tmp1*tmp2/tmp4;
      fjac[i + ldfjac*2] = tmp1*tmp3/tmp4;
    }
#    ifdef BOX_CONSTRAINTS
    for (j = 0; j < 3; ++j) {
      for (i=0; i < 15; ++i) {
        fjac[i + ldfjac*j] *= jacfac[j];
      }
    }
#    endif
  }
  return 0;
}
