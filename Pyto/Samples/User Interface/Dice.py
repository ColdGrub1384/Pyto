"""
A script to roll a dice runnable on a widget.
This script was converted from Pythonista examples to work on Pyto.
"""

import pyto_ui as ui
import random
import notification_center as nc

nc.expandable = True
nc.maximum_height = 300

v = ui.View()

label = ui.Label()
label.text_alignment = ui.TEXT_ALIGNMENT_RIGHT
label.font = ui.Font.system_font_of_size(100)
label.frame = (v.center_x, 0, v.width/2, 70)
label.flex = [ui.FLEXIBLE_WIDTH]
v.add_subview(label)

button = ui.Button()
button.title = "Roll"
button.font = ui.Font.system_font_of_size(60)
button.horizontal_alignment = ui.HORZONTAL_ALIGNMENT_LEFT
button.size_to_fit()
button.origin = (0, 0)
button.width = v.width/2
button.flex = [
    ui.FLEXIBLE_WIDTH,
    ui.FLEXIBLE_LEFT_MARGIN,
    ui.FLEXIBLE_RIGHT_MARGIN
]
button.flexible_margins, button.flexible_width = True, True
button.flexible_top_margin, button.flexible_bottom_margin = False, False
v.add_subview(button)

def layout(v):
    if v.height <= 150:
        label.text_alignment = ui.TEXT_ALIGNMENT_RIGHT
        label.font = ui.Font.system_font_of_size(100)
        label.frame = (v.center_x, 0, v.width/2, 70)

        button.origin = (0, 0)
        button.width = v.width/2
        button.horizontal_alignment = ui.HORZONTAL_ALIGNMENT_LEFT
        button.font = ui.Font.system_font_of_size(60)
    else:
        label.text_alignment = ui.TEXT_ALIGNMENT_CENTER
        label.font = ui.Font.system_font_of_size(200)
        label.frame = (0, v.height-label.height-140, v.width, 140)

        button.origin = (0, 0)
        button.width = v.width
        button.horizontal_alignment = ui.HORZONTAL_ALIGNMENT_CENTER
        button.font = ui.Font.system_font_of_size(30)

v.layout = layout

def random_string():
    symbols = ['\u2680', '\u2681', '\u2682', '\u2683', '\u2684', '\u2685']
    dice = [random.randint(1, 6) for i in range(2)]
    return ''.join(symbols[i - 1] for i in dice)

def roll_action(sender):
    label.text = random_string()

button.action = roll_action

roll_action(button)

ui.show_view(v, ui.PRESENTATION_MODE_WIDGET)
