/*    driver for lmstr1 example. */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <minpack.h>
#define real __minpack_real__

void  fcn(const int *m, const int *n, const real *x, real *fvec, real *fjrow, int *iflag);

int main()
{
  int j, m, n, ldfjac, info, lwa, ipvt[3], one=1;
  real tol, fnorm;
  real x[3], fvec[15], fjac[9], wa[30];

  m = 15;
  n = 3;

  /*     the following starting values provide a rough fit. */

  x[0] = 1.;
  x[1] = 1.;
  x[2] = 1.;

  ldfjac = 3;
  lwa = 30;

  /*     set tol to the square root of the machine precision.
     unless high precision solutions are required,
     this is the recommended setting. */

  tol = sqrt(__minpack_func__(dpmpar)(&one));

  __minpack_func__(lmstr1)(&fcn, &m, &n, 
	  x, fvec, fjac, &ldfjac, 
	  &tol, &info, ipvt, wa, &lwa);

  fnorm = __minpack_func__(enorm)(&m, fvec);

  printf("      final l2 norm of the residuals%15.7g\n\n", (double)fnorm);
  printf("      exit parameter                %10i\n\n", info);
  printf("      final approximate solution\n");
  for (j=0; j<n; ++j) {
    printf("%s%15.7g", j%3==0?"\n     ":"", (double)x[j]);
  }
  printf("\n");

  return 0;
}

void  fcn(const int *m, const int *n, const real *x, real *fvec, real *fjrow, int *iflag)
{
  /*  subroutine fcn for lmstr1 example. */
  int i;
  real tmp1, tmp2, tmp3, tmp4;
  real y[15]={1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 2.9e-1, 3.2e-1, 3.5e-1,
              3.9e-1, 3.7e-1, 5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};
  assert(*m == 15 && *n == 3);

  if (*iflag == 0) {
    /*      insert print statements here when nprint is positive. */
    /* if the nprint parameter to lmdif is positive, the function is
       called every nprint iterations with iflag=0, so that the
       function may perform special operations, such as printing
       residuals. */
    return;
  }
  
  if (*iflag < 2) {
    for (i=1; i<=15; i++) {
      tmp1=i;
      tmp2 = 16-i;
      tmp3 = tmp1;
      if (i > 8) tmp3 = tmp2;
      fvec[i-1] = y[i-1] - (x[1-1] + tmp1/(x[2-1]*tmp2 + x[3-1]*tmp3));
    }
  } else {
    i = *iflag - 1;
    tmp1 = i;
    tmp2 = 16 - i;
    tmp3 = tmp1;
    if (i > 8) tmp3 = tmp2;
    tmp4 = (x[2-1]*tmp2 + x[3-1]*tmp3); tmp4=tmp4*tmp4;
    fjrow[1-1] = -1;
    fjrow[2-1] = tmp1*tmp2/tmp4;
    fjrow[3-1] = tmp1*tmp3/tmp4;
  }
}
