"""
Classes from the 'TelephonyUtilities' framework.
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


TUConversationManagerXPCClient = _Class("TUConversationManagerXPCClient")
TUMomentsProvider = _Class("TUMomentsProvider")
TUCallHistoryManager = _Class("TUCallHistoryManager")
TUCallCenter = _Class("TUCallCenter")
TUICFInterface = _Class("TUICFInterface")
TUICFQueryResult = _Class("TUICFQueryResult")
TUMomentsControllerXPCClient = _Class("TUMomentsControllerXPCClient")
TUCallServicesClientCapabilities = _Class("TUCallServicesClientCapabilities")
TUContactsDataProviderFetchRequest = _Class("TUContactsDataProviderFetchRequest")
TUCallHistoryManagerXPCClient = _Class("TUCallHistoryManagerXPCClient")
TUContactsAutocompleteSearchModule = _Class("TUContactsAutocompleteSearchModule")
TUSenderIdentityCapabilitiesState = _Class("TUSenderIdentityCapabilitiesState")
TUDialRequest = _Class("TUDialRequest")
TUHandle = _Class("TUHandle")
TUCall = _Class("TUCall")
TUProxyCall = _Class("TUProxyCall")
TUCallProvider = _Class("TUCallProvider")
TUSenderIdentity = _Class("TUSenderIdentity")
TUAutocompleteResultPartitioner = _Class("TUAutocompleteResultPartitioner")
TUSearchModuleManager = _Class("TUSearchModuleManager")
TUVideoDeviceControllerProvider = _Class("TUVideoDeviceControllerProvider")
TUPhoneNumber = _Class("TUPhoneNumber")
TUPrivacyRule = _Class("TUPrivacyRule")
TUPrivacyManager = _Class("TUPrivacyManager")
TUCloudCallingDevice = _Class("TUCloudCallingDevice")
TUConversationManager = _Class("TUConversationManager")
TUCallNotificationManager = _Class("TUCallNotificationManager")
TUMetadataCache = _Class("TUMetadataCache")
TUCallProviderManager = _Class("TUCallProviderManager")
TUCallGroup = _Class("TUCallGroup")
TUCallCapabilitiesState = _Class("TUCallCapabilitiesState")
TUSandboxExtendedURL = _Class("TUSandboxExtendedURL")
TUCallSoundPlayerDescriptor = _Class("TUCallSoundPlayerDescriptor")
TUCallSoundPlayer = _Class("TUCallSoundPlayer")
TUAudioFrequencyController = _Class("TUAudioFrequencyController")
TUAudioRouteCollectionKey = _Class("TUAudioRouteCollectionKey")
TUReportingControllerXPCClient = _Class("TUReportingControllerXPCClient")
TUCTCapabilityInfo = _Class("TUCTCapabilityInfo")
TUSearchController = _Class("TUSearchController")
TUCoreTelephonyClient = _Class("TUCoreTelephonyClient")
TUIDSLookupManager = _Class("TUIDSLookupManager")
TUMetadataDestinationID = _Class("TUMetadataDestinationID")
TUMetadataItem = _Class("TUMetadataItem")
TUCallServicesInterface = _Class("TUCallServicesInterface")
TUConversationParticipantPresentationContext = _Class(
    "TUConversationParticipantPresentationContext"
)
TUAdhocResult = _Class("TUAdhocResult")
TUReplyWithMessageStore = _Class("TUReplyWithMessageStore")
TUResultGroup = _Class("TUResultGroup")
TULabeledHandle = _Class("TULabeledHandle")
TUConversationMediaController = _Class("TUConversationMediaController")
TULogging = _Class("TULogging")
TUCallModel = _Class("TUCallModel")
TUGeoLocationMetadataWorker = _Class("TUGeoLocationMetadataWorker")
TUFeatureFlags = _Class("TUFeatureFlags")
TUCallFilterController = _Class("TUCallFilterController")
TUCallDisplayContext = _Class("TUCallDisplayContext")
TUMutableCallDisplayContext = _Class("TUMutableCallDisplayContext")
TUDynamicCallDisplayContext = _Class("TUDynamicCallDisplayContext")
TUCallProviderManagerXPCClient = _Class("TUCallProviderManagerXPCClient")
TURemoteVideoClient = _Class("TURemoteVideoClient")
TUGroupTitle = _Class("TUGroupTitle")
TUMetadataClientController = _Class("TUMetadataClientController")
TUAnswerRequest = _Class("TUAnswerRequest")
TUMomentDescriptor = _Class("TUMomentDescriptor")
TUJoinConversationRequest = _Class("TUJoinConversationRequest")
TUContactsDataProvider = _Class("TUContactsDataProvider")
TUContactsDataProviderResult = _Class("TUContactsDataProviderResult")
TUNotifyObserver = _Class("TUNotifyObserver")
TUConversationMember = _Class("TUConversationMember")
TUCallCapabilitiesXPCClient = _Class("TUCallCapabilitiesXPCClient")
TUCallContainer = _Class("TUCallContainer")
TUMutableCallContainer = _Class("TUMutableCallContainer")
TUConversation = _Class("TUConversation")
TUProxyAutocompleteResult = _Class("TUProxyAutocompleteResult")
TURoute = _Class("TURoute")
TUAudioRoute = _Class("TUAudioRoute")
TUMutableRoute = _Class("TUMutableRoute")
TUProxyRecentCall = _Class("TUProxyRecentCall")
TUVideoCallAttributes = _Class("TUVideoCallAttributes")
TUConversationParticipant = _Class("TUConversationParticipant")
TUMutableConversationParticipant = _Class("TUMutableConversationParticipant")
TUAudioDeviceController = _Class("TUAudioDeviceController")
TUContactsDataProviderAppleCareHandles = _Class(
    "TUContactsDataProviderAppleCareHandles"
)
TUSoundPlayer = _Class("TUSoundPlayer")
TUMomentsController = _Class("TUMomentsController")
TUSenderIdentityClient = _Class("TUSenderIdentityClient")
TUCallCapabilities = _Class("TUCallCapabilities")
TUCallHistoryController = _Class("TUCallHistoryController")
TUDiscoverabilitySignal = _Class("TUDiscoverabilitySignal")
TURepeatingAction = _Class("TURepeatingAction")
TURepeatingActor = _Class("TURepeatingActor")
TUVideoEffect = _Class("TUVideoEffect")
TUOptionalObject = _Class("TUOptionalObject")
TUDialAssist = _Class("TUDialAssist")
TUDTMFSoundPlayer = _Class("TUDTMFSoundPlayer")
TUUserNotificationProviderXPCClient = _Class("TUUserNotificationProviderXPCClient")
TUCallHistorySearchModule = _Class("TUCallHistorySearchModule")
TUVideoDeviceController = _Class("TUVideoDeviceController")
TUDispatcher = _Class("TUDispatcher")
TUCTCapabilitiesState = _Class("TUCTCapabilitiesState")
TUThumperCTCapabilitiesState = _Class("TUThumperCTCapabilitiesState")
TUSenderIdentityCapabilities = _Class("TUSenderIdentityCapabilities")
TUAudioController = _Class("TUAudioController")
TUAudioSystemController = _Class("TUAudioSystemController")
TUSearchResults = _Class("TUSearchResults")
TURecentsResults = _Class("TURecentsResults")
TUMetadataCacheDataProvider = _Class("TUMetadataCacheDataProvider")
TUMapsMetadataCacheDataProvider = _Class("TUMapsMetadataCacheDataProvider")
TUGeoLocationMetadataCacheDataProvider = _Class(
    "TUGeoLocationMetadataCacheDataProvider"
)
TUCallDirectoryMetadataCacheDataProvider = _Class(
    "TUCallDirectoryMetadataCacheDataProvider"
)
TUSuggestionsMetadataCacheDataProvider = _Class(
    "TUSuggestionsMetadataCacheDataProvider"
)
TUCarPlayHardwareControlsBroadcaster = _Class("TUCarPlayHardwareControlsBroadcaster")
TUMomentsCapabilities = _Class("TUMomentsCapabilities")
TURouteController = _Class("TURouteController")
