"""
Presenting a subclass of UIViewController.
"""

from UIKit import *
from LinkPresentation import *
from Foundation import *
from rubicon.objc import *
from mainthread import mainthread
import pyto_ui as ui

# We subclass UIViewController
class MyViewController(UIViewController):
    
    # Overriding viewDidLoad
    @objc_method
    def viewDidLoad(self):
        send_super(__class__, self, "viewDidLoad")

        self.title = "Link"

        self.view.backgroundColor = UIColor.systemBackgroundColor()

        done_button = UIBarButtonItem.alloc().initWithBarButtonSystemItem(0, target=self, action=SEL("close"))
        self.navigationItem.rightBarButtonItems = [done_button]
        
        self.url = NSURL.alloc().initWithString("https://apple.com")
        self.link_view = LPLinkView.alloc().initWithURL(self.url)
        self.link_view.frame = CGRectMake(0, 0, 200, 000)
        self.view.addSubview(self.link_view)
        self.fetchMetadata()
    
    @objc_method
    def fetchMetadata(self):
        
        @mainthread
        def set_metadata(metadata):
            self.link_view.setMetadata(metadata)
            self.layout()

        def fetch_handler(metadata: ObjCInstance, error: ObjCInstance) -> None:
             set_metadata(metadata)
        
        provider = LPMetadataProvider.alloc().init().autorelease()
        provider.startFetchingMetadataForURL(self.url, completionHandler=fetch_handler)
    
    @objc_method
    def layout(self):
        self.link_view.sizeToFit()
        self.link_view.setCenter(self.view.center)
    
    @objc_method
    def close(self):
        self.dismissViewControllerAnimated(True, completion=None)
    
    @objc_method
    def viewDidLayoutSubviews(self):
        self.layout()
    
    @objc_method
    def dealloc(self):
        self.link_view.release()

@mainthread
def show():
    # We initialize our view controller and a navigation controller
    # This must be called from the main thread
    vc = MyViewController.alloc().init().autorelease()
    nav_vc = UINavigationController.alloc().initWithRootViewController(vc).autorelease()
    ui.show_view_controller(nav_vc)

show()
