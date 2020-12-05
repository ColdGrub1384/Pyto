"""
Classes from the 'StudyLog' framework.
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


SLGLogXPCClient = _Class("SLGLogXPCClient")
SLGActivatableLogger = _Class("SLGActivatableLogger")
SLGTimedLogger = _Class("SLGTimedLogger")
SLGNotificationActivatedLoggerRegistration = _Class(
    "SLGNotificationActivatedLoggerRegistration"
)
SLGNotificationActivatedLogger = _Class("SLGNotificationActivatedLogger")
SLGDomainWhitelist = _Class("SLGDomainWhitelist")
SLGLog = _Class("SLGLog")
