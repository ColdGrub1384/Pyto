"""
You can open items from other apps with a Python script.
To do that, open the share sheet, select "Run Pyto script" and select the script you want to run. The script will have access to the shared items.

# How to test this script?

To test this script, click the share button on the editor, save the file somewhere in the Files app and open any item with this script from the share sheet.
"""

import appex

# Code here

items = appex.extensionItems()
if (items != None):
    print("Shared items are:\n")
    for item in items:
        print("-", item)
else:
    print("\n\nTo test this script, click the share button on the editor, save the file somewhere in the Files app and open any item with this script from the share sheet.")
