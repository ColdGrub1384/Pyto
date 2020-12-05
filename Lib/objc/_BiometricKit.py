"""
Classes from the 'BiometricKit' framework.
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


BKErrorHelper = _Class("BKErrorHelper")
BKEnrollPearlProgressInfo = _Class("BKEnrollPearlProgressInfo")
BKFaceDetectStateInfo = _Class("BKFaceDetectStateInfo")
BKSystemProtectedConfiguration = _Class("BKSystemProtectedConfiguration")
BKUserProtectedConfiguration = _Class("BKUserProtectedConfiguration")
BKMatchResultInfo = _Class("BKMatchResultInfo")
BKMatchPearlResultInfo = _Class("BKMatchPearlResultInfo")
BKIdentity = _Class("BKIdentity")
BKOperation = _Class("BKOperation")
BKExtendEnrollTouchIDOperation = _Class("BKExtendEnrollTouchIDOperation")
BKPresenceDetectOperation = _Class("BKPresenceDetectOperation")
BKFaceDetectOperation = _Class("BKFaceDetectOperation")
BKFingerDetectOperation = _Class("BKFingerDetectOperation")
BKMatchOperation = _Class("BKMatchOperation")
BKMatchPearlOperation = _Class("BKMatchPearlOperation")
BKMatchTouchIDOperation = _Class("BKMatchTouchIDOperation")
BKEnrollOperation = _Class("BKEnrollOperation")
BKEnrollPearlOperation = _Class("BKEnrollPearlOperation")
BKEnrollTouchIDOperation = _Class("BKEnrollTouchIDOperation")
BiometricPreferences = _Class("BiometricPreferences")
BiometricSupportTools = _Class("BiometricSupportTools")
BKDevice = _Class("BKDevice")
BKDevicePearl = _Class("BKDevicePearl")
BKDeviceTouchID = _Class("BKDeviceTouchID")
BKMatchEvent = _Class("BKMatchEvent")
BKDeviceManager = _Class("BKDeviceManager")
BKDeviceDescriptor = _Class("BKDeviceDescriptor")
BiometricKitMatchInfo = _Class("BiometricKitMatchInfo")
BiometricKitIdentity = _Class("BiometricKitIdentity")
BiometricKit = _Class("BiometricKit")
BiometricKitStatistics = _Class("BiometricKitStatistics")
BiometricKitTemplateInfo = _Class("BiometricKitTemplateInfo")
BiometricKitXPCClient = _Class("BiometricKitXPCClient")
BiometricKitXPCClientConnection = _Class("BiometricKitXPCClientConnection")
BiometricKitEnrollProgressMergedComponent = _Class(
    "BiometricKitEnrollProgressMergedComponent"
)
BiometricKitEnrollProgressCoordinates = _Class("BiometricKitEnrollProgressCoordinates")
BiometricKitEnrollProgressInfo = _Class("BiometricKitEnrollProgressInfo")
