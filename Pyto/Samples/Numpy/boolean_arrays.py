"""
An example of indexing with boolean arrays
"""

import numpy as pd

a = np.arange(12).reshape(3,4)
b = a > 4
print(b)                                          # b is a boolean with a's shape

print(a[b])                                       # 1d array with the selected elements
