"""
A Text View that edits the clipboard.
"""

import pyto_ui as ui
import pasteboard as pb

def did_end(text_view):
  pb.set_string(text_view.text)

text_view = ui.TextView(text=pb.string())
text_view.become_first_responder()

text_view.did_end_editing = did_end
text_view.font = ui.Font.system_font_of_size(17)
text_view.text_alignment = ui.TEXT_ALIGNMENT_CENTER

ui.show_view(text_view, ui.PRESENTATION_MODE_SHEET)