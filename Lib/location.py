"""
Accessing location

This module gives access to the devices's location.
"""

import os
import pyto
from typing import Tuple

if "widget" in os.environ:
    raise ImportError("Cannot use this module on a widget.")

__PyLocationHelper__ = pyto.PyLocationHelper


def start_updating():
    """
    Starts receiving location updates. Call this before calling :func:`~location.get_location`.
    """

    __PyLocationHelper__.startUpdating()


def stop_updating():
    """
    Stops receiving location updates.
    """

    __PyLocationHelper__.stopUpdating()


def get_location() -> Tuple[float]:
    """
    Returns a tuple with current longitude, latitude and altitude.

    :rtype: Tuple[float]
    """

    return (float(__PyLocationHelper__.longitude), float(__PyLocationHelper__.latitude), float(__PyLocationHelper__.altitude))
