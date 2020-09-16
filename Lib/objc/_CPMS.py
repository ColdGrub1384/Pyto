'''
Classes from the 'CPMS' framework.
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

    
CPMSStateReader = _Class('CPMSStateReader')
CPMSClientDescription = _Class('CPMSClientDescription')
CPMSAgent = _Class('CPMSAgent')
