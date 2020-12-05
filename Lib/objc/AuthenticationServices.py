"""
Classes from the 'AuthenticationServices' framework.
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


ASPasswordCredentialIdentity = _Class("ASPasswordCredentialIdentity")
ASAuthorizationPasswordProvider = _Class("ASAuthorizationPasswordProvider")
ASAccountAuthenticationModificationController = _Class(
    "ASAccountAuthenticationModificationController"
)
ASAuthorizationProviderExtensionAuthorizationRequest = _Class(
    "ASAuthorizationProviderExtensionAuthorizationRequest"
)
ASBackgroundObserver = _Class("ASBackgroundObserver")
ASEmpty = _Class("ASEmpty")
ASCredentialServiceIdentifier = _Class("ASCredentialServiceIdentifier")
ASAuthorizationController = _Class("ASAuthorizationController")
ASAccountAuthenticationModificationRequest = _Class(
    "ASAccountAuthenticationModificationRequest"
)
ASAccountAuthenticationModificationReplacePasswordWithSignInWithAppleRequest = _Class(
    "ASAccountAuthenticationModificationReplacePasswordWithSignInWithAppleRequest"
)
ASAccountAuthenticationModificationUpgradePasswordToStrongPasswordRequest = _Class(
    "ASAccountAuthenticationModificationUpgradePasswordToStrongPasswordRequest"
)
ASPasswordCredential = _Class("ASPasswordCredential")
ASWebAuthenticationSession = _Class("ASWebAuthenticationSession")
ASAuthorizationSingleSignOnProvider = _Class("ASAuthorizationSingleSignOnProvider")
_ASAccountAuthenticationModificationExtensionManager = _Class(
    "_ASAccountAuthenticationModificationExtensionManager"
)
ASAuthorizationRequest = _Class("ASAuthorizationRequest")
ASAuthorizationPasswordRequest = _Class("ASAuthorizationPasswordRequest")
ASAuthorizationOpenIDRequest = _Class("ASAuthorizationOpenIDRequest")
ASAuthorizationSingleSignOnRequest = _Class("ASAuthorizationSingleSignOnRequest")
ASAuthorizationAppleIDRequest = _Class("ASAuthorizationAppleIDRequest")
ASAuthorizationAppleIDCredential = _Class("ASAuthorizationAppleIDCredential")
ASAuthorization = _Class("ASAuthorization")
ASAuthorizationSingleSignOnCredential = _Class("ASAuthorizationSingleSignOnCredential")
ASCredentialIdentityStore = _Class("ASCredentialIdentityStore")
_ASIncomingCallObserver = _Class("_ASIncomingCallObserver")
ASCredentialIdentityStoreState = _Class("ASCredentialIdentityStoreState")
ASAuthorizationAppleIDProvider = _Class("ASAuthorizationAppleIDProvider")
ASCredentialProviderExtensionContext = _Class("ASCredentialProviderExtensionContext")
_ASAccountAuthenticationModificationExtensionHostContext = _Class(
    "_ASAccountAuthenticationModificationExtensionHostContext"
)
_ASCredentialProviderExtensionHostContext = _Class(
    "_ASCredentialProviderExtensionHostContext"
)
ASAccountAuthenticationModificationExtensionContext = _Class(
    "ASAccountAuthenticationModificationExtensionContext"
)
ASAuthorizationAppleIDButton = _Class("ASAuthorizationAppleIDButton")
ASAccountAuthenticationModificationViewController = _Class(
    "ASAccountAuthenticationModificationViewController"
)
_ASExtensionViewController = _Class("_ASExtensionViewController")
_ASCredentialListViewController = _Class("_ASCredentialListViewController")
_ASPasswordCredentialAuthenticationViewController = _Class(
    "_ASPasswordCredentialAuthenticationViewController"
)
_ASCredentialProviderExtensionConfigurationViewController = _Class(
    "_ASCredentialProviderExtensionConfigurationViewController"
)
_ASAccountAuthenticationModificationHostViewController = _Class(
    "_ASAccountAuthenticationModificationHostViewController"
)
ASCredentialProviderViewController = _Class("ASCredentialProviderViewController")
ASAccountAuthenticationModificationServiceViewController = _Class(
    "ASAccountAuthenticationModificationServiceViewController"
)
_ASAccountAuthenticationModificationRemoteViewController = _Class(
    "_ASAccountAuthenticationModificationRemoteViewController"
)
