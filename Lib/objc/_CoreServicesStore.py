"""
Classes from the 'CoreServicesStore' framework.
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


_CSVisualizerTableFunctions = _Class("_CSVisualizerTableFunctions")
_CSVisualizer = _Class("_CSVisualizer")
_CSStore2DataContainer = _Class("_CSStore2DataContainer")
_CSVisualizationArchiver = _Class("_CSVisualizationArchiver")
_CSStore = _Class("_CSStore")
_CSVisualizerPredicate = _Class("_CSVisualizerPredicate")
