//
//  ConsoleViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller containing Python script output.
@objc open class ConsoleViewController: UIViewController, UITextViewDelegate {
    
    #if MAIN
    /// The theme the user choosed.
    static var choosenTheme: Theme {
        set {
            
            let themeID: Int
            
            switch newValue {
            case is XcodeLightTheme:
                themeID = -1
            case is DefaultTheme:
                themeID = 0
            case is XcodeDarkTheme:
                themeID = 1
            case is BasicTheme:
                themeID = 2
            case is DuskTheme:
                themeID = 3
            case is LowKeyTheme:
                themeID = 4
            case is MidnightTheme:
                themeID = 5
            case is SunsetTheme:
                themeID = 6
            case is WWDC16Theme:
                themeID = 7
            case is CoolGlowTheme:
                themeID = 8
            case is SolarizedLightTheme:
                themeID = 9
            case is SolarizedDarkTheme:
                themeID = 10
            default:
                themeID = 0
            }
            
            UserDefaults.standard.set(themeID, forKey: "theme")
            UserDefaults.standard.synchronize()
            
            UIApplication.shared.keyWindow?.tintColor = newValue.tintColor
            
            NotificationCenter.default.post(name: ThemeDidChangeNotification, object: newValue)
        }
        
        get {
            switch UserDefaults.standard.integer(forKey: "theme") {
            case -1:
                return XcodeLightTheme()
            case 0:
                return DefaultTheme()
            case 1:
                return XcodeDarkTheme()
            case 2:
                return BasicTheme()
            case 3:
                return DuskTheme()
            case 4:
                return LowKeyTheme()
            case 5:
                return MidnightTheme()
            case 6:
                return SunsetTheme()
            case 7:
                return WWDC16Theme()
            case 8:
                return CoolGlowTheme()
            case 9:
                return SolarizedLightTheme()
            case 10:
                return SolarizedDarkTheme()
            default:
                return DefaultTheme()
            }
        }
    }
    #endif
    
    /// Clears screen.
    @objc func clear() {
        DispatchQueue.main.sync {
            textView.text = ""
            console = ""
        }
    }
    
    /// The content of the console.
    @objc var console = ""
    
    /// The Text view containing the console.
    @objc var textView = ConsoleTextView()
    
    /// If set to `true`, the user will not be able to input.
    var ignoresInput = false
    
    /// If set to `true`, the user will not be able to input.
    static var ignoresInput = false
    
    /// Returns `true` if the UI main loop is running.
    @objc static private(set) var isMainLoopRunning = false
    
    /// Add the content of the given notification as `String` to `textView`. Called when the stderr changed or when a script printed from the Pyto module's `print` function`.
    ///
    /// - Parameters:
    ///     - notification: Its associated object should be the `String` added to `textView`.
    @objc func print_(_ notification: Notification) {
        if let output = notification.object as? String {
            DispatchQueue.main.async {
                self.console += output
                
                let attrStr = NSMutableAttributedString(attributedString: self.textView.attributedText)
                attrStr.append(NSAttributedString(string: output, attributes: [.font : UIFont(name: "Menlo", size: 12) ?? UIFont.systemFont(ofSize: 12)]))
                self.textView.attributedText = attrStr
                
                self.textViewDidChange(self.textView)
                self.textView.scrollToBottom()
            }
        }
    }
    
    /// The text field used for sending input.
    var movableTextField: MovableTextField?
    
    /// Prompt sent by Python `input(prompt)` function.
    var prompt: String?
    
    /// Returns `false` if input should be ignored.
    var shouldRequestInput: Bool {
        #if MAIN
        let condition = (!self.ignoresInput && !ConsoleViewController.ignoresInput || self.parent is REPLViewController)
        #else
        let condition = (!ignoresInput && !ConsoleViewController.ignoresInput)
        #endif
        
        guard condition else {
            self.ignoresInput = false
            ConsoleViewController.ignoresInput = false
            return false
        }
        
        #if MAIN
        if !(self.parent is REPLViewController) {
            guard Python.shared.isScriptRunning else {
                return false
            }
        }
        #endif
        return true
    }
    
