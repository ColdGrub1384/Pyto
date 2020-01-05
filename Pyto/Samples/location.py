"""
An example of how to access the device's location.
"""

import location
from time import sleep

location.start_updating()

while True:
    print(f"\rCurrent location: {location.get_location()}", end="")
    sleep(1)
