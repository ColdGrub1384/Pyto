"""
Receive remote notifications

This module has everything needed to receive push notifications from a server.
"""

from pyto import __Class__
from time import sleep
from typing import Dict


__RemoteNotifications__ = __Class__("RemoteNotifications")


def remove_category(category: str):
    """
    Removes a category with its given identifier.

    :param category: The identifier of the category to remove.
    """

    __RemoteNotifications__.removeCategory(category)


def add_category(id: str, actions: Dict[str, str]):
    """
    Adds a category of notification.

    A category contains set of actions for a certain type of notifications.

    :param id: The unique identifier of the category.
    :param actions: A dictionary with actions displayed by the notification.

    The actions are in a dictionary. Each key is the name of an action and its value is a URL that will be opened when the action is pressed.
    The ``"{}"`` characters on URLs will be replaced by a percent encoded data sent by the server.

    Example:

    .. highlight:: python
    .. code-block:: python

        import remote_notifications as rn

        actions = {
            "Google": "https://www.google.com/search?q={}"
        }
        rn.add_category("google", actions)

    In the example above, if a notification with the category id `"google"` is received, an action will be added to the notification.
    When it's pressed, Pyto will search on Google for the data passed by the server.
    """

    __RemoteNotifications__.addCategory(id, actions=actions)


def register() -> str:
    """
    Registers the device for push notifications.

    Returns a token to use with the api.

    :rtype: str
    """

    __RemoteNotifications__.register()

    while True:

        if __RemoteNotifications__.error is not None:
            raise RuntimeError(str(__RemoteNotifications__.error))

        if __RemoteNotifications__.deviceToken is not None:
            return str(__RemoteNotifications__.deviceToken)

        sleep(0.2)
