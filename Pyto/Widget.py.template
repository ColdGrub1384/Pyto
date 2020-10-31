# Created with Pyto

import widgets as wd
import datetime as dt


class TimelineProvider(wd.TimelineProvider):

    # Provide data for the next 10 hours
    def timeline(self):

        # Number of dates
        count = 10

        # Space between dates
        delta = dt.timedelta(hours=1)

        dates = []
        for i in range(count):
            date = dt.datetime.now() + (delta * i)
            dates.append(date)

        return dates

    # Create the widget for the given timestamp
    def widget(self, date):
        widget = wd.Widget()

        text = wd.DynamicDate(date)
        text.font = wd.Font.bold_system_font_of_size(40)

        # Supported layouts
        layouts = [widget.small_layout, widget.medium_layout, widget.large_layout]

        for layout in layouts:
            layout.add_row([text])

        return widget


wd.provide_timeline(TimelineProvider())
