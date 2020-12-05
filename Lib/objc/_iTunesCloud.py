"""
Classes from the 'iTunesCloud' framework.
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


ICMusicAccountNotificationsSettingsResponse = _Class(
    "ICMusicAccountNotificationsSettingsResponse"
)
ICNetworkConstraints = _Class("ICNetworkConstraints")
ICMutableNetworkConstraints = _Class("ICMutableNetworkConstraints")
ICClientInfo = _Class("ICClientInfo")
ICMutableClientInfo = _Class("ICMutableClientInfo")
ICWiFiManager = _Class("ICWiFiManager")
ICMusicSubscriptionStatusTerms = _Class("ICMusicSubscriptionStatusTerms")
ICMusicSubscriptionStatus = _Class("ICMusicSubscriptionStatus")
ICMutableMusicSubscriptionStatus = _Class("ICMutableMusicSubscriptionStatus")
ICPlayActivityEventItemIDs = _Class("ICPlayActivityEventItemIDs")
ICMutablePlayActivityEventItemIDs = _Class("ICMutablePlayActivityEventItemIDs")
ICLocalStoreAccountProperties = _Class("ICLocalStoreAccountProperties")
ICMutableLocalStoreAccountProperties = _Class("ICMutableLocalStoreAccountProperties")
_ICUserCredentialProviderRequestSession = _Class(
    "_ICUserCredentialProviderRequestSession"
)
ICUserCredentialProvider = _Class("ICUserCredentialProvider")
ICADIProvisionSession = _Class("ICADIProvisionSession")
ICADIUtilities = _Class("ICADIUtilities")
ICEnvironmentMonitor = _Class("ICEnvironmentMonitor")
ICSecureKeyDeliveryRequest = _Class("ICSecureKeyDeliveryRequest")
ICMusicSubscriptionPlaybackResponse = _Class("ICMusicSubscriptionPlaybackResponse")
ICMusicSubscriptionFairPlayController = _Class("ICMusicSubscriptionFairPlayController")
ICURLBagLibraryDAAPConfiguration = _Class("ICURLBagLibraryDAAPConfiguration")
ICSQLiteConnection = _Class("ICSQLiteConnection")
ICDelegationProviderNetService = _Class("ICDelegationProviderNetService")
ICStorePlatformOffer = _Class("ICStorePlatformOffer")
ICStoreVideoArtworkInfo = _Class("ICStoreVideoArtworkInfo")
ICMachineDataActionHandler = _Class("ICMachineDataActionHandler")
ICUserIdentityStore = _Class("ICUserIdentityStore")
ICMusicAccountNotificationsSettingsSwitch = _Class(
    "ICMusicAccountNotificationsSettingsSwitch"
)
ICHTTPCookieStore = _Class("ICHTTPCookieStore")
ICSuzeLeaseSessionConfiguration = _Class("ICSuzeLeaseSessionConfiguration")
ICDelegateAccountStoreReader = _Class("ICDelegateAccountStoreReader")
ICMusicSubscriptionStatusMonitor = _Class("ICMusicSubscriptionStatusMonitor")
ICUserVerificationRequest = _Class("ICUserVerificationRequest")
ICMusicSubscriptionStatusRemoteRequesting = _Class(
    "ICMusicSubscriptionStatusRemoteRequesting"
)
ICDelegateAccountStoreSchema = _Class("ICDelegateAccountStoreSchema")
ICDAAPPropertyInfo = _Class("ICDAAPPropertyInfo")
_ICMusicSubscriptionLeaseIdentityCacheKey = _Class(
    "_ICMusicSubscriptionLeaseIdentityCacheKey"
)
ICMusicSubscriptionLeaseController = _Class("ICMusicSubscriptionLeaseController")
ICSecurityInfo = _Class("ICSecurityInfo")
ICDelegateAccountStoreSQLWriter = _Class("ICDelegateAccountStoreSQLWriter")
ICRadioStationMetadata = _Class("ICRadioStationMetadata")
ICDelegationProviderServiceProtocolHandler = _Class(
    "ICDelegationProviderServiceProtocolHandler"
)
ICURLBag = _Class("ICURLBag")
ICTelephonyController = _Class("ICTelephonyController")
ICSecureKeyDeliveryResponse = _Class("ICSecureKeyDeliveryResponse")
ICInAppMessageEventEntry = _Class("ICInAppMessageEventEntry")
ICStorePlatformResponse = _Class("ICStorePlatformResponse")
ICDelegationConsumerServiceSession = _Class("ICDelegationConsumerServiceSession")
ICMusicSubscriptionStatusController = _Class("ICMusicSubscriptionStatusController")
ICStoreDialogResponseButtonAction = _Class("ICStoreDialogResponseButtonAction")
ICStoreDialogResponseButton = _Class("ICStoreDialogResponseButton")
ICStoreDialogResponse = _Class("ICStoreDialogResponse")
ICDelegationNetServiceTXTRecord = _Class("ICDelegationNetServiceTXTRecord")
ICDelegationServiceSecuritySettings = _Class("ICDelegationServiceSecuritySettings")
ICRemoteRequestOperationExecuting = _Class("ICRemoteRequestOperationExecuting")
ICUserIdentityContext = _Class("ICUserIdentityContext")
ICDelegationPlayInfoResponseToken = _Class("ICDelegationPlayInfoResponseToken")
ICURLResponseAuthenticationProvider = _Class("ICURLResponseAuthenticationProvider")
ICStoreURLResponseAuthenticationProvider = _Class(
    "ICStoreURLResponseAuthenticationProvider"
)
ICDelegationProviderServiceSession = _Class("ICDelegationProviderServiceSession")
ICMusicUserTokenCache = _Class("ICMusicUserTokenCache")
ICCloudAvailabilityController = _Class("ICCloudAvailabilityController")
ICCloudContentTasteRequestListener = _Class("ICCloudContentTasteRequestListener")
ICCloudServiceStatusMonitor = _Class("ICCloudServiceStatusMonitor")
ICSQLiteQueryResults = _Class("ICSQLiteQueryResults")
ICStorePlatformResponseGroup = _Class("ICStorePlatformResponseGroup")
ICUserNotificationManager = _Class("ICUserNotificationManager")
ICUserNotificationContext = _Class("ICUserNotificationContext")
ICPlayActivityEnqueuerProperties = _Class("ICPlayActivityEnqueuerProperties")
ICMutablePlayActivityEnqueuerProperties = _Class(
    "ICMutablePlayActivityEnqueuerProperties"
)
ICDelegationProviderServiceAssertion = _Class("ICDelegationProviderServiceAssertion")
ICRadioPlaybackHistoryItem = _Class("ICRadioPlaybackHistoryItem")
ICMutableRadioPlaybackHistoryItem = _Class("ICMutableRadioPlaybackHistoryItem")
ICDefaults = _Class("ICDefaults")
ICDelegationPlayInfoTokenRequest = _Class("ICDelegationPlayInfoTokenRequest")
ICDelegationPlayInfoRequest = _Class("ICDelegationPlayInfoRequest")
ICSuzeLeaseResponse = _Class("ICSuzeLeaseResponse")
ICInAppMessageStore = _Class("ICInAppMessageStore")
ICPushNotificationsResponse = _Class("ICPushNotificationsResponse")
ICMediaAVAssetDownloadOptions = _Class("ICMediaAVAssetDownloadOptions")
ICCloudClientAvailabilityService = _Class("ICCloudClientAvailabilityService")
ICKeyedSharedInstanceManager = _Class("ICKeyedSharedInstanceManager")
ICMusicSubscriptionLeaseSession = _Class("ICMusicSubscriptionLeaseSession")
ICStoreHLSAssetInfo = _Class("ICStoreHLSAssetInfo")
ICUserCredentialRequest = _Class("ICUserCredentialRequest")
ICPrivacyInfo = _Class("ICPrivacyInfo")
ICSQLitePreparedStatement = _Class("ICSQLitePreparedStatement")
ICLibraryAuthServiceClientTokenProvider = _Class(
    "ICLibraryAuthServiceClientTokenProvider"
)
ICAuthorizeMachineRequest = _Class("ICAuthorizeMachineRequest")
ICURLResponseHandler = _Class("ICURLResponseHandler")
ICStoreURLResponseHandler = _Class("ICStoreURLResponseHandler")
ICMusicKitURLResponseHandler = _Class("ICMusicKitURLResponseHandler")
ICAddToWishListResponse = _Class("ICAddToWishListResponse")
ICDelegationConsumerServiceSessionRequestResult = _Class(
    "ICDelegationConsumerServiceSessionRequestResult"
)
ICRadioLikeRequest = _Class("ICRadioLikeRequest")
ICBook = _Class("ICBook")
ICURLBagMonitor = _Class("ICURLBagMonitor")
ICDelegationServicePairingSession = _Class("ICDelegationServicePairingSession")
ICPlayActivityEventContainerIDs = _Class("ICPlayActivityEventContainerIDs")
ICMutablePlayActivityEventContainerIDs = _Class(
    "ICMutablePlayActivityEventContainerIDs"
)
ICSuzeLeaseRequest = _Class("ICSuzeLeaseRequest")
ICCloudServerListenerEndpointProvider = _Class("ICCloudServerListenerEndpointProvider")
ICRadioGetTracksRequest = _Class("ICRadioGetTracksRequest")
ICSQLiteRow = _Class("ICSQLiteRow")
ICRemoteRequestOperationExecutionContext = _Class(
    "ICRemoteRequestOperationExecutionContext"
)
ICURLResponse = _Class("ICURLResponse")
ICMusicKitURLResponse = _Class("ICMusicKitURLResponse")
ICMusicSubscriptionStatusCacheKey = _Class("ICMusicSubscriptionStatusCacheKey")
ICPlayActivityEvent = _Class("ICPlayActivityEvent")
ICMutablePlayActivityEvent = _Class("ICMutablePlayActivityEvent")
ICMusicSubscriptionFairPlayKeyStatus = _Class("ICMusicSubscriptionFairPlayKeyStatus")
ICPlayActivityTable = _Class("ICPlayActivityTable")
ICMusicSubscriptionStatusRequest = _Class("ICMusicSubscriptionStatusRequest")
ICDelegateAccountStoreXPCWriter = _Class("ICDelegateAccountStoreXPCWriter")
ICMusicSubscriptionLeasePlaybackRequest = _Class(
    "ICMusicSubscriptionLeasePlaybackRequest"
)
ICCloudAddReferral = _Class("ICCloudAddReferral")
_ICDelegationServiceConnectionPendingRequestContext = _Class(
    "_ICDelegationServiceConnectionPendingRequestContext"
)
ICDelegationServiceConnection = _Class("ICDelegationServiceConnection")
ICRadioStationTrack = _Class("ICRadioStationTrack")
ICMusicAccountNotificationsSettingsManager = _Class(
    "ICMusicAccountNotificationsSettingsManager"
)
ICInAppMessageConfiguration = _Class("ICInAppMessageConfiguration")
ICDispatchOnce = _Class("ICDispatchOnce")
ICMediaRedownloadResponse = _Class("ICMediaRedownloadResponse")
ICDeviceSetupStatusMonitor = _Class("ICDeviceSetupStatusMonitor")
ICStoreDialogResponseHandlerConfiguration = _Class(
    "ICStoreDialogResponseHandlerConfiguration"
)
ICStoreDialogResponseHandler = _Class("ICStoreDialogResponseHandler")
ICStoreRadioStreamAssetInfo = _Class("ICStoreRadioStreamAssetInfo")
ICFPStreamContext = _Class("ICFPStreamContext")
_ICValueHistoryItem = _Class("_ICValueHistoryItem")
ICValueHistory = _Class("ICValueHistory")
ICAgeVerificationState = _Class("ICAgeVerificationState")
ICRadioStationProviderResource = _Class("ICRadioStationProviderResource")
ICDelegationConsumerServiceRequest = _Class("ICDelegationConsumerServiceRequest")
ICDelegationConsumerService = _Class("ICDelegationConsumerService")
ICMusicRestoreRequestParameters = _Class("ICMusicRestoreRequestParameters")
ICUserIdentityStoreTestingBackend = _Class("ICUserIdentityStoreTestingBackend")
ICCloudItemIDList = _Class("ICCloudItemIDList")
ICURLRequest = _Class("ICURLRequest")
ICMusicKitURLRequest = _Class("ICMusicKitURLRequest")
ICStoreURLRequest = _Class("ICStoreURLRequest")
ICRadioURLRequest = _Class("ICRadioURLRequest")
ICMusicSubscriptionPlaybackURLRequest = _Class("ICMusicSubscriptionPlaybackURLRequest")
ICAuthorizeMachineURLRequest = _Class("ICAuthorizeMachineURLRequest")
ICRadioResponse = _Class("ICRadioResponse")
ICRadioGetTracksResponse = _Class("ICRadioGetTracksResponse")
ICRadioLikeResponse = _Class("ICRadioLikeResponse")
ICRadioFetchMetadataResponse = _Class("ICRadioFetchMetadataResponse")
ICSQLiteConnectionOptions = _Class("ICSQLiteConnectionOptions")
ICAgeVerifier = _Class("ICAgeVerifier")
ICURLBagRadioConfiguration = _Class("ICURLBagRadioConfiguration")
ICInAppMessageMetadataEntry = _Class("ICInAppMessageMetadataEntry")
ICDeviceInfo = _Class("ICDeviceInfo")
ICStoreFileAssetFairPlayInfo = _Class("ICStoreFileAssetFairPlayInfo")
ICStoreURLRequestBuilderProperties = _Class("ICStoreURLRequestBuilderProperties")
ICUserIdentityStoreCoding = _Class("ICUserIdentityStoreCoding")
ICSuzeLeaseSession = _Class("ICSuzeLeaseSession")
ICStoreArtworkInfo = _Class("ICStoreArtworkInfo")
ICStoreArtworkSizeInfo = _Class("ICStoreArtworkSizeInfo")
_ICPlayActivityFlushSessionInformation = _Class(
    "_ICPlayActivityFlushSessionInformation"
)
_ICPlayActivityEndpointRevisionInformation = _Class(
    "_ICPlayActivityEndpointRevisionInformation"
)
ICPlayActivityController = _Class("ICPlayActivityController")
ICRadioPlaybackHistoryStore = _Class("ICRadioPlaybackHistoryStore")
ICFPContentInfo = _Class("ICFPContentInfo")
ICFPSAPContext = _Class("ICFPSAPContext")
ICDelegateAccountStoreServiceListener = _Class("ICDelegateAccountStoreServiceListener")
ICDelegationConsumerServiceSessionRequestInfo = _Class(
    "ICDelegationConsumerServiceSessionRequestInfo"
)
ICAMSBagAdapter = _Class("ICAMSBagAdapter")
ICInAppMessageEntry = _Class("ICInAppMessageEntry")
ICURLSession = _Class("ICURLSession")
ICStorePlatformMetadata = _Class("ICStorePlatformMetadata")
ICUserNotificationBuilder = _Class("ICUserNotificationBuilder")
ICStorePlatformRequest = _Class("ICStorePlatformRequest")
ICLibraryAuthServiceClientTokenStatus = _Class("ICLibraryAuthServiceClientTokenStatus")
ICMusicSubscriptionLeaseStatus = _Class("ICMusicSubscriptionLeaseStatus")
ICUserVerificationContext = _Class("ICUserVerificationContext")
ICConnectionConfiguration = _Class("ICConnectionConfiguration")
ICHTTPArchive = _Class("ICHTTPArchive")
ICUserIdentityProperties = _Class("ICUserIdentityProperties")
ICMutableUserIdentityProperties = _Class("ICMutableUserIdentityProperties")
ICUserIdentityStoreACAccountBackend = _Class("ICUserIdentityStoreACAccountBackend")
ICDelegationProviderService = _Class("ICDelegationProviderService")
ICLibraryAuthServiceBulkClientTokenResponse = _Class(
    "ICLibraryAuthServiceBulkClientTokenResponse"
)
ICNanoPairedDeviceStatusMonitor = _Class("ICNanoPairedDeviceStatusMonitor")
ICUserAuthenticationValidationRequest = _Class("ICUserAuthenticationValidationRequest")
ICFPLeaseSyncSession = _Class("ICFPLeaseSyncSession")
ICUserCredentialResponse = _Class("ICUserCredentialResponse")
ICStorageManager = _Class("ICStorageManager")
ICDelegateAccountStore = _Class("ICDelegateAccountStore")
ICURLBagMescalConfiguration = _Class("ICURLBagMescalConfiguration")
ICStorePlatformOfferAsset = _Class("ICStorePlatformOfferAsset")
ICMusicSubscriptionPlaybackResponseItem = _Class(
    "ICMusicSubscriptionPlaybackResponseItem"
)
ICDelegationConsumerServiceProtocolHandler = _Class(
    "ICDelegationConsumerServiceProtocolHandler"
)
ICMusicSubscriptionAccountlessPlaybackRequest = _Class(
    "ICMusicSubscriptionAccountlessPlaybackRequest"
)
ICMusicSubscriptionStatusResponse = _Class("ICMusicSubscriptionStatusResponse")
ICURLBagProvider = _Class("ICURLBagProvider")
ICUserIdentity = _Class("ICUserIdentity")
ICLibraryAuthServiceClientTokenIdentifier = _Class(
    "ICLibraryAuthServiceClientTokenIdentifier"
)
ICLibraryAuthServiceClientTokenResult = _Class("ICLibraryAuthServiceClientTokenResult")
ICLibraryAuthServiceClientTokenResponse = _Class(
    "ICLibraryAuthServiceClientTokenResponse"
)
ICCloudServiceStatusRemoteMonitoring = _Class("ICCloudServiceStatusRemoteMonitoring")
ICMusicRestoreBagConfiguration = _Class("ICMusicRestoreBagConfiguration")
ICRadioFetchMetadataRequest = _Class("ICRadioFetchMetadataRequest")
ICStoreMediaResponseItem = _Class("ICStoreMediaResponseItem")
ICDeveloperTokenDefaultProvider = _Class("ICDeveloperTokenDefaultProvider")
ICRemoteRequestOperationController = _Class("ICRemoteRequestOperationController")
ICCloudClient = _Class("ICCloudClient")
ICPushNotificationMessage = _Class("ICPushNotificationMessage")
ICURLSessionManager = _Class("ICURLSessionManager")
ICMediaAssetDownloadSessionCache = _Class("ICMediaAssetDownloadSessionCache")
ICDelegationConsumerNetService = _Class("ICDelegationConsumerNetService")
ICRemoteRequestOperationExecutionResponse = _Class(
    "ICRemoteRequestOperationExecutionResponse"
)
ICInAppMessageManager = _Class("ICInAppMessageManager")
ICAgeVerificationManager = _Class("ICAgeVerificationManager")
ICSQLiteStatement = _Class("ICSQLiteStatement")
ICRadioPlaybackHistory = _Class("ICRadioPlaybackHistory")
ICMutableRadioPlaybackHistory = _Class("ICMutableRadioPlaybackHistory")
ICMusicSubscriptionCarrierBundlingEligibilityResponse = _Class(
    "ICMusicSubscriptionCarrierBundlingEligibilityResponse"
)
ICStoreFinanceItemMetadata = _Class("ICStoreFinanceItemMetadata")
ICPlayActivityFeedSerialization = _Class("ICPlayActivityFeedSerialization")
ICStoreFileAssetInfo = _Class("ICStoreFileAssetInfo")
ICCloudClientCloudService = _Class("ICCloudClientCloudService")
ICRadioContentReference = _Class("ICRadioContentReference")
ICRadioLibraryTrackContentReference = _Class("ICRadioLibraryTrackContentReference")
ICRadioLibraryAlbumContentReference = _Class("ICRadioLibraryAlbumContentReference")
ICRadioStoreContentReference = _Class("ICRadioStoreContentReference")
ICRadioTrackInfoContentReference = _Class("ICRadioTrackInfoContentReference")
ICRadioLibraryArtistContentReference = _Class("ICRadioLibraryArtistContentReference")
ICAuthenticationUtilities = _Class("ICAuthenticationUtilities")
ICDelegateAccountStoreOptions = _Class("ICDelegateAccountStoreOptions")
ICRequestContext = _Class("ICRequestContext")
ICStoreRequestContext = _Class("ICStoreRequestContext")
ICMusicKitRequestContext = _Class("ICMusicKitRequestContext")
ICSAPSession = _Class("ICSAPSession")
ICAuthorizeMachineResponse = _Class("ICAuthorizeMachineResponse")
ICDelegateToken = _Class("ICDelegateToken")
ICUnfairLock = _Class("ICUnfairLock")
ICJSSignConfiguration = _Class("ICJSSignConfiguration")
ICJSSign = _Class("ICJSSign")
ICMusicSubscriptionStatusCache = _Class("ICMusicSubscriptionStatusCache")
ICAMSBagValuePromise = _Class("ICAMSBagValuePromise")
ICIAMSerialCheckResponse = _Class("ICIAMSerialCheckResponse")
ICPBDGSPlayerInfoContextRequestToken = _Class("ICPBDGSPlayerInfoContextRequestToken")
ICIAMParameter = _Class("ICIAMParameter")
ICPBDGSMessage = _Class("ICPBDGSMessage")
ICPBDGSFinishDelegationResponse = _Class("ICPBDGSFinishDelegationResponse")
ICIAMLogEventResponse = _Class("ICIAMLogEventResponse")
ICCloudContentTastePBFuseItemPreference = _Class(
    "ICCloudContentTastePBFuseItemPreference"
)
ICPBDGSPlayerInfoContextToken = _Class("ICPBDGSPlayerInfoContextToken")
ICPBDGSResponse = _Class("ICPBDGSResponse")
ICPBDGSStartDelegationResponse = _Class("ICPBDGSStartDelegationResponse")
ICPAPlayActivityEvent = _Class("ICPAPlayActivityEvent")
ICPAPlayActivityEnqueuerProperties = _Class("ICPAPlayActivityEnqueuerProperties")
ICIAMMessageRule = _Class("ICIAMMessageRule")
ICIAMMessageContent = _Class("ICIAMMessageContent")
ICIAMMessageAction = _Class("ICIAMMessageAction")
ICCloudContentTastePBFusePreferences = _Class("ICCloudContentTastePBFusePreferences")
ICPAPlayModeDictionary = _Class("ICPAPlayModeDictionary")
ICIAMApplicationMessageSyncResponse = _Class("ICIAMApplicationMessageSyncResponse")
ICIAMLocalNotification = _Class("ICIAMLocalNotification")
ICIAMMetricEvent = _Class("ICIAMMetricEvent")
ICIAMMessagePresentationTrigger = _Class("ICIAMMessagePresentationTrigger")
ICIAMImage = _Class("ICIAMImage")
ICIAMTriggerCondition = _Class("ICIAMTriggerCondition")
ICIAMSynchronizeMessagesResponse = _Class("ICIAMSynchronizeMessagesResponse")
ICIAMApplicationMessageSyncCommand = _Class("ICIAMApplicationMessageSyncCommand")
ICPBDGSPlayerDelegateInfoToken = _Class("ICPBDGSPlayerDelegateInfoToken")
ICIAMApplicationMessage = _Class("ICIAMApplicationMessage")
ICIAMImpressionNode = _Class("ICIAMImpressionNode")
ICIAMSynchronizeMessagesRequest = _Class("ICIAMSynchronizeMessagesRequest")
ICPBDGSRequest = _Class("ICPBDGSRequest")
ICPBDGSFinishDelegationRequest = _Class("ICPBDGSFinishDelegationRequest")
ICPBDGSStartDelegationRequest = _Class("ICPBDGSStartDelegationRequest")
ICIAMLogEventRequest = _Class("ICIAMLogEventRequest")
ICIAMSerialCheckRequest = _Class("ICIAMSerialCheckRequest")
ICPlayActivityDebugLogOperation = _Class("ICPlayActivityDebugLogOperation")
ICAsyncOperation = _Class("ICAsyncOperation")
ICSecureKeyDeliveryRequestOperation = _Class("ICSecureKeyDeliveryRequestOperation")
ICDelegationPlayInfoRequestOperation = _Class("ICDelegationPlayInfoRequestOperation")
ICSAPSessionPrepareFairPlayContextOperation = _Class(
    "ICSAPSessionPrepareFairPlayContextOperation"
)
ICUserVerificationOperation = _Class("ICUserVerificationOperation")
ICACAccountVerificationOperation = _Class("ICACAccountVerificationOperation")
ICMusicSubscriptionCarrierBundlingEligibilityOperation = _Class(
    "ICMusicSubscriptionCarrierBundlingEligibilityOperation"
)
ICFlushPlayActivityEventsOperation = _Class("ICFlushPlayActivityEventsOperation")
ICMusicSubscriptionStatusRequestOperation = _Class(
    "ICMusicSubscriptionStatusRequestOperation"
)
ICMusicSubscriptionPlaybackRequestOperation = _Class(
    "ICMusicSubscriptionPlaybackRequestOperation"
)
ICAsyncBlockOperation = _Class("ICAsyncBlockOperation")
ICMachineDataOperation = _Class("ICMachineDataOperation")
ICMachineDataEraseOperation = _Class("ICMachineDataEraseOperation")
ICMachineDataSyncOperation = _Class("ICMachineDataSyncOperation")
ICMachineDataProvisionOperation = _Class("ICMachineDataProvisionOperation")
ICStorePlatformRequestOperation = _Class("ICStorePlatformRequestOperation")
ICSAPSessionAbstractOperation = _Class("ICSAPSessionAbstractOperation")
ICSAPSessionVerifySignatureOperation = _Class("ICSAPSessionVerifySignatureOperation")
ICSAPSessionSignDataOperation = _Class("ICSAPSessionSignDataOperation")
ICRequestOperation = _Class("ICRequestOperation")
ICPushNotificationsEnableTypesRequest = _Class("ICPushNotificationsEnableTypesRequest")
ICSongDownloadDoneRequest = _Class("ICSongDownloadDoneRequest")
ICSagaGetAccountStatusRequest = _Class("ICSagaGetAccountStatusRequest")
ICInAppMessageSyncRequest = _Class("ICInAppMessageSyncRequest")
ICBuyProductRequest = _Class("ICBuyProductRequest")
ICSetParentalControlRequestOperation = _Class("ICSetParentalControlRequestOperation")
ICAddToWishListRequest = _Class("ICAddToWishListRequest")
ICRemoveMediaDRMOperation = _Class("ICRemoveMediaDRMOperation")
ICInAppReportEventRequest = _Class("ICInAppReportEventRequest")
ICMusicAccountNotificationsSettingsRequestOperation = _Class(
    "ICMusicAccountNotificationsSettingsRequestOperation"
)
ICRemoteRequestOperation = _Class("ICRemoteRequestOperation")
ICDeveloperTokenFetchRequest = _Class("ICDeveloperTokenFetchRequest")
ICMusicUserTokenFetchRequest = _Class("ICMusicUserTokenFetchRequest")
ICPushNotificationsDisableTypesRequest = _Class(
    "ICPushNotificationsDisableTypesRequest"
)
ICMusicRestoreRequest = _Class("ICMusicRestoreRequest")
ICSiriAddToAccousticHistoryRequest = _Class("ICSiriAddToAccousticHistoryRequest")
ICPushNotificationsRegisterAPNSTokenRequest = _Class(
    "ICPushNotificationsRegisterAPNSTokenRequest"
)
ICMusicSubscriptionRecommendationsRequest = _Class(
    "ICMusicSubscriptionRecommendationsRequest"
)
ICLibraryAuthServiceBulkClientTokenRequest = _Class(
    "ICLibraryAuthServiceBulkClientTokenRequest"
)
ICLibraryAuthServiceClientTokenRequest = _Class(
    "ICLibraryAuthServiceClientTokenRequest"
)
ICMediaAssetDownloadRequest = _Class("ICMediaAssetDownloadRequest")
ICMediaRedownloadRequest = _Class("ICMediaRedownloadRequest")
ICMatchRedownloadRequest = _Class("ICMatchRedownloadRequest")
ICPurchaseRedownloadRequest = _Class("ICPurchaseRedownloadRequest")
ICSubscriptionRedownloadRequest = _Class("ICSubscriptionRedownloadRequest")
ICMusicSubscriptionRequest = _Class("ICMusicSubscriptionRequest")
