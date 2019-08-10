"""
Shows an alert.
"""

from pyto_ui import Alert

# Code here

alert = Alert("Hello", "Hello World!")
alert.add_action("Ok")
alert.add_cancel_action("Cancel")
if (alert.show() == "Ok"):
  print("Good Bye!")
