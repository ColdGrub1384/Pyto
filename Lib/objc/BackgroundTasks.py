'''
Classes from the 'BackgroundTasks' framework.
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

    
BGTaskRequest = _Class('BGTaskRequest')
BGProcessingTaskRequest = _Class('BGProcessingTaskRequest')
BGAppRefreshTaskRequest = _Class('BGAppRefreshTaskRequest')
BGTask = _Class('BGTask')
BGProcessingTask = _Class('BGProcessingTask')
BGAppRefreshTask = _Class('BGAppRefreshTask')
_BGTaskSchedulerRegistration = _Class('_BGTaskSchedulerRegistration')
BGTaskScheduler = _Class('BGTaskScheduler')
