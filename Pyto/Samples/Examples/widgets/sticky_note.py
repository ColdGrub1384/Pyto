"""
This widget let's you write a note on it.

Usage
=====

1. Run the script and write a note.

2. Add an "In App" widget on your home screen and select "Note" as the category.

3. Now you can tap on the widget to write anything on it.
"""

import widgets as wd
import sf_symbols as sf
from UIKit import UIApplication
from mainthread import mainthread

# Constants

BACKGROUND = wd.Color.rgb(236/255, 212/255, 0/255)
FOREGROUND = wd.Color.rgb(75/255, 72/255, 53/255)

# Creating the widget

@mainthread
def suspend():
    UIApplication.sharedApplication.suspend()

note = input("Note: ")

widget = wd.Widget()
text = wd.Text(
    note,
    font=wd.Font("AmericanTypewriter", 18),
    color=FOREGROUND,
    padding=wd.PADDING_HORIZONTAL)

symbol = wd.SystemSymbol(
    sf.PENCIL,
    color=FOREGROUND,
    padding=wd.Padding(10, 0, 10, 0),
    font_size=20)

layouts = [widget.small_layout, widget.medium_layout, widget.large_layout]

for layout in layouts:
    layout.add_row([symbol, wd.Spacer()])
    layout.add_vertical_spacer()
    layout.add_row([text])
    layout.add_vertical_spacer()
    layout.set_background_color(BACKGROUND)

wd.save_widget(widget, "Note")

suspend()
