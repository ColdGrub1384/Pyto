"""
Classes from the 'CrashReporterSupport' framework.
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


OTATaskingAgentClient = _Class("OTATaskingAgentClient")
StructuredDataReport = _Class("StructuredDataReport")
CrashReport = _Class("CrashReport")
