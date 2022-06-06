//
//  CTCellularPlanProvisioning.h
//  CoreTelephony
//
//  Copyright (c) 2018 Apple Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreTelephony/CoreTelephonyDefines.h>
#import <CoreTelephony/CTCellularPlanProvisioningRequest.h>

NS_ASSUME_NONNULL_BEGIN

CORETELEPHONY_CLASS_AVAILABLE(12_0)
@interface CTCellularPlanProvisioning : NSObject

- (BOOL)supportsCellularPlan   __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_12_0);

- (void)addPlanWith:(CTCellularPlanProvisioningRequest *)request completionHandler:(void (^)(CTCellularPlanProvisioningAddPlanResult result))completionHandler   __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_12_0);

@end

NS_ASSUME_NONNULL_END
