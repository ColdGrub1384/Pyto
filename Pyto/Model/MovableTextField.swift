//
//  MovableTextField.swift
//  MovableTextField
//
//  Created by Emma Labbé on 3/30/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import AVKit
#if MAIN
import InputAssistant
import Pipable
#endif

/// The text field used in the terminal.
class TerminalTextField: UITextField {
    
    var isTabbing = false
    
    @objc func down() {
        console?.down()
    }
    
    @objc func up() {
        console?.up()
    }
    
    @objc func nextSuggestion() {
        console?.nextSuggestion()
        becomeFirstResponder()
    }
    
    @objc func interrupt() {
        console?.editorSplitViewController?.interrupt(self)
    }
    
    @objc func doNothing() {
        print("Do nothing")
    }
    
    override var canBecomeFirstResponder: Bool {
        console?.presentedViewController == nil
    }
    
    var pipBarButtonItem: UIBarButtonItem!
    
    override func pressesBegan(_ presses: Set<UIPress>, with event: UIPressesEvent?) {
        for press in presses {
            
            if press.key?.keyCode == .keyboardTab && press.key?.modifierFlags == [] {
                isTabbing = true
                nextSuggestion()
                return
            }
            
            break
        }
        
        super.pressesBegan(presses, with: event)
    }
    
