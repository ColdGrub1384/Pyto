import pyto_ui as ui
import threading
import math
import warnings
import sys
from pyto import PyTurtle
from rubicon.objc import CGPoint
from numbers import Number
from matplotlib import colors
from collections import namedtuple
from UIKit import UIColor
from time import sleep
from types import ModuleType

warnings.warn("Importing an incomplete version of turtle. Some (many) features may not work.")

class Turtle(object):

    __Vec2D__ = namedtuple('Vec2D','x y')

    def Vec2D(self, x, y):
        return self.__Vec2D__(x, y)

    __shown__ = False
    __showing__ = False

    _all = []

    def layout(self, view):
        self.__drawing__.center = view.center

    def __init__(self):
        self.Turtle = self.__class__
        self.__name__ = "turtle"

        self.__speed__ = 6
        self.__turtle__ = PyTurtle.alloc().init()
        view = ui.View()
        view.__py_view__ = self.__turtle__.view
        view.size = 300, 300
        self.__drawing__ = view
        
        _view = ui.View()
        _view.title = view.title
        _view.background_color = ui.COLOR_SYSTEM_FILL
        _view.add_subview(view)
        view.center = _view.center
        _view.layout = self.layout
        self.__view__ = _view
        self.__turtle__._position = CGPoint(x=150, y=150)

    def __show__(self, force=False):

        if self.__class__.__shown__ and not force:
            return

        self.__class__.__shown__ = True
        self.__class__.__showing__ = True

        def _show():
            ui.show_view(self.__view__, ui.PRESENTATION_MODE_SHEET)
            self.__class__.__showing__ = False

        thread = threading.current_thread().__class__(target=_show)
        try:
            thread.script_path = threading.current_thread().script_path
        except AttributeError:
            pass

        thread.start()
        sleep(1)
    
    def showturtle(self):
        self.__show__(True)

    def hideturtle(self):
        self.__view__.close()

    def isvisible(self):
        return self.__class__.__showing__

    def forward(self, d):
        self.__show__()

        if self.__speed__ == 0:
            self.__turtle__.forward(d)
            return

        i = 0
        all = 0
        while i < abs(d):
            _d = self.__speed__
            if all+_d >= abs(d):
                self.__turtle__.forward(d-all)
                break
                
            if d < 0:
                self.__turtle__.forward(-_d)
            else:
                self.__turtle__.forward(_d)
            i += _d
            all += _d
    
    def back(self, d):
        self.forward(-d)
    
    def right(self, d):
        self.__show__()
        self.__turtle__.right(d)
    
    def left(self, d):
        self.__show__()
        self.__turtle__.left(d)

    def goto(self, x, y=None):
        self.__show__()
        if isinstance(x, self.__Vec2D__):
            self.__turtle__.goto(CGPoint(x=x[0], y=x[1]))
        else:
            _y = y
            if _y is None:
                _y = self.ycor()
            self.__turtle__.goto(CGPoint(x=x, y=(-_y)))
    
    def setheading(self, h):
        self.__turtle__.rotation = h
    
    def heading(self):
        return self.__turtle__.rotation
    
    def pos(self):
        pos = self.__turtle__.position()
        return (pos.x, -pos.y)

    def xcor(self):
        return self.pos()[0]

    def ycor(self):
        return self.pos()[1]
    
    def setx(self, x):
        self.goto(x)

    def sety(self, y):
        self.goto(y)

    def penup(self):
        self.__turtle__.penOn = False
    
    def pendown(self):
        self.__turtle__.penOn = True

    def home(self):
        self.goto(0, 0)
        self.setheading(0)
    
    def isdown(self):
        return self.__turtle__.penOn

    def distance(self, x, y=None):

        if y is not None:
            pos = self.Vec2D(x, y)
        if isinstance(x, self.__Vec2D__):
            pos = x
        elif isinstance(x, tuple):
            pos = self.Vec2D(*x)
        elif isinstance(x, self.__class__):
            pos = x.position()
        
        x = self.position()[0]
        y = self.position()[1]
        dest_x = pos[0]
        dest_y = pos[1]

        dist_x = abs(x-dest_x)
        dist_y = abs(y-dest_y)

        return math.sqrt((dist_x*dist_x)+(dist_y*dist_y))
    
    def towards(self, x, y=None):

        if y is not None:
            pos = self.Vec2D(x, y)
        if isinstance(x, self.__Vec2D__):
            pos = x
        elif isinstance(x, tuple):
            pos = self.Vec2D(*x)
        elif isinstance(x, self.__class__):
            pos = x.position()
        
        x = self.position()[0]
        y = self.position()[1]
        dest_x = pos[0]
        dest_y = pos[1]

        dist_x = dest_x-x
        dist_y = dest_y-y

        result = round(math.atan2(dist_x, dist_y)*180.0/math.pi, 10) % 360.0
        result /= 1
        return (0 + 1*result) % 360

    def pencolor(self, *args):
        if len(args) == 0:
            color = self.__turtle__.colorValues
            return (color[0]*255, color[1]*255, color[2]*255)
        if (len(args) == 1 and isinstance(args[0], str)):
            color = colors.to_rgba(args[0])
            self.__turtle__.colorWithRed(color[0]*255, green=color[1]*255, blue=color[2]*255)
        elif (len(args) == 1 and isinstance(args[0], tuple)):
            self.__turtle__.colorWithRed(args[0][0]*255, green=args[0][1]*255, blue=args[0][2]*255)
        elif (len(args) == 3 and isinstance(args[0], Number) 
            and isinstance(args[1], Number)
            and isinstance(args[2], Number)
        ):
            self.__turtle__.colorWithRed(args[0]*255, green=args[1]*255, blue=args[2]*255)
    
    def fillcolor(self, *args):
        if len(args) == 0:
            color = self.__turtle__.colorValues
            return (color[0]*255, color[1]*255, color[2]*255)
        if (len(args) == 1 and isinstance(args[0], str)):
            color = colors.to_rgba(args[0])
            self.__turtle__.fillColorWithRed(color[0]*255, green=color[1]*255, blue=color[2]*255)
        elif (len(args) == 1 and isinstance(args[0], tuple)):
            self.__turtle__.fillColorWithRed(args[0][0]*255, green=args[0][1]*255, blue=args[0][2]*255)
        elif (len(args) == 3 and isinstance(args[0], Number) 
            and isinstance(args[1], Number)
            and isinstance(args[2], Number)
        ):
            self.__turtle__.fillColorWithRed(args[0]*255, green=args[1]*255, blue=args[2]*255)
        
    def color(self, *args):
        if len(args) == 0:
            return (self.pencolor(), self.fillcolor())
        elif len(args) == 1:
            self.pencolor(args[0])
        elif len(args) == 2:
            self.pencolor(args[0])
            self.fillcolor(args[1])

    def begin_fill(self):
        self.__turtle__.fillColor = self.__turtle__._fillColor
    
    def end_fill(self):
        self.__turtle__.fillColor = UIColor.clearColor
    
    def filling(self):
        return self.__turtle__.isFilling

    def pensize(self, width=None):
        if width is not None:
            self.__turtle__.setPenSize(width)
        else:
            return self.__turtle__.path.lineWidth

    def clear(self):
        self.__turtle__.clear()
    
    def reset(self):
        self.speed(6)
        self.__turtle__.reset()

    def pen(self, pen=None, **pendict):
        _pd =  {"shown"         : True,
                "pendown"       : self.__turtle__.penOn,
                "pencolor"      : self.pencolor(),
                "fillcolor"     : self.fillcolor(),
                "pensize"       : self.pensize(),
                "speed"         : self.__speed__,
                "resizemode"    : "noresize",
                "stretchfactor" : (1, 1),
                "tilt"          : self.__turtle__.tilt
               }

        if not (pen or pendict):
            return _pd

        if isinstance(pen, dict):
            p = pen
        else:
            p = {}
        p.update(pendict)

        _p_buf = {}
        for key in p:
            _p_buf[key] = _pd[key]

        if "pendown" in p:
            self.__turtle__.penOn = p["pendown"]
        if "pencolor" in p:
            self.pencolor(p["pencolor"])
        if "pensize" in p:
            self.pensize(p["pensize"])
        if "fillcolor" in p:
            self.fillcolor(p["fillcolor"])
        if "speed" in p:
            self.__speed__ = p["speed"]
            self.__turtle__.speed = p["speed"]
        if "resizemode" in p:
            pass
        if "stretchfactor" in p:
            pass
        if "outline" in p:
            pass
        if "shown" in p:
            pass
        if "tilt" in p:
            self.tiltangle(p["tilt"])

    def tiltangle(self, angle=None):
        if angle is None:
            return self.__turtle__.tilt
        else:
            self.__turtle__.setTiltAngle(angle)
    
    def tilt(self, angle):
        self.tiltangle(self.tiltangle()+angle)

    def dot(self, size=None, *color):
        s = size
        if size is None:
            s = self.pensize()
        
        penOn = self.__turtle__.penOn
        self.__turtle__.penOn = True
        
        fillcolor = self.fillcolor()
        pencolor = self.pencolor()
        if len(color) != 0:
            self.pencolor(*color)
        self.fillcolor(self.pencolor())
        self.begin_fill()
        self.circle(s)
        self.end_fill()
        self.fillcolor(fillcolor)
        self.pencolor(pencolor)

        self.__turtle__.penOn = penOn

    def speed(self, s=None):
        speeds = {'fastest':0, 'fast':10, 'normal':6, 'slow':3, 'slowest':1 }
        if s is None:
            return self.__speed__
        if s in speeds:
            speed = speeds[speed]
        elif 0.5 < s < 10.5:
            speed = int(round(s))
        else:
            speed = 0
        self.pen(speed=speed)

    def circle(self, radius, extent=None, steps=None):
        self.__show__()

        speed = self.speed()
        if extent is None:
            extent = 360
        if steps is None:
            frac = abs(extent)/360
            steps = 1+int(min(11+abs(radius)/6.0, 59.0)*frac)
        w = 1.0 * extent / steps
        w2 = 0.5 * w
        l = 2.0 * radius * math.sin(w2*math.pi/180.0*1)
        if radius < 0:
            l, w, w2 = -l, -w, -w2
    
        dl = 0
        self.left(w2)
        for i in range(steps):
            self.speed(speed)
            self.forward(l)
            self.speed(0)
            self.left(w)
        self.left(-w2)
        self.speed(speed)
   
    fd = forward
    bk = back
    backward = back
    rt = right
    lt = left
    position = pos
    setpos = goto
    setposition = goto
    seth = setheading
    pd = pendown
    pu = penup
    up = pu
    down = pd
    width = pensize

    def mainloop(self):
        if not self.__class__.__showing__:
            return
        else:
            while self.__class__.__showing__:
                sleep(0.2)

    done = mainloop

class ModuleTurtle(Turtle):

    def __getattribute__(self, key):
        if key == "__all__":
            return self._all
        else:
            return super().__getattribute__(key)

turtle = ModuleTurtle()
_all = []
for key in dir(turtle):
    if not key.startswith("_"):
        _all.append(key)
turtle._all = _all

sys.modules[__name__] = turtle
