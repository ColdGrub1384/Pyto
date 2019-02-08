//
//  ConsoleViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
#if MAIN
import InputAssistant
#endif

/// A View controller containing Python script output.
@objc open class ConsoleViewController: UIViewController, UITextViewDelegate {
    
    #if MAIN
    /// The theme the user choosed.
    static var choosenTheme: Theme {
        set {
            
            let themeID: Int
            
            switch newValue {
            case is XcodeTheme:
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
            
            NotificationCenter.default.post(name: ThemeDidChangedNotification, object: newValue)
        }
        
        get {
            switch UserDefaults.standard.integer(forKey: "theme") {
            case 0:
                return XcodeTheme()
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
                return XcodeTheme()
            }
        }
    }
    
    /// The Input assistant view for typing module's identifier.
    let inputAssistant = InputAssistantView()
    
    /// Reloads suggestions.
    @objc func reloadSuggestions() {
        DispatchQueue.main.async {
            self.inputAssistant.reloadData()
        }
    }
    
    private var willReloadSuggestion = false
    
    private var _suggestions = [String]()
    
    /// Code completion suggestions for the REPL.
    @objc var suggestions: [String] {
        set {
            
            _suggestions = []
            
            // Here I'm trying to fix a EXC_BAD_ACCESS crash
            
            for suggestion in newValue {
                _suggestions.append(suggestion)
            }
            // Disabled due to multiple crashes
            /*DispatchQueue.main.async {
                self.inputAssistant.reloadData()
            }*/
        }
        
        get {
            return _suggestions
        }
    }
    
    /// Code completion suggestions values for the REPL.
    @objc var completions = [String]()
    #endif
    
    /// Clears screen.
    @objc func clear() {
        DispatchQueue.main.sync {
            textView.text = ""
            console = ""
        }
    }
    
    #if MAIN
    /// Variables from running scripts.
    @objc static var variables = [String:Any]() {
        didSet {
            DispatchQueue.main.async {
                if let inspector = (self.visible.presentedViewController as? UINavigationController)?.viewControllers.first as? InspectorTableViewController, String(describing: inspector.hierarchy) != String(describing: variables) {
                    inspector.hierarchy = variables
                    inspector.tableView.reloadData()
                }
            }
        }
    }
    
    /// Shows the variables inspector.
    @objc func showInspector() {
        if let vc = UIStoryboard(name: "Inspector", bundle: Bundle.main).instantiateInitialViewController() {
            ((vc as? UINavigationController)?.viewControllers.first as? InspectorTableViewController)?.hierarchy = ConsoleViewController.variables
            (parent as? REPLViewController)?.reloadREPL = false
            
            present(vc, animated: true, completion: nil)
        }
    }
    #endif
    
    /// The current prompt.
    @objc var prompt = ""
    
    /// The content of the console.
    @objc var console = ""
    
    /// Set to `true` for asking the user for input.
    @objc var isAskingForInput = false
    
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
    
    /// Requests the user for input.
    ///
    /// - Parameters:
    ///     - prompt: The prompt from the Python function
    func input(prompt: String) {
        
        #if MAIN
        let condition = (!ignoresInput && !ConsoleViewController.ignoresInput || parent is REPLViewController)
        #else
        let condition = (!ignoresInput && !ConsoleViewController.ignoresInput)
        #endif
        
        guard condition else {
            ignoresInput = false
            ConsoleViewController.ignoresInput = false
            return
        }
        
        #if MAIN
        if !(parent is REPLViewController) {
            guard Python.shared.isScriptRunning else {
                return
            }
        }
        #endif
        
        textView.text += prompt
        Python.shared.output += prompt
        textViewDidChange(textView)
        isAskingForInput = true
        textView.isEditable = true
        textView.becomeFirstResponder()
    }
    
    /// Closes the View controller and stops script.
    @objc func close() {
        
        #if MAIN
        extensionContext?.completeRequest(returningItems: nil, completionHandler: nil)
        
        if navigationController != nil {
            dismiss(animated: true, completion: {
                EditorSplitViewController.visible?.editor.stop()
                if let line = EditorSplitViewController.visible?.editor.lineNumberError {
                    EditorSplitViewController.visible?.editor.lineNumberError = nil
                    EditorSplitViewController.visible?.editor.showErrorAtLine(line)
                }
            })
        }
        #else
        exit(0)
        #endif
    }
    
    private static var shared = ConsoleViewController()
    
    /// The visible instance.
    @objc static var visible: ConsoleViewController {
        if Thread.current.isMainThread {
            #if MAIN
            if REPLViewController.shared?.view.window != nil {
                return REPLViewController.shared?.console ?? shared
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
            
            override func viewWillAppear(_ animated: Bool) {
                super.viewWillAppear(animated)
                
                navigationBar.isTranslucent = false
                navigationBar.shadowImage = UIImage()
                navigationBar.barStyle = ConsoleViewController.choosenTheme.barStyle
                navigationBar.barTintColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
            }
            
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
        
        textView.inputAccessoryView = nil
        
        textView.keyboardAppearance = theme.keyboardAppearance
        textView.backgroundColor = theme.sourceCodeTheme.backgroundColor
        textView.textColor = theme.sourceCodeTheme.color(for: .plain)
        
        inputAssistant.attach(to: textView)
        inputAssistant.trailingActions = [InputAssistantAction(image: EditorSplitViewController.downArrow, target: textView, action: #selector(textView.resignFirstResponder))]
    }
    
    /// Called when the user choosed a theme.
    @objc func themeDidChanged(_ notification: Notification) {
        setup(theme: ConsoleViewController.choosenTheme)
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    #endif
    
    // MARK: - View controller
    
    override open func viewDidLoad() {
        super.viewDidLoad()
                
        #if MAIN
        NotificationCenter.default.addObserver(self, selector: #selector(themeDidChanged(_:)), name: ThemeDidChangedNotification, object: nil)
        #endif
        
        edgesForExtendedLayout = []
        
        title = Localizable.console
        
        textView.translatesAutoresizingMaskIntoConstraints = false
        textView.delegate = self
        textView.isEditable = false
        view.addSubview(textView)
        
        #if MAIN
        inputAssistant.delegate = self
        inputAssistant.dataSource = self
        inputAssistant.trailingActions = [InputAssistantAction(image: EditorSplitViewController.downArrow, target: textView, action: #selector(textView.resignFirstResponder))]
        #endif
        
        NotificationCenter.default.addObserver(self, selector: #selector(print_(_:)), name: .init(rawValue: "DidReceiveOutput"), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name:UIResponder.keyboardWillHideNotification, object: nil)
    }
    
    override open func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        #if MAIN
        if (parent as? REPLViewController)?.reloadREPL == false {
            (parent as? REPLViewController)?.reloadREPL = true
        }
        #endif
        textView.frame = view.safeAreaLayoutGuide.layoutFrame
    }
    
    override open func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
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
        
        #if MAIN
        let inspectorButton = UIButton(type: .infoDark)
        inspectorButton.addTarget(self, action: #selector(showInspector), for: .touchUpInside)
        let inspectorItem = UIBarButtonItem(customView: inspectorButton)
        items.append(inspectorItem)
        if parent?.navigationItem.rightBarButtonItems == nil {
            //parent?.navigationItem.rightBarButtonItem = inspectorItem
        } else {
            var continue_ = true
            for item in parent?.navigationItem.rightBarButtonItems ?? [] {
                if (item.customView as? UIButton)?.buttonType == .infoDark {
                    continue_ = false
                }
            }
            if continue_ {
                parent?.navigationItem.rightBarButtonItems?.append(inspectorItem)
            }
        }
        #endif
        navigationItem.rightBarButtonItems = items
        
        #if MAIN
        setup(theme: ConsoleViewController.choosenTheme)
        #endif
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
    
    override open func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        
        guard view != nil else {
            return
        }
        
        guard view.frame.height != size.height else {
            textView.frame.size.width = self.view.safeAreaLayoutGuide.layoutFrame.width
            return
        }
        
        let wasFirstResponder = textView.isFirstResponder
        textView.resignFirstResponder()
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in
            self.textView.frame = self.view.safeAreaLayoutGuide.layoutFrame
            if wasFirstResponder {
                self.textView.becomeFirstResponder()
            }
        }) // TODO: Anyway to to it without a timer?
    }
    
    // MARK: - Keyboard
    
    @objc func keyboardWillShow(_ notification:Notification) {
        let d = notification.userInfo!
        var r = d[UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
        
        r = textView.convert(r, from:nil)
        textView.contentInset.bottom = r.size.height
        textView.scrollIndicatorInsets.bottom = r.size.height
    }
    
    @objc func keyboardWillHide(_ notification:Notification) {
        textView.contentInset = .zero
        textView.scrollIndicatorInsets = .zero
    }
    
    // MARK: - Text view delegate
    
    public func textViewDidChange(_ textView: UITextView) {
        if !isAskingForInput {
            console = textView.text
        }
    }
    
    public func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        
        let location:Int = textView.offset(from: textView.beginningOfDocument, to: textView.endOfDocument)
        let length:Int = textView.offset(from: textView.endOfDocument, to: textView.endOfDocument)
        let end =  NSMakeRange(location, length)
        
        if end != range && !(text == "" && range.length == 1 && range.location+1 == end.location) {
            // Only allow inserting text from the end
            return false
        }
        
        if (textView.text as NSString).replacingCharacters(in: range, with: text).count >= console.count {
            
            prompt += text
            
            if text == "\n" {
                prompt = String(prompt.dropLast())
                PyInputHelper.userInput = prompt
                Python.shared.output += prompt
                prompt = ""
                isAskingForInput = false
                textView.isEditable = false
                textView.text += "\n"
                return false
            } else if text == "" && range.length == 1 {
                prompt = String(prompt.dropLast())
            }
            
            return true
        }
        
        return false
    }
}

#if MAIN
extension ConsoleViewController: InputAssistantViewDelegate, InputAssistantViewDataSource {
    
    public func inputAssistantView(_ inputAssistantView: InputAssistantView, didSelectSuggestionAtIndex index: Int) {
        
        guard completions.indices.contains(index) else {
            return
        }
        
        let completion = completions[index]
        prompt += completion
        textView.text += completion
        
        inputAssistantView.reloadData()
    }
    
    public func textForEmptySuggestionsInInputAssistantView() -> String? {
        return nil
    }
    
    public func numberOfSuggestionsInInputAssistantView() -> Int {
        return suggestions.count
    }
    
    public func inputAssistantView(_ inputAssistantView: InputAssistantView, nameForSuggestionAtIndex index: Int) -> String {
        
        guard suggestions.indices.contains(index) else {
            return ""
        }
        
        let suggestion = suggestions[index]
        
        if suggestion.hasSuffix("(") {
            return suggestion+")"
        }
        
        return suggestion
    }
    
}
#endif
