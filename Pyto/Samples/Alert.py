import Pyto

# Code here

def ok() -> None:
  print("Good Bye!")

alert = Pyto.Alert.initWithTitle("Hello", message="Hello World!")
alert.addActionWithTitle("Ok", handler=ok)
alert.show()
