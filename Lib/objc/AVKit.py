"""
Classes from the 'AVKit' framework.
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


AVLayoutViewRowHead = _Class("AVLayoutViewRowHead")
_AVBundle = _Class("_AVBundle")
AVAirMessageResponse = _Class("AVAirMessageResponse")
AVDisplayLink = _Class("AVDisplayLink")
AVLayoutItemAttributes = _Class("AVLayoutItemAttributes")
AVInternetDateFormatter = _Class("AVInternetDateFormatter")
AVTransitionController = _Class("AVTransitionController")
AVPlaybackControlsController = _Class("AVPlaybackControlsController")
AVPresentationContextTransition = _Class("AVPresentationContextTransition")
AVBehaviorStorage = _Class("AVBehaviorStorage")
AVDefaultBehaviorContext = _Class("AVDefaultBehaviorContext")
AVAirMessageParts = _Class("AVAirMessageParts")
AVMessageParser = _Class("AVMessageParser")
AVPresentationContainerViewAppearanceProxy = _Class(
    "AVPresentationContainerViewAppearanceProxy"
)
AVPlayerVolumeController = _Class("AVPlayerVolumeController")
AVSecondScreenConnection = _Class("AVSecondScreenConnection")
AVSecondScreenContentViewConnection = _Class("AVSecondScreenContentViewConnection")
AVTimer = _Class("AVTimer")
AVPlayerViewControllerAnimationCoordinator = _Class(
    "AVPlayerViewControllerAnimationCoordinator"
)
AVMicaPackage = _Class("AVMicaPackage")
AVCustomStackLayout = _Class("AVCustomStackLayout")
AVTransition = _Class("AVTransition")
AVNewsWidgetPlayerBehaviorContext = _Class("AVNewsWidgetPlayerBehaviorContext")
AVZoomingBehaviorContext = _Class("AVZoomingBehaviorContext")
AVPrioritizedSize = _Class("AVPrioritizedSize")
AVPlayerControllerTimeResolver = _Class("AVPlayerControllerTimeResolver")
AVTimecodeController = _Class("AVTimecodeController")
AVTimecode = _Class("AVTimecode")
AVExternalPlaybackController = _Class("AVExternalPlaybackController")
AVControlItem = _Class("AVControlItem")
AVHomeLoadingButtonControlItem = _Class("AVHomeLoadingButtonControlItem")
AVPictureInPictureControllerContentSource = _Class(
    "AVPictureInPictureControllerContentSource"
)
AVDataValueTransformer = _Class("AVDataValueTransformer")
AVAirMessageTransformer = _Class("AVAirMessageTransformer")
AVHomeIPCameraBehaviorContext = _Class("AVHomeIPCameraBehaviorContext")
AVKeyValueChange = _Class("AVKeyValueChange")
AVProxyKVOObserver = _Class("AVProxyKVOObserver")
AVObservationController = _Class("AVObservationController")
AVSecondScreenDebugAssistant = _Class("AVSecondScreenDebugAssistant")
AVValueTiming = _Class("AVValueTiming")
AVConcreteValueTiming = _Class("AVConcreteValueTiming")
AVMutableValueTiming = _Class("AVMutableValueTiming")
AVConcreteMutableValueTiming = _Class("AVConcreteMutableValueTiming")
AVAirMessage = _Class("AVAirMessage")
AVEditBehaviorContext = _Class("AVEditBehaviorContext")
AVEditBehavior = _Class("AVEditBehavior")
AVStyleSheet = _Class("AVStyleSheet")
AVPictureInPicturePlaybackState = _Class("AVPictureInPicturePlaybackState")
AVZoomingBehavior = _Class("AVZoomingBehavior")
AVSystemVolumeController = _Class("AVSystemVolumeController")
AVVolumeHUDAssertion = _Class("AVVolumeHUDAssertion")
AVAirMessageDispatcher = _Class("AVAirMessageDispatcher")
AVAirTransport = _Class("AVAirTransport")
AVAirTransportStreams = _Class("AVAirTransportStreams")
AVStringPair = _Class("AVStringPair")
AVSecondScreen = _Class("AVSecondScreen")
AVMusicAppBehaviorContext = _Class("AVMusicAppBehaviorContext")
AVMusicAppBehavior = _Class("AVMusicAppBehavior")
AVNowPlayingInfoController = _Class("AVNowPlayingInfoController")
AVBonjourServiceClient = _Class("AVBonjourServiceClient")
AVPresentationContext = _Class("AVPresentationContext")
AVSecondScreenController = _Class("AVSecondScreenController")
AVInteractiveTransitionGestureTracker = _Class("AVInteractiveTransitionGestureTracker")
AVHomeIPCameraBehavior = _Class("AVHomeIPCameraBehavior")
AVPlayerControllerVolumeAnimator = _Class("AVPlayerControllerVolumeAnimator")
AVNewsWidgetPlayerBehavior = _Class("AVNewsWidgetPlayerBehavior")
AVNewsWidgetPlayerLegacyBehavior = _Class("AVNewsWidgetPlayerLegacyBehavior")
AVScrollViewObserver = _Class("AVScrollViewObserver")
AVPlayerItemAVKitData = _Class("AVPlayerItemAVKitData")
AVChapter = _Class("AVChapter")
AVAirMessageNotificationCenter = _Class("AVAirMessageNotificationCenter")
AVScrubberVelocity = _Class("AVScrubberVelocity")
AVPictureInPicturePrerollAttributes = _Class("AVPictureInPicturePrerollAttributes")
AVRouteDetectorCoordinator = _Class("AVRouteDetectorCoordinator")
AVPictureInPicturePlatformAdapter = _Class("AVPictureInPicturePlatformAdapter")
AVPictureInPictureController = _Class("AVPictureInPictureController")
AVPresentationController = _Class("AVPresentationController")
AVExternalGestureRecognizerPreventer = _Class("AVExternalGestureRecognizerPreventer")
AVUserInteractionObserverGestureRecognizer = _Class(
    "AVUserInteractionObserverGestureRecognizer"
)
AVImage = _Class("AVImage")
AVPresentationContainerViewLayer = _Class("AVPresentationContainerViewLayer")
AVPictureInPictureIndicatorSublayer = _Class("AVPictureInPictureIndicatorSublayer")
AVPictureInPictureIndicatorLayer = _Class("AVPictureInPictureIndicatorLayer")
AVCABackdropLayer = _Class("AVCABackdropLayer")
AVPlayerController = _Class("AVPlayerController")
AVSampleBufferDisplayLayerPlayerController = _Class(
    "AVSampleBufferDisplayLayerPlayerController"
)
AVHomeIPCameraPlayerController = _Class("AVHomeIPCameraPlayerController")
AVPictureInPictureIndicatorView = _Class("AVPictureInPictureIndicatorView")
AVPlaybackControlsView = _Class("AVPlaybackControlsView")
AVPlayerViewControllerContentView = _Class("AVPlayerViewControllerContentView")
AVSecondScreenPlayerLayerView = _Class("AVSecondScreenPlayerLayerView")
AVTurboModePlaybackControlsPlaceholderView = _Class(
    "AVTurboModePlaybackControlsPlaceholderView"
)
AVBackgroundView = _Class("AVBackgroundView")
AVCABackdropLayerView = _Class("AVCABackdropLayerView")
AVPresentationContainerView = _Class("AVPresentationContainerView")
AVPlayerView = _Class("AVPlayerView")
AVLabel = _Class("AVLabel")
AVEditView = _Class("AVEditView")
AVPlaybackContentContainerView = _Class("AVPlaybackContentContainerView")
AVExternalPlaybackIndicatorView = _Class("AVExternalPlaybackIndicatorView")
AVRoutePickerView = _Class("AVRoutePickerView")
AVPlaybackControlsRoutePickerView = _Class("AVPlaybackControlsRoutePickerView")
AVPlayerViewControllerCustomControlsView = _Class(
    "AVPlayerViewControllerCustomControlsView"
)
AVPlayerViewControllerCustomControlsViewLayoutMarginsGuideProvidingView = _Class(
    "AVPlayerViewControllerCustomControlsViewLayoutMarginsGuideProvidingView"
)
AVLoadingButtonView = _Class("AVLoadingButtonView")
AVStatusBarBackgroundGradientViewSubview = _Class(
    "AVStatusBarBackgroundGradientViewSubview"
)
AVStatusBarBackgroundGradientView = _Class("AVStatusBarBackgroundGradientView")
AVPictureInPictureSampleBufferDisplayLayerHostView = _Class(
    "AVPictureInPictureSampleBufferDisplayLayerHostView"
)
AVPictureInPictureCALayerHostView = _Class("AVPictureInPictureCALayerHostView")
AVVolumeWarningView = _Class("AVVolumeWarningView")
__AVPlayerLayerView = _Class("__AVPlayerLayerView")
_AVSimplePlayerLayerView = _Class("_AVSimplePlayerLayerView")
AVPictureInPicturePlayerLayerView = _Class("AVPictureInPicturePlayerLayerView")
AVPictureInPictureSampleBufferDisplayLayerView = _Class(
    "AVPictureInPictureSampleBufferDisplayLayerView"
)
AVTouchIgnoringView = _Class("AVTouchIgnoringView")
AVContentOverlayView = _Class("AVContentOverlayView")
AVAppStorePlayerLayerView = _Class("AVAppStorePlayerLayerView")
AVAppStorePlayerView = _Class("AVAppStorePlayerView")
AVView = _Class("AVView")
AVLayoutView = _Class("AVLayoutView")
AVBackdropView = _Class("AVBackdropView")
AVTransportControlsView = _Class("AVTransportControlsView")
AVPlaybackContentTransitioningView = _Class("AVPlaybackContentTransitioningView")
AVPlaybackContentZoomingView = _Class("AVPlaybackContentZoomingView")
AVTableViewCell = _Class("AVTableViewCell")
AVVolumeButtonControl = _Class("AVVolumeButtonControl")
AVVolumeSlider = _Class("AVVolumeSlider")
AVScrubber = _Class("AVScrubber")
AVButton = _Class("AVButton")
AVSecondScreenViewController = _Class("AVSecondScreenViewController")
AVPictureInPictureViewController = _Class("AVPictureInPictureViewController")
AVFullScreenViewController = _Class("AVFullScreenViewController")
AVPlayerViewController = _Class("AVPlayerViewController")
AVMediaSelectionTableViewController = _Class("AVMediaSelectionTableViewController")
AVMediaSelectionViewController = _Class("AVMediaSelectionViewController")
