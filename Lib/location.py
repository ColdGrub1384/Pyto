"""
Accessing location

This module gives access to the devices's location.
"""

import pyto
import sys
from types import ModuleType
from collections import namedtuple
from typing import NamedTuple
from UIKit import UIApplication
from __check_type__ import check

__PyLocationHelper__ = pyto.PyLocationHelper


class Location(NamedTuple):
    """
    A tuple containing data about longitude, latitude and altitude (optional).
    """

    latitude: float

    longitude: float

    altitude: float = None


class __Location__(ModuleType):
    @property
    def accuracy(self):
        return float(__PyLocationHelper__.desiredAccuracy)

    @accuracy.setter
    def accuracy(self, new_value):

        check(new_value, "new_value", [float, int])

        __PyLocationHelper__.desiredAccuracy = new_value


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


def get_location() -> Location:
    """
    Returns a tuple with current longitude, latitude and altitude.

    :rtype: Location
    """

    return Location(
        float(__PyLocationHelper__.latitude),
        float(__PyLocationHelper__.longitude),
        float(__PyLocationHelper__.altitude),
    )


accuracy = -1
"""The number of meters from the original geographic coordinate that could yield the user's actual location."""

LOCATION_ACCURACY_BEST_FOR_NAVIGATION = -2
"""The highest possible accuracy that uses additional sensor data to facilitate navigation apps."""

LOCATION_ACCURACY_BEST = -1
"""The best level of accuracy available."""

LOCATION_ACCURACY_NEAREST_TEN_METERS = 10
"""Accurate to within ten meters of the desired target."""

LOCATION_ACCURACY_HUNDRED_METERS = 100
"""Accurate to within one hundred meters."""

LOCATION_ACCURACY_KILOMETER = 1000
"""Accurate to the nearest kilometer."""

LOCATION_ACCURACY_THREE_KILOMETERS = 3000
"""Accurate to the nearest three kilometers."""

if UIApplication is not None:
    location = __Location__(__name__)
    location.__all__ = [
        "start_updating",
        "stop_updating",
        "get_location",
        "LOCATION_ACCURACY_BEST_FOR_NAVIGATION",
        "LOCATION_ACCURACY_BEST",
        "LOCATION_ACCURACY_NEAREST_TEN_METERS",
        "LOCATION_ACCURACY_HUNDRED_METERS",
        "LOCATION_ACCURACY_KILOMETER",
        "LOCATION_ACCURACY_THREE_KILOMETERS",
    ]
    location.start_updating = start_updating
    location.stop_updating = stop_updating
    location.get_location = get_location
    location.LOCATION_ACCURACY_BEST_FOR_NAVIGATION = (
        LOCATION_ACCURACY_BEST_FOR_NAVIGATION
    )
    location.LOCATION_ACCURACY_BEST = LOCATION_ACCURACY_BEST
    location.LOCATION_ACCURACY_NEAREST_TEN_METERS = LOCATION_ACCURACY_NEAREST_TEN_METERS
    location.LOCATION_ACCURACY_HUNDRED_METERS = LOCATION_ACCURACY_HUNDRED_METERS
    location.LOCATION_ACCURACY_KILOMETER = LOCATION_ACCURACY_KILOMETER
    location.LOCATION_ACCURACY_THREE_KILOMETERS = LOCATION_ACCURACY_THREE_KILOMETERS
    location.Location = Location

    sys.modules[__name__] = location
