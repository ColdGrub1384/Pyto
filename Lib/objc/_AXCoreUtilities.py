'''
Classes from the 'AXCoreUtilities' framework.
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

    
AXAccessQueue = _Class('AXAccessQueue')
AXXPCUtilities = _Class('AXXPCUtilities')
AXMetric = _Class('AXMetric')
AXBookendMetric = _Class('AXBookendMetric')
AXBlockMetric = _Class('AXBlockMetric')
AXMetricSession = _Class('AXMetricSession')
AXDispatchTimer = _Class('AXDispatchTimer')
AXAccessQueueTimer = _Class('AXAccessQueueTimer')
