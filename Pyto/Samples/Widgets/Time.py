import widgets as wd
from datetime import time

BACKGROUND = wd.Color.rgb(255/255, 250/255, 227/255)
FOREGROUND = wd.Color.rgb(75/255, 72/255, 55/255)

widget = wd.Widget()

date = wd.DynamicDate(
    date=time(0, 0, 0),
    style=wd.DATE_STYLE_RELATIVE,
    font=wd.Font("AmericanTypewriter-Bold", 30),
    color=FOREGROUND,
    padding=wd.PADDING_ALL
)

for layout in [
    widget.small_layout,
    widget.medium_layout,
    widget.large_layout]:
    
    layout.add_row([date])
    layout.set_background_color(BACKGROUND)

# Show the widget and reload every hour
# It needs to be reloaded at least once per day, but we don't know when the day will end
wd.schedule_next_reload(60*60)
wd.show_widget(widget)
