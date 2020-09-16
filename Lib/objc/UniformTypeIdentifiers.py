'''
Classes from the 'UniformTypeIdentifiers' framework.
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

    
UTType = _Class('UTType')
_UTTaggedType = _Class('_UTTaggedType')
_UTConstantType = _Class('_UTConstantType')
_UTRuntimeConstantType = _Class('_UTRuntimeConstantType')
_UTCoreType = _Class('_UTCoreType')
