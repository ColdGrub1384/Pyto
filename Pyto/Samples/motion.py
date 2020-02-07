"""
Access the pitch of the device.
"""

import motion

motion.start_updating()

while True:
    a = motion.get_attitude()
    pitch = int(a.pitch*90)
    
    arrow = ""
    if pitch < 0:
        arrow = "↑"
    elif pitch > 0:
        arrow = "↓"
    
    print(f"\r{pitch}° {arrow}", end="")
