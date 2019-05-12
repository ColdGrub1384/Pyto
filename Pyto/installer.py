from pip import main
import sys
import traceback

try:
    main(sys.argv[1:])
except:
    print(traceback.format_exc())
