/* -*- mode: c++ -*- */
/* ------------------------------ */
/*  driver for lmdif example.     */
/* ------------------------------ */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cminpack.h>

#include <lmdif.cu>
#include <covar1.cu>
#define real __cminpack_real__

#define cutilSafeCall(err)           __cudaSafeCall      (err, __FILE__, __LINE__)
inline void __cudaSafeCall( cudaError err, const char *file, const int line )
{
    if( cudaSuccess != err) {
        fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n",
                file, line, cudaGetErrorString( err) );
        exit(-1);
    }
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
const unsigned int NUM_OBSERVATIONS = 15; // m
const unsigned int NUM_PARAMS = 3; // 3 = n

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// 
//  fixed arrangement of threads to be run 
// 
const unsigned int NUM_THREADS = 2048;
const unsigned int NUM_THREADS_PER_BLOCK = 128;
const unsigned int NUM_BLOCKS = NUM_THREADS / NUM_THREADS_PER_BLOCK;

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//
// the struct for returning results from the GPU
//
//   #define ALIGN 16
// #pragma pack(16)
// float rankJ;
// __align__(2*sizeof(float))
// __align__(ALIGN) 
// float covar[NUM_PARAMS][NUM_PARAMS];


typedef struct    
{
    real fnorm;
    int nfev;
    int info;
    int rankJ;
    real solution[NUM_PARAMS];
    real covar[NUM_PARAMS][NUM_PARAMS];
} ResultType;

//--------------------------------------------------------------------------
// the cost function
//--------------------------------------------------------------------------
__cminpack_attr__ /* __device__ */
int fcn_mn(void *p, int m, int n, const real *x, real *fvec, int iflag)
{

    /*      subroutine fcn for lmdif example. */

    int i;
    real tmp1, tmp2, tmp3;
    real y[NUM_OBSERVATIONS]={1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 2.9e-1, 3.2e-1, 3.5e-1,
                              3.9e-1, 3.7e-1, 5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};

    if (iflag == 0)
    {
        /*      insert print statements here when nprint is positive. */
        return 0;
    }
    for (i = 1; i <= NUM_OBSERVATIONS; i++)
    {
        tmp1 = i;
        tmp2 = (NUM_OBSERVATIONS+1) - i;
        tmp3 = tmp1;
        if (i > 8) tmp3 = tmp2;
        fvec[i-1] = y[i-1] - (x[1-1] + tmp1/(x[2-1]*tmp2 + x[3-1]*tmp3));
    }
    return 0;
}

//--------------------------------------------------------------------------
// a test kernel for cheking the return of results
//--------------------------------------------------------------------------
__global__ void test_mainKernel(ResultType * pResults)
{

    int threadId = (blockIdx.x * blockDim.x) + threadIdx.x;

    pResults[threadId].fnorm = 13.13;
    pResults[threadId].nfev = 144;
    pResults[threadId].info = -1234;

    for (int j=0; j<NUM_PARAMS; j++) {
	pResults[threadId].solution[j] = 200+sqrt((real) (j*j));
    }

    for (unsigned int i=0; i<NUM_PARAMS; i++) {
        for (unsigned int j=0; j<NUM_PARAMS; j++) {
            pResults[threadId].covar[i][j] = 100+i+j;
	} // for
    } // for

    pResults[threadId].rankJ =   NUM_PARAMS; 

} // ()

