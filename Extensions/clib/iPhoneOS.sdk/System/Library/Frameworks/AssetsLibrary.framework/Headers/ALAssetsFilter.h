//
//  ALAssetsFilter.h
//  AssetsLibrary
//
//  Copyright 2010 Apple Inc. All rights reserved.
//
/*
 *
 * This class encapsulates filtering criteria to be used when retrieving assets from a group.
 *
 */

#import <Foundation/Foundation.h>

#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

NS_CLASS_DEPRECATED_IOS(4_0, 9_0, "Use fetchAssetsInAssetCollection:options: on PHAsset and set a mediaType predicate on the PHFetchOptions from the Photos framework instead")
@interface ALAssetsFilter : NSObject {
@package
    id _internal;
}

// Get all photos assets in the assets group.
+ (ALAssetsFilter *)allPhotos;
// Get all video assets in the assets group.
+ (ALAssetsFilter *)allVideos;
// Get all assets in the group.
+ (ALAssetsFilter *)allAssets;

@end

#endif
