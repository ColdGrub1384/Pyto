//
//  UNNotificationContentExtension.h
//  UserNotificationsUI
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>

@class UNNotification;
@class UNNotificationAction;
@class UNNotificationResponse;

typedef NS_ENUM(NSUInteger, UNNotificationContentExtensionMediaPlayPauseButtonType) {
    UNNotificationContentExtensionMediaPlayPauseButtonTypeNone,
    UNNotificationContentExtensionMediaPlayPauseButtonTypeDefault,
    UNNotificationContentExtensionMediaPlayPauseButtonTypeOverlay,
} __IOS_AVAILABLE(10_0) __TVOS_UNAVAILABLE __WATCHOS_UNAVAILABLE __OSX_UNAVAILABLE;

typedef NS_ENUM(NSUInteger, UNNotificationContentExtensionResponseOption) {
    UNNotificationContentExtensionResponseOptionDoNotDismiss,
    UNNotificationContentExtensionResponseOptionDismiss,
    UNNotificationContentExtensionResponseOptionDismissAndForwardAction,
} __IOS_AVAILABLE(10_0) __TVOS_UNAVAILABLE __WATCHOS_UNAVAILABLE __OSX_UNAVAILABLE;

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10_0) __TVOS_UNAVAILABLE __WATCHOS_UNAVAILABLE __OSX_UNAVAILABLE
@protocol UNNotificationContentExtension <NSObject>

// This will be called to send the notification to be displayed by
// the extension. If the extension is being displayed and more related
// notifications arrive (eg. more messages for the same conversation)
// the same method will be called for each new notification.
- (void)didReceiveNotification:(UNNotification *)notification;

@optional

// If implemented, the method will be called when the user taps on one
// of the notification actions. The completion handler can be called
// after handling the action to dismiss the notification and forward the
// action to the app if necessary.
- (void)didReceiveNotificationResponse:(UNNotificationResponse *)response completionHandler:(void (^)(UNNotificationContentExtensionResponseOption option))completion;

// Implementing this method and returning a button type other that "None" will
// make the notification attempt to draw a play/pause button correctly styled
// for that type.
@property (nonatomic, readonly, assign) UNNotificationContentExtensionMediaPlayPauseButtonType mediaPlayPauseButtonType;

// Implementing this method and returning a non-empty frame will make
// the notification draw a button that allows the user to play and pause
// media content embedded in the notification.
@property (nonatomic, readonly, assign) CGRect mediaPlayPauseButtonFrame;

// The tint color to use for the button.
@property (nonatomic, readonly, copy) UIColor *mediaPlayPauseButtonTintColor;

// Called when the user taps the play or pause button.
- (void)mediaPlay;
- (void)mediaPause;

@end


@interface NSExtensionContext (UNNotificationContentExtension)

@property (nonatomic, copy) NSArray <UNNotificationAction *> *notificationActions __IOS_AVAILABLE(12_0) __TVOS_UNAVAILABLE __WATCHOS_UNAVAILABLE __OSX_UNAVAILABLE;

// Opens the corresponding applicaton and delivers it the default notification action response
- (void)performNotificationDefaultAction __IOS_AVAILABLE(12_0) __TVOS_UNAVAILABLE __WATCHOS_UNAVAILABLE __OSX_UNAVAILABLE;

- (void)dismissNotificationContentExtension __IOS_AVAILABLE(12_0) __TVOS_UNAVAILABLE __WATCHOS_UNAVAILABLE __OSX_UNAVAILABLE;

// Call these methods when the playback state changes in the content
// extension to update the state of the media control button.
- (void)mediaPlayingStarted __IOS_AVAILABLE(10_0) __TVOS_UNAVAILABLE __WATCHOS_UNAVAILABLE __OSX_UNAVAILABLE;
- (void)mediaPlayingPaused __IOS_AVAILABLE(10_0) __TVOS_UNAVAILABLE __WATCHOS_UNAVAILABLE __OSX_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
