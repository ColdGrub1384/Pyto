"""
Home Screen Widgets

This module is used to present custom UIs on home screen widgets.
"""

import pyto_ui as ui
import os
import datetime
from pyto import __Class__
from UIKit import UIDevice
from typing import Union


__PyWidget__ = __Class__("PyWidget")
__widget_id__ = None
__widget__ = __PyWidget__.alloc().init()
__shown_view__ = False


if UIDevice is not None and float(str(UIDevice.currentDevice.systemVersion).split(".")[0]) < 14:
    raise ImportError("Home Screen Widgets were introduced on iPadOS / iOS 14.")

if __PyWidget__ is None:
    raise NotImplementedError("Home Screen Widgets are coming on Pyto 13.")


def schedule_next_reload(time: Union[datetime.timedelta, float]):
    """
    Schedules the next reload of the widget. The passed time must be greater than 5 minutes.

    :param time: The time passed before the widget should reload. A ``datetime.timedelta`` object or the number of seconds.
    """

    seconds = 0

    if isinstance(time, datetime.timedelta):
        seconds = time.total_seconds()
    else:
        seconds = time

    if seconds < 300:
        raise ValueError("A widget cannot be reloaded before 5 minutes.")

    __widget__.updateInterval = seconds

def __show_view__(view: ui.View, key: str = None):

    widget = __widget__

    widget.view = view.__py_view__
        
    small = __PyWidget__.sizeForFamily(0)
    medium = __PyWidget__.sizeForFamily(1)
    large = __PyWidget__.sizeForFamily(2)

    for size in [(0, small), (1, medium), (2, large)]:
        view.size = (size[1].width, size[1].height)
        
        func = view.layout
        if func is not None:
            if func.__code__.co_argcount >= 1:
                func(view)
            else:
                func()

        widget.setSnapshot(size[0])

    if key is None:
        __PyWidget__.updateTimeline(__widget_id__, widget=widget)
    else:
        __PyWidget__.addWidget(widget, key=key)


def show_view(view: ui.View):
    """
    Shows the given view on a widget. A snapshot for each widget size will be taken.

    :param view: A view to show in the widget.
    """

    global __shown_view__
    __shown_view__ = True

    __show_view__(view)


def save_snapshot(view: ui.View, key: str):
    """
    Saves the snapshot of the given view. The snapshot will be selectable to show in a widget and can be updated in app.

    :param view: A view to show in the widget.
    :param key: The name of the snapshot. When a new snapshot is saved with an existing key, the widget will be updated.
    """

    __show_view__(view, key)

