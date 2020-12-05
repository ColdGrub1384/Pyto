"""
Classes from the 'ContactsDonation' framework.
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


_CNDonationToolLogger = _Class("_CNDonationToolLogger")
CNDInMemoryDonationPreferences = _Class("CNDInMemoryDonationPreferences")
CNDDonationPreferences = _Class("CNDDonationPreferences")
CNDonationLoggerProvider = _Class("CNDonationLoggerProvider")
_CNDonationAccountLogger = _Class("_CNDonationAccountLogger")
CNDDonorExtension = _Class("CNDDonorExtension")
_CNDonationExtensionLogger = _Class("_CNDonationExtensionLogger")
_CNDonationAgentXPCMethodScope = _Class("_CNDonationAgentXPCMethodScope")
CNDonationAgentXPCAdapter = _Class("CNDonationAgentXPCAdapter")
_CNDonationAgentLogger = _Class("_CNDonationAgentLogger")
CNDCoreTelephonyServices = _Class("CNDCoreTelephonyServices")
CNDSIMCardItem = _Class("CNDSIMCardItem")
_CNDonationPreferencesLogger = _Class("_CNDonationPreferencesLogger")
CNDonationExtensionRequestHandler = _Class("CNDonationExtensionRequestHandler")
CNDDonorLoader = _Class("CNDDonorLoader")
CNDonationStore = _Class("CNDonationStore")
CNDonationValue = _Class("CNDonationValue")
_CNImageDataDonationValue = _Class("_CNImageDataDonationValue")
_CNPostalAddressDonationValue = _Class("_CNPostalAddressDonationValue")
_CNPhoneNumberDonationValue = _Class("_CNPhoneNumberDonationValue")
_CNEmailAddressDonationValue = _Class("_CNEmailAddressDonationValue")
_CNNameComponentsDonationValue = _Class("_CNNameComponentsDonationValue")
_CNDonationAnalyticsLogger = _Class("_CNDonationAnalyticsLogger")
CNDSIMCardMonitor = _Class("CNDSIMCardMonitor")
CNDonationOrigin = _Class("CNDonationOrigin")
CNMutableDonationOrigin = _Class("CNMutableDonationOrigin")
_CNDExtensionContext = _Class("_CNDExtensionContext")
_CNDRemoteExtensionContext = _Class("_CNDRemoteExtensionContext")
_CNDHostExtensionContext = _Class("_CNDHostExtensionContext")
