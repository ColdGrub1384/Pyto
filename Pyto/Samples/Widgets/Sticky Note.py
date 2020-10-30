"""
An example for In App widgets. When the widget is pressed, it opens the app, asks for a note and displays the note on the widget.
After running the script once, you can set it in an "In App" widget.
The content of the widget is set by a script executed in app and is not updated automatically.
"""

import widgets as wd
import sf_symbols as sf
from UIKit import UIApplication
from mainthread import mainthread

BACKGROUND = wd.Color.rgb(255/255, 250/255, 227/255)
FOREGROUND = wd.Color.rgb(75/255, 72/255, 55/255)

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
