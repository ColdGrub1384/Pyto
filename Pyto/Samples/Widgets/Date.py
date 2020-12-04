"""
A widget showing the current week day and date.
"""

import widgets as wd
from datetime import datetime, timedelta

BACKGROUND = wd.Color.rgb(255/255, 250/255, 227/255)
FOREGROUND = wd.Color.rgb(75/255, 72/255, 55/255)

def weekday(date):
    day = date.weekday()
    if day == 0:
        return "Monday"
    elif day == 1:
        return "Tuesday"
    elif day == 2:
        return "Wednesday"
    elif day == 3:
        return "Thursday"
    elif day == 4:
        return "Friday"
    elif day == 5:
        return "Saturday"
    elif day == 6:
        return "Sunday"

class DateProvider(wd.TimelineProvider):

    def timeline(self):
        today = datetime.today()
        today = datetime.combine(today, datetime.min.time())

        dates = []
        for i in range(30):
            date = today + timedelta(days=i)
            dates.append(date)

        return dates

    def widget(self, date):
        widget = wd.Widget()
        layout = widget.medium_layout

        day = wd.Text(
            text=weekday(date),
            font=wd.Font("AmericanTypewriter-Bold", 50),
            color=FOREGROUND)

        date_text = wd.DynamicDate(
            date=date,
            font=wd.Font("AmericanTypewriter", 18),
            color=FOREGROUND,
            padding=wd.PADDING_ALL)

        layout.add_vertical_spacer()
        layout.add_row([day])
        layout.add_row([date_text])
        layout.set_background_color(BACKGROUND)
        layout.set_link(date.ctime())

        return widget

if wd.link is not None:
    print(wd.link)
else:
    wd.provide_timeline(DateProvider())
