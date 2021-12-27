watch
=====

.. currentmodule:: watch

.. automodule:: watch

API Reference
-------------

.. toctree::
   :maxdepth: 2

   watch/api

Building Complications
----------------------

watchOS complications are kinds of tiny widgets displayed in an Apple Watch. It's possible to code these complications with Pyto, but the Apple Watch must be paired to the iPhone to update. If the iPhone isn't near the Apple Watch, the refresh will be performed later.


Let's start by importing the required libraries:

.. highlight:: python
.. code-block:: python

    import watch as wt
    import widgets as wd
    import datetime as dt

We import `widgets <widgets.html>`_ because it's the API we use to create the UI of the complication.

To provide complications, we need to subclass :class:`~watch.ComplicationsProvider`.

.. highlight:: python
.. code-block:: python

    class MinutesProvider(wt.ComplicationsProvider):

        def name(self):
            return "Minutes"

The :meth:`~watch.ComplicationsProvider.name` method returns the name of the complication that will appear in the Watch face customizer.

The :meth:`~watch.ComplicationsProvider.timeline` method returns a list of ``datetime.datetime`` objects corresponding to the time when the script has data for. You should return timestamps after the ``after_date`` parameter and no more than the given ``limit``.

In this example, we return a timestamp for each next minute.

.. highlight:: python
.. code-block:: python

        def timeline(self, after_date, limit):
            dates = []
            for i in range(limit):
                delta = dt.timedelta(minutes=i*1)
                date = after_date + delta
                date = date.replace(second=0)
                dates.append(date)

            return dates

Then we just have to implement :meth:`~watch.ComplicationsProvider.complication` to create a complication for the given timestamp.
A :class:`~watch.Complication` object must be returned. The API is the same as the `widgets <widgets.html>`_ module.

.. highlight:: python
.. code-block:: python

        def complication(self, date):

            min = date.time().minute
            text = wd.Text(str(min), font=wd.Font.bold_system_font_of_size(20))

            complication = wt.Complication()
            complication.circular.add_row([text])

            return complication

Finally, an instance of the previously created class must be passed to :func:`~watch.add_complications_provider`.

.. highlight:: python
.. code-block:: python

    wt.add_complications_provider(MinutesProvider())

The script looks like this:

.. highlight:: python
.. code-block:: python

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

Setup
******

To setup the complication, run the script that calls :func:`~watch.add_complications_provider`. Once executed, go the the main screen, then the menu icon > Settings > Apple Watch and select the script. If the Apple Watch is paired to the iPhone, a complication with the name returned by the :meth:`~watch.ComplicationsProvider.name` method will appear in the Watch Face customizer.

Note that multiple complications can be added with :func:`~watch.add_complications_provider`, it just have to be in the same script.
Also, you can put top level code that will be executed when opening the Apple Watch app.
