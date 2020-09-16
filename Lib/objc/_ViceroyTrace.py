'''
Classes from the 'ViceroyTrace' framework.
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

    
VCSymptomReporter = _Class('VCSymptomReporter')
VCVideoFECStatsHolder = _Class('VCVideoFECStatsHolder')
VCHistogram = _Class('VCHistogram')
GKSLinkingSingleton = _Class('GKSLinkingSingleton')
GKSDLHandleWrapper = _Class('GKSDLHandleWrapper')
VCAggregatorUtils = _Class('VCAggregatorUtils')
TimingCollection = _Class('TimingCollection')
TimingInstance = _Class('TimingInstance')
VCWeakObjectHolder = _Class('VCWeakObjectHolder')
RTCReportingAgent = _Class('RTCReportingAgent')
MultiwaySegment = _Class('MultiwaySegment')
DownlinkSegment = _Class('DownlinkSegment')
UplinkSegment = _Class('UplinkSegment')
MultiwayCall = _Class('MultiwayCall')
MultiwayStream = _Class('MultiwayStream')
VCAdaptiveLearning = _Class('VCAdaptiveLearning')
VCSegmentCallHistory = _Class('VCSegmentCallHistory')
CallSegment = _Class('CallSegment')
VCAggregator = _Class('VCAggregator')
VCAggregatorSecondDisplay = _Class('VCAggregatorSecondDisplay')
VCAggregatorMultiway = _Class('VCAggregatorMultiway')
VCAggregatorFaceTime = _Class('VCAggregatorFaceTime')
VCAggregatorAirPlay = _Class('VCAggregatorAirPlay')
