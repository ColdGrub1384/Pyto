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
import InputAssistant
import IntentsUI
import CoreSpotlight

/// The View controller used to edit source code.
class EditorViewController: UIViewController, SyntaxTextViewDelegate, InputAssistantViewDelegate, InputAssistantViewDataSource, UITextViewDelegate, INUIAddVoiceShortcutViewControllerDelegate, INUIAddVoiceShortcutButtonDelegate, INUIEditVoiceShortcutViewControllerDelegate {
    
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
    
    /// The Input assistant view containing `suggestions`.
    let inputAssistant = InputAssistantView()
    
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
        textView.contentTextView.delegate = self
        textView.theme = DefaultSourceCodeTheme()
        view.backgroundColor = textView.theme?.backgroundColor
        
        inputAssistant.dataSource = self
        inputAssistant.delegate = self
        inputAssistant.attach(to: textView.contentTextView)
        
        title = document?.fileURL.deletingPathExtension().lastPathComponent
        
        if document?.fileURL == URL(fileURLWithPath: NSTemporaryDirectory()+"/Temporary") {
            title = nil
        }
        
        let saveItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        let runItem = UIBarButtonItem(barButtonSystemItem: .play, target: self, action: #selector(run))
        navigationItem.rightBarButtonItems = [saveItem, runItem]
        if isSample {
            navigationItem.rightBarButtonItems?.append(UIBarButtonItem(barButtonSystemItem: .action, target: self, action: #selector(share(_:))))
        }
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name: UIResponder.keyboardWillHideNotification, object: nil)
        
        textView.contentTextView.isEditable = !isSample
        
        // Siri shortcut
        
        if #available(iOS 12.0, *) {
            let button = INUIAddVoiceShortcutButton(style: .blackOutline)
            
            navigationItem.leftBarButtonItem = UIBarButtonItem(customView: button)
            
            button.addConstraints([NSLayoutConstraint(item: button, attribute: .width, relatedBy: .equal, toItem: nil, attribute: .notAnAttribute, multiplier: 1.0, constant: 130), NSLayoutConstraint(item: button, attribute: .height, relatedBy: .equal, toItem: nil, attribute: .notAnAttribute, multiplier: 1.0, constant: 40)])
            
            let filePath: String?
            if let url = document?.fileURL {
                filePath = RelativePathForScript(url)
            } else {
                filePath = nil
            }
            
            let attributes = CSSearchableItemAttributeSet(itemContentType: "public.item")
            attributes.contentDescription = document?.fileURL.lastPathComponent
            attributes.kind = "Python Script"
            let activity = NSUserActivity(activityType: "ch.marcela.ada.Pyto.script")
            activity.title = "Run \(title ?? "script")"
            activity.contentAttributeSet = attributes
            activity.isEligibleForSearch = true
            activity.isEligibleForPrediction = true
            activity.keywords = ["python", "pyto", "run", "script", title ?? "Untitled"]
            activity.requiredUserInfoKeys = ["filePath"]
            activity.persistentIdentifier = filePath
            attributes.relatedUniqueIdentifier = filePath
            attributes.identifier = filePath
            attributes.domainIdentifier = filePath
            userActivity = activity
            if let path = filePath {
                activity.addUserInfoEntries(from: ["filePath" : path])
                activity.suggestedInvocationPhrase = document?.fileURL.deletingPathExtension().lastPathComponent
            }
            button.shortcut = INShortcut(userActivity: activity)
            button.delegate = self
        }
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
        
        let wasFirstResponder = textView.contentTextView.isFirstResponder
        textView.contentTextView.resignFirstResponder()
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in
            self.textView.frame = self.view.safeAreaLayoutGuide.layoutFrame
            if wasFirstResponder {
                self.textView.contentTextView.becomeFirstResponder()
            }
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
    
    // MARK: - Text view delegate
    
    func textViewDidChangeSelection(_ textView: UITextView) {
        if textView.isFirstResponder {
            updateSuggestions()
        }
        return self.textView.textViewDidChangeSelection(textView)
    }
    
    func textViewDidChange(_ textView: UITextView) {
        updateSuggestions()
        return self.textView.textViewDidChange(textView)
    }
    
    func textViewDidBeginEditing(_ textView: UITextView) {
        updateSuggestions()
    }
    
    // MARK: - Suggestions
    
    /// All supported suggestions.
    static var suggestions: [String] {
        
        let operators = ["=", "+=", "-=", "/=", "*=", "%=", "**=", "//=", "+", "-", "*", "/", "**", "//", "%", "<", ">", "<=", ">=", "==", "!="]
        
        let constants = ["True", "False", "None"]
        
        let definitions = ["import", "def", "class", "global", "nonlocal", "del", "as", "from"]
        
        let statements = ["while", "for", "lambda", "in", "return", "continue", "pass", "break", "try", "except", "finally", "raise", "assert", "with", "yield"]
        
        let conditions = ["if", "else", "elif", "not", "or", "is", "and"]
        
        return [":"]+operators+constants+definitions+statements+conditions
    }
    
    /// Returns suggestions for current word.
    var suggestions = [String]()
    
    /// Updates suggestions.
    func updateSuggestions() {
        
        guard let selectedWord = textView.contentTextView.currentWord, !selectedWord.isEmpty else {
            self.suggestions = EditorViewController.suggestions
            return inputAssistant.reloadData()
        }
        
        var suggestions = EditorViewController.suggestions
        func checkForSuggestions() {
            for suggestion in suggestions.enumerated() {
                if !suggestion.element.contains(selectedWord) {
                    suggestions.remove(at: suggestion.offset)
                    checkForSuggestions()
                    break
                }
            }
        }
        checkForSuggestions()
        
        self.suggestions = suggestions
        inputAssistant.reloadData()
    }
    
    // MARK: - Syntax text view delegate

    func didChangeText(_ syntaxTextView: SyntaxTextView) {
        document?.text = textView.text
    }
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
    
    func lexerForSource(_ source: String) -> Lexer {
        return Python3Lexer()
    }
    
    // MARK: - Input assistant view delegate
    
    func inputAssistantView(_ inputAssistantView: InputAssistantView, didSelectSuggestionAtIndex index: Int) {
        
        if let textRange = textView.contentTextView.currentWordRange {
            textView.contentTextView.replace(textRange, withText: suggestions[index])
        }
    }
    
    // MARK: - Input assistant view data source
    
    func textForEmptySuggestionsInInputAssistantView() -> String? {
        return nil
    }
    
    func numberOfSuggestionsInInputAssistantView() -> Int {
        return suggestions.count
    }
    
    func inputAssistantView(_ inputAssistantView: InputAssistantView, nameForSuggestionAtIndex index: Int) -> String {
        return suggestions[index]
    }
    
    // MARK: - Siri shortcuts
    
    // MARK: - Add voice shortcut view controller delegate
    
    @available(iOS 12.0, *)
    func addVoiceShortcutViewControllerDidCancel(_ controller: INUIAddVoiceShortcutViewController) {
        dismiss(animated: true, completion: nil)
    }
    
    @available(iOS 12.0, *)
    func addVoiceShortcutViewController(_ controller: INUIAddVoiceShortcutViewController, didFinishWith voiceShortcut: INVoiceShortcut?, error: Error?) {
        dismiss(animated: true) {
            if let error = error {
                let alert = UIAlertController(title: nil, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
                self.present(alert, animated: true, completion: nil)
            }
        }
    }
    
    // MARK: - Add voice shortcut button delegate
    
    @available(iOS 12.0, *)
    func present(_ addVoiceShortcutViewController: INUIAddVoiceShortcutViewController, for addVoiceShortcutButton: INUIAddVoiceShortcutButton) {
        
        addVoiceShortcutViewController.delegate = self
        addVoiceShortcutViewController.modalPresentationStyle = .formSheet
        present(addVoiceShortcutViewController, animated: true, completion: nil)
    }
    
    @available(iOS 12.0, *)
    func present(_ editVoiceShortcutViewController: INUIEditVoiceShortcutViewController, for addVoiceShortcutButton: INUIAddVoiceShortcutButton) {
        
        editVoiceShortcutViewController.delegate = self
        editVoiceShortcutViewController.modalPresentationStyle = .formSheet
        present(editVoiceShortcutViewController, animated: true, completion: nil)
    }
    
    // MARK: - Edit voice shortcut view controller delegetae
    
    @available(iOS 12.0, *)
    func editVoiceShortcutViewController(_ controller: INUIEditVoiceShortcutViewController, didUpdate voiceShortcut: INVoiceShortcut?, error: Error?) {
        dismiss(animated: true) {
            if let error = error {
                let alert = UIAlertController(title: nil, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
                self.present(alert, animated: true, completion: nil)
            }
        }
    }
    
    @available(iOS 12.0, *)
    func editVoiceShortcutViewController(_ controller: INUIEditVoiceShortcutViewController, didDeleteVoiceShortcutWithIdentifier deletedVoiceShortcutIdentifier: UUID) {
        dismiss(animated: true, completion: nil)
    }
    
    @available(iOS 12.0, *)
    func editVoiceShortcutViewControllerDidCancel(_ controller: INUIEditVoiceShortcutViewController) {
        dismiss(animated: true, completion: nil)
    }
}

