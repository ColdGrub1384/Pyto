/* Usage: chkdrv < chkder.data */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cminpack.h"
#include "vec.h"
#define real __cminpack_real__

/*     ********** */

/*     this program tests the ability of chkder to detect */
/*     inconsistencies between functions and their first derivatives. */
/*     fourteen test function vectors and jacobians are used. eleven of */
/*     the tests are false(f), i.e. there are inconsistencies between */
/*     the function vectors and the corresponding jacobians. three of */
/*     the tests are true(t), i.e. there are no inconsistencies. the */
/*     driver reads in data, calls chkder and prints out information */
/*     required by and received from chkder. */

/*     subprograms called */

/*       minpack supplied ... chkder,errjac,initpt,vecfcn */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */

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
    /* Initialized data */
    const int a[14] = { 0,0,0,1,0,0,0,1,0,0,0,0,1,0 };
    real cp = .123;
    /* Local variables */
    int i, n;
    real x1[10], x2[10];
    int na[14], np[14];
    real err[10];
    int lnp = 0;
    real fjac[10*10];
    const int ldfjac = 10;
    real diff[10];
    real fvec1[10], fvec2[10];
    int nprob;
    real errmin[14], errmax[14];
    (void)argc; (void)argv;

    for (;;) {
        scanf("%5d%5d\n", &nprob, &n);
        if (nprob <= 0) {
            break;
        }

        hybipt(n,x1,nprob,1.);
        for(i=0; i<n; ++i) {
            x1[i] += cp;
            cp = -cp;
        }

        printf("\n\n\n      problem%5d      with dimension%5d   is  %c\n\n", nprob, n, a[nprob-1]?'T':'F');

        __cminpack_func__(chkder)(n,n,x1,NULL,NULL,ldfjac,x2,NULL,1,NULL);
        vecfcn(n,x1,fvec1,nprob);
        errjac(n,x1,fjac,ldfjac,nprob);
        vecfcn(n,x2,fvec2,nprob);
        __cminpack_func__(chkder)(n,n,x1,fvec1,fjac,ldfjac,NULL,fvec2,2,err);

        errmin[nprob-1] = err[0];
        errmax[nprob-1] = err[0];
        for(i=0; i<n; ++i) {
            diff[i] = fvec2[i] - fvec1[i];
            if (errmin[nprob-1] > err[i])
                errmin[nprob-1] = err[i];
            if (errmax[nprob-1] < err[i])
                errmax[nprob-1] = err[i];
        }

        np[nprob-1] = nprob;
        lnp = nprob;
        na[nprob-1] = n;

        printf("\n      first function vector   \n\n");
        printvec(n, fvec1);
        printf("\n\n      function difference vector\n\n");
        printvec(n, diff);
        printf("\n\n      error vector\n\n");
        printvec(n, err);
    }

    printf("\f summary of %3d tests of chkder\n", lnp);
    printf("\n nprob   n    status     errmin         errmax\n\n");

    for (i = 0; i < lnp; ++i) {
        printf("%4d%6d      %c   %15.7e%15.7e\n",
               np[i], na[i], a[i]?'T':'F', (double)errmin[i], (double)errmax[i]);
    }
    exit(0);
}
