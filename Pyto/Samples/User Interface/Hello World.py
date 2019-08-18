"""
A button that closes the UI when it's pressed.
"""

import pyto_ui as ui
    
def button_pressed(sender):
    sender.superview.close()

view = ui.View()
view.background_color = ui.COLOR_SYSTEM_BACKGROUND
     
button = ui.Button(title="Hello World!")
button.size = (100, 50)
button.center = (view.width/2, view.height/2)
button.flex = [
    ui.FLEXIBLE_BOTTOM_MARGIN,
    ui.FLEXIBLE_TOP_MARGIN,
    ui.FLEXIBLE_LEFT_MARGIN,
    ui.FLEXIBLE_RIGHT_MARGIN
]
button.action = button_pressed
view.add_subview(button)

ui.show_view(view, ui.PRESENTATION_MODE_SHEET)

print("Hello World!")
