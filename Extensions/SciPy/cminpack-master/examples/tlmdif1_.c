/*     driver for lmdif1 example. */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <minpack.h>
#define real __minpack_real__

void fcn(const int *m, const int *n, const real *x, real *fvec, int *iflag);

int main()
{
    int j, m, n, info, lwa, iwa[3], one=1;
  real tol, fnorm, x[3], fvec[15], wa[75];

  m = 15;
  n = 3;

  /* the following starting values provide a rough fit. */

  x[0] = 1.e0;
  x[1] = 1.e0;
  x[2] = 1.e0;

  lwa = 75;

  /* set tol to the square root of the machine precision.  unless high
     precision solutions are required, this is the recommended
     setting. */

  tol = sqrt(__minpack_func__(dpmpar)(&one));

  __minpack_func__(lmdif1)(&fcn, &m, &n, x, fvec, &tol, &info, iwa, wa, &lwa);

  fnorm = __minpack_func__(enorm)(&m, fvec);

  printf("      final l2 norm of the residuals%15.7g\n\n", (double)fnorm);
  printf("      exit parameter                %10i\n\n", info);
  printf("      final approximate solution\n");
  for (j=1; j<=n; j++) {
    printf("%s%15.7g", j%3==1?"\n ":"", (double)x[j-1]);
  }
  printf("\n");
  return 0;
}

void fcn(const int *m, const int *n, const real *x, real *fvec, int *iflag)
{
  /* function fcn for lmdif1 example */

  int i;
  real tmp1,tmp2,tmp3;
  real y[15]={1.4e-1,1.8e-1,2.2e-1,2.5e-1,2.9e-1,3.2e-1,3.5e-1,3.9e-1,
              3.7e-1,5.8e-1,7.3e-1,9.6e-1,1.34e0,2.1e0,4.39e0};
  assert(*m == 15 && *n == 3);

  if (*iflag == 0) {
    /*      insert print statements here when nprint is positive. */
    /* if the nprint parameter to lmder is positive, the function is
       called every nprint iterations with iflag=0, so that the
       function may perform special operations, such as printing
       residuals. */
    return;
  }

  /* compute residuals */
  for (i=0; i<15; i++) {
    tmp1 = i+1;
    tmp2 = 15 - i;
    tmp3 = tmp1;
      
    if (i >= 8) {
      tmp3 = tmp2;
    }
    fvec[i] = y[i] - (x[0] + tmp1/(x[1]*tmp2 + x[2]*tmp3));
  }
}
