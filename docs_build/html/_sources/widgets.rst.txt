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

<<<<<<< HEAD
**In App**: A script executed manually in foreground that will provide an UI for a widget. The scripts can do everything a script running in foreground can. This is very powerful with Shortcuts automations or with :func:`~background.request_background_fetch`.

Since Pyto 14.0, 'Run Script' widgets can be executed in app by calling the "Start Handling Widgets In App" Shortcut. After running the shortcut, the app will run in background and will be notified when a widget is about to be reloaded so it runs without RAM limit and it can import libraries with C extensions like Numpy. That's basically handling widgets in app but without having to care about reloading the widget in a while loop, the app will take care and run the scripts when required. You should run the "Start Handling Widgets In App" shortcut from Shortcuts automation, for example once a day to make sure the app is running in background, having it in the app switcher isn't enough.
=======
**Set Content in App**: A script executed manually in foreground that will provide an UI for a widget. The scripts can do everything a script running in foreground can. This is very powerful with Shortcuts automations or with :func:`~background.request_background_fetch`.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

Getting Started
---------------

<<<<<<< HEAD
As an example, we will code a widget that shows the current date and week day.
=======
As an example, we will code a widget that shows the latest posts from `Daring Fireball <https://daringfireball.net/>`_.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

Firstly, we will import the required libraries:

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
    import widgets as wd
    from datetime import datetime, timedelta

We will start by defining the text foreground color and the background color for the widget's UI.
=======
    import widgets as wd # For the UI
    import json # For parsing the feed
    from urllib.request import urlopen # For requesting the feed
    from dateutil.parser import parse # For parsing dates
    from webbrowser import open # For opening posts

We will start by defining some values. The text foreground color and the background color used on the widget's UI. ``FEED_URL`` stores an URL that gives all the posts from the blog in a JSON format.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python
    
<<<<<<< HEAD
    BACKGROUND = wd.Color.rgb(255/255, 250/255, 227/255)
    FOREGROUND = wd.Color.rgb(75/255, 72/255, 55/255)

Then we'll declare a function that returns the weekday of a 'datetime' object as a string.
=======
    FOREGROUND_COLOR = wd.COLOR_WHITE
    BACKGROUND_COLOR = wd.Color.rgb(74/255, 82/255, 90/255)
    FEED_URL = "https://daringfireball.net/feeds/json"

Then we'll declare a class to store posts information. Each post has an URL, a title, a publication date and the content itself.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
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
=======
    class Article:
    
        def __init__(self, url, title, content, date):
            self.url = url
            self.title = title
            self.content = content
            self.date = date

After that, we'll declare a function that returns a all of the articles in the feed as a list. Each ``Article`` object is created from the information parsed as JSON.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
    class DateProvider(wd.TimelineProvider):

Two methods must be implemented: :meth:`~widgets.TimelineProvider.timeline` and :meth:`~widgets.TimelineProvider.widget`.

Let's start by :meth:`~widgets.TimelineProvider.timeline`. This method returns a list of dates for which the script has data.
As we are creating a calendar widget, we need to update it everyday at midnight. We will cache the next 30 days.
=======
    def get_posts():
        request = urlopen(FEED_URL)
        data = request.read().decode()
        feed = json.loads(data)
        items = feed["items"]
        
        articles = []
        
        for item in items:
            url = item["url"]
            title = item["title"]
            content = item["content_html"]
            date = parse(item["date_published"])
            article = Article(url, title, content, date)
            articles.append(article)
        
        return articles

Now we will code the UI. Each widget has 3 layouts: small, medium and large. So we need to provide a different layout for each size.
A layout is composed of rows, each row containing horizontally aligned UI elements.
The small layout is a small square, the medium layout is a rectangle and the large one is a big square.

We need to create a :class:`~widgets.Widget` object and store the blog's feed returned by ``get_posts()``. A :class:`~widgets.Widget` instance has 3 properties that can be used to modify the layout of each widget size. :data:`~widgets.Widget.small_layout`, :data:`~widgets.Widget.medium_layout`, :data:`~widgets.Widget.large_layout`
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
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
=======
    posts = get_posts()
    widget = wd.Widget()

While the medium sized widget will contain the title and the content of a post, the large layout will contain 3 posts. So we create a function that can add the UI to a layout, then we would just need to call this function once for the medium layout and 3 times for the large layout.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
        def widget(self, date):
            widget = wd.Widget()
            layout = widget.medium_layout

