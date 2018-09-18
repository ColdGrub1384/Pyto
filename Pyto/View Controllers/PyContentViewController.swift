//
//  PyContentViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller representing the result of the script ran by the user. Change `viewController` property or call `setRootViewController(_:)` to embed a custom View controller. It can be set from Python trough the Rubicon library to access Objective-C runtime, but it's not recommended because of issues subclassing. The default View controller is the console.
@objc class PyContentViewController: UIViewController {
    
    /// The visible instance.
    @objc static var shared: PyContentViewController?
    
    /// URL of the script to be ran when this View controller will appear.
    static var scriptToRun: URL?
    
    // MARK: - Content view controller
    
    /// Calls the setter of `viewController` with given value.
    @objc func setRootViewController(_ vc: UIViewController?) {
        viewController = vc
    }
    
    /// The embedded View controller.
    @objc var viewController: UIViewController? {
        didSet {
            if let newValue = viewController {
                addChild(newValue)
                for view in view.subviews {
                    view.removeFromSuperview()
                }
                newValue.view.frame = view.frame
                newValue.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
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
        viewController = navVC
    }
    
    /// Dismisses the console's keyboard.
    @objc func dismissKeyboard() {
        DispatchQueue.main.async {
            let console = (self.viewController as? UINavigationController)?.visibleViewController as? ConsoleViewController
            console?.resignFirstResponder()
            console?.textView.isEditable = false
            console?.isAskingForInput = false
            console?.ignoresInput = true
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
        
        if let url = PyContentViewController.scriptToRun {
            let console = (viewController as? UINavigationController)?.visibleViewController as? ConsoleViewController
            console?.textView?.text = ""
            console?.ignoresInput = false
            if Python.shared.isREPLRunning {
                // Import the script
                PyInputHelper.userInput = "from importlib.machinery import SourceFileLoader; import PytoClasses as __pytoclasses__; pyto_running_script = SourceFileLoader('main', '\(url.path)').load_module(); __pytoclasses__.PyContentViewController.shared.dismissKeyboard();"
            } else {
                Python.shared.runScript(at: url)
            }
            PyContentViewController.scriptToRun = nil
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        PyContentViewController.shared = nil
    }
    
    override var prefersStatusBarHidden: Bool {
        return viewController?.prefersStatusBarHidden ?? false
    }
    
    override var preferredStatusBarStyle: UIStatusBarStyle {
        return viewController?.preferredStatusBarStyle ?? .default
    }
}
