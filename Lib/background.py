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
import stopit
import random
import string


__tasks__ = {}


class TaskExit(Exception):
    """
    An exception thrown when a task is stopped.
    """

    pass


def _stop(id):
    try:
        thread = __tasks__[id].__thread__
    except KeyError:
        return

    for tid, tobj in threading._active.items():
        try:
            if tobj == thread:
                stopit.async_raise(tid, TaskExit)
                break
        except:
            continue


def request_background_fetch():
    """
    This function is used to start fetching information in background.
    It tells the system to execute the script from which the function is called multiple times a day. The OS decides when it's appropiate to perform the fetch, so it's pretty unreliable.
    The script cannot take more than 30 seconds to execute.

    For example, you can write a script for sending notifications or updating a widget.

    .. highlight:: python
    .. code-block:: python

        import background as bg
        import notifications as nc
        import widgets as wd
        import time

        bg.request_background_fetch()

        current_time = time.strftime("It is %H:%M")

        # Send notification

        notif = nc.Notification()
        notif.message = current_time
        nc.send_notification(notif)

        # Update widget

        time_label = wd.Text(current_time)

        widget = wd.Widget()
        for layout in (
            widget.small_layout,
            widget.medium_layout,
            widget.large_layout):
                
                layout.add_row([time_label])

        wd.save_widget(widget, "Fetching Test")

    """

    BackgroundTask = __Class__("BackgroundTask")
    BackgroundTask.scheduleFetch()

    script_path = None
    try:
        script_path = threading.current_thread().script_path
    except AttributeError:
        pass

    if script_path is not None:
        BackgroundTask.backgroundScript = script_path


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

    __thread__ = None

    id: str = None
    """
    A string that identifies the task. If a task with the same ID of a task that is already running is started, the other task will be stopped.
    That is useful with Shortcuts Personal Automations where you can create a background task multiple times to make sure it's running without having to worry about the task already running.
    """

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

    def __init__(self, audio_path: str = None, id: str = None):

        check(audio_path, "audio_path", [str, None])
        check(id, "id", [str, None])

        if id is None:
            self.id = "".join(
                random.choice(string.ascii_uppercase + string.digits) for _ in range(5)
            )
        else:
            self.id = id

        self.__background_task__ = __Class__("BackgroundTask").new()
        if audio_path is not None:
            self.__background_task__.soundPath = abspath(audio_path)

    def start(self):
        """
        Starts the background task. After calling this function, Pyto will not be killed by the system.
        """

        self.start_date = datetime.now()
        self.__end_date__ = None
        self.__thread__ = threading.current_thread()

        if self.id in __tasks__:
            __tasks__[self.id].stop()

        if self.id is not None:
            __tasks__[self.id] = self

        try:
            self.__background_task__.scriptName = threading.current_thread().script_path.split(
                "/"
            )[
                -1
            ]
        except AttributeError:
            pass
        except IndexError:
            pass

        self.__background_task__.startBackgroundTask()

    def stop(self):
        """
        Stops the background task. After calling this function, Pyto can be killed by the system to free memory (if no other task is running).
        """

        if self.id is not None:
            _stop(self.id)
            try:
                del __tasks__[self.id]
            except KeyError:
                pass

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

        if type is TaskExit:
            return

        if type is not None and value is not None and traceback is not None:
            sys.excepthook(type, value, traceback)
