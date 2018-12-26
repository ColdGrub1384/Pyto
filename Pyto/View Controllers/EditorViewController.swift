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
@objc class EditorViewController: UIViewController, SyntaxTextViewDelegate, InputAssistantViewDelegate, InputAssistantViewDataSource, UITextViewDelegate, INUIAddVoiceShortcutViewControllerDelegate, INUIAddVoiceShortcutButtonDelegate, INUIEditVoiceShortcutViewControllerDelegate {
    
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
    
    /// A Navigation controller containing the documentation.
    var documentationNavigationController: UINavigationController?
    
    /// Shows documentation
    @objc func showDocs(_ sender: UIBarButtonItem) {
        if documentationNavigationController == nil {
            documentationNavigationController = UINavigationController(rootViewController: DocumentationViewController())
        }
        documentationNavigationController?.view.tintColor = UIColor(named: "Tint Color")
        documentationNavigationController?.modalPresentationStyle = .popover
        documentationNavigationController?.popoverPresentationController?.barButtonItem = sender
        present(documentationNavigationController!, animated: true, completion: nil)
    }
    
    private var isDocOpened = false
    
    /// The currently visible editor.
    @objc static var visible: EditorViewController?
    
    /// The bar button item for running script.
    var runBarButtonItem: UIBarButtonItem!
    
    /// The bar button item for stopping script.
    var stopBarButtonItem: UIBarButtonItem!
    
