import widgets as wd
from datetime import datetime

BACKGROUND = wd.Color.rgb(255/255, 250/255, 227/255)
FOREGROUND = wd.Color.rgb(75/255, 72/255, 55/255)

widget = wd.Widget()

date = wd.DynamicDate(
    date=datetime.today(),
    font=wd.Font("AmericanTypewriter-Bold", 25),
    color=FOREGROUND,
    padding=wd.PADDING_ALL
)

for layout in [
    widget.small_layout,
    widget.medium_layout,
    widget.large_layout]:
    
    layout.add_row([date])
    layout.set_background_color(BACKGROUND)

# Show the widget and reload every 2 hours
wd.schedule_next_reload(60*60*2)
wd.show_widget(widget)
