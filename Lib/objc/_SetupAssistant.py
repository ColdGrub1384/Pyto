'''
Classes from the 'SetupAssistant' framework.
'''

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

    
BYAnalyticsExpressRestore = _Class('BYAnalyticsExpressRestore')
BYAnalyticsEventRecommendedLocale = _Class('BYAnalyticsEventRecommendedLocale')
BYBuddyDaemonMigrationSourceClient = _Class('BYBuddyDaemonMigrationSourceClient')
BYAnalyticsManager = _Class('BYAnalyticsManager')
BYLicenseAgreement = _Class('BYLicenseAgreement')
BYSetupStateNotifier = _Class('BYSetupStateNotifier')
BYAnalyticsEvent = _Class('BYAnalyticsEvent')
BYNetworkMonitor = _Class('BYNetworkMonitor')
BYTelephonyStateNotifier = _Class('BYTelephonyStateNotifier')
BYBuddyDaemonProximitySourceClient = _Class('BYBuddyDaemonProximitySourceClient')
BYBuddyDaemonProximityTargetClient = _Class('BYBuddyDaemonProximityTargetClient')
BYAnalyticsLazyEvent = _Class('BYAnalyticsLazyEvent')
BYDeviceSetupSourceSession = _Class('BYDeviceSetupSourceSession')
BYRunState = _Class('BYRunState')
BYPaneAnalyticsManager = _Class('BYPaneAnalyticsManager')
BYSettingsManagerClient = _Class('BYSettingsManagerClient')
BYLocationController = _Class('BYLocationController')
BYDeviceConfiguration = _Class('BYDeviceConfiguration')
BFFSettingsManager = _Class('BFFSettingsManager')
BYDeviceMigrationManager = _Class('BYDeviceMigrationManager')
BYSourceDeviceMigration = _Class('BYSourceDeviceMigration')
BYAppleIDAccountsManager = _Class('BYAppleIDAccountsManager')
BYFlowSkipController = _Class('BYFlowSkipController')
BYChronicle = _Class('BYChronicle')
BYChronicleEntry = _Class('BYChronicleEntry')
BYPreferencesController = _Class('BYPreferencesController')
BYMigrationSourceController = _Class('BYMigrationSourceController')
BYBuddyDaemonGeneralClient = _Class('BYBuddyDaemonGeneralClient')
BYLocaleCountry = _Class('BYLocaleCountry')
BYSilentLoginUpgradeGuarantor = _Class('BYSilentLoginUpgradeGuarantor')
BYManagedAppleIDBootstrap = _Class('BYManagedAppleIDBootstrap')
BYDevice = _Class('BYDevice')
BYDeviceForTest = _Class('BYDeviceForTest')
BYLocaleDataSource = _Class('BYLocaleDataSource')
BYCapabilities = _Class('BYCapabilities')
BYXPCActivity = _Class('BYXPCActivity')
BYXPCActivityRegistrar = _Class('BYXPCActivityRegistrar')
BYSetupStateManager = _Class('BYSetupStateManager')
BYBuddyDaemonCloudSyncClient = _Class('BYBuddyDaemonCloudSyncClient')
BYSiriUtilities = _Class('BYSiriUtilities')
BYBackupMetadata = _Class('BYBackupMetadata')
