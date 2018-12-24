//
//  PyContentViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller representing the result of the script ran by the user. Change `viewController` property or call `setRootViewController(_:)` to embed a custom View controller. It can be set from Python trough the Rubicon library to access Objective-C runtime. The default View controller is the console.
@objc class PyContentViewController: UIViewController {
    
    /// The visible instance.
    @objc static var shared: PyContentViewController?
    
    // MARK: - Content view controller
    
    /// Calls the setter of `viewController` with given value.
    @objc func setRootViewController(_ vc: UIViewController?) {
        viewController = vc
    }
    
    /// Returns `true` if this View controller is shown.
    @objc var isViewVisible: Bool {
        var isViewVisible = false
        
        let semaphore = DispatchSemaphore(value: 0)
        DispatchQueue.main.async {
            isViewVisible = (self.view.window != nil)
            semaphore.signal()
        }
        semaphore.wait()
        
        return isViewVisible
    }
    
    /// The embedded View controller.
    @objc var viewController: UIViewController? {
        didSet {
            if let newValue = viewController {
                addChild(newValue)
                for view in view.subviews {
                    view.removeFromSuperview()
                }
                
                if let navVC = newValue as? UINavigationController, navVC.viewControllers.first is ConsoleViewController {
                    newValue.view.frame = view.frame
                    newValue.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
                } else {
                    newValue.view.frame = CGRect(x: 0, y: 0, width: 320, height: 420)
                    newValue.view.center = view.center
                    newValue.view.autoresizingMask = [.flexibleTopMargin, .flexibleBottomMargin, .flexibleLeftMargin, .flexibleRightMargin]
                }
                
                view.addSubview(newValue.view)
                setNeedsStatusBarAppearanceUpdate()
            } else {
                setDefaultViewController()
            }
        }
    }
    
    /// Show the console.
    func setDefaultViewController() {
        let navVC = UINavigationController(rootViewController: ConsoleViewController())
        navVC.navigationBar.barStyle = .black
        navVC.isNavigationBarHidden = true
        viewController = navVC
    }
    
    /// Dismisses the console's keyboard.
    @objc func dismissKeyboard() {
        DispatchQueue.main.async {
            let console = (self.viewController as? UINavigationController)?.visibleViewController as? ConsoleViewController
            console?.resignFirstResponder()
            console?.isAskingForInput = false
            console?.ignoresInput = true
            console?.textView?.isEditable = false
        }
    }
    
    /// Runs the script at given URL.
    ///
    /// - Parameters:
    ///     - url: The URL of the script.
    func runScript(at url: URL) {
        let console = (viewController as? UINavigationController)?.visibleViewController as? ConsoleViewController
        console?.textView?.text = ""
        console?.ignoresInput = false
        console?.console = ""
        if Python.shared.isREPLRunning {
            if Python.shared.isScriptRunning { // A script is already running
                PyOutputHelper.print(Localizable.Python.alreadyRunning)
                return
            }
            Python.shared.isScriptRunning = true
            Python.shared.values = []
            // Import the script
            PyInputHelper.userInput = "import console as __console__; script = __console__.runScriptAtPath('\(url.path)')"
        } else {
            Python.shared.runScript(at: url)
        }
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        setDefaultViewController()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        PyContentViewController.shared = self
    }
    
    override var prefersStatusBarHidden: Bool {
        return viewController?.prefersStatusBarHidden ?? false
    }
    
    override var preferredStatusBarStyle: UIStatusBarStyle {
        return viewController?.preferredStatusBarStyle ?? .default
    }
}
