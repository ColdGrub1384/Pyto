"""
Classes from the 'ClassKit' framework.
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


CLSRelation = _Class("CLSRelation")
CLSChildParentRelation = _Class("CLSChildParentRelation")
CLSParentChildRelation = _Class("CLSParentChildRelation")
CLSAssetUploadObserver = _Class("CLSAssetUploadObserver")
CLSSearchSpecification = _Class("CLSSearchSpecification")
CLSSettingsVisibilityController = _Class("CLSSettingsVisibilityController")
CLSClient = _Class("CLSClient")
CLSEndpointConnection = _Class("CLSEndpointConnection")
CLSAuthTreeNode = _Class("CLSAuthTreeNode")
CLSAuthTree = _Class("CLSAuthTree")
CLSPendingOperations = _Class("CLSPendingOperations")
CLSUtil = _Class("CLSUtil")
CLSUtilityService = _Class("CLSUtilityService")
CLSFaultProcessor = _Class("CLSFaultProcessor")
CLSContextProviderService = _Class("CLSContextProviderService")
CLSDataStore = _Class("CLSDataStore")
CLSEntitlements = _Class("CLSEntitlements")
CLSCurrentUser = _Class("CLSCurrentUser")
CLSContextProviderServiceFinder = _Class("CLSContextProviderServiceFinder")
CLSDataObserver = _Class("CLSDataObserver")
CLSQuery = _Class("CLSQuery")
CLSSaveResponse = _Class("CLSSaveResponse")
CLSGraph = _Class("CLSGraph")
CLSReportItem = _Class("CLSReportItem")
CLSHandoutReportItem = _Class("CLSHandoutReportItem")
CLSActivityReport = _Class("CLSActivityReport")
CLSActivityReportItem = _Class("CLSActivityReportItem")
CLSQuantityReportItem = _Class("CLSQuantityReportItem")
CLSScoreReportItem = _Class("CLSScoreReportItem")
CLSBinaryReportItem = _Class("CLSBinaryReportItem")
CLSAggregatedValue = _Class("CLSAggregatedValue")
CLSObject = _Class("CLSObject")
CLSServerAlert = _Class("CLSServerAlert")
CLSCollection = _Class("CLSCollection")
CLSArchivedHandoutAttachment = _Class("CLSArchivedHandoutAttachment")
CLSAsset = _Class("CLSAsset")
CLSRange = _Class("CLSRange")
CLSContext = _Class("CLSContext")
CLSActivity = _Class("CLSActivity")
CLSRole = _Class("CLSRole")
CLSImageUtils = _Class("CLSImageUtils")
CLSHandoutAttachment = _Class("CLSHandoutAttachment")
CLSBlob = _Class("CLSBlob")
CLSLocation = _Class("CLSLocation")
CLSArchivedAsset = _Class("CLSArchivedAsset")
CLSPerson = _Class("CLSPerson")
CLSTimeInterval = _Class("CLSTimeInterval")
CLSFavorite = _Class("CLSFavorite")
CLSProgressReportingCapability = _Class("CLSProgressReportingCapability")
CLSAbstractHandout = _Class("CLSAbstractHandout")
CLSArchivedHandout = _Class("CLSArchivedHandout")
CLSHandout = _Class("CLSHandout")
CLSCollaborationState = _Class("CLSCollaborationState")
CLSClassMember = _Class("CLSClassMember")
CLSCollectionItem = _Class("CLSCollectionItem")
CLSHandoutRecipient = _Class("CLSHandoutRecipient")
CLSActivityItem = _Class("CLSActivityItem")
CLSScoreItem = _Class("CLSScoreItem")
CLSBinaryItem = _Class("CLSBinaryItem")
CLSQuantityItem = _Class("CLSQuantityItem")
CLSClass = _Class("CLSClass")
CLSCollaborationStateChange = _Class("CLSCollaborationStateChange")
CLSContextProviderExtensionContext = _Class("CLSContextProviderExtensionContext")
CLSContextProviderExtensionHostContext = _Class(
    "CLSContextProviderExtensionHostContext"
)
