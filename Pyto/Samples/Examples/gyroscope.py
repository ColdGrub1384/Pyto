"""
Access the pitch of the device.
"""

import motion


def main():
    motion.start_updating()

    try:
        while True:
            a = motion.get_attitude()
            pitch = int(a.pitch*90)
            
            arrow = ""
            if pitch < 0:
                arrow = "↑"
            elif pitch > 0:
                arrow = "↓"
            
            print(f"\r{pitch}° {arrow}", end="")
    except (KeyboardInterrupt, SystemExit):
        motion.stop_updating()


if __name__ == "__main__":
    main()

