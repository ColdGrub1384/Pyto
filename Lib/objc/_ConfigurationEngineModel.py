"""
Classes from the 'ConfigurationEngineModel' framework.
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


CEMRegisteredTypeResolver = _Class("CEMRegisteredTypeResolver")
CEMAssetReference = _Class("CEMAssetReference")
CEMPayloadBase = _Class("CEMPayloadBase")
CEMUserNameAndPasswordCredentialsDeclaration = _Class(
    "CEMUserNameAndPasswordCredentialsDeclaration"
)
CEMSystemXsanVolumePreferencesDeclaration_Status = _Class(
    "CEMSystemXsanVolumePreferencesDeclaration_Status"
)
CEMSystemXsanSettingsDeclaration_Status = _Class(
    "CEMSystemXsanSettingsDeclaration_Status"
)
CEMSystemWebContentFilterDeclaration_Status = _Class(
    "CEMSystemWebContentFilterDeclaration_Status"
)
CEMSystemWebContentFilterDeclaration_WhitelistedBookmarksItem = _Class(
    "CEMSystemWebContentFilterDeclaration_WhitelistedBookmarksItem"
)
CEMSystemWebDeclaration_Status = _Class("CEMSystemWebDeclaration_Status")
CEMSystemWatchDeclaration_Status = _Class("CEMSystemWatchDeclaration_Status")
CEMSystemTVRemoteDeclaration_Status = _Class("CEMSystemTVRemoteDeclaration_Status")
CEMSystemTVRemoteDeclaration_AllowedTVsItem = _Class(
    "CEMSystemTVRemoteDeclaration_AllowedTVsItem"
)
CEMSystemTVRemoteDeclaration_AllowedRemotesItem = _Class(
    "CEMSystemTVRemoteDeclaration_AllowedRemotesItem"
)
CEMSystemTVProviderDeclaration_Status = _Class("CEMSystemTVProviderDeclaration_Status")
CEMSystemTimeServerDeclaration_Status = _Class("CEMSystemTimeServerDeclaration_Status")
CEMSystemSiriDeclaration_Status = _Class("CEMSystemSiriDeclaration_Status")
CEMSystemSearchDeclaration_Status = _Class("CEMSystemSearchDeclaration_Status")
CEMSystemRatingsDeclaration_Status = _Class("CEMSystemRatingsDeclaration_Status")
CEMSystemNotificationsDeclaration_Status = _Class(
    "CEMSystemNotificationsDeclaration_Status"
)
CEMSystemNotificationsDeclaration_NotificationSettingsItem = _Class(
    "CEMSystemNotificationsDeclaration_NotificationSettingsItem"
)
CEMSystemMusicDeclaration_Status = _Class("CEMSystemMusicDeclaration_Status")
CEMSystemMigrationDeclaration_Status = _Class("CEMSystemMigrationDeclaration_Status")
CEMSystemMigrationDeclaration_CustomBehaviorItemPathsItem = _Class(
    "CEMSystemMigrationDeclaration_CustomBehaviorItemPathsItem"
)
CEMSystemMigrationDeclaration_CustomBehaviorItem = _Class(
    "CEMSystemMigrationDeclaration_CustomBehaviorItem"
)
CEMSystemKeyboardDeclaration_Status = _Class("CEMSystemKeyboardDeclaration_Status")
CEMSystemiCloudDeclaration_Status = _Class("CEMSystemiCloudDeclaration_Status")
CEMSystemGameCenterDeclaration_Status = _Class("CEMSystemGameCenterDeclaration_Status")
CEMSystemFontDeclaration_Status = _Class("CEMSystemFontDeclaration_Status")
CEMSystemEnergySaverDeclaration_Status = _Class(
    "CEMSystemEnergySaverDeclaration_Status"
)
CEMSystemEnergySaverDeclaration_RepeatingPowerItem = _Class(
    "CEMSystemEnergySaverDeclaration_RepeatingPowerItem"
)
CEMSystemEnergySaverDeclaration_EnergySaverSchedule = _Class(
    "CEMSystemEnergySaverDeclaration_EnergySaverSchedule"
)
CEMSystemEnergySaverDeclaration_PowerSettings = _Class(
    "CEMSystemEnergySaverDeclaration_PowerSettings"
)
CEMSystemDoNotDisturbDeclaration_Status = _Class(
    "CEMSystemDoNotDisturbDeclaration_Status"
)
CEMSystemDiskRecordingDeclaration_Status = _Class(
    "CEMSystemDiskRecordingDeclaration_Status"
)
CEMSystemDictionaryDeclaration_Status = _Class("CEMSystemDictionaryDeclaration_Status")
CEMSystemDateAndTimeDeclaration_Status = _Class(
    "CEMSystemDateAndTimeDeclaration_Status"
)
CEMSystemDashboardDeclaration_Status = _Class("CEMSystemDashboardDeclaration_Status")
CEMSystemDashboardDeclaration_WhiteListItem = _Class(
    "CEMSystemDashboardDeclaration_WhiteListItem"
)
CEMSystemCarPlayDeclaration_Status = _Class("CEMSystemCarPlayDeclaration_Status")
CEMSystemCameraDeclaration_Status = _Class("CEMSystemCameraDeclaration_Status")
CEMSystemBasicWebContentFilterDeclaration_Status = _Class(
    "CEMSystemBasicWebContentFilterDeclaration_Status"
)
CEMSystemBasicWebContentFilterDeclaration_SiteWhiteListItem = _Class(
    "CEMSystemBasicWebContentFilterDeclaration_SiteWhiteListItem"
)
CEMSystemAllowedMediaDeclaration_Status = _Class(
    "CEMSystemAllowedMediaDeclaration_Status"
)
CEMSystemAllowedMediaDeclaration_MediaItems = _Class(
    "CEMSystemAllowedMediaDeclaration_MediaItems"
)
CEMSystemAirPrintSettingsDeclaration_Status = _Class(
    "CEMSystemAirPrintSettingsDeclaration_Status"
)
CEMSystemAirPrintPrintersDeclaration_Status = _Class(
    "CEMSystemAirPrintPrintersDeclaration_Status"
)
CEMSystemAirPrintPrintersDeclaration_AirPrintItem = _Class(
    "CEMSystemAirPrintPrintersDeclaration_AirPrintItem"
)
CEMSystemAirPlaySettingsDeclaration_Status = _Class(
    "CEMSystemAirPlaySettingsDeclaration_Status"
)
CEMSystemAirPlaySecurityDeclaration_Status = _Class(
    "CEMSystemAirPlaySecurityDeclaration_Status"
)
CEMSystemAirPlayDestinationsDeclaration_Status = _Class(
    "CEMSystemAirPlayDestinationsDeclaration_Status"
)
CEMSystemAirPlayDestinationsDeclaration_PasswordsItem = _Class(
    "CEMSystemAirPlayDestinationsDeclaration_PasswordsItem"
)
CEMSystemAirPlayDestinationsDeclaration_WhitelistItem = _Class(
    "CEMSystemAirPlayDestinationsDeclaration_WhitelistItem"
)
CEMSystemAirdropDeclaration_Status = _Class("CEMSystemAirdropDeclaration_Status")
CEMStringDeclaration_Status = _Class("CEMStringDeclaration_Status")
CEMSecurityTimeLimitsDeclaration_Status = _Class(
    "CEMSecurityTimeLimitsDeclaration_Status"
)
CEMSecurityTimeLimitsDeclaration_Allowance = _Class(
    "CEMSecurityTimeLimitsDeclaration_Allowance"
)
CEMSecurityTimeLimitsDeclaration_TimeLimits = _Class(
    "CEMSecurityTimeLimitsDeclaration_TimeLimits"
)
CEMSecuritySmartCardDeclaration_Status = _Class(
    "CEMSecuritySmartCardDeclaration_Status"
)
CEMSecuritySingleSignOnDeclaration_Status = _Class(
    "CEMSecuritySingleSignOnDeclaration_Status"
)
CEMSecuritySingleSignOnDeclaration_Kerberos = _Class(
    "CEMSecuritySingleSignOnDeclaration_Kerberos"
)
CEMSecuritySettingsDeclaration_Status = _Class("CEMSecuritySettingsDeclaration_Status")
CEMSecurityInformationCommand_StatusSecurityInfoFirmwarePasswordStatus = _Class(
    "CEMSecurityInformationCommand_StatusSecurityInfoFirmwarePasswordStatus"
)
CEMSecurityInformationCommand_StatusSecurityInfoFirewallSettingsApplicationsItem = _Class(
    "CEMSecurityInformationCommand_StatusSecurityInfoFirewallSettingsApplicationsItem"
)
CEMSecurityInformationCommand_StatusSecurityInfoFirewallSettings = _Class(
    "CEMSecurityInformationCommand_StatusSecurityInfoFirewallSettings"
)
CEMSecurityInformationCommand_StatusSecurityInfo = _Class(
    "CEMSecurityInformationCommand_StatusSecurityInfo"
)
CEMSecurityInformationCommand_Status = _Class("CEMSecurityInformationCommand_Status")
CEMSecurityIdentityPreferenceDeclaration_Status = _Class(
    "CEMSecurityIdentityPreferenceDeclaration_Status"
)
CEMSecurityIdentityDeclaration_Status = _Class("CEMSecurityIdentityDeclaration_Status")
CEMSecurityFirewallDeclaration_Status = _Class("CEMSecurityFirewallDeclaration_Status")
CEMSecurityFirewallDeclaration_ApplicationsItem = _Class(
    "CEMSecurityFirewallDeclaration_ApplicationsItem"
)
CEMSecurityFDERecoveryKeyEscrowDeclaration_Status = _Class(
    "CEMSecurityFDERecoveryKeyEscrowDeclaration_Status"
)
CEMSecurityFDEFileVaultDeclaration_Status = _Class(
    "CEMSecurityFDEFileVaultDeclaration_Status"
)
CEMSecurityCertificatePreferenceDeclaration_Status = _Class(
    "CEMSecurityCertificatePreferenceDeclaration_Status"
)
CEMSecurityCertificateDeclaration_Status = _Class(
    "CEMSecurityCertificateDeclaration_Status"
)
CEMSecurityADCertificateDeclaration_Status = _Class(
    "CEMSecurityADCertificateDeclaration_Status"
)
CEMSecretCredentialsDeclaration = _Class("CEMSecretCredentialsDeclaration")
CEMProfileSettingsDeclaration_Status = _Class("CEMProfileSettingsDeclaration_Status")
CEMProfileInstallDeclaration_Status = _Class("CEMProfileInstallDeclaration_Status")
CEMPredicateCompositeBudget_TimeBudgetItem = _Class(
    "CEMPredicateCompositeBudget_TimeBudgetItem"
)
CEMPredicateCompositeBudget_Monitors = _Class("CEMPredicateCompositeBudget_Monitors")
CEMPredicateBudget_TimeBudgetItem = _Class("CEMPredicateBudget_TimeBudgetItem")
CEMPredicateBase = _Class("CEMPredicateBase")
CEMPredicateWeeklyTimeRange = _Class("CEMPredicateWeeklyTimeRange")
CEMPredicateTrue = _Class("CEMPredicateTrue")
CEMPredicateOneTime = _Class("CEMPredicateOneTime")
CEMPredicateNot = _Class("CEMPredicateNot")
CEMPredicateiCloudAccount = _Class("CEMPredicateiCloudAccount")
CEMPredicateFalse = _Class("CEMPredicateFalse")
CEMPredicateCompositeBudget = _Class("CEMPredicateCompositeBudget")
CEMPredicateBudget = _Class("CEMPredicateBudget")
CEMPredicateAny = _Class("CEMPredicateAny")
CEMPredicateAll = _Class("CEMPredicateAll")
CEMPolicyWebSiteSettingsDeclaration_Status = _Class(
    "CEMPolicyWebSiteSettingsDeclaration_Status"
)
CEMPolicyWebSiteDeclaration_Status = _Class("CEMPolicyWebSiteDeclaration_Status")
CEMPolicyiCloudAccountDeclaration_Status = _Class(
    "CEMPolicyiCloudAccountDeclaration_Status"
)
CEMPolicyCategorySettingsDeclaration_Status = _Class(
    "CEMPolicyCategorySettingsDeclaration_Status"
)
CEMPolicyCategoryDeclaration_Status = _Class("CEMPolicyCategoryDeclaration_Status")
CEMPolicyAppSettingsDeclaration_Status = _Class(
    "CEMPolicyAppSettingsDeclaration_Status"
)
CEMPolicyAppDeclaration_Status = _Class("CEMPolicyAppDeclaration_Status")
CEMAnyPayload = _Class("CEMAnyPayload")
CEMPasscodeVerifyFirmwarePasswordCommand_Status = _Class(
    "CEMPasscodeVerifyFirmwarePasswordCommand_Status"
)
CEMPasscodeSettingsDeclaration_Status = _Class("CEMPasscodeSettingsDeclaration_Status")
CEMPasscodeSetFirmwarePasswordCommand_Status = _Class(
    "CEMPasscodeSetFirmwarePasswordCommand_Status"
)
CEMPasscodeScreensaverUserDeclaration_Status = _Class(
    "CEMPasscodeScreensaverUserDeclaration_Status"
)
CEMPasscodeScreensaverDeclaration_Status = _Class(
    "CEMPasscodeScreensaverDeclaration_Status"
)
CEMPasscodeRequestUnlockTokenCommand_Status = _Class(
    "CEMPasscodeRequestUnlockTokenCommand_Status"
)
CEMPasscodeLoginWindowDeclaration_Status = _Class(
    "CEMPasscodeLoginWindowDeclaration_Status"
)
CEMPasscodeLockscreenSettingsDeclaration_Status = _Class(
    "CEMPasscodeLockscreenSettingsDeclaration_Status"
)
CEMPasscodeClearPasscodeCommand_Status = _Class(
    "CEMPasscodeClearPasscodeCommand_Status"
)
CEMNSExtensionsMappingsNSExtensionsCommand_StatusExtensionsItem = _Class(
    "CEMNSExtensionsMappingsNSExtensionsCommand_StatusExtensionsItem"
)
CEMNSExtensionsMappingsNSExtensionsCommand_Status = _Class(
    "CEMNSExtensionsMappingsNSExtensionsCommand_Status"
)
CEMNetworkWiFiDeclaration_Status = _Class("CEMNetworkWiFiDeclaration_Status")
CEMNetworkWiFiDeclaration_QoSMarkingPolicy = _Class(
    "CEMNetworkWiFiDeclaration_QoSMarkingPolicy"
)
CEMNetworkWiFiDeclaration_EAPClientConfiguration = _Class(
    "CEMNetworkWiFiDeclaration_EAPClientConfiguration"
)
CEMNetworkVPNAppToAppLayerMappingDeclaration_Status = _Class(
    "CEMNetworkVPNAppToAppLayerMappingDeclaration_Status"
)
CEMNetworkVPNAppToAppLayerMappingDeclaration_AppLayerVPNMappingItem = _Class(
    "CEMNetworkVPNAppToAppLayerMappingDeclaration_AppLayerVPNMappingItem"
)
CEMNetworkVPNAppLayerDeclaration_Status = _Class(
    "CEMNetworkVPNAppLayerDeclaration_Status"
)
CEMNetworkVPNDeclaration_Status = _Class("CEMNetworkVPNDeclaration_Status")
CEMNetworkVPNDeclaration_DNS = _Class("CEMNetworkVPNDeclaration_DNS")
CEMNetworkVPNDeclaration_AlwaysOnAllowedCaptiveNetworkPlugin = _Class(
    "CEMNetworkVPNDeclaration_AlwaysOnAllowedCaptiveNetworkPlugin"
)
CEMNetworkVPNDeclaration_AlwaysOnServiceException = _Class(
    "CEMNetworkVPNDeclaration_AlwaysOnServiceException"
)
CEMNetworkVPNDeclaration_AlwaysOnTunnelConfiguration = _Class(
    "CEMNetworkVPNDeclaration_AlwaysOnTunnelConfiguration"
)
CEMNetworkVPNDeclaration_AlwaysOn = _Class("CEMNetworkVPNDeclaration_AlwaysOn")
CEMNetworkVPNDeclaration_Proxies = _Class("CEMNetworkVPNDeclaration_Proxies")
CEMNetworkVPNDeclaration_SecurityAssociationParameters = _Class(
    "CEMNetworkVPNDeclaration_SecurityAssociationParameters"
)
CEMNetworkVPNDeclaration_IKEv2 = _Class("CEMNetworkVPNDeclaration_IKEv2")
CEMNetworkVPNDeclaration_IPSec = _Class("CEMNetworkVPNDeclaration_IPSec")
CEMNetworkVPNDeclaration_PPP = _Class("CEMNetworkVPNDeclaration_PPP")
CEMNetworkVPNDeclaration_IPv4 = _Class("CEMNetworkVPNDeclaration_IPv4")
CEMNetworkVPNDeclaration_OnDemandRulesElementActionParameters = _Class(
    "CEMNetworkVPNDeclaration_OnDemandRulesElementActionParameters"
)
CEMNetworkVPNDeclaration_OnDemandRulesElement = _Class(
    "CEMNetworkVPNDeclaration_OnDemandRulesElement"
)
CEMNetworkVPNDeclaration_VPN = _Class("CEMNetworkVPNDeclaration_VPN")
CEMNetworkVPNDeclaration_VendorConfig = _Class("CEMNetworkVPNDeclaration_VendorConfig")
CEMNetworkUsageRulesDeclaration_Status = _Class(
    "CEMNetworkUsageRulesDeclaration_Status"
)
CEMNetworkUsageRulesDeclaration_ApplicationRulesItem = _Class(
    "CEMNetworkUsageRulesDeclaration_ApplicationRulesItem"
)
CEMNetworkSettingsDeclaration_Status = _Class("CEMNetworkSettingsDeclaration_Status")
CEMNetworkHostNameDeclaration_Status = _Class("CEMNetworkHostNameDeclaration_Status")
CEMNetworkGlobalHTTPProxyDeclaration_Status = _Class(
    "CEMNetworkGlobalHTTPProxyDeclaration_Status"
)
CEMNetworkDomainsDeclaration_Status = _Class("CEMNetworkDomainsDeclaration_Status")
CEMNetworkDNSProxyDeclaration_Status = _Class("CEMNetworkDNSProxyDeclaration_Status")
CEMNetworkDirectoryServiceDeclaration_Status = _Class(
    "CEMNetworkDirectoryServiceDeclaration_Status"
)
CEMNetworkContentCachingDeclaration_Status = _Class(
    "CEMNetworkContentCachingDeclaration_Status"
)
CEMNetworkContentCachingDeclaration_Ranges = _Class(
    "CEMNetworkContentCachingDeclaration_Ranges"
)
CEMNetworkCellularSettingsDeclaration_Status = _Class(
    "CEMNetworkCellularSettingsDeclaration_Status"
)
CEMNetworkCellularDeclaration_Status = _Class("CEMNetworkCellularDeclaration_Status")
CEMNetworkCellularDeclaration_APNsItem = _Class(
    "CEMNetworkCellularDeclaration_APNsItem"
)
CEMNetworkCellularDeclaration_AttachAPN = _Class(
    "CEMNetworkCellularDeclaration_AttachAPN"
)
CEMNetworkBluetoothDeclaration_Status = _Class("CEMNetworkBluetoothDeclaration_Status")
CEMNetwork8021XThirdEthernetDeclaration_Status = _Class(
    "CEMNetwork8021XThirdEthernetDeclaration_Status"
)
CEMNetwork8021XThirdActiveEthernetDeclaration_Status = _Class(
    "CEMNetwork8021XThirdActiveEthernetDeclaration_Status"
)
CEMNetwork8021XSecondEthernetDeclaration_Status = _Class(
    "CEMNetwork8021XSecondEthernetDeclaration_Status"
)
CEMNetwork8021XSecondActiveEthernetDeclaration_Status = _Class(
    "CEMNetwork8021XSecondActiveEthernetDeclaration_Status"
)
CEMNetwork8021XGlobalEthernetDeclaration_Status = _Class(
    "CEMNetwork8021XGlobalEthernetDeclaration_Status"
)
CEMNetwork8021XFirstEthernetDeclaration_Status = _Class(
    "CEMNetwork8021XFirstEthernetDeclaration_Status"
)
CEMNetwork8021XFirstActiveEthernetDeclaration_Status = _Class(
    "CEMNetwork8021XFirstActiveEthernetDeclaration_Status"
)
CEMNetwork8021XBuiltinWirelessDeclaration_Status = _Class(
    "CEMNetwork8021XBuiltinWirelessDeclaration_Status"
)
CEMMediaSettingsDeclaration_Status = _Class("CEMMediaSettingsDeclaration_Status")
CEMMediaInstallDeclaration_Status = _Class("CEMMediaInstallDeclaration_Status")
CEMManagementUpdateEnrollmentCommand_Status = _Class(
    "CEMManagementUpdateEnrollmentCommand_Status"
)
CEMManagementTestMessageMessage_Reply = _Class("CEMManagementTestMessageMessage_Reply")
CEMMessageBase = _Class("CEMMessageBase")
CEMManagementTestMessageMessage = _Class("CEMManagementTestMessageMessage")
CEMManagementTestEvent_EventMessage = _Class("CEMManagementTestEvent_EventMessage")
CEMManagementTestCommandCommand_Status = _Class(
    "CEMManagementTestCommandCommand_Status"
)
CEMManagementTestDeclaration_Status = _Class("CEMManagementTestDeclaration_Status")
CEMManagementStateCommand_Status = _Class("CEMManagementStateCommand_Status")
CEMManagementRetryActivatedConfigurationCommand_Status = _Class(
    "CEMManagementRetryActivatedConfigurationCommand_Status"
)
CEMManagementRefreshStatusCommand_Status = _Class(
    "CEMManagementRefreshStatusCommand_Status"
)
CEMManagementOrganizationInformationDeclaration_Status = _Class(
    "CEMManagementOrganizationInformationDeclaration_Status"
)
CEMManagementConfiguredCommand_Status = _Class("CEMManagementConfiguredCommand_Status")
CEMLegacyRestrictionsAppsDeclaration_Status = _Class(
    "CEMLegacyRestrictionsAppsDeclaration_Status"
)
CEMImageDeclaration_Status = _Class("CEMImageDeclaration_Status")
CEMFontDeclaration_Status = _Class("CEMFontDeclaration_Status")
CEMEventSubscriptionNowCommand_Status = _Class("CEMEventSubscriptionNowCommand_Status")
CEMEventSubscriptionDeclaration_Status = _Class(
    "CEMEventSubscriptionDeclaration_Status"
)
CEMEventSubscriptionDeclaration_Schedule = _Class(
    "CEMEventSubscriptionDeclaration_Schedule"
)
CEMEventBase = _Class("CEMEventBase")
CEMManagementTestEvent = _Class("CEMManagementTestEvent")
CEMDeviceWallpaperDeclaration_Status = _Class("CEMDeviceWallpaperDeclaration_Status")
CEMDeviceShutDownCommand_Status = _Class("CEMDeviceShutDownCommand_Status")
CEMDeviceRestartCommand_Status = _Class("CEMDeviceRestartCommand_Status")
CEMDevicePlayLostModeSoundCommand_Status = _Class(
    "CEMDevicePlayLostModeSoundCommand_Status"
)
CEMDeviceNameDeclaration_Status = _Class("CEMDeviceNameDeclaration_Status")
CEMDeviceLostmodeLocationCommand_Status = _Class(
    "CEMDeviceLostmodeLocationCommand_Status"
)
CEMDeviceLostModeDeclaration_Status = _Class("CEMDeviceLostModeDeclaration_Status")
CEMDeviceLockCommand_Status = _Class("CEMDeviceLockCommand_Status")
CEMDeviceListRestrictionsCommand_StatusProfileRestrictions = _Class(
    "CEMDeviceListRestrictionsCommand_StatusProfileRestrictions"
)
CEMDeviceListRestrictionsCommand_StatusIntersectionDictionaryANYrestrictionname = _Class(
    "CEMDeviceListRestrictionsCommand_StatusIntersectionDictionaryANYrestrictionname"
)
CEMDeviceListRestrictionsCommand_StatusIntersectionDictionary = _Class(
    "CEMDeviceListRestrictionsCommand_StatusIntersectionDictionary"
)
CEMDeviceListRestrictionsCommand_StatusValueDictionaryANYrestrictionname = _Class(
    "CEMDeviceListRestrictionsCommand_StatusValueDictionaryANYrestrictionname"
)
CEMDeviceListRestrictionsCommand_StatusValueDictionary = _Class(
    "CEMDeviceListRestrictionsCommand_StatusValueDictionary"
)
CEMDeviceListRestrictionsCommand_StatusBooleanDictionaryANYrestrictionname = _Class(
    "CEMDeviceListRestrictionsCommand_StatusBooleanDictionaryANYrestrictionname"
)
CEMDeviceListRestrictionsCommand_StatusBooleanDictionary = _Class(
    "CEMDeviceListRestrictionsCommand_StatusBooleanDictionary"
)
CEMDeviceListRestrictionsCommand_StatusRestrictionsDictionary = _Class(
    "CEMDeviceListRestrictionsCommand_StatusRestrictionsDictionary"
)
CEMDeviceListRestrictionsCommand_Status = _Class(
    "CEMDeviceListRestrictionsCommand_Status"
)
CEMDeviceInformationCommand_StatusErrorResponsesItem = _Class(
    "CEMDeviceInformationCommand_StatusErrorResponsesItem"
)
CEMDeviceInformationCommand_StatusErrorResponses = _Class(
    "CEMDeviceInformationCommand_StatusErrorResponses"
)
CEMDeviceInformationCommand_StatusQueryResponsesAutoSetupAdminAccountsItem = _Class(
    "CEMDeviceInformationCommand_StatusQueryResponsesAutoSetupAdminAccountsItem"
)
CEMDeviceInformationCommand_StatusQueryResponsesOSUpdateSettings = _Class(
    "CEMDeviceInformationCommand_StatusQueryResponsesOSUpdateSettings"
)
CEMDeviceInformationCommand_StatusQueryResponsesOrganizationInfo = _Class(
    "CEMDeviceInformationCommand_StatusQueryResponsesOrganizationInfo"
)
CEMDeviceInformationCommand_StatusQueryResponses = _Class(
    "CEMDeviceInformationCommand_StatusQueryResponses"
)
CEMDeviceInformationCommand_Status = _Class("CEMDeviceInformationCommand_Status")
CEMDeviceHomeScreenLayoutDeclaration_Status = _Class(
    "CEMDeviceHomeScreenLayoutDeclaration_Status"
)
CEMDeviceHomeScreenLayoutDeclaration_IconItem = _Class(
    "CEMDeviceHomeScreenLayoutDeclaration_IconItem"
)
CEMDeviceeSIMCellularPlanManagementCommand_Status = _Class(
    "CEMDeviceeSIMCellularPlanManagementCommand_Status"
)
CEMDeviceEraseCommand_Status = _Class("CEMDeviceEraseCommand_Status")
CEMDeviceDockDeclaration_Status = _Class("CEMDeviceDockDeclaration_Status")
CEMDeviceDockDeclaration_StaticItemTileData = _Class(
    "CEMDeviceDockDeclaration_StaticItemTileData"
)
CEMDeviceDockDeclaration_StaticItem = _Class("CEMDeviceDockDeclaration_StaticItem")
CEMDeviceDesktopDeclaration_Status = _Class("CEMDeviceDesktopDeclaration_Status")
CEMDeviceConferenceRoomDisplayDeclaration_Status = _Class(
    "CEMDeviceConferenceRoomDisplayDeclaration_Status"
)
CEMDeviceClearRestrictionsPasswordCommand_Status = _Class(
    "CEMDeviceClearRestrictionsPasswordCommand_Status"
)
CEMDeviceClearActivationLockBypassCodeCommand_Status = _Class(
    "CEMDeviceClearActivationLockBypassCodeCommand_Status"
)
CEMDeviceActivationLockSettingsDeclaration_Status = _Class(
    "CEMDeviceActivationLockSettingsDeclaration_Status"
)
CEMDeviceActivationLockBypassCodeCommand_Status = _Class(
    "CEMDeviceActivationLockBypassCodeCommand_Status"
)
CEMCredentialUserNameAndPasswordDeclaration_Status = _Class(
    "CEMCredentialUserNameAndPasswordDeclaration_Status"
)
CEMCredentialSecretDeclaration_Status = _Class("CEMCredentialSecretDeclaration_Status")
CEMCredentialSCEPDeclaration_Status = _Class("CEMCredentialSCEPDeclaration_Status")
CEMCredentialSCEPDeclaration_SCEPSubjectAltName = _Class(
    "CEMCredentialSCEPDeclaration_SCEPSubjectAltName"
)
CEMCredentialSCEPDeclaration_SCEP = _Class("CEMCredentialSCEPDeclaration_SCEP")
CEMCredentialCertificateIdentityDeclaration_Status = _Class(
    "CEMCredentialCertificateIdentityDeclaration_Status"
)
CEMClassroomUnlockUserAccountCommand_Status = _Class(
    "CEMClassroomUnlockUserAccountCommand_Status"
)
CEMClassroomStopMirroringCommand_Status = _Class(
    "CEMClassroomStopMirroringCommand_Status"
)
CEMClassroomRequestMirroringCommand_Status = _Class(
    "CEMClassroomRequestMirroringCommand_Status"
)
CEMClassroomLogOutUserCommand_Status = _Class("CEMClassroomLogOutUserCommand_Status")
CEMClassroomDeleteUserCommand_Status = _Class("CEMClassroomDeleteUserCommand_Status")
CEMCertificateIdentityCredentialsDeclaration = _Class(
    "CEMCertificateIdentityCredentialsDeclaration"
)
CEMCertificateDeclaration_Status = _Class("CEMCertificateDeclaration_Status")
CEMBookEnterpriseDeclaration_Status = _Class("CEMBookEnterpriseDeclaration_Status")
CEMBookBookStoreDeclaration_Status = _Class("CEMBookBookStoreDeclaration_Status")
CEMAssetBaseReference = _Class("CEMAssetBaseReference")
CEMAssetBaseDescriptor = _Class("CEMAssetBaseDescriptor")
CEMApplicationValidateApplicationsCommand_Status = _Class(
    "CEMApplicationValidateApplicationsCommand_Status"
)
CEMApplicationUpdateApplicationCommand_Status = _Class(
    "CEMApplicationUpdateApplicationCommand_Status"
)
CEMApplicationStoreMacOSDeclaration_Status = _Class(
    "CEMApplicationStoreMacOSDeclaration_Status"
)
CEMApplicationStoreDeclaration_Status = _Class("CEMApplicationStoreDeclaration_Status")
CEMApplicationSettingsManagedDeclaration_Status = _Class(
    "CEMApplicationSettingsManagedDeclaration_Status"
)
CEMApplicationSettingsDeclaration_Status = _Class(
    "CEMApplicationSettingsDeclaration_Status"
)
CEMApplicationRemoveApplicationCommand_Status = _Class(
    "CEMApplicationRemoveApplicationCommand_Status"
)
CEMApplicationLoginItemsDeclaration_Status = _Class(
    "CEMApplicationLoginItemsDeclaration_Status"
)
CEMApplicationLoginItemsDeclaration_LoginItem = _Class(
    "CEMApplicationLoginItemsDeclaration_LoginItem"
)
CEMApplicationLockDeclaration_Status = _Class("CEMApplicationLockDeclaration_Status")
CEMApplicationLockDeclaration_AppUserEnabledOptions = _Class(
    "CEMApplicationLockDeclaration_AppUserEnabledOptions"
)
CEMApplicationLockDeclaration_AppOptions = _Class(
    "CEMApplicationLockDeclaration_AppOptions"
)
CEMApplicationLockDeclaration_App = _Class("CEMApplicationLockDeclaration_App")
CEMApplicationListInstalledApplicationsCommand_StatusInstalledApplicationListItem = _Class(
    "CEMApplicationListInstalledApplicationsCommand_StatusInstalledApplicationListItem"
)
CEMApplicationListInstalledApplicationsCommand_Status = _Class(
    "CEMApplicationListInstalledApplicationsCommand_Status"
)
CEMApplicationListActiveNSExtensionsCommand_StatusExtensionsItem = _Class(
    "CEMApplicationListActiveNSExtensionsCommand_StatusExtensionsItem"
)
CEMApplicationListActiveNSExtensionsCommand_Status = _Class(
    "CEMApplicationListActiveNSExtensionsCommand_Status"
)
CEMApplicationInviteToProgramCommand_Status = _Class(
    "CEMApplicationInviteToProgramCommand_Status"
)
CEMCommandBase = _Class("CEMCommandBase")
CEMSecurityInformationCommand = _Class("CEMSecurityInformationCommand")
CEMPasscodeVerifyFirmwarePasswordCommand = _Class(
    "CEMPasscodeVerifyFirmwarePasswordCommand"
)
CEMPasscodeSetFirmwarePasswordCommand = _Class("CEMPasscodeSetFirmwarePasswordCommand")
CEMPasscodeRequestUnlockTokenCommand = _Class("CEMPasscodeRequestUnlockTokenCommand")
CEMPasscodeClearPasscodeCommand = _Class("CEMPasscodeClearPasscodeCommand")
CEMNSExtensionsMappingsNSExtensionsCommand = _Class(
    "CEMNSExtensionsMappingsNSExtensionsCommand"
)
CEMManagementUpdateEnrollmentCommand = _Class("CEMManagementUpdateEnrollmentCommand")
CEMManagementTestCommandCommand = _Class("CEMManagementTestCommandCommand")
CEMManagementStateCommand = _Class("CEMManagementStateCommand")
CEMManagementRetryActivatedConfigurationCommand = _Class(
    "CEMManagementRetryActivatedConfigurationCommand"
)
CEMManagementRefreshStatusCommand = _Class("CEMManagementRefreshStatusCommand")
CEMManagementConfiguredCommand = _Class("CEMManagementConfiguredCommand")
CEMEventSubscriptionNowCommand = _Class("CEMEventSubscriptionNowCommand")
CEMDeviceShutDownCommand = _Class("CEMDeviceShutDownCommand")
CEMDeviceRestartCommand = _Class("CEMDeviceRestartCommand")
CEMDevicePlayLostModeSoundCommand = _Class("CEMDevicePlayLostModeSoundCommand")
CEMDeviceLostmodeLocationCommand = _Class("CEMDeviceLostmodeLocationCommand")
CEMDeviceLockCommand = _Class("CEMDeviceLockCommand")
CEMDeviceListRestrictionsCommand = _Class("CEMDeviceListRestrictionsCommand")
CEMDeviceInformationCommand = _Class("CEMDeviceInformationCommand")
CEMDeviceeSIMCellularPlanManagementCommand = _Class(
    "CEMDeviceeSIMCellularPlanManagementCommand"
)
CEMDeviceEraseCommand = _Class("CEMDeviceEraseCommand")
CEMDeviceClearRestrictionsPasswordCommand = _Class(
    "CEMDeviceClearRestrictionsPasswordCommand"
)
CEMDeviceClearActivationLockBypassCodeCommand = _Class(
    "CEMDeviceClearActivationLockBypassCodeCommand"
)
CEMDeviceActivationLockBypassCodeCommand = _Class(
    "CEMDeviceActivationLockBypassCodeCommand"
)
CEMClassroomUnlockUserAccountCommand = _Class("CEMClassroomUnlockUserAccountCommand")
CEMClassroomStopMirroringCommand = _Class("CEMClassroomStopMirroringCommand")
CEMClassroomRequestMirroringCommand = _Class("CEMClassroomRequestMirroringCommand")
CEMClassroomLogOutUserCommand = _Class("CEMClassroomLogOutUserCommand")
CEMClassroomDeleteUserCommand = _Class("CEMClassroomDeleteUserCommand")
CEMApplicationValidateApplicationsCommand = _Class(
    "CEMApplicationValidateApplicationsCommand"
)
CEMApplicationUpdateApplicationCommand = _Class(
    "CEMApplicationUpdateApplicationCommand"
)
CEMApplicationRemoveApplicationCommand = _Class(
    "CEMApplicationRemoveApplicationCommand"
)
CEMApplicationListInstalledApplicationsCommand = _Class(
    "CEMApplicationListInstalledApplicationsCommand"
)
CEMApplicationListActiveNSExtensionsCommand = _Class(
    "CEMApplicationListActiveNSExtensionsCommand"
)
CEMApplicationInviteToProgramCommand = _Class("CEMApplicationInviteToProgramCommand")
CEMApplicationInstallDeclaration_Status = _Class(
    "CEMApplicationInstallDeclaration_Status"
)
CEMApplicationExtensionsDeclaration_Status = _Class(
    "CEMApplicationExtensionsDeclaration_Status"
)
CEMApplicationEnterpriseDeclaration_Status = _Class(
    "CEMApplicationEnterpriseDeclaration_Status"
)
CEMApplicationEnterpriseDeclaration_AppPackage = _Class(
    "CEMApplicationEnterpriseDeclaration_AppPackage"
)
CEMApplicationControlDeclaration_Status = _Class(
    "CEMApplicationControlDeclaration_Status"
)
CEMApplicationControlDeclaration_UpdateSchedule = _Class(
    "CEMApplicationControlDeclaration_UpdateSchedule"
)
CEMApplicationControlDeclaration_InstallSchedule = _Class(
    "CEMApplicationControlDeclaration_InstallSchedule"
)
CEMApplicationAutonomousSingleAppModeDeclaration_Status = _Class(
    "CEMApplicationAutonomousSingleAppModeDeclaration_Status"
)
CEMApplicationAutonomousSingleAppModeDeclaration_AllowedApplicationsItem = _Class(
    "CEMApplicationAutonomousSingleAppModeDeclaration_AllowedApplicationsItem"
)
CEMApplicationAppStoreDeclaration_Status = _Class(
    "CEMApplicationAppStoreDeclaration_Status"
)
CEMApplicationAnyDeclaration_Status = _Class("CEMApplicationAnyDeclaration_Status")
CEMActivationSimpleDeclaration_StatusInstalledConfigurationsItem = _Class(
    "CEMActivationSimpleDeclaration_StatusInstalledConfigurationsItem"
)
CEMActivationSimpleDeclaration_Status = _Class("CEMActivationSimpleDeclaration_Status")
CEMActivationBasicDeclaration_StatusInstalledConfigurationsItem = _Class(
    "CEMActivationBasicDeclaration_StatusInstalledConfigurationsItem"
)
CEMActivationBasicDeclaration_Status = _Class("CEMActivationBasicDeclaration_Status")
CEMActivationAdvancedDeclaration_StatusInstalledConfigurationsItem = _Class(
    "CEMActivationAdvancedDeclaration_StatusInstalledConfigurationsItem"
)
CEMActivationAdvancedDeclaration_Status = _Class(
    "CEMActivationAdvancedDeclaration_Status"
)
CEMActivationAdvancedDeclaration_ConfigurationsItem = _Class(
    "CEMActivationAdvancedDeclaration_ConfigurationsItem"
)
CEMAccountWebClipDeclaration_Status = _Class("CEMAccountWebClipDeclaration_Status")
CEMAccountSubscribedCalendarDeclaration_Status = _Class(
    "CEMAccountSubscribedCalendarDeclaration_Status"
)
CEMAccountSettingsDeclaration_Status = _Class("CEMAccountSettingsDeclaration_Status")
CEMAccountMailDeclaration_Status = _Class("CEMAccountMailDeclaration_Status")
CEMAccountmacOSServerDeclaration_Status = _Class(
    "CEMAccountmacOSServerDeclaration_Status"
)
CEMAccountmacOSServerDeclaration_ConfiguredAccountsItem = _Class(
    "CEMAccountmacOSServerDeclaration_ConfiguredAccountsItem"
)
CEMAccountLDAPDeclaration_Status = _Class("CEMAccountLDAPDeclaration_Status")
CEMAccountLDAPDeclaration_CommunicationServiceRulesDefaultServiceHandlers = _Class(
    "CEMAccountLDAPDeclaration_CommunicationServiceRulesDefaultServiceHandlers"
)
CEMAccountLDAPDeclaration_CommunicationServiceRules = _Class(
    "CEMAccountLDAPDeclaration_CommunicationServiceRules"
)
CEMAccountLDAPDeclaration_LDAPSearchSettingsItem = _Class(
    "CEMAccountLDAPDeclaration_LDAPSearchSettingsItem"
)
CEMAccountGoogleDeclaration_Status = _Class("CEMAccountGoogleDeclaration_Status")
CEMAccountGoogleDeclaration_CommunicationServiceRulesDefaultServiceHandlers = _Class(
    "CEMAccountGoogleDeclaration_CommunicationServiceRulesDefaultServiceHandlers"
)
CEMAccountGoogleDeclaration_CommunicationServiceRules = _Class(
    "CEMAccountGoogleDeclaration_CommunicationServiceRules"
)
CEMAccountCardDAVDeclaration_Status = _Class("CEMAccountCardDAVDeclaration_Status")
CEMAccountCardDAVDeclaration_CommunicationServiceRulesDefaultServiceHandlers = _Class(
    "CEMAccountCardDAVDeclaration_CommunicationServiceRulesDefaultServiceHandlers"
)
CEMAccountCardDAVDeclaration_CommunicationServiceRules = _Class(
    "CEMAccountCardDAVDeclaration_CommunicationServiceRules"
)
CEMAccountCalDAVDeclaration_Status = _Class("CEMAccountCalDAVDeclaration_Status")
CEMDeclarationBase = _Class("CEMDeclarationBase")
CEMAssetBase = _Class("CEMAssetBase")
CEMStringDeclaration = _Class("CEMStringDeclaration")
CEMImageDeclaration = _Class("CEMImageDeclaration")
CEMFontDeclaration = _Class("CEMFontDeclaration")
CEMCredentialUserNameAndPasswordDeclaration = _Class(
    "CEMCredentialUserNameAndPasswordDeclaration"
)
CEMCredentialSecretDeclaration = _Class("CEMCredentialSecretDeclaration")
CEMCredentialSCEPDeclaration = _Class("CEMCredentialSCEPDeclaration")
CEMCredentialCertificateIdentityDeclaration = _Class(
    "CEMCredentialCertificateIdentityDeclaration"
)
CEMCertificateDeclaration = _Class("CEMCertificateDeclaration")
CEMBookEnterpriseDeclaration = _Class("CEMBookEnterpriseDeclaration")
CEMBookBookStoreDeclaration = _Class("CEMBookBookStoreDeclaration")
CEMApplicationEnterpriseDeclaration = _Class("CEMApplicationEnterpriseDeclaration")
CEMApplicationAppStoreDeclaration = _Class("CEMApplicationAppStoreDeclaration")
CEMApplicationAnyDeclaration = _Class("CEMApplicationAnyDeclaration")
CEMActivationSimpleDeclaration = _Class("CEMActivationSimpleDeclaration")
CEMActivationBasicDeclaration = _Class("CEMActivationBasicDeclaration")
CEMActivationAdvancedDeclaration = _Class("CEMActivationAdvancedDeclaration")
CEMConfigurationBase = _Class("CEMConfigurationBase")
CEMSystemXsanVolumePreferencesDeclaration = _Class(
    "CEMSystemXsanVolumePreferencesDeclaration"
)
CEMSystemXsanSettingsDeclaration = _Class("CEMSystemXsanSettingsDeclaration")
CEMSystemWebContentFilterDeclaration = _Class("CEMSystemWebContentFilterDeclaration")
CEMSystemWebDeclaration = _Class("CEMSystemWebDeclaration")
CEMSystemWatchDeclaration = _Class("CEMSystemWatchDeclaration")
CEMSystemTVRemoteDeclaration = _Class("CEMSystemTVRemoteDeclaration")
CEMSystemTVProviderDeclaration = _Class("CEMSystemTVProviderDeclaration")
CEMSystemTimeServerDeclaration = _Class("CEMSystemTimeServerDeclaration")
CEMSystemSiriDeclaration = _Class("CEMSystemSiriDeclaration")
CEMSystemSearchDeclaration = _Class("CEMSystemSearchDeclaration")
CEMSystemRatingsDeclaration = _Class("CEMSystemRatingsDeclaration")
CEMSystemNotificationsDeclaration = _Class("CEMSystemNotificationsDeclaration")
CEMSystemMusicDeclaration = _Class("CEMSystemMusicDeclaration")
CEMSystemMigrationDeclaration = _Class("CEMSystemMigrationDeclaration")
CEMSystemKeyboardDeclaration = _Class("CEMSystemKeyboardDeclaration")
CEMSystemiCloudDeclaration = _Class("CEMSystemiCloudDeclaration")
CEMSystemGameCenterDeclaration = _Class("CEMSystemGameCenterDeclaration")
CEMSystemFontDeclaration = _Class("CEMSystemFontDeclaration")
CEMSystemEnergySaverDeclaration = _Class("CEMSystemEnergySaverDeclaration")
CEMSystemDoNotDisturbDeclaration = _Class("CEMSystemDoNotDisturbDeclaration")
CEMSystemDiskRecordingDeclaration = _Class("CEMSystemDiskRecordingDeclaration")
CEMSystemDictionaryDeclaration = _Class("CEMSystemDictionaryDeclaration")
CEMSystemDateAndTimeDeclaration = _Class("CEMSystemDateAndTimeDeclaration")
CEMSystemDashboardDeclaration = _Class("CEMSystemDashboardDeclaration")
CEMSystemCarPlayDeclaration = _Class("CEMSystemCarPlayDeclaration")
CEMSystemCameraDeclaration = _Class("CEMSystemCameraDeclaration")
CEMSystemBasicWebContentFilterDeclaration = _Class(
    "CEMSystemBasicWebContentFilterDeclaration"
)
CEMSystemAllowedMediaDeclaration = _Class("CEMSystemAllowedMediaDeclaration")
CEMSystemAirPrintSettingsDeclaration = _Class("CEMSystemAirPrintSettingsDeclaration")
CEMSystemAirPrintPrintersDeclaration = _Class("CEMSystemAirPrintPrintersDeclaration")
CEMSystemAirPlaySettingsDeclaration = _Class("CEMSystemAirPlaySettingsDeclaration")
CEMSystemAirPlaySecurityDeclaration = _Class("CEMSystemAirPlaySecurityDeclaration")
CEMSystemAirPlayDestinationsDeclaration = _Class(
    "CEMSystemAirPlayDestinationsDeclaration"
)
CEMSystemAirdropDeclaration = _Class("CEMSystemAirdropDeclaration")
CEMSecurityTimeLimitsDeclaration = _Class("CEMSecurityTimeLimitsDeclaration")
CEMSecuritySmartCardDeclaration = _Class("CEMSecuritySmartCardDeclaration")
CEMSecuritySingleSignOnDeclaration = _Class("CEMSecuritySingleSignOnDeclaration")
CEMSecuritySettingsDeclaration = _Class("CEMSecuritySettingsDeclaration")
CEMSecurityIdentityPreferenceDeclaration = _Class(
    "CEMSecurityIdentityPreferenceDeclaration"
)
CEMSecurityIdentityDeclaration = _Class("CEMSecurityIdentityDeclaration")
CEMSecurityFirewallDeclaration = _Class("CEMSecurityFirewallDeclaration")
CEMSecurityFDERecoveryKeyEscrowDeclaration = _Class(
    "CEMSecurityFDERecoveryKeyEscrowDeclaration"
)
CEMSecurityFDEFileVaultDeclaration = _Class("CEMSecurityFDEFileVaultDeclaration")
CEMSecurityCertificatePreferenceDeclaration = _Class(
    "CEMSecurityCertificatePreferenceDeclaration"
)
CEMSecurityCertificateDeclaration = _Class("CEMSecurityCertificateDeclaration")
CEMSecurityADCertificateDeclaration = _Class("CEMSecurityADCertificateDeclaration")
CEMProfileSettingsDeclaration = _Class("CEMProfileSettingsDeclaration")
CEMProfileInstallDeclaration = _Class("CEMProfileInstallDeclaration")
CEMPolicyWebSiteSettingsDeclaration = _Class("CEMPolicyWebSiteSettingsDeclaration")
CEMPolicyWebSiteDeclaration = _Class("CEMPolicyWebSiteDeclaration")
CEMPolicyiCloudAccountDeclaration = _Class("CEMPolicyiCloudAccountDeclaration")
CEMPolicyCategorySettingsDeclaration = _Class("CEMPolicyCategorySettingsDeclaration")
CEMPolicyCategoryDeclaration = _Class("CEMPolicyCategoryDeclaration")
CEMPolicyAppSettingsDeclaration = _Class("CEMPolicyAppSettingsDeclaration")
CEMPolicyAppDeclaration = _Class("CEMPolicyAppDeclaration")
CEMPasscodeSettingsDeclaration = _Class("CEMPasscodeSettingsDeclaration")
CEMPasscodeScreensaverUserDeclaration = _Class("CEMPasscodeScreensaverUserDeclaration")
CEMPasscodeScreensaverDeclaration = _Class("CEMPasscodeScreensaverDeclaration")
CEMPasscodeLoginWindowDeclaration = _Class("CEMPasscodeLoginWindowDeclaration")
CEMPasscodeLockscreenSettingsDeclaration = _Class(
    "CEMPasscodeLockscreenSettingsDeclaration"
)
CEMNetworkWiFiDeclaration = _Class("CEMNetworkWiFiDeclaration")
CEMNetworkVPNAppToAppLayerMappingDeclaration = _Class(
    "CEMNetworkVPNAppToAppLayerMappingDeclaration"
)
CEMNetworkVPNAppLayerDeclaration = _Class("CEMNetworkVPNAppLayerDeclaration")
CEMNetworkVPNDeclaration = _Class("CEMNetworkVPNDeclaration")
CEMNetworkUsageRulesDeclaration = _Class("CEMNetworkUsageRulesDeclaration")
CEMNetworkSettingsDeclaration = _Class("CEMNetworkSettingsDeclaration")
CEMNetworkHostNameDeclaration = _Class("CEMNetworkHostNameDeclaration")
CEMNetworkGlobalHTTPProxyDeclaration = _Class("CEMNetworkGlobalHTTPProxyDeclaration")
CEMNetworkDomainsDeclaration = _Class("CEMNetworkDomainsDeclaration")
CEMNetworkDNSProxyDeclaration = _Class("CEMNetworkDNSProxyDeclaration")
CEMNetworkDirectoryServiceDeclaration = _Class("CEMNetworkDirectoryServiceDeclaration")
CEMNetworkContentCachingDeclaration = _Class("CEMNetworkContentCachingDeclaration")
CEMNetworkCellularSettingsDeclaration = _Class("CEMNetworkCellularSettingsDeclaration")
CEMNetworkCellularDeclaration = _Class("CEMNetworkCellularDeclaration")
CEMNetworkBluetoothDeclaration = _Class("CEMNetworkBluetoothDeclaration")
CEMNetwork8021XThirdEthernetDeclaration = _Class(
    "CEMNetwork8021XThirdEthernetDeclaration"
)
CEMNetwork8021XThirdActiveEthernetDeclaration = _Class(
    "CEMNetwork8021XThirdActiveEthernetDeclaration"
)
CEMNetwork8021XSecondEthernetDeclaration = _Class(
    "CEMNetwork8021XSecondEthernetDeclaration"
)
CEMNetwork8021XSecondActiveEthernetDeclaration = _Class(
    "CEMNetwork8021XSecondActiveEthernetDeclaration"
)
CEMNetwork8021XGlobalEthernetDeclaration = _Class(
    "CEMNetwork8021XGlobalEthernetDeclaration"
)
CEMNetwork8021XFirstEthernetDeclaration = _Class(
    "CEMNetwork8021XFirstEthernetDeclaration"
)
CEMNetwork8021XFirstActiveEthernetDeclaration = _Class(
    "CEMNetwork8021XFirstActiveEthernetDeclaration"
)
CEMNetwork8021XBuiltinWirelessDeclaration = _Class(
    "CEMNetwork8021XBuiltinWirelessDeclaration"
)
CEMMediaSettingsDeclaration = _Class("CEMMediaSettingsDeclaration")
CEMMediaInstallDeclaration = _Class("CEMMediaInstallDeclaration")
CEMManagementTestDeclaration = _Class("CEMManagementTestDeclaration")
CEMManagementOrganizationInformationDeclaration = _Class(
    "CEMManagementOrganizationInformationDeclaration"
)
CEMLegacyRestrictionsAppsDeclaration = _Class("CEMLegacyRestrictionsAppsDeclaration")
CEMEventSubscriptionDeclaration = _Class("CEMEventSubscriptionDeclaration")
CEMDeviceWallpaperDeclaration = _Class("CEMDeviceWallpaperDeclaration")
CEMDeviceNameDeclaration = _Class("CEMDeviceNameDeclaration")
CEMDeviceLostModeDeclaration = _Class("CEMDeviceLostModeDeclaration")
CEMDeviceHomeScreenLayoutDeclaration = _Class("CEMDeviceHomeScreenLayoutDeclaration")
CEMDeviceDockDeclaration = _Class("CEMDeviceDockDeclaration")
CEMDeviceDesktopDeclaration = _Class("CEMDeviceDesktopDeclaration")
CEMDeviceConferenceRoomDisplayDeclaration = _Class(
    "CEMDeviceConferenceRoomDisplayDeclaration"
)
CEMDeviceActivationLockSettingsDeclaration = _Class(
    "CEMDeviceActivationLockSettingsDeclaration"
)
CEMApplicationStoreMacOSDeclaration = _Class("CEMApplicationStoreMacOSDeclaration")
CEMApplicationStoreDeclaration = _Class("CEMApplicationStoreDeclaration")
CEMApplicationSettingsManagedDeclaration = _Class(
    "CEMApplicationSettingsManagedDeclaration"
)
CEMApplicationSettingsDeclaration = _Class("CEMApplicationSettingsDeclaration")
CEMApplicationLoginItemsDeclaration = _Class("CEMApplicationLoginItemsDeclaration")
CEMApplicationLockDeclaration = _Class("CEMApplicationLockDeclaration")
CEMApplicationInstallDeclaration = _Class("CEMApplicationInstallDeclaration")
CEMApplicationExtensionsDeclaration = _Class("CEMApplicationExtensionsDeclaration")
CEMApplicationControlDeclaration = _Class("CEMApplicationControlDeclaration")
CEMApplicationAutonomousSingleAppModeDeclaration = _Class(
    "CEMApplicationAutonomousSingleAppModeDeclaration"
)
CEMAccountWebClipDeclaration = _Class("CEMAccountWebClipDeclaration")
CEMAccountSubscribedCalendarDeclaration = _Class(
    "CEMAccountSubscribedCalendarDeclaration"
)
CEMAccountSettingsDeclaration = _Class("CEMAccountSettingsDeclaration")
CEMAccountMailDeclaration = _Class("CEMAccountMailDeclaration")
CEMAccountmacOSServerDeclaration = _Class("CEMAccountmacOSServerDeclaration")
CEMAccountLDAPDeclaration = _Class("CEMAccountLDAPDeclaration")
CEMAccountGoogleDeclaration = _Class("CEMAccountGoogleDeclaration")
CEMAccountCardDAVDeclaration = _Class("CEMAccountCardDAVDeclaration")
CEMAccountCalDAVDeclaration = _Class("CEMAccountCalDAVDeclaration")
