"""
An example of a loop that responds to SystemExit and KeyboardInterrupt
"""

print("Hello World!")

try:
  while True:
    continue
except KeyboardInterrupt:
  print("Interrupted with hardware keyboard '^C'")
  input("Press enter to confirm ")
except SystemExit:
  print("Exit with stop button")
  input("Press enter to confirm ")
