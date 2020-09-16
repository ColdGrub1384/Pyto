'''
Classes from the 'DTDDISupport' framework.
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

    
UIKitDebugHierarchyMetaDataProvider = _Class('UIKitDebugHierarchyMetaDataProvider')
DBGViewDebuggerSupport = _Class('DBGViewDebuggerSupport')
DBGViewDebuggerSupport_iOS = _Class('DBGViewDebuggerSupport_iOS')
