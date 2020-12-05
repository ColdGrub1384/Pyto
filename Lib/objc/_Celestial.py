"""
Classes from the 'Celestial' framework.
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


AVSystemController = _Class("AVSystemController")
FigCheckpointSupport = _Class("FigCheckpointSupport")
AVFileProcessor = _Class("AVFileProcessor")
AVObjectRegistry = _Class("AVObjectRegistry")
AVValue = _Class("AVValue")
AVSafePerformOnMainThreadTargetDict = _Class("AVSafePerformOnMainThreadTargetDict")
AVSafePostDelayedNotificationFromMainThreadTargetDict = _Class(
    "AVSafePostDelayedNotificationFromMainThreadTargetDict"
)
AVFromNotifySafeThreadPostNotificationNameDict = _Class(
    "AVFromNotifySafeThreadPostNotificationNameDict"
)
AVFromMainThreadPostNotificationNameDict = _Class(
    "AVFromMainThreadPostNotificationNameDict"
)
