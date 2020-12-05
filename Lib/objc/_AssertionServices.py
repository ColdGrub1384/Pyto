"""
Classes from the 'AssertionServices' framework.
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


BKSLaunchdJobSpecification = _Class("BKSLaunchdJobSpecification")
BKSApplicationStateMonitor = _Class("BKSApplicationStateMonitor")
BKSTerminationAssertionObserverManager = _Class(
    "BKSTerminationAssertionObserverManager"
)
BKSTerminationContext = _Class("BKSTerminationContext")
BKSProcess = _Class("BKSProcess")
BKSProcessExitContext = _Class("BKSProcessExitContext")
BKSWorkspace = _Class("BKSWorkspace")
BKSAssertion = _Class("BKSAssertion")
BKSTerminationAssertion = _Class("BKSTerminationAssertion")
BKSProcessAssertion = _Class("BKSProcessAssertion")
