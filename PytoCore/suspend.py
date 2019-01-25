from UIKit import UIApplication
import mainthread

def suspend():
    
    def runSuspend() -> None:
        UIApplication.sharedApplication.suspend()

    mainthread.run_sync(runSuspend)
