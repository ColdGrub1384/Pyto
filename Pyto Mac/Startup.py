# MARK: - Platform checking

__builtins__.iOS = "iOS"
__builtins__.macOS = "macOS"
__builtins__.__platform__ = __builtins__.macOS

from importlib.machinery import SourceFileLoader

# MARK: - Run script

SourceFileLoader("main", "%@").load_module()
