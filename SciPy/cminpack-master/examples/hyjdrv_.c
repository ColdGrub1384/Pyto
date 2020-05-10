/* Usage: hyjdrv < hybrd.data */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minpack.h"
#include "vec.h"
#define real __minpack_real__

/*     ********** */

/*     this program tests codes for the solution of n nonlinear */
/*     equations in n variables. it consists of a driver and an */
/*     interface subroutine fcn. the driver reads in data, calls the */
/*     nonlinear equation solver, and finally prints out information */
/*     on the performance of the solver. this is only a sample driver, */
/*     many other drivers are possible. the interface subroutine fcn */
/*     is necessary to take into account the forms of calling */
/*     sequences used by the function and jacobian subroutines in */
/*     the various nonlinear equation solvers. */

/*     subprograms called */

/*       user-supplied ...... fcn */

/*       minpack-supplied ... dpmpar,enorm,hybrj1,initpt,vecfcn */

/*       fortran-supplied ... dsqrt */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */

void fcn(const int *n, const real *x, real *fvec, real *fjac,
         const int *ldfjac, int *iflag);

struct refnum {
    int nprob, nfev, njev;
};

struct refnum hybrjtest;

static void printvec(int n, const real *x)
{
    int i, num5, ilow, numleft;
    num5 = n/5;

    for (i = 0; i < num5; ++i) {
        ilow = i*5;
        printf("     %15.7e%15.7e%15.7e%15.7e%15.7e\n",
               (double)x[ilow+0], (double)x[ilow+1], (double)x[ilow+2], (double)x[ilow+3], (double)x[ilow+4]);
    }
    
    numleft = n%5;
    ilow = n - numleft;

    switch (numleft) {
        case 1:
            printf("     %15.7e\n",
                   (double)x[ilow+0]);
            break;
        case 2:
            printf("     %15.7e%15.7e\n",
                   (double)x[ilow+0], (double)x[ilow+1]);
            break;
        case 3:
            printf("     %15.7e%15.7e%15.7e\n",
                   (double)x[ilow+0], (double)x[ilow+1], (double)x[ilow+2]);
            break;
        case 4:
            printf("     %15.7e%15.7e%15.7e%15.7e\n",
                   (double)x[ilow+0], (double)x[ilow+1], (double)x[ilow+2], (double)x[ilow+3]);
            break;
    }
}

/* Main program */
int main(int argc, char **argv)
{

    int i,ic,k,n,ntries;
    int info;

    int na[60];
    int nf[60];
    int nj[60];
    int np[60];
    int nx[60];

    real factor,fnorm1,fnorm2,tol;

    real fjac[40*40];
    const int ldfjac = 40;

    real fnm[60];
    real fvec[40];
    real x[40];

    real wa[1060];
    const int lwa = 1060;
    const int i1 = 1;
    (void)argc; (void)argv;

    tol = sqrt(__minpack_func__(dpmpar)(&i1));

    ic = 0;

    for (;;) {
        scanf("%5d%5d%5d\n", &hybrjtest.nprob, &n, &ntries);
        if (hybrjtest.nprob <= 0.)
            break;

        factor = 1.;

        for (k = 0; k < ntries; ++k, ++ic) {
            hybipt(n,x,hybrjtest.nprob,factor);

            vecfcn(n,x,fvec,hybrjtest.nprob);

            fnorm1 = __minpack_func__(enorm)(&n,fvec);

            printf("\n\n\n\n      problem%5d      dimension%5d\n\n", hybrjtest.nprob, n);

            hybrjtest.nfev = 0;
            hybrjtest.njev = 0;

            __minpack_func__(hybrj1)(fcn,&n,x,fvec,fjac,&ldfjac,&tol,&info,wa,&lwa);

            fnorm2 = __minpack_func__(enorm)(&n,fvec);

            np[ic] = hybrjtest.nprob;
            na[ic] = n;
            nf[ic] = hybrjtest.nfev;
            nj[ic] = hybrjtest.njev;
            nx[ic] = info;

            fnm[ic] = fnorm2;

            printf("\n      initial l2 norm of the residuals%15.7e\n"
                   "\n      final l2 norm of the residuals  %15.7e\n"
                   "\n      number of function evaluations  %10d\n"
                   "\n      number of jacobian evaluations  %10d\n"
                   "\n      exit parameter                  %10d\n"
                   "\n      final approximate solution\n\n",
                   (double)fnorm1, (double)fnorm2, hybrjtest.nfev, hybrjtest.njev, info);
            printvec(n, x);

            factor *= 10.;

        }

    }

    printf("\f summary of %d calls to hybrj1\n", ic);
    printf("\n nprob   n    nfev   njev  info  final l2 norm\n\n");

    for (i = 0; i < ic; ++i) {
        printf("%4d%6d%7d%7d%6d%16.7e\n",
               np[i], na[i], nf[i], nj[i], nx[i], (double)fnm[i]);
    }
    exit(0);
}


void fcn(const int *n, const real *x, real *fvec, real *fjac,
         const int *ldfjac, int *iflag)
{
/*     ********** */

/*     the calling sequence of fcn should be identical to the */
/*     calling sequence of the function subroutine in the nonlinear */
/*     equation solver. fcn should only call the testing function */
/*     and jacobian subroutines vecfcn and vecjac with the */
/*     appropriate value of problem number (nprob). */

/*     subprograms called */

/*       minpack-supplied ... vecfcn,vecjac */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    if (*iflag == 1) {
        vecfcn(*n, x, fvec, hybrjtest.nprob);
        hybrjtest.nfev++;
    }
    if (*iflag == 2) {
        vecjac(*n, x, fjac, *ldfjac, hybrjtest.nprob);
        hybrjtest.njev++;
    }
} /* fcn_ */
