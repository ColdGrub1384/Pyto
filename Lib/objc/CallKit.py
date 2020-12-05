"""
Classes from the 'CallKit' framework.
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


CXCall = _Class("CXCall")
CXCallDirectoryStoreIdentificationEntry = _Class(
    "CXCallDirectoryStoreIdentificationEntry"
)
CXVoicemailControllerHost = _Class("CXVoicemailControllerHost")
CXNetworkExtensionMessageController = _Class("CXNetworkExtensionMessageController")
CXDatabaseStatement = _Class("CXDatabaseStatement")
CXProviderConfiguration = _Class("CXProviderConfiguration")
CXCallDirectoryPhoneNumberEntryData = _Class("CXCallDirectoryPhoneNumberEntryData")
CXCallDirectoryMutablePhoneNumberEntryData = _Class(
    "CXCallDirectoryMutablePhoneNumberEntryData"
)
CXCallDirectorySanitizer = _Class("CXCallDirectorySanitizer")
CXNetworkExtensionMessageControllerHostConnection = _Class(
    "CXNetworkExtensionMessageControllerHostConnection"
)
CXNetworkExtensionMessageControllerXPCClient = _Class(
    "CXNetworkExtensionMessageControllerXPCClient"
)
CXTransactionGroup = _Class("CXTransactionGroup")
CXCallDirectoryExtension = _Class("CXCallDirectoryExtension")
CXVoicemailControllerHostConnection = _Class("CXVoicemailControllerHostConnection")
CXNetworkExtensionMessageControllerHost = _Class(
    "CXNetworkExtensionMessageControllerHost"
)
CXVoicemail = _Class("CXVoicemail")
CXCallDirectoryManager = _Class("CXCallDirectoryManager")
CXCallControllerHostConnection = _Class("CXCallControllerHostConnection")
CXCallDirectoryExtensionManager = _Class("CXCallDirectoryExtensionManager")
CXCallController = _Class("CXCallController")
CXCallDirectoryIdentificationEntry = _Class("CXCallDirectoryIdentificationEntry")
CXSandboxExtendedURL = _Class("CXSandboxExtendedURL")
CXAccount = _Class("CXAccount")
CXLabeledHandle = _Class("CXLabeledHandle")
CXVoicemailSource = _Class("CXVoicemailSource")
CXXPCVoicemailSource = _Class("CXXPCVoicemailSource")
CXCallDirectoryStoreExtension = _Class("CXCallDirectoryStoreExtension")
CXCallUpdate = _Class("CXCallUpdate")
CXCallFailureContext = _Class("CXCallFailureContext")
CXDatabase = _Class("CXDatabase")
CXTransactionManager = _Class("CXTransactionManager")
CXVoicemailController = _Class("CXVoicemailController")
CXVoicemailObserver = _Class("CXVoicemailObserver")
CXProvider = _Class("CXProvider")
CXInProcessProvider = _Class("CXInProcessProvider")
CXXPCProvider = _Class("CXXPCProvider")
CXExtensionProvider = _Class("CXExtensionProvider")
CXHandoffContext = _Class("CXHandoffContext")
CXVoicemailObserverXPCClient = _Class("CXVoicemailObserverXPCClient")
CXCallDirectoryStoreMigrationResult = _Class("CXCallDirectoryStoreMigrationResult")
CXCallDirectoryStoreMigrator = _Class("CXCallDirectoryStoreMigrator")
CXCallDirectoryStore = _Class("CXCallDirectoryStore")
CXCallDirectoryLabeledPhoneNumberEntryData = _Class(
    "CXCallDirectoryLabeledPhoneNumberEntryData"
)
CXCallDirectoryMutableLabeledPhoneNumberEntryData = _Class(
    "CXCallDirectoryMutableLabeledPhoneNumberEntryData"
)
CXCallSourceManager = _Class("CXCallSourceManager")
CXTransaction = _Class("CXTransaction")
CXCallDirectoryProvider = _Class("CXCallDirectoryProvider")
CXAbstractProvider = _Class("CXAbstractProvider")
CXVoicemailProvider = _Class("CXVoicemailProvider")
CXVoicemailUpdate = _Class("CXVoicemailUpdate")
CXCallControllerHost = _Class("CXCallControllerHost")
CXSenderIdentity = _Class("CXSenderIdentity")
CXCallDirectoryHost = _Class("CXCallDirectoryHost")
CXCallSource = _Class("CXCallSource")
CXXPCCallSource = _Class("CXXPCCallSource")
CXExtensionCallSource = _Class("CXExtensionCallSource")
CXInProcessCallSource = _Class("CXInProcessCallSource")
CXAction = _Class("CXAction")
CXSendMMIOrUSSDCodeAction = _Class("CXSendMMIOrUSSDCodeAction")
CXCallAction = _Class("CXCallAction")
CXSetVideoPresentationStateCallAction = _Class("CXSetVideoPresentationStateCallAction")
CXSetVideoPresentationSizeCallAction = _Class("CXSetVideoPresentationSizeCallAction")
CXEndCallAction = _Class("CXEndCallAction")
CXSetSendingVideoCallAction = _Class("CXSetSendingVideoCallAction")
CXSetTTYTypeCallAction = _Class("CXSetTTYTypeCallAction")
CXSetMutedCallAction = _Class("CXSetMutedCallAction")
CXStartCallAction = _Class("CXStartCallAction")
CXSetRelayingCallAction = _Class("CXSetRelayingCallAction")
CXJoinCallAction = _Class("CXJoinCallAction")
CXPlayDTMFCallAction = _Class("CXPlayDTMFCallAction")
CXSetGroupCallAction = _Class("CXSetGroupCallAction")
CXSetHeldCallAction = _Class("CXSetHeldCallAction")
CXAnswerCallAction = _Class("CXAnswerCallAction")
CXPullCallAction = _Class("CXPullCallAction")
CXVoicemailAction = _Class("CXVoicemailAction")
CXSetPlayedVoicemailAction = _Class("CXSetPlayedVoicemailAction")
CXRemoveVoicemailAction = _Class("CXRemoveVoicemailAction")
CXSetTrashedVoicemailAction = _Class("CXSetTrashedVoicemailAction")
CXHandle = _Class("CXHandle")
CXCallDirectoryNSExtensionManager = _Class("CXCallDirectoryNSExtensionManager")
CXCallObserverXPCClient = _Class("CXCallObserverXPCClient")
CXCallObserver = _Class("CXCallObserver")
CXCallDirectoryExtensionContext = _Class("CXCallDirectoryExtensionContext")
CXCallDirectoryExtensionHostContext = _Class("CXCallDirectoryExtensionHostContext")
CXProviderExtensionContext = _Class("CXProviderExtensionContext")
CXProviderExtensionVendorContext = _Class("CXProviderExtensionVendorContext")
CXProviderExtensionHostContext = _Class("CXProviderExtensionHostContext")
