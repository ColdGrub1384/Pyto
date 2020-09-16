'''
Classes from the 'CoreRecents' framework.
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

    
CRSQLRow = _Class('CRSQLRow')
CRRecentContactsLibrary = _Class('CRRecentContactsLibrary')
CRRecentContact = _Class('CRRecentContact')
CRSearchQuery = _Class('CRSearchQuery')
CRDRecentContactsLibraryInterface = _Class('CRDRecentContactsLibraryInterface')
