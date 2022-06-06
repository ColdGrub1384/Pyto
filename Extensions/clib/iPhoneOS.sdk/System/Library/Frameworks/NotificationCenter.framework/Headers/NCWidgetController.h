//
//  NCWidgetController.h
//  NotificationCenter
//
//  Copyright (c) 2014 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

// 'NCWidgetController' provides an interface available to both the widget and the widget-providing app through which clients can specify whether the widget has content to display.
// If the widget determines it no longer has content to display, it can obtain a widget controller and update this state.
// Later, should the providing app determine that the widget should have content, it can update this state via a widget controller as well, even if the widget is no longer running.
// This class is NOT intended to be subclassed.
NS_ASSUME_NONNULL_BEGIN
NS_CLASS_AVAILABLE_IOS(8_0) @interface NCWidgetController : NSObject

+ (instancetype)widgetController;

// Whether the widget has content to display, and the view should be visible in Notification Center. Default is 'YES'.
// A widget controller can be obtained and messaged in either the widget or the providing app.
- (void)setHasContent:(BOOL)flag forWidgetWithBundleIdentifier:(NSString *)bundleID;

@end
NS_ASSUME_NONNULL_END
