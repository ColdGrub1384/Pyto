#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIMenu.h>)
//
//  UIMenu.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIMenuElement.h>

typedef NSString *UIMenuIdentifier NS_SWIFT_NAME(UIMenu.Identifier) NS_TYPED_EXTENSIBLE_ENUM API_AVAILABLE(ios(13.0));

typedef NS_OPTIONS(NSUInteger, UIMenuOptions) {
    /// Show children inline in parent, instead of hierarchically
    UIMenuOptionsDisplayInline  = 1 << 0,

    /// Indicates whether the menu should be rendered with a destructive appearance in its parent
    UIMenuOptionsDestructive    = 1 << 1,
} NS_SWIFT_NAME(UIMenu.Options) API_AVAILABLE(ios(13.0));

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UIMenu : UIMenuElement

/// Unique identifier.
@property (nonatomic, readonly) UIMenuIdentifier identifier;

/// Options.
@property (nonatomic, readonly) UIMenuOptions options;

/// The menu's sub-elements and sub-menus. All children are immutable.
@property (nonatomic, readonly) NSArray<UIMenuElement *> *children;

/*!
 * @abstract Creates a UIMenu with the given arguments.
 *
 * @param title       The menu's title.
 * @param children    The menu's action-based sub-elements and sub-menus.
 *
 * @return A new UIMenu.
 */
+ (UIMenu *)menuWithTitle:(NSString *)title
                 children:(NSArray<UIMenuElement *> *)children NS_SWIFT_UNAVAILABLE("Use init(title:image:identifier:options:children:) instead");

/*!
 * @abstract Creates a UIMenu with the given arguments.
 *
 * @param title       The menu's title.
 * @param image       Image to be displayed alongside the menu's title.
 * @param identifier  The menu's unique identifier. Pass nil to use an auto-generated identifier.
 * @param options     The menu's options.
 * @param children    The menu's action-based sub-elements and sub-menus.
 *
 * @return A new UIMenu.
 */
+ (UIMenu *)menuWithTitle:(NSString *)title
                    image:(nullable UIImage *)image
               identifier:(nullable UIMenuIdentifier)identifier
                  options:(UIMenuOptions)options
                 children:(NSArray<UIMenuElement *> *)children NS_REFINED_FOR_SWIFT;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/*!
 * @abstract Copies this menu and replaces its children.
 *
 * @param newChildren  The replacement children.
 *
 * @return A copy of this menu with updated children.
 */
- (UIMenu *)menuByReplacingChildren:(NSArray<UIMenuElement *> *)newChildren;

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIMenu.h>
#endif
