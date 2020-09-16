'''
Classes from the 'GraphVisualizer' framework.
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

    
GVInternalRenderer = _Class('GVInternalRenderer')
GVLayout = _Class('GVLayout')
GVRank = _Class('GVRank')
GVVerticalRank = _Class('GVVerticalRank')
GVHorizontalRank = _Class('GVHorizontalRank')
GVGraph = _Class('GVGraph')
GVEdge = _Class('GVEdge')
GVNode = _Class('GVNode')
GVDummyNode = _Class('GVDummyNode')
