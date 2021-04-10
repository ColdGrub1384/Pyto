//
//  MovableTextField.swift
//  MovableTextField
//
//  Created by Adrian Labbé on 3/30/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
#if MAIN
import InputAssistant
#endif

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
            toolbar.barStyle = .black
        } else {
            toolbar.barStyle = .default
        }
        toolbar.isTranslucent = true
        
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
    let toolbar: UIToolbar
    
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
        toolbar = Bundle(for: MovableTextField.self).loadNibNamed("TextField", owner: nil, options: nil)?.first as! UIToolbar
        textField = toolbar.items!.first!.customView as! UITextField
        
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
        
        #if !Xcode11
        if #available(iOS 14.0, *), !(console.editorSplitViewController is REPLViewController), !(console.editorSplitViewController is RunModuleViewController) {
        } else {
            listenToKeyboardNotifications()
        }
        #else
        listenToKeyboardNotifications()
        #endif
        
        if #available(iOS 14.0, *) {} else {
            NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide(_:)), name: UIResponder.keyboardWillHideNotification, object: nil)
            NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow(_:)), name: UIResponder.keyboardWillShowNotification, object: nil)
        }
    }
    
    /// Shows the text field.
    func show() {
        
        guard let console = console else {
            return
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
    
    @objc private func keyboardDidShow(_ notification: NSNotification) {
        
        // That's the typical code you just cannot understand when you are playing Clash Royale while coding
        // So please, open iTunes, play your playlist, focus and then go back.
        //
        // Edit from 2020: Stop watching TikTok and focus
        //
        // 2021: Ok, so: THIS CODE DOES NOT TOUCHES THE CONSOLE'S TEXTVIEW, IT JUST MOVES THE TEXT BOX. So look at ConsoleViewController.swift if you have a problem with the text view. There's a lot of maths here so I don't really remember how it works but it works so don't touch this.
        
        if console?.parent?.parent?.modalPresentationStyle != .popover || console?.parent?.parent?.view.frame.width != console?.parent?.parent?.preferredContentSize.width {
            
            #if MAIN
            let inputAssistantOrigin = inputAssistant.frame.origin
            
            let yPos = inputAssistant.convert(inputAssistantOrigin, to: console?.view).y
            
            toolbar.frame.origin = CGPoint(x: console?.view.safeAreaInsets.left ?? 0, y: yPos-toolbar.frame.height)
            
            
            if toolbar.superview != nil,
                !EditorSplitViewController.shouldShowConsoleAtBottom,
                !toolbar.superview!.bounds.intersection(toolbar.frame).equalTo(toolbar.frame) {
                toolbar.frame.origin.y = (console?.view.frame.height ?? 0)-toolbar.frame.height
            }
            #else
            var r = notification.userInfo![UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
            r = console?.textView.convert(r, from:nil)
            toolbar.frame.origin.y = console?.view.frame.height-r.height-toolbar.frame.height
            #endif
        }
        
        UIView.animate(withDuration: 0.5) {
            self.toolbar.alpha = 1
        }
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
    }
    
    @objc private func keyboardWillHide(_ notification: NSNotification) {
        UIView.animate(withDuration: 0.5) {
            self.toolbar.alpha = 0
        }
    }
    
    @objc private func keyboardWillShow(_ notification: NSNotification) {
        UIView.animate(withDuration: 0.5) {
            self.toolbar.alpha = 0
        }
    }
    
    // MARK: - Text field delegate
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
                
        defer {
            self.handler?(self.textField.text ?? "")
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
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        console?.parent?.setNeedsUpdateOfHomeIndicatorAutoHidden()
        
        if isiOSAppOnMac {
            toolbar.frame.origin.y = console?.view.frame.height ?? 0
        }
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

