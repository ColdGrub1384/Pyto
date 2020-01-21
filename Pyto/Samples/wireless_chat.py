"""
Send text to other devices running this script remotely.
"""

import multipeer
from console import clear
from time import sleep
from threading import Thread
from PIL import Image

done = False

def loop():
    while not done:
        data = multipeer.get_data()
        if data is not None:
            clear()
            print(data)
            print("> ", end="")
        sleep(0.2)

Thread(target=loop).start()

multipeer.connect()

try:
    while True:
        multipeer.send(input("> "))
except:
    done = False
