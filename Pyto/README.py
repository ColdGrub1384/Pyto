# Welcome to Pyto!

# Pyto is a Python 3.7 IDE.

# You can start by creating a script by tapping the "+" button on the main screen. You can then type your code and run it by tapping the Play button.

# You can also code inside the REPL (Main Screen > Tab bar > REPL)

# You can include all scripts in your current directory or in the "modules" directory.

# You can use all default libraries, like `sys` for example:

from sys import version
print(version)

# You can print and request for input:

name = input("What's your name? ")
print("Hello "+name+"!")

# And even run some commands with `os.system`

from os import system
print("Your scripts:")
system("ls ~/Documents")
