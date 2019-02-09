# MARK: - Platform checking

__builtins__.iOS = "iOS"
__builtins__.macOS = "macOS"
__builtins__.__platform__ = __builtins__.macOS

__builtins__.widget = "widget"
__builtins__.app = "app"
__builtins__.__host__ = app

# MARK: - Run script

from console import run_script

run_script("%@")


