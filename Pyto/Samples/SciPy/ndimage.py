"""
An example of rotating an image with SciPy.

Taken from https://www.guru99.com/scipy-tutorial.html
"""

from scipy import ndimage, misc
from PIL import Image

panda = misc.face()
#rotatation function of scipy for image – image rotated 135 degree
panda_rotate = ndimage.rotate(panda, 135)
Image.fromarray(panda_rotate).show()
