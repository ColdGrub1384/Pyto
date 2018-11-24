"""
This script shows an example of how presenting an User Interface.
"""

import ui
import mainthread
from Interface import ExampleViewController
from UIKit import UINavigationController

def main() -> None:
    
    viewController = ExampleViewController.new()
    
    navigationController = UINavigationController.new()
    navigationController.setViewControllers([viewController])
    navigationController.navigationBar.barStyle = 1
    ui.showViewController(navigationController)

mainthread.runSync(main)

ui.mainLoop()
