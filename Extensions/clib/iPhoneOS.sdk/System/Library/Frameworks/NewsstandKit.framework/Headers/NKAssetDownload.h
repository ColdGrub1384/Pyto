//
//  NKAssetDownload.h
//  NewsstandKit
//
//  Copyright 2011 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NKIssue;


/*!
 @class      NKAssetDownload
 @abstract   Represents a downloading asset for an issue.
 @discussion An NKIssue may have one or more assets that together form the structure
 of the Newsstand issue. You generate a downloading asset by constructing
 an NSURLRequest adding the request to the NKIssue using
 -[NKIssue addAssetWithRequest:]. Begin downloading the asset by calling
 -[NKAssetDownload downloadWithDelegate:].
 Upon download completion, you will need to put your uncompressed content
 in the URL specified by -[NKIssue contentURL].
 */
NS_ASSUME_NONNULL_BEGIN
NS_CLASS_DEPRECATED_IOS(5.0, 13.0, "Use the Remote Notifications Background Modes instead: https://developer.apple.com/documentation/usernotifications/setting_up_a_remote_notification_server/pushing_updates_to_your_app_silently")
@interface NKAssetDownload : NSObject

/*!
 @property   issue
 @abstract   A pointer to the issue that this asset is associated with.
 */
@property (readonly, weak, nullable) NKIssue *issue; // back-pointer to the issue this asset is associated with

/*!
 @property   identifier
 @abstract   A unique identifier representing the asset.
 */
@property (readonly, copy) NSString *identifier;

/*!
 @property   userInfo
 @abstract   Application specific information that is saved with the asset. Can be nil.
 @discussion You may add arbitrary key-value pairs to this dictionary. However, the keys
 and values must be valid property-list types; if any are not, an exception is raised.
 Using this property you can save download related information such as file name/paths,
 encoding mechanisms, custom identifiers, etc.  However, performance concerns dictate
 that you should make this content as minimal as possible.
 */
@property (copy, nullable) NSDictionary *userInfo;

/*!
 @property   URLRequest
 @abstract   The NSURLRequest of the download
 */
@property (readonly, copy) NSURLRequest *URLRequest;

/*!
 @method     downloadWithDelegate:
 @abstract   Begins downloading the asset with the specified delegate. Delegate
 may not be nil.
 */
- (NSURLConnection *)downloadWithDelegate:(id <NSURLConnectionDownloadDelegate>)delegate;

@end
NS_ASSUME_NONNULL_END
