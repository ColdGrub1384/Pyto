//
//  MarkdownEditorViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import InputAssistant
import SavannaKit
import SourceEditor

/// A View controller for editing plain text.
class PlainTextEditorViewController: UIViewController, UITextViewDelegate {
    
    /// The Text view containing text.
    let textView = SyntaxTextView()
    
    /// The URL of the file to edit.
    var url: URL? {
        didSet {
            if let url = self.url {
                title = url.lastPathComponent
                parent?.title = title
                textView.text = (try? String(contentsOf: url)) ?? ""
                
                textView.contentTextView.isEditable = !isBundled
                
                (parent as? MarkdownSplitViewController)?.previewer.load(markdown: textView.text, baseURL: url.deletingLastPathComponent())
            }
        }
    }
    
    /// Returns `true` if the file is in the app's bundle.
    var isBundled: Bool {
        return (url != nil && url!.path.hasPrefix(Bundle.main.bundlePath))
    }
    
    /// Closes this View controller and saves.
    @objc func close() {
        dismiss(animated: true) {
            do {
                if let url = self.url, !self.isBundled {
                    try self.textView.text.write(to: url, atomically: true, encoding: .utf8)
                }
            } catch {
                let alert = UIAlertController(title: Localizable.Errors.errorWrittingToScript, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                UIApplication.shared.keyWindow?.rootViewController?.present(alert, animated: true, completion: nil)
            }
        }
    }
    
    // MARK: - Theme
    
    /// Setups the View controller interface for given theme.
    ///
    /// - Parameters:
    ///     - theme: The theme to apply.
    func setup(theme: Theme) {
        let text = textView.text
        textView.text = ""
        
        view.backgroundColor = theme.sourceCodeTheme.backgroundColor
        textView.theme = theme.sourceCodeTheme
        textView.contentTextView.textColor = theme.sourceCodeTheme.color(for: .plain)
        textView.contentTextView.keyboardAppearance = theme.keyboardAppearance
        textView.text = text
    }
    
    /// Called when the user choosed a theme.
    @objc func themeDidChange(_ notification: Notification?) {
        setup(theme: ConsoleViewController.choosenTheme)
    }
    
    /// The input assistant view.
    let inputAssistant = InputAssistantView()
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self, selector: #selector(themeDidChange(_:)), name: ThemeDidChangeNotification, object: nil)
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name: UIResponder.keyboardWillHideNotification, object: nil)
        
        ((parent is UINavigationController) ? self : parent)?.navigationItem.leftBarButtonItem = UIBarButtonItem(image: EditorSplitViewController.gridImage, style: .plain, target: self, action: #selector(close))
        
        inputAssistant.trailingActions = [InputAssistantAction(image: EditorSplitViewController.downArrow, target: textView.contentTextView, action: #selector(textView.contentTextView.resignFirstResponder))]
        inputAssistant.attach(to: textView.contentTextView)
        textView.backgroundColor = .clear
        textView.contentTextView.delegate = self
        view.addSubview(textView)
        
        textView.contentTextView.becomeFirstResponder()
        DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
            self.textView.contentTextView.resignFirstResponder()
        }
        
        setup(theme: ConsoleViewController.choosenTheme)
    }
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        themeDidChange(nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
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
    
    /// Resize `textView`.
    @objc func keyboardWillShow(_ notification:Notification) {
        let d = notification.userInfo!
        var r = d[UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
        
        r = textView.convert(r, from:nil)
        textView.frame.size.height -= r.size.height
    }
    
    /// Set `textView` to the default size.
    @objc func keyboardWillHide(_ notification:Notification) {
        textView.frame = view.safeAreaLayoutGuide.layoutFrame
    }
    
    // MARK: - Text view delegate
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        textView.contentTextView.setNeedsDisplay()
    }
    
    func textViewDidChangeSelection(_ textView: UITextView) {
        return self.textView.textViewDidChangeSelection(textView)
    }
    
    func textViewDidChange(_ textView: UITextView) {
        return self.textView.textViewDidChange(textView)
    }
    
    func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        
        defer {
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                if let url = self.url {
                    try? textView.text.write(to: url, atomically: true, encoding: .utf8)
                }
                
                (self.parent as? MarkdownSplitViewController)?.previewer.load(markdown: textView.text, baseURL: self.url?.deletingLastPathComponent())
            }
        }
        
        return true
    }
}
