"""
Shows an alert.
"""

import console

# Code here

alert = console.Alert.alertWithTitle("Hello", message="Hello World!")
alert.addAction("Ok")
alert.addCancelAction("Cancel")
if (alert.show() == "Ok"):
  print("Good Bye!")
