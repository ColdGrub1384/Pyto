"""
Classes from the 'CalendarDaemon' framework.
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


CADCalendarDatabaseCalStoreInfoProvider = _Class(
    "CADCalendarDatabaseCalStoreInfoProvider"
)
CADBlacklistedDelegateAccountAccessHandler = _Class(
    "CADBlacklistedDelegateAccountAccessHandler"
)
CADMCAccountAccessHandler = _Class("CADMCAccountAccessHandler")
CADSyntheticRouteHypothesizerCache = _Class("CADSyntheticRouteHypothesizerCache")
CADDefaultPermissionValidator = _Class("CADDefaultPermissionValidator")
CADChangeTrackingClientId = _Class("CADChangeTrackingClientId")
CADIdleChangeTrackingCleanupInfo = _Class("CADIdleChangeTrackingCleanupInfo")
CADEntityWrapper = _Class("CADEntityWrapper")
CADEventEntityWrapper = _Class("CADEventEntityWrapper")
CADACAccountStoreAccountsProvider = _Class("CADACAccountStoreAccountsProvider")
CADBirthdayListener = _Class("CADBirthdayListener")
LocalAttachmentCleanUpSupport = _Class("LocalAttachmentCleanUpSupport")
CADServer = _Class("CADServer")
CADCalendarDatabaseCalCalendarInfoProvider = _Class(
    "CADCalendarDatabaseCalCalendarInfoProvider"
)
CADNotificationGatheringContext = _Class("CADNotificationGatheringContext")
CADNotificationUtilities = _Class("CADNotificationUtilities")
CADMCProfileConnectionManagedConfigurationHandler = _Class(
    "CADMCProfileConnectionManagedConfigurationHandler"
)
ClientConnection = _Class("ClientConnection")
CADOperationProxy = _Class("CADOperationProxy")
CADNotificationCountOperationProxy = _Class("CADNotificationCountOperationProxy")
CADCalendarToolOperationProxy = _Class("CADCalendarToolOperationProxy")
CADEventKitSyncOperationProxy = _Class("CADEventKitSyncOperationProxy")
CADMigrationOperationProxy = _Class("CADMigrationOperationProxy")
CADEventAndReminderOperationProxy = _Class("CADEventAndReminderOperationProxy")
CADSpringBoardOperationProxy = _Class("CADSpringBoardOperationProxy")
CADReminderOnlyOperationProxy = _Class("CADReminderOnlyOperationProxy")
CADRemindersOperationProxy = _Class("CADRemindersOperationProxy")
CADEventOnlyOperationProxy = _Class("CADEventOnlyOperationProxy")
CADMobileCalOperationProxy = _Class("CADMobileCalOperationProxy")
CADTestingOperationProxy = _Class("CADTestingOperationProxy")
CADAnonymousOperationProxy = _Class("CADAnonymousOperationProxy")
CADXPCProxyHelper = _Class("CADXPCProxyHelper")
CADXPCInvocationContextHolder = _Class("CADXPCInvocationContextHolder")
CADFeatureSet = _Class("CADFeatureSet")
CADRouteHypothesis = _Class("CADRouteHypothesis")
ClientIdentity = _Class("ClientIdentity")
CADGroupedAccountAccessHandler = _Class("CADGroupedAccountAccessHandler")
CADWhitelistedAccountAccessHandler = _Class("CADWhitelistedAccountAccessHandler")
CADDatabaseInitializationOptions = _Class("CADDatabaseInitializationOptions")
CADOperationGroup = _Class("CADOperationGroup")
CADEventOperationGroup = _Class("CADEventOperationGroup")
CADCalendarToolOperationGroup = _Class("CADCalendarToolOperationGroup")
CADTestingOperationGroup = _Class("CADTestingOperationGroup")
CADInternalOperationGroup = _Class("CADInternalOperationGroup")
CADSourceOperationGroup = _Class("CADSourceOperationGroup")
CADCalendarOperationGroup = _Class("CADCalendarOperationGroup")
CADAccessOperationGroup = _Class("CADAccessOperationGroup")
CADNotificationCountOperationGroup = _Class("CADNotificationCountOperationGroup")
CADReminderOperationGroup = _Class("CADReminderOperationGroup")
CADSpotlightOperationGroup = _Class("CADSpotlightOperationGroup")
CADMigrationOperationGroup = _Class("CADMigrationOperationGroup")
CADSyncOperationGroup = _Class("CADSyncOperationGroup")
CADCalendarItemOperationGroup = _Class("CADCalendarItemOperationGroup")
CADDatabaseStorageManagementOperationGroup = _Class(
    "CADDatabaseStorageManagementOperationGroup"
)
CADDatabaseOperationGroup = _Class("CADDatabaseOperationGroup")
CADNotificationMonitorOperationGroup = _Class("CADNotificationMonitorOperationGroup")
CADObjectOperationGroup = _Class("CADObjectOperationGroup")
CADAlarmEngineOperationGroup = _Class("CADAlarmEngineOperationGroup")
CADFilter = _Class("CADFilter")
CADPropertyFilter = _Class("CADPropertyFilter")
CADCompoundFilter = _Class("CADCompoundFilter")
CADMutableCalStoreInfo = _Class("CADMutableCalStoreInfo")
EKAlarmOccurrence = _Class("EKAlarmOccurrence")
CADPredicate = _Class("CADPredicate")
CADRespondedEventsPredicate = _Class("CADRespondedEventsPredicate")
CADPropertySearchPredicate = _Class("CADPropertySearchPredicate")
CADUnacknowledgedEventsPredicate = _Class("CADUnacknowledgedEventsPredicate")
CADUpcomingEventsPredicate = _Class("CADUpcomingEventsPredicate")
CADNotificationCenterVisibleEventsPredicate = _Class(
    "CADNotificationCenterVisibleEventsPredicate"
)
CADEventTimeWindowPredicate = _Class("CADEventTimeWindowPredicate")
CADUnalertedEventsPredicate = _Class("CADUnalertedEventsPredicate")
CADNotifiableEventsPredicate = _Class("CADNotifiableEventsPredicate")
EKPredicate = _Class("EKPredicate")
CADNaturalLanguageSuggestedEventsSearchPredicate = _Class(
    "CADNaturalLanguageSuggestedEventsSearchPredicate"
)
EKReminderPredicate = _Class("EKReminderPredicate")
CADEventCreatedFromSuggestionPredicate = _Class(
    "CADEventCreatedFromSuggestionPredicate"
)
CADEventsForAssistantSearchPredicate = _Class("CADEventsForAssistantSearchPredicate")
EKScheduledReminderPredicate = _Class("EKScheduledReminderPredicate")
EKMasterEventsPredicate = _Class("EKMasterEventsPredicate")
CADTravelEventsPredicate = _Class("CADTravelEventsPredicate")
CADContactEventsPredicate = _Class("CADContactEventsPredicate")
CADUpNextEventsPredicate = _Class("CADUpNextEventsPredicate")
CADEventPredicate = _Class("CADEventPredicate")
CADCalendarItemsWithExternalIdentifierPredicate = _Class(
    "CADCalendarItemsWithExternalIdentifierPredicate"
)
CADCalSearchOperation = _Class("CADCalSearchOperation")
CADCalLocationSearchOperation = _Class("CADCalLocationSearchOperation")
_CADFetchCalendarItemsWithPredicateOperation = _Class(
    "_CADFetchCalendarItemsWithPredicateOperation"
)
