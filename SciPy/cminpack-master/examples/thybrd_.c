/*      driver for hybrd example. */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <minpack.h>
#define real __minpack_real__

void fcn(const int *n, const real *x, real *fvec, int *iflag);

int main()
{
#if defined(__MINGW32__) || (defined(_MSC_VER) && (_MSC_VER < 1900))
  _set_output_format(_TWO_DIGIT_EXPONENT);
#endif
  int j, n, maxfev, ml, mu, mode, nprint, info, nfev, ldfjac, lr;
  real xtol, epsfcn, factor, fnorm;
  real x[9], fvec[9], diag[9], fjac[9*9], r[45], qtf[9],
    wa1[9], wa2[9], wa3[9], wa4[9];
  int one=1;

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

  xtol = sqrt(__minpack_func__(dpmpar)(&one));

  maxfev = 2000;
  ml = 1;
  mu = 1;
  epsfcn = 0.;
  mode = 2;
  for (j=1; j<=9; j++) {
    diag[j-1] = 1.;
  }

  factor = 1.e2;
  nprint = 0;

  __minpack_func__(hybrd)(&fcn, &n, x, fvec, &xtol, &maxfev, &ml, &mu, &epsfcn,
	 diag, &mode, &factor, &nprint, &info, &nfev,
	 fjac, &ldfjac, r, &lr, qtf, wa1, wa2, wa3, wa4);
  fnorm = __minpack_func__(enorm)(&n, fvec);
  printf("     final l2 norm of the residuals %15.7g\n\n", (double)fnorm);
  printf("     number of function evaluations  %10i\n\n", nfev);
  printf("     exit parameter                  %10i\n\n", info);
  printf("     final approximate solution\n");
  for (j=1; j<=n; j++) {
    printf("%s%15.7g", j%3==1?"\n     ":"", (double)x[j-1]);
  }
  printf("\n");
  return 0;
}


void fcn(const int *n, const real *x, real *fvec, int *iflag)
{
  /*      subroutine fcn for hybrd example. */

  int k;
  real temp, temp1, temp2;
  assert(*n == 9);

  if (*iflag == 0) {
    /*      insert print statements here when nprint is positive. */
    /* if the nprint parameter to lmder is positive, the function is
       called every nprint iterations with iflag=0, so that the
       function may perform special operations, such as printing
       residuals. */
    return;
  }
  
  /* compute residuals */
  for (k=1; k<=*n; k++) {
    temp = (3 - 2*x[k-1])*x[k-1];
    temp1 = 0;
    if (k != 1) {
      temp1 = x[k-1-1];
    }
    temp2 = 0;
    if (k != *n) {
      temp2 = x[k+1-1];
    }
    fvec[k-1] = temp - temp1 - 2*temp2 + 1;
  }
  return;
}

