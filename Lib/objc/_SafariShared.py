"""
Classes from the 'SafariShared' framework.
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


WBSAppleAccountInformationProvider = _Class("WBSAppleAccountInformationProvider")
WBSURLSuffixChecker = _Class("WBSURLSuffixChecker")
WBSURLCompletionUserTypedString = _Class("WBSURLCompletionUserTypedString")
WBSURLCompletionSessionProxy = _Class("WBSURLCompletionSessionProxy")
WBSURLCompletionMatchSnapshot = _Class("WBSURLCompletionMatchSnapshot")
WBSURLCompletionHistorySnapshot = _Class("WBSURLCompletionHistorySnapshot")
WBSURLCompletionDatabase = _Class("WBSURLCompletionDatabase")
WBSPasswordPickerHintStringGenerator = _Class("WBSPasswordPickerHintStringGenerator")
WBSPasswordPatternMatch = _Class("WBSPasswordPatternMatch")
WBSTabDialogManager = _Class("WBSTabDialogManager")
WBSTabDialogInformation = _Class("WBSTabDialogInformation")
WBSUserAgentQuirksManager = _Class("WBSUserAgentQuirksManager")
WBSUserMediaCapturePolicyEntry = _Class("WBSUserMediaCapturePolicyEntry")
WBSPasswordBreachResultQuery = _Class("WBSPasswordBreachResultQuery")
WBSHistoryContextController = _Class("WBSHistoryContextController")
WBSHistoryVisitsMatchingTimesPredicate = _Class(
    "WBSHistoryVisitsMatchingTimesPredicate"
)
WBSHistoryVisitsWithIDPredicate = _Class("WBSHistoryVisitsWithIDPredicate")
WBSPasswordBreachCryptographicOperations = _Class(
    "WBSPasswordBreachCryptographicOperations"
)
WBSSearchHelperConnectionManager = _Class("WBSSearchHelperConnectionManager")
WBSSameDocumentNavigationToHistoryVisitCorrelator = _Class(
    "WBSSameDocumentNavigationToHistoryVisitCorrelator"
)
WBSSafariCyclerConfigurationTool = _Class("WBSSafariCyclerConfigurationTool")
_WBSSafariCyclerConfigurationCommand = _Class("_WBSSafariCyclerConfigurationCommand")
WBSCertificateWarningPageContext = _Class("WBSCertificateWarningPageContext")
WBSHistoryItemToTagPairsPredicate = _Class("WBSHistoryItemToTagPairsPredicate")
WBSRemoteHistoryVisit = _Class("WBSRemoteHistoryVisit")
WBSRemoteHistorySession = _Class("WBSRemoteHistorySession")
WBSRemoteHistoryItem = _Class("WBSRemoteHistoryItem")
WBSRecentWebSearchesController = _Class("WBSRecentWebSearchesController")
WBSRecentWebSearchEntry = _Class("WBSRecentWebSearchEntry")
WBSRecentlyUsedAutoFillSet = _Class("WBSRecentlyUsedAutoFillSet")
WBSDictionaryInt64 = _Class("WBSDictionaryInt64")
WBSReaderLocalizedFonts = _Class("WBSReaderLocalizedFonts")
WBSPasswordBreachResultRecord = _Class("WBSPasswordBreachResultRecord")
WBSReaderFontManager = _Class("WBSReaderFontManager")
WBSReaderFontDownloadManager = _Class("WBSReaderFontDownloadManager")
WBSHistoryObjectCache = _Class("WBSHistoryObjectCache")
WBSReaderFont = _Class("WBSReaderFont")
WBSReaderResources = _Class("WBSReaderResources")
WBSRadarNewProblemURLBuilder = _Class("WBSRadarNewProblemURLBuilder")
WBSQuickWebsiteSearchProvider = _Class("WBSQuickWebsiteSearchProvider")
WBSQuickWebsiteSearchController = _Class("WBSQuickWebsiteSearchController")
WBSHistorySQLiteSchema = _Class("WBSHistorySQLiteSchema")
WBSPerSitePreferenceValueInformation = _Class("WBSPerSitePreferenceValueInformation")
WBSPerSitePreferencesSQLiteStore = _Class("WBSPerSitePreferencesSQLiteStore")
WBSPeriodicActivityScheduler = _Class("WBSPeriodicActivityScheduler")
WBSPasswordAutoFillUtilities = _Class("WBSPasswordAutoFillUtilities")
WBSHistoryVisitsWithItemsPredicate = _Class("WBSHistoryVisitsWithItemsPredicate")
WBSHistoryServiceURLCompletionMatchData = _Class(
    "WBSHistoryServiceURLCompletionMatchData"
)
WBSHistoryServiceURLCompletionMatchEntry = _Class(
    "WBSHistoryServiceURLCompletionMatchEntry"
)
WBSPasswordBreachContext = _Class("WBSPasswordBreachContext")
WBSHistoryVisitsInTimeRangePredicate = _Class("WBSHistoryVisitsInTimeRangePredicate")
WBSPasswordPatternMatcher = _Class("WBSPasswordPatternMatcher")
WBSPasswordBreachBloomFilter = _Class("WBSPasswordBreachBloomFilter")
WBSHistoryVisitsMatchingOriginsPredicate = _Class(
    "WBSHistoryVisitsMatchingOriginsPredicate"
)
WBSHistoryServiceEvent = _Class("WBSHistoryServiceEvent")
WBSTabDialog = _Class("WBSTabDialog")
WBSParsecSchema = _Class("WBSParsecSchema")
_WBSParsecDictionarySchema = _Class("_WBSParsecDictionarySchema")
_WBSParsecArraySchema = _Class("_WBSParsecArraySchema")
WBSHistoryServiceDatabaseDelegateWeakProxy = _Class(
    "WBSHistoryServiceDatabaseDelegateWeakProxy"
)
WBSHistoryServiceDatabaseDelegateProxy = _Class(
    "WBSHistoryServiceDatabaseDelegateProxy"
)
WBSDomainWhitelistManager = _Class("WBSDomainWhitelistManager")
WBSHistoryServiceDatabase = _Class("WBSHistoryServiceDatabase")
WBSPasswordWordListEntry = _Class("WBSPasswordWordListEntry")
WBSOneShotTimer = _Class("WBSOneShotTimer")
WBSMemoryPressureMonitor = _Class("WBSMemoryPressureMonitor")
WBSPasswordEvaluation = _Class("WBSPasswordEvaluation")
WBSParsecModel = _Class("WBSParsecModel")
WBSRecentHistoryTopicTagController = _Class("WBSRecentHistoryTopicTagController")
WBSPasswordBreachConfigurationBagLoader = _Class(
    "WBSPasswordBreachConfigurationBagLoader"
)
WBSReaderNavigationPolicyDecider = _Class("WBSReaderNavigationPolicyDecider")
WBSOpenSearchURLTemplate = _Class("WBSOpenSearchURLTemplate")
WBSOpenSearchURLTemplateParameter = _Class("WBSOpenSearchURLTemplateParameter")
WBSOpenSearchSchemaFetcher = _Class("WBSOpenSearchSchemaFetcher")
WBSPasswordBreachCredential = _Class("WBSPasswordBreachCredential")
WBSOpenSearchDescription = _Class("WBSOpenSearchDescription")
WBSScopeTimeoutHandler = _Class("WBSScopeTimeoutHandler")
WBSHistoryTagsPredicate = _Class("WBSHistoryTagsPredicate")
WBSTabDialogCancellationContext = _Class("WBSTabDialogCancellationContext")
WBSPasswordWarningStore = _Class("WBSPasswordWarningStore")
WBSAsynchronousRequestHelper = _Class("WBSAsynchronousRequestHelper")
WBSHistoryServiceURLRepresentation = _Class("WBSHistoryServiceURLRepresentation")
WBSReaderAvailabilityCheckResult = _Class("WBSReaderAvailabilityCheckResult")
WBSAutoplayQuirkWhitelistSnapshot = _Class("WBSAutoplayQuirkWhitelistSnapshot")
WBSPasswordBreachRequestManager = _Class("WBSPasswordBreachRequestManager")
WBSClass = _Class("WBSClass")
WBSMultiRoundAutoFillManager = _Class("WBSMultiRoundAutoFillManager")
WBSPasswordBreachResults = _Class("WBSPasswordBreachResults")
WBSPasswordBreachQueuedPasswordBagManager = _Class(
    "WBSPasswordBreachQueuedPasswordBagManager"
)
WBSDispatchSourceTimer = _Class("WBSDispatchSourceTimer")
WBSSingleCreditCardData = _Class("WBSSingleCreditCardData")
WBSSmartHistorySearcher = _Class("WBSSmartHistorySearcher")
WBSJSCallbackHandler = _Class("WBSJSCallbackHandler")
WBSDomainWhitelistSnapshot = _Class("WBSDomainWhitelistSnapshot")
WBSHistoryCrypto = _Class("WBSHistoryCrypto")
WBSHistoryVisit = _Class("WBSHistoryVisit")
WBSHistoryURLCompletionSession = _Class("WBSHistoryURLCompletionSession")
WBSHistoryVisitsAndTombstonesInSyncWindowPredicate = _Class(
    "WBSHistoryVisitsAndTombstonesInSyncWindowPredicate"
)
WBSHistoryURLCompletionMatchData = _Class("WBSHistoryURLCompletionMatchData")
WBSHistoryURLCompletionDataStore = _Class("WBSHistoryURLCompletionDataStore")
WBSWellKnownURLResponseCodeReliabilityChecker = _Class(
    "WBSWellKnownURLResponseCodeReliabilityChecker"
)
WBSPasswordBreachNotificationManager = _Class("WBSPasswordBreachNotificationManager")
WBSHistoryVisitsInRedirectChainPredicate = _Class(
    "WBSHistoryVisitsInRedirectChainPredicate"
)
WBSHistoryTagDatabaseController = _Class("WBSHistoryTagDatabaseController")
WBSHistoryTombstone = _Class("WBSHistoryTombstone")
WBSHistoryVisitsNeedingRecomputedVisitCountsPredicate = _Class(
    "WBSHistoryVisitsNeedingRecomputedVisitCountsPredicate"
)
WBSReaderConfigurationManager = _Class("WBSReaderConfigurationManager")
WBSHistorySessionIntervalCache = _Class("WBSHistorySessionIntervalCache")
WBSHistoryTag = _Class("WBSHistoryTag")
WBSHistoryTopicTag = _Class("WBSHistoryTopicTag")
WBSHistorySessionController = _Class("WBSHistorySessionController")
WBSAllowedLegacyTLSHostManager = _Class("WBSAllowedLegacyTLSHostManager")
WBSHistoryService = _Class("WBSHistoryService")
WBSHistoryServiceForTesting = _Class("WBSHistoryServiceForTesting")
WBSProtectionSpaceMatch = _Class("WBSProtectionSpaceMatch")
WBSHistoryNotification = _Class("WBSHistoryNotification")
WBSPasswordBreachHelperProxy = _Class("WBSPasswordBreachHelperProxy")
WBSHistoryItem = _Class("WBSHistoryItem")
WBSPasswordBreachHelperListener = _Class("WBSPasswordBreachHelperListener")
WBSHistoryDeletionPlan = _Class("WBSHistoryDeletionPlan")
WBSHistoryDatabaseAccessBroker = _Class("WBSHistoryDatabaseAccessBroker")
WBSHistoryConnectionProxy = _Class("WBSHistoryConnectionProxy")
WBSHistoryConnectionProxyForTesting = _Class("WBSHistoryConnectionProxyForTesting")
WBSTabOrderInsertionHint = _Class("WBSTabOrderInsertionHint")
WBSTabOrderManager = _Class("WBSTabOrderManager")
WBSHistoryConnection = _Class("WBSHistoryConnection")
WBSHistoryAccessSessionProxy = _Class("WBSHistoryAccessSessionProxy")
WBSCredentialMatchCriteria = _Class("WBSCredentialMatchCriteria")
WBSHistoryAccessSession = _Class("WBSHistoryAccessSession")
WBSHistory = _Class("WBSHistory")
WBSSafariSandboxBrokerConnection = _Class("WBSSafariSandboxBrokerConnection")
WBSFrequentlyVisitedSitesController = _Class("WBSFrequentlyVisitedSitesController")
WBSFrequentlyVisitedSitesBannedURLStore = _Class(
    "WBSFrequentlyVisitedSitesBannedURLStore"
)
WBSFrequentlyVisitedSiteCandidate = _Class("WBSFrequentlyVisitedSiteCandidate")
WBSFormToABBinder = _Class("WBSFormToABBinder")
WBSPasswordWordListCollection = _Class("WBSPasswordWordListCollection")
WBSFormMetadataController = _Class("WBSFormMetadataController")
WBSFormMetadata = _Class("WBSFormMetadata")
WBSPasswordPatternMatchSolver = _Class("WBSPasswordPatternMatchSolver")
WBSPasswordPatternPartialSolution = _Class("WBSPasswordPatternPartialSolution")
WBSPasswordBreachConfigurationDictionaryUnpacker = _Class(
    "WBSPasswordBreachConfigurationDictionaryUnpacker"
)
WBSFormFieldFingerprinter = _Class("WBSFormFieldFingerprinter")
WBSFormFieldClassificationCorrector = _Class("WBSFormFieldClassificationCorrector")
WBSPersistentPropertyListStore = _Class("WBSPersistentPropertyListStore")
WBSFormDataController = _Class("WBSFormDataController")
WBSPasswordEvaluator = _Class("WBSPasswordEvaluator")
WBSResultRanker = _Class("WBSResultRanker")
WBSFormAutoFillParsecFeedbackProcessor = _Class(
    "WBSFormAutoFillParsecFeedbackProcessor"
)
WBSFormAutoFillParsecDomainPolicyProvider = _Class(
    "WBSFormAutoFillParsecDomainPolicyProvider"
)
WBSPasswordWarningManager = _Class("WBSPasswordWarningManager")
WBSFormAutoFillParsecCrowdsourcedCorrectionsProcessor = _Class(
    "WBSFormAutoFillParsecCrowdsourcedCorrectionsProcessor"
)
WBSPasswordBreachConfigurationBag = _Class("WBSPasswordBreachConfigurationBag")
WBSFormAutoFillMetadataCorrector = _Class("WBSFormAutoFillMetadataCorrector")
WBSSetInt64 = _Class("WBSSetInt64")
WBSHistorySession = _Class("WBSHistorySession")
WBSHistorySessionWithItems = _Class("WBSHistorySessionWithItems")
WBSDigitalHealthManager = _Class("WBSDigitalHealthManager")
WBSFormAutoFillCorrectionsSQLiteStore = _Class("WBSFormAutoFillCorrectionsSQLiteStore")
WBSFormAutoFillCorrectionsHistoryObserver = _Class(
    "WBSFormAutoFillCorrectionsHistoryObserver"
)
WBSBrowserTabCompletionProvider = _Class("WBSBrowserTabCompletionProvider")
WBSBrowserTabCompletionInfo = _Class("WBSBrowserTabCompletionInfo")
WBSFormAutoFillCorrectionSet = _Class("WBSFormAutoFillCorrectionSet")
WBSFormAutoFillCorrectionManager = _Class("WBSFormAutoFillCorrectionManager")
_WBSFieldLabelPatternMatcherFactory = _Class("_WBSFieldLabelPatternMatcherFactory")
WBSFileLockFactoryPOSIX = _Class("WBSFileLockFactoryPOSIX")
WBSFileLockPOSIX = _Class("WBSFileLockPOSIX")
WBSEncryptedCloudKeyValueStore = _Class("WBSEncryptedCloudKeyValueStore")
WBSDistributedNotificationObserver = _Class("WBSDistributedNotificationObserver")
WBSCyclerTestTargetProxyController = _Class("WBSCyclerTestTargetProxyController")
WBSCyclerTestSuiteBookmarkAuxiliary = _Class("WBSCyclerTestSuiteBookmarkAuxiliary")
WBSHistoryVisitIdentifier = _Class("WBSHistoryVisitIdentifier")
WBSCyclerTestRunner = _Class("WBSCyclerTestRunner")
WBSCyclerStatus = _Class("WBSCyclerStatus")
WBSHistoryServicePendingVisit = _Class("WBSHistoryServicePendingVisit")
WBSCyclerServiceProxy = _Class("WBSCyclerServiceProxy")
WBSCyclerService = _Class("WBSCyclerService")
WBSTabDialogCancellationExemption = _Class("WBSTabDialogCancellationExemption")
WBSCyclerRandomnessUtilities = _Class("WBSCyclerRandomnessUtilities")
WBSPasswordImportedCredential = _Class("WBSPasswordImportedCredential")
WBSCyclerOperation = _Class("WBSCyclerOperation")
WBSCyclerMoveBookmarkOperation = _Class("WBSCyclerMoveBookmarkOperation")
WBSCyclerModifyBookmarkOperation = _Class("WBSCyclerModifyBookmarkOperation")
WBSPerSitePreference = _Class("WBSPerSitePreference")
WBSCyclerDeleteBookmarkOperation = _Class("WBSCyclerDeleteBookmarkOperation")
WBSSearchImpressionAnalyticsRecorder = _Class("WBSSearchImpressionAnalyticsRecorder")
WBSCyclerCreateBookmarkOperation = _Class("WBSCyclerCreateBookmarkOperation")
WBSCyclerConnectionManager = _Class("WBSCyclerConnectionManager")
WBSPerSitePreferenceTimeout = _Class("WBSPerSitePreferenceTimeout")
WBSPasswordWarning = _Class("WBSPasswordWarning")
WBSCyclerCloudKitMigrationTestSuite = _Class("WBSCyclerCloudKitMigrationTestSuite")
WBSCyclerBookmarksTestSuite = _Class("WBSCyclerBookmarksTestSuite")
WBSPasswordBreachManager = _Class("WBSPasswordBreachManager")
WBSHistoryServiceStore = _Class("WBSHistoryServiceStore")
WBSCyclerBookmarkOperationContext = _Class("WBSCyclerBookmarkOperationContext")
WBSCyclerBookmarkRepresentation = _Class("WBSCyclerBookmarkRepresentation")
WBSCyclerBookmarkListRepresentation = _Class("WBSCyclerBookmarkListRepresentation")
WBSCyclerBookmarkLeafRepresentation = _Class("WBSCyclerBookmarkLeafRepresentation")
WBSSafariSandboxBroker = _Class("WBSSafariSandboxBroker")
WBSPasswordBreachHelper = _Class("WBSPasswordBreachHelper")
WBSPasswordBreachKeychainCredentialSource = _Class(
    "WBSPasswordBreachKeychainCredentialSource"
)
WBSCreditCardDataController = _Class("WBSCreditCardDataController")
WBSPasswordBreachQueuedPassword = _Class("WBSPasswordBreachQueuedPassword")
WBSPasswordBreachChecker = _Class("WBSPasswordBreachChecker")
WBSCreditCardData = _Class("WBSCreditCardData")
WBSHistoryServiceDatabaseProxy = _Class("WBSHistoryServiceDatabaseProxy")
WBSContactsHelper = _Class("WBSContactsHelper")
WBSCloudHistoryServiceProxy = _Class("WBSCloudHistoryServiceProxy")
WBSContactsEntry = _Class("WBSContactsEntry")
WBSContactAutoFillSet = _Class("WBSContactAutoFillSet")
WBSCompletionQuery = _Class("WBSCompletionQuery")
WBSUserAgentQuirksSnapshot = _Class("WBSUserAgentQuirksSnapshot")
WBSProcessProxyOverride = _Class("WBSProcessProxyOverride")
WBSCoalescedAsynchronousWriter = _Class("WBSCoalescedAsynchronousWriter")
WBSCloudTabStore = _Class("WBSCloudTabStore")
WBSCloudTabDevice = _Class("WBSCloudTabDevice")
WBSCloudTabCloseRequest = _Class("WBSCloudTabCloseRequest")
WBSCloudTab = _Class("WBSCloudTab")
WBSPasswordWordList = _Class("WBSPasswordWordList")
WBSPasswordOrderedSetWordList = _Class("WBSPasswordOrderedSetWordList")
WBSPasswordLexiconWordList = _Class("WBSPasswordLexiconWordList")
WBSPasswordSetWordList = _Class("WBSPasswordSetWordList")
WBSAutomaticBugCaptureManager = _Class("WBSAutomaticBugCaptureManager")
WBSCloudHistoryVisit = _Class("WBSCloudHistoryVisit")
WBSCloudHistoryStore = _Class("WBSCloudHistoryStore")
WBSCloudHistoryPushAgentProxy = _Class("WBSCloudHistoryPushAgentProxy")
WBSCloudHistoryPushAgent = _Class("WBSCloudHistoryPushAgent")
WBSHistoryServiceObject = _Class("WBSHistoryServiceObject")
WBSHistoryServiceItem = _Class("WBSHistoryServiceItem")
WBSHistoryServiceVisit = _Class("WBSHistoryServiceVisit")
WBSHistoryServiceTombstone = _Class("WBSHistoryServiceTombstone")
WBSCloudHistoryMergeOperation = _Class("WBSCloudHistoryMergeOperation")
WBSContentBlockerStatisticsFirstParty = _Class("WBSContentBlockerStatisticsFirstParty")
WBSContentBlockerStatisticsSQLiteStore = _Class(
    "WBSContentBlockerStatisticsSQLiteStore"
)
WBSPerSitePreferenceManager = _Class("WBSPerSitePreferenceManager")
WBSUserMediaPermissionController = _Class("WBSUserMediaPermissionController")
WBSPageZoomPreferenceManager = _Class("WBSPageZoomPreferenceManager")
WBSContentBlockersPreferenceManager = _Class("WBSContentBlockersPreferenceManager")
WBSAutoplayPreferenceManager = _Class("WBSAutoplayPreferenceManager")
WBSGeolocationPreferenceManager = _Class("WBSGeolocationPreferenceManager")
WBSAutomaticReaderActivationManager = _Class("WBSAutomaticReaderActivationManager")
WBSCloudHistoryFetchResult = _Class("WBSCloudHistoryFetchResult")
WBSCloudHistoryConfiguration = _Class("WBSCloudHistoryConfiguration")
WBSPasswordWarningTopFraudTargets = _Class("WBSPasswordWarningTopFraudTargets")
WBSQuerySuggestion = _Class("WBSQuerySuggestion")
WBSCloudHistory = _Class("WBSCloudHistory")
WBSPasswordBreachTestCredentialSource = _Class("WBSPasswordBreachTestCredentialSource")
WBSCredentialMatchResult = _Class("WBSCredentialMatchResult")
WBSCloudBookmarksMigrationCoordinator = _Class("WBSCloudBookmarksMigrationCoordinator")
WBSPasswordBreachConfiguration = _Class("WBSPasswordBreachConfiguration")
WBSCleanupHandler = _Class("WBSCleanupHandler")
WBSPasswordBreachStore = _Class("WBSPasswordBreachStore")
WBSCache = _Class("WBSCache")
WBSURLCompletionMatch = _Class("WBSURLCompletionMatch")
WBSTabCompletionMatch = _Class("WBSTabCompletionMatch")
WBSBrowserTabCompletionMatch = _Class("WBSBrowserTabCompletionMatch")
WBSBookmarkAndHistoryCompletionMatch = _Class("WBSBookmarkAndHistoryCompletionMatch")
WBSTopHitCompletionMatch = _Class("WBSTopHitCompletionMatch")
WBSHistoryUniversalPredicate = _Class("WBSHistoryUniversalPredicate")
WBSHistoryServiceURLCompletion = _Class("WBSHistoryServiceURLCompletion")
WBSFormAutoFillItem = _Class("WBSFormAutoFillItem")
WBSUserTypedFormString = _Class("WBSUserTypedFormString")
WBSCredentialMatch = _Class("WBSCredentialMatch")
WBSCredentialIdentityMatch = _Class("WBSCredentialIdentityMatch")
WBSAddressBookMatch = _Class("WBSAddressBookMatch")
WBSFormControlMetadata = _Class("WBSFormControlMetadata")
WBSMutableFormControlMetadata = _Class("WBSMutableFormControlMetadata")
WBSFormControlMetadataProperty = _Class("WBSFormControlMetadataProperty")
WBSAutoplayQuirkWhitelistSnapshotTransformer = _Class(
    "WBSAutoplayQuirkWhitelistSnapshotTransformer"
)
WBSDomainWhitelistSnapshotTransformer = _Class("WBSDomainWhitelistSnapshotTransformer")
WBSUserAgentQuirksSnapshotTransformer = _Class("WBSUserAgentQuirksSnapshotTransformer")
WBSPasswordWarningTopFraudTargetsTransformer = _Class(
    "WBSPasswordWarningTopFraudTargetsTransformer"
)
WBSPasswordBreachConfigurationBagSnapshotTransformer = _Class(
    "WBSPasswordBreachConfigurationBagSnapshotTransformer"
)
WBSAutoplayQuirkWhitelistManager = _Class("WBSAutoplayQuirkWhitelistManager")
WBSCrowdsourcedFeedbackDomainNormalizer = _Class(
    "WBSCrowdsourcedFeedbackDomainNormalizer"
)
WBSFormAutoFillClassificationToCorrectionsTransformer = _Class(
    "WBSFormAutoFillClassificationToCorrectionsTransformer"
)
WBSCreditCardFormatter = _Class("WBSCreditCardFormatter")
