//
//  CPListItem.h
//  CarPlay
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern CGSize const CPMaximumListItemImageSize; // 44 x 44

/**
 @c CPListItem describes a single object appearing in a list template.
 Each @c CPListItem is displayed in a single cell in the list.
 */
API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface CPListItem : NSObject <NSSecureCoding>

/**
 Initialize a list item with text, detailtext, an image, and a disclosure indicator.

 @note The maximum image size is 44 points by 44 points. If you supply a larger image,
 it will be scaled down to this size.
 */
- (instancetype)initWithText:(nullable NSString *)text
                  detailText:(nullable NSString *)detailText
                       image:(nullable UIImage *)image
    showsDisclosureIndicator:(BOOL)showsDisclosureIndicator;

/**
 Initialize a list item with text, detail text, and an image.

 @note The maximum image size is 44 points by 44 points. If you supply a larger image,
 it will be scaled down to this size.
 */
- (instancetype)initWithText:(nullable NSString *)text
                  detailText:(nullable NSString *)detailText
                       image:(nullable UIImage *)image;

/**
 Initialize a list item with text and detail text.
 */
- (instancetype)initWithText:(nullable NSString *)text
                  detailText:(nullable NSString *)detailText;

/**
 The primary text shown in a cell displaying this list item.
 */
@property (nullable, nonatomic, readonly, copy) NSString *text;

/**
 Any extra text displayed below the primary text in a cell displaying this list item.
 */
@property (nullable, nonatomic, readonly, copy) NSString *detailText;

/**
 An image displayed on the leading side of a cell displaying this list item.

 @discussion Animated images are not supported. If an animated image is assigned, only the first image will be used.
 */
@property (nullable, nonatomic, readonly, strong) UIImage *image;

/**
 If YES, a cell displaying this list item will render with a disclosure indicator
 in the trailing side of the cell.

 Defaults to NO.
 */
@property (nonatomic, readonly, assign) BOOL showsDisclosureIndicator;

/**
 Any custom user info related to this item.
 */
@property (nullable, nonatomic, strong) id userInfo;

@end

NS_ASSUME_NONNULL_END
