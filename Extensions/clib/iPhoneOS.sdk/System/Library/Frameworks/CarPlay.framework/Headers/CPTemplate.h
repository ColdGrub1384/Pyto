//
//  CPTemplate.h
//  CarPlay
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Abstract superclass for a template object.
 */
API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface CPTemplate : NSObject <NSSecureCoding>

/**
 Any custom data or an object associated with this template can be stored in this property.
 */
@property (nullable, nonatomic, strong) id userInfo;

@end

NS_ASSUME_NONNULL_END
