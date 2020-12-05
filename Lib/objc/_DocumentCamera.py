"""
Classes from the 'DocumentCamera' framework.
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


ICDocCamScanCache = _Class("ICDocCamScanCache")
ICDocCamScanCacheItem = _Class("ICDocCamScanCacheItem")
ICDocCamRenamePrompt = _Class("ICDocCamRenamePrompt")
ICDocCamRectangleResultsQueue = _Class("ICDocCamRectangleResultsQueue")
DCPDFGenerator = _Class("DCPDFGenerator")
ICDocCamRetakeTransitionAnimator = _Class("ICDocCamRetakeTransitionAnimator")
ICDocCamUtilities = _Class("ICDocCamUtilities")
ICDocCamThumbnailZoomTransitionAnimator = _Class(
    "ICDocCamThumbnailZoomTransitionAnimator"
)
DCLocalization = _Class("DCLocalization")
ZhangHeFilter = _Class("ZhangHeFilter")
DCNotesSPI = _Class("DCNotesSPI")
ICDocCamDebugMovieController = _Class("ICDocCamDebugMovieController")
DCMarkupUtilities = _Class("DCMarkupUtilities")
ICDocCamProcessingBlocker = _Class("ICDocCamProcessingBlocker")
ICDocCamImageCache = _Class("ICDocCamImageCache")
ICDocCamDocumentInfoCollection = _Class("ICDocCamDocumentInfoCollection")
ICDocCamDocumentInfo = _Class("ICDocCamDocumentInfo")
DCAccessibility = _Class("DCAccessibility")
DCColorDummyClass = _Class("DCColorDummyClass")
ICDocCamViewControllerMeshTransform = _Class("ICDocCamViewControllerMeshTransform")
VNDocumentCameraScan = _Class("VNDocumentCameraScan")
DCLRUCache = _Class("DCLRUCache")
DCAtomicLRUCache = _Class("DCAtomicLRUCache")
DCCachesDirectory = _Class("DCCachesDirectory")
DCActivityItemSource = _Class("DCActivityItemSource")
DCDocumentInfoCollectionActivityItemSource = _Class(
    "DCDocumentInfoCollectionActivityItemSource"
)
DCMarkupActivityItem = _Class("DCMarkupActivityItem")
DCDispatchAfterHandler = _Class("DCDispatchAfterHandler")
DCDispatchAfterBlocks = _Class("DCDispatchAfterBlocks")
ICDocCamCVPixelBufferUtilities = _Class("ICDocCamCVPixelBufferUtilities")
DCScannedDocument = _Class("DCScannedDocument")
ICDocCamImageQuad = _Class("ICDocCamImageQuad")
ICDocCamImageFilters = _Class("ICDocCamImageFilters")
ICDocCamSpinner = _Class("ICDocCamSpinner")
DCLongRunningTaskController = _Class("DCLongRunningTaskController")
DCDocumentCameraViewServiceSessionRequest = _Class(
    "DCDocumentCameraViewServiceSessionRequest"
)
DCUtilities = _Class("DCUtilities")
DCDocumentCameraViewServiceSession = _Class("DCDocumentCameraViewServiceSession")
ICDocCamPhotoCaptureDelegate = _Class("ICDocCamPhotoCaptureDelegate")
DCSandboxExtension = _Class("DCSandboxExtension")
DCMarkupPresenter = _Class("DCMarkupPresenter")
ICDocCamImageSequenceAnalyzer = _Class("ICDocCamImageSequenceAnalyzer")
ICDocCamImageSequenceFrame = _Class("ICDocCamImageSequenceFrame")
ICDocCamPhysicalCaptureNotifier = _Class("ICDocCamPhysicalCaptureNotifier")
DCDocCamPDFGenerator = _Class("DCDocCamPDFGenerator")
ICDocCamRecropTransitionAnimator = _Class("ICDocCamRecropTransitionAnimator")
DCSelectorDelayer = _Class("DCSelectorDelayer")
DCSettings = _Class("DCSettings")
WhiteboardFilter = _Class("WhiteboardFilter")
ICDocCamThumbnailViewLayoutAttributes = _Class("ICDocCamThumbnailViewLayoutAttributes")
ICDocCamThumbnailCollectionViewLayout = _Class("ICDocCamThumbnailCollectionViewLayout")
ICDocCamReorderingThumbnailCollectionViewLayout = _Class(
    "ICDocCamReorderingThumbnailCollectionViewLayout"
)
DCMarkupActivity = _Class("DCMarkupActivity")
ICDocCamPhysicalCaptureRecognizer = _Class("ICDocCamPhysicalCaptureRecognizer")
ICDocCamImageQuadEditPanGestureRecognizer = _Class(
    "ICDocCamImageQuadEditPanGestureRecognizer"
)
ICDocCamImageQuadEditKnobAccessibilityElement = _Class(
    "ICDocCamImageQuadEditKnobAccessibilityElement"
)
ICDocCamImageQuadEditOverlay = _Class("ICDocCamImageQuadEditOverlay")
ICDocCamThumbnailContainerView = _Class("ICDocCamThumbnailContainerView")
ICDocCamImageQuadEditImageView = _Class("ICDocCamImageQuadEditImageView")
DCCircularProgressView = _Class("DCCircularProgressView")
ICDocCamOverlayView = _Class("ICDocCamOverlayView")
ICDocCamExtractedThumbnailContainerView = _Class(
    "ICDocCamExtractedThumbnailContainerView"
)
DCNotesTextureBackgroundView = _Class("DCNotesTextureBackgroundView")
DCNotesTextureView = _Class("DCNotesTextureView")
ICDocCamFilterViewControllerInvisibleRootView = _Class(
    "ICDocCamFilterViewControllerInvisibleRootView"
)
ICDocCamPreviewView = _Class("ICDocCamPreviewView")
DCSinglePixelLineView = _Class("DCSinglePixelLineView")
DCSinglePixelVerticalLineView = _Class("DCSinglePixelVerticalLineView")
DCSinglePixelHorizontalLineView = _Class("DCSinglePixelHorizontalLineView")
ICDocCamThumbnailDecorationView = _Class("ICDocCamThumbnailDecorationView")
ICDocCamExtractedDocumentThumbnailCell = _Class(
    "ICDocCamExtractedDocumentThumbnailCell"
)
ICDocCamThumbnailCell = _Class("ICDocCamThumbnailCell")
ICDocCamZoomablePageContentImageView = _Class("ICDocCamZoomablePageContentImageView")
ICDocCamSaveButton = _Class("ICDocCamSaveButton")
ICDocCamFilterButton = _Class("ICDocCamFilterButton")
ICDocCamShutterButton = _Class("ICDocCamShutterButton")
DCProgressViewController = _Class("DCProgressViewController")
ICDocCamNonRotatableViewController = _Class("ICDocCamNonRotatableViewController")
ICDocCamViewController = _Class("ICDocCamViewController")
DCDocumentCameraViewController = _Class("DCDocumentCameraViewController")
DCDocumentCameraViewController_ViewService = _Class(
    "DCDocumentCameraViewController_ViewService"
)
DCDocumentCameraViewController_InProcess = _Class(
    "DCDocumentCameraViewController_InProcess"
)
ICDocCamImageQuadEditViewController = _Class("ICDocCamImageQuadEditViewController")
ICDocCamFilterViewController = _Class("ICDocCamFilterViewController")
VNDocumentCameraViewController = _Class("VNDocumentCameraViewController")
VNDocumentCameraViewController_InProcess = _Class(
    "VNDocumentCameraViewController_InProcess"
)
VNDocumentCameraViewController_ViewService = _Class(
    "VNDocumentCameraViewController_ViewService"
)
ICDocCamZoomablePageContentViewController = _Class(
    "ICDocCamZoomablePageContentViewController"
)
ICDocCamPageContentViewController = _Class("ICDocCamPageContentViewController")
ICDocCamExtractedDocumentViewController = _Class(
    "ICDocCamExtractedDocumentViewController"
)
DCActivityViewController = _Class("DCActivityViewController")
DCDocumentCameraRemoteViewController = _Class("DCDocumentCameraRemoteViewController")
ICDocCamThumbnailCollectionViewController = _Class(
    "ICDocCamThumbnailCollectionViewController"
)
ICDocCamNavigationController = _Class("ICDocCamNavigationController")
DCDocumentEditorViewController = _Class("DCDocumentEditorViewController")
ICDocCamExtractedDocumentNavigationController = _Class(
    "ICDocCamExtractedDocumentNavigationController"
)
