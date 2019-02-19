"""
This script shows an example of how presenting an User Interface.

Important: You should not subclass `UIViewController` because you would have to relaunch Pyto to modify the class. Pyto has now APIs for creating selectors from Python functions.
"""

#
# Pyto uses UIKit for presenting UI.
#
import ui
from UIKit import *

#
# So all UIKit functions should be called from the main thread.
#
import mainthread

#
# Rubicon Objective-C is used to access Objective-C classes.
#
from rubicon.objc import *
from rubicon.objc.types import *

# MARK: - Implementation

label = None
button = None
viewController = None

def sayHello(sender: ObjCInstance) -> None:
  """
  This function is called when the "Say Hello" button is pressed.
  
   IMPORTANT: All functions that will be sent to Objective-C must be fully annotated. For example, this function returns `None`, so add "-> None" at the end. For parameters, write ": ObjCInstance" to represent any Objective-C instance.
  
   Args:
    sender: The sender button.
  
  Returns: `None`
  """
  
  alert = UIAlertController.alertControllerWithTitle("What's your name?", message="Type your name to say hello.", preferredStyle=1)
  
  def ok() -> None:
    ui.close_view_controller()
    print("Hello "+alert.textFields.firstObject().text+"!")
  
  def setupTextField(textField: ObjCInstance) -> None:
    textField.placeholder = "Your name"

  alert.addAction(UIAlertAction.actionWithTitle("Cancel", style=1, handler=None))
  alert.addAction(UIAlertAction.actionWithTitle("Ok", style=0, handler=Block(ok)))

  alert.addTextFieldWithConfigurationHandler(setupTextField)
  
  viewController.presentViewController(alert, animated=True, completion=None)

def setupView() -> None:
  """
  Setups views.
  
   IMPORTANT: All functions that will be sent to Objective-C must be fully annotated. For example, this function returns `None`, so add "-> None" at the end. For parameters, write ": ObjCInstance" to represent any Objective-C instance.
  
  Returns: `None`
  """
  
  global label
  global button
  
  label = UILabel.new()
  button = UIButton.buttonWithType(1)
  
  edgesForExtendedLayout = 0
  
  viewController.view.backgroundColor = UIColor.whiteColor
  
  viewController.title = "Hello World!"
  
  button.setTitle("Say Hello", forState=0)
  viewController.view.addSubview(button)
  
  """
  Pyto provides APIs for creating selectors without classes.
  
  Pass `Target` as target and `Selector(Your_Function)` as action.
  """
  button.addTarget(Target, action=Selector(sayHello), forControlEvents=1)
  
  label.textAlignment = 1
  label.text = "Hello World!"
  label.textColor = UIColor.blackColor
  viewController.view.addSubview(label)
  
  size = viewController.view.bounds.size
  
  button.frame = CGRect(CGPoint(0, 0), CGSize(size.width, 50))
  button.center = CGPoint(size.width/2, size.height/2)
  
  label.frame = CGRect(CGPoint(0, 0), CGSize(size.width, 50))
  label.center = CGPoint(size.width/2, (size.height/2)-60)

# MARK: - Showing the UI

def main() -> None:
  """
  Ran on main thread for presenting the View controller.
  
  IMPORTANT: All functions that will be sent to Objective-C must be fully annotated. For example, this function returns `None`, so add "-> None" at the end. For parameters, write ": ObjCInstance" to represent any Objective-C instance.
  
  Returns: `None`
  """
  
  global viewController
  viewController = UIViewController.new()
  
  navigationController = UINavigationController.new()
  navigationController.setViewControllers([viewController])
  ui.show_view_controller(navigationController, setupView)

# Runs `main` on main thread.
mainthread.run_sync(main)

# This will stop the current thread until the View controller is hidden. Very important to avoid crashes on actions!
ui.main_loop()