//--------------------------------------------------------------------------
// the kernel in the GPU
//--------------------------------------------------------------------------
__global__ void mainKernel(ResultType  pResults[])
{
    int  maxfev, mode, nprint, info, nfev, ldfjac;
    int ipvt[NUM_PARAMS];
    real ftol, xtol, gtol, epsfcn, factor, fnorm;
    real x[NUM_PARAMS], fvec[NUM_OBSERVATIONS], 
            diag[NUM_PARAMS], fjac[NUM_OBSERVATIONS*NUM_PARAMS], qtf[NUM_PARAMS], 
            wa1[NUM_PARAMS], wa2[NUM_PARAMS], wa3[NUM_PARAMS], wa4[NUM_OBSERVATIONS];
    int k;

    // m = NUM_OBSERVATIONS;
    // n = NUM_PARAMS;

    /*      the following starting values provide a rough fit. */

    x[1-1] = 1.; 
    x[2-1] = 1.; 
    x[3-1] = 1.;

    ldfjac = NUM_OBSERVATIONS;

    /*      set ftol and xtol to the square root of the machine */
    /*      and gtol to zero. unless high solutions are */
    /*      required, these are the recommended settings. */

    ftol = sqrt(__cminpack_func__(dpmpar)(1));
    xtol = sqrt(__cminpack_func__(dpmpar)(1));
    gtol = 0.;

    maxfev = 800;
    epsfcn = 0.;
    mode = 1;
    factor = 1.e2;
    nprint = 0;

    /* NOTE: lmdif for pointer to cost function
       Error: Function pointers and function template parameters are not supported in sm_1x.
       info = lmdif(COST_FUNCTION, 0, m, n, x, fvec, ftol, xtol, gtol, maxfev, epsfcn, 
       diag, mode, factor, nprint, &nfev, fjac, ldfjac, 
       ipvt, qtf, wa1, wa2, wa3, wa4);
    */

    // -------------------------------
    // call lmdif, enorm, and covar1
    // -------------------------------
    info = __cminpack_func__(lmdif)(__cminpack_param_fcn_mn__ 0, NUM_OBSERVATIONS, NUM_PARAMS, 
                 x, fvec, ftol, xtol, gtol, maxfev, epsfcn, 
                 diag, mode, factor, nprint, &nfev, fjac, ldfjac, 
                 ipvt, qtf, wa1, wa2, wa3, wa4);

    fnorm = __cminpack_func__(enorm)(NUM_OBSERVATIONS, fvec);

    // NOTE: REMOVED THE TEST OF ORIGINAL MINPACK covar routine

    /* test covar1, which also estimates the rank of the Jacobian */
    ftol = __cminpack_func__(dpmpar)(1);
    k = __cminpack_func__(covar1)(NUM_OBSERVATIONS, NUM_PARAMS, 
               fnorm*fnorm, fjac, ldfjac, ipvt, ftol, wa1);

    // ----------------------------------
    // save the results in global memory
    // ----------------------------------
    int threadId = (blockIdx.x * blockDim.x) + threadIdx.x;

    pResults[threadId].fnorm = fnorm;
    pResults[threadId].nfev = nfev;
    pResults[threadId].info = info;

    for (int j=1; j<=NUM_PARAMS; j++) {
        pResults[threadId].solution[j-1] = x[j-1];
    }

    for (int i=1; i<=NUM_PARAMS; i++) {
        for (int j=1; j<=NUM_PARAMS; j++) {
            pResults[threadId].covar[i-1][j-1] = fjac[(i-1)*ldfjac+j-1];
	} // for
    } // for

    /*
      for (unsigned int i=0; i<NUM_PARAMS; i++) {
      for (unsigned int j=0; j<NUM_PARAMS; j++) {
      pResults[threadId].covar[i][j] = 100+i+j;
      } // for
      } // for
    */

    pResults[threadId].rankJ =  (k != 0 ? k : NUM_PARAMS); 

} // ()

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int main (int argc, char** argv)
{

    fprintf (stderr, "\ntlmdif starts ! \n");
    //  ...............................................................
    // choose the fastest GPU device
    //  ...............................................................
    unsigned int GPU_ID = 1; 
    //unsigned int GPU_ID =  cutGetMaxGflopsDeviceId() ;
    cudaSetDevice(GPU_ID); 
    fprintf (stderr, " CUDA device chosen = %d \n", GPU_ID);

    // ....................................................... 
    //  get memory in the GPU to store the results 
    // ....................................................... 
    ResultType * results_GPU = 0;
    cutilSafeCall( cudaMalloc( &results_GPU,  NUM_THREADS * sizeof(ResultType) ) );

    // ....................................................... 
    //  get memory in the CPU to store the results 
    // ....................................................... 
    ResultType * results_CPU = 0;
    cutilSafeCall( cudaMallocHost( &results_CPU, NUM_THREADS * sizeof(ResultType) ) );

    // ....................................................... 
    //  launch the kernel
    // ....................................................... 
    fprintf (stderr, " \nlaunching the kernel num. blocks = %d, threads per block = %d\n total threads = %d\n\n",
             NUM_BLOCKS, NUM_THREADS_PER_BLOCK, NUM_THREADS);

    mainKernel<<<NUM_BLOCKS,NUM_THREADS_PER_BLOCK>>> ( results_GPU );

    // ....................................................... 
    // wait for termination
    // ....................................................... 
    cudaThreadSynchronize(); 
    fprintf (stderr, " GPU processing done \n\n");

    // ....................................................... 
    // copy back to CPU the results
    // ....................................................... 
    cutilSafeCall( cudaMemcpy( results_CPU, results_GPU, 
                               NUM_THREADS * sizeof(ResultType),
                               cudaMemcpyDeviceToHost
                               ) );

    // ....................................................... 
    // check all the threads computed the same results
    // ....................................................... 
    bool ok = true;
    for (unsigned int i = 1; i<NUM_THREADS; i++) {
	if ( memcmp (&results_CPU[0], &results_CPU[i], sizeof(ResultType)) != 0) {
            // warning: may the padding bytes be different ?
            ok = false;
	}
	/*
          if ( results_CPU[0].fnorm != results_CPU[i].fnorm
          || results_CPU[0].nfev != results_CPU[i].nfev
          || results_CPU[0].info != results_CPU[i].info
          || results_CPU[0].rankJ != results_CPU[i].rankJ
          )
	  {
          ok = false;
	  }
	*/
    } // for
		 

    if (ok) {
	fprintf (stderr, " !!! all threads computed the same results !!! \n\n");
    } else {
	fprintf (stderr, "ERROR in results of threads \n");
    }

    // ....................................................... 
    // show the results !
    // ....................................................... 

    printf("      final l2 norm of the residuals%15.7g\n\n", results_CPU[0].fnorm);
    printf("      number of function evaluations%10i\n\n", results_CPU[0].nfev);
    printf("      exit parameter                %10i\n\n", results_CPU[0].info);
    printf("      final approximate solution\n");

    for (int j=0; j<NUM_PARAMS; j++)  {
        printf("%15.7g", results_CPU[0].solution[j]);
    }
    printf("\n");

    printf("      covariance\n");

 
    for (unsigned int i=0; i<NUM_PARAMS; i++) {
        for (unsigned int j=0; j<NUM_PARAMS; j++) {
            printf("%15.7g", results_CPU[0].covar[i][j]);
	} // for
	printf ("\n");
    } // for
  
    printf("\n");
    printf(" rank(J) = %d\n", results_CPU[0].rankJ );
    cutilSafeCall(cudaFree(results_GPU));
    cutilSafeCall(cudaFreeHost(results_CPU));
    cudaThreadExit();
    //cutilExit(argc, argv);

} // ()
