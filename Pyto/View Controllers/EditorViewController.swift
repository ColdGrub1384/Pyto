//
//  ViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SourceEditor
import SavannaKit

/// The View controller used to edit source code.
class EditorViewController: UIViewController, SyntaxTextViewDelegate {
    
    /// The `SyntaxTextView` containing the code.
    let textView = SyntaxTextView()
    
    /// The document to be edited.
    var document: PyDocument?
    
    /// Initialize with given document.
    ///
    /// - Parameters:
    ///     - document: The document to be edited.
    init(document: PyDocument) {
        super.init(nibName: nil, bundle: nil)
        self.document = document
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        textView.frame = view.frame
        textView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.addSubview(textView)
        textView.delegate = self
        textView.theme = DefaultSourceCodeTheme()
        
        title = document?.fileURL.lastPathComponent
        
        document?.open(completionHandler: { (_) in
            self.textView.text = self.document?.text ?? "Error reading file"
        })
        
        let saveItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        let runItem = UIBarButtonItem(barButtonSystemItem: .play, target: self, action: #selector(run))
        navigationItem.rightBarButtonItems = [saveItem, runItem]
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name: UIResponder.keyboardWillHideNotification, object: nil)
    }
    
    // MARK: - Actions
    
    /// Run the script represented by `document`.
    @objc func run() {
        save { (_) in
            DispatchQueue.main.async {
                if let url = self.document?.fileURL {
                    PyContentViewController.scriptToRun = url
                    self.navigationController?.tabBarController?.selectedIndex = 1
                }
            }
        }
    }
    
    /// Save the document on a background queue.
    ///
    /// - Parameters:
    ///     - completion: The code executed when the file was saved. A boolean indicated if the file was successfully saved is passed.
    @objc func save(completion: ((Bool) -> Void)? = nil) {
        DispatchQueue.global().async {
            self.document?.save(to: self.document!.fileURL, for: .forOverwriting, completionHandler: completion)
        }
    }
    
    /// If the keyboard is shown, the keyboard is dissmiss and if not, the View controller is closed and the document is saved.
    @objc func close() {
        if textView.contentTextView.isFirstResponder {
            textView.contentTextView.resignFirstResponder()
        } else {
            dismiss(animated: true) {
                self.document?.save(to: self.document!.fileURL, for: .forOverwriting, completionHandler: { success in
                    if !success {
                        let alert = UIAlertController(title: "Error writting to script", message: "Cannot save the contents of '\(self.document!.fileURL.lastPathComponent)'", preferredStyle: .alert)
                        alert.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
                        UIApplication.shared.keyWindow?.rootViewController?.present(alert, animated: true, completion: nil)
                    }
                    self.document?.close(completionHandler: nil)
                })
            }
        }
    }
    
    // MARK: - Keyboard
    
    /// Resize `textView`.
    @objc func keyboardWillShow(_ notification:Notification) {
        let d = notification.userInfo!
        var r = d[UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
        
        r = textView.convert(r, from:nil)
        textView.contentInset.bottom = r.size.height
        textView.contentTextView.scrollIndicatorInsets.bottom = r.size.height
    }
    
    /// Set `textView` to the default size.
    @objc func keyboardWillHide(_ notification:Notification) {
        textView.contentInset = .zero
        textView.contentTextView.scrollIndicatorInsets = .zero
    }
    
    // MARK: - Syntax text view delegate

    func didChangeText(_ syntaxTextView: SyntaxTextView) {
        document?.text = textView.text
    }
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
    
    func lexerForSource(_ source: String) -> Lexer {
        return Python3Lexer()
    }
}

