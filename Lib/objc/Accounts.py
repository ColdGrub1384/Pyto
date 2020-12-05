"""
Classes from the 'Accounts' framework.
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


ACAccountMigrationLock = _Class("ACAccountMigrationLock")
ACTrackedSet = _Class("ACTrackedSet")
ACMutableTrackedSet = _Class("ACMutableTrackedSet")
ACDispatchCerberus = _Class("ACDispatchCerberus")
ACCredentialItem = _Class("ACCredentialItem")
ACDataclassAction = _Class("ACDataclassAction")
ACRemoteAccountStoreInterface = _Class("ACRemoteAccountStoreInterface")
ACNotificationRebroadcaster = _Class("ACNotificationRebroadcaster")
ACSystemConfigManager = _Class("ACSystemConfigManager")
ACTimedExpirer = _Class("ACTimedExpirer")
ACRateLimiter = _Class("ACRateLimiter")
ACSimpleRateLimiter = _Class("ACSimpleRateLimiter")
ACAccountStoreClientSideListener = _Class("ACAccountStoreClientSideListener")
ACRemoteAccountStoreSession = _Class("ACRemoteAccountStoreSession")
ACAccountCredential = _Class("ACAccountCredential")
ACOAuthSigner = _Class("ACOAuthSigner")
ACPersonaManager = _Class("ACPersonaManager")
ACAccountType = _Class("ACAccountType")
ACAccount = _Class("ACAccount")
ACPluginLoader = _Class("ACPluginLoader")
ACManagedDefaults = _Class("ACManagedDefaults")
ACAccountStore = _Class("ACAccountStore")
ACMonitoredAccountStore = _Class("ACMonitoredAccountStore")
ACProtobufUUID = _Class("ACProtobufUUID")
ACProtobufAccountCredential = _Class("ACProtobufAccountCredential")
ACProtobufURL = _Class("ACProtobufURL")
ACProtobufDate = _Class("ACProtobufDate")
ACProtobufAccountType = _Class("ACProtobufAccountType")
ACProtobufVariableValueDictionary = _Class("ACProtobufVariableValueDictionary")
ACProtobufKeyValuePair = _Class("ACProtobufKeyValuePair")
ACProtobufCredentialItem = _Class("ACProtobufCredentialItem")
ACProtobufAccount = _Class("ACProtobufAccount")
ACProtobufVariableValueList = _Class("ACProtobufVariableValueList")
ACProtobufDataclassAction = _Class("ACProtobufDataclassAction")
ACProtobufVariableKeyValuePair = _Class("ACProtobufVariableKeyValuePair")
ACProtobufVariableValue = _Class("ACProtobufVariableValue")
ACDManagedAccountProperty = _Class("ACDManagedAccountProperty")
ACDManagedCredentialItem = _Class("ACDManagedCredentialItem")
ACDManagedDataclass = _Class("ACDManagedDataclass")
ACDManagedAccessOptionsKey = _Class("ACDManagedAccessOptionsKey")
ACDManagedAuthorization = _Class("ACDManagedAuthorization")
ACDManagedAccountType = _Class("ACDManagedAccountType")
ACDManagedAccount = _Class("ACDManagedAccount")
ACZeroingString = _Class("ACZeroingString")
