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
import MarqueeLabel
import SwiftUI

fileprivate func parseArgs(_ args: inout [String]) {
    ParseArgs(&args)
}

/// The View controller used to edit source code.
@objc class EditorViewController: UIViewController, SyntaxTextViewDelegate, InputAssistantViewDelegate, InputAssistantViewDataSource, UITextViewDelegate, UISearchBarDelegate, UIDocumentPickerDelegate {
    
    /// Parses a string into a list of arguments.
    ///
    /// - Parameters:
    ///     - arguments: String of arguments.
    ///
    /// - Returns: A list of arguments to send to a program.
    @objc static func parseArguments(_ arguments: String) -> NSArray {
        var arguments_ = arguments.components(separatedBy: " ")
        parseArgs(&arguments_)
        return NSArray(array: arguments_)
    }
    
    /// Returns string used for indentation
    static var indentation: String {
        get {
            return UserDefaults.standard.string(forKey: "indentation") ?? "    "
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "indentation")
            UserDefaults.standard.synchronize()
        }
    }
    
    /// The font used in the code editor and the console.
    static var font: UIFont {
        get {
            return UserDefaults.standard.font(forKey: "codeFont") ?? DefaultSourceCodeTheme().font
        }
        
        set {
            UserDefaults.standard.set(font: newValue, forKey: "codeFont")
        }
    }
    
    /// The `SyntaxTextView` containing the code.
    let textView = SyntaxTextView()
    
    /// The document to be edited.
    @objc var document: PyDocument? {
        didSet {
            
            isDocOpened = false
            
            loadViewIfNeeded()
            
            document?.editor = self
            
            textView.contentTextView.isEditable = !(document?.documentState == .editingDisabled)
            
            NotificationCenter.default.addObserver(self, selector: #selector(stateChanged(_:)), name: UIDocument.stateChangedNotification, object: document)
        }
    }
    
    /// Returns `true` if the opened file is a sample.
    var isSample: Bool {
        guard document != nil else {
            return true
        }
        return !FileManager.default.isWritableFile(atPath: document!.fileURL.path)
    }
    
    /// A boolean indicating whether the opened script is a shortcut.
    var isShortcut = false
    
    /// The Input assistant view containing `suggestions`.
    var inputAssistant = InputAssistantView()
    
    /// A Navigation controller containing the documentation.
    var documentationNavigationController: UINavigationController?
    
    private var isDocOpened = false
    
    /// The line number where an error occurred. If this value is set at `viewDidAppear(_:)`, the error will be shown and the value will be reset to `nil`.
    var lineNumberError: Int?
    
    /// Arguments passed to the script.
    var args: String {
        get {
            return UserDefaults.standard.string(forKey: "arguments\(document?.fileURL.path.replacingOccurrences(of: "//", with: "/") ?? "")") ?? ""
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "arguments\(document?.fileURL.path.replacingOccurrences(of: "//", with: "/") ?? "")")
        }
    }
    
    /// Obtains the current directory URL set for the given script.
    ///
    /// - Parameters:
    ///     - scriptURL: The URL of the script.
    ///
    /// - Returns: The current directory set for the given script.
    static func directory(for scriptURL: URL) -> URL {
        var isStale = false
        
        let defaultDir = scriptURL.deletingLastPathComponent()
        
        guard let data = try? scriptURL.extendedAttribute(forName: "currentDirectory") else {
            return defaultDir
        }
        
        guard let url = try? URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale) else {
            return defaultDir
        }
        
        _ = url.startAccessingSecurityScopedResource()
        
        var isDir: ObjCBool = false
        guard FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir), isDir.boolValue else {
            return defaultDir
        }
        
        return url
    }
    
    /// Directory in which the script will be ran.
    var currentDirectory: URL {
        get {
            if let url = document?.fileURL {
                return EditorViewController.directory(for: url)
            } else {
                return DocumentBrowserViewController.localContainerURL
            }
        }
        
        set {
            func _set() {
                guard newValue != document?.fileURL.deletingLastPathComponent() else {
                    if (try? document?.fileURL.extendedAttribute(forName: "currentDirectory")) != nil {
                        do {
                            try document?.fileURL.removeExtendedAttribute(forName: "currentDirectory")
                        } catch {
                            print(error.localizedDescription)
                        }
                    }
                    return
                }
                
                if let data = try? newValue.bookmarkData() {
                    do {
                        try document?.fileURL.setExtendedAttribute(data: data, forName: "currentDirectory")
                    } catch {
                        print(error.localizedDescription)
                    }
                }
            }
            
            DispatchQueue.global().async(execute: _set)
        }
    }
    
    /// Set to `true` before presenting to run the code.
    var shouldRun = false
    
    /// Handles state changes on a document..
    @objc func stateChanged(_ notification: Notification) {
        textView.contentTextView.isEditable = !(document?.documentState == .editingDisabled)
        
        save { (_) in
            self.document?.checkForConflicts(onViewController: self, completion: {
                if let doc = self.document, let data = try? Data(contentsOf: doc.fileURL) {
                    try? doc.load(fromContents: data, ofType: "public.python-script")
                    self.textView.text = doc.text
                    self.updateSuggestions(force: true)
                }
            })
        }
    }
    
    /// Initialize with given document.
    ///
    /// - Parameters:
    ///     - document: The document to be edited.
    init(document: PyDocument) {
        super.init(nibName: nil, bundle: nil)
        self.document = document
        self.document?.editor = self
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
    
    /// The bar button item for sharing the script.
    var shareItem: UIBarButtonItem!
    
    /// Button for searching for text in the editor.
    var searchItem: UIBarButtonItem!
    
    /// Button for going back to scripts.
    var scriptsItem: UIBarButtonItem!
    
    /// Button for debugging script.
    var debugItem: UIBarButtonItem!
    
    /// The button for seeing definitions.
    var definitionsItem: UIBarButtonItem!
    
    // MARK: - Theme
    
    /// Setups the View controller interface for given theme.
    ///
    /// - Parameters:
    ///     - theme: The theme to apply.
    func setup(theme: Theme) {
        
        textView.contentTextView.inputAccessoryView = nil
        
        // SwiftUI
        parent?.parent?.parent?.view.backgroundColor = theme.sourceCodeTheme.backgroundColor
        
        let text = textView.text
        textView.delegate = nil
        textView.delegate = self
        textView.theme = theme.sourceCodeTheme
        textView.contentTextView.textColor = theme.sourceCodeTheme.color(for: .plain)
        if traitCollection.userInterfaceStyle == .dark {
            textView.contentTextView.keyboardAppearance = .dark
        } else {
            textView.contentTextView.keyboardAppearance = theme.keyboardAppearance
        }
        textView.text = text
        
        inputAssistant = InputAssistantView()
        inputAssistant.delegate = self
        inputAssistant.dataSource = self
        inputAssistant.leadingActions = (UIDevice.current.orientation.isLandscape ? [InputAssistantAction(image: UIImage())] : [])+[InputAssistantAction(image: "⇥".image() ?? UIImage(), target: self, action: #selector(insertTab))]
        inputAssistant.attach(to: textView.contentTextView)
        inputAssistant.trailingActions = [InputAssistantAction(image: EditorSplitViewController.downArrow, target: textView.contentTextView, action: #selector(textView.contentTextView.resignFirstResponder))]+(UIDevice.current.orientation.isLandscape ? [InputAssistantAction(image: UIImage())] : [])
        
        textView.contentTextView.reloadInputViews()
    }
    
    /// Called when the user choosed a theme.
    @objc func themeDidChange(_ notification: Notification?) {
        setup(theme: ConsoleViewController.choosenTheme)
    }
    
    private func setBarItems() {
        
        runBarButtonItem = UIBarButtonItem(barButtonSystemItem: .play, target: self, action: #selector(run))
        stopBarButtonItem = UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(stop))
        
        let debugButton = UIButton(frame: CGRect(x: 0, y: 0, width: 30, height: 30))
        debugButton.addTarget(self, action: #selector(debug), for: .touchUpInside)
        debugItem = UIBarButtonItem(image: EditorSplitViewController.debugImage, style: .plain, target: self, action: #selector(debug))
        
        let scriptsButton = UIButton(frame: CGRect(x: 0, y: 0, width: 30, height: 30))
        scriptsButton.setImage(EditorSplitViewController.gridImage, for: .normal)
        scriptsButton.addTarget(self, action: #selector(close), for: .touchUpInside)
        scriptsItem = UIBarButtonItem(customView: scriptsButton)
        
        let defintionsButton = UIButton(frame: CGRect(x: 0, y: 0, width: 30, height: 30))
        defintionsButton.setImage(UIImage(systemName: "arrowtriangle.down.fill"), for: .normal)
        defintionsButton.addTarget(self, action: #selector(showDefintions(_:)), for: .touchUpInside)
        definitionsItem = UIBarButtonItem(customView: defintionsButton)
        
        let searchButton = UIButton(frame: CGRect(x: 0, y: 0, width: 30, height: 30))
        if #available(iOS 13.0, *) {
            searchButton.setImage(UIImage(systemName: "magnifyingglass"), for: .normal)
        } else {
            searchButton.setImage(UIImage(named: "Search"), for: .normal)
        }
        searchButton.addTarget(self, action: #selector(search), for: .touchUpInside)
        searchItem = UIBarButtonItem(customView: searchButton)
        
        docItem = UIBarButtonItem(barButtonSystemItem: .bookmarks, target: self, action: #selector(showDocs(_:)))
        shareItem = UIBarButtonItem(barButtonSystemItem: .action, target: self, action: #selector(share(_:)))
        let moreItem = UIBarButtonItem(image: EditorSplitViewController.threeDotsImage, style: .plain, target: self, action: #selector(showEditorScripts(_:)))
        let runtimeItem = UIBarButtonItem(image: EditorSplitViewController.gearImage, style: .plain, target: self, action: #selector(showRuntimeSettings(_:)))
        
        if !(parent is REPLViewController) && !(parent is RunModuleViewController) && !(parent is PipInstallerViewController) {
            if let path = document?.fileURL.path, Python.shared.isScriptRunning(path) {
                parentNavigationItem?.rightBarButtonItems = [
                    stopBarButtonItem,
                    debugItem,
                ]
            } else {
                parentNavigationItem?.rightBarButtonItems = [
                    runBarButtonItem,
                    debugItem,
                ]
            }
            
            if (parent as? EditorSplitViewController)?.folder != nil {
                scriptsItem = splitViewController?.displayModeButtonItem ?? scriptsItem
            }
            
            if #available(iOS 14.0, *), (parent as? EditorSplitViewController)?.folder == nil, traitCollection.horizontalSizeClass != .compact {
                parentNavigationItem?.leftBarButtonItems = [searchItem, definitionsItem]
            } else {
                parentNavigationItem?.leftBarButtonItems = [scriptsItem, searchItem, definitionsItem]
            }
        }
    
        if !(parent is REPLViewController) && !(parent is RunModuleViewController) && !(parent is PipInstallerViewController) {
            parent?.title = document?.fileURL.deletingPathExtension().lastPathComponent
            parent?.parent?.title = document?.fileURL.deletingPathExtension().lastPathComponent
        }
        
        let space = UIBarButtonItem(barButtonSystemItem: .fixedSpace, target: nil, action: nil)
        space.width = 10
        
        if !(parent is REPLViewController) && !(parent is PipInstallerViewController) && !(parent is RunModuleViewController) {
            parent?.navigationController?.isToolbarHidden = false
        } else {
            parent?.navigationController?.isToolbarHidden = true
        }
        
        if #available(iOS 13.0, *), !FileManager.default.isReadableFile(atPath: currentDirectory.path) {
            parentVC?.toolbarItems = [
                shareItem,
                moreItem,
                space,
                docItem,
                UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil),
                UIBarButtonItem(image: UIImage(systemName: "lock.fill"), style: .plain, target: self, action: #selector(setCwd(_:))),
                runtimeItem
            ]
        } else {
            parentVC?.toolbarItems = [
                shareItem,
                moreItem,
                space,
                docItem,
                UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil),
                runtimeItem
            ]
        }
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
                
        NotificationCenter.default.addObserver(self, selector: #selector(themeDidChange(_:)), name: ThemeDidChangeNotification, object: nil)
        
        if #available(iOS 13.0, *) {
            view.backgroundColor = .systemBackground
        }
        
        view.addSubview(textView)
        textView.delegate = self
        textView.contentTextView.delegate = self
        
        NoSuggestionsLabel = {
            let label = MarqueeLabel(frame: .zero, rate: 100, fadeLength: 1)
            return label
        }
        inputAssistant.dataSource = self
        inputAssistant.delegate = self
        
        if document?.fileURL == URL(fileURLWithPath: NSTemporaryDirectory()+"/Temporary") {
            title = nil
        }
        
        setBarItems()
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardDidShow), name: UIResponder.keyboardDidShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardDidShow), name: UIResponder.keyboardDidChangeFrameNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name: UIResponder.keyboardWillHideNotification, object: nil)
        
        textView.contentTextView.isEditable = !isSample
    }
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        themeDidChange(nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        setup(theme: ConsoleViewController.choosenTheme)
        
        func openDoc() {
            guard let doc = self.document else {
                return
            }
            
            if #available(iOS 13.0, *) {
                EditorViewController.setupEditorButton(self)
            }
            
            let path = doc.fileURL.path
            
            self.textView.text = document?.text ?? ""
            
            if !FileManager.default.isWritableFile(atPath: doc.fileURL.path) {
                self.navigationItem.leftBarButtonItem = nil
                self.textView.contentTextView.isEditable = false
                self.textView.contentTextView.inputAccessoryView = nil
            }
            
            if doc.fileURL.path == Bundle.main.path(forResource: "installer", ofType: "py") && (!(parent is REPLViewController) && !(parent is RunModuleViewController) && !(parent is PipInstallerViewController)) {
                self.parentNavigationItem?.leftBarButtonItems = []
                if Python.shared.isScriptRunning(path) {
                    self.parentNavigationItem?.rightBarButtonItems = [self.stopBarButtonItem]
                } else {
                    self.parentNavigationItem?.rightBarButtonItems = [self.runBarButtonItem]
                }
            }
        }
        
        if !isDocOpened {
            isDocOpened = true
            
            if document?.hasBeenOpened != true {
                document?.open(completionHandler: { (_) in
                    openDoc()
                })
            } else {
                openDoc()
            }
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if shouldRun, let path = document?.fileURL.path {
            shouldRun = false
            
            if Python.shared.isScriptRunning(path) {
                stop()
            }
            
            let splitVC = parent as? EditorSplitViewController
            
            splitVC?.ratio = 0
            
            for view in (splitVC?.view.subviews ?? []) {
                if view.backgroundColor == .white {
                    view.backgroundColor = splitVC?.view.backgroundColor
                }
            }
            
            splitVC?.firstChild?.view.superview?.backgroundColor = splitVC!.view.backgroundColor
            splitVC?.secondChild?.view.superview?.backgroundColor = splitVC!.view.backgroundColor
            
            DispatchQueue.main.asyncAfter(deadline: .now()+0.25, execute: {
                splitVC?.firstChild = nil
                splitVC?.secondChild = nil
                
                for view in (splitVC?.view.subviews ?? []) {
                    view.removeFromSuperview()
                }
                
                splitVC?.viewDidLoad()
                splitVC?.viewWillTransition(to: splitVC!.view.frame.size, with: ViewControllerTransitionCoordinator())
                splitVC?.viewDidAppear(true)
                
                splitVC?.removeGestures()
                
                splitVC?.firstChild = splitVC?.editor
                splitVC?.secondChild = splitVC?.console
                
                splitVC?.setNavigationBarItems()
            })
            
            if Python.shared.isScriptRunning(path) || !Python.shared.isSetup {
                _ = Timer.scheduledTimer(withTimeInterval: 1, repeats: true, block: { (timer) in
                    if !Python.shared.isScriptRunning(path) && Python.shared.isSetup {
                        timer.invalidate()
                        self.run()
                    }
                })
            } else {
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    self.run()
                }
            }
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.2) {
            self.updateSuggestions(force: true)
        }
        
        textView.frame = view.safeAreaLayoutGuide.layoutFrame
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        save()
        
        parent?.navigationController?.isToolbarHidden = true
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        if let parent = parent {
            compactNavigationController?.setViewControllers([parent], animated: true)
        }
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        
        guard view != nil else {
            return
        }
        
        setBarItems()
        
        for (_, marker) in breakpointMarkers {
            marker.backgroundColor = .clear
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+1) {
            self.updateBreakpointMarkersPosition()
        }
        
        guard (view.frame.height != size.height) || (textView.contentTextView.isFirstResponder && textView.frame.height != view.safeAreaLayoutGuide.layoutFrame.height) else {
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                self.textView.frame = self.view.safeAreaLayoutGuide.layoutFrame
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
    
    override var canBecomeFirstResponder: Bool {
        return true
    }
    
    override var keyCommands: [UIKeyCommand]? {
        if textView.contentTextView.isFirstResponder {
            var commands = [
                UIKeyCommand(input: "c", modifierFlags: [.command, .shift], action: #selector(toggleComment), discoverabilityTitle: Localizable.MenuItems.toggleComment),
                UIKeyCommand(input: "b", modifierFlags: [.command, .shift], action: #selector(setBreakpoint(_:)), discoverabilityTitle: Localizable.MenuItems.breakpoint)
            ]
            if numberOfSuggestionsInInputAssistantView() != 0 {
                commands.append(UIKeyCommand(input: "\t", modifierFlags: [], action: #selector(nextSuggestion), discoverabilityTitle: Localizable.nextSuggestion))
            }
            
            var indented = false
            if let range = textView.contentTextView.selectedTextRange {
                for line in textView.contentTextView.text(in: range)?.components(separatedBy: "\n") ?? [] {
                    if line.hasPrefix(EditorViewController.indentation) {
                        indented = true
                        break
                    }
                }
            }
            if let line = textView.contentTextView.currentLine, line.hasPrefix(EditorViewController.indentation) {
                indented = true
            }
            
            if indented {
                commands.append(UIKeyCommand(input: "\t", modifierFlags: [.alternate], action: #selector(unindent), discoverabilityTitle: Localizable.unindent))
            }
            
            return commands
        } else {
            return []
        }
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
            textView.contentTextView.verticalScrollIndicatorInsets.top = findBarHeight
            
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
            textView.contentTextView.verticalScrollIndicatorInsets.top = 0
            
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
        searchBar.scopeButtonTitles = [Localizable.find, Localizable.replace]
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
        textView.contentTextView.verticalScrollIndicatorInsets.top = findBarHeight
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
        
        if let range = ranges.first {
            textView.contentTextView.scrollRangeToVisible(range)
        }
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
    
    // MARK: - Plugin
    
    /// Setups the plugin button.
    @objc static func setupEditorButton(_ editor: EditorViewController?) {
        
        if #available(iOS 13.0, *) {
        } else {
            return
        }
        
        if !Thread.current.isMainThread {
            return DispatchQueue.main.async {
                self.setupEditorButton(editor)
            }
        }
        
        func addToEditor(_ editor: EditorViewController) {
            PyCore.editorViewControllers.addObject(editor)
            let i = PyCore.editorViewControllers.count-1
            _ = Timer.scheduledTimer(withTimeInterval: 0.2, repeats: true, block: { (timer) in
                if Python.shared.isSetup {
                    Python.shared.run(code: """
                    import pyto_core as pc
                    pc.__setup_editor_button__(\(i))
                    """)
                    timer.invalidate()
                }
            })
        }
        
        if let editor = editor, !editor.buttonAdded {
            addToEditor(editor)
        } else {
            if #available(iOS 13.0, *) {
                for scene in UIApplication.shared.connectedScenes {
                    let presented = (scene.delegate as? UIWindowSceneDelegate)?.window??.rootViewController?.presentedViewController
                    let editor = ((presented as? UINavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor ?? (presented as? EditorSplitViewController.ProjectSplitViewController)?.editor?.editor
                    
                    if let editor = editor, !editor.buttonAdded {
                        addToEditor(editor)
                    }
                }
            }
        }
    }
    
    private var buttonAdded = false
    
    /// Calls the plugin editor actions.
    @objc func callPlugin() {
        Python.shared.runningScripts = NSArray(array: Python.shared.runningScripts.adding(document?.fileURL.path ?? ""))
        Python.shared.run(code: """
        import pyto_core as pc
        pc.__actions__[\(actionIndex)]()
        """)
    }
    
    /// The icon of the plugin.
    @objc var editorIcon: UIImage? {
        didSet {
            let added = buttonAdded
            buttonAdded = true
            DispatchQueue.main.async {
                if !added {
                    let item = UIBarButtonItem(image: self.editorIcon, style: .plain, target: self, action: #selector(self.callPlugin))
                    self.parentVC?.toolbarItems?.insert(item, at: 2)
                }
            }
        }
    }
    
    /// The index of the function to call in the `pyto_core` module.
    @objc var actionIndex = -1
    
    // MARK: - Actions
    
    /// Shows scripts to run with this script as argument.
    @objc func showEditorScripts(_ sender: UIBarButtonItem) {
        
        class NavigationController: UINavigationController {
            
            var editor: EditorViewController?
            
            override func viewWillDisappear(_ animated: Bool) {
                super.viewWillDisappear(animated)
                
                if let doc = editor?.document, let data = try? Data(contentsOf: doc.fileURL) {
                    try? doc.load(fromContents: data, ofType: "public.python-script")
                    editor?.textView.text = doc.text
                }
            }
        }
        
        guard let fileURL = document?.fileURL else {
            return
        }
        
        save { (success) in
            
            func presentPopover() {
                DispatchQueue.main.async {
                    let tableVC = EditorActionsTableViewController(scriptURL: fileURL)
                    tableVC.editor = self
                    let vc = NavigationController(rootViewController: tableVC)
                    vc.editor = self
                    vc.modalPresentationStyle = .popover
                    vc.popoverPresentationController?.barButtonItem = sender
                    vc.popoverPresentationController?.delegate = tableVC
                    
                    self.present(vc, animated: true, completion: nil)
                }
            }
            
            guard success else {
                DispatchQueue.main.async {
                    let alert = UIAlertController(title: Localizable.Errors.errorWrittingToScript, message: nil, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: { (_) in
                        presentPopover()
                    }))
                    self.present(alert, animated: true, completion: nil)
                }
                return
            }
            
            presentPopover()
        }
    }
    
    /// Shows function definitions.
    @objc func showDefintions(_ sender: Any) {
        var navVC: UINavigationController!
                
        let view = DefinitionsView(defintions: definitionsList, handler: { (def) in
            navVC.dismiss(animated: true) {
                
                var lines = [NSRange]()
                
                let textView = self.textView.contentTextView
                let text = NSString(string: textView.text)
                text.enumerateSubstrings(in: text.range(of: text as String), options: .byLines) { (_, range, _, _) in
                    lines.append(range)
                }
                
                if lines.indices.contains(def.line-1), textView.contentSize.height > textView.frame.height {
                    let substringRange = lines[def.line-1]
                    let glyphRange = textView.layoutManager.glyphRange(forCharacterRange: substringRange, actualCharacterRange: nil)
                    let rect = textView.layoutManager.boundingRect(forGlyphRange: glyphRange, in: textView.textContainer)
                    let topTextInset = textView.textContainerInset.top
                    let contentOffset = CGPoint(x: 0, y: topTextInset + rect.origin.y)
                    if textView.contentSize.height-contentOffset.y > textView.frame.height {
                        textView.setContentOffset(contentOffset, animated: true)
                    } else {
                        textView.scrollToBottom()
                    }
                }
            }
        }) {
            navVC.dismiss(animated: true, completion: nil)
        }
        
        navVC = UINavigationController(rootViewController: UIHostingController(rootView: view))
        navVC.modalPresentationStyle = .popover
        navVC.popoverPresentationController?.barButtonItem = definitionsItem
        
        present(navVC, animated: true, completion: nil)
    }
    
    /// Shares the current script.
    @objc func share(_ sender: UIBarButtonItem) {
        let activityVC = UIActivityViewController(activityItems: [document?.fileURL as Any], applicationActivities: nil)
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
    
    /// Sets current directory.
    @objc func setCwd(_ sender: Any) {
        
        let picker = UIDocumentPickerViewController(documentTypes: ["public.folder"], in: .open)
        picker.delegate = self
        if #available(iOS 13.0, *) {
            picker.directoryURL = self.currentDirectory
        } else {
            picker.allowsMultipleSelection = true
        }
        self.present(picker, animated: true, completion: nil)
    }
    
    /// Stops the current running script.
    @objc func stop() {
        
        guard let path = document?.fileURL.path else {
            return
        }
        
        for console in ConsoleViewController.visibles {
            func stop_() {
                Python.shared.stop(script: path)
                console.textView.resignFirstResponder()
            }
            
            if console.presentedViewController != nil {
                console.dismiss(animated: true) {
                    stop_()
                }
            } else {
                stop_()
            }
        }
    }
    
    /// Debugs script.
    @objc func debug() {
        runScript(debug: true)
    }
    
    /// Runs script.
    @objc func run() {
        
        if textView.contentTextView.isFirstResponder {
            textView.contentTextView.resignFirstResponder()
            
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                self.runScript(debug: false)
            }
        } else {
            runScript(debug: false)
        }
    }
    
    /// Run the script represented by `document`.
    ///
    /// - Parameters:
    ///     - debug: Set to `true` for debugging with `pdb`.
    func runScript(debug: Bool) {
        
        guard isReceiptChecked else {
            _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { (timer) in
                if isReceiptChecked {
                    self.runScript(debug: debug)
                    timer.invalidate()
                }
            })
            return
        }
        
        guard isUnlocked else {
            if #available(iOS 13.0, *) {
                (view.window?.windowScene?.delegate as? SceneDelegate)?.showOnboarding()
            }
            return
        }
        
        var task: UIBackgroundTaskIdentifier!
        task = UIApplication.shared.beginBackgroundTask(expirationHandler: {
            UIApplication.shared.endBackgroundTask(task)
        })
        
        // For error handling
        textView.delegate = nil
        textView.delegate = self
        
        guard let path = document?.fileURL.path else {
            return
        }
        
        guard Python.shared.isSetup else {
            return
        }
                
        save { (_) in
            if !(UserDefaults.standard.value(forKey: "arguments\(self.document?.fileURL.path.replacingOccurrences(of: "//", with: "/") ?? "")") is [String]) {
                var arguments = self.args.components(separatedBy: " ")
                parseArgs(&arguments)
                            
                Python.shared.args = NSMutableArray(array: arguments)
            }
            Python.shared.currentWorkingDirectory = self.currentDirectory.path
            
            guard let console = (self.parent as? EditorSplitViewController)?.console else {
                return
            }
            
            console.updateSize()
            
            (UIApplication.shared.delegate as? AppDelegate)?.addURLToShortcuts(self.document!.fileURL)
            
            DispatchQueue.main.async {
                if let url = self.document?.fileURL {
                    func run() {
                        if !(self.parent is REPLViewController) {
                            console.textView.text = ""
                            console.console = ""
                        }
                        console.movableTextField?.placeholder = ""
                        if Python.shared.isREPLRunning {
                            if Python.shared.isScriptRunning(path) {
                                return
                            }
                            
                            Python.shared.run(script: Python.Script(path: path, debug: debug, breakpoints: self.breakpoints))
                        } else {
                            Python.shared.runScript(at: url)
                        }
                        
                        console.updateSize()
                    }
                    
                    let editorSplitViewController = console.editorSplitViewController
                    
                    guard console.view.window != nil && editorSplitViewController?.ratio != 1 else {
                        editorSplitViewController?.showConsole {
                            run()
                        }
                        return
                    }
                    
                    run()
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
        
        guard document?.text != text else {
            completion?(true)
            return
        }
        
        document?.text = text
        
        if document?.documentState != UIDocument.State.editingDisabled {
            document?.save(to: document!.fileURL, for: .forOverwriting, completionHandler: completion)
        }
    }
    
    /// The View controller is closed and the document is saved.
    @objc func close() {
        
        //stop()
        
        let presenting = presentingViewController
        
        dismiss(animated: true) {
            
            guard !self.isSample else {
                return
            }
            
            self.save(completion: { (_) in
                DispatchQueue.main.async {
                    self.document?.text = self.textView.text
                    self.document?.close(completionHandler: { (success) in
                        if !success {
                            let alert = UIAlertController(title: Localizable.Errors.errorWrittingToScript, message: nil, preferredStyle: .alert)
                            alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                            presenting?.present(alert, animated: true, completion: nil)
                        }
                    })
                }
            })
        }
    }
    
    /// Shows documentation
    @objc func showDocs(_ sender: UIBarButtonItem) {
        
        guard presentedViewController == nil else {
            return
        }
        
        if documentationNavigationController == nil {
            documentationNavigationController = ThemableNavigationController(rootViewController: DocumentationViewController())
        }
        present(documentationNavigationController!, animated: true, completion: nil)
    }
    
    /// Indents current line.
    @objc func insertTab() {
        if let range = textView.contentTextView.selectedTextRange, let selected = textView.contentTextView.text(in: range) {
            
            let nsRange = textView.contentTextView.selectedRange
            
            /*
             location: 3
             length: 37
             
             location: ~40
             length: 0
             
                .
             ->     print("Hello World")
                    print("Foo Bar")| selected
                               - 37
             */
            
            var lines = [String]()
            for line in selected.components(separatedBy: "\n") {
                lines.append(EditorViewController.indentation+line)
            }
            textView.contentTextView.insertText(lines.joined(separator: "\n"))
            
            textView.contentTextView.selectedRange = NSRange(location: nsRange.location, length: textView.contentTextView.selectedRange.location-nsRange.location)
            if selected.components(separatedBy: "\n").count == 1, let range = textView.contentTextView.selectedTextRange {
                textView.contentTextView.selectedTextRange = textView.contentTextView.textRange(from: range.end, to: range.end)
            }
        } else {
            textView.contentTextView.insertText(EditorViewController.indentation)
        }
    }
    
    /// Unindent current line
    @objc func unindent() {
        if let range = textView.contentTextView.selectedTextRange, let selected = textView.contentTextView.text(in: range), selected.components(separatedBy: "\n").count > 1 {
            
            let nsRange = textView.contentTextView.selectedRange
            
            var lines = [String]()
            for line in selected.components(separatedBy: "\n") {
                lines.append(line.replacingFirstOccurrence(of: EditorViewController.indentation, with: ""))
            }
            
            textView.contentTextView.replace(range, withText: lines.joined(separator: "\n"))
            
            textView.contentTextView.selectedRange = NSRange(location: nsRange.location, length: textView.contentTextView.selectedRange.location-nsRange.location)
        } else if let range = textView.contentTextView.currentLineRange, let text = textView.contentTextView.text(in: range) {
            let newRange = textView.contentTextView.textRange(from: range.start, to: range.start)
            textView.contentTextView.replace(range, withText: text.replacingFirstOccurrence(of: EditorViewController.indentation, with: ""))
            textView.contentTextView.selectedTextRange = newRange
        }
    }
    
    /// Comments / Uncomments line.
    @objc func toggleComment() {
        
        guard textView.contentTextView.isFirstResponder else {
            return
        }
        
        guard let selected = textView.contentTextView.selectedTextRange else {
            return
        }
        
        if (textView.contentTextView.text(in: selected)?.components(separatedBy: "\n").count ?? 0) > 1 { // Multiple lines
            guard let line = textView.contentTextView.selectedTextRange else {
                return
            }
            
            guard let text = textView.contentTextView.text(in: line) else {
                return
            }
            
            var newText = [String]()
            
            for line in text.components(separatedBy: "\n") {
                let _line = line.replacingOccurrences(of: " ", with: "").replacingOccurrences(of: "\t", with: "")
                if _line == "" {
                    newText.append(line)
                } else if _line.hasPrefix("#") {
                    newText.append(line.replacingFirstOccurrence(of: "#", with: ""))
                } else {
                    newText.append("#"+line)
                }
            }
            
            textView.contentTextView.replace(line, withText: newText.joined(separator: "\n"))
        } else { // Current line
            guard var line = textView.contentTextView.currentLine else {
                return
            }
            
            let currentLine = line
            
            line = line.replacingOccurrences(of: " ", with: "").replacingOccurrences(of: "\t", with: "")
            
            if line.hasPrefix("#") {
                line = currentLine.replacingFirstOccurrence(of: "#", with: "")
            } else {
                line = "#"+currentLine
            }
            if let lineRange = textView.contentTextView.currentLineRange {
                textView.contentTextView.replace(lineRange, withText: line)
            }
        }
    }
    
    /// Undo.
    @objc func undo() {
        textView.contentTextView.undoManager?.undo()
    }
    
    /// Redo.
    @objc func redo() {
        textView.contentTextView.undoManager?.redo()
    }
    
    /// Shows runtime settings.
    @objc func showRuntimeSettings(_ sender: UIBarButtonItem) {
        
        guard let navVC = UIStoryboard(name: "ScriptSettingsViewController", bundle: Bundle.main).instantiateInitialViewController() as? UINavigationController else {
            return
        }
        
        guard let vc = navVC.viewControllers.first as? ScriptSettingsViewController else {
            return
        }
        
        vc.editor = self
        
        navVC.modalPresentationStyle = .formSheet
        navVC.preferredContentSize = CGSize(width: 480, height: 640)
        
        present(navVC, animated: true, completion: nil)
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
            for console in ConsoleViewController.visibles {
                guard let editor = console.editorSplitViewController?.editor else {
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
    @objc func keyboardDidShow(_ notification:Notification) {
        let d = notification.userInfo!
        let r = d[UIResponder.keyboardFrameEndUserInfoKey] as! CGRect
        let point = (view.window)?.convert(r.origin, to: textView) ?? r.origin
        
        textView.contentInset.bottom = (point.y >= textView.frame.height ? 0 : textView.frame.height-point.y)
        textView.contentTextView.verticalScrollIndicatorInsets.bottom = textView.contentInset.bottom
        
        if point.y+50 >= textView.frame.height {
            textView.contentInset.bottom += 50
        }
        
        if searchBar?.window != nil {
            textView.contentInset.top = findBarHeight
            textView.contentTextView.verticalScrollIndicatorInsets.top = findBarHeight
        }
    }
    
    /// Set `textView` to the default size.
    @objc func keyboardWillHide(_ notification:Notification) {
        textView.contentInset = .zero
        textView.contentTextView.scrollIndicatorInsets = .zero
        
        if searchBar?.window != nil {
            textView.contentInset.top = findBarHeight
            textView.contentTextView.verticalScrollIndicatorInsets.top = findBarHeight
        }
    }
    
    // MARK: - Text view delegate
    
    /// Taken from https://stackoverflow.com/a/52515645/7515957.
    private func characterBeforeCursor() -> String? {
        // get the cursor position
        if let cursorRange = textView.contentTextView.selectedTextRange {
            // get the position one character before the cursor start position
            if let newPosition = textView.contentTextView.position(from: cursorRange.start, offset: -1) {
                let range = textView.contentTextView.textRange(from: newPosition, to: cursorRange.start)
                return textView.contentTextView.text(in: range!)
            }
        }
        return nil
    }
    
    /// Taken from https://stackoverflow.com/a/52515645/7515957.
    private func characterAfterCursor() -> String? {
        // get the cursor position
        if let cursorRange = textView.contentTextView.selectedTextRange {
            // get the position one character before the cursor start position
            if let newPosition = textView.contentTextView.position(from: cursorRange.start, offset: 1) {
                let range = textView.contentTextView.textRange(from: newPosition, to: cursorRange.start)
                return textView.contentTextView.text(in: range!)
            }
        }
        return nil
    }
    
    func textViewShouldBeginEditing(_ textView: UITextView) -> Bool {
        for console in ConsoleViewController.visibles {
            if console.movableTextField?.textField.isFirstResponder == false {
                continue
            } else {
                console.movableTextField?.textField.resignFirstResponder()
                return false
            }
        }
        return true
    }
    
    func textViewDidChangeSelection(_ textView: UITextView) {
        if textView.isFirstResponder {
            updateSuggestions()
        }
        return self.textView.textViewDidChangeSelection(textView)
    }
    
    func textViewDidChange(_ textView: UITextView) {
        
        func removeUndoAndRedo() {
            for (i, item) in (UIMenuController.shared.menuItems ?? []).enumerated() {
                if item.action == #selector(EditorViewController.redo) || item.action == #selector(EditorViewController.undo) {
                    UIMenuController.shared.menuItems?.remove(at: i)
                    removeUndoAndRedo()
                    break
                }
            }
        }
        
        removeUndoAndRedo()
        
        if textView.undoManager?.canRedo == true {
            UIMenuController.shared.menuItems?.insert(UIMenuItem(title: Localizable.MenuItems.redo, action: #selector(EditorViewController.redo)), at: 0)
        }
        
        if textView.undoManager?.canUndo == true {
            UIMenuController.shared.menuItems?.insert(UIMenuItem(title: Localizable.MenuItems.undo, action: #selector(EditorViewController.undo)), at: 0)
        }
        
        let text = textView.text
        EditorViewController.isCompleting = true
        DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
            if textView.text == text {
                EditorViewController.isCompleting = false
            }
        }
        
        return self.textView.textViewDidChange(textView)
    }
    
    
    func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        
        docString = nil
        
        if text == "\n", currentSuggestionIndex != -1 {
            inputAssistantView(inputAssistant, didSelectSuggestionAtIndex: 0)
            return false
        }
        
        if text == "\t" {
            if let textRange = range.toTextRange(textInput: textView) {
                if let selected = textView.text(in: textRange) {
                    
                    let nsRange = textView.selectedRange
                    
                    var lines = [String]()
                    for line in selected.components(separatedBy: "\n") {
                        lines.append(EditorViewController.indentation+line)
                    }
                    textView.replace(textRange, withText: lines.joined(separator: "\n"))
                    
                    textView.selectedRange = NSRange(location: nsRange.location, length: textView.selectedRange.location-nsRange.location)
                    if selected.components(separatedBy: "\n").count == 1, let range = textView.selectedTextRange {
                        textView.selectedTextRange = textView.textRange(from: range.end, to: range.end)
                    }
                }
                return false
            }
        }
        
        // Close parentheses and brackets.
        let completable: [(String, String)] = [
            ("(", ")"),
            ("[", "]"),
            ("{", "}"),
            ("\"", "\""),
            ("'", "'")
        ]
        
        for chars in completable {
            
            if text == chars.1 {
                let range = textView.selectedRange
                let nextCharRange = NSRange(location: range.location, length: 1)
                let nsText = NSString(string: textView.text)
                
                if nsText.length > nextCharRange.location, nsText.substring(with: nextCharRange) == chars.1 {
                    textView.selectedTextRange = NSRange(location: range.location+1, length: 0).toTextRange(textInput: textView)
                    return false
                }
            }
            
            if text == chars.0 {
                textView.insertText(chars.0)
                let range = textView.selectedTextRange
                textView.insertText(chars.1)
                textView.selectedTextRange = range
                
                return false
            }
        }
        
        if text == "\n", var currentLine = textView.currentLine, let currentLineRange = textView.currentLineRange, let selectedRange = textView.selectedTextRange {
            
            if selectedRange.start == currentLineRange.start {
                return true
            }
            
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
    
    func textViewDidEndEditing(_ textView: UITextView) {
        save(completion: nil)
        parent?.setNeedsUpdateOfHomeIndicatorAutoHidden()
        parent?.navigationController?.toolbar.frame.origin.y += 50
    }
    
    func textViewDidBeginEditing(_ textView: UITextView) {
        parent?.navigationController?.toolbar.frame.origin.y -= 50
        parent?.setNeedsUpdateOfHomeIndicatorAutoHidden()
    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        textView.contentTextView.setNeedsDisplay()
    }
    
    // MARK: - Suggestions
    
    /// The defintions of the scripts. Array of arrays: [["content", lineNumber]]
    @objc var definitions = NSMutableArray() {
        didSet {
            DispatchQueue.main.async {
                if let hostC = (self.presentedViewController as? UINavigationController)?.visibleViewController as? UIHostingController<DefinitionsView> {
                    hostC.rootView.dataSource.definitions = self.definitionsList
                }
            }
        }
    }
    
    /// Defintions of the scripts.
    var definitionsList: [Definiton] {
        var definitions = [Definiton]()
        for def in self.definitions {
            if let content = def as? [Any], content.count == 2 {
                guard let description = content[0] as? String else {
                    continue
                }
                
                guard let line = content[1] as? Int else {
                    continue
                }
                
                definitions.append(Definiton(signature: description, line: line))
            }
        
        }
        
        return definitions
    }
    
    private var currentSuggestionIndex = -1 {
        didSet {
            DispatchQueue.main.async {
                self.inputAssistant.reloadData()
            }
        }
    }
    
    @objc private static var codeToComplete = ""
    
    /// Selects a suggestion from hardware tab key.
    @objc func nextSuggestion() {
        
        guard numberOfSuggestionsInInputAssistantView() != 0 else {
            return
        }
                
        let new = currentSuggestionIndex+1
        
        if suggestions.indices.contains(new) {
            currentSuggestionIndex = new
        } else {
            currentSuggestionIndex = -1
        }
    }
    
    /// A boolean indicating whether the editor is completing code.
    @objc static var isCompleting = false
    
    /// Returns suggestions for current word.
    @objc var suggestions: [String] {
        
        get {
            
            if _suggestions.indices.contains(currentSuggestionIndex) {
                var completions = _suggestions
                
                let completion = completions[currentSuggestionIndex]
                completions.remove(at: currentSuggestionIndex)
                completions.insert(completion, at: 0)
                return completions
            }
            
            return _suggestions
        }
        
        set {
            
            currentSuggestionIndex = -1
            
            _suggestions = newValue
            
            guard !Thread.current.isMainThread else {
                return
            }
            
            DispatchQueue.main.async {
                self.inputAssistant.reloadData()
            }
        }
    }
    
    private var _completions = [String]()
    
    private var _suggestions = [String]()
    
    /// Completions corresponding to `suggestions`.
    @objc var completions: [String] {
        get {
            if _completions.indices.contains(currentSuggestionIndex) {
                var completions = _completions
                
                let completion = completions[currentSuggestionIndex]
                completions.remove(at: currentSuggestionIndex)
                completions.insert(completion, at: 0)
                return completions
            }
            
            return _completions
        }
        
        set {
            _completions = newValue
        }
    }
    
    private var _signature = ""
    
    /// Function or class signature displayed in the completion bar.
    @objc var signature: String {
        get {
            return _signature
        }
        
        set {
            if newValue != "NoneType()" {
                _signature = newValue
            }
        }
    }
    
    /// Returns doc strings per suggestions.
    @objc var docStrings = [String:String]()
    
    /// The doc string to display.
    @objc var docString: String? {
        didSet {
            
            class DocViewController: UIViewController, UIAdaptivePresentationControllerDelegate {
                
                override func viewLayoutMarginsDidChange() {
                    super.viewLayoutMarginsDidChange()
                    
                    view.subviews.first?.frame = view.safeAreaLayoutGuide.layoutFrame
                }
                
                override func viewWillAppear(_ animated: Bool) {
                    super.viewWillAppear(animated)
                    
                    view.subviews.first?.isHidden = true
                }
                
                override func viewDidAppear(_ animated: Bool) {
                    super.viewDidAppear(animated)
                    
                    view.subviews.first?.frame = view.safeAreaLayoutGuide.layoutFrame
                    view.subviews.first?.isHidden = false
                }
                
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
                docView.backgroundColor = .black
                
                let docVC = DocViewController()
                docView.frame = docVC.view.safeAreaLayoutGuide.layoutFrame
                docVC.view.addSubview(docView)
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
    
    /// Updates suggestions.
    ///
    /// - Parameters:
    ///     - force: If set to `true`, the Python code will be called without doing any check.
    func updateSuggestions(force: Bool = false) {
        
        let textView = self.textView.contentTextView
        
        let text = textView.text ?? ""
        
        if !force {
            guard let line = textView.currentLine, !line.isEmpty else {
                self.suggestions = []
                self.completions = []
                self.signature = ""
                return inputAssistant.reloadData()
            }
        }
        
        EditorViewController.codeToComplete = text
        
        ConsoleViewController.ignoresInput = true
        Python.shared.run(code: """
        from _codecompletion import suggestForCode
        from pyto import EditorViewController
        import sys
        
        path = '\(currentDirectory.path.replacingOccurrences(of: "'", with: "\\'"))'
        should_path_be_deleted = False
        
        if not path in sys.path:
          sys.path.append(path)
          should_path_be_deleted = True
        
        source = str(EditorViewController.codeToComplete)
        suggestForCode(source, \(textView.selectedRange.location), '\((document?.fileURL.path ?? "").replacingOccurrences(of: "'", with: "\\'"))')
            
        if should_path_be_deleted:
          sys.path.remove(path)
        """)
    }
    
    // MARK: - Syntax text view delegate

    func didChangeText(_ syntaxTextView: SyntaxTextView) {
        if #available(iOS 13.0, *) {
            for scene in UIApplication.shared.connectedScenes {
                
                guard scene != view.window?.windowScene else {
                    continue
                }
                
                let presented = (scene.delegate as? UIWindowSceneDelegate)?.window??.rootViewController?.presentedViewController
                let editor = ((presented as? UINavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor ?? (presented as? EditorSplitViewController.ProjectSplitViewController)?.editor?.editor
                
                guard editor?.textView.text != syntaxTextView.text, editor?.document?.fileURL.path == document?.fileURL.path else {
                    continue
                }
                
                editor?.textView.text = syntaxTextView.text
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
            currentSuggestionIndex = -1
            return
        }
        
        let completion = completions[index]
        var suggestion = suggestions[index]
        
        var isParam = false
        
        if suggestion.hasSuffix("=") {
            suggestion.removeLast()
            isParam = true
        }
        
        let selectedRange = textView.contentTextView.selectedRange
        
        let location = selectedRange.location-(suggestion.count-completion.count)
        let length = suggestion.count-completion.count
        
        /*
         
         hello_w HELLO_WORLD ORLD
         
         */
        
        let iDonTKnowHowToNameThisVariableButItSSomethingWithTheSelectedRangeButFromTheBeginingLikeTheEntireSelectedWordWithUnderscoresIncluded = NSRange(location: location, length: length)
        
        textView.contentTextView.selectedRange = iDonTKnowHowToNameThisVariableButItSSomethingWithTheSelectedRangeButFromTheBeginingLikeTheEntireSelectedWordWithUnderscoresIncluded
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.1) {
            self.textView.contentTextView.insertText(suggestion)
            if suggestion.hasSuffix("(") {
                let range = self.textView.contentTextView.selectedRange
                self.textView.contentTextView.insertText(")")
                self.textView.contentTextView.selectedRange = range
            }
            
            if isParam {
                self.textView.contentTextView.insertText("=")
            }
        }
                
        currentSuggestionIndex = -1
    }
    
    // MARK: - Input assistant view data source
    
    func textForEmptySuggestionsInInputAssistantView() -> String? {
        
        // Color for dark mode
        for view in inputAssistant.subviews {
            for view in view.subviews {
                if let collectionView = view as? UICollectionView {
                    for view in collectionView.subviews {
                        if let label = view as? UILabel {
                            label.textColor = .label
                            label.font = textView.contentTextView.font?.withSize(12)
                        }
                    }
                    break
                }
            }
        }
        
        return signature+" "
    }
    
    func numberOfSuggestionsInInputAssistantView() -> Int {
        
        var zero: Int {
            signature = ""
            return 0
        }
        
        if let currentTextRange = textView.contentTextView.selectedTextRange {
            
            var range = textView.contentTextView.selectedRange
            
            if range.length > 1 {
                return 0
            }
            
            if textView.contentTextView.text(in: currentTextRange) == "" {
                
                range.length += 1
                
                if textView.contentTextView.currentWord?.replacingOccurrences(of: " ", with: "").replacingOccurrences(of: "\t", with: "").isEmpty != false {
                    return 0
                }
                
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
        
        let suffix: String = ((currentSuggestionIndex != -1 && index == 0) ? " ⤶" : "")
        
        guard suggestions.indices.contains(index) else {
            return ""
        }
        
        if suggestions[index].hasSuffix("(") {
            return "()"+suffix
        }
        
        return suggestions[index]+suffix
    }
    
    // MARK: - Document picker delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        let success = urls.first?.startAccessingSecurityScopedResource()
        
        let url = urls.first ?? currentDirectory
        
        func doChange() {
            currentDirectory = url
            if !FoldersBrowserViewController.accessibleFolders.contains(currentDirectory.resolvingSymlinksInPath()) {
                FoldersBrowserViewController.accessibleFolders.append(currentDirectory.resolvingSymlinksInPath())
            }
            
            if success == true {
                for item in (parentVC?.toolbarItems ?? []).enumerated() {
                    if item.element.action == #selector(setCwd(_:)) {
                        parentVC?.toolbarItems?.remove(at: item.offset)
                        break
                    }
                }
            }
        }
        
        if let file = document?.fileURL,
            url.appendingPathComponent(file.lastPathComponent).resolvingSymlinksInPath() == file.resolvingSymlinksInPath() {
            
            doChange()
        } else {
            
            let alert = UIAlertController(title: Localizable.CouldNotAccessScriptAlert.title, message: Localizable.CouldNotAccessScriptAlert.message, preferredStyle: .alert)
            
            alert.addAction(UIAlertAction(title: Localizable.CouldNotAccessScriptAlert.useAnyway, style: .destructive, handler: { (_) in
                doChange()
            }))
            
            alert.addAction(UIAlertAction(title: Localizable.CouldNotAccessScriptAlert.selectAnotherLocation, style: .default, handler: { (_) in
                self.setCwd(alert)
            }))
            
            alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: { (_) in
                urls.first?.stopAccessingSecurityScopedResource()
            }))
            
            present(alert, animated: true, completion: nil)
        }
    }
}

