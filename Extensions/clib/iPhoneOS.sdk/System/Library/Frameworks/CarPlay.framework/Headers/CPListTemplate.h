//
//  CPListTemplate.h
//  CarPlay
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <CarPlay/CPBarButtonProviding.h>
#import <CarPlay/CPListItem.h>
#import <CarPlay/CPListSection.h>
#import <CarPlay/CPTemplate.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CPListTemplateDelegate;

API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface CPListTemplate : CPTemplate <CPBarButtonProviding>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Initialize a list template with one or more sections of items and an optional title.
 */
- (instancetype)initWithTitle:(nullable NSString *)title
                     sections:(NSArray <CPListSection *> *)sections;

/**
 The list template's delegate is informed of list selection events.
 */
@property (nullable, nonatomic, weak) id<CPListTemplateDelegate> delegate;

/**
 The sections displayed in this list.
 */
@property (nonatomic, readonly, copy) NSArray <CPListSection *> *sections;

/**
 Title shown in the navigation bar while this template is visible.
 */
@property (nullable, nonatomic, readonly, copy) NSString *title;

/**
 Update the list of sections displayed in this list template, reloading
 the table view displaying this list.
 */
- (void)updateSections:(NSArray <CPListSection *> *)sections;

@end

API_AVAILABLE(ios(12.0)) API_UNAVAILABLE(macos, watchos, tvos)
@protocol CPListTemplateDelegate <NSObject>

/**
 The user has selected an item in the list template.
 
 Your app has an opportunity to perform any necessary operations to prepare for completing
 this item selection. The list template will display a spinner after a short delay.
 
 You must call the completion block after your app has finished loading and updated its UI.
 
 @param listTemplate The list template containing this item
 @param item The item selected by the user
 @param completionHandler A completion block you must call after you have updated your UI.
 */
- (void)listTemplate:(CPListTemplate *)listTemplate didSelectListItem:(CPListItem *)item completionHandler:(void (^)(void))completionHandler;

@end

NS_ASSUME_NONNULL_END
