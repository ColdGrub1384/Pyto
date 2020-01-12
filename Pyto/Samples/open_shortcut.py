"""
Opens a Shortcut and retrieves the result.
"""

import xcallback
from urllib.parse import quote

shortcut_name = input("The name of the shortcut to open: ")
shortcut_input = input("What would you like to send to the Shortcut? ")

url = f"shortcuts://x-callback-url/run-shortcut?name={quote(shortcut_name)}&input=text&text={quote(shortcut_input)}"

try:
    res = xcallback.open_url(url)
    print("Result:\n"+res)
except RuntimeError as e:
    print("Error: "+str(e))
except SystemExit:
    print("Cancelled")
