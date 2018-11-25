"""
Changes the tint color of the app to red.
"""

from UIKit import UIColor, UIApplication
import mainthread

# Code here

def changeTintColor() -> None:
  UIApplication.sharedApplication.keyWindow.tintColor = UIColor.redColor
  
mainthread.runSync(changeTintColor)
