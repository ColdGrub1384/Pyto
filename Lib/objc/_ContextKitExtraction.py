'''
Classes from the 'ContextKitExtraction' framework.
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

    
CKContextDonation = _Class('CKContextDonation')
CKContextExecutor = _Class('CKContextExecutor')
CKContextDonationItem = _Class('CKContextDonationItem')
CKContextContentProviderManager = _Class('CKContextContentProviderManager')
CKContextContentProvider = _Class('CKContextContentProvider')
CKContextContentProviderUIScene = _Class('CKContextContentProviderUIScene')
