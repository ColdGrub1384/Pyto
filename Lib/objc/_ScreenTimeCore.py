"""
Classes from the 'ScreenTimeCore' framework.
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


STXPCRemoteObjectProxy = _Class("STXPCRemoteObjectProxy")
STWebUsageController = _Class("STWebUsageController")
STVersionVectorNode = _Class("STVersionVectorNode")
STVersionVector = _Class("STVersionVector")
STUserID = _Class("STUserID")
STUserDescription = _Class("STUserDescription")
STUsageTrustIdentifier = _Class("STUsageTrustIdentifier")
STUsageReporter = _Class("STUsageReporter")
STUsageDetailItem = _Class("STUsageDetailItem")
STUniquedManagedObjectDelta = _Class("STUniquedManagedObjectDelta")
STUnifiedTransportPayloadDestination = _Class("STUnifiedTransportPayloadDestination")
STSetupConfiguration = _Class("STSetupConfiguration")
STSetupClient = _Class("STSetupClient")
STScreenTimeCoreBundle = _Class("STScreenTimeCoreBundle")
STScreenTimeAgentPrivateConnection = _Class("STScreenTimeAgentPrivateConnection")
STReconciler = _Class("STReconciler")
STPINController = _Class("STPINController")
STPersistenceConfiguration = _Class("STPersistenceConfiguration")
STOpaquePasscode = _Class("STOpaquePasscode")
STMigrationContext = _Class("STMigrationContext")
STUnique = _Class("STUnique")
STManagementStateObserver = _Class("STManagementStateObserver")
STManagementState = _Class("STManagementState")
STLog = _Class("STLog")
STLocations = _Class("STLocations")
STDelta = _Class("STDelta")
STHistoryAnalyzer = _Class("STHistoryAnalyzer")
STGroupFetchedResultsController = _Class("STGroupFetchedResultsController")
STFetchResultsRequest = _Class("STFetchResultsRequest")
STFamily = _Class("STFamily")
STFamilyMember = _Class("STFamilyMember")
STConversation = _Class("STConversation")
STConversationContext = _Class("STConversationContext")
STConfigurationSchedule = _Class("STConfigurationSchedule")
STConfigurationScheduleDay = _Class("STConfigurationScheduleDay")
STBlueprintUsageLimitScheduleRepresentation = _Class(
    "STBlueprintUsageLimitScheduleRepresentation"
)
STBlueprintUsageLimitScheduleCustomDayItem = _Class(
    "STBlueprintUsageLimitScheduleCustomDayItem"
)
STBlueprintUsageLimitScheduleSimpleItem = _Class(
    "STBlueprintUsageLimitScheduleSimpleItem"
)
STBlueprintScheduleRepresentation = _Class("STBlueprintScheduleRepresentation")
STBlueprintScheduleCustomDayItem = _Class("STBlueprintScheduleCustomDayItem")
STBlueprintScheduleSimpleItem = _Class("STBlueprintScheduleSimpleItem")
STAskForTimeResponse = _Class("STAskForTimeResponse")
STAskForTimeResource = _Class("STAskForTimeResource")
STAskForTimeCategoryResource = _Class("STAskForTimeCategoryResource")
STAskForTimeWebsiteResource = _Class("STAskForTimeWebsiteResource")
STAskForTimeApplicationResource = _Class("STAskForTimeApplicationResource")
STAskForTimeRequest = _Class("STAskForTimeRequest")
STAskForTimeClient = _Class("STAskForTimeClient")
STUserNotificationContext = _Class("STUserNotificationContext")
STWeeklyReportUserNotificationContext = _Class("STWeeklyReportUserNotificationContext")
STScreenTimeEnabledUserNotificationContext = _Class(
    "STScreenTimeEnabledUserNotificationContext"
)
STDowntimeWarningUserNotificationContext = _Class(
    "STDowntimeWarningUserNotificationContext"
)
STDeviceDowntimeUserNotificationContext = _Class(
    "STDeviceDowntimeUserNotificationContext"
)
STAskToManageContactsRequestReceivedUserNotificationContext = _Class(
    "STAskToManageContactsRequestReceivedUserNotificationContext"
)
STAskToManageContactsNotApprovedResponseReceivedUserNotificationContext = _Class(
    "STAskToManageContactsNotApprovedResponseReceivedUserNotificationContext"
)
STAskToManageContactsApprovedResponseReceivedUserNotificationContext = _Class(
    "STAskToManageContactsApprovedResponseReceivedUserNotificationContext"
)
STAskForTimeRequestReceivedUserNotificationContext = _Class(
    "STAskForTimeRequestReceivedUserNotificationContext"
)
STAskForTimeNotApprovedResponseReceivedUserNotificationContext = _Class(
    "STAskForTimeNotApprovedResponseReceivedUserNotificationContext"
)
STAskForTimeApprovedResponseReceivedUserNotificationContext = _Class(
    "STAskForTimeApprovedResponseReceivedUserNotificationContext"
)
STAppLimitWarningUserNotificationContext = _Class(
    "STAppLimitWarningUserNotificationContext"
)
STAppInfoCache = _Class("STAppInfoCache")
STAppInfo = _Class("STAppInfo")
STPersistenceController = _Class("STPersistenceController")
STAdminPersistenceController = _Class("STAdminPersistenceController")
RMRemoteManagementScreenTimeViewUsage = _Class("RMRemoteManagementScreenTimeViewUsage")
RMRemoteManagementScreenTimeState = _Class("RMRemoteManagementScreenTimeState")
RMRemoteManagementScreenTimeReportingEnabled = _Class(
    "RMRemoteManagementScreenTimeReportingEnabled"
)
RMRemoteManagementScreenTimeNumberOfLimits = _Class(
    "RMRemoteManagementScreenTimeNumberOfLimits"
)
RMRemoteManagementScreenTimeLimitUsageChange = _Class(
    "RMRemoteManagementScreenTimeLimitUsageChange"
)
RMRemoteManagementScreenTimeLimitIgnore = _Class(
    "RMRemoteManagementScreenTimeLimitIgnore"
)
RMRemoteManagementScreenTimeLimitDelete = _Class(
    "RMRemoteManagementScreenTimeLimitDelete"
)
RMRemoteManagementScreenTimeFamilySetup = _Class(
    "RMRemoteManagementScreenTimeFamilySetup"
)
RMRemoteManagementScreenTimeEnabled = _Class("RMRemoteManagementScreenTimeEnabled")
RMRemoteManagementScreenTimeDowntimeEnabled = _Class(
    "RMRemoteManagementScreenTimeDowntimeEnabled"
)
RMRemoteManagementScreenTimeDisabled = _Class("RMRemoteManagementScreenTimeDisabled")
RMCategoryLimitUsageChange = _Class("RMCategoryLimitUsageChange")
RMRemoteManagementScreenTimeAskForMoreRequest = _Class(
    "RMRemoteManagementScreenTimeAskForMoreRequest"
)
STUserDeviceAddress = _Class("STUserDeviceAddress")
STUsageTimedItem = _Class("STUsageTimedItem")
STUsageRequest = _Class("STUsageRequest")
STUsageCountedItem = _Class("STUsageCountedItem")
STUsageCategory = _Class("STUsageCategory")
STUsageBlock = _Class("STUsageBlock")
STUsage = _Class("STUsage")
STTestSyncableSubObject = _Class("STTestSyncableSubObject")
STScreenTimeSettings = _Class("STScreenTimeSettings")
STDowntime = _Class("STDowntime")
STDailySchedule = _Class("STDailySchedule")
STCoreUser = _Class("STCoreUser")
STCoreTransportPayload = _Class("STCoreTransportPayload")
STCoreOrganization = _Class("STCoreOrganization")
STFamilyOrganization = _Class("STFamilyOrganization")
STiCloudOrganization = _Class("STiCloudOrganization")
STLocalOrganization = _Class("STLocalOrganization")
STCoreDevice = _Class("STCoreDevice")
STCloudUserDevicePair = _Class("STCloudUserDevicePair")
STCloudUser = _Class("STCloudUser")
STCloudUsageDeviceIdentifier = _Class("STCloudUsageDeviceIdentifier")
STCloudOrganization = _Class("STCloudOrganization")
STCloudDevice = _Class("STCloudDevice")
STCloudConfiguration = _Class("STCloudConfiguration")
STCloudCategory = _Class("STCloudCategory")
STCloudApp = _Class("STCloudApp")
STBlueprintUsageLimit = _Class("STBlueprintUsageLimit")
STBlueprintSchedule = _Class("STBlueprintSchedule")
STBlueprintConfiguration = _Class("STBlueprintConfiguration")
STUniquedManagedObject = _Class("STUniquedManagedObject")
STUserDeviceState = _Class("STUserDeviceState")
STTestSyncableObject = _Class("STTestSyncableObject")
STInstalledApp = _Class("STInstalledApp")
STCoreOrganizationSettings = _Class("STCoreOrganizationSettings")
STFamilyOrganizationSettings = _Class("STFamilyOrganizationSettings")
STiCloudOrganizationSettings = _Class("STiCloudOrganizationSettings")
STLocalOrganizationSettings = _Class("STLocalOrganizationSettings")
STCloudActivation = _Class("STCloudActivation")
STBlueprint = _Class("STBlueprint")
STAskForTimeRequestResponse = _Class("STAskForTimeRequestResponse")
