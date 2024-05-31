pyto_ui
=======

.. currentmodule:: pyto_ui

.. automodule:: pyto_ui

API Reference
-------------

.. toctree::
   :maxdepth: 2

   pyto_ui/classes
   pyto_ui/functions
   pyto_ui/constants

Getting Started
---------------

Each item presented on the screen is a :class:`~pyto_ui.View` object. This module contains many :class:`~pyto_ui.View` subclasses.

We can initialize a view like that:

.. highlight:: python
.. code-block:: python

    import pyto_ui as ui

    view = ui.View()

You can modify the view's attributes, like :data:`~pyto_ui.View.background_color` for example:

.. highlight:: python
.. code-block:: python

    view.background_color = ui.COLOR_SYSTEM_BACKGROUND

Then, call the :func:`~pyto_ui.show_view` function to show the view:

.. highlight:: python
.. code-block:: python

    ui.show_view(view, ui.PRESENTATION_MODE_SHEET)

A view will be presented, with the system background color, white or black depending on if the device has dark mode enabled or not.
It's important to set our view's background color because it will be transparent if it's not set. That looks great on widgets, but not in app.

NOTE: The thread will be blocked until the view is closed, but you can run code on another thread and modify the UI from there:

.. highlight:: python
.. code-block:: python

    ui.show_view(view)
    print("Closed") # This line will be called after the view is closed.

Now we have an empty view, the root view, we can add other views inside it, like a :class:`~pyto_ui.Button`:

.. highlight:: python
.. code-block:: python

    button = ui.Button(title="Hello World!")
    button.size = (100, 50)
    button.center = (view.width/2, view.height/2)
    button.flex = [
        ui.FLEXIBLE_TOP_MARGIN,
        ui.FLEXIBLE_BOTTOM_MARGIN,
        ui.FLEXIBLE_LEFT_MARGIN,
        ui.FLEXIBLE_RIGHT_MARGIN
    ]
    view.add_subview(button)

We are creating a button with title "Hello World!", with 100 as width and 50 as height. We place it at center, and we set :data:`~pyto_ui.View.flex` to have flexible margins so the button will always stay at center even if the root view will change its size.

To add an action to the button:

.. highlight:: python
.. code-block:: python

    def button_pressed(sender):
        sender.superview.close()

    button.action = button_pressed

We define a function that takes the button as parameter and we pass it to the button's :data:`~pyto_ui.Button.action` property. The :data:`~pyto_ui.View.superview` property of the button is the view that contains it. With the :meth:`~pyto_ui.View.close` function, we close it.

So we have this code:

.. highlight:: python
.. code-block:: python

    import pyto_ui as ui

    def button_pressed(sender):
        sender.superview.close()

    view = ui.View()
    view.background_color = ui.COLOR_SYSTEM_BACKGROUND

    button = ui.Button(title="Hello World!")
    button.size = (100, 50)
    button.center = (view.width/2, view.height/2)
    button.flex = [
        ui.FLEXIBLE_TOP_MARGIN,
        ui.FLEXIBLE_BOTTOM_MARGIN,
        ui.FLEXIBLE_LEFT_MARGIN,
        ui.FLEXIBLE_RIGHT_MARGIN
    ]
    button.action = button_pressed
    view.add_subview(button)

    ui.show_view(view, ui.PRESENTATION_MODE_SHEET)

    print("Hello World!")

When the button is clicked, the UI will be closed and "Hello World!" will be printed.
UIs can be presented on the Today widget if you set the widget script.


Interface Builder
-----------------

The easiest way to make user interfaces is with Pyto's interface builder. ``.pytoui`` files can be created from the file browser's templates or from the project creator as a part of a package.

Layout works with horizontal and vertical stacks, like SwiftUI. One ``.pytoui`` file is one view, which can be read with the :func:`~pyto_ui.read` function, which takes the path of the UI file and optionally, a dictionary set by default to the caller's locals. This dictionary is used to search for connections like class and function names referenced by the UI file.

.. highlight:: python
.. code-block:: python
    
    import pyto_ui as ui
    
    class MainView(ui.View):
        pass
    
    ui.show_view("view.pytoui")
    
This code is equivalent to:

.. highlight:: python
.. code-block:: python
    
    import pyto_ui as ui
    import main_view
    
    ui.read("view.pytoui", vars(main_view))
    
Or just:

.. highlight:: python
.. code-block:: python
    
    import pyto_ui as ui
    from main_view import MainView
    
    ui.read("view.pytoui")
    
