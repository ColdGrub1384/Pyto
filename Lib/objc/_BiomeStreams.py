'''
Classes from the 'BiomeStreams' framework.
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

    
BMStreamQuery = _Class('BMStreamQuery')
BMStoreValidator = _Class('BMStoreValidator')
BMCoreDuetStream = _Class('BMCoreDuetStream')
BMStreamsAccessClient = _Class('BMStreamsAccessClient')
BMStreams = _Class('BMStreams')
BMPublicStreamsPruner = _Class('BMPublicStreamsPruner')
BMDiscoverabilitySignalStream = _Class('BMDiscoverabilitySignalStream')
BMDiscoverabilitySignalEvent = _Class('BMDiscoverabilitySignalEvent')
BMAppClipLaunchEvent = _Class('BMAppClipLaunchEvent')
BMAppClipLaunchStream = _Class('BMAppClipLaunchStream')
BMAppLaunchStream = _Class('BMAppLaunchStream')
BMMediaUsageStream = _Class('BMMediaUsageStream')
BMSource = _Class('BMSource')
BMStoreSource = _Class('BMStoreSource')
BMCoreDuetDiscoverabilitySignalsSource = _Class('BMCoreDuetDiscoverabilitySignalsSource')
BMAppClipLaunchSource = _Class('BMAppClipLaunchSource')
BMCoreDuetMediaUsageSource = _Class('BMCoreDuetMediaUsageSource')
BMCoreDuetMediaUsageStore = _Class('BMCoreDuetMediaUsageStore')
BMStoreStream = _Class('BMStoreStream')
BMBookmarkNode = _Class('BMBookmarkNode')
BMEventContext = _Class('BMEventContext')
BMStoreStreamPublisher = _Class('BMStoreStreamPublisher')
BMStreamsAccessRequest = _Class('BMStreamsAccessRequest')
BMIntentStream = _Class('BMIntentStream')
BMKnowledgeContextMapping = _Class('BMKnowledgeContextMapping')
BMStream = _Class('BMStream')
BMStreamsAccessService = _Class('BMStreamsAccessService')
BMTestStream = _Class('BMTestStream')
BMEventBase = _Class('BMEventBase')
BMAppLaunchEvent = _Class('BMAppLaunchEvent')
BMMediaUsageEvent = _Class('BMMediaUsageEvent')
BMEventAppAssociatingImplementor = _Class('BMEventAppAssociatingImplementor')
BMEventBinarySteppingImplementor = _Class('BMEventBinarySteppingImplementor')
BMEventTimeElapsingImplementor = _Class('BMEventTimeElapsingImplementor')
BMIntentEvent = _Class('BMIntentEvent')
BMTestEvent = _Class('BMTestEvent')
BMKnowledgeContextPublisher = _Class('BMKnowledgeContextPublisher')
BMBookmarkWrapper = _Class('BMBookmarkWrapper')
BPSBiomeStorePublisher = _Class('BPSBiomeStorePublisher')
BPSKnowledgeStorePublisher = _Class('BPSKnowledgeStorePublisher')
_BPSBookmarkedInner = _Class('_BPSBookmarkedInner')
_BPSInnerBiomeSubscription = _Class('_BPSInnerBiomeSubscription')
_BPSInnerKnowledgeSubscription = _Class('_BPSInnerKnowledgeSubscription')
BMStoreTypedEvent = _Class('BMStoreTypedEvent')
BMPBAppLaunchEvent = _Class('BMPBAppLaunchEvent')
BMPBIntentEvent = _Class('BMPBIntentEvent')
