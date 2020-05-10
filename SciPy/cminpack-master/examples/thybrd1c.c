/*      driver for hybrd1 example. */


#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cminpack.h>
#define real __cminpack_real__

int fcn(void *p, int n, const real *x, real *fvec, int iflag);

int main()
{
#if defined(__MINGW32__) || (defined(_MSC_VER) && (_MSC_VER < 1900))
  _set_output_format(_TWO_DIGIT_EXPONENT);
#endif
  int j, n, info, lwa;
  real tol, fnorm;
  real x[9], fvec[9], wa[180];

  n = 9;

/*      the following starting values provide a rough solution. */

  for (j=1; j<=9; j++) {
    x[j-1] = -1.;
  }

  lwa = 180;

/*      set tol to the square root of the machine precision. */
/*      unless high solutions are required, */
/*      this is the recommended setting. */

  tol = sqrt(__cminpack_func__(dpmpar)(1));
  info = __cminpack_func__(hybrd1)(fcn, 0, n, x, fvec, tol, wa, lwa);
  fnorm = __cminpack_func__(enorm)(n, fvec);

  printf("     final L2 norm of the residuals %15.7g\n", (double)fnorm);
  printf("     exit parameter                 %10i\n", info);
  printf("     final approximates solution\n");
  for (j=1; j<=n; j++) {
    printf("%s%15.7g",j%3==1?"\n     ":"", (double)x[j-1]);
  }
  printf("\n");

  return 0;
}

int fcn(void *p, int n, const real *x, real *fvec, int iflag)
{
/*      subroutine fcn for hybrd1 example. */

  int k;
  real temp, temp1, temp2;
  (void)p;
  assert(n == 9);

  if (iflag == 0) {
    /*      insert print statements here when nprint is positive. */
    /* if the nprint parameter to lmder is positive, the function is
       called every nprint iterations with iflag=0, so that the
       function may perform special operations, such as printing
       residuals. */
    return 0;
  }

  /* compute residuals */
  for (k=1; k <= n; k++) {
    temp = (3 - 2*x[k-1])*x[k-1];
    temp1 = 0;
    if (k != 1) {
      temp1 = x[k-1-1];
    }
    temp2 = 0;
    if (k != n) {
      temp2 = x[k+1-1];
    }
    fvec[k-1] = temp - temp1 - 2*temp2 + 1;
  }
  return 0;
}
