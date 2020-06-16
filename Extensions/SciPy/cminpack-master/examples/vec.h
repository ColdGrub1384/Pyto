#ifndef __CMINPACK_HYB_H__
#define __CMINPACK_HYB_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void hybipt(int n, __cminpack_real__ *x, int nprob, __cminpack_real__ factor);

void vecfcn(int n, const __cminpack_real__ *x, __cminpack_real__ *fvec, int nprob);

void vecjac(int n, const __cminpack_real__ *x, __cminpack_real__ *fjac, int ldfjac, int nprob);

void errjac(int n, const __cminpack_real__ *x, __cminpack_real__ *fjac, int ldfjac, int nprob);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __CMINPACK_HYB_H__ */
