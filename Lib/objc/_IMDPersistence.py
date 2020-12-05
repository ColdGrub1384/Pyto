"""
Classes from the 'IMDPersistence' framework.
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


IMDCNPersonAliasResolver = _Class("IMDCNPersonAliasResolver")
IMDMessageAutomaticHistoryDeletion = _Class("IMDMessageAutomaticHistoryDeletion")
IMDDonationManager = _Class("IMDDonationManager")
IMDCoreSpotlightManager = _Class("IMDCoreSpotlightManager")
IMDCoreSpotlightContactCache = _Class("IMDCoreSpotlightContactCache")
IMDCoreSpotlightDispatchObject = _Class("IMDCoreSpotlightDispatchObject")
IMDTaskProgress = _Class("IMDTaskProgress")
IMDPersistentAttachmentController = _Class("IMDPersistentAttachmentController")
IMDSqlQuery = _Class("IMDSqlQuery")
IMDSqlSelectQuery = _Class("IMDSqlSelectQuery")
IMDCoreSpotlightChatParticipant = _Class("IMDCoreSpotlightChatParticipant")
IMDCoreSpotlightBaseIndexer = _Class("IMDCoreSpotlightBaseIndexer")
IMDCoreSpotlightMessageAttachmentIndexer = _Class(
    "IMDCoreSpotlightMessageAttachmentIndexer"
)
IMDCoreSpotlightMessageDataDetectorsIndexer = _Class(
    "IMDCoreSpotlightMessageDataDetectorsIndexer"
)
IMDCoreSpotlightMessageBalloonPluginIndexer = _Class(
    "IMDCoreSpotlightMessageBalloonPluginIndexer"
)
IMDCoreSpotlightMessageMetadataIndexer = _Class(
    "IMDCoreSpotlightMessageMetadataIndexer"
)
IMDCoreSpotlightMessageSubjectIndexer = _Class("IMDCoreSpotlightMessageSubjectIndexer")
IMDCoreSpotlightMessageBodyIndexer = _Class("IMDCoreSpotlightMessageBodyIndexer")
IMDCoreSpotlightRecipientIndexer = _Class("IMDCoreSpotlightRecipientIndexer")
IMAbstractDatabaseArchiver = _Class("IMAbstractDatabaseArchiver")
IMAbstractDatabaseTrimmer = _Class("IMAbstractDatabaseTrimmer")
IMTrimDatabaseToMessageCount = _Class("IMTrimDatabaseToMessageCount")
IMTrimDatabaseToDays = _Class("IMTrimDatabaseToDays")
IMDAbstractDatabaseDowngrader = _Class("IMDAbstractDatabaseDowngrader")
IMDWhitetailToCoralDowngrader = _Class("IMDWhitetailToCoralDowngrader")
IMDatabaseAnonymizer = _Class("IMDatabaseAnonymizer")
IMDCNAliasResolver = _Class("IMDCNAliasResolver")
IMDPersistence = _Class("IMDPersistence")
IMDNotificationsController = _Class("IMDNotificationsController")
IMDDatabaseDowngradeHelper = _Class("IMDDatabaseDowngradeHelper")
IMDWhitetailToCoralDowngradeHelper = _Class("IMDWhitetailToCoralDowngradeHelper")
IMDSuggestions = _Class("IMDSuggestions")