    /// Requests the user for input.
    ///
    /// - Parameters:
    ///     - prompt: The prompt from the Python function
    func input(prompt: String) {
        
        guard shouldRequestInput else {
            return
        }
        
        self.prompt = prompt
        movableTextField?.placeholder = prompt
        movableTextField?.focus()
    }
    
    /// Requests the user for a password.
    ///
    /// - Parameters:
    ///     - prompt: The prompt from the Python function
    func getpass(prompt: String) {
        
        guard shouldRequestInput else {
            return
        }
        
        self.prompt = prompt
        movableTextField?.textField.isSecureTextEntry = true
        movableTextField?.placeholder = prompt
        movableTextField?.focus()
    }
    
    /// Closes the View controller and stops script.
    @objc func close() {
        
        #if MAIN
        extensionContext?.completeRequest(returningItems: nil, completionHandler: nil)
        
        if navigationController != nil {
            dismiss(animated: true, completion: {
                EditorSplitViewController.visible?.editor.stop()
                DispatchQueue.main.asyncAfter(deadline: .now()+0.5, execute: {
                    if let line = EditorSplitViewController.visible?.editor.lineNumberError {
                        EditorSplitViewController.visible?.editor.lineNumberError = nil
                        EditorSplitViewController.visible?.editor.showErrorAtLine(line)
                    }
                })
            })
        }
        #else
        exit(0)
        #endif
    }
    
