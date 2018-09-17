import Pyto

from rubicon.objc import *
import MainThread

# Code here

UIColor = ObjCClass("UIColor")
UIApplication = ObjCClass("UIApplication")

def changeTintColor() -> None:
  UIApplication.sharedApplication.keyWindow.tintColor = UIColor.redColor
  
MainThread.async(changeTintColor)
