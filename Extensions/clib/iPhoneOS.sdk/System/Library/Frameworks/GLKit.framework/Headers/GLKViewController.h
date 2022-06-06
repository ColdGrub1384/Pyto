//
//  GLKViewController.h
//  GLKit
//
//  Copyright (c) 2011-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#import <GLKit/GLKView.h>

NS_ASSUME_NONNULL_BEGIN
@protocol GLKViewControllerDelegate;

#pragma mark -
#pragma mark GLKViewController
#pragma mark -

OPENGLES_DEPRECATED(ios(5.0,12.0), tvos(9.0,12.0))
API_UNAVAILABLE(macos)
@interface GLKViewController : UIViewController <NSCoding, GLKViewDelegate>
{
    
}

@property (nullable, nonatomic, assign) IBOutlet id <GLKViewControllerDelegate> delegate;

/*
 For setting the desired frames per second at which the update and drawing will take place.
 The default is 30.
 */
@property (nonatomic) NSInteger preferredFramesPerSecond;

/*
 The actual frames per second that was decided upon given the value for preferredFramesPerSecond
 and the screen for which the GLKView resides. The value chosen will be as close to
 preferredFramesPerSecond as possible, without exceeding the screen's refresh rate. This value
 does not account for dropped frames, so it is not a measurement of your statistical frames per
 second. It is the static value for which updates will take place.
 */
@property (nonatomic, readonly) NSInteger framesPerSecond;

/*
 Used to pause and resume the controller.
 */
@property (nonatomic, getter=isPaused) BOOL paused;

/*
 The total number of frames displayed since drawing began.
 */
@property (nonatomic, readonly) NSInteger framesDisplayed;

/*
 Time interval since properties.
 */
@property (nonatomic, readonly) NSTimeInterval timeSinceFirstResume;
@property (nonatomic, readonly) NSTimeInterval timeSinceLastResume;
@property (nonatomic, readonly) NSTimeInterval timeSinceLastUpdate;
@property (nonatomic, readonly) NSTimeInterval timeSinceLastDraw;

/*
 If true, the controller will pause when the application recevies a willResignActive notification.
 If false, the controller will not pause and it is expected that some other mechanism will pause
 the controller when necessary.
 The default is true.
 */
@property (nonatomic) BOOL pauseOnWillResignActive;

/*
 If true, the controller will resume when the application recevies a didBecomeActive notification.
 If false, the controller will not resume and it is expected that some other mechanism will resume
 the controller when necessary.
 The default is true.
 */
@property (nonatomic) BOOL resumeOnDidBecomeActive;

@end

#pragma mark -
#pragma mark GLKViewControllerDelegate
#pragma mark -

@protocol GLKViewControllerDelegate <NSObject>

@required
/*
 Required method for implementing GLKViewControllerDelegate. This update method variant should be used
 when not subclassing GLKViewController. This method will not be called if the GLKViewController object
 has been subclassed and implements -(void)update.
 */
- (void)glkViewControllerUpdate:(GLKViewController *)controller;

@optional
/*
 Delegate method that gets called when the pause state changes. 
 */
- (void)glkViewController:(GLKViewController *)controller willPause:(BOOL)pause;

@end
NS_ASSUME_NONNULL_END
