//
//  NotificationCenterDefines.h
//  NotificationCenter
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <Availability.h>

#ifdef __cplusplus
#define NOTIFICATION_CENTER_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define NOTIFICATION_CENTER_EXTERN extern __attribute__((visibility ("default")))
#endif
