//
//  NCWidgetProviding.h
//  NotificationCenter
//
//  Copyright (c) 2014 Apple. All rights reserved.
//

#import <NotificationCenter/NotificationCenterDefines.h>
#import <NotificationCenter/NCWidgetTypes.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// If the widget has local state that can be loaded quickly, it should do so before returning from ‘viewWillAppear:’.
// Otherwise, the widget should ensure that the state and layout of its view when returning from 'viewWillAppear:’ will match that of the last time it returned from 'viewWillDisappear:', transitioning smoothly to the new data later when it arrives.”

// While the Notification Center ultimately controls the layout of its children, widgets can request a change in height.
// Widgets with heights defined by constraints will be automatically adjusted (within limits).
// Widgets using explicit layout can request a new height (that may, or may not, be adjusted or honored at all) by changing the value of their ‘preferredContentSize’.
// Should either form of request result in a height change, the widget will be messaged with ‘viewWillTransitionToSize:withTransitionCoordinator:’ and, if the transition is animated, passed a transition coordinator.
// If the transition coordinator argument is not 'nil', and the widget has additional animations it wishes to run in concert with the height change, it can specify them and/or a completion block by messaging the coordinator with 'animateAlongsideTransition:completion:'.

typedef NS_ENUM(NSUInteger, NCUpdateResult) {
    NCUpdateResultNewData,
    NCUpdateResultNoData,
    NCUpdateResultFailed
} __API_AVAILABLE(ios(8.0));

// 'NCWidgetProviding' is an optional protocol for further customizing aspects of the provided content. 

NS_ASSUME_NONNULL_BEGIN
@protocol NCWidgetProviding <NSObject>

@optional

// If implemented, the system will call at opportune times for the widget to update its state, both when the Notification Center is visible as well as in the background.
// An implementation is required to enable background updates.
// It's expected that the widget will perform the work to update asynchronously and off the main thread as much as possible.
// Widgets should call the argument block when the work is complete, passing the appropriate 'NCUpdateResult'.
// Widgets should NOT block returning from 'viewWillAppear:' on the results of this operation.
// Instead, widgets should load cached state in 'viewWillAppear:' in order to match the state of the view from the last 'viewWillDisappear:', then transition smoothly to the new data when it arrives.
- (void)widgetPerformUpdateWithCompletionHandler:(void (^)(NCUpdateResult result))completionHandler;

// If implemented, called when the active display mode changes.
// The widget may wish to change its preferredContentSize to better accommodate the new display mode.
- (void)widgetActiveDisplayModeDidChange:(NCWidgetDisplayMode)activeDisplayMode withMaximumSize:(CGSize)maxSize __API_AVAILABLE(ios(10.0));

// Widgets wishing to customize the default margin insets can return their preferred values.
// Widgets that choose not to implement this method will receive the default margin insets.
- (UIEdgeInsets)widgetMarginInsetsForProposedMarginInsets:(UIEdgeInsets)defaultMarginInsets __API_DEPRECATED("This method will not be called on widgets linked against iOS versions 10.0 and later.", ios(8.0, 10.0));

@end

@interface NSExtensionContext (NCWidgetAdditions)

// Widgets can change the largest display mode they make available from the default 'NCWidgetDisplayModeCompact' by messaging the extension context.
// Modifying this property more than once during the lifetime of the widget (perhaps due to changes in the amount of available content) is supported.
@property (nonatomic, assign) NCWidgetDisplayMode widgetLargestAvailableDisplayMode __API_AVAILABLE(ios(10.0));
@property (nonatomic, assign, readonly) NCWidgetDisplayMode widgetActiveDisplayMode __API_AVAILABLE(ios(10.0));

- (CGSize)widgetMaximumSizeForDisplayMode:(NCWidgetDisplayMode)displayMode __API_AVAILABLE(ios(10.0));

@end

@interface UIVibrancyEffect (NCWidgetAdditions)

+ (UIVibrancyEffect *)widgetEffectForVibrancyStyle:(UIVibrancyEffectStyle)vibrancyStyle __API_AVAILABLE(ios(13.0));

@end

@interface UIVibrancyEffect (NCWidgetDeprecated)

+ (UIVibrancyEffect *)widgetPrimaryVibrancyEffect __API_DEPRECATED_WITH_REPLACEMENT("widgetEffectForVibrancyStyle:", ios(10.0, 13.0)); // For use with select supporting text and glyphs.
+ (UIVibrancyEffect *)widgetSecondaryVibrancyEffect __API_DEPRECATED_WITH_REPLACEMENT("widgetEffectForVibrancyStyle:", ios(10.0, 13.0)); // For use with select supporting text and glyphs where further diminution is required.

+ (UIVibrancyEffect *)notificationCenterVibrancyEffect __API_DEPRECATED_WITH_REPLACEMENT("widgetEffectForVibrancyStyle:", ios(8.0, 10.0));

@end

NS_ASSUME_NONNULL_END
