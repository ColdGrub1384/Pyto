"""
This script implements the `ExampleViewController` class.
"""

from UIKit import * # This gives access to all UIKit classes
import ui

import mainthread
from rubicon.objc import *
from rubicon.objc.types import *

button = UIButton.buttonWithType(1)
label = label = UILabel.new()

def sayHello(self):
    alert = UIAlertController.alertControllerWithTitle("What's your name?", message="Type your name to say hello.", preferredStyle=1)
    
    def ok() -> None:
        print("Hello "+alert.textFields.firstObject().text+"!")
    
    def setupTextField(textField: ObjCInstance) -> None:
        textField.placeholder = "Your name"

    alert.addAction(UIAlertAction.actionWithTitle("Cancel", style=1, handler=None))
    alert.addAction(UIAlertAction.actionWithTitle("Ok", style=0, handler=Block(ok)))

    alert.addTextFieldWithConfigurationHandler(setupTextField)
    
    self.presentViewController(alert, animated=True, completion=None)

def setViewsFrame(size):
    button.frame = CGRect(CGPoint(0, 0), CGSize(size.width, 50))
    button.center = CGPoint(size.width/2, size.height/2)
    
    label.frame = CGRect(CGPoint(0, 0), CGSize(size.width, 50))
    label.center = CGPoint(size.width/2, (size.height/2)-60)

def viewDidLoad(self):
    edgesForExtendedLayout = 0
    
    self.view.backgroundColor = UIColor.blackColor
    
    self.title = "Hello World!"
    
    button.setTitle("Say Hello", forState=0)
    button.addTarget(self, action=SEL("sayHello:"), forControlEvents=1)
    self.view.addSubview(button)
    
    label.textAlignment = 1
    label.text = "Hello World!"
    label.textColor = UIColor.whiteColor
    self.view.addSubview(label)
    
    setViewsFrame(self.view.bounds.size)

try:
    # Check if the `ExampleViewController` class is already defined. When an Objective-C class is defined, you cannot redefine it before re-launching the app.
    # So, always use unique class names for your scripts.
    # You should also define external functions and call them from the class so you can modify them. You cannot modifiy a class until re-launching the app.
    ExampleViewController
except:
    class ExampleViewController(UIViewController):
        
        @objc_method
        def sayHello_(self, sender) -> None:
            sayHello(self)
        
        @objc_method
        def viewDidLoad(self) -> None:
            viewDidLoad(self)
        
        @objc_method
        def viewDidLayoutSubviews(self):
            setViewsFrame(self.view.size)

