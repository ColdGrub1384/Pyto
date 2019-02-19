#  Welcome to Pyto

Thank you for downloading Pyto. You can now write and run Python scripts.

# Getting Started

* Tap `⊞` to return to the file browser.

* To create a new script, tap  `+` at top right of the file browser.

* To run a script open it and tap `►`. The output will be shown and the keyboard will appear when input will be required.

* To pass arguments, tap the `args` button

* To change the app's theme, press the `Info` button at top left of the file browser, then tap `Theme` and choose the theme you want.

# New on 10.0

* Debug scripts with `pdb` and set breakpoints

* Added Pandas

* Updated Numpy to 1.16.1

* Added a setting for tabs

# Debugging

Pyto uses `pdb` for debugging. To debug a script, open it and press the bug button next to  `►`.

To set a breakpoint, select a line, long press to show the context menu and press `Breakpoint`. To remove it, press `Breakpoint` again. 

To apply breakpoints, debug the script with the bug button.

If you never used `pdb`, you can learn how to use it [here](https://docs.python.org/3/library/pdb.html). 

# Installing third party modules

Pyto has a minimal version of pip. 

For installing a module, tap `pip` button on the file browser. Arguments will be asked. If you want to install a module, write `install <module_name>` and if you want to uninstall a module, then write `uninstall <module_name>`.

Pyto cannot compile modules and cannot link shared libraries from outside the app bundle. So `pip` will fail for packages like `pandas`, `scipy` or `numpy`.

`numpy`,  `matplotlib`  and `pandas` are included in the app.