Firstly, we will create a :class:`~widgets.Text` showing the week day corresponding to the given date.
=======
    def add_post(post, layout, link=False):
        
        # If 'line' is 'True', the UI elements will be tappable
        
        if link:
            url = post.url
        else:
            url = None
                
        # Add the title of the post
        layout.add_row([
            wd.Text(
                post.title,
                color=FOREGROUND_COLOR,
                link=url,
                font=wd.Font.bold_system_font_of_size(17),
                padding=wd.Padding(5, 0, 10, 10)
            ),
        ])
        layout.add_vertical_spacer()
        
        # Add the content of the post
        # post.content can contain HTML code
        # HTML code is automatically converted into plain text (no markup)
        layout.add_row([
            wd.Text(post.content,
                color=FOREGROUND_COLOR,
                link=url
            ),
        ])
        layout.add_vertical_spacer()
        
        # Add the publication date
        layout.add_row([
            wd.Spacer(),
            wd.DynamicDate(
                post.date,
                color=FOREGROUND_COLOR,
                padding=wd.Padding(0, 10, 10, 10)
            )
        ], link=url)
        
        # Set the background color of the widget
        layout.set_background_color(BACKGROUND_COLOR)

The small widget just contains the title and the publication date of the last post. The first element of the ``posts`` list is the last post.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
            day = wd.Text(
                text=weekday(date),
                font=wd.Font("AmericanTypewriter-Bold", 50),
                color=FOREGROUND)

To show the current formatted date, we can use :class:`~widgets.DynamicDate`:
=======
    # # # # #
    # Small #
    # # # # #

    # Add the post's title
    widget.small_layout.add_row([
        wd.Text(
            posts[0].title,
            color=FOREGROUND_COLOR,
            font=wd.Font.bold_system_font_of_size(17),
            padding=wd.Padding(10, 0, 10, 10)
        )
    ])
    
    # Add the publication date at the bottom
    widget.small_layout.add_vertical_spacer()
    widget.small_layout.add_row([
        wd.Spacer(),
        wd.DynamicDate(
            posts[0].date,
            color=FOREGROUND_COLOR,
            padding=wd.Padding(0, 5, 0, 0)
        )
    ])
    
    # If the widget is pressed, the post's URL will be passed to the script
    widget.small_layout.set_link(posts[0].url)
    
    # Set the background color of the widget
    widget.small_layout.set_background_color(BACKGROUND_COLOR)

For the medium widget, we just call the previously created ``add_post`` function.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
            date_text = wd.DynamicDate(
                date=date,
                font=wd.Font("AmericanTypewriter", 18),
                color=FOREGROUND,
                padding=wd.PADDING_ALL)

Then we place the the week day at center and the date at the bottom. :meth:`~widgets.WidgetLayout.add_vertical_layout` adds an invisible space that takes as much as vertical space as it can. The :meth:`~widgets.WidgetLayout.set_link` method sets a parameter that will be passed to the script when the widget is pressed, the :data:`~widgets.WidgetComponent.link` property can be set for individual UI elements.

See `UI Elements <widgets/ui.html#ui-elements>`_ for a list of UI elements and their documentation.
=======
    # # # # # #
    # Medium  #
    # # # # # #
    
    add_post(posts[0], widget.medium_layout)
    
    # If the widget is pressed, the post's URL will be passed to the script
    widget.medium_layout.set_link(posts[0].url)

The large widget will contain 3 posts, so we call ``add_post`` 3 times. This time, we set the third parameter (``link``) to ``True``. Because the large widget contains multiple posts, the ``link`` attribute isn't set to the whole layout but to individual UI elements.

Between each post, we add a tinny line with :meth:`~widgets.WidgetLayout.add_vertical_divider`.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
            layout.add_vertical_spacer()
            layout.add_row([day])
            layout.add_row([date_text])
            layout.set_background_color(BACKGROUND)
            layout.set_link(date.ctime())
        
            return widget

Call the :func:`~widgets.provide_timeline` function to show the widget:
=======
    # # # # #
    # Large #
    # # # # #
    
    for i in range(3):
        # Setting the third parameter to 'True' will make individual elements tappable
        add_post(posts[i], widget.large_layout, True)
        if i < 2:
            widget.large_layout.add_vertical_divider()

Then we can just show the widget with :func:`~widgets.show_widget`. You can run the code in app and see a preview. A reload is scheduled with :func:`~widgets.schedule_next_reload`.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
    wd.provide_timeline(DateProvider())

And we can check for the :data:`~widgets.link` variable to use the passed parameter.
=======
    # # # # #
    # Show  #
    # # # # #
    
    # Don't reload before five hours
    wd.schedule_next_reload(60*60*5)
    wd.show_widget(widget)

