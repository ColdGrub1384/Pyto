"""
Classes from the 'WebCore' framework.
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


WebVideoFullscreenController = _Class("WebVideoFullscreenController")
WebUndefined = _Class("WebUndefined")
WebItemProviderPasteboard = _Class("WebItemProviderPasteboard")
WebItemProviderLoadResult = _Class("WebItemProviderLoadResult")
WebItemProviderRegistrationInfoList = _Class("WebItemProviderRegistrationInfoList")
WebItemProviderPromisedFileRegistrar = _Class("WebItemProviderPromisedFileRegistrar")
WebItemProviderWritableObjectRegistrar = _Class(
    "WebItemProviderWritableObjectRegistrar"
)
WebItemProviderDataRegistrar = _Class("WebItemProviderDataRegistrar")
WebCoreResourceHandleAsOperationQueueDelegate = _Class(
    "WebCoreResourceHandleAsOperationQueueDelegate"
)
WebCoreResourceHandleWithCredentialStorageAsOperationQueueDelegate = _Class(
    "WebCoreResourceHandleWithCredentialStorageAsOperationQueueDelegate"
)
WebCoreNSURLSessionDataTask = _Class("WebCoreNSURLSessionDataTask")
WebCoreNSURLSession = _Class("WebCoreNSURLSession")
WebCoreNSURLSessionTaskMetrics = _Class("WebCoreNSURLSessionTaskMetrics")
WebCoreNSURLSessionTaskTransactionMetrics = _Class(
    "WebCoreNSURLSessionTaskTransactionMetrics"
)
WebAVPlayerViewController = _Class("WebAVPlayerViewController")
WebAVPlayerViewControllerDelegate = _Class("WebAVPlayerViewControllerDelegate")
WebCoreRenderThemeBundle = _Class("WebCoreRenderThemeBundle")
WebCoreAuthenticationClientAsChallengeSender = _Class(
    "WebCoreAuthenticationClientAsChallengeSender"
)
WebCookieObserverAdapter = _Class("WebCookieObserverAdapter")
WebNSHTTPCookieStorageDummyForInternalAccess = _Class(
    "WebNSHTTPCookieStorageDummyForInternalAccess"
)
WebAVAssetWriterDelegate = _Class("WebAVAssetWriterDelegate")
WebDatabaseTransactionBackgroundTaskController = _Class(
    "WebDatabaseTransactionBackgroundTaskController"
)
WebCoreMotionManager = _Class("WebCoreMotionManager")
WebAVMediaSelectionOption = _Class("WebAVMediaSelectionOption")
WebAVPlayerController = _Class("WebAVPlayerController")
WebValidationBubbleDelegate = _Class("WebValidationBubbleDelegate")
WebValidationBubbleTapRecognizer = _Class("WebValidationBubbleTapRecognizer")
WebPreviewConverterDelegate = _Class("WebPreviewConverterDelegate")
LegacyTileCacheTombstone = _Class("LegacyTileCacheTombstone")
WebCoreBundleFinder = _Class("WebCoreBundleFinder")
WebDisplayLinkHandler = _Class("WebDisplayLinkHandler")
WebCoreTextTrackRepresentationCocoaHelper = _Class(
    "WebCoreTextTrackRepresentationCocoaHelper"
)
WebAnimationDelegate = _Class("WebAnimationDelegate")
WebCoreAudioBundleClass = _Class("WebCoreAudioBundleClass")
WebEventRegion = _Class("WebEventRegion")
WebArchiveResourceWebResourceHandler = _Class("WebArchiveResourceWebResourceHandler")
WebArchiveResourceFromNSAttributedString = _Class(
    "WebArchiveResourceFromNSAttributedString"
)
WebAccessibilityObjectWrapperBase = _Class("WebAccessibilityObjectWrapperBase")
WebAccessibilityObjectWrapper = _Class("WebAccessibilityObjectWrapper")
WebAccessibilityTextMarker = _Class("WebAccessibilityTextMarker")
WebAVSampleBufferErrorListener = _Class("WebAVSampleBufferErrorListener")
WebAVStreamDataParserListener = _Class("WebAVStreamDataParserListener")
WebSpeechSynthesisWrapper = _Class("WebSpeechSynthesisWrapper")
WebMediaSessionHelper = _Class("WebMediaSessionHelper")
WebRootSampleBufferBoundsChangeListener = _Class(
    "WebRootSampleBufferBoundsChangeListener"
)
WebCoreAVFPullDelegate = _Class("WebCoreAVFPullDelegate")
WebCoreAVFLoaderDelegate = _Class("WebCoreAVFLoaderDelegate")
WebCoreAVFMovieObserver = _Class("WebCoreAVFMovieObserver")
WebAVSampleBufferStatusChangeListener = _Class("WebAVSampleBufferStatusChangeListener")
WebCoreSharedBufferResourceLoaderDelegate = _Class(
    "WebCoreSharedBufferResourceLoaderDelegate"
)
WebCoreAudioCaptureSourceIOSListener = _Class("WebCoreAudioCaptureSourceIOSListener")
WebCDMSessionAVContentKeySessionDelegate = _Class(
    "WebCDMSessionAVContentKeySessionDelegate"
)
WebCoreFPSContentKeySessionDelegate = _Class("WebCoreFPSContentKeySessionDelegate")
WebCoreAVVideoCaptureSourceObserver = _Class("WebCoreAVVideoCaptureSourceObserver")
WebCoreAVCaptureDeviceManagerObserver = _Class("WebCoreAVCaptureDeviceManagerObserver")
WebAVAudioSessionAvailableInputsListener = _Class(
    "WebAVAudioSessionAvailableInputsListener"
)
WebActionDisablingCALayerDelegate = _Class("WebActionDisablingCALayerDelegate")
WebScriptObjectPrivate = _Class("WebScriptObjectPrivate")
WebInterruptionObserverHelper = _Class("WebInterruptionObserverHelper")
WebNetworkStateObserver = _Class("WebNetworkStateObserver")
WebLowPowerModeObserver = _Class("WebLowPowerModeObserver")
WebBackgroundTaskController = _Class("WebBackgroundTaskController")
WAKResponder = _Class("WAKResponder")
WAKWindow = _Class("WAKWindow")
WAKView = _Class("WAKView")
WAKClipView = _Class("WAKClipView")
WAKScrollView = _Class("WAKScrollView")
WebViewVisualIdentificationOverlay = _Class("WebViewVisualIdentificationOverlay")
WebEvent = _Class("WebEvent")
WebScriptObject = _Class("WebScriptObject")
WebAVPlayerLayer = _Class("WebAVPlayerLayer")
LegacyTileLayer = _Class("LegacyTileLayer")
LegacyTileHostLayer = _Class("LegacyTileHostLayer")
WebSimpleLayer = _Class("WebSimpleLayer")
WebLayer = _Class("WebLayer")
WebGLLayer = _Class("WebGLLayer")
WebVideoContainerLayer = _Class("WebVideoContainerLayer")
WebTiledBackingLayer = _Class("WebTiledBackingLayer")
WebSystemBackdropLayer = _Class("WebSystemBackdropLayer")
WebDarkSystemBackdropLayer = _Class("WebDarkSystemBackdropLayer")
WebLightSystemBackdropLayer = _Class("WebLightSystemBackdropLayer")
WebResourceUsageOverlayLayer = _Class("WebResourceUsageOverlayLayer")
WebGPULayer = _Class("WebGPULayer")
WebSwapLayer = _Class("WebSwapLayer")
WebCustomNSURLError = _Class("WebCustomNSURLError")
WebCoreSharedBufferData = _Class("WebCoreSharedBufferData")
