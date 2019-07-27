"""
Generates a random color and display it on screen
"""

from PIL import Image
from random import randint

red = randint(0, 255)
green = randint(0, 255)
blue = randint(0, 255)

img = Image.new("RGB", (100, 20), (red, green, blue))
img.show()

print("")
print(red, green, blue, sep=", ")
print("#{:02x}{:02x}{:02x}".format(red, green, blue))