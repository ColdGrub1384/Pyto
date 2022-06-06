//
//  CLSObject.h
//  ClassKit
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @abstract      An object managed by ClassKit.
 @discussion    See @c CLSContext for more details.
 */

API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos)
@interface CLSObject : NSObject <NSSecureCoding>

/*!
 @abstract      The date this object was created.
 */
@property (nonatomic, strong, readonly) NSDate *dateCreated;

/*!
 @abstract      The date this object was last modified.
 */
@property (nonatomic, strong, readonly) NSDate *dateLastModified;

- (instancetype)init NS_UNAVAILABLE;

@end


NS_ASSUME_NONNULL_END
