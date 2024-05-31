"""
This widget reminds you to take breaks each 25 minutes during an x amount of time.

Usage
=====

1. Run the script.

2. Add an "In App" widget to your home screen and select "Timer" as the category. This widget only works on medium size, so make sure to select the 1x2 widget.

You can now tap on a button and a timer will start. You'll receive a notification to remind you to take breaks.
"""


import background as bg
import widgets as wd
import datetime as dt
import notifications as nc
import sf_symbols as sf
from threading import Thread
from time import sleep
from mainthread import mainthread
from UIKit import UIApplication

# Constants

BACKGROUND = wd.Color.rgb(122/255, 0/255, 230/255)
FOREGROUND = wd.COLOR_WHITE

FONT_NAME = "AmericanTypewriter"

BREAK = 5*60 # 5 minutes break
WORK = 25*60 # Each 25 minutes
LARGE_BREAK = 15*60 # And a 15 minutes break each hour
ENDED = 0

# Functions

@mainthread
def suspend():
    UIApplication.sharedApplication.suspend()

def send_notification(type):
    notif = nc.Notification()
    if type == WORK:
        notif.message = "Start working"
    elif type != ENDED:
        notif.message = "Take a break"
    else:
        notif.message = "Ended"
    nc.send_notification(notif)
        

def show_timer(type):
    widget = wd.Widget()
    layout = widget.medium_layout
    
    if type != WORK:
        text = "Break"
    else:
        text = "Work"
    
    header = wd.Text(text)
    header.font = wd.Font(FONT_NAME+"-Bold", 25)
    header.color = FOREGROUND
    header.padding = wd.PADDING_ALL
    
    stop = wd.SystemSymbol(sf.XMARK)
    stop.color = FOREGROUND
    stop.font_size = 30
    stop.padding = wd.PADDING_ALL
    stop.link = "stop"
    
    date = dt.datetime.now() + dt.timedelta(seconds=type)
    timer = wd.DynamicDate(date)
    timer.font = wd.Font(FONT_NAME, 40)
    timer.color = FOREGROUND
    timer.style = wd.DATE_STYLE_TIMER
    
    layout.add_row([header, wd.Spacer(), stop])
    layout.add_vertical_spacer()
    layout.add_row([timer])
    layout.add_vertical_spacer()
    layout.set_background_color(BACKGROUND)
    wd.save_widget(widget, "Timer")


def show_start_widget():
    widget = wd.Widget()
    layout = widget.medium_layout
    
    header = wd.Text("Work")
    header.font = wd.Font(FONT_NAME+"-Bold", 20)
    header.color = FOREGROUND
    header.padding = wd.PADDING_ALL
    
    row = []
    for hours in ["1", "2", "4"]:
        text = wd.Text(hours+"h")
        text.font = wd.Font(FONT_NAME+"-Bold", 25)
        text.color = BACKGROUND
        text.background_color = FOREGROUND
        text.corner_radius = 30
        text.padding = wd.PADDING_ALL
        
        if hours == "1":
            text.link = "2"
        elif hours == "2":
            text.link = "4"
        elif hours == "4":
            text.link = "8"
        
        row.append(text)

    layout.add_row([header])
    layout.add_row(row)
    layout.add_vertical_spacer()
    layout.set_background_color(BACKGROUND)
    wd.save_widget(widget, "Work")

if wd.link is not None:
    
    if wd.link == "stop":
        show_start_widget()
        bg.BackgroundTask(id="Work").stop() 
        suspend()  
        raise SystemExit
    
    count = int(wd.link)
    divided = int(count/4)
    if divided <= 0:
        divided = 1
    if count > 4:
        count = 4
    
    suspend()
    
    def begin():
        with bg.BackgroundTask(id="Work") as b:
            for i in range(divided):
            
                for i in range(count):
                    show_timer(WORK)
                    send_notification(WORK)
                    b.wait(WORK)
                
                    if i < count-1:
                        show_timer(BREAK)
                        send_notification(BREAK)
                        b.wait(BREAK)
            
                if divided > 1 and i < divided-1:
                    show_timer(LARGE_BREAK)
                    send_notification(LARGE_BREAK)
                    b.wait(LARGE_BREAK)


            send_notification(ENDED)
            show_start_widget()

    Thread(target=begin).start()
            
else:
    show_start_widget()
