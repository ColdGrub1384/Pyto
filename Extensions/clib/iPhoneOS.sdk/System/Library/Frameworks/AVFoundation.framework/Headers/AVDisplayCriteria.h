/*
	File:  AVDisplayCriteria.h

	Framework:  AVFoundation

	Copyright 2017-2018 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AVDisplayCriteriaInternal;

/*
 @class			AVDisplayCriteria
 @abstract		AVDisplayCriteria is an abstract set of properties that is used to guide the selection of a display mode.
 @discussion	Certain display modes are more suitable for certain types of content.
 */

API_AVAILABLE(tvos(11.2)) API_UNAVAILABLE(ios) API_UNAVAILABLE(macos, watchos)
@interface AVDisplayCriteria : NSObject <NSCopying>
{
@private
	AVDisplayCriteriaInternal *_displayCriteria;
}

@end

NS_ASSUME_NONNULL_END
