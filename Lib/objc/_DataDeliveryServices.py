"""
Classes from the 'DataDeliveryServices' framework.
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


DDSManager = _Class("DDSManager")
DDSAssertionTracker = _Class("DDSAssertionTracker")
DDSAssertionDataHandler = _Class("DDSAssertionDataHandler")
DDSAssertDescriptor = _Class("DDSAssertDescriptor")
DDSAssetPolicy = _Class("DDSAssetPolicy")
DDSTimedAnalytic = _Class("DDSTimedAnalytic")
DDSAssetDownloadAnalytic = _Class("DDSAssetDownloadAnalytic")
DDSMobileAssetv1PredicateAdapter = _Class("DDSMobileAssetv1PredicateAdapter")
DDSAnalytics = _Class("DDSAnalytics")
DDSRemoteSyncState = _Class("DDSRemoteSyncState")
DDSAssertion = _Class("DDSAssertion")
DDSBackgroundActivityScheduler = _Class("DDSBackgroundActivityScheduler")
DDSContentItem = _Class("DDSContentItem")
DDSContentItemMatcher = _Class("DDSContentItemMatcher")
DDSServer = _Class("DDSServer")
DDSAsset = _Class("DDSAsset")
DDSMobileAssetv2QueryAdapter = _Class("DDSMobileAssetv2QueryAdapter")
DDSAssetQuery = _Class("DDSAssetQuery")
DDSLinguisticAssetQuery = _Class("DDSLinguisticAssetQuery")
DDSAttributeFilter = _Class("DDSAttributeFilter")
DDSLinguisticAttributeFilter = _Class("DDSLinguisticAttributeFilter")
DDSAssetObserver = _Class("DDSAssetObserver")
DDSInterface = _Class("DDSInterface")
DDSAssetQueryResultCache = _Class("DDSAssetQueryResultCache")
DDSMobileAssetv2Provider = _Class("DDSMobileAssetv2Provider")
DDSAssetCenter = _Class("DDSAssetCenter")
