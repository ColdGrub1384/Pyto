"""
An example of how to access the device's location.
"""

import location
from time import sleep

location.start_updating()

clear = u"{}[2J{}[;H".format(chr(27), chr(27))

while True:
    print(f"{clear}Current location: {location.get_location()}", end="")
    sleep(1)
