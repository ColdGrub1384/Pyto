from pip import main
import sys
import traceback

try:
    del sys.modules["pip"]
except KeyError:
    pass

try:
    main(sys.argv[1:])
except Exception as e:
    print(e)
    sys.__stderr__.write(traceback.format_exc())
