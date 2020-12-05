"""
Classes from the 'iTunesStore' framework.
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


ISDeleteDaemonModule = _Class("ISDeleteDaemonModule")
ISURLBagCache = _Class("ISURLBagCache")
ISURLRequestPerformance = _Class("ISURLRequestPerformance")
ISPersonalizeOffersRequest = _Class("ISPersonalizeOffersRequest")
ISCookieStorage = _Class("ISCookieStorage")
OpenURLTarget = _Class("OpenURLTarget")
ISOpenURLRequest = _Class("ISOpenURLRequest")
ISPasswordSettingsUtility = _Class("ISPasswordSettingsUtility")
ISURLOperationPool = _Class("ISURLOperationPool")
ISURLCacheConfiguration = _Class("ISURLCacheConfiguration")
ISURLCache = _Class("ISURLCache")
ISURLRequest = _Class("ISURLRequest")
ISDelegateProxy = _Class("ISDelegateProxy")
ISITunesSyncHelper = _Class("ISITunesSyncHelper")
ISUniqueOperationContext = _Class("ISUniqueOperationContext")
ISUniqueOperationManager = _Class("ISUniqueOperationManager")
ISURLBagBackend = _Class("ISURLBagBackend")
ISSoftwareMap = _Class("ISSoftwareMap")
ISDialogTextField = _Class("ISDialogTextField")
ISAMSBagShim = _Class("ISAMSBagShim")
ISUserNotification = _Class("ISUserNotification")
ISSSURLBag = _Class("ISSSURLBag")
ISReview = _Class("ISReview")
ISSoftwareApplication = _Class("ISSoftwareApplication")
ISAuthenticationChallenge = _Class("ISAuthenticationChallenge")
ISURLAuthenticationChallenge = _Class("ISURLAuthenticationChallenge")
ISStoreAuthenticationChallenge = _Class("ISStoreAuthenticationChallenge")
ISHashError = _Class("ISHashError")
ISNetworkObserver = _Class("ISNetworkObserver")
ISClient = _Class("ISClient")
ISURLBag = _Class("ISURLBag")
ISDataProvider = _Class("ISDataProvider")
ISJSONDataProvider = _Class("ISJSONDataProvider")
ISReviewProvider = _Class("ISReviewProvider")
ISHashedDownloadProvider = _Class("ISHashedDownloadProvider")
ISProtocolDataProvider = _Class("ISProtocolDataProvider")
ISPropertyListProvider = _Class("ISPropertyListProvider")
ISOperationQueue = _Class("ISOperationQueue")
ISURLBagLoadingController = _Class("ISURLBagLoadingController")
ISInvocationRecorder = _Class("ISInvocationRecorder")
ISMainThreadInvocationRecorder = _Class("ISMainThreadInvocationRecorder")
ISDelayedInvocationRecorder = _Class("ISDelayedInvocationRecorder")
ISDialogButton = _Class("ISDialogButton")
ISTouchIDDialogButton = _Class("ISTouchIDDialogButton")
ISDialog = _Class("ISDialog")
ISQRCodeDialog = _Class("ISQRCodeDialog")
ISTouchIDDialog = _Class("ISTouchIDDialog")
ISBiometricStore = _Class("ISBiometricStore")
ISDevice = _Class("ISDevice")
RemovableSoftwareLookupTable = _Class("RemovableSoftwareLookupTable")
ISStoreVersion = _Class("ISStoreVersion")
ISOperation = _Class("ISOperation")
ISLogoutOperation = _Class("ISLogoutOperation")
ISPersonalizeOffersOperation = _Class("ISPersonalizeOffersOperation")
ISCreateAccountPromptOperation = _Class("ISCreateAccountPromptOperation")
ISSoftwareCapabilitiesDialogOperation = _Class("ISSoftwareCapabilitiesDialogOperation")
ISMachineDataProvisioningOperation = _Class("ISMachineDataProvisioningOperation")
ISBiometricOptInOperation = _Class("ISBiometricOptInOperation")
ISStoreServicesRequestOperation = _Class("ISStoreServicesRequestOperation")
ISBiometricUpdateTouchIDSettingsOperation = _Class(
    "ISBiometricUpdateTouchIDSettingsOperation"
)
ISURLOperationPoolOperation = _Class("ISURLOperationPoolOperation")
ISProcessPropertyListOperation = _Class("ISProcessPropertyListOperation")
ISServerAuthenticationOperation = _Class("ISServerAuthenticationOperation")
ISSetApplicationBadgeOperation = _Class("ISSetApplicationBadgeOperation")
ISMachineDataSyncOperation = _Class("ISMachineDataSyncOperation")
ISOpenURLOperation = _Class("ISOpenURLOperation")
ISCreateAccountOperation = _Class("ISCreateAccountOperation")
ISMachineDataActionOperation = _Class("ISMachineDataActionOperation")
ISPostReviewOperation = _Class("ISPostReviewOperation")
ISBiometricAuthorizationDialogOperation = _Class(
    "ISBiometricAuthorizationDialogOperation"
)
ISStoreAuthenticateOperation = _Class("ISStoreAuthenticateOperation")
ISLoadSoftwareMapOperation = _Class("ISLoadSoftwareMapOperation")
ISDialogOperation = _Class("ISDialogOperation")
ISAuthenticationChallengeOperation = _Class("ISAuthenticationChallengeOperation")
ISUIKitDialogOperation = _Class("ISUIKitDialogOperation")
ISBiometricSignatureOperation = _Class("ISBiometricSignatureOperation")
ISLoadURLBagOperation = _Class("ISLoadURLBagOperation")
ISURLResolverOperation = _Class("ISURLResolverOperation")
ISURLOperation = _Class("ISURLOperation")
ISStoreURLOperation = _Class("ISStoreURLOperation")
