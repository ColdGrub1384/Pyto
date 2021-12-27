widgets
=======

.. currentmodule:: widgets

.. automodule:: widgets

API Reference
-------------

.. toctree::
   :maxdepth: 2

   widgets/ui
   widgets/constants
   widgets/functions

Types of widgets
----------------

There are two types of widgets:

**Run Script**: A script running in background to update the widget content automatically. The scripts runs with a very limited amount of RAM and cannot import most of the bundled libraries. Scripts can access resources or import other modules and packages installed with PyPI are also available but libraries with C extensions like Numpy (except PIL) cannot be imported.

**In App**: A script executed manually in foreground that will provide an UI for a widget. The scripts can do everything a script running in foreground can. This is very powerful with Shortcuts automations or with :func:`~background.request_background_fetch`.

Since Pyto 14.0, 'Run Script' widgets can be executed in app by calling the "Start Handling Widgets In App" Shortcut. After running the shortcut, the app will run in background and will be notified when a widget is about to be reloaded so it runs without RAM limit and it can import libraries with C extensions like Numpy. That's basically handling widgets in app but without having to care about reloading the widget in a while loop, the app will take care and run the scripts when required. You should run the "Start Handling Widgets In App" shortcut from Shortcuts automation, for example once a day to make sure the app is running in background, having it in the app switcher isn't enough.

Getting Started
---------------

As an example, we will code a widget that shows the current date and week day.

Firstly, we will import the required libraries:

.. highlight:: python
.. code-block:: python

    import widgets as wd
    from datetime import datetime, timedelta

We will start by defining the text foreground color and the background color for the widget's UI.

.. highlight:: python
.. code-block:: python
    
    BACKGROUND = wd.Color.rgb(255/255, 250/255, 227/255)
    FOREGROUND = wd.Color.rgb(75/255, 72/255, 55/255)

Then we'll declare a function that returns the weekday of a 'datetime' object as a string.

.. highlight:: python
.. code-block:: python

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

To provide the widgets, we need to declare a subclass of :class:`~widgets.TimelineProvider`.

.. highlight:: python
.. code-block:: python

    class DateProvider(wd.TimelineProvider):

Two methods must be implemented: :meth:`~widgets.TimelineProvider.timeline` and :meth:`~widgets.TimelineProvider.widget`.

Let's start by :meth:`~widgets.TimelineProvider.timeline`. This method returns a list of dates for which the script has data.
As we are creating a calendar widget, we need to update it everyday at midnight. We will cache the next 30 days.

.. highlight:: python
.. code-block:: python

        def timeline(self):
            today = datetime.today()
            today = datetime.combine(today, datetime.min.time())
            
            dates = []
            for i in range(30):
                date = today + timedelta(days=i)
                dates.append(date)
            
            return dates

The method above returns the next 30 days dates at midnight. Then we need to provide a widget for each date.

We will code the UI. Each widget has 3 layouts: small, medium and large. So we need to provide a different layout for each size.
A layout is composed of rows, each row containing horizontally aligned UI elements.
The small layout is a small square, the medium layout is a rectangle and the large one is a big square.

 A :class:`~widgets.Widget` instance has 3 properties that can be used to modify the layout of each widget size. :data:`~widgets.Widget.small_layout`, :data:`~widgets.Widget.medium_layout`, :data:`~widgets.Widget.large_layout`

The :class:`~widgets.Widget` object must be returned from the :meth:`~widgets.TimelineProvider.widget`. The ``date`` parameter is a ``datetime`` object corresponding to the date when the widget will be displayed. For this example, we will use the medium layout only.

.. highlight:: python
.. code-block:: python

        def widget(self, date):
            widget = wd.Widget()
            layout = widget.medium_layout

Firstly, we will create a :class:`~widgets.Text` showing the week day corresponding to the given date.

.. highlight:: python
.. code-block:: python

            day = wd.Text(
                text=weekday(date),
                font=wd.Font("AmericanTypewriter-Bold", 50),
                color=FOREGROUND)

To show the current formatted date, we can use :class:`~widgets.DynamicDate`:

.. highlight:: python
.. code-block:: python

            date_text = wd.DynamicDate(
                date=date,
                font=wd.Font("AmericanTypewriter", 18),
                color=FOREGROUND,
                padding=wd.PADDING_ALL)

Then we place the the week day at center and the date at the bottom. :meth:`~widgets.WidgetLayout.add_vertical_layout` adds an invisible space that takes as much as vertical space as it can. The :meth:`~widgets.WidgetLayout.set_link` method sets a parameter that will be passed to the script when the widget is pressed, the :data:`~widgets.WidgetComponent.link` property can be set for individual UI elements.

See `UI Elements <widgets/ui.html#ui-elements>`_ for a list of UI elements and their documentation.

.. highlight:: python
.. code-block:: python

            layout.add_vertical_spacer()
            layout.add_row([day])
            layout.add_row([date_text])
            layout.set_background_color(BACKGROUND)
            layout.set_link(date.ctime())
        
            return widget

Call the :func:`~widgets.provide_timeline` function to show the widget:

.. highlight:: python
.. code-block:: python

    wd.provide_timeline(DateProvider())

And we can check for the :data:`~widgets.link` variable to use the passed parameter.

.. highlight:: python
.. code-block:: python

    if wd.link is not None:
        print(wd.link)
    else:
        wd.provide_timeline(DateProvider())


The script looks like that:

.. highlight:: python
.. code-block:: python

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

After running the script, it will be selectable in the "Run Script" widget.

If your widget doesn't have any data for the future, instead of providing a timeline you can provide a single widget and request a refresh after a certain delay. See :func:`~widgets.show_widget` and :func:`~widgets.schedule_next_reload`.

.. highlight:: python
.. code-block:: python

    import widgets as wd
    from datetime import timedelta

    widget = wd.Widget()
    
    ...
    
    wd.schedule_next_reload(timedelta(hours=1))
    wd.show_widget(widget)
