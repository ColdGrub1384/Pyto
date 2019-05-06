"""
Shows an alert.
"""

from console import Alert
from sys import platform

# Code here

alert = Alert.alertWithTitle("Hello", message="Hello World!")
alert.addAction("Ok")
if platform == "ios":
    alert.addCancelAction("Cancel")
else:
    alert.addAction("Cancel")
if (alert.show() == "Ok"):
  print("Good Bye!")
