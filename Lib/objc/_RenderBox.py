"""
Classes from the 'RenderBox' framework.
"""

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


RBMetalRenderState = _Class("RBMetalRenderState")
RBSurface = _Class("RBSurface")
RBXMLParser = _Class("RBXMLParser")
RBFill = _Class("RBFill")
RBXMLRecorder_Fill = _Class("RBXMLRecorder_Fill")
RBDrawable = _Class("RBDrawable")
RBDisplayList = _Class("RBDisplayList")
RBXMLRecorder_DisplayList = _Class("RBXMLRecorder_DisplayList")
RBStrokeAccumulator = _Class("RBStrokeAccumulator")
RBDevice = _Class("RBDevice")
RBShape = _Class("RBShape")
RBXMLRecorder_Shape = _Class("RBXMLRecorder_Shape")
RBLayer = _Class("RBLayer")
