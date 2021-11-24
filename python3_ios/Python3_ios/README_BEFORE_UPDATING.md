# Before updating Python

Edit `config.c` to include `cryptography` modules and `posixmodule.c` to implement `get_terminal_size`.

(!) Edit `pythonrun.c` so `_Py_HandleSystemExit` always returns 0 (!)