Actions can reference instance methods of a view or any function on the namespace given to :func:`~pyto_ui.read`.

.. highlight:: python
.. code-block:: python

    import pyto_ui as ui

    class MainView(ui.View):

        @ui.ib_action
        def button_pressed(self, sender: ui.Button):
            pass
    
    @ui.ib_action
    def other_button_pressed(sender: ui.Button):
        pass
    
    ui.read("view.pytoui")

Subviews can be accessed by name with :class:`~pyto_ui.View`'s subscript, but also with variables:

.. highlight:: python
.. code-block:: python

    import pyto_ui as ui

    class MainView(ui.View):

        my_button: Button # Will be retrieved from getattr

    my_other_button: Button # Will be set on read
    
    ui.read("view.pytoui")

UIKit bridge
------------

(Previous knowledge of iOS development with UIKit is needed to follow this tutorial)

PytoUI can show custom UIKit views with the :class:`~pyto_ui.UIKitView` class. Presenting ``UIViewController`` is also possible with :func:`~pyto_ui.show_view_controller`.

See `Objective-C <Objective-C.html>`_ for information about using Objective-C classes in Python.

To use classes from UIKit, we can write the following code:

.. highlight:: python
.. code-block:: python

    from UIKit import *

Using UIView
************

In this example, we will create a date picker with ``UIDatePicker``. Firstly, we will import the needed modules.

.. highlight:: python
.. code-block:: python

    import pyto_ui as ui
    from UIKit import UIDatePicker
    from Foundation import NSObject
    from rubicon.objc import objc_method, SEL
    from datetime import datetime

Then we subclass :class:`~pyto_ui.UIKitView` to implement a date picker by implementing :meth:`~pyto_ui.UIKitView.make_view` to return an UIDatePicker object. ``DatePicker.did_change`` will be the function called when the selected date changes.

.. highlight:: python
.. code-block:: python

    class DatePicker(ui.UIKitView):
        
        did_change = None

        def make_view(self):
            picker = UIDatePicker.alloc().init()
            return picker

We will now create an Objective-C subclass of ``NSObject`` to receive ``UIDatePicker`` events. ``@objc_method`` is the equivalent of ``@objc`` in Swift, it exposes a method to the Objective-C runtime.

The ``didChange`` method converts the selected date from ``NSDate`` to ``datetime`` and calls the callback function (``DatePicker.did_change``) with the date as parameter.
``PickerDelegate.picker`` will be set to an instance of the previously created class.

.. highlight:: python
.. code-block:: python

    class PickerDelegate(NSObject):

        picker = None

        @objc_method
        def didChange(self):
            if self.picker.did_change is not None:
                date = self.objc_picker.date
                date = datetime.fromtimestamp(date.timeIntervalSince1970())
                self.picker.did_change(date)

In the ``DatePicker.make_view`` method, we'll set the event handler to the delegate's ``didChange`` method with ``addTarget(_:action:forControlEvents:)``.

.. highlight:: python
.. code-block:: python

    ...
        
        def make_view(self):
            picker = UIDatePicker.alloc().init()

            delegate = PickerDelegate.alloc().init()
            delegate.picker = self
            delegate.objc_picker = picker
        
            # 4096 is the value for UIControlEventValueChanged
            picker.addTarget(delegate, action=SEL("didChange"), forControlEvents=4096)

            return picker

    ...

Then the date picker is usable as any view because :class:`~pyto_ui.UIKitView` is a subclass of :class:`~pyto_ui.View`.

.. highlight:: python
.. code-block:: python

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
    
The whole script:

.. highlight:: python
.. code-block:: python

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

Using UIViewController
**********************

UIKit View controllers can be presented with :func:`~pyto_ui.show_view_controller`.

In this example, we will subclass ``UIViewController`` and use the `LinkPresentation <https://developer.apple.com/documentation/linkpresentation>`_ framework to show the preview of a link.

We need to import the required modules.

.. highlight:: python
.. code-block:: python

    from UIKit import *
    from LinkPresentation import *
    from Foundation import *
    from rubicon.objc import *
    from mainthread import mainthread
    import pyto_ui as ui

Then we can subclass ``UIViewController`` and implement ``viewDidLoad`` like any UIKit app does.
``send_super()`` from ``rubicon.objc`` is used to call methods from the superclass.
``@objc_method`` is the equivalent of ``@objc`` in Swift, it exposes a method to the Objective-C runtime.

