"""
A patch to Toga's iOS backend for Pyto

It works without changing the Toga's source code, just import this module before or after importing toga. Don't delete toga or rubicon from sys.modules or the patch will be undone.
"""

import sys
import toga
from toga_iOS import app, widgets
from toga_iOS.widgets.base import Widget
from toga_iOS import window as _ios_window
from mainthread import mainthread
import rubicon.objc as objc
from rubicon.objc import objc_method, CGRectMake, CGSize, objc_property
import pyto_ui as ui
from UIKit import UIViewController, UIColor, UIView
from pyto import ConsoleViewController
from threading import Thread
from time import sleep
from pyto import MacSupport

# Add the UIKit view of a Widget to `_garbage_collector` after initializing it

_garbage_collector = []

_init = Widget.__init__

class _Widget(Widget):

    def __init__(self, interface):
        _init(self, interface)

        _garbage_collector.append(self.native)

Widget.__init__ = _Widget.__init__

# Override App.__init__ so it doesn't need a life cycle

_App = app.App

class iOSApp(app.App):

    def __init__(self, interface):
        self.interface = interface
        self.interface._impl = self
        self.__class__.app = self
        _App.app = self

app.App = iOSApp

# Override App.startup so it doesn't show the window

class App(toga.App):

    def startup(self):
        self.main_window = toga.MainWindow(title=self.formal_name, factory=self.factory)

        if self._startup_method:
            widget = self._startup_method(self)
            self.main_window.content = widget

toga.app.App.startup = App.startup

# ContainerViewController will resize the contained widget when necessary
# Override Window.set_content so it creates an instance of ContainerViewController instead of UIViewController and so it sets the view port to the vc's view instead of the window

class ContainerViewController(UIViewController):

    viewport_view = objc_property()

    @objc_method
    def viewDidLoad(self):
        self.view.backgroundColor = UIColor.systemBackgroundColor()

    @objc_method
    def viewDidLayoutSubviews(self):

        if self.viewport_view is None:
            self.viewport_view = UIView.alloc().init().autorelease()

        view = self.viewport_view

        size = self.view.frame.size
        view.frame = CGRectMake(0, 0, size.width, size.height)
        self.widget.viewport = _ios_window.iOSViewport(view)
        self.widget.interface.refresh()

class iOSWindow(_ios_window.Window):

    def set_content(self, widget):

        for child in widget.interface.children:
            child._impl.container = widget

        if getattr(widget, 'controller', None):
            self.controller = widget.controller
        else:
            self.controller = ContainerViewController.alloc().init().autorelease()
            self.controller.widget = widget

        widget.viewport = _ios_window.iOSViewport(self.controller.view)

        self.native.rootViewController = self.controller
        self.controller.view = widget.native

_ios_window.Window.set_content = iOSWindow.set_content

# Subclass App so it shows the window with PytoUI

class PytoTogaApp(toga.App):

    @mainthread
    def show(self):
        self.startup()
        window = self.main_window._impl.native

        vc = window.rootViewController

        window.rootViewController = None
        vc.sheetPresentationController().prefersGrabberVisible = True

        self.vc = vc

        ui.show_view_controller(vc)

        return vc

    @mainthread
    def clear_subviews(self, item):
        try:
            for subview in list(item.subviews()):
                subview.removeFromSuperview()
        except AttributeError:
            pass

    def main_loop(self):
        global _garbage_collector

        try:
            del sys.modules["toga_Pyto"]
        except KeyError:
            pass

        vc = self.show()
        sleep(0.1)
        ConsoleViewController.waitForViewController(vc)

        if True: # TODO: Make the garbage collector not crash the app
            _garbage_collector = []
            return

        for item in _garbage_collector:
            
            try:
                del item.interface
            except AttributeError:
                pass
                
            self.clear_subviews(item)
            
            for _ in range(item.retainCount()):
                item.release()
        
        _garbage_collector = []
        
toga.App = PytoTogaApp
