/*      driver for fdjac2 example. */
/*      The test works by running chkder both on the Jacobian computed
        by forward-differences and on the real Jacobian */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <minpack.h>
#include <cminpack.h>
#define real __minpack_real__

void fcn(const int *m, const int *n, const real *x, real *fvec, int *iflag);
void fcnjac(int m, int n, const real *x, real *fjac, int ldfjac);

int main()
{
#if defined(__MINGW32__) || (defined(_MSC_VER) && (_MSC_VER < 1900))
  _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

  int i, m, n, ldfjac, mode;
  real epsfcn;
  real x[3], fvec[15], fjac[15*3], fdjac[15*3], xp[3], fvecp[15], 
      err[15], errd[15], wa[15];
  int one=1, iflag=1;

  m = 15;
  n = 3;

  /*      the following values should be suitable for */
  /*      checking the jacobian matrix. */

  x[1-1] = 9.2e-1;
  x[2-1] = 1.3e-1;
  x[3-1] = 5.4e-1;

  ldfjac = 15;

  epsfcn = 0.;

  mode = 1;
  __minpack_func__(chkder)(&m, &n, x, NULL, NULL, &ldfjac, xp, NULL, &mode, NULL);
  mode = 2;
  fcn(&m, &n, x, fvec, &one);
  __minpack_func__(fdjac2)(fcn, &m, &n, x, fvec, fdjac, &ldfjac, &iflag, &epsfcn, wa);
  fcnjac(m, n, x, fjac, ldfjac);
  fcn(&m, &n, xp, fvecp, &one);
  __minpack_func__(chkder)(&m, &n, x, fvec, fdjac, &ldfjac, NULL, fvecp, &mode, errd);
  __minpack_func__(chkder)(&m, &n, x, fvec, fjac, &ldfjac, NULL, fvecp, &mode, err);

  for (i=1; i<=m; i++) {
    fvecp[i-1] = fvecp[i-1] - fvec[i-1];
  }
  printf("\n      fvec\n");  
  for (i=1; i<=m; i++) {
    printf("%s%15.7g",i%3==1?"\n     ":"", (double)fvec[i-1]);
  }
  printf("\n      fvecp - fvec\n");  
  for (i=1; i<=m; i++) {
    printf("%s%15.7g",i%3==1?"\n     ":"", (double)fvecp[i-1]);
  }
  printf("\n      errd\n");  
  for (i=1; i<=m; i++) {
    printf("%s%15.7g",i%3==1?"\n     ":"", (double)errd[i-1]);
  }
  printf("\n      err\n");  
  for (i=1; i<=m; i++) {
    printf("%s%15.7g",i%3==1?"\n     ":"", (double)err[i-1]);
  }
  printf("\n");
  return 0;
}

void fcn(const int *m, const int *n, const real *x, real *fvec, int *iflag)
{

/*      subroutine fcn for fdjac2 example. */

  int i;
  real tmp1, tmp2, tmp3;
  real y[15]={1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 2.9e-1, 3.2e-1, 3.5e-1,
		3.9e-1, 3.7e-1, 5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};
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
  for (i = 1; i <= 15; i++) {
    tmp1 = i;
    tmp2 = 16 - i;
    tmp3 = tmp1;
    if (i > 8) tmp3 = tmp2;
    fvec[i-1] = y[i-1] - (x[1-1] + tmp1/(x[2-1]*tmp2 + x[3-1]*tmp3));
  }
}

void fcnjac(int m, int n, const real *x,
            real *fjac, int ldfjac)
{
  /*      Jacobian of fcn (corrected version from tchkder). */

  int i;
  real tmp1, tmp2, tmp3, tmp4;
  assert(m == 15 && n == 3);

  for (i = 1; i <= 15; i++) {
    tmp1 = i;
    tmp2 = 16 - i;
	  
    tmp3 = tmp1;
    if (i > 8) {
      tmp3 = tmp2;
    }
    tmp4 = (x[2-1]*tmp2 + x[3-1]*tmp3); tmp4=tmp4*tmp4;
    fjac[i-1+ ldfjac*(1-1)] = -1.;
    fjac[i-1+ ldfjac*(2-1)] = tmp1*tmp2/tmp4;
    fjac[i-1+ ldfjac*(3-1)] = tmp1*tmp3/tmp4;
  }
}
