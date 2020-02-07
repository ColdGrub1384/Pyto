"""
A script that access the devices accelerometer.
"""

import motion
from time import sleep

motion.start_updating()

while True:
    a = motion.get_acceleration()
    if a.x > 0 or a.x <= -1:
        print("Moved x")
    if a.y > 0 or a.y <= -1:
        print("Moved y")
    if a.z > 0 or a.z <= -1:
        print("Moved z")
    sleep(0.2)
