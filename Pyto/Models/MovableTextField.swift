//
//  MovableTextField.swift
//  MovableTextField
//
//  Created by Adrian Labbé on 3/30/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import InputAssistant

/// A class for managing a movable text field.
class MovableTextField: NSObject, UITextFieldDelegate {
    
    /// The view containing this text field.
    let console: ConsoleViewController
    
    /// The placeholder of the text field.
    var placeholder = "" {
        didSet {
            textField.placeholder = placeholder
        }
    }
    
    private func applyTheme() {
        textField.keyboardAppearance = theme.keyboardAppearance
        if textField.keyboardAppearance == .dark {
            toolbar.barStyle = .black
        } else {
            toolbar.barStyle = .default
        }
    }
    
    /// Theme used by the bar.
    var theme: Theme = ConsoleViewController.choosenTheme {
        didSet {
            applyTheme()
        }
    }
    
    /// The toolbar containing the text field
    let toolbar: UIToolbar
    
    /// The text field.
    let textField: UITextField
        
    /// Initializes the manager.
    ///
    /// - Parameters:
    ///     - console: The console containing the text field.
    init(console: ConsoleViewController) {
        self.console = console
        toolbar = Bundle(for: MovableTextField.self).loadNibNamed("TextField", owner: nil, options: nil)?.first as! UIToolbar
        textField = toolbar.items!.first!.customView as! UITextField
        
        super.init()
        
        applyTheme()
        
        textField.delegate = self
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow(_:)), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide(_:)), name: UIResponder.keyboardWillHideNotification, object: nil)
    }
    
    /// Shows the text field.
    func show() {
        toolbar.frame.size.width = console.view.frame.width
        toolbar.frame.origin.x = 0
        toolbar.frame.origin.y = console.view.safeAreaLayoutGuide.layoutFrame.height-toolbar.frame.height
        toolbar.autoresizingMask = [.flexibleWidth, .flexibleBottomMargin, .flexibleTopMargin]
        console.view.addSubview(toolbar)
    }
    
    /// Shows keyboard.
    func focus() {
        guard console.shouldRequestInput else {
            return
        }
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
            self.textField.becomeFirstResponder()
        }
    }
    
    /// Code called when text is sent. Receives the text.
    var handler: ((String) -> Void)?
    
    // MARK: - Keyboard
    
    @objc private func keyboardWillShow(_ notification: NSNotification) {
        if let keyboardFrame = (notification.userInfo?[UIResponder.keyboardFrameEndUserInfoKey] as? NSValue)?.cgRectValue {
            let point = CGPoint(x: 0, y: (UIApplication.shared.keyWindow ?? console.view).frame.height-keyboardFrame.height-toolbar.frame.height)
            toolbar.frame.origin = (UIApplication.shared.keyWindow ?? console.view).convert(point, to: console.view)
        }
    }
    
    @objc private func keyboardWillHide(_ notification: NSNotification) {
        toolbar.frame.origin.y = console.view.safeAreaLayoutGuide.layoutFrame.height-toolbar.frame.height
    }
    
    // MARK: - Text field delegate
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        
        textField.resignFirstResponder()
        
        defer {
            handler?(textField.text ?? "")
            placeholder = ""
            textField.text = ""
        }
        
        return true
    }
}
