"""
Classes from the 'AppStoreOverlays' framework.
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


ASOOverlayAppClipConfiguration = _Class("ASOOverlayAppClipConfiguration")
ASOOverlayManager = _Class("ASOOverlayManager")
ASORemoteOverlay = _Class("ASORemoteOverlay")
ASOOverlayAppConfiguration = _Class("ASOOverlayAppConfiguration")
ASOOverlayAnimator = _Class("ASOOverlayAnimator")
ASOOverlayTransitionContext = _Class("ASOOverlayTransitionContext")
ASOHostContext = _Class("ASOHostContext")
ASODismissRemoteOverlayOperation = _Class("ASODismissRemoteOverlayOperation")
ASOPresentRemoteOverlayOperation = _Class("ASOPresentRemoteOverlayOperation")
ASOOverlayWindow = _Class("ASOOverlayWindow")
ASOOverlayViewController = _Class("ASOOverlayViewController")
ASORemoteViewController = _Class("ASORemoteViewController")
