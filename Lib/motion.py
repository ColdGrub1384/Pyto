"""
Motion sensors

The ``motion`` module gives access to the device's accelerometer, gyroscope and magnetometer data.
"""

from pyto import PyMotionHelper as __PyMotionHelper__
from collections import namedtuple


Gravity = namedtuple("Gravity", "x y z")
"""
A tuple containing data about gravity (x, y, z).
"""

Rotation = namedtuple("Rotation", "x y z")
"""
A tuple containing data about rotation (x, y, z).
"""

Acceleration = namedtuple("Acceleration", "x y z")
"""
A tuple containing data about acceleration (x, y, z).
"""

MagneticField = namedtuple("MagneticField", "x y z")
"""
A tuple containing data about magnetic field (x, y, z).
"""

Attitude = namedtuple("Attitude", "roll pitch yaw")
"""
A tuple containing data about attitude (roll, pitch, yaw).
"""


def start_updating():
    """
    Starts receiving information from the sensors.
    """

    __PyMotionHelper__.startUpdating()


def stop_updating():
    """
    Stops receiving information from the sensors
    """

    __PyMotionHelper__.stopUpdating()


def get_gravity() -> Gravity:
    """
    Returns a tuple with information about gravity (x, y, z).

    :rtype: Gravity
    """

    gravity = __PyMotionHelper__.gravity
    return Gravity(float(str(gravity[0])), float(str(gravity[1])), float(str(gravity[2])))


def get_rotation() -> Rotation:
    """
    Returns a tuple with information about rotation (x, y, z).

    :rtype: Rotation
    """

    rotation = __PyMotionHelper__.rotation
    return Rotation(float(str(rotation[0])), float(str(rotation[1])), float(str(rotation[2])))


def get_acceleration() -> Acceleration:
    """
    Returns a tuple with information about acceleration (x, y, z).

    :rtype: Acceleration
    """

    acceleration = __PyMotionHelper__.acceleration
    return Acceleration(
        float(str(acceleration[0])), float(str(acceleration[1])), float(str(acceleration[2]))
    )


def get_magnetic_field() -> MagneticField:
    """
    Returns a tuple with information about the magnetic field (x, y, z).

    :rtype: MagneticField
    """

    magnetic_field = __PyMotionHelper__.magneticField
    return MagneticField(
        float(str(magnetic_field[0])), float(str(magnetic_field[1])), float(str(magnetic_field[2]))
    )


def get_attitude() -> Attitude:
    """
    Returns a tuple with information about the attitude (roll, pitch, yaw).

    :rtype: Attitude
    """

    attitude = __PyMotionHelper__.attitude
    return Attitude(float(str(attitude[0])), float(str(attitude[1])), float(str(attitude[2])))
