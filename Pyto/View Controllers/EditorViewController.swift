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

fileprivate func parseArgs(_ args: inout [String]) {
    
    enum QuoteType: String {
        case double = "\""
        case single = "'"
    }
    
    func parseArgs(_ args: inout [String], quoteType: QuoteType) {
        
        var parsedArgs = [String]()
        
        var currentArg = ""
        
        for arg in args {
            
            if arg.hasPrefix("\(quoteType.rawValue)") {
                
                if currentArg.isEmpty {
                    
                    currentArg = arg
                    currentArg.removeFirst()
                    
                } else {
                    
                    currentArg.append(" " + arg)
                    
                }
                
            } else if arg.hasSuffix("\(quoteType.rawValue)") {
                
                if currentArg.isEmpty {
                    
                    currentArg.append(arg)
                    
                } else {
                    
                    currentArg.append(" " + arg)
                    currentArg.removeLast()
                    parsedArgs.append(currentArg)
                    currentArg = ""
                    
                }
                
            } else {
                
                if currentArg.isEmpty {
                    parsedArgs.append(arg)
                } else {
                    currentArg.append(" " + arg)
                }
                
            }
        }
        
        if !currentArg.isEmpty {
            if currentArg.hasSuffix("\(quoteType.rawValue)") {
                currentArg.removeLast()
            }
            parsedArgs.append(currentArg)
        }
        
        args = parsedArgs
    }
    
    parseArgs(&args, quoteType: .single)
    parseArgs(&args, quoteType: .double)
}


/// The View controller used to edit source code.
@objc class EditorViewController: UIViewController, SyntaxTextViewDelegate, InputAssistantViewDelegate, InputAssistantViewDataSource, UITextViewDelegate, UISearchBarDelegate {
    
