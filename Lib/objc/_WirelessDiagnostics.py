"""
Classes from the 'WirelessDiagnostics' framework.
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


AWDMetricManager = _Class("AWDMetricManager")
AWDServerConnection = _Class("AWDServerConnection")
AWDMetricContainer = _Class("AWDMetricContainer")
AWDObserver = _Class("AWDObserver")
