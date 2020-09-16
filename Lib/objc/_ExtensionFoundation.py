'''
Classes from the 'ExtensionFoundation' framework.
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

    
_EXExtensionPoint = _Class('_EXExtensionPoint')
EXDefaults = _Class('EXDefaults')
EXCacheBuilder = _Class('EXCacheBuilder')
EXOSExtensionEnumerator = _Class('EXOSExtensionEnumerator')
EXExtensionPointEnumerator = _Class('EXExtensionPointEnumerator')
EXEnumerator = _Class('EXEnumerator')
