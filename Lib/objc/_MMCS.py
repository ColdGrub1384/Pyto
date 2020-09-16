'''
Classes from the 'MMCS' framework.
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

    
MMCSOperationMetric = _Class('MMCSOperationMetric')
MMCSHTTPContext = _Class('MMCSHTTPContext')
MMCSBoundedQueue = _Class('MMCSBoundedQueue')
MMCSOperationStateTimeRange = _Class('MMCSOperationStateTimeRange')
C2WarmRequest = _Class('C2WarmRequest')
