//
//  NKNSURLConnectionAdditions.h
//  NewsstandKit
//
//  Copyright 2011 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NKAssetDownload;


/*!
 @category   NKAssetDownloadAdditions(NSURLConnection)
 @abstract   NKAssetDownload extensions to NSURLConnection.
 @discussion This category provides a convenient way to look up an
 NKAssetDownload that is related to a NSURLConnection.
 */

@interface NSURLConnection (NKAssetDownloadAdditions)

/*!
 @property   newsstandAssetDownload
 @abstract   A pointer to the asset download that this connection is associated with.
 */
@property (readonly, weak, nullable) NKAssetDownload *newsstandAssetDownload NS_DEPRECATED_IOS(5.0, 13.0, "Use Remote notifications Background Modes instead: https://developer.apple.com/documentation/usernotifications/setting_up_a_remote_notification_server/pushing_updates_to_your_app_silently");

@end
