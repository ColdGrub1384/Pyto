"""
Schedule notifications

Use the ``notifications`` to schedule notifications that can be delivered even if Pyto isn't opened.
"""

from pyto import __Class__
from typing import List
from __check_type__ import check


try:
    from rubicon.objc import ObjCClass
except ValueError:
    pass


__PyNotificationCenter__ = __Class__("PyNotificationCenter")


try:
    UNUserNotificationCenter = ObjCClass("UNUserNotificationCenter")
    """
    The 'UNUserNotificationCenter' class from the ``UserNotifications`` framework.
    """
except NameError:
    UNUserNotificationCenter = None
    """
    The 'UNUserNotificationCenter' class from the ``UserNotifications`` framework.
    """


class Notification:
    """
    A class representing a notification.
    """

    __id__ = None

    message = None
    """
    The body of the notification.
    """

    url = None
    """
    The URL to open when the notification is opened.
    """

    actions = None
    """
    Additional actions on the notification.

    A dictionary with the name of the action and the URL to open.
    """


def get_pending_notifications() -> List[Notification]:
    """
    Returns a list of pending notifications. Notifications cannot be modified after being scheduled.

    :rtype: List[Notification]
    """

    notifications = []
    for request in __PyNotificationCenter__.scheduled:
        notification = Notification()
        notification.message = str(request.content.body)
        notification.url = str(request.content.userInfo["url"])
        notification.__id__ = str(request.identifier)

        actions = {}
        for key in request.content.userInfo["actions"].allKeys():
            actions[str(key)] = str(request.content.userInfo["actions"][key])

        notification.actions = actions

        notifications.append(notification)

    return notifications


def cancel_notification(notification: Notification):
    """
    Cancels a pending notification.

    :param notification: The :class:`~notifications.Notification` object returned from :func:`~notifications.get_pending_notifications`.
    """

    check(notification, "notification", [Notification])

    UNUserNotificationCenter.currentNotificationCenter().removePendingNotificationRequestsWithIdentifiers([notification.__id__])


def remove_delivered_notifications():
    """
    Removes all delivered notifications from the Notification Center.
    """

    UNUserNotificationCenter.currentNotificationCenter().removeAllDeliveredNotifications()


def cancel_all():
    """
    Cancels all pending notifications.
    """

    UNUserNotificationCenter.currentNotificationCenter().removeAllPendingNotificationRequests()


def schedule_notification(notification: Notification, delay: float, repeat: bool):
    """
    Schedules a notification.

    :param Notification: The :class:`~notifications.Notification` object representing the notification content.
    :param delay: The time interval in seconds until the notification is delivered.
    :param repeat: A boolean indicating whether the notification delivery should be repeated indefinitely.
    """

    __PyNotificationCenter__.scheduleNotificationWithMessage(notification.message, delay=delay, url=notification.url, actions=notification.actions, repeats=repeat)
