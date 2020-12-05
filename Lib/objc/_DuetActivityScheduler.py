"""
Classes from the 'DuetActivityScheduler' framework.
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


_DASFileProtection = _Class("_DASFileProtection")
_DASStrings = _Class("_DASStrings")
_DASPriorityQueue = _Class("_DASPriorityQueue")
_DASSystemContext = _Class("_DASSystemContext")
_DASExtension = _Class("_DASExtension")
_DASWidgetRefreshScheduler = _Class("_DASWidgetRefreshScheduler")
_DASWidgetBudgetParameters = _Class("_DASWidgetBudgetParameters")
_DASWidgetBudget = _Class("_DASWidgetBudget")
_DASWidgetInfo = _Class("_DASWidgetInfo")
_DASWidgetRefresh = _Class("_DASWidgetRefresh")
_DASWidgetView = _Class("_DASWidgetView")
_DASPairedSystemContext = _Class("_DASPairedSystemContext")
_DASExtensionRemoteContext = _Class("_DASExtensionRemoteContext")
_DASActivityGroup = _Class("_DASActivityGroup")
_DASActivity = _Class("_DASActivity")
_DASSubmissionRateLimiter = _Class("_DASSubmissionRateLimiter")
_DASScheduler = _Class("_DASScheduler")
