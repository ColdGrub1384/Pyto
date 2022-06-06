//
//  CTCellularData.h
//  CFTelephony
//
//  Copyright (c) 2015 Apple Inc. All rights reserved.
//

#import <CoreTelephony/CoreTelephonyDefines.h>

typedef NS_ENUM(NSUInteger, CTCellularDataRestrictedState) {
	kCTCellularDataRestrictedStateUnknown,
	kCTCellularDataRestricted,
	kCTCellularDataNotRestricted
};

typedef void (^CellularDataRestrictionDidUpdateNotifier)(CTCellularDataRestrictedState);

NS_ASSUME_NONNULL_BEGIN

CORETELEPHONY_CLASS_AVAILABLE(9_0)
@interface CTCellularData : NSObject
/*
 * cellularDataRestrictionDidUpdateNotifier
 *
 * A block that will be dispatched on the default priority global dispatch queue the first time 
 * app sets the callback handler and everytime there is a change in cellular data allowed policy 
 * for the app.
 */

@property (copy, nullable) CellularDataRestrictionDidUpdateNotifier cellularDataRestrictionDidUpdateNotifier __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_9_0);
@property (nonatomic, readonly) CTCellularDataRestrictedState restrictedState __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_9_0);
@end

NS_ASSUME_NONNULL_END

