'''
Classes from the 'WebUI' framework.
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

    
WBUFormAutoFillWhiteList = _Class('WBUFormAutoFillWhiteList')
WBUGeneratedPasswordCredentialUpdater = _Class('WBUGeneratedPasswordCredentialUpdater')
WBUGeneratedPasswordCredentialUpdateRequest = _Class('WBUGeneratedPasswordCredentialUpdateRequest')
_WBUDynamicMeCard = _Class('_WBUDynamicMeCard')
WBUFormAutoFillPrompt = _Class('WBUFormAutoFillPrompt')
WBUAutoFillDisplayData = _Class('WBUAutoFillDisplayData')
WebUIAlert = _Class('WebUIAlert')
WebUICertificateError = _Class('WebUICertificateError')
WBUFeatureManager = _Class('WBUFeatureManager')
WBUSheetController = _Class('WBUSheetController')
WBUHistory = _Class('WBUHistory')
WBUFormDataController = _Class('WBUFormDataController')
WBUCreditCardDataController = _Class('WBUCreditCardDataController')
WBUAlertController = _Class('WBUAlertController')
