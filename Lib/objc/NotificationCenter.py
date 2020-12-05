"""
Classes from the 'NotificationCenter' framework.
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


NCWidgetMetrics = _Class("NCWidgetMetrics")
_NCWidgetControllerRequestLimiter = _Class("_NCWidgetControllerRequestLimiter")
NCWidgetController = _Class("NCWidgetController")
_NCWidgetExtensionContext = _Class("_NCWidgetExtensionContext")
_NCContentUnavailableViewWithButton = _Class("_NCContentUnavailableViewWithButton")
NCSizeObservingView = _Class("NCSizeObservingView")
_NCWidgetViewControllerView = _Class("_NCWidgetViewControllerView")
_NCContentUnavailableView = _Class("_NCContentUnavailableView")
_NCWidgetViewController = _Class("_NCWidgetViewController")
