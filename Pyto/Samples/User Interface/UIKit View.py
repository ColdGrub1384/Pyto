"""
Using an UIKit view.
"""

import pyto_ui as ui
from UIKit import UIDatePicker
from Foundation import NSObject
from rubicon.objc import objc_method, SEL
from datetime import datetime

# We subclass ui.UIKitView to implement a date picker
class DatePicker(ui.UIKitView):
    
    did_change = None

    # Here we return an UIDatePicker object
    def make_view(self):
        picker = UIDatePicker.alloc().init()
        
         # We create an Objective-C instance that will respond to the date picker value changed event
        delegate = PickerDelegate.alloc().init()
        delegate.picker = self
        delegate.objc_picker = picker
        
        # 4096 is the value for UIControlEventValueChanged
        picker.addTarget(delegate, action=SEL("didChange"), forControlEvents=4096)
        return picker
    
# An Objective-C class for addTarget(_:action:forControlEvents:)
class PickerDelegate(NSObject):

    picker = None

    @objc_method
    def didChange(self):
        if self.picker.did_change is not None:
            date = self.objc_picker.date
            date = datetime.fromtimestamp(date.timeIntervalSince1970())
            self.picker.did_change(date)

# Then we can use our date picker as any other view

view = ui.View()
view.background_color = ui.COLOR_SYSTEM_BACKGROUND

def did_change(date):
    view.title = str(date)

date_picker = DatePicker()
date_picker.did_change = did_change

date_picker.flex = [
    ui.FLEXIBLE_BOTTOM_MARGIN,
    ui.FLEXIBLE_TOP_MARGIN,
    ui.FLEXIBLE_LEFT_MARGIN,
    ui.FLEXIBLE_RIGHT_MARGIN
]
date_picker.center = view.center
view.add_subview(date_picker)

ui.show_view(view, ui.PRESENTATION_MODE_SHEET)
