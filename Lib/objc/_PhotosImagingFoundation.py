"""
Classes from the 'PhotosImagingFoundation' framework.
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


IPAImageTransformSequence = _Class("IPAImageTransformSequence")
IPAAdjustmentEnvelope = _Class("IPAAdjustmentEnvelope")
IPAAutoRegistry = _Class("IPAAutoRegistry")
IPAAutoRegistryEntry = _Class("IPAAutoRegistryEntry")
IPAPreviewSizePolicy = _Class("IPAPreviewSizePolicy")
IPAImageGeometry = _Class("IPAImageGeometry")
IPARegion = _Class("IPARegion")
IPAMutableRegion = _Class("IPAMutableRegion")
IPAEditOperation = _Class("IPAEditOperation")
IPAVideoOperation = _Class("IPAVideoOperation")
IPASloMoOperation = _Class("IPASloMoOperation")
IPATrimOperation = _Class("IPATrimOperation")
IPAPosterFrameOperation = _Class("IPAPosterFrameOperation")
IPAImageSizePolicy = _Class("IPAImageSizePolicy")
IPAAggregateLargestImageSizePolicy = _Class("IPAAggregateLargestImageSizePolicy")
IPABestFitShortSideWithLongSideLimit = _Class("IPABestFitShortSideWithLongSideLimit")
IPABestFitTotalPixelCountImageSizePolicy = _Class(
    "IPABestFitTotalPixelCountImageSizePolicy"
)
IPABestFitEvenWidthTotalPixelCountImageSizePolicy = _Class(
    "IPABestFitEvenWidthTotalPixelCountImageSizePolicy"
)
IPABestFitEvenTotalPixelCountImageSizePolicy = _Class(
    "IPABestFitEvenTotalPixelCountImageSizePolicy"
)
IPAShortestEdgeImageSizePolicy = _Class("IPAShortestEdgeImageSizePolicy")
IPABestFitImageHeightPolicy = _Class("IPABestFitImageHeightPolicy")
IPABestFitImageWidthPolicy = _Class("IPABestFitImageWidthPolicy")
IPABestFitImageSizePolicy = _Class("IPABestFitImageSizePolicy")
IPAScaleImageSizePolicy = _Class("IPAScaleImageSizePolicy")
IPAOriginalSizePolicy = _Class("IPAOriginalSizePolicy")
IPAAdjustmentStackSerializer = _Class("IPAAdjustmentStackSerializer")
IPAVideoAdjustmentStackSerializer = _Class("IPAVideoAdjustmentStackSerializer")
IPAVideoAdjustmentStackSerializer_SLM_v10 = _Class(
    "IPAVideoAdjustmentStackSerializer_SLM_v10"
)
IPAVideoAdjustmentStackSerializer_SLM_v11 = _Class(
    "IPAVideoAdjustmentStackSerializer_SLM_v11"
)
IPAVideoAdjustmentStackSerializer_v10 = _Class("IPAVideoAdjustmentStackSerializer_v10")
IPAPhotoAdjustmentStackSerializer = _Class("IPAPhotoAdjustmentStackSerializer")
IPAPhotoAdjustmentStackSerializer_SLM_v11 = _Class(
    "IPAPhotoAdjustmentStackSerializer_SLM_v11"
)
IPAPhotoAdjustmentStackSerializer_v10 = _Class("IPAPhotoAdjustmentStackSerializer_v10")
IPASerializationManager = _Class("IPASerializationManager")
IPAAdjustmentSerialization = _Class("IPAAdjustmentSerialization")
IPARectArray = _Class("IPARectArray")
IPAMutableRectArray = _Class("IPAMutableRectArray")
IPAImageTransform = _Class("IPAImageTransform")
IPAImageIdentityTransform = _Class("IPAImageIdentityTransform")
IPAPerspectiveTransform = _Class("IPAPerspectiveTransform")
IPAAffineImageTransform = _Class("IPAAffineImageTransform")
IPAPreviewSizeRegistry = _Class("IPAPreviewSizeRegistry")
IPALocalPreviewSizeRegistry = _Class("IPALocalPreviewSizeRegistry")
IPAMetadata = _Class("IPAMetadata")
IPAAdjustment = _Class("IPAAdjustment")
IPAPhotoAdjustment = _Class("IPAPhotoAdjustment")
IPAVideoAdjustment = _Class("IPAVideoAdjustment")
IPAAdjustmentStack = _Class("IPAAdjustmentStack")
IPAPhotoAdjustmentStack = _Class("IPAPhotoAdjustmentStack")
IPAVideoAdjustmentStack = _Class("IPAVideoAdjustmentStack")
IPAEditDescription = _Class("IPAEditDescription")
IPAVideoPlaybackSettings = _Class("IPAVideoPlaybackSettings")
IPAAdjustmentVersionInfo = _Class("IPAAdjustmentVersionInfo")
IPAPhotoAdjustmentPipeline = _Class("IPAPhotoAdjustmentPipeline")
IPAAdjustmentVersion = _Class("IPAAdjustmentVersion")
IPAAutoSettings = _Class("IPAAutoSettings")
IPARemoveAutoSettings = _Class("IPARemoveAutoSettings")
IPAManualAutoSettings = _Class("IPAManualAutoSettings")
IPAPendingAutoSettings = _Class("IPAPendingAutoSettings")
IPAGeometryOperator = _Class("IPAGeometryOperator")
IPAPerspectiveOperator = _Class("IPAPerspectiveOperator")
IPAGeometryOperatorSequence = _Class("IPAGeometryOperatorSequence")
IPAIdentityOperator = _Class("IPAIdentityOperator")
IPACropOperator = _Class("IPACropOperator")
IPAStraightenOperator = _Class("IPAStraightenOperator")
IPAScaleOperator = _Class("IPAScaleOperator")
IPAOrientationOperator = _Class("IPAOrientationOperator")