.. highlight:: python
.. code-block:: python

    class MyViewController(UIViewController):

        @objc_method
        def close(self):
            self.dismissViewControllerAnimated(True, completion=None)

        @objc_method
        def dealloc(self):
            self.link_view.release()

        @objc_method
        def viewDidLoad(self):
            send_super(__class__, self, "viewDidLoad")

            self.title = "Link"

            self.view.backgroundColor = UIColor.systemBackgroundColor()

            # 0 is the value for a 'Done' button
            done_button = UIBarButtonItem.alloc().initWithBarButtonSystemItem(0, target=self, action=SEL("close"))
            self.navigationItem.rightBarButtonItems = [done_button]

We create an ``LPLinkView`` from the `LinkPresentation <https://developer.apple.com/documentation/linkpresentation>`_ framework and we fetch the metadata. The ``fetch_handler()`` function is a block passed to an Objective-C method, it has to be fully annotated. Mark parameters as ``ObjCInstance`` from ``rubicon.objc``.

.. highlight:: python
.. code-block:: python

    ...

        @objc_method
        def viewDidLoad(self):

            ...

            self.url = NSURL.alloc().initWithString("https://apple.com")
            self.link_view = LPLinkView.alloc().initWithURL(self.url)
            self.link_view.frame = CGRectMake(0, 0, 200, 000)
            self.view.addSubview(self.link_view)
            self.fetchMetadata()


        @objc_method
        def fetchMetadata(self):
            
            @mainthread
            def set_metadata(metadata):
                self.link_view.setMetadata(metadata)
                self.layout()

            def fetch_handler(metadata: ObjCInstance, error: ObjCInstance) -> None:
                 set_metadata(metadata)
            
            provider = LPMetadataProvider.alloc().init().autorelease()
            provider.startFetchingMetadataForURL(self.url, completionHandler=fetch_handler)

        @objc_method
        def layout(self):
            self.link_view.sizeToFit()
            self.link_view.setCenter(self.view.center)
        
        @objc_method
        def viewDidLayoutSubviews(self):
            self.layout()

When our View controller is ready, we can show it with :func:`~pyto_ui.show_view_controller`. :func:`~mainthread.mainthread` is used to call a function in the app's main thread.

.. highlight:: python
.. code-block:: python

    @mainthread
    def show():
        vc = MyViewController.alloc().init().autorelease()
        nav_vc = UINavigationController.alloc().initWithRootViewController(vc).autorelease()
        ui.show_view_controller(nav_vc)

    show()

The whole script:

.. highlight:: python
.. code-block:: python

    from UIKit import *
    from LinkPresentation import *
    from Foundation import *
    from rubicon.objc import *
    from mainthread import mainthread
    import pyto_ui as ui

    # We subclass UIViewController
    class MyViewController(UIViewController):
        
        @objc_method
        def close(self):
            self.dismissViewControllerAnimated(True, completion=None)
        
        @objc_method
        def dealloc(self):
            self.link_view.release()
        
        # Overriding viewDidLoad
        @objc_method
        def viewDidLoad(self):
            send_super(__class__, self, "viewDidLoad")

            self.title = "Link"

            self.view.backgroundColor = UIColor.systemBackgroundColor()

            # 0 is the value for a 'Done' button
            done_button = UIBarButtonItem.alloc().initWithBarButtonSystemItem(0, target=self, action=SEL("close"))
            self.navigationItem.rightBarButtonItems = [done_button]
            
            self.url = NSURL.alloc().initWithString("https://apple.com")
            self.link_view = LPLinkView.alloc().initWithURL(self.url)
            self.link_view.frame = CGRectMake(0, 0, 200, 000)
            self.view.addSubview(self.link_view)
            self.fetchMetadata()
        
        @objc_method
        def fetchMetadata(self):
            
            @mainthread
            def set_metadata(metadata):
                self.link_view.setMetadata(metadata)
                self.layout()

            def fetch_handler(metadata: ObjCInstance, error: ObjCInstance) -> None:
                 set_metadata(metadata)
            
            provider = LPMetadataProvider.alloc().init().autorelease()
            provider.startFetchingMetadataForURL(self.url, completionHandler=fetch_handler)
        
        @objc_method
        def layout(self):
            self.link_view.sizeToFit()
            self.link_view.setCenter(self.view.center)
        
        @objc_method
        def viewDidLayoutSubviews(self):
            self.layout()

    @mainthread
    def show():
        # We initialize our view controller and a navigation controller
        # This must be called from the main thread
        vc = MyViewController.alloc().init().autorelease()
        nav_vc = UINavigationController.alloc().initWithRootViewController(vc).autorelease()
        ui.show_view_controller(nav_vc)

    show()

