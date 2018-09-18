//
//  ConsoleViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller containing Python script output.
class ConsoleViewController: UIViewController, UITextViewDelegate {
    
    private var console = ""
    private var prompt = ""
    private var askingForInput = false
    
    /// The Text view containing the console.
    var textView: ConsoleTextView!
    
    /// Add the content of the given notification as `String` to `textView`. Called when the stderr changed or when a script printed from the Pyto module's `print` function`.
    ///
    /// - Parameters:
    ///     - notification: Its associated object should be the `String` added to `textView`.
    @objc func print_(_ notification: Notification) {
        if let output = notification.object as? String {
            DispatchQueue.main.async {
                if output == "PytoRemoveConsoleContent" {
                    self.textView?.text = ""
                    self.textViewDidChange(self.textView)
                } else {
                    self.textView?.text.append(output)
                    self.textViewDidChange(self.textView)
                }
            }
        }
    }
    
    /// Requests the user for input.
    ///
    /// - Parameters:
    ///     - prompt: The prompt from the Python function
    func input(prompt: String) {
        textView.text += prompt
        Python.shared.output += prompt
        textViewDidChange(textView)
        askingForInput = true
        textView.isEditable = true
        textView.becomeFirstResponder()
    }
    
    /// Closes the View controller.
    @objc func close() {
        extensionContext?.completeRequest(returningItems: nil, completionHandler: nil)
        dismiss(animated: true, completion: nil)        
    }
    
    deinit {        
        NotificationCenter.default.removeObserver(self)
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = "Console"
        textView = ConsoleTextView(frame: view.frame)
        textView.autoresizingMask = [.flexibleHeight, .flexibleWidth]
        textView.delegate = self
        view.addSubview(textView)
        
        navigationItem.rightBarButtonItems = [UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))]
        
        NotificationCenter.default.addObserver(self, selector: #selector(print_(_:)), name: .init(rawValue: "DidReceiveOutput"), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name:UIResponder.keyboardWillHideNotification, object: nil)
    }
    
    // MARK: - Keyboard
    
    @objc func keyboardWillShow(_ notification:Notification) {
        let d = notification.userInfo!
        var r = d[UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
        
        r = textView.convert(r, from:nil)
        textView.contentInset.bottom = r.size.height+50
        textView.scrollIndicatorInsets.bottom = r.size.height+50
    }
    
    @objc func keyboardWillHide(_ notification:Notification) {
        textView.contentInset = .zero
        textView.scrollIndicatorInsets = .zero
    }
    
    // MARK: - Text view delegate
    
    func textViewDidChange(_ textView: UITextView) {
        if !askingForInput {
            console = textView.text
        }
    }
    
    func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        
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
                textView.text += "\n"
                PyInputHelper.userInput = prompt
                Python.shared.output += prompt
                prompt = ""
                askingForInput = false
                textView.isEditable = false
                textView.resignFirstResponder()
                
                return false
            } else if text == "" && range.length == 1 {
                prompt = String(prompt.dropLast())
            }
            
            return true
        }
        
        return false
    }
}
