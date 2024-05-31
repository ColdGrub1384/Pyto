"""
A widget that tracks how many times you opened an app in a day.

Usage
=====

1. Run this script.

2. Open Shortcuts and add an automation triggered when an app is opened.

3. Select any app for which you want to monitor launches. For example, Twitter.

4. Add the "Run Script" action and select this script.

5. As an argument, pass the name of the app you previously chose. So in this case: Twitter.

6. Run the automation.

7. Add an "In App" widget to your homescreen and select the widget named "< App > launches". In this case, "Twitter launches".

The widget will update when you open the app. However, it will not update immediately like the other widgets. It will take some time because iOS doesn't update widgets immediately unless the corresponding app is in foreground. 
"""

import widgets as wd
import userkeys as uk
import sys
from datetime import date

try:
    APP_NAME = sys.argv[1]
except IndexError:
    msg = "Pass the name of an app as an argument to setup the widget."
    raise ValueError(msg)

# Constants

LAST_LAUNCH_KEY = f"app_widget.last_launch.{APP_NAME}"
LAUNCH_COUNT_KEY = f"app_widget.launch_count.{APP_NAME}"
TODAY = date.today()

try:
    last_launch = uk.get(LAST_LAUNCH_KEY)
    if last_launch == TODAY.day:
        uk.set(uk.get(LAUNCH_COUNT_KEY)+1, LAUNCH_COUNT_KEY)
    else:
        uk.set(1, LAUNCH_COUNT_KEY)
except KeyError:
    uk.set(1, LAUNCH_COUNT_KEY)

uk.set(TODAY.day, LAST_LAUNCH_KEY)

BACKGROUND = wd.COLOR_SYSTEM_BLUE
FOREGROUND = wd.COLOR_WHITE

# Widget

widget = wd.Widget()

header = wd.Text(
    "You have opened",
    color=FOREGROUND,
    padding=wd.Padding(top=20, left=10, right=10),
)

app_name = wd.Text(
    APP_NAME,
    color=FOREGROUND,
    font=wd.Font.bold_system_font_of_size(17),
    padding=wd.Padding(top=5, left=10, right=10),
)

body = wd.Text(
    str(uk.get(LAUNCH_COUNT_KEY)),
    color=FOREGROUND,
    font=wd.Font("ChalkboardSE-Bold", 50),
)

footer = wd.Text(
    "times today",
    color=FOREGROUND,
    padding=wd.Padding(bottom=20),
)

# Supported layouts
layouts = [
    widget.small_layout,
    widget.medium_layout,
    widget.large_layout,
    widget.extra_large_layout
]

for layout in layouts:
    layout.add_row([header])
    layout.add_row([app_name])
    layout.add_vertical_spacer()
    layout.add_row([body])
    layout.add_vertical_spacer()
    layout.add_row([footer])
    
    layout.set_background_color(BACKGROUND)


wd.save_widget(widget, f"{APP_NAME} launches")
