'''
Classes from the 'MediaToolbox' framework.
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

    
FigCPEFPAirPlaySession = _Class('FigCPEFPAirPlaySession')
FigPhotoTile = _Class('FigPhotoTile')
CMNetworkActivityMonitor = _Class('CMNetworkActivityMonitor')
CMNetworkActivityObserver = _Class('CMNetworkActivityObserver')
FigVideoLayerInternal = _Class('FigVideoLayerInternal')
FigNSURLSessionRegistry = _Class('FigNSURLSessionRegistry')
FigNSURLSession = _Class('FigNSURLSession')
FigDisplaySleepAssertion = _Class('FigDisplaySleepAssertion')
FigHTTPRequestSessionDataDelegate = _Class('FigHTTPRequestSessionDataDelegate')
FigPlayablePattern = _Class('FigPlayablePattern')
FigDisplayMirroringChangeObserver = _Class('FigDisplayMirroringChangeObserver')
fmpcDummyThreadInvoker = _Class('fmpcDummyThreadInvoker')
FPSupport_VideoRangeSingleton = _Class('FPSupport_VideoRangeSingleton')
FPSupport_PowerStateSingleton = _Class('FPSupport_PowerStateSingleton')
FigScreenCaptureController = _Class('FigScreenCaptureController')
FigCaptionLayerPrivate = _Class('FigCaptionLayerPrivate')
FigPhotoTiledLayer = _Class('FigPhotoTiledLayer')
FigHUDLayer = _Class('FigHUDLayer')
FigHUDGraphLayer = _Class('FigHUDGraphLayer')
FigNeroLayer = _Class('FigNeroLayer')
FigBaseCALayer = _Class('FigBaseCALayer')
FigFCRCALayerOutputNodeLayer = _Class('FigFCRCALayerOutputNodeLayer')
FigFCRCALayerOutputNodeContentLayer = _Class('FigFCRCALayerOutputNodeContentLayer')
FigVideoLayer = _Class('FigVideoLayer')
FigFCRCALayer = _Class('FigFCRCALayer')
FigVideoContainerLayer = _Class('FigVideoContainerLayer')
FigCDSCALayerOutputNodeLayer = _Class('FigCDSCALayerOutputNodeLayer')
FigCDSCALayerOutputNodeContentLayer = _Class('FigCDSCALayerOutputNodeContentLayer')
FigCDSCALayer = _Class('FigCDSCALayer')
FigSubtitleWebVTTRegionCALayer = _Class('FigSubtitleWebVTTRegionCALayer')
FigSubtitleBackdropCALayer = _Class('FigSubtitleBackdropCALayer')
FigSubtitleWebVTTCueCALayer = _Class('FigSubtitleWebVTTCueCALayer')
FigSubtitleCALayer = _Class('FigSubtitleCALayer')
FigSubtitleBackdropCALayerContentLayer = _Class('FigSubtitleBackdropCALayerContentLayer')
FigCaptionRowLayer = _Class('FigCaptionRowLayer')
FigCaptionLayer = _Class('FigCaptionLayer')
FigBaseCALayerHost = _Class('FigBaseCALayerHost')
FigBaseCABackdropLayer = _Class('FigBaseCABackdropLayer')
FigCaptionBackdropLayer = _Class('FigCaptionBackdropLayer')
