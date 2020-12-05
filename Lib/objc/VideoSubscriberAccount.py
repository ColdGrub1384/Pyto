"""
Classes from the 'VideoSubscriberAccount' framework.
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


VSAccountMetadata = _Class("VSAccountMetadata")
VSKeychainStore = _Class("VSKeychainStore")
VSKeychainEditingContext = _Class("VSKeychainEditingContext")
VSAppInstallationInfoCenter = _Class("VSAppInstallationInfoCenter")
VSPrivacyVoucherLockbox = _Class("VSPrivacyVoucherLockbox")
VSPrivacyInfoCenter = _Class("VSPrivacyInfoCenter")
VSIdentityProviderAppsResponse = _Class("VSIdentityProviderAppsResponse")
VSDevice = _Class("VSDevice")
VSSetTopBoxProfile = _Class("VSSetTopBoxProfile")
VSPrivacyConsentVoucher = _Class("VSPrivacyConsentVoucher")
VSClassForFindingBundle = _Class("VSClassForFindingBundle")
VSKeychainFetchRequest = _Class("VSKeychainFetchRequest")
VSAuditToken = _Class("VSAuditToken")
VSIdentityProviderAvailabilityInfoCenter = _Class(
    "VSIdentityProviderAvailabilityInfoCenter"
)
VSSemaphore = _Class("VSSemaphore")
VSOnceAndOnlyOnceHandler = _Class("VSOnceAndOnlyOnceHandler")
VSSubscriptionPersistentContainer = _Class("VSSubscriptionPersistentContainer")
VSKeychainItemKind = _Class("VSKeychainItemKind")
VSErrorRecoveryOption = _Class("VSErrorRecoveryOption")
VSErrorRecoveryAttempter = _Class("VSErrorRecoveryAttempter")
VSErrorRecoveryAttempterDelegate = _Class("VSErrorRecoveryAttempterDelegate")
VSAccount = _Class("VSAccount")
VSViewServiceResponse = _Class("VSViewServiceResponse")
VSAccountMetadataRequest = _Class("VSAccountMetadataRequest")
VSPersistentStorage = _Class("VSPersistentStorage")
VSSecurityTask = _Class("VSSecurityTask")
VSViewServiceRequestCenter = _Class("VSViewServiceRequestCenter")
VSStoreRequest = _Class("VSStoreRequest")
VSAccountManagerResult = _Class("VSAccountManagerResult")
VSSubscriptionRegistrationCenter = _Class("VSSubscriptionRegistrationCenter")
VSAccountChannelsCenter = _Class("VSAccountChannelsCenter")
VSServiceConnectionHandler = _Class("VSServiceConnectionHandler")
VSSubscriptionRegistry = _Class("VSSubscriptionRegistry")
VSExpressionEvaluator = _Class("VSExpressionEvaluator")
VSDeveloperModeStore = _Class("VSDeveloperModeStore")
VSBindingInfo = _Class("VSBindingInfo")
VSAccountsArchive = _Class("VSAccountsArchive")
VSIdentityProviderInfoCenter = _Class("VSIdentityProviderInfoCenter")
VSIdentityProviderInfoQueryResult = _Class("VSIdentityProviderInfoQueryResult")
VSBinder = _Class("VSBinder")
VSSubscriptionSource = _Class("VSSubscriptionSource")
VSPreferences = _Class("VSPreferences")
VSAccountProviderResponse = _Class("VSAccountProviderResponse")
VSBackgroundTask = _Class("VSBackgroundTask")
VSPrivacyFacade = _Class("VSPrivacyFacade")
VSOptional = _Class("VSOptional")
VSAppChannelsMapping = _Class("VSAppChannelsMapping")
VSSubscriptionFetchOptionsValidator = _Class("VSSubscriptionFetchOptionsValidator")
VSSubscriptionFetchOptionDescription = _Class("VSSubscriptionFetchOptionDescription")
VSHash = _Class("VSHash")
VSWeakForwardingTarget = _Class("VSWeakForwardingTarget")
VSKeychainItemAttribute = _Class("VSKeychainItemAttribute")
VSKeychainItem = _Class("VSKeychainItem")
VSKeychainGenericPassword = _Class("VSKeychainGenericPassword")
VSViewServiceXPCInterface = _Class("VSViewServiceXPCInterface")
VSDeveloperSettings = _Class("VSDeveloperSettings")
VSFailable = _Class("VSFailable")
VSDeveloperServiceConnection = _Class("VSDeveloperServiceConnection")
VSOpaqueAuthenticationToken = _Class("VSOpaqueAuthenticationToken")
VSSAMLAuthenticationToken = _Class("VSSAMLAuthenticationToken")
VSIdentityProvider = _Class("VSIdentityProvider")
VSAccountChannels = _Class("VSAccountChannels")
VSObservance = _Class("VSObservance")
VSMetricsCenter = _Class("VSMetricsCenter")
VSServiceListener = _Class("VSServiceListener")
VSSubscriptionService = _Class("VSSubscriptionService")
VSPrivacyService = _Class("VSPrivacyService")
VSDeveloperService = _Class("VSDeveloperService")
VSSubscription = _Class("VSSubscription")
VSUnbinder = _Class("VSUnbinder")
VSLinkedOnOrAfterChecker = _Class("VSLinkedOnOrAfterChecker")
VSViewServiceRequest = _Class("VSViewServiceRequest")
VSSubscriptionServiceConnection = _Class("VSSubscriptionServiceConnection")
VSStoreURLBag = _Class("VSStoreURLBag")
VSTreeNode = _Class("VSTreeNode")
VSKeyPathBasedTreeNode = _Class("VSKeyPathBasedTreeNode")
VSAccountManager = _Class("VSAccountManager")
VSRestrictionsCenter = _Class("VSRestrictionsCenter")
VSPersistentContainer = _Class("VSPersistentContainer")
VSStateMachine = _Class("VSStateMachine")
VSStateTransition = _Class("VSStateTransition")
VSAccountSerializationCenter = _Class("VSAccountSerializationCenter")
VSValueType = _Class("VSValueType")
VSValueTypeProperty = _Class("VSValueTypeProperty")
VSAccountStore = _Class("VSAccountStore")
VSRemoteNotifier = _Class("VSRemoteNotifier")
VSAppChannelsFilter = _Class("VSAppChannelsFilter")
VSSubscriptionPredicateFactory = _Class("VSSubscriptionPredicateFactory")
VSSubscriptionPropertyListStore = _Class("VSSubscriptionPropertyListStore")
VSSubscriptionSourceKindPropertyListValueTransformer = _Class(
    "VSSubscriptionSourceKindPropertyListValueTransformer"
)
VSStoreAllAppsResponseDictionaryValueTransformer = _Class(
    "VSStoreAllAppsResponseDictionaryValueTransformer"
)
VSReverseValueTransformer = _Class("VSReverseValueTransformer")
VSJSONDataValueTransformer = _Class("VSJSONDataValueTransformer")
VSBlockBasedValueTransformer = _Class("VSBlockBasedValueTransformer")
VSAuthenticationSchemeValueTransformer = _Class(
    "VSAuthenticationSchemeValueTransformer"
)
VSSubscriptionAccountHashValueTransformer = _Class(
    "VSSubscriptionAccountHashValueTransformer"
)
VSCompoundValueTransformer = _Class("VSCompoundValueTransformer")
VSStoreAllAppsResponseValueTransformer = _Class(
    "VSStoreAllAppsResponseValueTransformer"
)
VSStoreAppsResponseValueTransformer = _Class("VSStoreAppsResponseValueTransformer")
VSStoreAppsResponseDictionaryValueTransformer = _Class(
    "VSStoreAppsResponseDictionaryValueTransformer"
)
VSFailableValueTransformer = _Class("VSFailableValueTransformer")
VSSubscriptionAvailabilityTypeJSONValueTransformer = _Class(
    "VSSubscriptionAvailabilityTypeJSONValueTransformer"
)
VSDataCompressionValueTransformer = _Class("VSDataCompressionValueTransformer")
VSBase64DataValueTransformer = _Class("VSBase64DataValueTransformer")
VSURLStringValueTransformer = _Class("VSURLStringValueTransformer")
VSDeveloperIdentityProvider = _Class("VSDeveloperIdentityProvider")
VSPersistentSubscription = _Class("VSPersistentSubscription")
VSUserNotificationOperation = _Class("VSUserNotificationOperation")
VSAsyncOperation = _Class("VSAsyncOperation")
VSAccountSaveOperation = _Class("VSAccountSaveOperation")
VSApplicationBootURLOperation = _Class("VSApplicationBootURLOperation")
VSFileRemoveOperation = _Class("VSFileRemoveOperation")
VSDeveloperSettingsUpdateOperation = _Class("VSDeveloperSettingsUpdateOperation")
VSDelayOperation = _Class("VSDelayOperation")
VSFileWriteOperation = _Class("VSFileWriteOperation")
VSIdentityProviderFetchAppsOperation = _Class("VSIdentityProviderFetchAppsOperation")
VSTestSetupPreparationOperation = _Class("VSTestSetupPreparationOperation")
VSVerificationDataOperation = _Class("VSVerificationDataOperation")
VSDeveloperIdentityProviderFetchAllOperation = _Class(
    "VSDeveloperIdentityProviderFetchAllOperation"
)
VSCredentialSaveOperation = _Class("VSCredentialSaveOperation")
VSViewServiceRequestOperation = _Class("VSViewServiceRequestOperation")
VSDeveloperSettingsFetchOperation = _Class("VSDeveloperSettingsFetchOperation")
VSStoreRequestOperation = _Class("VSStoreRequestOperation")
VSVerificationStateResetOperation = _Class("VSVerificationStateResetOperation")
VSAppInstallationOperation = _Class("VSAppInstallationOperation")
VSStoreURLBagLoadOperation = _Class("VSStoreURLBagLoadOperation")
VSFileReadOperation = _Class("VSFileReadOperation")
VSTimeoutOperation = _Class("VSTimeoutOperation")
VSAccountChannelsSaveOperation = _Class("VSAccountChannelsSaveOperation")
VSDeveloperIdentityProviderChangeOperation = _Class(
    "VSDeveloperIdentityProviderChangeOperation"
)
VSIdentityProviderFetchAllAppsOperation = _Class(
    "VSIdentityProviderFetchAllAppsOperation"
)
VSCasePreservingString = _Class("VSCasePreservingString")
