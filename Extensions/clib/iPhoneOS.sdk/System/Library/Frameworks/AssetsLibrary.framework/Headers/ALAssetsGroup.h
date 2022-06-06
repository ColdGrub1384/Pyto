//
//  ALAssetsGroup.h
//  AssetsLibrary
//
//  Copyright 2010 Apple Inc. All rights reserved.
//
/*
 *
 * An ALAssetsGroup is a ordered set of assets. The order of its elements is the order that the user sees in the Photos application. 
 * Groups are synced via iTunes, created on the device, created to hold the users saved photos, or created during camera import. 
 * Synced groups cannot be directly modified using this API. Only user-created groups and the saved photos group can have assets added.
 */

#import <Foundation/Foundation.h>

#import <CoreGraphics/CoreGraphics.h>

#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

@class ALAsset;
@class ALAssetsGroup;
@class ALAssetsFilter;

// This block is executed when a result is found. The result argument passed into the block is an ALAsset that
// matches the filter set by the caller.
// The index argument indicates which asset is being returned. In the case where no asset is found, index will be set to NSNotFound and stop to YES.
// When the enumeration is done, the block will be called with result set to nil and index set to NSNotFound.
// Setting the output argument stop to YES will finish the enumeration.
typedef void (^ALAssetsGroupEnumerationResultsBlock)(ALAsset *result, NSUInteger index, BOOL *stop) NS_DEPRECATED_IOS(4_0, 9_0, "Use the PHFetchResult returned by fetchAssetsInAssetCollection:options: on PHAsset from the Photos framework to enumerate the assets in an asset collection instead");

// Groups Properties
extern NSString *const ALAssetsGroupPropertyName NS_DEPRECATED_IOS(4_0, 9_0, "Use the localizedTitle property on a PHAssetCollection from the Photos framework instead");              // An NSString with the name of the group
extern NSString *const ALAssetsGroupPropertyType NS_DEPRECATED_IOS(4_0, 9_0, "Use the assetCollectionType and assetCollectionSubtype properties on a PHAssetCollection from the Photos framework instead");              // An ALAssetsGroupType wrapped in an NSNumber
extern NSString *const ALAssetsGroupPropertyPersistentID NS_DEPRECATED_IOS(4_0, 9_0, "Use the localIdentifier property on a PHAssetCollection from the Photos framework instead");      // An NSString with the group's persistent ID. 
extern NSString *const ALAssetsGroupPropertyURL NS_DEPRECATED_IOS(5_0, 9_0, "Use the localIdentifier property on a PHAssetCollection from the Photos framework, or to lookup PHAssetCollections by a previously known ALAssetsGroupPropertyURL use fetchAssetCollectionsWithALAssetGroupURLs:options: instead");              // An NSURL that uniquely identifies the group



NS_CLASS_DEPRECATED_IOS(4_0, 9_0, "Use PHAssetCollection from the Photos framework instead")
@interface ALAssetsGroup : NSObject {
@package
    id _internal;
}

// Use this method to get information about the group.
- (id)valueForProperty:(NSString *)property NS_DEPRECATED_IOS(4_0, 9_0, "Use the class properties on a PHAssetCollection in the Photos framework instead");

// Returns a CGImage of the poster photo for the group.  The thumbnail will be in the correct orientation.
- (CGImageRef)posterImage NS_DEPRECATED_IOS(4_0, 9_0, "Use fetchKeyAssetsInAssetCollection:options: on PHAsset, then use the PHImageManager to request image data for key assets in the asset collection from the Photos framework instead");

// Set the ALAssetsFilter on the group to filter the group contents. This does not execute the filter. 
// For that, -enumerateAssetsUsingBlock:doneBlock: or -numberOfAssets needs to be called. 
// If no filter is set, the enumeration will return all the assets in the group.
// Only one filter is active at a time. Calling this method again resets the filter and does not affect any enumeration that may be in flight.
- (void)setAssetsFilter:(ALAssetsFilter *)filter NS_DEPRECATED_IOS(4_0, 9_0, "Use fetchAssetsInAssetCollection:options: on PHAsset with a predicate in the PHFetchOptions from the Photos framework to filter the assets in an asset collection instead");

// Get the number of assets in the group that match the filter.
// If no filter is set, it returns the count of all assets in the group.
- (NSInteger)numberOfAssets NS_DEPRECATED_IOS(4_0, 9_0, "Use the estimatedAssetCount on PHAssetCollection for a quick estimate of the total assets in a collection (or fetch the assets to get an exact value) from the Photos framework instead");

// These methods are used to retrieve the assets that match the filter.  
// The caller can specify which results are returned using an NSIndexSet. The index set's count or lastIndex cannot exceed -numberOfAssets.
// 'enumerationBlock' is used to pass back results to the caller and provide the opportunity to stop the filter.
// When the enumeration is done, 'enumerationBlock' will be called with result set to nil and index set to NSNotFound.
// If the application has not been granted access to the data, 'enumerationBlock' will be called with result set to nil, index set to NSNotFound, and stop set to YES.
- (void)enumerateAssetsUsingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock NS_DEPRECATED_IOS(4_0, 9_0, "Use the PHFetchResult returned by fetchAssetsInAssetCollection:options: on PHAsset to enumerate the assets in an asset collection from the Photos framework instead");
- (void)enumerateAssetsWithOptions:(NSEnumerationOptions)options usingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock NS_DEPRECATED_IOS(4_0, 9_0, "Use the PHFetchResult returned by fetchAssetsInAssetCollection:options: on PHAsset to enumerate the assets in an asset collection from the Photos framework instead");
- (void)enumerateAssetsAtIndexes:(NSIndexSet *)indexSet options:(NSEnumerationOptions)options usingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock NS_DEPRECATED_IOS(4_0, 9_0, "Use the PHFetchResult returned by fetchAssetsInAssetCollection:options: on PHAsset to enumerate the assets in an asset collection from the Photos framework instead");

// Returns YES if the application is able to edit the group.  Returns NO if the application is not able to edit the group.
@property (nonatomic, readonly, getter=isEditable) BOOL editable NS_DEPRECATED_IOS(5_0, 9_0, "Use canPerformEditOperation: on a PHAssetCollection from the Photos framework instead");

// Add an existing ALAsset to the group.  An asset can belong to multiple ALAssetsGroups.
// The caller should check the editable property of the group to see if it is possible to add an asset to the group.
// Returns YES if the asset was added successfully.  Returns NO if the group is not editable, or if the asset was not able to be added to the group.
- (BOOL)addAsset:(ALAsset *)asset NS_DEPRECATED_IOS(5_0, 9_0, "Use addAssets: on a PHAssetCollectionChangeRequest: created from a PHAssetCollection in the Photos framework instead");

@end

#endif
