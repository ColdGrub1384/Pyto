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
    
    /// Returns `true` if the opened file is a sample.
    var isSample: Bool {
        guard document != nil else {
            return true
        }
        return !FileManager.default.isWritableFile(atPath: document!.fileURL.path)
    }
    
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
        
        view.addSubview(textView)
        textView.delegate = self
        textView.theme = DefaultSourceCodeTheme()
        view.backgroundColor = textView.theme?.backgroundColor
        
        title = document?.fileURL.lastPathComponent
        
        let saveItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        let runItem = UIBarButtonItem(barButtonSystemItem: .play, target: self, action: #selector(run))
        navigationItem.rightBarButtonItems = [saveItem, runItem]
        if isSample {
            navigationItem.rightBarButtonItems?.append(UIBarButtonItem(barButtonSystemItem: .action, target: self, action: #selector(share(_:))))
        }
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name: UIResponder.keyboardWillHideNotification, object: nil)
        
        textView.contentTextView.isEditable = !isSample
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        document?.open(completionHandler: { (_) in
            self.textView.text = self.document?.text ?? Localizable.Errors.errorReadingFile
        })
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        textView.frame = view.safeAreaLayoutGuide.layoutFrame
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        
        guard view != nil else {
            return
        }
        
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in
            self.textView.frame = self.view.safeAreaLayoutGuide.layoutFrame
        }) // TODO: Anyway to to it without a timer?
    }
    
    // MARK: - Actions
    
    /// Shares the current script.
    @objc func share(_ sender: UIBarButtonItem) {
        let activityVC = UIActivityViewController(activityItems: [document?.fileURL as Any], applicationActivities: nil)
        activityVC.popoverPresentationController?.barButtonItem = sender
        present(activityVC, animated: true, completion: nil)
    }
    
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
                
                guard !self.isSample else {
                    return
                }
                
                self.document?.save(to: self.document!.fileURL, for: .forOverwriting, completionHandler: { success in
                    if !success {
                        let alert = UIAlertController(title: Localizable.Errors.errorWrittingToScript, message: nil, preferredStyle: .alert)
                        alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                        UIApplication.shared.keyWindow?.rootViewController?.present(alert, animated: true, completion: nil)
                    }
                    self.document?.close(completionHandler: { _ in
                        DocumentBrowserViewController.visible?.collectionView.reloadData()
                    })
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

