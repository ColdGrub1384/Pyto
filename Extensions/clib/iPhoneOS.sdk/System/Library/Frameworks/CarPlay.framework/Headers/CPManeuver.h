//
//  CPManeuver.h
//  CarPlay
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <CarPlay/CPImageSet.h>
#import <Foundation/Foundation.h>
#import <CarPlay/CPTravelEstimates.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @c CPManeuver describes a navigation instruction.
 */
API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface CPManeuver : NSObject <NSCopying, NSSecureCoding>

/**
 symbolSet is a @c CPImageSet representing the maneuver.
 */
@property (nullable, nonatomic, strong) CPImageSet *symbolSet API_DEPRECATED_WITH_REPLACEMENT("symbolImage", ios(12.0, 13.0)) API_UNAVAILABLE(macos, watchos, tvos);

/**
 symbolImage is a @c UIImage representing the maneuver. Provide variants for UIUserInterfaceStyleLight and UIUserInterfaceStyleDark that will be used against light backgrounds and dark backgrounds.
 */
@property (nullable, nonatomic, strong) UIImage *symbolImage;

/**
 junctionImage is a @c UIImage used to display a junction for the maneuver.
 
 @note The maximum image size is 140 points by 100 points. If necessary, images will be scaled down to fit while maintaining the aspect ratio.
 */
@property (nullable, nonatomic, strong) UIImage *junctionImage;

/**
 instructionVariants is an array of @c NSString representing the instruction for this maneuver, arranged from most to least preferred. You must provide at least one variant.
 The variant strings should be provided as localized, displayable content.
 */
@property (nonatomic, copy) NSArray<NSString *> *instructionVariants;

/**
   initialTravelEstimates represents the estimates beginning from the end of the preceding maneuver.
*/
@property (nullable, nonatomic, strong) CPTravelEstimates *initialTravelEstimates;

/**
 attributedInstructionVariants is an array of @c NSAttributedString representing the instruction for this maneuver,
 arranged from most to least preferred.
 
 @c attributedInstructionVariants will be preferred over instructionVariants. You must provide at least one variant for each maneuver.
 
 Only one attribute is presently supported: text attachments. You may annotate a maneuver instruction with an image
 by including a text attachment. The maximum text attachment image size is 64x16 points.

 @warning All attributes other than text attachment attributes will be removed from your attributed string.

 @see +[NSAttributedString attributedStringWithAttachment:], -[NSTextAttachment image]
 */
@property (nonatomic, copy) NSArray<NSAttributedString *> *attributedInstructionVariants;

/**
 Any custom user info related to this maneuver.
 */
@property (nullable, nonatomic, strong) id userInfo;

@end

NS_ASSUME_NONNULL_END
