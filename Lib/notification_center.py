"""
Today Widgets

This module is used to manage Today Widget expansion / collapsion.
"""

from UIKit import UIDevice
from pyto import __Class__
from types import ModuleType
import sys

if UIDevice is not None and float(str(UIDevice.currentDevice.systemVersion)) < 13:
    raise ImportError("'notification_center' requires iPadOS / iOS 13")

__PyNotificationCenter__ = __Class__("PyNotificationCenter")


class __NotificationCenter__(ModuleType):
    @property
    def expandable(self):
        return __PyNotificationCenter__.canBeExpanded

    @expandable.setter
    def expandable(self, new_value):
        __PyNotificationCenter__.canBeExpanded = new_value

    @property
    def maximum_height(self):
        return __PyNotificationCenter__.maximumHeight

    @maximum_height.setter
    def maximum_height(self, new_value):
        __PyNotificationCenter__.maximumHeight = new_value


expandable = False
"""
If set to ``True``\ , the widget will be expandable.
"""

maximum_height = 280
"""
The maximum height of an expandable widget.
"""

if UIDevice is not None:
    sys.modules[__name__] = __NotificationCenter__(__name__)
