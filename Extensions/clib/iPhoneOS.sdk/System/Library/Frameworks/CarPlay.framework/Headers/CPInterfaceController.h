//
//  CPInterfaceController.h
//  CarPlay
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <CarPlay/CPAlertTemplate.h>
#import <CarPlay/CPTemplate.h>
#import <CarPlay/CPWindow.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CPManeuver, CPNavigationAlert;
@protocol CPInterfaceControllerDelegate;

API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface CPInterfaceController : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 The delegate for this interface controller.
 */
@property (nonatomic, weak) id<CPInterfaceControllerDelegate> delegate;

/**
 Set the preferred interface style to UIUserInterfaceStyleDark for all templates. Set this value to YES prior to setting a root template
 or pushing any templates for first appearance to have style UIUserInterfaceStyleDark. The default value is NO which will allow templates to change between light and dark styles.
 */
@property (nonatomic, assign) BOOL prefersDarkUserInterfaceStyle API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(macos, watchos, tvos);

#pragma mark - Templates

/**
 Set the root template. If no existing templates exist in the template navigation hierarchy, the animated flag will be ignored.
 If there is an existing template navigation hierarchy, the existing stack will be replaced by the new root template.
 */
- (void)setRootTemplate:(__kindof CPTemplate *)rootTemplate animated:(BOOL)animated;

/**
 Push a new template onto the template navigation hierarchy, showing it immediately.
 */
- (void)pushTemplate:(__kindof CPTemplate *)templateToPush animated:(BOOL)animated;

/**
 Pop back a single level in the template navigation hierarchy.
 */
- (void)popTemplateAnimated:(BOOL)animated;

/**
 Pop back to the first template in the template navigation hierarchy.
 */
- (void)popToRootTemplateAnimated:(BOOL)animated;

/**
 Pop back to a specified template.
 
 targetTemplate must exist in the current template navigation hierarchy.
 */
- (void)popToTemplate:(__kindof CPTemplate *)targetTemplate animated:(BOOL)animated;

/**
 Present a template modally over the navigation hierarchy. Only one template may be presented at a time.

 @note Supported template types: @c CPActionSheetTemplate, @c CPAlertTemplate, @c CPVoiceControlTemplate
 */
- (void)presentTemplate:(__kindof CPTemplate *)templateToPresent animated:(BOOL)animated;

/**
 Dismiss the current modally-presented template, optionally animating the dismissal.

 @note If there is no current modally-presented template, this method will have no effect.
 */
- (void)dismissTemplateAnimated:(BOOL)animated;

/**
 The current modally-presented template.

 @warning Reading this property may synchronously perform an IPC call to retrieve the current presented template.
 */
@property (nonatomic, readonly, nullable) __kindof CPTemplate *presentedTemplate;

/**
 Returns the root template.
 */
@property (nonatomic, readonly) __kindof CPTemplate *rootTemplate;

/**
 The top template in the navigation hierarchy.

 @warning Reading this property may synchronously perform an IPC call to retrieve the current top-most template.
 */
@property (nullable, nonatomic, readonly, strong) CPTemplate *topTemplate;

/**
 The current stack of templates in the navigation hierarchy.

 @warning Reading this property may synchronously perform an IPC call to retrieve the current stack of templates.
 */
@property (nonatomic, readonly, strong) NSArray<CPTemplate *> *templates;

@end


/**
 */
API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@protocol CPInterfaceControllerDelegate <NSObject>

@optional

- (void)templateWillAppear:(CPTemplate *)aTemplate animated:(BOOL)animated;
- (void)templateDidAppear:(CPTemplate *)aTemplate animated:(BOOL)animated;
- (void)templateWillDisappear:(CPTemplate *)aTemplate animated:(BOOL)animated;
- (void)templateDidDisappear:(CPTemplate *)aTemplate animated:(BOOL)animated;

@end


/**
 A set of methods that are called by the @c UIApplication singleton in response to CarPlay lifecycle events.

 @discussion This must be implemented by the same object that serves as your application's delegate object.
 */
API_DEPRECATED_WITH_REPLACEMENT("CPTemplateApplicationSceneDelegate", ios(12.0, 13.0)) API_UNAVAILABLE(macos, watchos, tvos)
@protocol CPApplicationDelegate <UIApplicationDelegate>

@required

/**
 The CarPlay screen has connected and is ready to present content.

 Your app should create its view controller and assign it to the @c rootViewController property
 of this window.

 @note It is the responsibility of the delegate to maintain a reference to the interface controller beyond the scope of this method.
 */
- (void)application:(UIApplication *)application didConnectCarInterfaceController:(CPInterfaceController *)interfaceController toWindow:(CPWindow *)window;

/**
 The CarPlay screen has disconnected.
 */
- (void)application:(UIApplication *)application didDisconnectCarInterfaceController:(CPInterfaceController *)interfaceController fromWindow:(CPWindow *)window;

@optional

/**
 If your application posts a @c CPNavigationAlert while backgrounded, a notification banner may be presented to the user.
 If the user taps on that banner, your application will launch on the car screen and this method will be called
 with the alert the user tapped.
 */
- (void)application:(UIApplication *)application didSelectNavigationAlert:(CPNavigationAlert *)navigationAlert;

/**
 If your application posts a @c CPManeuver while backgrounded, a notification banner may be presented to the user.
 If the user taps on that banner, your application will launch on the car screen and this method will be called
 with the maneuver the user tapped.
 */
- (void)application:(UIApplication *)application didSelectManeuver:(CPManeuver *)maneuver;

@end

NS_ASSUME_NONNULL_END
