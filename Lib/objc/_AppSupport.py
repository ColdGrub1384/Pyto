'''
Classes from the 'AppSupport' framework.
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

    
CPMemoryPool = _Class('CPMemoryPool')
CPMemoryPoolFile = _Class('CPMemoryPoolFile')
CPBitmapStore = _Class('CPBitmapStore')
RadiosPreferences = _Class('RadiosPreferences')
ALCity = _Class('ALCity')
ALCityManager = _Class('ALCityManager')
PEPServiceConfiguration = _Class('PEPServiceConfiguration')
CPSearchMatcher = _Class('CPSearchMatcher')
InvocationTrampoline = _Class('InvocationTrampoline')
CapturedInvocationTrampoline = _Class('CapturedInvocationTrampoline')
OperationQueueInvocationTrampoline = _Class('OperationQueueInvocationTrampoline')
DelayedInvocationTrampoline = _Class('DelayedInvocationTrampoline')
ThreadedInvocationTrampoline = _Class('ThreadedInvocationTrampoline')
_ReachabilityRequest = _Class('_ReachabilityRequest')
CPDistributedMessagingCenter = _Class('CPDistributedMessagingCenter')
CPDistributedMessagingDelayedReplyContext = _Class('CPDistributedMessagingDelayedReplyContext')
CPDistributedMessagingCallout = _Class('CPDistributedMessagingCallout')
CPDistributedNotificationCenter = _Class('CPDistributedNotificationCenter')
ALSCGreenClient = _Class('ALSCGreenClient')
_CPPowerAssertion = _Class('_CPPowerAssertion')
CPExclusiveLock = _Class('CPExclusiveLock')
CPNetworkObserver = _Class('CPNetworkObserver')
CPLRUDictionaryNode = _Class('CPLRUDictionaryNode')
CPLRUDictionary = _Class('CPLRUDictionary')
CPAggregateDictionary = _Class('CPAggregateDictionary')
CPDistributedMessagingAsyncOperation = _Class('CPDistributedMessagingAsyncOperation')
_CPPowerAssertionThread = _Class('_CPPowerAssertionThread')
_CPBundleIdentifierString = _Class('_CPBundleIdentifierString')
