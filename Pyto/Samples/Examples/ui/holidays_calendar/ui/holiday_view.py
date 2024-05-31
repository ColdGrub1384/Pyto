import pyto_ui as ui
from ..cal import Holiday
from datetime import datetime
import calendar_events as cal

class HolidayView(ui.View):
    
    add_button_container: ui.StackView
    
    remove_button_container: ui.StackView
    
    date_label: ui.Label
    
    holiday: Holiday
    
    def event_saved(self) -> cal.Event:
        date = self.holiday.date
        start = datetime(date.year, date.month, date.day)
        end = datetime(date.year, date.month, date.day, 23, 59)
        
        events = cal.get_events(start, end)
        print(events)
        for event in events:
            if event.title == self.holiday.name:
                return event
    
    
    def place_buttons(self):
        saved = (self.event_saved() is not None)
        self.add_button_container.hidden = saved
        self.remove_button_container.hidden = not saved
    
    
    def set_holiday(self, holiday: Holiday):
        self.holiday = holiday
        self.title = holiday.date.strftime("%d %B")
        self.date_label.text = holiday.name
        
    
    def did_appear(self):
        self.place_buttons()

    
    @ui.ib_action
    def remove_event(self, sender: ui.Button):
        saved = self.event_saved()
        if saved is not None:
            cal.remove_event(saved)
        
        self.place_buttons()
    
    @ui.ib_action
    def add_event(self, sender: ui.Button):
        
        date = self.holiday.date
        start = datetime(date.year, date.month, date.day)
        end = datetime(date.year, date.month, date.day, 23, 59)
        
        event = cal.Event()
        event.title = self.holiday.name
        event.start_date = start
        event.end_date = end
        event.all_day = True
        
        cal.save_event(event)
        
        self.place_buttons()
    
    
    @ui.ib_action
    def done(self, sender: ui.Button):
        self.close()