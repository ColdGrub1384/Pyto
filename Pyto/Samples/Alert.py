"""
Shows an alert.
"""

import pyto

# Code here

def ok() -> None:
  print("Good Bye!")

alert = pyto.Alert.initWithTitle("Hello", message="Hello World!")
alert.addActionWithTitle("Ok", handler=ok)
alert.addCancelActionWithTitle("Cancel", handler=None)
alert.show()
