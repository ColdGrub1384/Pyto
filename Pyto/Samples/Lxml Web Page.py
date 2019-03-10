"""
Creates an HTML page with lxml and display it on a WKWebView.
"""

#
# To create the HTML page
#
from lxml import etree

#
# To create a View controller
#
from UIKit import UIViewController

#
# To access Objective-C classes
#
from rubicon.objc import ObjCClass

#
# To run code on main thread
#
from mainthread import run_sync

#
# To show the UI
#
import ui

#
# A Web kit web view
#
WKWebView = ObjCClass("WKWebView")

# MARK: - Generate HTML

# html
root_elem = etree.Element("html", lang="en_US")

#   head
head = etree.SubElement(root_elem, "head")

#     meta
etree.SubElement(head, "meta", name="viewport", content="width=device-width, initial-scale=1.0")

#     title
etree.SubElement(root_elem, "title").text = "Web Page"

#   body
etree.SubElement(root_elem, "body").text = "Hello World!"

html = etree.tostring(root_elem, pretty_print=True).decode("utf-8")

# MARK: - Show UI

def main():
  """
  Shows the web page.
  """
    
  viewController = UIViewController.new()
  
  viewController.view = WKWebView.new()
  viewController.view.loadHTMLString(html, baseURL=None)
    
  ui.show_view_controller(viewController)

run_sync(main)
ui.main_loop()
