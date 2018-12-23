//
//  PyContentViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import FloatingPanel

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
    @objc private(set) var isViewVisible = false
    
    private var floatingPanel: FloatingPanelController?
    
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
                
                let console = ConsoleViewController()
                console.loadViewIfNeeded()
                console.view.backgroundColor = .black
                floatingPanel?.removeFromParent()
                floatingPanel = FloatingPanelController()
                floatingPanel?.set(contentViewController: console)
                floatingPanel?.track(scrollView: console.textView)
                floatingPanel?.addPanel(toParent: self)
                floatingPanel?.move(to: .tip, animated: true)
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
        floatingPanel?.removePanelFromParent(animated: true)
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
        
        isViewVisible = true
        PyContentViewController.shared = self
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        isViewVisible = false
    }
    
    override var prefersStatusBarHidden: Bool {
        return viewController?.prefersStatusBarHidden ?? false
    }
    
    override var preferredStatusBarStyle: UIStatusBarStyle {
        return viewController?.preferredStatusBarStyle ?? .default
    }
}
