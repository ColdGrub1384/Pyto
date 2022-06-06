//
//  UIFont+EKDayOccurrenceView.h
//  EventKitUI
//
//  Created by harry-dev on 4/18/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (EKDayOccurrenceView)

@property (nonatomic, readonly, class) UIFont *ek_defaultOccurrenceSecondaryTextFont;

+ (UIFont *)ek_defaultOccurrencePrimaryTextFontForSizeClass:(UIUserInterfaceSizeClass)sizeClass;
+ (UIFont *)ek_defaultOccurrenceSmallPrimaryTextFontForSizeClass:(UIUserInterfaceSizeClass)sizeClass;

@end

NS_ASSUME_NONNULL_END
