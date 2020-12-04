/* -*- mode: c++ -*- */
/* ------------------------------ */
/*  driver for lmdif1 example.     */
/* ------------------------------ */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cminpack.h>

#include <lmdif1.cu>
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

typedef struct    
{
    real fnorm;
    int info;
    real solution[NUM_PARAMS];
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

    for (i = 0; i < NUM_OBSERVATIONS; i++) {
        tmp1 = i+1;
        tmp2 = NUM_OBSERVATIONS - i;
        tmp3 = tmp1;
	  
        if (i >= 8) tmp3 = tmp2;
        fvec[i] = y[i] - (x[0] + tmp1/(x[1]*tmp2 + x[2]*tmp3));
    } // for
    return 0;
}

//--------------------------------------------------------------------------
// the kernel in the GPU
//--------------------------------------------------------------------------
__global__ void mainKernel(ResultType  pResults[])
{

    int info, lwa, iwa[NUM_PARAMS];
    real tol, fnorm, x[NUM_PARAMS], fvec[NUM_OBSERVATIONS], wa[75];

    // m = 15 = NUM_OBSERVATIONS;
    // n = 3 = NUM_PARAMS;

    /*   the following starting values provide a rough fit. */
    x[0] = 1.; 
    x[1] = 1.; 
    x[2] = 1.;

    lwa = 75;

    /* set tol to the square root of the machine precision.  unless high
       precision solutions are required, this is the recommended
       setting. */

    tol = sqrt(__cminpack_func__(dpmpar)(1));

    // -------------------------------
    // call lmdif, and enorm
    // -------------------------------
    info = __cminpack_func__(lmdif1)(__cminpack_param_fcn_mn__ 0, NUM_OBSERVATIONS, NUM_PARAMS, x, fvec, tol, iwa, wa, lwa);
  
    fnorm = __cminpack_func__(enorm)(NUM_OBSERVATIONS, fvec);

    // ----------------------------------
    // save the results in global memory
    // ----------------------------------
    int threadId = (blockIdx.x * blockDim.x) + threadIdx.x;

    pResults[threadId].fnorm = fnorm;
    pResults[threadId].info = info;

    for (int j=0; j<NUM_PARAMS; j++) {
        pResults[threadId].solution[j] = x[j];
    }

} // ()

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int main (int argc, char** argv)
{

    fprintf (stderr, "\ntlmdif1c starts ! \n");

    //  ...............................................................
    // choose the fastest GPU device
    //  ...............................................................
    unsigned int GPU_ID = 1;  // not actually :-)
    // unsigned int GPU_ID =  cutGetMaxGflopsDeviceId() ;
    cudaSetDevice(GPU_ID); 
    fprintf (stderr, " CUDA device chosen = %d \n", GPU_ID);

    // ....................................................... 
    //  get memory in the GPU to store the results 
    // ....................................................... 
    ResultType * results_GPU = 0;
    cutilSafeCall( cudaMalloc( &results_GPU,  NUM_THREADS * sizeof(ResultType)) );

    // ....................................................... 
    //  get memory in the CPU to store the results 
    // ....................................................... 
    ResultType * results_CPU = 0;
    cutilSafeCall( cudaMallocHost( &results_CPU, NUM_THREADS * sizeof(ResultType)) );

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
    printf("      exit parameter                %10i\n\n", results_CPU[0].info);
    printf("      final approximate solution\n");

    for (int j=0; j<NUM_PARAMS; j++)  {
        printf("%15.7g", results_CPU[0].solution[j]);
    }
    printf("\n");

    cutilSafeCall(cudaFree(results_GPU));
    cutilSafeCall(cudaFreeHost(results_CPU));
    cudaThreadExit();
    //cutilExit(argc, argv);
} // ()

