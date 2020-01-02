"""
The Pyto's console can display colored output, images and progress bars.
"""

from console import clear

# ————————————
# Progress bar
# ____________

from progress.bar import ChargingBar as Bar
from time import sleep

bar = Bar('Progress Bar', max=20)
for i in range(20):
    sleep(0.1)
    bar.next()
bar.finish()

clear()

# ———————————————
# Carriage return
# _______________

for i in range(20):
    print(f"\r{i+1}", end="")
    sleep(0.1)

clear()

# ——————
# Images
# ______

from PIL import Image
from scipy import misc

f = Image.fromarray(misc.face())
f.show()

clear()

# —————————————
# Terminal size
# _____________

import os
h = int(os.environ["ROWS"])-1
w = int(os.environ["COLUMNS"])-1

print("-"*w)

for i in range(h-2):
    print("|"+(" "*(w-2))+"|")

print("—"*w)

clear()

# ——————
# Colors
# ______

for style in range(8):
    for fg in range(30,38):
        s1 = ""
        for bg in range(40,48):
            format = ";".join([str(style), str(fg), str(bg)])
            s1 += "\x1b[%sm %s \x1b[0m" % (format, format)
        print(s1)
    print("\n")
