from rubicon.objc import *
import mainthread

# Code here

UIColor = ObjCClass("UIColor")
UIApplication = ObjCClass("UIApplication")

def changeTintColor() -> None:
  UIApplication.sharedApplication.keyWindow.tintColor = UIColor.redColor
  
mainthread.async(changeTintColor)
