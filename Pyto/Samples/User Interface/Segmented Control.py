"""
A segmented control with a label showing its current state on top.
"""

import pyto_ui as ui

view = ui.View()
view.background_color = ui.COLOR_SYSTEM_BACKGROUND

label = ui.Label()
label.font = ui.Font.font_with_style(ui.FONT_TEXT_STYLE_LARGE_TITLE)
label.frame = (0, 20, view.width, 50)
label.text_alignment = ui.TEXT_ALIGNMENT_CENTER
label.flex = [ui.FLEXIBLE_WIDTH]
view.add_subview(label)

segmented_control = ui.SegmentedControl()
segmented_control.segments = ["Foo", "Bar"]
segmented_control.width = 200
segmented_control.center = (view.width/2, view.height/2)
segmented_control.flex = [
    ui.FLEXIBLE_BOTTOM_MARGIN,
    ui.FLEXIBLE_TOP_MARGIN,
    ui.FLEXIBLE_LEFT_MARGIN,
    ui.FLEXIBLE_RIGHT_MARGIN
]

def did_select(sender):
    label.text = sender.segments[sender.selected_segment]

segmented_control.action = did_select
view.add_subview(segmented_control)

ui.show_view(view, ui.PRESENTATION_MODE_SHEET)
