# Created with Pyto

import pyto_ui as ui

class MainView(ui.View):

    def ib_init(self):
        pass

    def did_appear(self):
        pass

    @ui.ib_action
    def button_pressed(self, sender: ui.Button):
        print("Hello World!")
        self.close()

