'''
Classes from the 'Catalyst' framework.
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

    
_CATArbitratorResourceProxy = _Class('_CATArbitratorResourceProxy')
_CATErrorBundleHelper = _Class('_CATErrorBundleHelper')
_CATXPCBoostAssertion = _Class('_CATXPCBoostAssertion')
CATTransition = _Class('CATTransition')
CATTaskSession = _Class('CATTaskSession')
CATTaskServer = _Class('CATTaskServer')
CATTaskResultObject = _Class('CATTaskResultObject')
CATTaskRequest = _Class('CATTaskRequest')
CATTaskProgress = _Class('CATTaskProgress')
CATMutableTaskProgress = _Class('CATMutableTaskProgress')
CATTaskClient = _Class('CATTaskClient')
CATTaskBlockServer = _Class('CATTaskBlockServer')
CATStateMachineEvent = _Class('CATStateMachineEvent')
CATStateMachine = _Class('CATStateMachine')
CATState = _Class('CATState')
CATSocket = _Class('CATSocket')
CATTransport = _Class('CATTransport')
CATXPCTransport = _Class('CATXPCTransport')
CATRemoteTransport = _Class('CATRemoteTransport')
CATRemoteConnectionTrustDecision = _Class('CATRemoteConnectionTrustDecision')
CATRemoteConnectionSocketOptions = _Class('CATRemoteConnectionSocketOptions')
_CATRemoteConnectionSendDataWithStreamContext = _Class('_CATRemoteConnectionSendDataWithStreamContext')
_CATRemoteConnectionSendDataContext = _Class('_CATRemoteConnectionSendDataContext')
CATRemoteConnection = _Class('CATRemoteConnection')
CATProperty = _Class('CATProperty')
_CATOperationTargetSelectorObserver = _Class('_CATOperationTargetSelectorObserver')
_CATObserverManager = _Class('_CATObserverManager')
CATNetworkReachability = _Class('CATNetworkReachability')
CATMessage = _Class('CATMessage')
CATTaskMessage = _Class('CATTaskMessage')
CATTaskMessageStart = _Class('CATTaskMessageStart')
CATTaskMessageProgressUpdate = _Class('CATTaskMessageProgressUpdate')
CATTaskMessageIncrementalProgress = _Class('CATTaskMessageIncrementalProgress')
CATTaskMessageFetchProgress = _Class('CATTaskMessageFetchProgress')
CATTaskMessageError = _Class('CATTaskMessageError')
CATTaskMessageCancel = _Class('CATTaskMessageCancel')
CATSessionMessage = _Class('CATSessionMessage')
CATSessionMessageResumed = _Class('CATSessionMessageResumed')
CATSessionMessageResume = _Class('CATSessionMessageResume')
CATSessionMessageInvalidate = _Class('CATSessionMessageInvalidate')
CATSessionMessageDidInvalidate = _Class('CATSessionMessageDidInvalidate')
CATNotificationMessage = _Class('CATNotificationMessage')
CATLocalizationHelper = _Class('CATLocalizationHelper')
CATHTTPMessageParser = _Class('CATHTTPMessageParser')
CATEndPoint = _Class('CATEndPoint')
CATCollectionController = _Class('CATCollectionController')
CATBlockOperationObserver = _Class('CATBlockOperationObserver')
_CATProxyWaitToken = _Class('_CATProxyWaitToken')
_CATArbitratorWaitToken = _Class('_CATArbitratorWaitToken')
_CATArbitratorRegistrationEntry = _Class('_CATArbitratorRegistrationEntry')
CATArbitrator = _Class('CATArbitrator')
CATAddress = _Class('CATAddress')
CATOperationQueue = _Class('CATOperationQueue')
CATSerialOperationQueue = _Class('CATSerialOperationQueue')
CATOperation = _Class('CATOperation')
_CATXPCTransportSendMessageOperation = _Class('_CATXPCTransportSendMessageOperation')
_CATRemoteTransportSendMessageOperation = _Class('_CATRemoteTransportSendMessageOperation')
CATTaskOperation = _Class('CATTaskOperation')
_CATLongRunningTaskOperation = _Class('_CATLongRunningTaskOperation')
_CATBlockTaskOperation = _Class('_CATBlockTaskOperation')
CATRemoteTaskOperation = _Class('CATRemoteTaskOperation')
CATBatchRemoteTaskOperation = _Class('CATBatchRemoteTaskOperation')
_CATTransportDidSendMessageOperation = _Class('_CATTransportDidSendMessageOperation')
