"""
Classes from the 'CloudServices' framework.
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


SESWrapper = _Class("SESWrapper")
CertOperations = _Class("CertOperations")
CloudServicesError = _Class("CloudServicesError")
SecureBackupBeginPasscodeRequestResults = _Class(
    "SecureBackupBeginPasscodeRequestResults"
)
SecureBackup = _Class("SecureBackup")
SRPInit = _Class("SRPInit")
CloudServicesAnalytics = _Class("CloudServicesAnalytics")
SecureBackupTermsInfo = _Class("SecureBackupTermsInfo")
