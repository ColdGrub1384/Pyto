# Created with Pyto

import pyto_ui as ui

class View(ui.VerticalStackView):

    def label(self) -> ui.Label:
        label = ui.Label()
        label.text = "Hello World!"
        label.font = ui.Font.bold_system_font_of_size(20)
        return label

    def __init__(self):
        super().__init__()

        self.add_subview(self.label())


view = View()
ui.show_view(view, ui.PRESENTATION_MODE_FULLSCREEN)
