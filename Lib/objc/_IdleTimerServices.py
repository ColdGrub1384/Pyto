'''
Classes from the 'IdleTimerServices' framework.
'''

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

    
ITIdleTimerServiceProvider = _Class('ITIdleTimerServiceProvider')
ITIdleTimerStateModel = _Class('ITIdleTimerStateModel')
ITIdleTimerConfiguration = _Class('ITIdleTimerConfiguration')
ITIdleTimerState = _Class('ITIdleTimerState')
ITIdleTimerStateClient = _Class('ITIdleTimerStateClient')
ITIdleTimerStateService = _Class('ITIdleTimerStateService')
ITIdleTimerStateServer = _Class('ITIdleTimerStateServer')
ITIdleTimerAssertion = _Class('ITIdleTimerAssertion')
