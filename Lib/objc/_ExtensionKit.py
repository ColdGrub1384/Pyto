'''
Classes from the 'ExtensionKit' framework.
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

    
EXRunningExtensionInfo = _Class('EXRunningExtensionInfo')
EXSwiftUI_Subsystem = _Class('EXSwiftUI_Subsystem')
EXConcreteExtensionContextVendor = _Class('EXConcreteExtensionContextVendor')
_EXItemProviderSandboxedResource = _Class('_EXItemProviderSandboxedResource')
_EXItemProviderCopyingLoadOperator = _Class('_EXItemProviderCopyingLoadOperator')
_EXItemProviderExtensionVendorLoadOperator = _Class('_EXItemProviderExtensionVendorLoadOperator')
EXExtensionContextImplementation = _Class('EXExtensionContextImplementation')
EXConcreteExtension = _Class('EXConcreteExtension')
