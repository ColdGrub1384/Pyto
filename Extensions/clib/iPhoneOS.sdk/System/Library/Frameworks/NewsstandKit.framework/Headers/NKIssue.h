//
//  NKIssue.h
//  NewsstandKit
//
//  Copyright 2011 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NKAssetDownload;

/*!
 @constant   NKIssueDownloadCompletedNotification
 @abstract   Notification when an issue's assets have all been downloaded.
 */
extern __attribute__((visibility ("default"))) NSString * __nonnull const NKIssueDownloadCompletedNotification NS_DEPRECATED_IOS(5.0, 13.0, "Use the Remote Notifications Background Modes instead: https://developer.apple.com/documentation/usernotifications/setting_up_a_remote_notification_server/pushing_updates_to_your_app_silently");

typedef NS_ENUM(NSInteger, NKIssueContentStatus) {
    NKIssueContentStatusNone,
    NKIssueContentStatusDownloading,
    NKIssueContentStatusAvailable,
} NS_ENUM_DEPRECATED_IOS(5.0, 13.0, "Use the Remote Notifications Background Modes instead: https://developer.apple.com/documentation/usernotifications/setting_up_a_remote_notification_server/pushing_updates_to_your_app_silently");


/*!
 @class      NKIssue
 @abstract   Represents the Newsstand issue and its location on disk.
 @discussion All Newsstand issues have a publication date and a unique name. 
 You register assets for download through this class.
 All of the Newsstand content that represents this issue should be
 placed in the URL provided by contentURL.
 If there are any downloading assets associated with this issue,
 the state of the issue is "downloading". If there are no outstanding
 downloading assets and the contentURL is non-empty, the state
 is "content available".
 An issue is created by adding it to the library with
 -[NKLibrary addIssueWithName:date:].
 */
NS_ASSUME_NONNULL_BEGIN
NS_CLASS_DEPRECATED_IOS(5.0, 13.0, "Use the Remote Notifications Background Modes instead: https://developer.apple.com/documentation/usernotifications/setting_up_a_remote_notification_server/pushing_updates_to_your_app_silently")
@interface NKIssue : NSObject

/*!
 @property   downloadingAssets
 @abstract   An array of NKAssetDownload associated with this issue.
 */
@property (readonly, copy) NSArray<NKAssetDownload *> *downloadingAssets;

/*!
 @property   contentURL
 @abstract   All content that represents this issue should be placed in the
 URL provided.
 */
@property (readonly, copy) NSURL   *contentURL;

/*!
 @property   status
 @abstract   The availability of this issue's content.
 @discussion If there are asset downloads associated with this issue, the status
 is NKIssueContentStatusDownloading. If there are no downloading assets
 and the directory represented by contentURL is non-empty, the status
 is NKIssueContentStatusAvailable. Otherwise, no content is available
 at the destination and the status is NKIssueContentStatusNone.
 */
@property (readonly) NKIssueContentStatus    status;

/*!
 @property   name
 @abstract   The unique name given to this issue
 */
@property (readonly, copy) NSString    *name;

/*!
 @property   date
 @abstract   The date of this issue
 */
@property (readonly, copy) NSDate  *date;

/*!
 @method     addAssetWithRequest:
 @abstract   Add a downloading asset to this issue. Initiate the download for this
 asset with the downloadWithDelegate: method on the NKAssetDownload.
 */
- (NKAssetDownload *)addAssetWithRequest:(NSURLRequest *)request;

@end
NS_ASSUME_NONNULL_END
