Terminal
========

The terminal embedded in Pyto is `hterm <https://hterm.org>`_, the terminal from Chrome OS.
It runs a shell that provides access to many UNIX commands from `ios_system <https://github.com/holzschu/ios_system>`_, which is used in many iOS / iPadOS apps.

These commands are embedded in the app and are executed in the same process and can be executed with :py:func:`os.system` and :py:class:`subprocess.Popen`.

Commands
--------

Type ``help`` in the shell to see a list of available commands.

Scripts installed from PyPI or packages embedded in-app will also be recognized by the shell. These scripts are installed in ``~/Documents/bin`` for user installed scripts and ``Pyto.app/site-packages/bin`` for bundled packages. If you want to run a module that has no entrypoint specified in setup.py or setup.cfg, you can always run the python interpreter: ``$ python -m my_module``.

Use ``xargs`` to pass the output of a command as an argument:

.. code-block::

    $ echo / | xargs ls
    Applications    etc
    Developer       private
    Library         sbin
    System          tmp
    bin             usr
    cores           var
    dev

Operators
---------

The shell supports operator for redirecting output and input.


Write to file:

.. code-block::

    $ find . -name "*.py" > scripts.txt


Append to file:

.. code-block::

    $ date >> history.txt


Pass file as input:

.. code-block::

    $ python < my_script.py
    Hello World!


Pass output from a command to another command as input.

.. code-block::

    $ echo 'print("Hello World!")' | python
    Hello World!

