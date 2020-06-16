/*      driver for hybrj example. */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cminpack.h>
#define real __cminpack_real__

#ifdef BOX_CONSTRAINTS
typedef struct  {
    real *xmin;
    real *xmax;
} fcndata_t;
#endif

int fcn(void *p, int n, const real *x, real *fvec, real *fjac, int ldfjac, 
	 int iflag);

int main()
{
#if defined(__MINGW32__) || (defined(_MSC_VER) && (_MSC_VER < 1900))
  _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

  int j, n, ldfjac, maxfev, mode, nprint, info, nfev, njev, lr;
  real xtol, factor, fnorm;
  real x[9], fvec[9], fjac[9*9], diag[9], r[45], qtf[9],
    wa1[9], wa2[9], wa3[9], wa4[9];
  void *p = NULL;
#ifdef BOX_CONSTRAINTS
  real xmin[9] = {-2.,-0.5, -2., -2., -2., -2., -2., -2., -2.};
  real xmax[9] = { 2.,  2.,  2.,  2.,  2.,  2.,  2.,  2.,  2.};
  fcndata_t data;
  data.xmin = xmin;
  data.xmax = xmax;
  p = &data;
#endif

  n = 9;

/*      the following starting values provide a rough solution. */

  for (j=1; j<=9; j++) {
    x[j-1] = -1.;
  }

  ldfjac = 9;
  lr = 45;

/*      set xtol to the square root of the machine precision. */
/*      unless high solutions are required, */
/*      this is the recommended setting. */

  xtol = sqrt(__cminpack_func__(dpmpar)(1));

  maxfev = 1000;
  mode = 2;
  for (j=1; j<=9; j++) {
    diag[j-1] = 1.;
  }
  factor = 1.e2;
  nprint = 0;

  info = __cminpack_func__(hybrj)(fcn, p, n, x, fvec, fjac, ldfjac, xtol, maxfev, diag, 
	mode, factor, nprint, &nfev, &njev, r, lr, qtf, 
	wa1, wa2, wa3, wa4);
#ifdef BOX_CONSTRAINTS
  /* compute the real x, using the same change of variable as in fcn */
  for (j = 0; j < 3; ++j) {
    real xmiddle = (xmin[j]+xmax[j])/2.;
    real xwidth = (xmax[j]-xmin[j])/2.;
    real th =  tanh((x[j]-xmiddle)/xwidth);
    x[j] = xmiddle + th * xwidth;
  }
#endif
 fnorm = __cminpack_func__(enorm)(n, fvec);

 printf("     final l2 norm of the residuals%15.7g\n\n", (double)fnorm);
 printf("     number of function evaluations%10i\n\n", nfev);
 printf("     number of jacobian evaluations%10i\n\n", njev);
 printf("     exit parameter                %10i\n\n", info);
 printf("     final approximate solution\n\n");
 for (j=1; j<=n; j++) {
   printf("%s%15.7g", j%3==1?"\n     ":"", (double)x[j-1]);
 }
 printf("\n");
 return 0;
}

int fcn(void *p, int n, const real *x, real *fvec, real *fjac, int ldfjac, 
	 int iflag)
{
  
  /*      subroutine fcn for hybrj example. */
  (void)p;
  assert(n == 9);

  int j, k;
  real temp, temp1, temp2;
#ifdef BOX_CONSTRAINTS
  const real *xmin = ((fcndata_t*)p)->xmin;
  const real *xmax = ((fcndata_t*)p)->xmax;
  real xb[9];
  real jacfac[9];

  for (j = 0; j < 9; ++j) {
    real xmiddle = (xmin[j]+xmax[j])/2.;
    real xwidth = (xmax[j]-xmin[j])/2.;
    real th =  tanh((x[j]-xmiddle)/xwidth);
    xb[j] = xmiddle + th * xwidth;
    jacfac[j] = 1. - th * th;
  }
  x = xb;
#endif

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
    for (k = 0; k < n; ++k) {
      temp = (3 - 2*x[k])*x[k];
      temp1 = 0;
      if (k != 0) temp1 = x[k-1];
      temp2 = 0;
      if (k != n-1) temp2 = x[k+1];
      fvec[k] = temp - temp1 - 2*temp2 + 1;
    }
  } else {
    /* compute Jacobian */
    for (k = 0; k < n; ++k) {
      for (j = 0; j < n; ++j) {
        fjac[k + ldfjac*j] = 0;
      }
      fjac[k + ldfjac*k] = 3 - 4*x[k];
      if (k != 0) {
        fjac[k + ldfjac*(k-1)] = -1;
      }
      if (k != n-1) {
        fjac[k + ldfjac*(k+1)] = -2;
      }
#    ifdef BOX_CONSTRAINTS
      for (j = 0; j < n; ++j) {
        fjac[k + ldfjac*j] *= jacfac[j];
      }
#    endif
    }      
  }
  return 0;
}

