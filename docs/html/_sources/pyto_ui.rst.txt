pyto_ui
=======

.. currentmodule:: pyto_ui

.. automodule:: pyto_ui

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
        FLEXIBLE_TOP_MARGIN,
        FLEXIBLE_BOTTOM_MARGIN,
        FLEXIBLE_LEFT_MARGIN,
        FLEXIBLE_RIGHT_MARGIN
    ]
    button.action = button_pressed
    view.add_subview(button)

    ui.show_view(view, ui.PRESENTATION_MODE_SHEET)

    print("Hello World!")

When the button is clicked, the UI will be closed and "Hello World!" will be printed.
UIs can be presented on the Today widget if you set the widget script.

API Reference
-------------

.. toctree::
   :maxdepth: 2

   pyto_ui/classes
   pyto_ui/functions
   pyto_ui/constants
