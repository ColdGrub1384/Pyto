"""
Classes from the 'SafariCore' framework.
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


WBSPasswordAuditingEligibleDomainsManager = _Class(
    "WBSPasswordAuditingEligibleDomainsManager"
)
WBSPasswordManagerURL = _Class("WBSPasswordManagerURL")
WBSSavedPasswordStore = _Class("WBSSavedPasswordStore")
_WBSSavedPasswordPartialCredential = _Class("_WBSSavedPasswordPartialCredential")
WBSPair = _Class("WBSPair")
WBSSavedPassword = _Class("WBSSavedPassword")
WBSSafariBookmarksSyncAgentProxy = _Class("WBSSafariBookmarksSyncAgentProxy")
WBSSQLiteStatement = _Class("WBSSQLiteStatement")
WBSPasswordRule = _Class("WBSPasswordRule")
WBSMaxLengthPasswordRule = _Class("WBSMaxLengthPasswordRule")
WBSMinLengthPasswordRule = _Class("WBSMinLengthPasswordRule")
WBSMaxConsecutivePasswordRule = _Class("WBSMaxConsecutivePasswordRule")
WBSRequiredPasswordRule = _Class("WBSRequiredPasswordRule")
WBSAllowedPasswordRule = _Class("WBSAllowedPasswordRule")
WBSSQLiteStore = _Class("WBSSQLiteStore")
WBSFetchedCloudTabDeviceOrCloseRequest = _Class(
    "WBSFetchedCloudTabDeviceOrCloseRequest"
)
WBSCloudKitContainerManateeObserver = _Class("WBSCloudKitContainerManateeObserver")
WBSPasswordRuleSet = _Class("WBSPasswordRuleSet")
WBSUserDefaultObservation = _Class("WBSUserDefaultObservation")
WBSAutoFillAssociatedDomainsManager = _Class("WBSAutoFillAssociatedDomainsManager")
WBSSQLiteRow = _Class("WBSSQLiteRow")
WBSRemotePlistController = _Class("WBSRemotePlistController")
WBSScopeExitHandler = _Class("WBSScopeExitHandler")
WBSKeychainCredentialNotificationMonitor = _Class(
    "WBSKeychainCredentialNotificationMonitor"
)
WBSAutoFillQuirksManager = _Class("WBSAutoFillQuirksManager")
WBSDontSaveMarker = _Class("WBSDontSaveMarker")
WBSSavedPasswordAuditor = _Class("WBSSavedPasswordAuditor")
WBSCloudKitThrottler = _Class("WBSCloudKitThrottler")
WBSMutableOrderedDictionary = _Class("WBSMutableOrderedDictionary")
WBSCoreClass = _Class("WBSCoreClass")
WBSCloudBookmarksRemoteMigrationInfo = _Class("WBSCloudBookmarksRemoteMigrationInfo")
WBSPasswordCharacterClass = _Class("WBSPasswordCharacterClass")
WBSMemoryFootprint = _Class("WBSMemoryFootprint")
WBSMemoryFootprintMallocZone = _Class("WBSMemoryFootprintMallocZone")
WBSSQLiteStatementCache = _Class("WBSSQLiteStatementCache")
WBSAutoFillQuirksSnapshot = _Class("WBSAutoFillQuirksSnapshot")
WBSFileLogger = _Class("WBSFileLogger")
WBSChangePasswordURLManager = _Class("WBSChangePasswordURLManager")
WBSPasswordGenerationManager = _Class("WBSPasswordGenerationManager")
WBSFeatureAvailability = _Class("WBSFeatureAvailability")
WBSSQLiteDatabase = _Class("WBSSQLiteDatabase")
WBSConfigurationDownloader = _Class("WBSConfigurationDownloader")
WBSAnalyticsLogger = _Class("WBSAnalyticsLogger")
WBSAddressBookValueSpecifier = _Class("WBSAddressBookValueSpecifier")
WBSURLCredentialCache = _Class("WBSURLCredentialCache")
WBSAggresiveURLCredentialCache = _Class("WBSAggresiveURLCredentialCache")
WBSLazyURLCredentialCache = _Class("WBSLazyURLCredentialCache")
WBSMutableOrderedSet = _Class("WBSMutableOrderedSet")
WBSPasswordRuleParser = _Class("WBSPasswordRuleParser")
WBSConfigurationDataTransformer = _Class("WBSConfigurationDataTransformer")
WBSAutoFillQuirksSnapshotTransformer = _Class("WBSAutoFillQuirksSnapshotTransformer")
WBSAnalyticsSafariParticipatedInPasswordAutoFill = _Class(
    "WBSAnalyticsSafariParticipatedInPasswordAutoFill"
)
WBSAnalyticsSafariSharedPasswordEvent = _Class("WBSAnalyticsSafariSharedPasswordEvent")
WBSAnalyticsSafariVersioningEvent = _Class("WBSAnalyticsSafariVersioningEvent")
WBSAnalyticsSafariActivatedHomeScreenQuickActionEvent = _Class(
    "WBSAnalyticsSafariActivatedHomeScreenQuickActionEvent"
)
WBSAnalyticsSafariSafeBrowsingUserActionAfterSeeingWarningEvent = _Class(
    "WBSAnalyticsSafariSafeBrowsingUserActionAfterSeeingWarningEvent"
)
WBSAnalyticsSafariInteractedWithGeneratedPasswordEvent = _Class(
    "WBSAnalyticsSafariInteractedWithGeneratedPasswordEvent"
)
WBSAnalyticsSafariAutoFillAuthenticationPreferenceEvent = _Class(
    "WBSAnalyticsSafariAutoFillAuthenticationPreferenceEvent"
)
WBSAnalyticsSafariDuplicatedPasswordsWarningEvent = _Class(
    "WBSAnalyticsSafariDuplicatedPasswordsWarningEvent"
)
WBSAnalyticsSafariAutoFillAuthenticationEvent = _Class(
    "WBSAnalyticsSafariAutoFillAuthenticationEvent"
)
WBSAnalyticsSafariCKBookmarksMigrationStartedEvent = _Class(
    "WBSAnalyticsSafariCKBookmarksMigrationStartedEvent"
)
WBSAnalyticsSafariUnableToSilentlyMigrateToCKBookmarksEvent = _Class(
    "WBSAnalyticsSafariUnableToSilentlyMigrateToCKBookmarksEvent"
)
WBSAnalyticsSafariCKBookmarksMigrationFinishedEvent = _Class(
    "WBSAnalyticsSafariCKBookmarksMigrationFinishedEvent"
)
WBSAnalyticsSafariDedupedDAVBookmarksEvent = _Class(
    "WBSAnalyticsSafariDedupedDAVBookmarksEvent"
)
WBSAnalyticsSafariSelectedFavoritesGridItemEvent = _Class(
    "WBSAnalyticsSafariSelectedFavoritesGridItemEvent"
)
WBSAnalyticsSafariReaderActiveOptInOutEvent = _Class(
    "WBSAnalyticsSafariReaderActiveOptInOutEvent"
)
WBSAnalyticsSafariContactAutoFillDidShowSetsEvent = _Class(
    "WBSAnalyticsSafariContactAutoFillDidShowSetsEvent"
)
WBSAnalyticsSafariContactAutoFillDidSelectSetEvent = _Class(
    "WBSAnalyticsSafariContactAutoFillDidSelectSetEvent"
)
WBSAnalyticsSafariContactAutoFillDidFillCustomContactSetEvent = _Class(
    "WBSAnalyticsSafariContactAutoFillDidFillCustomContactSetEvent"
)
WBSAnalyticsSafariReaderChangedOptInOutEvent = _Class(
    "WBSAnalyticsSafariReaderChangedOptInOutEvent"
)
WBSAnalyticsSafariViewControllerTappedOnToolbarButtonEvent = _Class(
    "WBSAnalyticsSafariViewControllerTappedOnToolbarButtonEvent"
)
WBSAnalyticsSafariEnterPasswordsPreferencesEvent = _Class(
    "WBSAnalyticsSafariEnterPasswordsPreferencesEvent"
)
WBSAnalyticsSafariViewControllerPresentedFromHostAppEvent = _Class(
    "WBSAnalyticsSafariViewControllerPresentedFromHostAppEvent"
)
WBSAnalyticsSafariViewControllerDismissedEvent = _Class(
    "WBSAnalyticsSafariViewControllerDismissedEvent"
)
WBSAnalyticsSafariUsingPrivateBrowsingEvent = _Class(
    "WBSAnalyticsSafariUsingPrivateBrowsingEvent"
)
WBSAnalyticsSafariTwoFingerTappedOnLinkEvent = _Class(
    "WBSAnalyticsSafariTwoFingerTappedOnLinkEvent"
)
WBSAnalyticsSafariTappedOnToolbarButtonEvent = _Class(
    "WBSAnalyticsSafariTappedOnToolbarButtonEvent"
)
WBSAnalyticsSafariTappedAutoFillQuickTypeSuggestionEvent = _Class(
    "WBSAnalyticsSafariTappedAutoFillQuickTypeSuggestionEvent"
)
WBSAnalyticsSafariDidTerminateWebProcessBeforeNavigation = _Class(
    "WBSAnalyticsSafariDidTerminateWebProcessBeforeNavigation"
)
WBSAnalyticsSafariSetAutoFillQuickTypeSuggestionEvent = _Class(
    "WBSAnalyticsSafariSetAutoFillQuickTypeSuggestionEvent"
)
WBSAnalyticsSafariSafeBrowsingWarningShownEvent = _Class(
    "WBSAnalyticsSafariSafeBrowsingWarningShownEvent"
)
WBSAnalyticsSafariPageLoadStartedEvent = _Class(
    "WBSAnalyticsSafariPageLoadStartedEvent"
)
WBSAnalyticsSafariPageLoadCompleteEvent = _Class(
    "WBSAnalyticsSafariPageLoadCompleteEvent"
)
WBSAnalyticsSafariEnterTwoUpEvent = _Class("WBSAnalyticsSafariEnterTwoUpEvent")
WBSAnalyticsSafariDidReceiveInvalidMessageFromWebProcessEvent = _Class(
    "WBSAnalyticsSafariDidReceiveInvalidMessageFromWebProcessEvent"
)
WBSAnalyticsSafariCKBookmarksSyncEvent = _Class(
    "WBSAnalyticsSafariCKBookmarksSyncEvent"
)
WBSSQLiteRowEnumerator = _Class("WBSSQLiteRowEnumerator")
