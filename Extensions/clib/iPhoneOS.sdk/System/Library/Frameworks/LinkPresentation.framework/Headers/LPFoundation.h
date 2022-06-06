//
//  LinkPresentation
//  Copyright © 2015-2019 Apple Inc. All rights reserved.
//

#import <Availability.h>
#import <Foundation/Foundation.h>
#import <TargetConditionals.h>

#ifdef __cplusplus
#define LP_EXTERN extern "C" __attribute__((visibility ("default")))
#define LP_EXTERN_C extern "C"
#else
#define LP_EXTERN extern __attribute__((visibility ("default")))
#define LP_EXTERN_C extern
#endif
