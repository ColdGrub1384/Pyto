'''
Classes from the 'MediaSafetyNet' framework.
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

    
MSNScopedExceptionsServer = _Class('MSNScopedExceptionsServer')
MSNScopedException = _Class('MSNScopedException')
MSNTTR = _Class('MSNTTR')
MSNCarPlay = _Class('MSNCarPlay')
