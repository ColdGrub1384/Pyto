"""
A draggable circle.
"""

import pyto_ui as ui

view = ui.View()
view.background_color = ui.COLOR_SYSTEM_BACKGROUND

circle = ui.View()
circle.size = (50, 50)
circle.center = (view.width/2, view.height/2)
circle.flex = [
  ui.FLEXIBLE_BOTTOM_MARGIN,
  ui.FLEXIBLE_TOP_MARGIN,
  ui.FLEXIBLE_LEFT_MARGIN,
  ui.FLEXIBLE_RIGHT_MARGIN
]
circle.corner_radius = 25
circle.background_color = ui.COLOR_LABEL
view.add_subview(circle)

def move(sender: ui.GestureRecognizer):
  if sender.state == ui.GESTURE_STATE_CHANGED:
    circle.center = sender.location
  
gesture = ui.GestureRecognizer(ui.GESTURE_TYPE_PAN)
gesture.action = move
view.add_gesture_recognizer(gesture)

ui.show_view(view, ui.PRESENTATION_MODE_SHEET)