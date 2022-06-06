//
//  NKLibrary.h
//  NewsstandKit
//
//  Copyright 2011 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NKIssue;
@class NKAssetDownload;


/*!
 @class      NKLibrary
 @abstract   Represents the library of Newsstand issues
 @discussion This is the library of Newsstand issues. Upon launch, one can
 get the issues in the Newsstand library and determine any outstanding
 downloading assets. To reconnect with any outstanding background
 download of content, you will be required to call 
 -[NKAssetDownload downloadWithDelegate:].
 */
NS_ASSUME_NONNULL_BEGIN
NS_CLASS_DEPRECATED_IOS(5.0, 13.0, "Use the Remote Notifications Background Modes instead: https://developer.apple.com/documentation/usernotifications/setting_up_a_remote_notification_server/pushing_updates_to_your_app_silently")
@interface NKLibrary : NSObject

/*!
 @property   issues
 @abstract   The Newsstand issues in the library
 */
@property (readonly, strong) NSArray<NKIssue *> *issues;

/*!
 @property   downloadingAssets
 @abstract   The assets that are currently being downloaded in this
 Newsstand library. The issue that this asset is associated with
 can be determined from the asset itself.
 */
@property (readonly, strong) NSArray<NKAssetDownload *> *downloadingAssets;

/*!
 @property   currentlyReadingIssue
 @abstract   The issue that is currently being read by the user. Clients should
 set this property to the currently read issue to prevent data
 from being purged when under disk pressure.
 */
@property (strong, nullable) NKIssue *currentlyReadingIssue;

/*!
 @method     sharedLibrary
 @abstract   The application's shared Newsstand Content Library
 */
+ (nullable NKLibrary *)sharedLibrary;

/*!
 @method     issueWithName:
 @abstract   Return the issue identified by the given name if it exists.
 */
- (nullable NKIssue *)issueWithName:(NSString *)name;

/*!
 @method     addIssueWithName:date:
 @abstract   Add a new issue to the Newsstand Content Library.
 */
- (NKIssue *)addIssueWithName:(NSString *)name date:(NSDate *)date;

/*!
 @method     removeIssue:
 @abstract   Remove the issue from the library
 */
- (void)removeIssue:(NKIssue *)issue;

@end
NS_ASSUME_NONNULL_END
