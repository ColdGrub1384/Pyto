//
//  CLSQuantityItem.h
//  ClassKit
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <ClassKit/CLSActivityItem.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @abstract      CLSQuantityItem represents user generated quantity information.
 */

API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos)
@interface CLSQuantityItem : CLSActivityItem

/*!
 @abstract      Quantity awarded.
 */
@property (nonatomic, assign) double quantity;

/*!
 @abstract      Create a quantity item with an identifier and title.
 @param         identifier      An identifier that is unique within activity.
 @param         title           Title of the quantity. Ex @em Hints @em
 */
- (instancetype)initWithIdentifier:(NSString *)identifier
                             title:(NSString *)title NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
