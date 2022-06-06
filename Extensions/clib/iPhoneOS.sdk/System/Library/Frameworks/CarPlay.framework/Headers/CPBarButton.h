//
//  CPBarButton.h
//  CarPlay
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Specifies the style of a @c CPBarButton
 */
typedef NS_ENUM(NSUInteger, CPBarButtonType) {
    CPBarButtonTypeText,
    CPBarButtonTypeImage,
} API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos);

/**
 A button for placement in a navigation bar.
 */
API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface CPBarButton : NSObject <NSSecureCoding>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize a new bar button of the specified type.

 @param type The button type. See @c CPBarButtonType for the possible values.
 @param handler A block to execute when the user selects the button. The block has no return value and takes the selected button as its only parameter.
 */
- (instancetype)initWithType:(CPBarButtonType)type handler:(void (^ _Nullable)(CPBarButton *barButton))handler NS_DESIGNATED_INITIALIZER;

/**
 A Boolean value indicating whether the button is enabled.

 @discussion Set the value of this property to @c YES to enable the button or @c NO to disable it. The default value of this property is @c YES.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/**
 The button type.

 @discussion See @c CPBarButtonType for the possible values.
 */
@property (nonatomic, readonly, assign) CPBarButtonType buttonType;

/**
 The image displayed on the button.

 @discussion Animated images are not supported. If an animated image is assigned, only the first image will be used.

 @note The setter has no effect unless the button is of type @c CPBarButtonTypeImage
 */
@property (nullable, nonatomic, strong) UIImage *image;

/**
 The title displayed on the button.

 @note The setter has no effect unless the button is of type @c CPBarButtonTypeText
 */
@property (nullable, nonatomic, copy) NSString *title;

@end

NS_ASSUME_NONNULL_END
