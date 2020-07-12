import os
from pyto import Python
from time import sleep
from mainthread import mainthread

os.environ["widget"] = "1"

while True:
    try: # Run code
        
        if Python.shared.codeToRun is not None:
            exec(str(Python.shared.codeToRun))
                
        Python.shared.codeToRun = None
    except Exception as e:
        print(e)

    sleep(0.2)
