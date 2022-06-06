//
//  CPAlertTemplate.h
//  CarPlay
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <CarPlay/CPAlertAction.h>
#import <CarPlay/CPTemplate.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @c CPAlertTemplate represents a modal alert that must be dismissed with a button press
 before the user may return to using the app.
 */
API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface CPAlertTemplate : CPTemplate

/**
 Initialize a @c CPAlertTemplate by specifying a list of title variants and at least one action.

 @param titleVariants a list of title variants
 @param actions the alert actions

 */
- (instancetype)initWithTitleVariants:(NSArray<NSString *> *)titleVariants
                              actions:(NSArray <CPAlertAction *> *)actions;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, copy, readonly) NSArray<NSString *> *titleVariants;

#pragma mark - Actions

@property (nonatomic, strong, readonly) NSArray <CPAlertAction *> *actions;

@end

NS_ASSUME_NONNULL_END
