# Created with Pyto

# This widget updates when the script is executed (from the app or from Shortcuts)

import widgets as wd

widget = wd.Widget()

text = wd.Text(
    "Hello World!",
    padding=wd.PADDING_HORIZONTAL)

# Supported layouts
layouts = [
    widget.small_layout,
    widget.medium_layout,
    widget.large_layout,
    widget.extra_large_layout
]

for layout in layouts:
    layout.add_vertical_spacer()
    layout.add_row([text])
    layout.add_vertical_spacer()

wd.save_widget(widget, "<WIDGET NAME>")

print("Created widget")
