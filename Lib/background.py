"""
Run code in background indefinitely

This module allows you to keep running a script in the background indefinitely.
A great usage of this is fetching data in background and sending notifications with :py:mod:`notifications`. You can also run a server or a Discord bot for example.

Note: Because of privacy, apps cannot access to the clipboard in background, so coding a clipboard manager is not possible.
"""

from pyto import __Class__
from __check_type__ import check
from datetime import datetime
from time import sleep
from os.path import abspath
import sys
import threading


class BackgroundTask:
    """
    Represents a task to run in background.
    When started, the audio at the path passed to the initializer is played. If no audio is passed, a blank audio is used so Pyto isn't killed by the system.

    Usage:

    .. highlight:: python
    .. code-block:: python

        import background as bg

        with bg.BackgroundTask() as b:
            while True:
                print(b.execution_time())
                b.wait(1)
    """

    start_date = None

    __end_date__ = None

    def execution_time(self) -> int:
        """
        Returns the total execution time of the task in seconds.

        :rtype: int
        """

        if self.__end_date__ is not None:
            date = self.__end_date__
        else:
            date = datetime.now()

        return int((date - self.start_date).total_seconds())

    @property
    def notification_delay(self) -> int:
        """
        The delay in seconds since each reminder notification.
        If set to 3600, a notification will be sent every hour while the task is running.
        The default value is ``21600`` (6 hours).

        :rtype: int
        """

        return self.__background_task__.delay

    @notification_delay.setter
    def notification_delay(self, new_value: int):
        self.__background_task__.delay = new_value

    @property
    def reminder_notifications(self) -> bool:
        """
        A boolean indicating whether a notification should be sent while the task is running.
        By default, a notification is sent every 6 hours while the task is running, set this property to ``False`` to disable that,

        :rtype: bool
        """

        return self.__background_task__.sendNotification

    @reminder_notifications.setter
    def reminder_notifications(self, new_value: bool):
        self.__background_task__.sendNotification = new_value

    def __init__(self, audio_path: str = None):

        check(audio_path, "audio_path", [str, None])

        self.__background_task__ = __Class__("BackgroundTask").new()
        if audio_path is not None:
            self.__background_task__.soundPath = abspath(audio_path)

    def start(self):
        """
        Starts the background task. After calling this function, Pyto will not be killed by the system.
        """

        self.start_date = datetime.now()
        self.__end_date__ = None

        try:
            self.__background_task__.scriptName = threading.current_thread().script_path.split("/")[-1]
        except AttributeError:
            pass
        except IndexError:
            pass

        self.__background_task__.startBackgroundTask()

    def stop(self):
        """
        Stops the background task. After calling this function, Pyto can be killed by the system to free memory.
        """

        self.__end_date__ = datetime.now()
        self.__background_task__.stopBackgroundTask()

    def wait(self, delay: float):
        """
        Waits n seconds. Does the same thing as ``time.sleep``.

        :param delay: Seconds to wait.
        """

        check(delay, "delay", [float, int])

        sleep(delay)

    def __enter__(self):
        self.start()

        return self

    def __exit__(self, type, value, traceback):
        self.stop()

        if type is not None and value is not None and traceback is not None:
            sys.excepthook(type, value, traceback)
