/*      driver for fdjac2 example. */
/*      The test works by running chkder both on the Jacobian computed
        by forward-differences and on the real Jacobian */

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
void fcnjac(int m, int n, const real *x, real *fjac, int ldfjac);

int main()
{
#if defined(__MINGW32__) || (defined(_MSC_VER) && (_MSC_VER < 1900))
  _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

  int i, ldfjac;
  real epsfcn;
  real x[3], fvec[15], fjac[15*3], fdjac[15*3], xp[3], fvecp[15], 
      err[15], errd[15], wa[15];
  const int m = 15;
  const int n = 3;

  /* auxiliary data (e.g. measurements) */
  real y[15] = {1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 2.9e-1, 3.2e-1, 3.5e-1,
                  3.9e-1, 3.7e-1, 5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};
  fcndata_t data;
  data.m = m;
  data.y = y;

  /*      the following values should be suitable for */
  /*      checking the jacobian matrix. */

  x[1-1] = 9.2e-1;
  x[2-1] = 1.3e-1;
  x[3-1] = 5.4e-1;

  ldfjac = 15;

  epsfcn = 0.;

  /* compute xp from x */
  __cminpack_func__(chkder)(m, n, x, NULL, NULL, ldfjac, xp, NULL, 1, NULL);
  /* compute fvec at x (all components of fvec should be != 0).*/
  fcn(&data, m, n, x, fvec, 1);
  /* compute fdjac (Jacobian using finite differences) at x */
  __cminpack_func__(fdjac2)(fcn, &data, m, n, x, fvec, fdjac, ldfjac, epsfcn, wa);
  /* compute fjac (real Jacobian) at x */
  fcnjac(m, n, x, fjac, ldfjac);
  /* compute fvecp at xp (all components of fvecp should be != 0)*/
  fcn(&data, m, n, xp, fvecp, 1);
  /* check Jacobian fdjac, put the result in errd */
  __cminpack_func__(chkder)(m, n, x, fvec, fdjac, ldfjac, NULL, fvecp, 2, errd);
  /* check Jacobian fjac, put the result in err */
  __cminpack_func__(chkder)(m, n, x, fvec, fjac, ldfjac, NULL, fvecp, 2, err);
  /* Output values:
     err[i] = 1.: i-th gradient is correct
     err[i] = 0.: i-th gradient is incorrect
     err[I] > 0.5: i-th gradient is probably correct
  */

  for (i=0; i<m; ++i)
    {
      fvecp[i] = fvecp[i] - fvec[i];
    }
  printf("\n      fvec\n");  
  for (i=0; i<m; ++i) {
    printf("%s%15.7g",i%3==0?"\n     ":"", (double)fvec[i]);
  }
  printf("\n      fvecp - fvec\n");  
  for (i=0; i<m; ++i) {
    printf("%s%15.7g",i%3==0?"\n     ":"", (double)fvecp[i]);
  }
  printf("\n      errd\n");  
  for (i=0; i<m; ++i) {
    printf("%s%15.7g",i%3==0?"\n     ":"", (double)errd[i]);
  }
  printf("\n      err\n");  
  for (i=0; i<m; ++i) {
    printf("%s%15.7g",i%3==0?"\n     ":"", (double)err[i]);
  }
  printf("\n");
  return 0;
}

int fcn(void *p, int m, int n, const real *x, real *fvec, int iflag)
{

/*      subroutine fcn for fdjac2 example. */

  int i;
  real tmp1, tmp2, tmp3;
  real y[15]={1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 2.9e-1, 3.2e-1, 3.5e-1,
		3.9e-1, 3.7e-1, 5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};
  assert(m == 15 && n == 3);
  (void)p;

  if (iflag == 0) {
    /*      insert print statements here when nprint is positive. */
    /* if the nprint parameter to lmder is positive, the function is
       called every nprint iterations with iflag=0, so that the
       function may perform special operations, such as printing
       residuals. */
    return 0;
  }

  /* compute residuals */
  for (i = 1; i <= 15; i++) {
    tmp1 = i;
    tmp2 = 16 - i;
    tmp3 = tmp1;
    if (i > 8) tmp3 = tmp2;
    fvec[i-1] = y[i-1] - (x[1-1] + tmp1/(x[2-1]*tmp2 + x[3-1]*tmp3));
  }
  return 0;
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
    if (i > 8) tmp3 = tmp2;
    tmp4 = (x[2-1]*tmp2 + x[3-1]*tmp3); tmp4=tmp4*tmp4;
    fjac[i-1+ ldfjac*(1-1)] = -1.;
    fjac[i-1+ ldfjac*(2-1)] = tmp1*tmp2/tmp4;
    fjac[i-1+ ldfjac*(3-1)] = tmp1*tmp3/tmp4;
  }
}
