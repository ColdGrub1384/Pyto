//
//  CTCellularPlanProvisioningRequest.h
//  CFTelephony
//
//  Copyright (c) 2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreTelephony/CoreTelephonyDefines.h>

typedef NS_ENUM(NSUInteger, CTCellularPlanProvisioningAddPlanResult) {
	CTCellularPlanProvisioningAddPlanResultUnknown,
	CTCellularPlanProvisioningAddPlanResultFail,
	CTCellularPlanProvisioningAddPlanResultSuccess
};

CORETELEPHONY_EXTERN_CLASS
@interface CTCellularPlanProvisioningRequest : NSObject<NSSecureCoding>

@property (nonatomic, strong, nonnull)  NSString *address;
@property (nonatomic, strong, nullable) NSString *matchingID;
@property (nonatomic, strong, nullable) NSString *OID;
@property (nonatomic, strong, nullable) NSString *confirmationCode;
@property (nonatomic, strong, nullable) NSString *ICCID;
@property (nonatomic, strong, nullable) NSString *EID;

@end

