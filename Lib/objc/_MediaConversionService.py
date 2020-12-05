"""
Classes from the 'MediaConversionService' framework.
"""

try:
    from rubicon.objc import ObjCClass
except ValueError:

    def ObjCClass(name):
        return None


def _Class(name):
    try:
        return ObjCClass(name)
    except NameError:
        return None


PAMediaConversionServiceImagingUtilities = _Class(
    "PAMediaConversionServiceImagingUtilities"
)
PHMediaFormatConversionSinglePassVideoProgressObserver = _Class(
    "PHMediaFormatConversionSinglePassVideoProgressObserver"
)
PHMediaFormatConversionImplementation_MediaConversionService = _Class(
    "PHMediaFormatConversionImplementation_MediaConversionService"
)
PAMediaConversionServiceImageMetadataPolicy = _Class(
    "PAMediaConversionServiceImageMetadataPolicy"
)
PAMediaConversionServiceSetAccessibilityDescriptionImageMetadataPolicy = _Class(
    "PAMediaConversionServiceSetAccessibilityDescriptionImageMetadataPolicy"
)
PAMediaConversionServiceSetCaptionImageMetadataPolicy = _Class(
    "PAMediaConversionServiceSetCaptionImageMetadataPolicy"
)
PAMediaConversionServiceSetCreationDateImageMetadataPolicy = _Class(
    "PAMediaConversionServiceSetCreationDateImageMetadataPolicy"
)
PAMediaConversionServiceSetLocationImageMetadataPolicy = _Class(
    "PAMediaConversionServiceSetLocationImageMetadataPolicy"
)
PAMediaConversionServiceAddPFMediaMetadataPolicy = _Class(
    "PAMediaConversionServiceAddPFMediaMetadataPolicy"
)
PAMediaConversionServiceCompositeImageMetadataPolicy = _Class(
    "PAMediaConversionServiceCompositeImageMetadataPolicy"
)
PAMediaConversionServiceDefaultImageMetadataPolicy = _Class(
    "PAMediaConversionServiceDefaultImageMetadataPolicy"
)
PAMediaConversionServiceiCloudPhotoLibraryImageMetadataPolicy = _Class(
    "PAMediaConversionServiceiCloudPhotoLibraryImageMetadataPolicy"
)
PAMediaConversionServiceSharedPhotoStreamImageMetadataPolicy = _Class(
    "PAMediaConversionServiceSharedPhotoStreamImageMetadataPolicy"
)
PHMediaFormatConversionManager = _Class("PHMediaFormatConversionManager")
PHMediaFormatConversionJob = _Class("PHMediaFormatConversionJob")
PHMediaFormatConversionRequest = _Class("PHMediaFormatConversionRequest")
PHMediaFormatConversionCompositeRequest = _Class(
    "PHMediaFormatConversionCompositeRequest"
)
PHMediaFormatChainedConversionRequest = _Class("PHMediaFormatChainedConversionRequest")
PHMediaFormatAssetBundleConversionRequest = _Class(
    "PHMediaFormatAssetBundleConversionRequest"
)
PHMediaFormatLivePhotoBundleConversionRequest = _Class(
    "PHMediaFormatLivePhotoBundleConversionRequest"
)
PHMediaFormatLivePhotoConversionRequest = _Class(
    "PHMediaFormatLivePhotoConversionRequest"
)
PHMediaFormatConversionContent = _Class("PHMediaFormatConversionContent")
PHMediaFormatConversionDestination = _Class("PHMediaFormatConversionDestination")
PHMediaFormatConversionSource = _Class("PHMediaFormatConversionSource")
PHMediaFormatConversionAssetBundleSource = _Class(
    "PHMediaFormatConversionAssetBundleSource"
)
PHMediaFormatConversionLivePhotoBundleSource = _Class(
    "PHMediaFormatConversionLivePhotoBundleSource"
)
PHMediaFormatConversionPlaceholderSource = _Class(
    "PHMediaFormatConversionPlaceholderSource"
)
PAMediaConversionServiceResourceURLCollection = _Class(
    "PAMediaConversionServiceResourceURLCollection"
)
PAMediaConversionServiceResourceURLReference = _Class(
    "PAMediaConversionServiceResourceURLReference"
)
PAImageConversionServiceClient = _Class("PAImageConversionServiceClient")
PAVideoConversionServiceClient = _Class("PAVideoConversionServiceClient")