    /// Shows an error at given line.
    ///
    /// - Parameters:
    ///     - lineNumber: The number of the line that caused the error.
    @objc func showErrorAtLine(_ lineNumber: Int) {
        DispatchQueue.main.async {
            guard lineNumber > 0 else {
                return
            }
            
            var lines = [String]()
            let allLines = self.textView.text.components(separatedBy: "\n")
            
            for (i, line) in allLines.enumerated() {
                let currentLineNumber = i+1
                
                guard currentLineNumber <= lineNumber else {
                    break
                }
                
                lines.append(line)
            }
            
            let errorRange = NSRange(location: lines.joined(separator: "\n").count, length: 0)
            
            self.textView.contentTextView.becomeFirstResponder()
            self.textView.contentTextView.selectedRange = errorRange
            
            let errorView = UITextView()
            errorView.textColor = .white
            errorView.isEditable = false
            
            let title = NSAttributedString(string: Python.shared.errorType ?? "", attributes: [
                .font : UIFont(name: "Menlo-Bold", size: UIFont.systemFontSize) ?? UIFont.systemFont(ofSize: UIFont.systemFontSize),
                .foregroundColor: UIColor.white
            ])
            
            let message = NSAttributedString(string: Python.shared.errorReason ?? "", attributes: [
                .font : UIFont(name: "Menlo", size: UIFont.systemFontSize) ?? UIFont.systemFont(ofSize: UIFont.systemFontSize),
                .foregroundColor: UIColor.white
            ])
            
            let attributedText = NSMutableAttributedString(attributedString: title)
            attributedText.append(NSAttributedString(string: "\n\n"))
            attributedText.append(message)
            errorView.attributedText = attributedText
            
            class ErrorViewController: UIViewController, UIAdaptivePresentationControllerDelegate {
                
                func adaptivePresentationStyle(for controller: UIPresentationController) -> UIModalPresentationStyle {
                    return .none
                }
            }
            
            let errorVC = ErrorViewController()
            errorVC.view = errorView
            errorVC.view.backgroundColor = #colorLiteral(red: 0.6743632277, green: 0.1917540668, blue: 0.1914597603, alpha: 1)
            errorVC.preferredContentSize = CGSize(width: 300, height: 100)
            errorVC.modalPresentationStyle = .popover
            errorVC.presentationController?.delegate = errorVC
            errorVC.popoverPresentationController?.backgroundColor = #colorLiteral(red: 0.6743632277, green: 0.1917540668, blue: 0.1914597603, alpha: 1)
            
            if let selectedTextRange = self.textView.contentTextView.selectedTextRange {
                errorVC.popoverPresentationController?.sourceView = self.textView.contentTextView
                errorVC.popoverPresentationController?.sourceRect = self.textView.contentTextView.caretRect(for: selectedTextRange.end)
            } else {
                errorVC.popoverPresentationController?.sourceView = self.textView.contentTextView
                errorVC.popoverPresentationController?.sourceRect = self.textView.contentTextView.bounds
            }
            
            self.present(errorVC, animated: true, completion: nil)
        }
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
        textView.contentTextView.delegate = self
        textView.theme = EditorTheme()
        textView.contentTextView.textColor = .black
        textView.contentTextView.keyboardAppearance = .default
        
        inputAssistant.dataSource = self
        inputAssistant.delegate = self
        inputAssistant.trailingActions = [InputAssistantAction(image: EditorSplitViewController.downArrow, target: textView.contentTextView, action: #selector(textView.contentTextView.resignFirstResponder))]
        inputAssistant.attach(to: textView.contentTextView)
        
        parent?.title = document?.fileURL.deletingPathExtension().lastPathComponent
        
        if document?.fileURL == URL(fileURLWithPath: NSTemporaryDirectory()+"/Temporary") {
            title = nil
        }
        
        runBarButtonItem = UIBarButtonItem(barButtonSystemItem: .play, target: self, action: #selector(run))
        stopBarButtonItem = UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(stop))
        
        let docItem = UIBarButtonItem(barButtonSystemItem: .bookmarks, target: self, action: #selector(showDocs(_:)))
        let scriptsItem = UIBarButtonItem(image: UIImage(named: "Grid"), style: .plain, target: self, action: #selector(close))
        if Python.shared.isScriptRunning {
            parent?.navigationItem.rightBarButtonItem = stopBarButtonItem
        } else {
            parent?.navigationItem.rightBarButtonItem = runBarButtonItem
        }
        parent?.navigationItem.leftBarButtonItems = [scriptsItem, docItem]
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name: UIResponder.keyboardWillHideNotification, object: nil)
        
        textView.contentTextView.isEditable = !isSample
        
        // Siri shortcut
        
        if #available(iOS 12.0, *) {
            let button = INUIAddVoiceShortcutButton(style: .black)
            
            parent?.navigationController?.isToolbarHidden = false
            parent?.toolbarItems = [UIBarButtonItem(customView: button), UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)]
            
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
        
        if !isDocOpened {
            isDocOpened = true
            document?.open(completionHandler: { (_) in
                guard let doc = self.document else {
                    return
                }
                
                self.textView.text = doc.text
                
                if !FileManager.default.isWritableFile(atPath: doc.fileURL.path) {
                    self.navigationItem.leftBarButtonItem = nil
                    self.textView.contentTextView.isEditable = false
                    self.textView.contentTextView.inputAccessoryView = nil
                }
            })
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if EditorViewController.visible != self {
            EditorViewController.visible = self
        }
        
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
        
        let wasFirstResponder = textView.contentTextView.isFirstResponder
        textView.contentTextView.resignFirstResponder()
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in
            self.textView.frame = self.view.safeAreaLayoutGuide.layoutFrame
            if wasFirstResponder {
                self.textView.contentTextView.becomeFirstResponder()
            }
        }) // TODO: Anyway to to it without a timer?
    }
    
    override var keyCommands: [UIKeyCommand]? {
        return [
            UIKeyCommand(input: "r", modifierFlags: .command, action: #selector(run), discoverabilityTitle: Localizable.MenuItems.run),
            UIKeyCommand(input: "w", modifierFlags: .command, action: #selector(close))
        ]
    }
    
    // MARK: - Actions
    
    /// Shares the current script.
    @objc func share(_ sender: UIBarButtonItem) {
        let activityVC = UIActivityViewController(activityItems: [document?.fileURL as Any], applicationActivities: nil)
        activityVC.popoverPresentationController?.barButtonItem = sender
        present(activityVC, animated: true, completion: nil)
    }
    
    /// Stops the current running script.
    @objc func stop() {
        Python.shared.isScriptRunning = false
        ConsoleViewController.visible.textView.resignFirstResponder()
        ConsoleViewController.visible.textView.isEditable = false
    }
    
    /// Run the script represented by `document`.
    @objc func run() {
        save { (_) in
            Python.shared.values = []
            DispatchQueue.main.async {
                if let url = self.document?.fileURL {
                    let console = ConsoleViewController.visible
                    guard console.view.window != nil else {
                        
                        self.present(UINavigationController(rootViewController: console), animated: true, completion: {
                            self.run()
                        })
                        
                        return
                    }
                    
                    console.textView.text = ""
                    console.console = ""
                    console.prompt = ""
                    if Python.shared.isREPLRunning {
                        if Python.shared.isScriptRunning { // A script is already running
                            PyOutputHelper.print(Localizable.Python.alreadyRunning)
                            return
                        }
                        Python.shared.isScriptRunning = true
                        // Import the script
                        PyInputHelper.userInput = "import console as __console__; script = __console__.runScriptAtPath('\(url.path)')"
                    } else {
                        Python.shared.runScript(at: url)
                    }
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
    
    /// The View controller is closed and the document is saved.
    @objc func close() {
        
        stop()
        
        dismiss(animated: true) {
            
            guard !self.isSample else {
                return
            }
            
            self.save(completion: { (success) in
                if !success {
                    let alert = UIAlertController(title: Localizable.Errors.errorWrittingToScript, message: nil, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                    UIApplication.shared.keyWindow?.rootViewController?.present(alert, animated: true, completion: nil)
                }
                self.document?.close(completionHandler: { _ in
                    DispatchQueue.main.async {
                        DocumentBrowserViewController.visible?.collectionView.reloadData()
                    }
                })
            })
        }
    }
    
    /// The doc string to display.
    @objc var docString: String? {
        didSet {
            
            class DocViewController: UIViewController, UIAdaptivePresentationControllerDelegate {
                
                func adaptivePresentationStyle(for controller: UIPresentationController) -> UIModalPresentationStyle {
                    return .none
                }
            }
            
            if presentedViewController != nil, presentedViewController! is DocViewController {
                presentedViewController?.dismiss(animated: false) {
                    self.docString = self.docString
                }
                return
            }
            
            guard docString != nil else {
                return
            }
            
            DispatchQueue.main.async {
                let docView = UITextView()
                docView.textColor = .white
                docView.font = UIFont(name: "Menlo", size: UIFont.systemFontSize)
                docView.isEditable = false
                docView.text = self.docString
                
                let docVC = DocViewController()
                docVC.view = docView
                docVC.view.backgroundColor = .black
                docVC.preferredContentSize = CGSize(width: 300, height: 100)
                docVC.modalPresentationStyle = .popover
                docVC.presentationController?.delegate = docVC
                docVC.popoverPresentationController?.backgroundColor = .black
                
                if let selectedTextRange = self.textView.contentTextView.selectedTextRange {
                    docVC.popoverPresentationController?.sourceView = self.textView.contentTextView
                    docVC.popoverPresentationController?.sourceRect = self.textView.contentTextView.caretRect(for: selectedTextRange.end)
                } else {
                    docVC.popoverPresentationController?.sourceView = self.textView.contentTextView
                    docVC.popoverPresentationController?.sourceRect = self.textView.contentTextView.bounds
                }
                
                self.present(docVC, animated: true, completion: nil)
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
    
    func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        
        docString = nil
        
        return true
    }
    
    // MARK: - Suggestions
    
    /// Returns suggestions for current word.
    @objc var suggestions = [String]() {
        didSet {
            DispatchQueue.main.async {
                self.inputAssistant.reloadData()
            }
        }
    }
    
    /// Returns doc strings per suggestions.
    @objc var docStrings = [String:String]()
    
    /// Updates suggestions.
    func updateSuggestions() {
        
        let textView = self.textView.contentTextView
        
        guard !Python.shared.isScriptRunning, let range = textView.selectedTextRange, let textRange = textView.textRange(from: textView.beginningOfDocument, to: range.end), let text = textView.text(in: textRange) else {
            self.suggestions = []
            return inputAssistant.reloadData()
        }
        
        ConsoleViewController.ignoresInput = true
        PyInputHelper.userInput = [
            "from _codecompletion import suggestForCode",
            "source = '''",
            text,
            "'''",
            "suggestForCode(source, '\(document?.fileURL.path ?? "")')"
        ].joined(separator: ";")
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
            
            let originalSuggestion = suggestions[index]
            var suggestion = originalSuggestion
            
            /*
             "print" -> "print()"
             "print()" -> "print()" NOT "print()" -> "print()()"
            */
            if suggestion.hasSuffix("(") {
                guard
                    let end = textView.contentTextView.position(from: textRange.end, offset: 1),
                    let range = textView.contentTextView.textRange(from: textRange.start, to: end)
                    else {
                    return
                }
                
                if textView.contentTextView.text(in: range)?.hasSuffix("(") == true {
                    suggestion.removeLast()
                }
                
            }
            
            textView.contentTextView.replace(textRange, withText: suggestion)
            
            if suggestion.hasSuffix("(") {
                let range = textView.contentTextView.selectedTextRange
                textView.contentTextView.insertText(")")
                textView.contentTextView.selectedTextRange = range
            }
            
            docString = docStrings[originalSuggestion]
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
        
        if suggestions[index].hasSuffix("(") {
            return suggestions[index]+")"
        }
        
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

