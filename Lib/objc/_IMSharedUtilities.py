"""
Classes from the 'IMSharedUtilities' framework.
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


IMSingletonProxy = _Class("IMSingletonProxy")
IMAKAppleIDAuthenticationController = _Class("IMAKAppleIDAuthenticationController")
IMFileTransfer = _Class("IMFileTransfer")
IMGroupBlacklistManager = _Class("IMGroupBlacklistManager")
IMOneTimeCodeUtilities = _Class("IMOneTimeCodeUtilities")
IMCoreSpotlightUtilities = _Class("IMCoreSpotlightUtilities")
IMDeviceConditions = _Class("IMDeviceConditions")
IMMetricsCollector = _Class("IMMetricsCollector")
IMXMLReparserContext = _Class("IMXMLReparserContext")
IMXMLReparser = _Class("IMXMLReparser")
IMAppleStoreHelper = _Class("IMAppleStoreHelper")
IMMessageNotificationTimeManager = _Class("IMMessageNotificationTimeManager")
IMMessageNotificationTimer = _Class("IMMessageNotificationTimer")
IMKeyValueCollectionDictionaryStorage = _Class("IMKeyValueCollectionDictionaryStorage")
IMSenderIdentityManager = _Class("IMSenderIdentityManager")
IMFeatureFlags = _Class("IMFeatureFlags")
IMCoreAutomationNotifications = _Class("IMCoreAutomationNotifications")
IMUnitTestFrameworkLoader = _Class("IMUnitTestFrameworkLoader")
IMCKPadding = _Class("IMCKPadding")
IMSingletonOverride = _Class("IMSingletonOverride")
IMWeakReferenceCollection = _Class("IMWeakReferenceCollection")
IMBusinessNameManager = _Class("IMBusinessNameManager")
IMMessageNotificationController = _Class("IMMessageNotificationController")
IMAttributedStringParser = _Class("IMAttributedStringParser")
IMCTSMSUtilities = _Class("IMCTSMSUtilities")
IMSpamFilterHelper = _Class("IMSpamFilterHelper")
IMXMLParserFrame = _Class("IMXMLParserFrame")
IMToSuperParserFrame = _Class("IMToSuperParserFrame")
HTMLToSuper_Default_Frame = _Class("HTMLToSuper_Default_Frame")
HTMLToSuper_OBJECT_Frame = _Class("HTMLToSuper_OBJECT_Frame")
HTMLToSuper_U_Frame = _Class("HTMLToSuper_U_Frame")
HTMLToSuper_STRONG_Frame = _Class("HTMLToSuper_STRONG_Frame")
HTMLToSuper_STRIKE_Frame = _Class("HTMLToSuper_STRIKE_Frame")
HTMLToSuper_SPAN_Frame = _Class("HTMLToSuper_SPAN_Frame")
HTMLToSuper_S_Frame = _Class("HTMLToSuper_S_Frame")
HTMLToSuper_I_Frame = _Class("HTMLToSuper_I_Frame")
HTMLToSuper_FONT_Frame = _Class("HTMLToSuper_FONT_Frame")
HTMLToSuper_EM_Frame = _Class("HTMLToSuper_EM_Frame")
HTMLToSuper_BODY_Frame = _Class("HTMLToSuper_BODY_Frame")
HTMLToSuper_BR_Frame = _Class("HTMLToSuper_BR_Frame")
HTMLToSuper_B_Frame = _Class("HTMLToSuper_B_Frame")
HTMLToSuper_A_Frame = _Class("HTMLToSuper_A_Frame")
IMXMLParserContext = _Class("IMXMLParserContext")
IMToSuperParserContext = _Class("IMToSuperParserContext")
IMHTMLToSuperParserContext = _Class("IMHTMLToSuperParserContext")
IMXMLParser = _Class("IMXMLParser")
IMSharedChatSummaries = _Class("IMSharedChatSummaries")
IMImageUtilities = _Class("IMImageUtilities")
IMContactStore = _Class("IMContactStore")
IMSticker = _Class("IMSticker")
IMTranscoderTelemetry = _Class("IMTranscoderTelemetry")
IMStateCaptureAssistant = _Class("IMStateCaptureAssistant")
IMSharedMessageSendingUtilities = _Class("IMSharedMessageSendingUtilities")
IMKeyValueCollection = _Class("IMKeyValueCollection")
IMBroadcastingKeyValueCollection = _Class("IMBroadcastingKeyValueCollection")
IMStateCaptureRecentsBuffer = _Class("IMStateCaptureRecentsBuffer")
IMStickerPack = _Class("IMStickerPack")
IMUnarchiverDecoder = _Class("IMUnarchiverDecoder")
IMDSharedUtilitiesPluginPayload = _Class("IMDSharedUtilitiesPluginPayload")
IMSharedMessageAppSummary = _Class("IMSharedMessageAppSummary")
IMSharedMessageRichLinkSummary = _Class("IMSharedMessageRichLinkSummary")
IMSharedMessage3rdPartySummary = _Class("IMSharedMessage3rdPartySummary")
IMSharedMessageDTSummary = _Class("IMSharedMessageDTSummary")
IMSharedMessagePhotosSummary = _Class("IMSharedMessagePhotosSummary")
IMSharedMessageHandwritingSummary = _Class("IMSharedMessageHandwritingSummary")
IMPreviewGeneratorManager = _Class("IMPreviewGeneratorManager")
IMiMessageAppPayloadDecoder = _Class("IMiMessageAppPayloadDecoder")
IMRuntimeTest = _Class("IMRuntimeTest")
IMRuntimeTestSuite = _Class("IMRuntimeTestSuite")
IMRuntimeTestCase = _Class("IMRuntimeTestCase")
IMRecentItemsList = _Class("IMRecentItemsList")
IMRecentItem = _Class("IMRecentItem")
IMUnitTestRunner = _Class("IMUnitTestRunner")
IMCTSubscriptionUtilities = _Class("IMCTSubscriptionUtilities")
IMCTXPCServiceSubscriptionInfo = _Class("IMCTXPCServiceSubscriptionInfo")
IMNicknameAvatar = _Class("IMNicknameAvatar")
IMNicknameAvatarImage = _Class("IMNicknameAvatarImage")
IMSandboxingUtils = _Class("IMSandboxingUtils")
IMIDSUtilities = _Class("IMIDSUtilities")
IMBagUtilities = _Class("IMBagUtilities")
IMEventNotificationQueue = _Class("IMEventNotificationQueue")
IMEventNotificationBroadcaster = _Class("IMEventNotificationBroadcaster")
IMAutomaticEventNotificationQueue = _Class("IMAutomaticEventNotificationQueue")
IMRequirementLogger = _Class("IMRequirementLogger")
IMKeyValueCollectionUserDefaultsStorage = _Class(
    "IMKeyValueCollectionUserDefaultsStorage"
)
IMSyndicationHelper = _Class("IMSyndicationHelper")
IMEventNotificationManager = _Class("IMEventNotificationManager")
IMBatteryStatus = _Class("IMBatteryStatus")
IMDeviceUtilities = _Class("IMDeviceUtilities")
IMDeleteActionHelper = _Class("IMDeleteActionHelper")
IMLogDump = _Class("IMLogDump")
IMAttachmentBlastdoor = _Class("IMAttachmentBlastdoor")
IMUnitTestBundleLoader = _Class("IMUnitTestBundleLoader")
IMAttachmentUtilities = _Class("IMAttachmentUtilities")
IMMeCardSharingStateController = _Class("IMMeCardSharingStateController")
IMDContactStoreChangeHistoryEventsHandler = _Class(
    "IMDContactStoreChangeHistoryEventsHandler"
)
IMMessageAcknowledgmentStringHelper = _Class("IMMessageAcknowledgmentStringHelper")
IMNickname = _Class("IMNickname")
IMRuntimeTestRun = _Class("IMRuntimeTestRun")
IMRuntimeTestSuiteTestRun = _Class("IMRuntimeTestSuiteTestRun")
IMPreviewGenerator = _Class("IMPreviewGenerator")
IMAnimatedImagePreviewGenerator = _Class("IMAnimatedImagePreviewGenerator")
IMImagePreviewGenerator = _Class("IMImagePreviewGenerator")
IMContactCardPreviewGenerator = _Class("IMContactCardPreviewGenerator")
IMMapPreviewGenerator = _Class("IMMapPreviewGenerator")
IMPassKitPreviewGenerator = _Class("IMPassKitPreviewGenerator")
IMWatchfacePreviewGenerator = _Class("IMWatchfacePreviewGenerator")
IMMoviePreviewGenerator = _Class("IMMoviePreviewGenerator")
IMPowerWifiUsageCollector = _Class("IMPowerWifiUsageCollector")
IMImageSource = _Class("IMImageSource")
IMGIFUtils = _Class("IMGIFUtils")
IMItem = _Class("IMItem")
IMMessageActionItem = _Class("IMMessageActionItem")
IMParticipantChangeItem = _Class("IMParticipantChangeItem")
IMGroupTitleChangeItem = _Class("IMGroupTitleChangeItem")
IMLocationShareStatusChangeItem = _Class("IMLocationShareStatusChangeItem")
IMMessageItem = _Class("IMMessageItem")
IMAssociatedMessageItem = _Class("IMAssociatedMessageItem")
FZMessage = _Class("FZMessage")
IMGroupActionItem = _Class("IMGroupActionItem")
IMTUConversationItem = _Class("IMTUConversationItem")
IMAttributedStringParserContext = _Class("IMAttributedStringParserContext")
IMFromSuperParserContext = _Class("IMFromSuperParserContext")
IMSuperToSuperSanitizerContext = _Class("IMSuperToSuperSanitizerContext")
IMSuperToPlainParserContext = _Class("IMSuperToPlainParserContext")
IMNicknameEncryptionPreKey = _Class("IMNicknameEncryptionPreKey")
IMNicknameEncryptionKey = _Class("IMNicknameEncryptionKey")
IMNicknameRecordTaggingKey = _Class("IMNicknameRecordTaggingKey")
IMNicknameFieldTaggingKey = _Class("IMNicknameFieldTaggingKey")
IMNicknameFieldEncryptionKey = _Class("IMNicknameFieldEncryptionKey")
IMNicknameEncryptionCipherRecordField = _Class("IMNicknameEncryptionCipherRecordField")
IMNicknameEncryptionPlainRecordField = _Class("IMNicknameEncryptionPlainRecordField")
IMNicknameEncryptionHelpers = _Class("IMNicknameEncryptionHelpers")
IMContactStoreChangeHistoryEventsHandler = _Class(
    "IMContactStoreChangeHistoryEventsHandler"
)
IMNicknameEncryptionTag = _Class("IMNicknameEncryptionTag")
IMNicknameEncryptionRecordTag = _Class("IMNicknameEncryptionRecordTag")
IMNicknameEncryptionFieldTag = _Class("IMNicknameEncryptionFieldTag")
IMUnitTestLogger = _Class("IMUnitTestLogger")
IMPowerLog = _Class("IMPowerLog")
IMINInteractionUtilities = _Class("IMINInteractionUtilities")
IMEventListenerList = _Class("IMEventListenerList")
IMEventListenerReference = _Class("IMEventListenerReference")
IMEventListener = _Class("IMEventListener")
IMNotificationCenterEventListener = _Class("IMNotificationCenterEventListener")
IMEventListenerResponse = _Class("IMEventListenerResponse")
IMDefaults = _Class("IMDefaults")
IMEventNotification = _Class("IMEventNotification")
IMSharedUtilitiesProtoCloudKitEncryptedMessageP2 = _Class(
    "IMSharedUtilitiesProtoCloudKitEncryptedMessageP2"
)
IMSharedUtilitiesProtoCloudKitEncryptedGroupAction = _Class(
    "IMSharedUtilitiesProtoCloudKitEncryptedGroupAction"
)
IMSharedUtilitiesProtoCloudKitEncryptedGroupTitleChange = _Class(
    "IMSharedUtilitiesProtoCloudKitEncryptedGroupTitleChange"
)
IMSharedUtilitiesProtoCloudKitEncryptedParticipantChange = _Class(
    "IMSharedUtilitiesProtoCloudKitEncryptedParticipantChange"
)
IMSharedUtilitiesProtoCloudKitEncryptedMessageAction = _Class(
    "IMSharedUtilitiesProtoCloudKitEncryptedMessageAction"
)
IMSharedUtilitiesProtoCloudKitEncryptedLocationShareStatusChange = _Class(
    "IMSharedUtilitiesProtoCloudKitEncryptedLocationShareStatusChange"
)
IMSharedUtilitiesProtoCloudKitEncryptedMessage = _Class(
    "IMSharedUtilitiesProtoCloudKitEncryptedMessage"
)
