"""
Classes from the 'CommonUtilities' framework.
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


CUTPowerMonitor = _Class("CUTPowerMonitor")
_CUTPowerMonitor = _Class("_CUTPowerMonitor")
CUTFileCopier = _Class("CUTFileCopier")
CUTPromiseSeal = _Class("CUTPromiseSeal")
CUTUnsafePromiseSeal = _Class("CUTUnsafePromiseSeal")
CUTWiFiManager = _Class("CUTWiFiManager")
CUTReachability = _Class("CUTReachability")
CUTTelephonyManager = _Class("CUTTelephonyManager")
CUTReporting = _Class("CUTReporting")
CUTResult = _Class("CUTResult")
CUTLog = _Class("CUTLog")
CUTPowerAssertion = _Class("CUTPowerAssertion")
_CUTPowerAssertion = _Class("_CUTPowerAssertion")
CUTNetworkInterfaceListener = _Class("CUTNetworkInterfaceListener")
CUTUnsafePromise = _Class("CUTUnsafePromise")
CUTPromise = _Class("CUTPromise")
_CUTLockingPromise = _Class("_CUTLockingPromise")
_CUTStaticPromise = _Class("_CUTStaticPromise")
_CUTPromise = _Class("_CUTPromise")
_CUTUnsafePromise = _Class("_CUTUnsafePromise")
CUTWeakReference = _Class("CUTWeakReference")
CUTAsyncReducerState = _Class("CUTAsyncReducerState")
CUTAsyncReducer = _Class("CUTAsyncReducer")
CUTCheckpoint = _Class("CUTCheckpoint")
CUTCheckpointSignpost = _Class("CUTCheckpointSignpost")
CUTCheckpointRange = _Class("CUTCheckpointRange")
CUTCheckpointTrace = _Class("CUTCheckpointTrace")
CUTCheckpointInstant = _Class("CUTCheckpointInstant")
CUTDeferredTaskQueue = _Class("CUTDeferredTaskQueue")