    #if MAIN
    /// Enables `'Done'` if Pip is running.
    @objc static func enableDoneButton() {
        DispatchQueue.main.async {
            guard let doneButton = self.visible.parent?.navigationItem.leftBarButtonItem else {
                return
            }
            
            if doneButton.action == #selector(PipInstallerViewController.closeViewController) {
                doneButton.isEnabled = true
            }
        }
    }
    #endif
    
    private static var shared = ConsoleViewController()
    
    /// The visible instance.
    @objc static var visible: ConsoleViewController {
        if Thread.current.isMainThread {
            #if MAIN
            if REPLViewController.shared?.view.window != nil {
                return REPLViewController.shared?.console ?? shared
            } else if PipInstallerViewController.shared?.view.window != nil {
                return PipInstallerViewController.shared?.console ?? shared
            } else if RunModuleViewController.shared?.view.window != nil {
                return RunModuleViewController.shared?.console ?? shared
            } else {
                return shared
            }
            #else
            return shared
            #endif
        } else {
            var console: ConsoleViewController?
            DispatchQueue.main.sync {
                console = ConsoleViewController.visible
            }
            return console ?? shared
        }
    }
    
    /// Closes the View controller presented from Python and stops the UI main loop.
    @objc func closePresentedViewController() {
        if presentedViewController != nil && ConsoleViewController.isMainLoopRunning {
            dismiss(animated: true) {
                ConsoleViewController.isMainLoopRunning = false
            }
        }
    }
    
    /// Creates a View controller to present
    ///
    /// - Parameters:
    ///     - viewController: The View controller to present initialized from Python.
    ///
    /// - Returns: A ready to present View controller.
    @objc public func viewController(_ viewController: UIViewController) -> UIViewController {
        
        #if MAIN
        class PyNavigationController: UINavigationController {
            
            override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
                if traitCollection.horizontalSizeClass == .compact {
                    return [.portrait, .portraitUpsideDown]
                } else {
                    return super.supportedInterfaceOrientations
                }
            }
        }
        
        let vc = UIViewController()
        vc.view.backgroundColor = UIColor.black.withAlphaComponent(0.5)
        vc.addChild(viewController)
        viewController.view.frame = CGRect(x: 0, y: 0, width: 320, height: 420)
        viewController.view.center = vc.view.center
        viewController.view.autoresizingMask = [.flexibleTopMargin, .flexibleBottomMargin, .flexibleLeftMargin, .flexibleRightMargin]
        vc.view.addSubview(viewController.view)
        
        vc.navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(closePresentedViewController))
        
        let navVC = PyNavigationController(rootViewController: vc)
        navVC.modalPresentationStyle = .overFullScreen
        
        if navigationController != nil {
            view.backgroundColor = UIColor.black.withAlphaComponent(0.25)
            navigationController?.view.backgroundColor = view.backgroundColor
        }
        
        return navVC
        #else
        return viewController
        #endif
    }
    
    // MARK: - Theme
    
    #if MAIN
    /// Setups the View controller interface for given theme.
    ///
    /// - Parameters:
    ///     - theme: The theme to apply.
    func setup(theme: Theme) {
        
        movableTextField?.theme = theme
        
        textView.keyboardAppearance = theme.keyboardAppearance
        textView.backgroundColor = theme.sourceCodeTheme.backgroundColor
        view.backgroundColor = theme.sourceCodeTheme.backgroundColor
        textView.textColor = theme.sourceCodeTheme.color(for: .plain)
    }
    
    /// Called when the user choosed a theme.
    @objc func themeDidChange(_ notification: Notification?) {
        setup(theme: ConsoleViewController.choosenTheme)
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    #endif
    
    /// Sets "COLUMNS" and "ROWS" environment variables.
    func updateSize() {
        var columns: Int {
            
            guard let font = textView.font else {
                assertionFailure("Expected font")
                return 0
            }
            
            // TODO: check if the bounds includes the safe area (on iPhone X)
            let viewWidth = textView.bounds.width
            
            let dummyAtributedString = NSAttributedString(string: "X", attributes: [.font: font])
            let charWidth = dummyAtributedString.size().width
            
            // Assumes the font is monospaced
            return Int((viewWidth / charWidth).rounded(.down))
        }
        
        var rows: Int {
            
            guard let font = textView.font else {
                assertionFailure("Expected font")
                return 0
            }
            
            // TODO: check if the bounds includes the safe area (on iPhone X)
            let viewHeight = textView.bounds.height-textView.contentInset.bottom
            
            let dummyAtributedString = NSAttributedString(string: "X", attributes: [.font: font])
            let charHeight = dummyAtributedString.size().height
            
            // Assumes the font is monospaced
            return Int((viewHeight / charHeight).rounded(.down))
        }
        
        print(columns)
        print(rows)
        setenv("COLUMNS", "\(columns)", 1)
        setenv("ROWS", "\(rows)", 1)
    }
    
    // MARK: - View controller
    
    override open func viewDidLoad() {
        super.viewDidLoad()
        
        #if MAIN
        NotificationCenter.default.addObserver(self, selector: #selector(themeDidChange(_:)), name: ThemeDidChangeNotification, object: nil)
        #endif
        
        if #available(iOS 13.0, *) {
            view.backgroundColor = .systemBackground
        }
        
        edgesForExtendedLayout = []
        
        title = Localizable.console
        
        textView.translatesAutoresizingMaskIntoConstraints = false
        textView.frame.size.height = view.frame.height
        textView.delegate = self
        textView.isEditable = false
        view.addSubview(textView)
        
        NotificationCenter.default.addObserver(self, selector: #selector(print_(_:)), name: .init(rawValue: "DidReceiveOutput"), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name:UIResponder.keyboardWillHideNotification, object: nil)
        
        movableTextField = MovableTextField(console: self)
    }
    
    override open func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        themeDidChange(nil)
    }
    
    override open func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        #if MAIN
        if (parent as? REPLViewController)?.reloadREPL == false {
            (parent as? REPLViewController)?.reloadREPL = true
        }
        #endif
        textView.frame = view.safeAreaLayoutGuide.layoutFrame
        textView.frame.size.height -= 44
        textView.frame.origin.y = view.safeAreaLayoutGuide.layoutFrame.origin.y
        
        updateSize()
    }
    
    override open func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if movableTextField == nil {
            movableTextField = MovableTextField(console: self)
            movableTextField?.placeholder = prompt ?? ""
        }
        movableTextField?.show()
        movableTextField?.handler = { text in
            
            let secureTextEntry = self.movableTextField?.textField.isSecureTextEntry ?? false
            self.movableTextField?.textField.isSecureTextEntry = false
            
            guard self.shouldRequestInput else {
                return
            }
            
            PyInputHelper.userInput = text
            if !secureTextEntry {
                Python.shared.output += text
                self.textView.text += "\(self.movableTextField?.placeholder ?? "")\(text)\n"
            } else {
                
                var hiddenPassword = ""
                for _ in 0...text.count {
                    hiddenPassword += "*"
                }
                
                Python.shared.output += text
                self.textView.text += "\(self.movableTextField?.placeholder ?? "")\(hiddenPassword)\n"
            }
            self.textView.scrollToBottom()
        }
        
        var items = [UIBarButtonItem]()
        func appendStop() {
            items.append(UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(close)))
        }
        #if MAIN
        if !(parent is REPLViewController) {
            appendStop()
        }
        #else
        appendStop()
        #endif
        
        navigationItem.rightBarButtonItems = items
        
        #if MAIN
        setup(theme: ConsoleViewController.choosenTheme)
        #endif
    }
    
    open override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        movableTextField?.toolbar.removeFromSuperview()
        movableTextField = nil
    }
    
    override open func dismiss(animated flag: Bool, completion: (() -> Void)? = nil) {
        super.dismiss(animated: flag, completion: completion)
        
        #if MAIN
        view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        navigationController?.view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        #else
        view.backgroundColor = .white
        navigationController?.view.backgroundColor = .white
        #endif
    }
    
    open override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        let wasFirstResponder = movableTextField?.textField.isFirstResponder ?? false
        movableTextField?.textField.resignFirstResponder()
        movableTextField?.toolbar.frame.size.width = view.safeAreaLayoutGuide.layoutFrame.width
        movableTextField?.toolbar.frame.origin.x = view.safeAreaInsets.left
        textView.frame = view.safeAreaLayoutGuide.layoutFrame
        textView.frame.size.height = view.safeAreaLayoutGuide.layoutFrame.height-44
        textView.frame.origin.y = view.safeAreaLayoutGuide.layoutFrame.origin.y
        if wasFirstResponder {
            movableTextField?.textField.becomeFirstResponder()
        }
        movableTextField?.toolbar.isHidden = (view.frame.size.height == 0 )
        #if MAIN
        movableTextField?.applyTheme()
        #endif
        updateSize()
    }
    
    open override var keyCommands: [UIKeyCommand]? {
        return [
            UIKeyCommand(input: UIKeyCommand.inputDownArrow, modifierFlags: [], action: #selector(down)),
            UIKeyCommand(input: UIKeyCommand.inputUpArrow, modifierFlags: [], action: #selector(up)),
        ]
    }
    
    // MARK: - Keyboard
    
    @objc func keyboardWillShow(_ notification:Notification) {
        if parent?.parent?.modalPresentationStyle != .popover || parent?.parent?.view.frame.width != parent?.parent?.preferredContentSize.width {
            let d = notification.userInfo!
            let r = d[UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
            
            let point = (UIApplication.shared.keyWindow)?.convert(r.origin, to: view) ?? r.origin
            
            textView.frame.size.height = point.y-44
        } else {
            textView.frame.size.height = view.safeAreaLayoutGuide.layoutFrame.height-44
        }
        
        textView.frame.origin.y = view.safeAreaLayoutGuide.layoutFrame.origin.y
        
        textView.scrollToBottom()
    }
    
    @objc func keyboardWillHide(_ notification:Notification) {
        textView.frame.size.height = view.safeAreaLayoutGuide.layoutFrame.height-44
        textView.frame.origin.y = view.safeAreaLayoutGuide.layoutFrame.origin.y
    }
    
    @objc private func up() {
        movableTextField?.up()
    }
    
    @objc private func down() {
        movableTextField?.down()
    }
    
    // MARK: - Text view delegate
    
    public func textViewDidChange(_ textView: UITextView) {
        console = textView.text
    }
}

