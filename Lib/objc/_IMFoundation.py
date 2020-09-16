'''
Classes from the 'IMFoundation' framework.
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

    
Broadcaster = _Class('Broadcaster')
IMMessageContext = _Class('IMMessageContext')
IMPowerAssertion = _Class('IMPowerAssertion')
IMMultiDict = _Class('IMMultiDict')
OSLogHandleManager = _Class('OSLogHandleManager')
IMPingTest = _Class('IMPingTest')
_IMPingStatisticsCollector = _Class('_IMPingStatisticsCollector')
IMPingStatistics = _Class('IMPingStatistics')
_IMPingPacketData = _Class('_IMPingPacketData')
IMWeakReference = _Class('IMWeakReference')
IMPurgableObject = _Class('IMPurgableObject')
IMPerfNSLogProfilerSink = _Class('IMPerfNSLogProfilerSink')
IMMultiQueue = _Class('IMMultiQueue')
IMMultiQueueItem = _Class('IMMultiQueueItem')
IMNetworkAvailability = _Class('IMNetworkAvailability')
IMNetworkReachability = _Class('IMNetworkReachability')
IMRemoteURLConnection = _Class('IMRemoteURLConnection')
IMRKResponse = _Class('IMRKResponse')
IMRKMessageResponseManager = _Class('IMRKMessageResponseManager')
_IMNotificationObservationHelper = _Class('_IMNotificationObservationHelper')
IMOrderedMutableDictionary = _Class('IMOrderedMutableDictionary')
IMIDSLog = _Class('IMIDSLog')
IMURLSession = _Class('IMURLSession')
IMTimer = _Class('IMTimer')
IMCallMonitor = _Class('IMCallMonitor')
IMRemoteURLConnectionMockScheduler = _Class('IMRemoteURLConnectionMockScheduler')
IMLogging = _Class('IMLogging')
_IMLogFileCompressor = _Class('_IMLogFileCompressor')
IMLockdownManager = _Class('IMLockdownManager')
IMMobileNetworkManager = _Class('IMMobileNetworkManager')
IMRGLog = _Class('IMRGLog')
IMRemoteObjectBroadcaster = _Class('IMRemoteObjectBroadcaster')
IMRemoteObject = _Class('IMRemoteObject')
IMRemoteObjectInternal = _Class('IMRemoteObjectInternal')
IMLocalObject = _Class('IMLocalObject')
IMLocalObjectInternal = _Class('IMLocalObjectInternal')
IMConnectionMonitor = _Class('IMConnectionMonitor')
IMNetworkConnectionMonitor = _Class('IMNetworkConnectionMonitor')
IMManualUpdater = _Class('IMManualUpdater')
IMScheduledUpdater = _Class('IMScheduledUpdater')
IMPerfProfiler = _Class('IMPerfProfiler')
IMPerfSinkPair = _Class('IMPerfSinkPair')
IMReachability = _Class('IMReachability')
IMFileCopier = _Class('IMFileCopier')
IMUserNotificationCenter = _Class('IMUserNotificationCenter')
IMUserNotification = _Class('IMUserNotification')
IMSystemMonitor = _Class('IMSystemMonitor')
IMAllocTracking = _Class('IMAllocTracking')
IMMockURLResponse = _Class('IMMockURLResponse')
IMPerfProfilerDefaultBehavior = _Class('IMPerfProfilerDefaultBehavior')
IMURLResponseToPlist = _Class('IMURLResponseToPlist')
NetworkChangeNotifier = _Class('NetworkChangeNotifier')
IMInvocationQueue = _Class('IMInvocationQueue')
IMDeviceSupport = _Class('IMDeviceSupport')
IMUserDefaults = _Class('IMUserDefaults')
IMTimingCollection = _Class('IMTimingCollection')
_IMTimingInstance = _Class('_IMTimingInstance')
IMWeakObjectCache = _Class('IMWeakObjectCache')
IMDoubleLinkedList = _Class('IMDoubleLinkedList')
IMDoubleLinkedListNode = _Class('IMDoubleLinkedListNode')
IMInvocationTrampoline = _Class('IMInvocationTrampoline')
IMCapturedInvocationTrampoline = _Class('IMCapturedInvocationTrampoline')
IMDelayedInvocationTrampoline = _Class('IMDelayedInvocationTrampoline')
IMThreadedInvocationTrampoline = _Class('IMThreadedInvocationTrampoline')
IMSystemProxySettingsFetcher = _Class('IMSystemProxySettingsFetcher')
IMPair = _Class('IMPair')
IMFileManager = _Class('IMFileManager')
