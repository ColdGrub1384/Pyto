"""
Peer to peer wireless connection

Use this module to trade data with other devices running Pyto. Works without WiFi.
"""

from pyto import PyMultipeerHelper
from __check_type__ import check


def connect():
    """
    Starts connecting to other devices.
    """

    PyMultipeerHelper.autoConnect()


def disconnect():
    """
    Disconnects from all connected devices.
    """

    PyMultipeerHelper.disconnect()


def send(data: str):
    """
    Sends the given string to other connected devices.

    :param data: The string to send.
    """

    check(data, "data", [str])

    PyMultipeerHelper.send(data)


def get_data() -> str:
    """
    Returns available data. Returns once per available data.

    :rtype: str
    """

    data = PyMultipeerHelper.data
    if data is None:
        return data
    else:
        PyMultipeerHelper.data = None
        return str(data)