Now the UI is correctly displayed, but now we need to handle taps to open an article.
:data:`~widgets.link` is set when an UI element with a ``link`` attribute is passed. So we need to check if this variable is set before showing the UI. If it's not, that means the widget is running normally and we need to show an UI, otherwise we open the passed link with the default web browser.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
    if wd.link is not None:
        print(wd.link)
    else:
        wd.provide_timeline(DateProvider())

=======
    if wd.link is None:
        
        # If the device was recently restarted,
        # it will wait until it's connected to the internet
        wd.wait_for_internet_connection()
        
        posts = get_posts()
        widget = wd.Widget()
        
        ...
        
        wd.show_widget(widget)

    else:
        # Open the article with the default web browser
    
        open(wd.link)
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

The script looks like that:

.. highlight:: python
.. code-block:: python

<<<<<<< HEAD
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
=======
    """
    A widget that shows the latest posts from Daring Fireball (https://daringfireball.net).
    """

    import widgets as wd # For the UI
    import json # For parsing the feed
    from urllib.request import urlopen # For requesting the feed
    from dateutil.parser import parse # For parsing dates
    from webbrowser import open # For opening posts
    from time import sleep

    FOREGROUND_COLOR = wd.COLOR_WHITE
    BACKGROUND_COLOR = wd.Color.rgb(74/255, 82/255, 90/255)
    FEED_URL = "https://daringfireball.net/feeds/json"

    class Article:
        
        def __init__(self, url, title, content, date):
            self.url = url
            self.title = title
            self.content = content.replace("\n", "")
            self.date = date

    def get_posts():
        request = urlopen(FEED_URL)
        data = request.read().decode()
        feed = json.loads(data)
        items = feed["items"]
        
        articles = []
        
        for item in items:
            url = item["url"]
            title = item["title"]
            content = item["content_html"]
            date = parse(item["date_published"])
            article = Article(url, title, content, date)
            articles.append(article)
        
        return articles

    def add_post(post, layout, link=False):
            
        # If 'line' is 'True', the UI elements will be tappable
        
        if link:
            url = post.url
        else:
            url = None
                
        # Add the title of the post
        layout.add_row([
            wd.Text(
                post.title,
                color=FOREGROUND_COLOR,
                font=wd.Font.bold_system_font_of_size(17),
                padding=wd.Padding(5, 0, 10, 10)
            )
        ], link=url)
        layout.add_vertical_spacer()
        
        # Add the content of the post
        # post.content can contain HTML code
        # HTML code is automatically converted into plain text (no markup)
        layout.add_row([
            wd.Text(post.content,
                color=FOREGROUND_COLOR,
                link=url,
                padding=wd.PADDING_HORIZONTAL
            ),
        ])
        layout.add_vertical_spacer()
        
        # Add the publication date
        layout.add_row([
            wd.Spacer(),
            wd.DynamicDate(
                post.date,
                color=FOREGROUND_COLOR,
                padding=wd.Padding(0, 10, 10, 10)
            )
        ], link=url)
        
        # Set the background color of the widget
        layout.set_background_color(BACKGROUND_COLOR)

    if wd.link is None:

        wd.wait_for_internet_connection()

        posts = get_posts()
        widget = wd.Widget()

        # # # # #
        # Small #
        # # # # #
        
        # Add the post's title
        widget.small_layout.add_row([
            wd.Text(
                posts[0].title,
                color=FOREGROUND_COLOR,
                font=wd.Font.bold_system_font_of_size(17),
                padding=wd.Padding(10, 0, 10, 10)
            )
        ])
        
        # Add the publication date at the bottom
        widget.small_layout.add_vertical_spacer()
        widget.small_layout.add_row([
            wd.DynamicDate(
                posts[0].date,
                color=FOREGROUND_COLOR,
                padding=wd.Padding(0, 5, 0, 0)
            )
        ])
        
        # If the widget is pressed, the post's URL will be passed to the script
        widget.small_layout.set_link(posts[0].url)
        
        # Set the background color of the widget
        widget.small_layout.set_background_color(BACKGROUND_COLOR)
        
        # # # # # #
        # Medium  #
        # # # # # #
            
        add_post(posts[0], widget.medium_layout)
        
        # If the widget is pressed, the post's URL will be passed to the script
        widget.medium_layout.set_link(posts[0].url)
        
        # # # # #
        # Large #
        # # # # #
        
        for i in range(3):
            # Setting the third parameter to 'True' will make individual elements tappable
            add_post(posts[i], widget.large_layout, True)
            if i < 2:
                widget.large_layout.add_vertical_divider()
        
        # # # # #
        # Show  #
        # # # # #
        
        # Don't reload before five hours
        wd.schedule_next_reload(60*60*5)
        wd.show_widget(widget)

    else:
        # Open the article with the default web browser
        
        open(wd.link)
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
