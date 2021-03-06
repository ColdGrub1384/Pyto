"""
Classes from the 'IMCore' framework.
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


IMCloudKitHooks = _Class("IMCloudKitHooks")
IMSPIMessage = _Class("IMSPIMessage")
IMSPIAttachment = _Class("IMSPIAttachment")
IMSPIRecentEvent = _Class("IMSPIRecentEvent")
IMSPISuggestionsObject = _Class("IMSPISuggestionsObject")
IMSPIChat = _Class("IMSPIChat")
IMSPIHandle = _Class("IMSPIHandle")
IMSendProgressRealTimeDataSource = _Class("IMSendProgressRealTimeDataSource")
IMSendProgress = _Class("IMSendProgress")
IMFMFSession = _Class("IMFMFSession")
IMLocationManager = _Class("IMLocationManager")
IMAttachment = _Class("IMAttachment")
IMDDController = _Class("IMDDController")
IMChatHistoryController = _Class("IMChatHistoryController")
IMIDStatusController = _Class("IMIDStatusController")
IMAutomationBatchMessageOperations = _Class("IMAutomationBatchMessageOperations")
IMOneTimeCodeAccelerator = _Class("IMOneTimeCodeAccelerator")
IMAutomationMessageSend = _Class("IMAutomationMessageSend")
IMBalloonApp = _Class("IMBalloonApp")
_IMBalloonBundleApp = _Class("_IMBalloonBundleApp")
_IMBalloonExtensionApp = _Class("_IMBalloonExtensionApp")
IMChatRegistry = _Class("IMChatRegistry")
IMWhitelistController = _Class("IMWhitelistController")
IMCommLimitsPolicyCache = _Class("IMCommLimitsPolicyCache")
IMMessage = _Class("IMMessage")
IMAddressBook = _Class("IMAddressBook")
IMTranscriptChatItemRules = _Class("IMTranscriptChatItemRules")
IMInlineReplyChatItemRules = _Class("IMInlineReplyChatItemRules")
IMAutomation = _Class("IMAutomation")
IMOrderingTools = _Class("IMOrderingTools")
IMItemChatContext = _Class("IMItemChatContext")
IMMessageItemChatContext = _Class("IMMessageItemChatContext")
IMMe = _Class("IMMe")
IMCloudKitSyncProgress = _Class("IMCloudKitSyncProgress")
IMCloudKitKeyRollPendingErrorProgress = _Class("IMCloudKitKeyRollPendingErrorProgress")
IMCloudKitHiddenSyncProgress = _Class("IMCloudKitHiddenSyncProgress")
IMCloudKitCloudKitStorageIsFullSyncProgress = _Class(
    "IMCloudKitCloudKitStorageIsFullSyncProgress"
)
IMCloudKitDeviceStorageIsFullSyncProgress = _Class(
    "IMCloudKitDeviceStorageIsFullSyncProgress"
)
IMCloudKitAccountNeedsRepairSyncProgress = _Class(
    "IMCloudKitAccountNeedsRepairSyncProgress"
)
IMCloudKitPausedSyncProgress = _Class("IMCloudKitPausedSyncProgress")
IMCloudKitSyncProgressIsSyncing = _Class("IMCloudKitSyncProgressIsSyncing")
IMTranscriptEffectHelper = _Class("IMTranscriptEffectHelper")
IMPeople = _Class("IMPeople")
IMCloudKitMockSyncState = _Class("IMCloudKitMockSyncState")
IMLocationManagerUtils = _Class("IMLocationManagerUtils")
IMHandleRegistrar = _Class("IMHandleRegistrar")
IMHandle = _Class("IMHandle")
IMBalloonPluginManager = _Class("IMBalloonPluginManager")
IMBalloonPlugin = _Class("IMBalloonPlugin")
IMBalloonAppExtension = _Class("IMBalloonAppExtension")
IMBalloonBrowserPlugin = _Class("IMBalloonBrowserPlugin")
IMServiceAgent = _Class("IMServiceAgent")
IMServiceAgentImpl = _Class("IMServiceAgentImpl")
IMChatItem = _Class("IMChatItem")
IMTranscriptChatItem = _Class("IMTranscriptChatItem")
IMUnreadCountChatItem = _Class("IMUnreadCountChatItem")
IMExpressiveSendAsTextChatItem = _Class("IMExpressiveSendAsTextChatItem")
IMAssociatedMessageChatItem = _Class("IMAssociatedMessageChatItem")
IMAggregateAcknowledgmentChatItem = _Class("IMAggregateAcknowledgmentChatItem")
IMAssociatedStickerChatItem = _Class("IMAssociatedStickerChatItem")
IMMessageAcknowledgmentChatItem = _Class("IMMessageAcknowledgmentChatItem")
IMMessageEditChatItem = _Class("IMMessageEditChatItem")
IMMessageActionChatItem = _Class("IMMessageActionChatItem")
IMTUConversationChatItem = _Class("IMTUConversationChatItem")
IMLocationShareActionChatItem = _Class("IMLocationShareActionChatItem")
IMLocationShareOfferChatItem = _Class("IMLocationShareOfferChatItem")
IMParticipantChangeChatItem = _Class("IMParticipantChangeChatItem")
IMGroupTitleChangeChatItem = _Class("IMGroupTitleChangeChatItem")
IMGroupActionChatItem = _Class("IMGroupActionChatItem")
IMMessageStatusChatItem = _Class("IMMessageStatusChatItem")
IMTranscriptPluginStatusChatItem = _Class("IMTranscriptPluginStatusChatItem")
IMMessageReplyCountChatItem = _Class("IMMessageReplyCountChatItem")
IMMessageAttributionChatItem = _Class("IMMessageAttributionChatItem")
IMMessageEffectControlChatItem = _Class("IMMessageEffectControlChatItem")
IMTranscriptPluginBreadcrumbChatItem = _Class("IMTranscriptPluginBreadcrumbChatItem")
IMMessageChatItem = _Class("IMMessageChatItem")
IMEmoteMessageChatItem = _Class("IMEmoteMessageChatItem")
IMLocatingChatItem = _Class("IMLocatingChatItem")
IMTypingChatItem = _Class("IMTypingChatItem")
IMTypingPluginChatItem = _Class("IMTypingPluginChatItem")
IMMessagePartChatItem = _Class("IMMessagePartChatItem")
IMTranscriptLocationChatItem = _Class("IMTranscriptLocationChatItem")
IMAttachmentMessagePartChatItem = _Class("IMAttachmentMessagePartChatItem")
IMExpirableMessageChatItem = _Class("IMExpirableMessageChatItem")
IMAudioMessageChatItem = _Class("IMAudioMessageChatItem")
IMErrorMessagePartChatItem = _Class("IMErrorMessagePartChatItem")
IMAnimatedEmojiMessagePartChatItem = _Class("IMAnimatedEmojiMessagePartChatItem")
IMReplyContextAttachmentMessagePartChatItem = _Class(
    "IMReplyContextAttachmentMessagePartChatItem"
)
IMTranscriptPluginChatItem = _Class("IMTranscriptPluginChatItem")
IMReplyContextTranscriptPluginChatItem = _Class(
    "IMReplyContextTranscriptPluginChatItem"
)
IMTextMessagePartChatItem = _Class("IMTextMessagePartChatItem")
IMAggregateMessagePartChatItem = _Class("IMAggregateMessagePartChatItem")
IMReplyContextAggregateMessagePartChatItem = _Class(
    "IMReplyContextAggregateMessagePartChatItem"
)
IMReplyContextTextMessagePartChatItem = _Class("IMReplyContextTextMessagePartChatItem")
IMReplyContextDeletedMessageChatItem = _Class("IMReplyContextDeletedMessageChatItem")
IMSenderChatItem = _Class("IMSenderChatItem")
IMReplySenderChatItem = _Class("IMReplySenderChatItem")
IMDateChatItem = _Class("IMDateChatItem")
IMNumberChangedChatItem = _Class("IMNumberChangedChatItem")
IMServiceChatItem = _Class("IMServiceChatItem")
IMSMSSpamChatItem = _Class("IMSMSSpamChatItem")
IMReportSpamChatItem = _Class("IMReportSpamChatItem")
IMBlackholeChatItem = _Class("IMBlackholeChatItem")
IMLoadMoreChatItem = _Class("IMLoadMoreChatItem")
IMLoadMoreRecentChatItem = _Class("IMLoadMoreRecentChatItem")
IMFileTransferCenter = _Class("IMFileTransferCenter")
IMParentalControls = _Class("IMParentalControls")
IMParentalControlsService = _Class("IMParentalControlsService")
IMCloudKitSyncState = _Class("IMCloudKitSyncState")
IMMapURLLocationInfo = _Class("IMMapURLLocationInfo")
IMNicknameController = _Class("IMNicknameController")
IMAccountController = _Class("IMAccountController")
IMSimulatedAccountController = _Class("IMSimulatedAccountController")
IMCoreAutomationHook = _Class("IMCoreAutomationHook")
IMAutomationGroupChat = _Class("IMAutomationGroupChat")
IMDaemonController = _Class("IMDaemonController")
IMSimulatedDaemonController = _Class("IMSimulatedDaemonController")
IMItemsController = _Class("IMItemsController")
IMInlineReplyController = _Class("IMInlineReplyController")
IMChat = _Class("IMChat")
IMSimulatedChat = _Class("IMSimulatedChat")
IMCloudKitEventNotificationManager = _Class("IMCloudKitEventNotificationManager")
IMCloudKitSyncStatistics = _Class("IMCloudKitSyncStatistics")
IMDaemonListener = _Class("IMDaemonListener")
IMDNDList = _Class("IMDNDList")
IMRemindersIntegration = _Class("IMRemindersIntegration")
IMAccount = _Class("IMAccount")
IMSimulatedAccount = _Class("IMSimulatedAccount")
IMSuggestionsService = _Class("IMSuggestionsService")
IMBalloonPluginAttributionController = _Class("IMBalloonPluginAttributionController")
IMPluginPayload = _Class("IMPluginPayload")
IMBalloonPluginDataSource = _Class("IMBalloonPluginDataSource")
IMService = _Class("IMService")
IMServiceImpl = _Class("IMServiceImpl")
IMPinnedConversationsController = _Class("IMPinnedConversationsController")
IMOrderingMetricCollector = _Class("IMOrderingMetricCollector")
IMCloudKitHookTestSingleton = _Class("IMCloudKitHookTestSingleton")
IMCloudKitEventNotificationRuntimeTestSuite = _Class(
    "IMCloudKitEventNotificationRuntimeTestSuite"
)
IMCloudKitEventNotificationManagerRuntimeTest = _Class(
    "IMCloudKitEventNotificationManagerRuntimeTest"
)
IMCloudKitSyncProgressRuntimeTest = _Class("IMCloudKitSyncProgressRuntimeTest")
IMCloudKitErrorProgressTest = _Class("IMCloudKitErrorProgressTest")
IMCloudKitSyncProgressRuntimeTestPaused = _Class(
    "IMCloudKitSyncProgressRuntimeTestPaused"
)
IMCloudKitSyncProgressRuntimeTestUploading = _Class(
    "IMCloudKitSyncProgressRuntimeTestUploading"
)
IMCloudKitSyncProgressRuntimeTestDownloading = _Class(
    "IMCloudKitSyncProgressRuntimeTestDownloading"
)
IMCloudKitSyncProgressRuntimeTestDeleting = _Class(
    "IMCloudKitSyncProgressRuntimeTestDeleting"
)
IMCloudKitSyncProgressRuntimeTestPreparing = _Class(
    "IMCloudKitSyncProgressRuntimeTestPreparing"
)
