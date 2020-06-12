from pyto import __Class__
from datetime import datetime
import sys

__background_task__ = __Class__("BackgroundTask").new()

class BackgroundTask:

    start_date = None

    def execution_time(self):
        return int((datetime.now()-self.start_date).total_seconds())

    def __enter__(self):

        self.start_date = datetime.now()

        __background_task__.startBackgroundTask()
        return self

    def __exit__(self, type, value, traceback):
        __background_task__.stopBackgroundTask()

        if type is not None and value is not None and traceback is not None:
            sys.excepthook(type, value, traceback)