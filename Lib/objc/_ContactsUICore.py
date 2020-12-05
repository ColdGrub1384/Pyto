"""
Classes from the 'ContactsUICore' framework.
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


_CNUILocalPhotoFuture = _Class("_CNUILocalPhotoFuture")
_CNUICachingLikenessRenderer = _Class("_CNUICachingLikenessRenderer")
CNMCProfileConnection = _Class("CNMCProfileConnection")
CNUIDefaultUserActionFetcher = _Class("CNUIDefaultUserActionFetcher")
CNUICoreFamilyMemberContactItem = _Class("CNUICoreFamilyMemberContactItem")
CNUIUserActionItemComparator = _Class("CNUIUserActionItemComparator")
CNUIUserActionRanking = _Class("CNUIUserActionRanking")
CNUIImageProvider = _Class("CNUIImageProvider")
CNUICoreProposedContactsFetchingDecorator = _Class(
    "CNUICoreProposedContactsFetchingDecorator"
)
CNUIPlaceholderProviderFactory = _Class("CNUIPlaceholderProviderFactory")
_CNUIUserActionCurator = _Class("_CNUIUserActionCurator")
CNUIUserActionItemList = _Class("CNUIUserActionItemList")
CNUIPRLikenessPhotoProvider = _Class("CNUIPRLikenessPhotoProvider")
CNHandle = _Class("CNHandle")
CNUIPRLikenessProvider = _Class("CNUIPRLikenessProvider")
CNUICoreContactNoteValueFilter = _Class("CNUICoreContactNoteValueFilter")
CNUIAvatarLayoutManager = _Class("CNUIAvatarLayoutManager")
CNUIAvatarLayoutLayerItem = _Class("CNUIAvatarLayoutLayerItem")
CNUIAvatarLayoutItemConfiguration = _Class("CNUIAvatarLayoutItemConfiguration")
CNUICoreFamilyInfo = _Class("CNUICoreFamilyInfo")
CNUIIDSIDQueryControllerWrapper = _Class("CNUIIDSIDQueryControllerWrapper")
CNUICoreContactPhotoValueFilter = _Class("CNUICoreContactPhotoValueFilter")
CNUICoreContactManagementConsentInspector = _Class(
    "CNUICoreContactManagementConsentInspector"
)
CNUICoreMainWhitelistedContactsController = _Class(
    "CNUICoreMainWhitelistedContactsController"
)
CNUIApplicationLaunchOptions = _Class("CNUIApplicationLaunchOptions")
CNTUCallProvider = _Class("CNTUCallProvider")
CNUICoreEditAuthorizationCheck = _Class("CNUICoreEditAuthorizationCheck")
CNUICoreContactNicknameValueFilter = _Class("CNUICoreContactNicknameValueFilter")
CNUIUserActionTargetDiscovering = _Class("CNUIUserActionTargetDiscovering")
CNUIPRLikenessLoadingPlaceholderProvider = _Class(
    "CNUIPRLikenessLoadingPlaceholderProvider"
)
CNUIPRLikenessLoadingGroupPlaceholderProvider = _Class(
    "CNUIPRLikenessLoadingGroupPlaceholderProvider"
)
CNUIUserActionDisambiguationModeler = _Class("CNUIUserActionDisambiguationModeler")
_CNUIGravatarPhotoFuture = _Class("_CNUIGravatarPhotoFuture")
_CNUIUserActionUserActivityOpener = _Class("_CNUIUserActionUserActivityOpener")
CNUICoreContactTypeAssessor = _Class("CNUICoreContactTypeAssessor")
CNUICoreScreentimePasscodeInspector = _Class("CNUICoreScreentimePasscodeInspector")
CNUIContactPropertyRanker = _Class("CNUIContactPropertyRanker")
CNUICoreFamilyMemberContactsController = _Class(
    "CNUICoreFamilyMemberContactsController"
)
CNUIUserActionWorkspaceURLOpener = _Class("CNUIUserActionWorkspaceURLOpener")
CNUIUserActionListModel = _Class("CNUIUserActionListModel")
CNTUCallProviderManagerDelegate = _Class("CNTUCallProviderManagerDelegate")
CNLSApplicationWorkspace = _Class("CNLSApplicationWorkspace")
CNUICoreFamilyElement = _Class("CNUICoreFamilyElement")
_CNUIUserActionImageProvider = _Class("_CNUIUserActionImageProvider")
CNUIPRLikenessPlaceholderProvider = _Class("CNUIPRLikenessPlaceholderProvider")
CNUIPRLikenessLookup = _Class("CNUIPRLikenessLookup")
CNTUCallProviderManager = _Class("CNTUCallProviderManager")
CNUICoreLogProvider = _Class("CNUICoreLogProvider")
CNUIInteractionDonor = _Class("CNUIInteractionDonor")
CNUICoreContactPropertyFilterBuilder = _Class("CNUICoreContactPropertyFilterBuilder")
CNUICoreContactStoreProductionFacade = _Class("CNUICoreContactStoreProductionFacade")
CNUICoreContactStoreTestFacade = _Class("CNUICoreContactStoreTestFacade")
CNUICoreContactRelationshipsFilter = _Class("CNUICoreContactRelationshipsFilter")
CNUIUserActionExtensionURLOpener = _Class("CNUIUserActionExtensionURLOpener")
CNUICoreFamilyInfoRetriever = _Class("CNUICoreFamilyInfoRetriever")
_CNUIDefaultUserActionRecorderEventFactory = _Class(
    "_CNUIDefaultUserActionRecorderEventFactory"
)
CNUIDefaultUserActionRecorder = _Class("CNUIDefaultUserActionRecorder")
CNUIIDSContactPropertyResolver = _Class("CNUIIDSContactPropertyResolver")
CNUIIDSAvailabilityProvider = _Class("CNUIIDSAvailabilityProvider")
CNUIUserActionDiscoveringEnvironment = _Class("CNUIUserActionDiscoveringEnvironment")
CNUILikenessRenderer = _Class("CNUILikenessRenderer")
CNCapabilities = _Class("CNCapabilities")
CNUICoreContactEditingSession = _Class("CNUICoreContactEditingSession")
CNUICoreFamilyMemberContactsModel = _Class("CNUICoreFamilyMemberContactsModel")
CNUICoreFamilyMemberContactsStore = _Class("CNUICoreFamilyMemberContactsStore")
CNUICoreFamilyMemberWhitelistedContactsController = _Class(
    "CNUICoreFamilyMemberWhitelistedContactsController"
)
CNUICoreContactPropertyValueFilterFactory = _Class(
    "CNUICoreContactPropertyValueFilterFactory"
)
CNUIUserActivityManager = _Class("CNUIUserActivityManager")
CNUIRemotePhotoFutures = _Class("CNUIRemotePhotoFutures")
CNUIUserActionListDataSource = _Class("CNUIUserActionListDataSource")
CNUIUserActionDisambiguationViewDataSource = _Class(
    "CNUIUserActionDisambiguationViewDataSource"
)
CNUICoreContactsSyncProductionTrigger = _Class("CNUICoreContactsSyncProductionTrigger")
CNUIContactPropertyIDSHandle = _Class("CNUIContactPropertyIDSHandle")
CNUICoreRecentsManager = _Class("CNUICoreRecentsManager")
CNUIPRLikenessResolver = _Class("CNUIPRLikenessResolver")
CNUIPRLikenessResolverOptions = _Class("CNUIPRLikenessResolverOptions")
CNUICoreContactFetchRequestAccumulator = _Class(
    "CNUICoreContactFetchRequestAccumulator"
)
CNUIMeContactComparisonStrategyUnified = _Class(
    "CNUIMeContactComparisonStrategyUnified"
)
CNUIMeContactComparisonStrategyIdentifier = _Class(
    "CNUIMeContactComparisonStrategyIdentifier"
)
CNUIMeContactMonitor = _Class("CNUIMeContactMonitor")
CNUICoreContactScratchpad = _Class("CNUICoreContactScratchpad")
CNUIPassKitWrapper = _Class("CNUIPassKitWrapper")
CNUICoreWhitelistedContactsControllerOptions = _Class(
    "CNUICoreWhitelistedContactsControllerOptions"
)
CNUIUserActivityRestorer = _Class("CNUIUserActivityRestorer")
CNUISnowglobeUtilities = _Class("CNUISnowglobeUtilities")
CNUIRenderedLikenessCacheEntry = _Class("CNUIRenderedLikenessCacheEntry")
CNUIUserActionDisambiguationModelFinalizer = _Class(
    "CNUIUserActionDisambiguationModelFinalizer"
)
CNUICoreFamilyMemberSaveRequestFactory = _Class(
    "CNUICoreFamilyMemberSaveRequestFactory"
)
_CNUIDirectoryServicesPhotoFuture = _Class("_CNUIDirectoryServicesPhotoFuture")
CNUIDowntimeLogger = _Class("CNUIDowntimeLogger")
CNUICoreFamilyMemberContactsModelRetriever = _Class(
    "CNUICoreFamilyMemberContactsModelRetriever"
)
CNUICoreContactEdit = _Class("CNUICoreContactEdit")
CNUICoreContactMatcher = _Class("CNUICoreContactMatcher")
CNUIUserActionItem = _Class("CNUIUserActionItem")
_CNUIUserActionDialRequestItem = _Class("_CNUIUserActionDialRequestItem")
_CNUIUserActionUserActivityItem = _Class("_CNUIUserActionUserActivityItem")
_CNUIUserActionURLItem = _Class("_CNUIUserActionURLItem")
CNUICoreFamilyMemberContactsModelBuilder = _Class(
    "CNUICoreFamilyMemberContactsModelBuilder"
)
CNUICoreInMemoryWhitelistedContactsDataSourceDecorator = _Class(
    "CNUICoreInMemoryWhitelistedContactsDataSourceDecorator"
)
CNUILibraryFolderDiscovery = _Class("CNUILibraryFolderDiscovery")
CNUICoreContactRefetcher = _Class("CNUICoreContactRefetcher")
CNUILikenessRenderingScope = _Class("CNUILikenessRenderingScope")
CNUIUserActionCacheKeyGenerator = _Class("CNUIUserActionCacheKeyGenerator")
CNUILikenessFingerprint = _Class("CNUILikenessFingerprint")
_CNUILikenessRenderer = _Class("_CNUILikenessRenderer")
_CNUIUserActionDialRequestOpener = _Class("_CNUIUserActionDialRequestOpener")
CNUIUserActionContext = _Class("CNUIUserActionContext")
CNUIUserActionTarget = _Class("CNUIUserActionTarget")
_CNUIUserActionSendMessageIntentTarget = _Class(
    "_CNUIUserActionSendMessageIntentTarget"
)
_CNUIUserActionDirectionsTarget = _Class("_CNUIUserActionDirectionsTarget")
_CNUIUserActionMessagesTextTarget = _Class("_CNUIUserActionMessagesTextTarget")
_CNUIUserActionSkypeVoiceTarget = _Class("_CNUIUserActionSkypeVoiceTarget")
_CNUIUserActionSkypeVideoTarget = _Class("_CNUIUserActionSkypeVideoTarget")
_CNUIUserActionCallProviderVideoTarget = _Class(
    "_CNUIUserActionCallProviderVideoTarget"
)
_CNUIUserActionSkypeTextTarget = _Class("_CNUIUserActionSkypeTextTarget")
_CNUIUserActionMailEmailTarget = _Class("_CNUIUserActionMailEmailTarget")
_CNUIUserActionFaceTimeVoiceTarget = _Class("_CNUIUserActionFaceTimeVoiceTarget")
_CNUIUserActionStartAudioCallIntentTarget = _Class(
    "_CNUIUserActionStartAudioCallIntentTarget"
)
_CNUIUserActionTelephonyVoiceTarget = _Class("_CNUIUserActionTelephonyVoiceTarget")
_CNUIUserActionFaceTimeVideoTarget = _Class("_CNUIUserActionFaceTimeVideoTarget")
_CNUIUserActionCallProviderVoiceTarget = _Class(
    "_CNUIUserActionCallProviderVoiceTarget"
)
_CNUIUserActionWalletPayTarget = _Class("_CNUIUserActionWalletPayTarget")
_CNUIUserActionStartVideoCallIntentTarget = _Class(
    "_CNUIUserActionStartVideoCallIntentTarget"
)
TestCNUIIDSHandleAvailability = _Class("TestCNUIIDSHandleAvailability")
CNUIRTTUtilities = _Class("CNUIRTTUtilities")
_CNUIRTTUtilities = _Class("_CNUIRTTUtilities")
CNContactsUIError = _Class("CNContactsUIError")
_CNUIIDSHandleAvailability = _Class("_CNUIIDSHandleAvailability")
CNUIIDSRequest = _Class("CNUIIDSRequest")
CNUICoreContactAggregateValueFilter = _Class("CNUICoreContactAggregateValueFilter")
CNUIDSHandleAvailabilityPromise = _Class("CNUIDSHandleAvailabilityPromise")
CNUIDHandleAvailabilityFuture = _Class("CNUIDHandleAvailabilityFuture")
CNUIUserActionTargetDiscoveringReplaySubjectPair = _Class(
    "CNUIUserActionTargetDiscoveringReplaySubjectPair"
)
CNUIUserActionTargetDiscoveryCache = _Class("CNUIUserActionTargetDiscoveryCache")
CNUIDSHandleAvailabilityCache = _Class("CNUIDSHandleAvailabilityCache")
CNUIDSIMessageHandleAvailabilityCache = _Class("CNUIDSIMessageHandleAvailabilityCache")
CNUIDSFaceTimeHandleAvailabilityCache = _Class("CNUIDSFaceTimeHandleAvailabilityCache")
CNUIUserActionListModelCache = _Class("CNUIUserActionListModelCache")
CNUIUserActionTargetDiscoveringObservableCancelationToken = _Class(
    "CNUIUserActionTargetDiscoveringObservableCancelationToken"
)
CNCallProvidersChangedCancelationToken = _Class(
    "CNCallProvidersChangedCancelationToken"
)
CNUIUserActionTargetDiscoveringReplaySubject = _Class(
    "CNUIUserActionTargetDiscoveringReplaySubject"
)
CNFirstRawActionsModelReplaySubject = _Class("CNFirstRawActionsModelReplaySubject")
CNDiscoveredUserActionReplaySubject = _Class("CNDiscoveredUserActionReplaySubject")
CNUICreateContactIntentResponse = _Class("CNUICreateContactIntentResponse")
CNUICreateContactIntent = _Class("CNUICreateContactIntent")
