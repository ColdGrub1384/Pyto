/* -*- mode: c++ -*- */
/* ------------------------------ */
/*  driver for lmder example.     */
/* ------------------------------ */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cminpack.h>

#include <lmder.cu>
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
//
// the struct for returning results from the GPU
//

typedef struct    
{
    real fnorm;
    int nfev;
    int njev;
    int info;
    int rankJ;
    real solution[NUM_PARAMS];
    real covar[NUM_PARAMS][NUM_PARAMS];
} ResultType;

//--------------------------------------------------------------------------
// the cost function
//--------------------------------------------------------------------------
__cminpack_attr__ /* __device__ */
int fcnder_mn(
    void *p, int m, int n, const real *x, 
    real *fvec, real *fjac, 
    int ldfjac, int iflag)
{

    /*      subroutine fcn for lmder example. */

    int i;
    real tmp1, tmp2, tmp3, tmp4;
    real y[NUM_OBSERVATIONS]={1.4e-1, 1.8e-1, 2.2e-1, 2.5e-1, 
                              2.9e-1, 3.2e-1, 3.5e-1, 3.9e-1, 3.7e-1, 
                              5.8e-1, 7.3e-1, 9.6e-1, 1.34, 2.1, 4.39};

    if (iflag == 0) {
        /*      insert print statements here when nprint is positive. */
        return 0;
    }

    if (iflag != 2) {

	for (i = 1; i <= NUM_OBSERVATIONS; i++) {
            tmp1 = i;
            tmp2 = (NUM_OBSERVATIONS+1) - i;
            tmp3 = tmp1;
            if (i > 8) tmp3 = tmp2;
            fvec[i-1] = y[i-1] - (x[1-1] + tmp1/(x[2-1]*tmp2 + x[3-1]*tmp3));
        } // for

    } else { 

        for (i=1; i<=NUM_OBSERVATIONS; i++) {
            tmp1 = i;
            tmp2 = (NUM_OBSERVATIONS+1) - i;
            tmp3 = tmp1;
            if (i > 8) tmp3 = tmp2;
            tmp4 = (x[2-1]*tmp2 + x[3-1]*tmp3); tmp4 = tmp4*tmp4;
            fjac[i-1 + ldfjac*(1-1)] = -1.;
            fjac[i-1 + ldfjac*(2-1)] = tmp1*tmp2/tmp4;
            fjac[i-1 + ldfjac*(3-1)] = tmp1*tmp3/tmp4;
        } // for
    } // if

    return 0;
}

//--------------------------------------------------------------------------
// the kernel in the GPU
//--------------------------------------------------------------------------
__global__ void mainKernel(ResultType  pResults[])
{
    int ldfjac, maxfev, mode, nprint, info, nfev, njev;
    int ipvt[NUM_PARAMS];
    real ftol, xtol, gtol, factor, fnorm;
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

    maxfev = 400;
    mode = 1;
    factor = 1.e2;
    nprint = 0;

    // -------------------------------
    // call lmder, enorm, and covar1
    // -------------------------------
    info = __cminpack_func__(lmder)(__cminpack_param_fcnder_mn__ 0, NUM_OBSERVATIONS, NUM_PARAMS, 
                 x, fvec, fjac, ldfjac, ftol, xtol, gtol, 
                 maxfev, diag, mode, factor, nprint, &nfev, &njev, 
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
    pResults[threadId].njev = njev;
    pResults[threadId].info = info;

    for (int j=1; j<=NUM_PARAMS; j++) {
        pResults[threadId].solution[j-1] = x[j-1];
    }

    for (int i=1; i<=NUM_PARAMS; i++) {
        for (int j=1; j<=NUM_PARAMS; j++) {
            pResults[threadId].covar[i-1][j-1] = fjac[(i-1)*ldfjac+j-1];
	} // for
    } // for

    pResults[threadId].rankJ =  (k != 0 ? k : NUM_PARAMS); 

} // ()

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int main (int argc, char** argv)
{

    fprintf (stderr, "\ntlmder starts ! \n");
    //  ...............................................................
    // choose the fastest GPU device
    //  ...............................................................
    unsigned int GPU_ID = 1; 
    // unsigned int GPU_ID =  cutGetMaxGflopsDeviceId() ;
    cudaSetDevice(GPU_ID); 
    fprintf (stderr, " CUDA device chosen = %d \n", GPU_ID);

    // ....................................................... 
    //  get memory in the GPU to store the results 
    // ....................................................... 
    ResultType * results_GPU = 0;
    cutilSafeCall(cudaMalloc( &results_GPU,  NUM_THREADS * sizeof(ResultType) ));

    // ....................................................... 
    //  get memory in the CPU to store the results 
    // ....................................................... 
    ResultType * results_CPU = 0;
    cutilSafeCall(cudaMallocHost( &results_CPU, NUM_THREADS * sizeof(ResultType) ));

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
    cutilSafeCall(cudaMemcpy( results_CPU, results_GPU,
                              NUM_THREADS * sizeof(ResultType),
                              cudaMemcpyDeviceToHost
                              ));

    // ....................................................... 
    // check all the threads computed the same results
    // ....................................................... 
    bool ok = true;
    for (unsigned int i = 1; i<NUM_THREADS; i++) {
	if ( memcmp (&results_CPU[0], &results_CPU[i], sizeof(ResultType)) != 0) {
            // warning: may the padding bytes be different ?
            ok = false;
	}
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
    printf("      number of Jacobian evaluations%10i\n\n", results_CPU[0].njev);
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
