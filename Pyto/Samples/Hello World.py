import Pyto
__builtins__.input = Pyto.input
__builtins__.print = Pyto.print

from time import sleep

# Code here

name = input("What's your name?")
print("Hello "+name+"!")

sleep(2)

print("Good Bye!")
