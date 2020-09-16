'''
Classes from the 'MobileInstallation' framework.
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

    
MIBundleMetadata = _Class('MIBundleMetadata')
MIFileManager = _Class('MIFileManager')
AITransactionLog = _Class('AITransactionLog')
MIInstallerClient = _Class('MIInstallerClient')
MIInstallOptions = _Class('MIInstallOptions')
MIHelperServiceFrameworkClient = _Class('MIHelperServiceFrameworkClient')
MIStoreMetadata = _Class('MIStoreMetadata')
MIStoreMetadataSubGenre = _Class('MIStoreMetadataSubGenre')
MIGlobalConfiguration = _Class('MIGlobalConfiguration')
