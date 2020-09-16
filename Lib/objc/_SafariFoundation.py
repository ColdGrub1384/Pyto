'''
Classes from the 'SafariFoundation' framework.
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

    
SFSharablePassword = _Class('SFSharablePassword')
_SFSharablePasswordEncryptionInformation = _Class('_SFSharablePasswordEncryptionInformation')
SFAppAutoFillOneTimeCodeProvider = _Class('SFAppAutoFillOneTimeCodeProvider')
SFSuggestedUser = _Class('SFSuggestedUser')
SFCredentialProviderExtensionManager = _Class('SFCredentialProviderExtensionManager')
SFSuggestedUserProvider = _Class('SFSuggestedUserProvider')
SFAutoFillOneTimeCode = _Class('SFAutoFillOneTimeCode')
SFAutoFillFeatureManager = _Class('SFAutoFillFeatureManager')
SFSharablePasswordReceiver = _Class('SFSharablePasswordReceiver')
SFExternalCredentialIdentityStoreManager = _Class('SFExternalCredentialIdentityStoreManager')
SFSharedWebCredentialsDatabaseEntry = _Class('SFSharedWebCredentialsDatabaseEntry')
SFCredentialProviderExtensionState = _Class('SFCredentialProviderExtensionState')
SFPasswordCredentialIdentity = _Class('SFPasswordCredentialIdentity')
SFStrongPasswordGenerator = _Class('SFStrongPasswordGenerator')
SFSafariCredentialStore = _Class('SFSafariCredentialStore')
SFDomainAssociationUtilities = _Class('SFDomainAssociationUtilities')
SFAutoFillHelperProxy = _Class('SFAutoFillHelperProxy')
SFSafariCredential = _Class('SFSafariCredential')
SFCredentialProviderExtensionHelperProxy = _Class('SFCredentialProviderExtensionHelperProxy')
SFExternalCredentialIdentityStore = _Class('SFExternalCredentialIdentityStore')
