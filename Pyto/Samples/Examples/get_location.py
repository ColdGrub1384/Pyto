"""
An example of how to access the device's location.
"""

import location
from time import sleep


clear = u"{}[2J{}[;H".format(chr(27), chr(27))


def main():
    location.start_updating()

    try:
    
        while True:
            current_location = location.get_location()
            url = f"http://maps.apple.com/?ll={current_location.latitude},{current_location.longitude}"
            url_escaped = f'\x1b[4m\x1b]8;;{url}\x07Open in Maps\x1b]8;;\x07\x1b[0m'
            
            print(f"{clear}Current location: {current_location}\n\n{url_escaped}")
            sleep(1)
    
    except (KeyboardInterrupt, SystemExit):
        print("")
        location.stop_updating()


if __name__ == "__main__":
    main()
