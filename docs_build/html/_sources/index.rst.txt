.. Pyto documentation master file, created by
   sphinx-quickstart on Sun Jul 21 17:54:15 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

.. image:: Icon.png
   :width: 100px

|

Welcome to Pyto's documentation!
================================

Pyto is an open source app to code and run Python code locally on an iPad or iPhone.
The app uses the Python C API to run Python code in the same process of the app, due to iOS restrictions. Third party pure Python modules can be installed from PyPi and some modules are bundled in the app, like ``Numpy``, ``Matplotlib``, ``Pandas``, ``SciPy``, ``SciKit-Learn``, ``SciKit-Image``, ``OpenCV``, ``Pillow`` and ``Biopython``.

.. toctree::
   :maxdepth: 2

   automation
   opencv
   django
   third_party

#################
  API Reference
#################

The following modules are integrated with Pyto.

.. toctree::
   :maxdepth: 2
   :caption: User Interface

   pyto_ui
   notification_center
   sound
   sharing
   mainthread
   UIKit

.. toctree::
   :maxdepth: 2
   :caption: OS Technologies

   notifications
   music
   photos
   location
   motion
   multipeer

.. toctree::
   :maxdepth: 2
   :caption: Sharing data

   xcallback
   userkeys
   pasteboard
