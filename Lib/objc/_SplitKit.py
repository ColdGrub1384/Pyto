"""
Classes from the 'SplitKit' framework.
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


PodsDummy_SplitKit = _Class("PodsDummy_SplitKit")
InstantPanGestureRecognizer = _Class("SplitKit.InstantPanGestureRecognizer")
HandleView = _Class("SplitKit.HandleView")
SPKSplitViewController = _Class("SPKSplitViewController")
