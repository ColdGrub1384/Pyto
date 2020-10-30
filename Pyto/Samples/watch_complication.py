"""
A small circular watchOS complication showing the current minute.

After running, the script must be selected in the 'Apple Watch' setting.
Then, a watchOS complication named 'Minutes' will appear in the Watch Face customizer.
This particular complication only works in the small circular setup.
"""

import watch as wt
import widgets as wd
import datetime as dt

class MinutesProvider(wt.ComplicationsProvider):

    def name(self):
        return "Minutes"

    def timeline(self, after_date, limit):
        dates = []
        for i in range(limit):
            delta = dt.timedelta(minutes=i*1)
            date = after_date + delta
            date = date.replace(second=0)
            dates.append(date)

        return dates

    def complication(self, date):

        min = date.time().minute
        text = wd.Text(str(min), font=wd.Font.bold_system_font_of_size(20))

        complication = wt.Complication()
        complication.circular.add_row([text])

        return complication

wt.add_complications_provider(MinutesProvider())
