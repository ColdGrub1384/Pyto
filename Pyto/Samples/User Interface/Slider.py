"""
A slider.
"""

import pyto_ui as ui
from time import sleep

slider = ui.Slider(0)

def did_slide(sender):
    print(sender.value)

def layout(sender):
    sleep(0.5)
    slider.set_value_with_animation(50)

view = ui.View()
view.background_color = ui.COLOR_SYSTEM_BACKGROUND
view.layout = layout

slider.maximum_value = 100
slider.width = 200
slider.center = (view.width/2, view.height/2)
slider.flex = [
    ui.FLEXIBLE_BOTTOM_MARGIN,
    ui.FLEXIBLE_TOP_MARGIN,
    ui.FLEXIBLE_LEFT_MARGIN,
    ui.FLEXIBLE_RIGHT_MARGIN
]
slider.action = did_slide
view.add_subview(slider)

ui.show_view(view, ui.PRESENTATION_MODE_SHEET)
