'''
Classes from the 'PhotosFormats' framework.
'''

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

    
PFAssetBundle = _Class('PFAssetBundle')
PFVideoExport = _Class('PFVideoExport')
PFSinglePassVideoExportItem = _Class('PFSinglePassVideoExportItem')
PFVideoExportRangeCoordinator = _Class('PFVideoExportRangeCoordinator')
PFVideoExportRangeWaitingCaller = _Class('PFVideoExportRangeWaitingCaller')
PFProportionalIntegralController = _Class('PFProportionalIntegralController')
PFSinglePassVideoExportItemStatistics = _Class('PFSinglePassVideoExportItemStatistics')
PFTimeZoneLookup = _Class('PFTimeZoneLookup')
PFVideoEncoding = _Class('PFVideoEncoding')
PFVideoComplement = _Class('PFVideoComplement')
PFVideoAVObjectBuilder = _Class('PFVideoAVObjectBuilder')
PFSlowMotionUtilities = _Class('PFSlowMotionUtilities')
PFSlowMotionTimeRangeMapper = _Class('PFSlowMotionTimeRangeMapper')
PFSlowMotionTimeRangeMapperScaledRegion = _Class('PFSlowMotionTimeRangeMapperScaledRegion')
PFSlowMotionRampConfiguration = _Class('PFSlowMotionRampConfiguration')
PFSlowMotionConfiguration = _Class('PFSlowMotionConfiguration')
PFCameraMetadataSerialization = _Class('PFCameraMetadataSerialization')
PFCameraMetadata = _Class('PFCameraMetadata')
_PFCameraMetadataAVMetadataObject = _Class('_PFCameraMetadataAVMetadataObject')
PFCameraMetadataJSONDebugSerialization = _Class('PFCameraMetadataJSONDebugSerialization')
PFSharingUtilities = _Class('PFSharingUtilities')
PFMetadataBuilder = _Class('PFMetadataBuilder')
PFXMPMetadataBuilder = _Class('PFXMPMetadataBuilder')
PFVideoMetadataBuilder = _Class('PFVideoMetadataBuilder')
PFImageMetadataBuilder = _Class('PFImageMetadataBuilder')
PFSharingRemaker = _Class('PFSharingRemaker')
PFSharingRemakerOperation = _Class('PFSharingRemakerOperation')
PFSharingRemakerOptions = _Class('PFSharingRemakerOptions')
PFFrameCache = _Class('PFFrameCache')
PFPhotosFaceUtilities = _Class('PFPhotosFaceUtilities')
PFLivePhotoPlaybackResult = _Class('PFLivePhotoPlaybackResult')
PFLivePhotoEditSession = _Class('PFLivePhotoEditSession')
PFLivePhotoPlaybackSettings = _Class('PFLivePhotoPlaybackSettings')
PFLivePhotoExportDestination = _Class('PFLivePhotoExportDestination')
PFLivePhotoFrameProcessingRequest = _Class('PFLivePhotoFrameProcessingRequest')
PFMediaUtilities = _Class('PFMediaUtilities')
PFImageMetadata = _Class('PFImageMetadata')
PFVideoMetadata = _Class('PFVideoMetadata')
PFMediaCapabilities = _Class('PFMediaCapabilities')
PFMediaCapabilitiesQuery = _Class('PFMediaCapabilitiesQuery')
PFJSONDebugDumpConverter = _Class('PFJSONDebugDumpConverter')
PFExportGIFRequest = _Class('PFExportGIFRequest')
PFCropUtilities = _Class('PFCropUtilities')
PFColorConverter = _Class('PFColorConverter')
PFAnimatedImage = _Class('PFAnimatedImage')
PFCameraAdjustmentsSerialization = _Class('PFCameraAdjustmentsSerialization')
PFCameraAdjustments = _Class('PFCameraAdjustments')
PFMutableCameraAdjustments = _Class('PFMutableCameraAdjustments')
PFAVReaderWriter = _Class('PFAVReaderWriter')
PFRWSampleBufferChannel = _Class('PFRWSampleBufferChannel')
PFAssetAdjustmentFingerprintData = _Class('PFAssetAdjustmentFingerprintData')
PFAssetAdjustments = _Class('PFAssetAdjustments')
PFVideoAdjustments = _Class('PFVideoAdjustments')
PFVideoSharingOperation = _Class('PFVideoSharingOperation')
PFPhotoSharingOperation = _Class('PFPhotoSharingOperation')
