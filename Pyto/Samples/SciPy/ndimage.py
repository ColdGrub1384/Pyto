"""
An example of rotating an image with SciPy.

Taken from https://www.guru99.com/scipy-tutorial.html
"""

from scipy import ndimage, misc
from matplotlib import pyplot as plt

panda = misc.face()
#rotatation function of scipy for image – image rotated 135 degree
panda_rotate = ndimage.rotate(panda, 135)
plt.imshow(panda_rotate)
plt.show()
