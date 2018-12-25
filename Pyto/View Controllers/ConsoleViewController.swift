//
//  ConsoleViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import TZKeyboardPop

/// A View controller containing Python script output.
class ConsoleViewController: UIViewController, UITextViewDelegate, TZKeyboardPopDelegate {
        
    /// The Text view containing the console.
    @objc var textView: ConsoleTextView!
    
    /// If set to `true`, the user will not be able to input.
    var ignoresInput = false
    
    /// The keyboard used for sending input.
    var keyboard: TZKeyboardPop!
    
    /// The prompt passed via `input(prompt)`.
    var prompt: String?
    
    /// If set to `true`, the user will not be able to input.
    @objc static var ignoresInput = false
    
    /// Add the content of the given notification as `String` to `textView`. Called when the stderr changed or when a script printed from the Pyto module's `print` function`.
    ///
    /// - Parameters:
    ///     - notification: Its associated object should be the `String` added to `textView`.
    @objc func print_(_ notification: Notification) {
        if let output = notification.object as? String {
            DispatchQueue.main.async {
                self.textView?.text.append(output)
                self.textView?.scrollToBottom()
            }
        }
    }
    
    /// Requests the user for input.
    ///
    /// - Parameters:
    ///     - prompt: The prompt from the Python function
    func input(prompt: String) {
        
        guard (!ignoresInput && !ConsoleViewController.ignoresInput) || self is REPLViewController else {
            ignoresInput = false
            ConsoleViewController.ignoresInput = false
            return
        }
        
        self.prompt = prompt
        
        if keyboard == nil {
            keyboard = TZKeyboardPop(view: UIApplication.shared.keyWindow ?? view)
        }
        keyboard.setTextFieldTextViewMode(.never)
        keyboard.setPlaceholderText(prompt)
        keyboard.delegate = self
        keyboard._mytextField.font = textView.font?.withSize(17)
        keyboard._mytextField.autocapitalizationType = .none
        keyboard._mytextField.autocorrectionType = .no
        keyboard._mytextField.smartDashesType = .no
        keyboard._mytextField.smartQuotesType = .no
        keyboard.setTextFieldText("")
        keyboard.showKeyboard()
    }
    
    /// Closes the View controller or dismisses keyboard.
    @objc func close() {
        
        if textView.isFirstResponder {
            textView.resignFirstResponder()
        } else {
            extensionContext?.completeRequest(returningItems: nil, completionHandler: nil)
            dismiss(animated: true, completion: nil)
        }
    }
    
    /// The currently visible console.
    static var visible: ConsoleViewController?
    
    deinit {        
        NotificationCenter.default.removeObserver(self)
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()

        edgesForExtendedLayout = []
        
        title = Localizable.console
        
        textView = ConsoleTextView()
        textView.delegate = self
        textView.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(textView)
        
        NotificationCenter.default.addObserver(self, selector: #selector(print_(_:)), name: .init(rawValue: "DidReceiveOutput"), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name:UIResponder.keyboardWillHideNotification, object: nil)        
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        ConsoleViewController.visible = self
        
        textView.frame = view.safeAreaLayoutGuide.layoutFrame
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        
        guard view != nil else {
            return
        }
        
        guard view.frame.height != size.height else {
            textView.frame.size.width = self.view.safeAreaLayoutGuide.layoutFrame.width
            return
        }
    }
    
    override var keyCommands: [UIKeyCommand]? {
        return [
            UIKeyCommand(input: "w", modifierFlags: .command, action: #selector(close))
        ]
    }
    
    // MARK: - Text view delegate
    
    func textViewShouldBeginEditing(_ textView: UITextView) -> Bool {
        
        if let prompt = prompt {
            input(prompt: prompt)
        }
        
        return false
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
    
    // MARK: - Keyboard pop delegate
    
    func didReturnKeyPressed(withText str: String!) {
        PyInputHelper.userInput = str
        prompt = nil
    }
}
