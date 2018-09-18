"""
Shows an alert.
"""

import console

# Code here

def ok() -> None:
  print("Good Bye!")

alert = console.Alert.initWithTitle("Hello", message="Hello World!")
alert.addActionWithTitle("Ok", handler=ok)
alert.addCancelActionWithTitle("Cancel", handler=None)
alert.show()
