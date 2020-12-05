"""
Classes from the 'SpringBoardServices' framework.
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


_SBSUIRemoteAlertServiceObserverHandle = _Class(
    "_SBSUIRemoteAlertServiceObserverHandle"
)
SBLegacyServices = _Class("SBLegacyServices")
SBSInCallPresentationRequest = _Class("SBSInCallPresentationRequest")
SBSLockScreenPluginService = _Class("SBSLockScreenPluginService")
SBSStatusBarStyleOverridesCoordinator = _Class("SBSStatusBarStyleOverridesCoordinator")
SBSAppDragLocalContext = _Class("SBSAppDragLocalContext")
_SBSDisplayIdentifiersCache = _Class("_SBSDisplayIdentifiersCache")
_SBSHardwareButtonEventConfiguration = _Class("_SBSHardwareButtonEventConfiguration")
SBSSwitcherDemoCommands = _Class("SBSSwitcherDemoCommands")
SBSRemoteContentPreferences = _Class("SBSRemoteContentPreferences")
SBSApplicationUserQuitMonitor = _Class("SBSApplicationUserQuitMonitor")
SBSRemoteAlertHandleXPCClient = _Class("SBSRemoteAlertHandleXPCClient")
SBSStatusBarStyleOverridesAssertionManager = _Class(
    "SBSStatusBarStyleOverridesAssertionManager"
)
SBSStatusBarStyleOverridesAssertionAcquisitionHandlerEntry = _Class(
    "SBSStatusBarStyleOverridesAssertionAcquisitionHandlerEntry"
)
SBSWebClipServiceSessionSpecification = _Class("SBSWebClipServiceSessionSpecification")
SBSAssertion = _Class("SBSAssertion")
SBSCardItemsController = _Class("SBSCardItemsController")
SBSCardItem = _Class("SBSCardItem")
SBSApplicationShortcutIcon = _Class("SBSApplicationShortcutIcon")
SBSApplicationShortcutContactIcon = _Class("SBSApplicationShortcutContactIcon")
SBSApplicationShortcutCustomImageIcon = _Class("SBSApplicationShortcutCustomImageIcon")
SBSApplicationShortcutTemplateIcon = _Class("SBSApplicationShortcutTemplateIcon")
SBSApplicationShortcutSystemPrivateIcon = _Class(
    "SBSApplicationShortcutSystemPrivateIcon"
)
SBSApplicationShortcutSystemIcon = _Class("SBSApplicationShortcutSystemIcon")
SBSRemoteAlertPresentationTarget = _Class("SBSRemoteAlertPresentationTarget")
SBSRemoteAlertConfigurationContext = _Class("SBSRemoteAlertConfigurationContext")
SBSStatusBarStyleOverridesAssertionData = _Class(
    "SBSStatusBarStyleOverridesAssertionData"
)
SBSRemoteAlertActivationContext = _Class("SBSRemoteAlertActivationContext")
SBSRemoteAlertActivationOptions = _Class("SBSRemoteAlertActivationOptions")
SBSWebClipService = _Class("SBSWebClipService")
SBSStatusBarTapContextImpl = _Class("SBSStatusBarTapContextImpl")
SBSWidgetMetricsServiceInterfaceSpecification = _Class(
    "SBSWidgetMetricsServiceInterfaceSpecification"
)
SBSRemoteAlertHandle = _Class("SBSRemoteAlertHandle")
SBSStatusBarStyleOverridesAssertion = _Class("SBSStatusBarStyleOverridesAssertion")
SBSAccessibilityWindowHostingController = _Class(
    "SBSAccessibilityWindowHostingController"
)
SBSHomeScreenService = _Class("SBSHomeScreenService")
_SBSUserNotificationButtonDefinitionBuilder = _Class(
    "_SBSUserNotificationButtonDefinitionBuilder"
)
SBSUserNotificationButtonDefinition = _Class("SBSUserNotificationButtonDefinition")
SBSMutableUserNotificationButtonDefinition = _Class(
    "SBSMutableUserNotificationButtonDefinition"
)
SBSSwitcherDemoCommandsSessionSpecification = _Class(
    "SBSSwitcherDemoCommandsSessionSpecification"
)
SBSHomeScreenServiceSpecification = _Class("SBSHomeScreenServiceSpecification")
SBSAppClipService = _Class("SBSAppClipService")
SBSInCallPresentationConfiguration = _Class("SBSInCallPresentationConfiguration")
SBSWidgetMetricsServer = _Class("SBSWidgetMetricsServer")
SBSApplicationUserQuitMonitorSessionSpecification = _Class(
    "SBSApplicationUserQuitMonitorSessionSpecification"
)
SBSRemoteContentDefinition = _Class("SBSRemoteContentDefinition")
_SBSUserNotificationTextFieldDefinitionBuilder = _Class(
    "_SBSUserNotificationTextFieldDefinitionBuilder"
)
SBSUserNotificationTextFieldDefinition = _Class(
    "SBSUserNotificationTextFieldDefinition"
)
SBSMutableUserNotificationTextFieldDefinition = _Class(
    "SBSMutableUserNotificationTextFieldDefinition"
)
SBSLockScreenServiceSpecification = _Class("SBSLockScreenServiceSpecification")
SBScreenTimeTrackingController = _Class("SBScreenTimeTrackingController")
SBSApplicationCarPlayService = _Class("SBSApplicationCarPlayService")
_SBSCarPlayApplicationInfo = _Class("_SBSCarPlayApplicationInfo")
SBSWallpaperService = _Class("SBSWallpaperService")
SBSAnalyticsState = _Class("SBSAnalyticsState")
SBSAccessibilityWindowHostingSpecification = _Class(
    "SBSAccessibilityWindowHostingSpecification"
)
SBSApplicationShortcutItem = _Class("SBSApplicationShortcutItem")
SBSApplicationShortcutServiceFetchResult = _Class(
    "SBSApplicationShortcutServiceFetchResult"
)
SBSRemoteAlertHandleContext = _Class("SBSRemoteAlertHandleContext")
SBSRemoteAlertHandleServiceSpecification = _Class(
    "SBSRemoteAlertHandleServiceSpecification"
)
SBSAbstractFacilityService = _Class("SBSAbstractFacilityService")
SBSAbstractApplicationService = _Class("SBSAbstractApplicationService")
SBSApplicationHarmonyService = _Class("SBSApplicationHarmonyService")
SBSApplicationShortcutService = _Class("SBSApplicationShortcutService")
SBSApplicationMultiwindowService = _Class("SBSApplicationMultiwindowService")
SBSApplicationService = _Class("SBSApplicationService")
SBSAbstractSystemService = _Class("SBSAbstractSystemService")
SBSTestAutomationService = _Class("SBSTestAutomationService")
SBSStateDumpService = _Class("SBSStateDumpService")
SBSAppSwitcherSystemService = _Class("SBSAppSwitcherSystemService")
SBSSoftwareUpdateService = _Class("SBSSoftwareUpdateService")
SBSHardwareButtonService = _Class("SBSHardwareButtonService")
SBSBiometricsService = _Class("SBSBiometricsService")
SBSLockScreenService = _Class("SBSLockScreenService")
SBSLockScreenServiceConnection = _Class("SBSLockScreenServiceConnection")
SBSWidgetMetricsService = _Class("SBSWidgetMetricsService")
SBSLockScreenContentAssertion = _Class("SBSLockScreenContentAssertion")
SBSSecureAppAssertion = _Class("SBSSecureAppAssertion")
SBSLockScreenRemoteContentAssertion = _Class("SBSLockScreenRemoteContentAssertion")
SBSWakeToRemoteAlertAssertion = _Class("SBSWakeToRemoteAlertAssertion")
SBSRemoteAlertDefinition = _Class("SBSRemoteAlertDefinition")
SBSRemoteAlertConfiguration = _Class("SBSRemoteAlertConfiguration")
SBSInCallPresentationServiceInterfaceSpecification = _Class(
    "SBSInCallPresentationServiceInterfaceSpecification"
)
_SBSHardwareButtonEventConsumerInfo = _Class("_SBSHardwareButtonEventConsumerInfo")
SBSUnlockOptions = _Class("SBSUnlockOptions")
SBSDisplayLayoutElement = _Class("SBSDisplayLayoutElement")
SBSExternalDisplayLayoutElement = _Class("SBSExternalDisplayLayoutElement")
SBSServiceFacilityClient = _Class("SBSServiceFacilityClient")
SBSApplicationClient = _Class("SBSApplicationClient")
SBSSystemServiceClient = _Class("SBSSystemServiceClient")
SBSWallpaperClient = _Class("SBSWallpaperClient")
SBIdleTimerRequestConfiguration = _Class("SBIdleTimerRequestConfiguration")
SBSLockScreenContentAction = _Class("SBSLockScreenContentAction")
SBSRelaunchAction = _Class("SBSRelaunchAction")
