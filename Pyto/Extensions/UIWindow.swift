import UIKit

extension UIWindow {
    
    /// Returns the top View controller of the window usable to present modally a View controller.
    @objc var topViewController: UIViewController? {
        var top = self.rootViewController
        while true {
            if let presented = top?.presentedViewController {
                top = presented
            } else if let nav = top as? UINavigationController {
                top = nav.visibleViewController
            } else if let tab = top as? UITabBarController {
                top = tab.selectedViewController
            } else {
                break
            }
        }
        return top
    }
}

extension UIViewController {
    
    /// Returns the top View controller of the window usable to present modally a View controller.
    @objc var topViewController: UIViewController {
        var top = self
        while true {
            if let presented = top.presentedViewController {
                top = presented
            } else if let nav = top as? UINavigationController {
                top = nav.visibleViewController ?? self
            } else if let tab = top as? UITabBarController {
                top = tab.selectedViewController ?? self
            } else {
                break
            }
        }
        return top
    }
}
