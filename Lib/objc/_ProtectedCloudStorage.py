'''
Classes from the 'ProtectedCloudStorage' framework.
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

    
PCSUtilities = _Class('PCSUtilities')
UserRegistryDB = _Class('UserRegistryDB')
PCSCKKS = _Class('PCSCKKS')
PCSCKKSItemModifyContext = _Class('PCSCKKSItemModifyContext')
PCSMTT = _Class('PCSMTT')
PCSMTTPoint = _Class('PCSMTTPoint')
NoServerHandler = _Class('NoServerHandler')
PCSKeybagKey = _Class('PCSKeybagKey')
PCSMobileBackup = _Class('PCSMobileBackup')
PCSLockManager = _Class('PCSLockManager')
PCSLockAssertion = _Class('PCSLockAssertion')
PCSShareProtectionObject = _Class('PCSShareProtectionObject')
UserRegistryStats = _Class('UserRegistryStats')
PCSAccountManager = _Class('PCSAccountManager')
PCSManatee = _Class('PCSManatee')
PCSAnalytics = _Class('PCSAnalytics')
PCSManateePrivateKey = _Class('PCSManateePrivateKey')
PCSManateeShareInvitation = _Class('PCSManateeShareInvitation')
PCSManateeShareableIdentity = _Class('PCSManateeShareableIdentity')
PCSCKKSOperation = _Class('PCSCKKSOperation')
PCSCKKSFetchCurrentOperation = _Class('PCSCKKSFetchCurrentOperation')
PCSCKKSOperationBlock = _Class('PCSCKKSOperationBlock')
PCSCKKSSyncViewOperation = _Class('PCSCKKSSyncViewOperation')
PCSCKKSEnsurePCSFieldsOperation = _Class('PCSCKKSEnsurePCSFieldsOperation')
PCSCKKSCreateIdentityOperation = _Class('PCSCKKSCreateIdentityOperation')
