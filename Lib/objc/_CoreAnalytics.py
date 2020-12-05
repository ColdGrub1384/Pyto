"""
Classes from the 'CoreAnalytics' framework.
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


AnalyticsConfigurationObserver = _Class("AnalyticsConfigurationObserver")
AnalyticsEventObserver = _Class("AnalyticsEventObserver")