    override var keyCommands: [UIKeyCommand]? {
        var commands = [
            UIKeyCommand(input: UIKeyCommand.inputDownArrow, modifierFlags: [], action: #selector(down)),
            UIKeyCommand(input: UIKeyCommand.inputUpArrow, modifierFlags: [], action: #selector(up)),
            UIKeyCommand.command(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: NSLocalizedString("interrupt", comment: "Description for CTRL+C key command."))
        ]
        
        #if MAIN
        commands.append(UIKeyCommand.command(input: "\t", modifierFlags: [], action: #selector(doNothing), discoverabilityTitle: NSLocalizedString("nextSuggestion", comment: "Title for command for selecting next suggestion")))
        #endif
        
        return commands
    }
    
    var console: ConsoleViewController? {
        (delegate as? MovableTextField)?.console
    }
}

/// A class for managing a movable text field.
class MovableTextField: NSObject, UITextFieldDelegate {
    
    /// The view containing this text field.
    weak var console: ConsoleViewController?
    
    /// The placeholder of the text field.
    var placeholder = "" {
        didSet {
            textField.placeholder = placeholder
        }
    }
    
    #if MAIN
    /// The input assistant containing arrows and a paste button.
    let inputAssistant = InputAssistantView()
    
    /// Applies theme.
    func applyTheme() {
        
        textField.inputAccessoryView = nil
        
        inputAssistant.leadingActions = (UIApplication.shared.orientation.isLandscape ? [InputAssistantAction(image: UIImage())] : [])+[
            InputAssistantAction(image: UIImage(named: "Down") ?? UIImage(), target: self, action: #selector(down)),
            InputAssistantAction(image: UIImage(named: "Up") ?? UIImage(), target: self, action: #selector(up))
        ]
        inputAssistant.trailingActions = [
            InputAssistantAction(image: UIImage(named: "CtrlC") ?? UIImage(), target: self, action: #selector(interrupt)),
            ]+(UIApplication.shared.orientation.isLandscape ? [InputAssistantAction(image: UIImage())] : [])
        
        textField.keyboardAppearance = theme.keyboardAppearance
        if console?.traitCollection.userInterfaceStyle == .dark {
            textField.keyboardAppearance = .dark
        } else {
            textField.keyboardAppearance = .light
        }
        if textField.keyboardAppearance == .dark {
            _uiToolbar.barStyle = .black
        } else {
            _uiToolbar.barStyle = .default
        }
        _uiToolbar.isTranslucent = true
        
        if #available(iOS 13.0, *) {
        } else {
            textField.textColor = theme.sourceCodeTheme.color(for: .plain)
        }
        
        inputAssistant.attach(to: textField)
                
        textField.backgroundColor = .clear
    }
    
    /// Theme used by the bar.
    var theme: Theme = ConsoleViewController.choosenTheme {
        didSet {
            applyTheme()
        }
    }
    #endif
    
    /// The toolbar containing the text field
    let toolbar: UIView
    
    private var _uiToolbar: UIToolbar {
        toolbar.subviews.first(where: { $0 is UIToolbar }) as! UIToolbar
    }
        
    /// The text field.
    let textField: UITextField
    
    /// Displays the given prompt.
    ///
    /// - Parameters:
    ///     - prompt: The prompt to display.
    func setPrompt(_ prompt: String) {        
        textField.placeholder = prompt
    }
    
    /// Initializes the manager.
    ///
    /// - Parameters:
    ///     - console: The console containing the text field.
    init(console: ConsoleViewController) {
        self.console = console
        toolbar = Bundle(for: MovableTextField.self).loadNibNamed("TextField", owner: nil, options: nil)?.first as! UIView
        
        textField = (toolbar.subviews.first(where: { $0 is UIToolbar }) as! UIToolbar).items!.first!.customView as! UITextField
        
        super.init()
        
        #if MAIN
        applyTheme()
        #endif
        
        textField.delegate = self
        if #available(iOS 13.0, *) {
            textField.textColor = UIColor.label
        }
        
        func listenToKeyboardNotifications() {
            NotificationCenter.default.addObserver(self, selector: #selector(keyboardDidShow(_:)), name: UIResponder.keyboardDidShowNotification, object: nil)
            NotificationCenter.default.addObserver(self, selector: #selector(keyboardDidHide(_:)), name: UIResponder.keyboardDidHideNotification, object: nil)
        }
        
        if ((console.editorSplitViewController is REPLViewController) && !(console.editorSplitViewController is ScriptRunnerViewController)) || (console.editorSplitViewController is RunModuleViewController) {
        } else {
            listenToKeyboardNotifications()
        }
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide(_:)), name: UIResponder.keyboardWillHideNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow(_:)), name: UIResponder.keyboardWillShowNotification, object: nil)
    }
    
    /// Shows the text field.
    func show() {
        
        guard let console = console else {
            return
        }
        
        if toolbar.superview != nil {
            toolbar.removeFromSuperview()
        }
        
        toolbar.frame.size.width = console.view.safeAreaLayoutGuide.layoutFrame.width
        toolbar.frame.origin.x = console.view.safeAreaInsets.left
        toolbar.frame.origin.y = console.view.safeAreaLayoutGuide.layoutFrame.height-toolbar.frame.height
        toolbar.autoresizingMask = [.flexibleWidth, .flexibleBottomMargin, .flexibleTopMargin]
        console.view.clipsToBounds = false
        console.view.addSubview(toolbar)
    }
    
    /// Shows keyboard.
    func focus() {
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25) { [weak self] in
            self?.textField.becomeFirstResponder()
        }
    }
    
    /// Code called when text is sent. Receives the text.
    var handler: ((String) -> Void)?
    
    /// Code called when text is modified. Receives the text.
    var didChangeText: ((String) -> Void)?
    
    // MARK: - Keyboard
    
    var lastKeyboardDidShowNotification: NSNotification?
    
    @objc func keyboardDidShow(_ notification: NSNotification) {
        
        // That's the typical code you just cannot understand when you are playing Clash Royale while coding
        // So please, open iTunes, play your playlist, focus and then go back.
        //
        // Edit from 2020: Stop watching TikTok and focus
        //
        // 2021: Ok, so: THIS CODE DOES NOT TOUCHES THE CONSOLE'S TEXTVIEW, IT JUST MOVES THE TEXT BOX. So look at ConsoleViewController.swift if you have a problem with the text view. There's a lot of maths here so I don't really remember how it works but it works so don't touch this.
        
        guard textField.isFirstResponder else {
            return
        }
        
        guard let console = console else {
            return
        }
        
        guard let splitVC = console.editorSplitViewController, !(splitVC is ScriptRunnerViewController) else {
            return
        }
        
        if isiOSAppOnMac {
            toolbar.frame.origin.y = console.view.frame.size.height-toolbar.frame.size.height
            return
        }
        
        lastKeyboardDidShowNotification = notification
        
        if console.parent?.parent?.modalPresentationStyle != .popover || console.parent?.parent?.view.frame.width != console.parent?.parent?.preferredContentSize.width {
            
            #if MAIN
            let inputAssistantOrigin = inputAssistant.frame.origin
            
            let yPos = inputAssistant.convert(inputAssistantOrigin, to: console.view).y
            
            toolbar.frame.origin = CGPoint(x: console.view.safeAreaInsets.left, y: yPos-toolbar.frame.height)
            
            
            if toolbar.superview != nil,
                !EditorSplitViewController.shouldShowConsoleAtBottom,
                !toolbar.superview!.bounds.intersection(toolbar.frame).equalTo(toolbar.frame) {
                toolbar.frame.origin.y = console.view.frame.height-toolbar.frame.height
            }
            #else
            var r = notification.userInfo![UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
            r = console.textView.convert(r, from:nil)
            toolbar.frame.origin.y = console.view.frame.height-r.height-toolbar.frame.height
            #endif
        }
        
        UIView.animate(withDuration: 0.5) {
            self.toolbar.alpha = 1
        }
        
        console.webView.evaluateJavaScript("sendSize()", completionHandler: nil)
    }
    
    @objc private func keyboardDidHide(_ notification: NSNotification) {
        #if MAIN
        toolbar.frame.origin.y = (console?.view.safeAreaLayoutGuide.layoutFrame.height ?? 0)-toolbar.frame.height
        #else
        toolbar.frame.origin.y = console?.view.safeAreaLayoutGuide.layoutFrame.height ?? 0
        #endif
        
        if textField.isFirstResponder { // Still editing, but with a hardware keyboard
            keyboardDidShow(notification)
        }
        
        UIView.animate(withDuration: 0.5) {
            self.toolbar.alpha = 1
        }
        
        console?.webView.evaluateJavaScript("sendSize()", completionHandler: nil)
    }
    
    private var previousConstraintValue: CGFloat?
    
    @objc private func keyboardWillHide(_ notification: NSNotification) {
        
        guard console?.editorSplitViewController?.superclass?.isSubclass(of: EditorSplitViewController.self) == false else {
            return
        }
        
        if EditorSplitViewController.shouldShowConsoleAtBottom, let previousConstraintValue = previousConstraintValue {
            
            let splitVC = console?.editorSplitViewController
            let constraint = (splitVC?.firstViewHeightRatioConstraint?.isActive == true) ? splitVC?.firstViewHeightRatioConstraint : splitVC?.firstViewHeightConstraint
            
            constraint?.constant = previousConstraintValue
            self.previousConstraintValue = nil
        }
    }
    
    @objc private func keyboardWillShow(_ notification: NSNotification) {
        
        guard console?.editorSplitViewController?.superclass?.isSubclass(of: EditorSplitViewController.self) == false else {
            return
        }
        
        guard let height = (notification.userInfo?["UIKeyboardBoundsUserInfoKey"] as? CGRect)?.height, height > 100 else { // Only software keyboard
            return
        }
        
        if EditorSplitViewController.shouldShowConsoleAtBottom && textField.isFirstResponder {
            
            let splitVC = console?.editorSplitViewController
            
            // I don't know what the fuck I'm doing
            splitVC?.firstViewHeightRatioConstraint?.isActive = false
            
            let constraint = (splitVC?.firstViewHeightRatioConstraint?.isActive == true) ? splitVC?.firstViewHeightRatioConstraint : splitVC?.firstViewHeightConstraint
            
            guard constraint?.constant != 0 else {
                return
            }
            
            previousConstraintValue = constraint?.constant
            constraint?.constant = 0
        }
    }
    
    // MARK: - Text field delegate
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
                
        defer {
            self.handler?(self.textField.text ?? "")
        }
        
        if textField.text?.isEmpty == true {
            textField.resignFirstResponder()
            return true
        }
        
        #if MAIN
        if console?.parent is REPLViewController {
            return false
        } else {
            return !isiOSAppOnMac
        }
        #else
        return false
        #endif
    }
        
    #if MAIN
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        console?.parent?.setNeedsUpdateOfHomeIndicatorAutoHidden()
        
        if isiOSAppOnMac {
            toolbar.frame.origin.y = (console?.view.frame.height ?? 0)-(inputAssistant.frame.height*1.75)
        }
        
        console?.webView.evaluateJavaScript("sendSize()", completionHandler: nil)
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        console?.parent?.setNeedsUpdateOfHomeIndicatorAutoHidden()
        
        if isiOSAppOnMac {
            toolbar.frame.origin.y = console?.view.frame.height ?? 0
        }
        
        console?.webView.evaluateJavaScript("sendSize()", completionHandler: nil)
    }
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        
        if string == "\n" {
            return false
        }
        
        defer {
            if historyIndex == -1 {
                currentInput = (textField.text as NSString?)?.replacingCharacters(in: range, with: string)
            }
            DispatchQueue.main.asyncAfter(deadline: .now()+0.2) { [weak self] in
                self?.didChangeText?(textField.text ?? "")
            }
        }
        
        return true
    }
    #endif
    
    // MARK: - Actions
    
    @objc private func interrupt() {
        placeholder = ""
        textField.resignFirstResponder()
        #if MAIN
        if let path = console?.editorSplitViewController?.editor?.document?.fileURL.path {
            Python.shared.interrupt(script: path)
        }
        #endif
    }
    
    // MARK: - History
    
    /// The current command that is not in the history.
    var currentInput: String?
    
    /// The index of current input in the history. `-1` if the command is not in the history.
    var historyIndex = -1 {
        didSet {
            if historyIndex == -1 {
                textField.text = currentInput
            } else if history.indices.contains(historyIndex) {
                textField.text = history[historyIndex]
            }
        }
    }
    
    /// The history of input. This array is reversed. The first command in the history is the last in this array.
    var history: [String] {
        get {
            return (UserDefaults.standard.array(forKey: "inputHistory") as? [String]) ?? []
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "inputHistory")
        }
    }
    
    /// Scrolls down on the history.
    @objc func down() {
        if historyIndex > -1 {
            historyIndex -= 1
        }
    }
    
    /// Scrolls up on the history.
    @objc func up() {
        if history.indices.contains(historyIndex+1) {
            historyIndex += 1
        }
    }
}