    /// Returns string used for indentation
    static var indentation: String {
        get {
            return UserDefaults.standard.string(forKey: "indentation") ?? "  "
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "indentation")
            UserDefaults.standard.synchronize()
        }
    }
    
    /// The `SyntaxTextView` containing the code.
    let textView = SyntaxTextView()
    
    /// The document URL to be edited.
    var document: URL?
    
    /// Returns `true` if the opened file is a sample.
    var isSample: Bool {
        guard document != nil else {
            return true
        }
        return !FileManager.default.isWritableFile(atPath: document!.path)
    }
    
    /// The Input assistant view containing `suggestions`.
    let inputAssistant = InputAssistantView()
    
    /// A Navigation controller containing the documentation.
    var documentationNavigationController: ThemableNavigationController?
    
    /// Shows documentation
    @objc func showDocs(_ sender: UIBarButtonItem) {
        if documentationNavigationController == nil {
            documentationNavigationController = ThemableNavigationController(rootViewController: DocumentationViewController())
        }
        documentationNavigationController?.modalPresentationStyle = .popover
        documentationNavigationController?.popoverPresentationController?.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        documentationNavigationController?.popoverPresentationController?.barButtonItem = sender
        documentationNavigationController?.preferredContentSize = CGSize(width: 400, height: 400)
        present(documentationNavigationController!, animated: true, completion: nil)
    }
    
    /// Inserts two spaces.
    @objc func insertTab() {
        textView.contentTextView.insertText(EditorViewController.indentation)
    }
    
    private var isSaving = false
    
    private var isDocOpened = false
    
    /// The line number where an error occurred. If this value is set at `viewDidAppear(_:)`, the error will be shown and the value will be reset to `nil`.
    var lineNumberError: Int?
    
    /// Arguments passed to the script.
    var args = ""
    
    /// Set to `true` before presenting to run the code.
    var shouldRun = false
    
    /// Initialize with given document.
    ///
    /// - Parameters:
    ///     - document: The document URL to be edited.
    init(document: URL) {
        super.init(nibName: nil, bundle: nil)
        self.document = document
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    // MARK: - Bar button items
    
    /// The bar button item for running script.
    var runBarButtonItem: UIBarButtonItem!
    
    /// The bar button item for stopping script.
    var stopBarButtonItem: UIBarButtonItem!
    
    /// The bar button item for showing docs.
    var docItem: UIBarButtonItem!
    
    /// The bar button item for setting arguments.
    var argsItem: UIBarButtonItem!
    
    /// The bar button item for sharing the script.
    var shareItem: UIBarButtonItem!
    
    /// Button for searching for text in the editor.
    var searchItem: UIBarButtonItem!
    
    /// Button for going back to scripts.
    var scriptsItem: UIBarButtonItem!
    
    // MARK: - Theme
    
    /// Setups the View controller interface for given theme.
    ///
    /// - Parameters:
    ///     - theme: The theme to apply.
    func setup(theme: Theme) {
        
        textView.contentTextView.inputAccessoryView = nil
        
        let text = textView.text
        textView.delegate = nil
        textView.text = ""
        textView.delegate = self
        textView.theme = theme.sourceCodeTheme
        textView.contentTextView.textColor = theme.sourceCodeTheme.color(for: .plain)
        textView.contentTextView.keyboardAppearance = theme.keyboardAppearance
        textView.text = text
        
        inputAssistant.leadingActions = (UIApplication.shared.statusBarOrientation.isLandscape ? [InputAssistantAction(image: UIImage())] : [])+[InputAssistantAction(image: "⇥".image() ?? UIImage(), target: self, action: #selector(insertTab))]
        inputAssistant.attach(to: textView.contentTextView)
        inputAssistant.trailingActions = [InputAssistantAction(image: EditorSplitViewController.downArrow, target: textView.contentTextView, action: #selector(textView.contentTextView.resignFirstResponder))]+(UIApplication.shared.statusBarOrientation.isLandscape ? [InputAssistantAction(image: UIImage())] : [])
    }
    
    /// Called when the user choosed a theme.
    @objc func themeDidChange(_ notification: Notification) {
        setup(theme: ConsoleViewController.choosenTheme)
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self, selector: #selector(themeDidChange(_:)), name: ThemeDidChangeNotification, object: nil)
        
        view.addSubview(textView)
        textView.delegate = self
        textView.contentTextView.delegate = self
        
        inputAssistant.dataSource = self
        inputAssistant.delegate = self
        
        parent?.title = document?.deletingPathExtension().lastPathComponent
        
        if document == URL(fileURLWithPath: NSTemporaryDirectory()+"/Temporary") {
            title = nil
        }
        
        argsItem = UIBarButtonItem(title: "args", style: .plain, target: self, action: #selector(setArgs(_:)))
        runBarButtonItem = UIBarButtonItem(barButtonSystemItem: .play, target: self, action: #selector(run))
        stopBarButtonItem = UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(stop))
        
        let debugButton = UIButton(frame: CGRect(x: 0, y: 0, width: 30, height: 30))
        debugButton.addTarget(self, action: #selector(debug), for: .touchUpInside)
        let debugItem = UIBarButtonItem(image: UIImage(named: "Debug"), style: .plain, target: self, action: #selector(debug))
        
        let scriptsButton = UIButton(frame: CGRect(x: 0, y: 0, width: 30, height: 30))
        scriptsButton.setImage(UIImage(named: "Grid"), for: .normal)
        scriptsButton.addTarget(self, action: #selector(close), for: .touchUpInside)
        scriptsItem = UIBarButtonItem(customView: scriptsButton)
        
        let searchButton = UIButton(frame: CGRect(x: 0, y: 0, width: 30, height: 30))
        searchButton.setImage(UIImage(imageLiteralResourceName: "search"), for: .normal)
        searchButton.addTarget(self, action: #selector(search), for: .touchUpInside)
        searchItem = UIBarButtonItem(customView: searchButton)
        
        docItem = UIBarButtonItem(barButtonSystemItem: .bookmarks, target: self, action: #selector(showDocs(_:)))
        shareItem = UIBarButtonItem(barButtonSystemItem: .action, target: self, action: #selector(share(_:)))
        
        if Python.shared.isScriptRunning {
            parent?.navigationItem.rightBarButtonItems = [
                stopBarButtonItem,
                debugItem,
            ]
        } else {
            parent?.navigationItem.rightBarButtonItems = [
                runBarButtonItem,
                debugItem,
            ]
        }
        parent?.navigationItem.leftBarButtonItems = [scriptsItem, searchItem]
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name: UIResponder.keyboardWillHideNotification, object: nil)
        
        textView.contentTextView.isEditable = !isSample
        
        parent?.navigationController?.isToolbarHidden = false
        parent?.toolbarItems = [shareItem, docItem, UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil), argsItem]
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        setup(theme: ConsoleViewController.choosenTheme)
        
        if !isDocOpened {
            isDocOpened = true
            
            guard let doc = self.document else {
                return
            }
            
            self.textView.text = (try? String(contentsOf: doc)) ?? ""
            
            if !FileManager.default.isWritableFile(atPath: doc.path) {
                self.navigationItem.leftBarButtonItem = nil
                self.textView.contentTextView.isEditable = false
                self.textView.contentTextView.inputAccessoryView = nil
            }
            
            if self.shouldRun {
                self.shouldRun = false
                if Python.shared.isScriptRunning {
                    self.stop()
                }
                DispatchQueue.main.asyncAfter(deadline: .now()+(Python.shared.isScriptRunning ? 4 : 1)) {
                    self.run()
                }
            }
            
            if doc.path == Bundle.main.path(forResource: "installer", ofType: "py") {
                self.parent?.navigationItem.leftBarButtonItems = []
                if Python.shared.isScriptRunning {
                    self.parent?.navigationItem.rightBarButtonItems = [self.stopBarButtonItem]
                } else {
                    self.parent?.navigationItem.rightBarButtonItems = [self.runBarButtonItem]
                }
            }
            
            // Siri shortcut
            
            if #available(iOS 12.0, *) {
                let filePath: String?
                if let url = document {
                    filePath = RelativePathForScript(url)
                } else {
                    filePath = nil
                }
                
                let attributes = CSSearchableItemAttributeSet(itemContentType: "public.item")
                attributes.contentDescription = document?.lastPathComponent
                attributes.kind = "Python Script"
                let activity = NSUserActivity(activityType: "ch.marcela.ada.Pyto.script")
                activity.title = "Run \(title ?? document?.deletingPathExtension().lastPathComponent ?? "script")"
                activity.contentAttributeSet = attributes
                activity.isEligibleForSearch = true
                activity.isEligibleForPrediction = true
                activity.isEligibleForHandoff = false
                activity.keywords = ["python", "pyto", "run", "script", title ?? "Untitled"]
                activity.requiredUserInfoKeys = ["filePath"]
                activity.persistentIdentifier = filePath
                attributes.relatedUniqueIdentifier = filePath
                attributes.identifier = filePath
                attributes.domainIdentifier = filePath
                userActivity = activity
                if let path = filePath {
                    activity.addUserInfoEntries(from: ["filePath" : path])
                    activity.suggestedInvocationPhrase = document?.deletingPathExtension().lastPathComponent
                }
            }
            
            if Python.shared.isScriptRunning {
                Python.shared.stop()
            }
        }
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
        
        for (_, marker) in breakpointMarkers {
            marker.backgroundColor = .clear
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+1) {
            self.updateBreakpointMarkersPosition()
        }
        
        guard view.frame.height != size.height else {
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                self.textView.frame.size.width = self.view.safeAreaLayoutGuide.layoutFrame.width
            }
            return
        }
        
        let wasFirstResponder = textView.contentTextView.isFirstResponder
        textView.contentTextView.resignFirstResponder()
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in
            self.textView.frame = self.view.safeAreaLayoutGuide.layoutFrame
            if wasFirstResponder {
                self.textView.contentTextView.becomeFirstResponder()
            }
            self.setup(theme: ConsoleViewController.choosenTheme)
        }) // TODO: Anyway to to it without a timer?
    }
    
    // MARK: - Searching
    
    /// Search bar used for searching for code.
    var searchBar: UISearchBar!
    
    /// The height of the find bar.
    var findBarHeight: CGFloat {
        var height = searchBar.frame.height
        if replace {
            height += 30
        }
        return height
    }
    
    /// Set to `true` for replacing text.
    var replace = false {
        didSet {
            
            textView.contentInset.top = findBarHeight
            textView.contentTextView.scrollIndicatorInsets.top = findBarHeight
            
            if replace {
                if let replaceView = Bundle.main.loadNibNamed("Replace", owner: nil, options: nil)?.first as? ReplaceView {
                    replaceView.frame.size.width = view.frame.width
                    replaceView.frame.origin.y = searchBar.frame.height
                    
                    
                    replaceView.replaceHandler = { searchText in
                        if let range = self.ranges.first {
                            
                            var text = self.textView.text
                            text = (text as NSString).replacingCharacters(in: range, with: searchText)
                            self.textView.text = text
                            
                            self.performSearch()
                        }
                    }
                    
                    replaceView.replaceAllHandler = { searchText in
                        while let range = self.ranges.first {
                            
                            var text = self.textView.text
                            text = (text as NSString).replacingCharacters(in: range, with: searchText)
                            self.textView.text = text
                            
                            self.performSearch()
                        }
                    }
                    
                    replaceView.autoresizingMask = [.flexibleWidth]
                    
                    view.addSubview(replaceView)
                }
                textView.contentTextView.setContentOffset(CGPoint(x: 0, y: textView.contentTextView.contentOffset.y-30), animated: true)
            } else {
                for view in view.subviews {
                    if let replaceView = view as? ReplaceView {
                        replaceView.removeFromSuperview()
                    }
                }
                textView.contentTextView.setContentOffset(CGPoint(x: 0, y: textView.contentTextView.contentOffset.y+30), animated: true)
            }
        }
    }
    
    /// Set to `true` for ignoring case.
    var ignoreCase = true
    
    /// Search mode.
    enum SearchMode {
        
        /// Contains typed text.
        case contains
        
        /// Starts with typed text.
        case startsWith
        
        /// Full word.
        case fullWord
    }
    
    /// Applied search mode.
    var searchMode = SearchMode.contains
    
    /// Found ranges.
    var ranges = [NSRange]()
    
    /// Searches for text in code.
    @objc func search() {
        
        guard searchBar?.window == nil else {
            
            
            replace = false
            
            searchBar.removeFromSuperview()
            searchBar.resignFirstResponder()
            textView.contentInset.top = 0
            textView.contentTextView.scrollIndicatorInsets.top = 0
            
            let text = textView.text
            textView.delegate = nil
            textView.text = text
            textView.delegate = self
            
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                self.textView.contentTextView.becomeFirstResponder()
            }
            
            return
        }
        
        searchBar = UISearchBar()
        
        searchBar.barTintColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        searchBar.frame.size.width = view.frame.width
        searchBar.autoresizingMask = [.flexibleWidth]
        
        view.addSubview(searchBar)
        
        searchBar.setShowsCancelButton(true, animated: true)
        searchBar.showsScopeBar = true
        searchBar.scopeButtonTitles = ["Find", "Replace"]
        searchBar.delegate = self
        
        func findTextField(_ containerView: UIView) {
            for view in containerView.subviews {
                if let textField = view as? UITextField {
                    textField.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
                    textField.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
                    textField.keyboardAppearance = ConsoleViewController.choosenTheme.keyboardAppearance
                    textField.autocorrectionType = .no
                    textField.autocapitalizationType = .none
                    textField.smartDashesType = .no
                    textField.smartQuotesType = .no
                    break
                } else {
                    findTextField(view)
                }
            }
        }
        
        findTextField(searchBar)
        
        searchBar.becomeFirstResponder()
        
        textView.contentInset.top = findBarHeight
        textView.contentTextView.scrollIndicatorInsets.top = findBarHeight
    }
    
    /// Highlights search results.
    func performSearch() {
        
        ranges = []
        
        guard searchBar.text != nil && !searchBar.text!.isEmpty else {
            return
        }
        
        let searchString = searchBar.text!
        let baseString = textView.text
        
        let attributed = NSMutableAttributedString(attributedString: textView.contentTextView.attributedText)
        
        guard let regex = try? NSRegularExpression(pattern: searchString, options: .caseInsensitive) else {
            return
        }
        
        for match in regex.matches(in: baseString, options: [], range: NSRange(location: 0, length: baseString.utf16.count)) as [NSTextCheckingResult] {
            ranges.append(match.range)
            attributed.addAttribute(NSAttributedString.Key.backgroundColor, value: UIColor.yellow.withAlphaComponent(0.5), range: match.range)
        }
        
        textView.contentTextView.attributedText = attributed
    }
    
    // MARK: - Search bar delegate
    
    func searchBarCancelButtonClicked(_ searchBar: UISearchBar) {
        search()
    }
    
    func searchBar(_ searchBar: UISearchBar, textDidChange searchText: String) {
        
        let text = textView.text
        textView.delegate = nil
        textView.text = text
        textView.delegate = self
        
        performSearch()
    }
    
    func searchBar(_ searchBar: UISearchBar, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        
        if text == "\n" {
            searchBar.resignFirstResponder()
        }
        
        return true
    }
    
    func searchBar(_ searchBar: UISearchBar, selectedScopeButtonIndexDidChange selectedScope: Int) {
        if selectedScope == 0 {
            replace = false
        } else {
            replace = true
        }
    }
    
    // MARK: - Actions
    
    /// Shares the current script.
    @objc func share(_ sender: UIBarButtonItem) {
        let activityVC = UIActivityViewController(activityItems: [document as Any], applicationActivities: [XcodeActivity()])
        activityVC.popoverPresentationController?.barButtonItem = sender
        present(activityVC, animated: true, completion: nil)
    }
    
    /// Opens an alert for setting arguments passed to the script.
    ///
    /// - Parameters:
    ///     - sender: The sender object. If called programatically with `sender` set to `true`, will run code after setting arguments.
    @objc func setArgs(_ sender: Any) {
        
        let alert = UIAlertController(title: Localizable.ArgumentsAlert.title, message: Localizable.ArgumentsAlert.message, preferredStyle: .alert)
        
        var textField: UITextField?
        
        alert.addTextField { (textField_) in
            textField = textField_
            textField_.text = self.args
        }
        
        if (sender as? Bool) == true {
            alert.addAction(UIAlertAction(title: Localizable.MenuItems.run, style: .default, handler: { _ in
                
                if let text = textField?.text {
                    self.args = text
                }
                
                self.run()
                
            }))
        } else {
            alert.addAction(UIAlertAction(title: Localizable.ok, style: .default, handler: { _ in
                
                if let text = textField?.text {
                    self.args = text
                }
                
            }))
        }
        
        alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
        
        present(alert, animated: true, completion: nil)
    }
    
    /// Stops the current running script.
    @objc func stop() {
        
        func stop_() {
            Python.shared.stop()
            ConsoleViewController.visible.textView.resignFirstResponder()
            ConsoleViewController.visible.textView.isEditable = false
        }
        
        if ConsoleViewController.isMainLoopRunning {
            ConsoleViewController.visible.closePresentedViewController()
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                stop_()
            }
        } else {
            stop_()
        }
    }
    
    /// Debugs script.
    @objc func debug() {
        runScript(debug: true)
    }
    
    /// Runs script.
    @objc func run() {
        runScript(debug: false)
    }
    
    /// Run the script represented by `document`.
    ///
    /// - Parameters:
    ///     -
    func runScript(debug: Bool) {
        
        // For error handling
        textView.delegate = nil
        textView.delegate = self
        
        save { (_) in            
            var arguments = self.args.components(separatedBy: " ")
            parseArgs(&arguments)
            Python.shared.args = arguments
            
            DispatchQueue.main.async {
                if let url = self.document {
                    let console = ConsoleViewController.visible
                    guard console.view.window != nil else {
                        let navVC = ThemableNavigationController(rootViewController: console)
                        navVC.modalPresentationStyle = .overCurrentContext
                        self.present(navVC, animated: true, completion: {
                            self.runScript(debug: debug)
                        })
                        
                        return
                    }
                    
                    console.textView.text = ""
                    console.console = ""
                    console.movableTextField?.placeholder = ""
                    if Python.shared.isREPLRunning {
                        if Python.shared.isScriptRunning {
                            return
                        }
                        // Import the script
                        if !debug {
                            PyInputHelper.userInput = "import console as c; s = c.run_script('\(url.path.replacingFirstOccurrence(of: "'", with: "\\'"))')"
                        } else {
                            
                            var breakpointsLines = [String]()
                            
                            for breakpoint in self.breakpoints {
                                breakpointsLines.append(String(describing: breakpoint))
                            }
                            
                            let breakpointsValue = "[\(breakpointsLines.joined(separator: ", "))]"
                            
                            PyInputHelper.userInput = "import console as c; s = c.run_script('\(url.path.replacingFirstOccurrence(of: "'", with: "\\'"))', debug=True, breakpoints=\(breakpointsValue))"
                        }
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
        
        guard document != nil else {
            completion?(false)
            return
        }
        
        let text = textView.text
        
        DispatchQueue.global().async {
            do {
                try text.write(to: self.document!, atomically: true, encoding: .utf8)
                completion?(true)
            } catch {
                completion?(false)
            }
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
                DispatchQueue.main.async {
                    DocumentBrowserViewController.visible?.collectionView.reloadData()
                }
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
                docVC.popoverPresentationController?.permittedArrowDirections = [.up, .down]
                
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
    
    // MARK: - Breakpoints
    
    private struct MarkerPosition: Hashable {
        var line: Int
        var range: UITextRange
    }
    
    private var breakpointMarkers = [MarkerPosition : UIView]()
    
    /// List of breakpoints in script. Each item is the line where the code will break.
    var breakpoints = [Int]()
    
    /// The currently running line. Set to `0` when no breakpoint is running.
    @objc static var runningLine = 0 {
        didSet {
            guard let editor = EditorSplitViewController.visible?.editor else {
                return
            }
            for (position, marker) in editor.breakpointMarkers {
                DispatchQueue.main.async {
                    marker.backgroundColor = breakpointColor
                    if position.line == runningLine {
                        print("Running")
                        marker.backgroundColor = runningLineColor
                    }
                }
            }
        }
    }
    
    /// Color for highlighting a breakpoint.
    static let breakpointColor = #colorLiteral(red: 0.2196078449, green: 0.007843137719, blue: 0.8549019694, alpha: 0.7039777729)
    
    /// Color for highlighting a line that is currently running.
    static let runningLineColor = #colorLiteral(red: 0.4666666687, green: 0.7647058964, blue: 0.2666666806, alpha: 0.7)
    
    /// Updates breakpoint markers position.
    func updateBreakpointMarkersPosition() {
        for (position, marker) in breakpointMarkers {
            marker.backgroundColor = EditorViewController.breakpointColor
            marker.frame.origin.y = textView.contentTextView.firstRect(for: position.range).origin.y
            marker.frame.origin.x = textView.contentTextView.frame.width-marker.frame.width
        }
        let runningLine = EditorViewController.runningLine
        EditorViewController.runningLine = 0
        EditorViewController.runningLine = runningLine
    }
    
    /// Sets breakpoint on current line.
    @objc func setBreakpoint(_ sender: Any) {
        
        let currentLineRange = (textView.text as NSString).lineRange(for: textView.contentTextView.selectedRange)
        
        var currentLine = (textView.text as NSString).substring(with: currentLineRange)
        if currentLine.hasSuffix("\n") {
            currentLine.removeLast()
        }
        
        var rangesOfLinesThatHaveTheSameContentThatTheCurrentLine = [NSRange]()
        
        var script = textView.text as NSString
        if !currentLine.isEmpty {
            while true {
                let foundRange = script.range(of: currentLine)
                if foundRange.location != NSNotFound {
                    rangesOfLinesThatHaveTheSameContentThatTheCurrentLine.append(foundRange)
                    script = script.replacingCharacters(in: foundRange, with: "") as NSString
                } else {
                    break
                }
            }
        } else {
            var lineRanges = [NSRange]()
            script.enumerateSubstrings(in: NSMakeRange(0, script.length), options: .byLines, using: { (_, lineRange, _, _) in
                lineRanges.append(lineRange)
            })
            for lineRange in lineRanges {
                if script.substring(with: lineRange).isEmpty {
                    rangesOfLinesThatHaveTheSameContentThatTheCurrentLine.append(lineRange)
                }
            }
        }
        
        var currentLineNumber: Int?
        
        var currentLineIndex = 0
        let lines = textView.text.components(separatedBy: .newlines)
        for line in lines.enumerated() {
            if line.element == currentLine {
                if rangesOfLinesThatHaveTheSameContentThatTheCurrentLine.indices.contains(currentLineIndex), (rangesOfLinesThatHaveTheSameContentThatTheCurrentLine[currentLineIndex].location == currentLineRange.location || rangesOfLinesThatHaveTheSameContentThatTheCurrentLine[currentLineIndex].location == currentLineRange.location-(currentLineRange.length-1)) {
                    currentLineNumber = line.offset+1
                    break
                }
                currentLineIndex += 1
            }
        }
        
        guard let currentLineNum = currentLineNumber else {
            return
        }
        
        if !breakpoints.contains(currentLineNum) {
            breakpoints.append(currentLineNum)
            
            if let textRange = textView.contentTextView.currentLineRange, let eol = textView.contentTextView.textRange(from: textRange.start, to: textRange.end) {
                let view = UIView()
                view.backgroundColor = EditorViewController.breakpointColor
                view.frame.origin.y = textView.contentTextView.firstRect(for: eol).origin.y
                view.frame.size = CGSize(width: ConsoleViewController.choosenTheme.sourceCodeTheme.font.pointSize, height: ConsoleViewController.choosenTheme.sourceCodeTheme.font.pointSize)
                view.frame.origin.x = textView.contentTextView.frame.width-view.frame.width
                view.layer.cornerRadius = view.frame.width/2
                
                breakpointMarkers[MarkerPosition(line: currentLineNum, range: eol)] = view
                
                textView.contentTextView.addSubview(view)
            }
        } else if let index = breakpoints.firstIndex(of: currentLineNum) {
            breakpoints.remove(at: index)
            
            for marker in breakpointMarkers {
                if marker.key.line == currentLineNum {
                    marker.value.removeFromSuperview()
                    breakpointMarkers[marker.key] = nil
                    break
                }
            }
        }
    }
    
    // MARK: - Keyboard
    
    /// Resize `textView`.
    @objc func keyboardWillShow(_ notification:Notification) {
        let d = notification.userInfo!
        var r = d[UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
        
        r = textView.convert(r, from:nil)
        textView.contentInset.bottom = r.height
        textView.contentTextView.scrollIndicatorInsets.bottom = r.height
        
        if searchBar?.window != nil {
            textView.contentInset.top = findBarHeight
            textView.contentTextView.scrollIndicatorInsets.top = findBarHeight
        }
    }
    
    /// Set `textView` to the default size.
    @objc func keyboardWillHide(_ notification:Notification) {
        textView.contentInset = .zero
        textView.contentTextView.scrollIndicatorInsets = .zero
        
        if searchBar?.window != nil {
            textView.contentInset.top = findBarHeight
            textView.contentTextView.scrollIndicatorInsets.top = findBarHeight
        }
    }
    
    // MARK: - Text view delegate
    
    func textViewDidChangeSelection(_ textView: UITextView) {
        if textView.isFirstResponder {
            updateSuggestions()
        }
        return self.textView.textViewDidChangeSelection(textView)
    }
    
    func textViewDidChange(_ textView: UITextView) {
        return self.textView.textViewDidChange(textView)
    }
    
    
    func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        
        docString = nil
        
        if text == "\t", let textRange = range.toTextRange(textInput: textView) {
            textView.replace(textRange, withText: EditorViewController.indentation)
            return false
        }
        
        if text == "(" {
            textView.insertText("(")
            let range = textView.selectedTextRange
            textView.insertText(")")
            textView.selectedTextRange = range
            return false
        }
        
        if text == "[" {
            textView.insertText("[")
            let range = textView.selectedTextRange
            textView.insertText("]")
            textView.selectedTextRange = range
            return false
        }
        
        if text == "\"" {
            textView.insertText("\"")
            let range = textView.selectedTextRange
            textView.insertText("\"")
            textView.selectedTextRange = range
            return false
        }
        
        if text == "\n", var currentLine = textView.currentLine {
            
            var spaces = ""
            while currentLine.hasPrefix(" ") {
                currentLine.removeFirst()
                spaces += " "
            }
            
            if currentLine.replacingOccurrences(of: " ", with: "").hasSuffix(":") {
                spaces += EditorViewController.indentation
            }
            
            textView.insertText("\n"+spaces)
            return false
        }
        
        return true
    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        textView.contentTextView.setNeedsDisplay()
    }
    
    // MARK: - Suggestions
    
    /// Returns suggestions for current word.
    @objc var suggestions = [String]() {
        didSet {
            guard !Thread.current.isMainThread else {
                return
            }
            
            DispatchQueue.main.async {
                self.inputAssistant.reloadData()
            }
        }
    }
    
    /// Completions corresponding to `suggestions`.
    @objc var completions = [String]()
    
    /// Returns doc strings per suggestions.
    @objc var docStrings = [String:String]()
    
    /// Updates suggestions.
    func updateSuggestions() {
        
        let textView = self.textView.contentTextView
        
        guard !Python.shared.isScriptRunning, let range = textView.selectedTextRange, let textRange = textView.textRange(from: textView.beginningOfDocument, to: range.end), let text = textView.text(in: textRange) else {
            self.suggestions = []
            self.completions = []
            return inputAssistant.reloadData()
        }
        
        ConsoleViewController.ignoresInput = true
        let input = [
            "from _codecompletion import suggestForCode",
            "source = '''",
            text.replacingOccurrences(of: "'", with: "\\'"),
            "'''",
            "suggestForCode(source, '\((document?.path ?? "").replacingOccurrences(of: "'", with: "\\'"))')"
        ].joined(separator: ";")
        PyInputHelper.userInput = input
    }
    
    // MARK: - Syntax text view delegate

    func didChangeText(_ syntaxTextView: SyntaxTextView) {
        if !isSaving {
            isSaving = true
            DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                self.save { (_) in
                    self.isSaving = false
                }
            }
        }
    }
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
    
    func lexerForSource(_ source: String) -> Lexer {
        return Python3Lexer()
    }
    
    // MARK: - Input assistant view delegate
    
    func inputAssistantView(_ inputAssistantView: InputAssistantView, didSelectSuggestionAtIndex index: Int) {
        
        guard completions.indices.contains(index), suggestions.indices.contains(index), docStrings.keys.contains(suggestions[index]) else {
            return
        }
        
        let completion = completions[index]
        let suggestion = suggestions[index]
        let doc = docStrings[suggestions[index]]
        
        if let currentWord = textView.contentTextView.currentWord, !suggestions[index].hasPrefix(currentWord), !suggestions[index].contains("_"), let currentWordRange = textView.contentTextView.currentWordRange {
            textView.contentTextView.replace(currentWordRange, withText: suggestion)
        } else if completion != "" {
            textView.insertText(completion)
            docString = doc
        }
    }
    
    // MARK: - Input assistant view data source
    
    func textForEmptySuggestionsInInputAssistantView() -> String? {
        return nil
    }
    
    func numberOfSuggestionsInInputAssistantView() -> Int {
        
        if let currentTextRange = textView.contentTextView.selectedTextRange {
            
            var range = textView.contentTextView.selectedRange
            
            if range.length > 1 {
                return 0
            }
            
            if textView.contentTextView.text(in: currentTextRange) == "" {
                
                range.length += 1
                
                if let textRange = range.toTextRange(textInput: textView.contentTextView), textView.contentTextView.text(in: textRange) == "_" {
                    return 0
                }
                
                range.location -= 1
                if let textRange = range.toTextRange(textInput: textView.contentTextView), let word = textView.contentTextView.word(in: range), let last = word.last, String(last) != textView.contentTextView.text(in: textRange) {
                    return 0
                }
                
                range.location += 2
                if let textRange = range.toTextRange(textInput: textView.contentTextView), let word = textView.contentTextView.word(in: range), let first = word.first, String(first) != textView.contentTextView.text(in: textRange) {
                    return 0
                }
            }
        }
        
        return suggestions.count
    }
    
    func inputAssistantView(_ inputAssistantView: InputAssistantView, nameForSuggestionAtIndex index: Int) -> String {
        
        if suggestions[index].hasSuffix("(") {
            return suggestions[index]+")"
        }
        
        return suggestions[index]
    }
}

