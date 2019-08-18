import pyto_ui as ui
from time import sleep

switch = ui.Switch(False)

def did_switch(sender):
    print(sender.on)

def layout(sender):
    sleep(0.5)
    switch.set_on_with_animation(True)

view = ui.View()
view.background_color = ui.COLOR_SYSTEM_BACKGROUND
view.layout = layout

switch.center = (view.width/2, view.height/2)
switch.flex = [
    ui.FLEXIBLE_BOTTOM_MARGIN,
    ui.FLEXIBLE_TOP_MARGIN,
    ui.FLEXIBLE_LEFT_MARGIN,
    ui.FLEXIBLE_RIGHT_MARGIN
]
switch.action = did_switch
view.add_subview(switch)

ui.show_view(view, ui.PRESENTATION_MODE_SHEET)
