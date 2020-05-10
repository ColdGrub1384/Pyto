#ifndef __CMINPACK_SSQ_H__
#define __CMINPACK_SSQ_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void lmdipt(int n, __cminpack_real__ *x, int nprob, __cminpack_real__ factor);

void ssqfcn(int m, int n, const __cminpack_real__ *x, __cminpack_real__ *fvec, int nprob);

void ssqjac(int m, int n, const __cminpack_real__ *x, __cminpack_real__ *fjac, int ldfjac, int nprob);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __CMINPACK_SSQ_H__ */
