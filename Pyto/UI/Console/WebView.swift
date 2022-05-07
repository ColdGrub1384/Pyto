//
//  WebView.swift
//  Pyto
//
//  Created by Emma Labbé on 13-05-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import WebKit
import InputAssistant
import AVKit
import GameController

/// The terminal Web View.
public class WebView: KBWebViewBase {
    
    weak var console: ConsoleViewController?
        
    func getCursorPosition(completionHandler: @escaping ((row: Int, column: Int)) -> ()) {
        console?.webView.evaluateJavaScript("[t.getCursorRow(), t.getCursorColumn()]", completionHandler: { res, _ in
            if let res = res as? [Int], res.count == 2 {
                completionHandler((row: res[0], column: res[1]))
            }
        })
    }
    
    @objc func didPan(_ gesture: UIPanGestureRecognizer) {
        let y = gesture.velocity(in: self).y
        let velocity = (Int((y/1000).rounded(y > 0 ? .up : .down))/4)+(y > 0 ? 1 : -1)
        var code = ""
        for _ in 0...(velocity > 0 ? velocity : velocity*(-1)) {
            if velocity < 0 {
                code += "t.scrollLineDown();"
            } else {
                code += "t.scrollLineUp();"
            }
        }
        
        evaluateJavaScript(code, completionHandler: nil)
    }
    
    public override var canBecomeFirstResponder: Bool {
        false
    }
    
    enum Operation {
        case insert
        case delete
    }
    
    func printInput(operation: Operation) {
        guard let console = console else {
            return
        }
                
        areCompletionsShown = false
        completionsIndex = -1
        
        if console.highlightInput {
            ConsoleViewController.codeToHighlight = ShortenFilePaths(in: console.input)
            
            let sourceCodeTheme = ConsoleViewController.choosenTheme.sourceCodeTheme
            
            let theme = (try? JSONSerialization.data(withJSONObject: [
                "comment": sourceCodeTheme.color(for: .comment).hexString,
                "keyword": sourceCodeTheme.color(for: .keyword).hexString,
                "name": sourceCodeTheme.color(for: .identifier).hexString,
                "function": sourceCodeTheme.color(for: .identifier).hexString,
                "class": sourceCodeTheme.color(for: .identifier).hexString,
                "string": sourceCodeTheme.color(for: .string).hexString,
                "number": sourceCodeTheme.color(for: .number).hexString,
            ], options: []))?.base64EncodedString() ?? "{}".data(using: .utf8)!.base64EncodedString()
                        
            let returnValue = Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: """
            import _codecompletion
            import pyto
            import base64
                        
            s = _codecompletion.highlightedCode(str(pyto.ConsoleViewController.codeToHighlight), base64.b64decode('\(theme)').decode('utf-8'))
            """)
            
            if let str = returnValue?.takeUnretainedValue() as? String {
                // Save cursor position, erase line, print input, restore cursor position and move cursor 1 char forward
                console.print("\u{001b}7\u{001b}[2K\r\(console.prompt ?? "")\(str.replacingOccurrences(of: "\n", with: ""))\u{001b}8\u{001b}[\(operation == .insert ? "C" : "D")")
            }
        } else {
            
            // Save cursor position, erase line, print input, restore cursor position and move cursor 1 char forward
            console.print("\u{001b}7\u{001b}[2K\r\(console.prompt ?? "")\(!console.secureTextEntry ? console.input : console.input.map({ _ in "*" }).joined(separator: ""))\u{001b}8\u{001b}[\(operation == .insert ? "C" : "D")")
        }
    }
    
    @objc func interrupt() {
        guard let console = console else {
            return
        }
        
        if areCompletionsShown {
            clearSuggestions()
            areCompletionsShown = false
            completionsIndex = -1
        }
        
        console.input = ""
        console.inputIndex = 0
        console.prompt = nil
        #if MAIN
        if let path = console.editorSplitViewController?.editor?.document?.fileURL.path {
            Python.shared.interrupt(script: path)
        }
        #endif
    }
    
    let inputAssistant = InputAssistantView()
    
    // MARK: - Keyboard
    
    @objc func down() {
        guard let console = console else {
            return
        }
        
        if areCompletionsShown {
            if console.completions.indices.contains(completionsIndex+1) {
                completionsIndex += 1
            }
            return
        }
        
        if console.historyIndex > -1 {
            console.historyIndex -= 1
        }
    }
    
    @objc func up() {
        guard let console = console else {
            return
        }
        
        if areCompletionsShown {
            if console.completions.indices.contains(completionsIndex-1) {
                completionsIndex -= 1
            }
            return
        }
        
        if console.history.indices.contains(console.historyIndex+1) {
            console.historyIndex += 1
        }
    }
    
    @objc func back() {
        guard let console = console else {
            return
        }
        
        if console.inputIndex > 0 {
            console.inputIndex -= 1
            console.print("\u{001b}[D")
        }
    }
    
    @objc func forward() {
        guard let console = console else {
            return
        }
        
        if console.inputIndex < console.input.count {
            console.inputIndex += 1
            console.print("\u{001b}[C")
        }
    }
    
    func backspace() {
        guard let console = console else {
            return
        }
        
        if areCompletionsShown {
            clearSuggestions()
            areCompletionsShown = false
            completionsIndex = -1
        }
        
        if console.input.count != 0 {
            let input = NSMutableString(string: console.input)
            let range = NSRange(location: console.inputIndex-1, length: 1)
            if NSMaxRange(range) <= input.length {
                input.deleteCharacters(in: NSRange(location: console.inputIndex-1, length: 1))
                console.input = input as String
                console.inputIndex -= 1
                printInput(operation: .delete)
            }
        }
    }
    
    private var isEntering = false
    
    func enter() {
        guard let console = console else {
            return
        }
        
        guard !areCompletionsShown else {
            clearSuggestions()
            
            let completion = console.completions[completionsIndex]
            isEntering = true
            for char in completion+((console.highlightInput || console.input.components(separatedBy: " ").count > 1) ? "" : " ") /* Insert a space when writting the first argument of a command */ {
                insert(char: String(char))
            }
            isEntering = false
            let upperBound = completion.count-(console.highlightInput ? 1 : 0)
            guard upperBound >= 0 else {
                return
            }
            for _ in 0..<upperBound {
                forward()
            }
            return
        }
        
        console.handleInput(console.input)
        console.input = ""
        console.inputIndex = 0
        console.currentInput = nil
        console.printInputAfterSettingHistoryIndex = false
        console.historyIndex = -1
        console.prompt = nil
    }
    
    var areCompletionsShown = false {
        didSet {
            if !areCompletionsShown {
                isShowingSuggestionsBelowThePrompt = false
                columnizedSuggestions = []
            }
        }
    }
    
    var isShowingSuggestionsBelowThePrompt = false
    
    var columnizedSuggestions = [[String]]()
    
    var isShowingOneSuggestionPerLine = false
    
    func clearSuggestions() {
        console?.print("\u{001b}7") // Save cursor position
        for _ in columnizedSuggestions {
            console?.print("\u{001b}[B\u{001b}[2K\r") // For each line, go down and erase it
        }
        console?.print("\u{001b}8") // Restore cursor position
    }
    
    var completionsIndex = -1 {
        didSet {
            guard console!.completions.indices.contains(completionsIndex) else {
                return
            }
            
            // save cursor position, clear line, prompt, input, green, suggestion, reset green, reset cursor position
            console?.print("\u{001b}7\u{001b}[2K\r\(console?.prompt ?? "")\(console?.input ?? "")\u{001b}[32m\(console!.completions[completionsIndex])\u{001b}[0m\u{001b}8")
            
            var suggestions = console!.suggestions.map({ $0.replacingOccurrences(of: " ", with: "\u{00a0}") /* A character that looks like a space but isn't */ }).map { suggestion -> String in
                var str = suggestion
                var removedChar = false
                while str.count > console!.terminalSize.columns {
                    str.removeLast()
                    removedChar = true
                }
                if str.count > 0 && removedChar {
                    str.removeLast()
                    str.append("…")
                }
                return str
            }
            
            while suggestions.count > 20 {
                suggestions.removeLast()
            }
            
            guard let object = Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: """
            from _codecompletion import columnize_suggestions
            from base64 import b64decode
            
            base64 = "\((try? JSONSerialization.data(withJSONObject: suggestions, options: []).base64EncodedString()) ?? "")"
            s = columnize_suggestions(b64decode(base64))
            """) else {
                return
            }
            
            guard var str = object.takeUnretainedValue() as? String else {
                return
            }
            
            if (str.components(separatedBy: "\n").first?.count ?? 0) > console!.terminalSize.columns {
                str = suggestions.map({ $0.replacingOccurrences(of: "  ", with: "").replacingOccurrences(of: "\t", with: "") }).joined(separator: "\n")
                isShowingOneSuggestionPerLine = true
            } else {
                isShowingOneSuggestionPerLine = false
            }
            
            clearSuggestions()
            
            var lines = [[String]]()
            for _line in str.components(separatedBy: "\n").map({ $0.components(separatedBy: " ") }) {
                var line = [String]()
                
                var foundSuggestion = false
                var endedReverseVideo = false
                var i = 0
                for word in _line {
                    
                    var removedChar = false
                    var suggestion = console!.suggestions[completionsIndex]
                    while suggestion.count > console!.terminalSize.columns {
                        suggestion.removeLast()
                        removedChar = true
                    }
                    if suggestion.count > 0, removedChar {
                        suggestion.removeLast()
                        suggestion.append("…")
                    }
                    
                    if word.replacingOccurrences(of: "\u{00a0}", with: " ") == suggestion {
                        foundSuggestion = true
                        line.append("\u{001b}[7m\(word)")
                    } else if !word.isEmpty && foundSuggestion {
                        line.append("\u{001b}[0m\(word)")
                        endedReverseVideo = true
                        foundSuggestion = false
                    } else {
                        line.append(word)
                    }
                    i += 1
                }
                
                if foundSuggestion && !endedReverseVideo {
                    var last = line.removeLast()
                    last += "\u{001b}[0m"
                    line.append(last)
                }
                
                lines.append(line)
            }
            
            if lines.last == [""] {
                lines.removeLast()
            }
            
            columnizedSuggestions = lines
            
            var output = [String]()
            for line in lines {
                output.append(line.joined(separator: " "))
            }
            
            evaluateJavaScript("numberOfRowsAfterPrompt()") { result, _ in
                let numberOfRowsAfterPrompt = (result as? Int) ?? 0
                self.console?.print("\u{001b}7\n\r\(output.joined(separator: "\n\r"))")
                self.getCursorPosition { newCursorPosition in
                    self.console?.print("\u{001b}8")
                    if !self.isShowingSuggestionsBelowThePrompt && (self.console?.terminalSize.rows ?? 0)-newCursorPosition.row <= 1 {
                        var cursorPosition = newCursorPosition
                        var i = 0
                        for _ in (numberOfRowsAfterPrompt == 0 || output.count-numberOfRowsAfterPrompt < 0) ? output : Array(repeating: "", count: output.count-numberOfRowsAfterPrompt) {
                            
                            if numberOfRowsAfterPrompt > 0 && i+1 >= numberOfRowsAfterPrompt {
                                break
                            }
                            
                            self.console?.print("\u{001b}[A")
                            cursorPosition.row -= 1
                            i += 1
                        }
                    }
                    
                    self.isShowingSuggestionsBelowThePrompt = true
                }
            }
        }
    }
    
    func navigateCompletions() {
        if !areCompletionsShown {
            areCompletionsShown = true
            completionsIndex = 0
        } else {
            down()
        }
    }
    
    func insert(char: String) {
        guard let console = console else {
            return
        }
        
        guard !char.isEmpty else {
            return
        }
        
        if char == "\t" && console.suggestions.count > 0 && !isEntering {
            return navigateCompletions()
        }
        
        if char == " " && console.suggestions.count > 0 && areCompletionsShown && !isEntering {
            return enter()
        }
        
        if areCompletionsShown {
            clearSuggestions()
            areCompletionsShown = false
            completionsIndex = -1
        }
        
        let input = NSMutableString(string: console.input)
        
        input.insert(char, at: console.inputIndex)
        console.input = input as String
        
        if console.historyIndex == -1 {
            console.currentInput = console.input
        }
        
        console.inputIndex += 1
        
        printInput(operation: .insert)
    }
    
    @objc func insertTab(_ sender: Any) {
        insert(char: "\t")
    }
    
    @objc func clear() {
        console?.clear()
        console?.print(console!.prompt ?? "")
        console?.print(console!.input)
        if areCompletionsShown {
            clearSuggestions()
            areCompletionsShown = false
            completionsIndex = -1
        }
    }
    
    @objc func caretRect(for position: UITextPosition) -> CGRect {
        .zero
    }
    
    static var swizzledCaretRect = false
    
    func swizzleCaretRectIfNeeded() {
        guard !Self.swizzledCaretRect else {
            return
        }
        
        for contentView in scrollView.subviews {
            if contentView.classForCoder.description() == [
                "W",
                "K",
                "Con",
                "te",
                "nt",
                "View"
            ].joined(separator: "") {
                if let impl = class_getMethodImplementation(WebView.self, #selector(caretRect(for:))) {
                    class_replaceMethod(type(of: contentView), #selector(UITextInput.caretRect(for:)), impl, nil)
                }
                
                break
            }
        }
    }
    
    // MARK: - Web view
    
    public override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        reloadInputViews()
    }
    
    public override func becomeFirstResponder() -> Bool {
        let bool = super.becomeFirstResponder()
        console?.parent?.setNeedsUpdateOfHomeIndicatorAutoHidden()
        return bool
    }
    
    public override func resignFirstResponder() -> Bool {
        let bool = super.resignFirstResponder()
        console?.parent?.setNeedsUpdateOfHomeIndicatorAutoHidden()
        evaluateJavaScript("t.document_.activeElement.blur()")
        return bool
    }
    
    public override func canPerformAction(_ action: Selector, withSender sender: Any?) -> Bool {
        guard super.canPerformAction(action, withSender: sender) else {
            return false
        }
        
        return action != NSSelectorFromString("_showTextStyleOptions:")
    }
    
    private var pasting = false
    
    public override func paste(_ sender: Any?) {
        
        guard !pasting else {
            return
        }
        
        pasting = true
        
        guard console?.prompt != nil else {
            return
        }
        
        guard let str = UIPasteboard.general.string else {
            return
        }
        
        for char in str {
            insert(char: String(char))
        }
        
        DispatchQueue.main.async {
            self.pasting = false // Fixes double pasting on macOS
        }
    }
    
    public override var keyCommands: [UIKeyCommand]? {
        [
            UIKeyCommand(input: "c", modifierFlags: .control, action: #selector(interrupt)),
            UIKeyCommand(input: "k", modifierFlags: .command, action: #selector(clear)),
            UIKeyCommand(input: "l", modifierFlags: .control, action: #selector(clear))
        ]
    }
    
    private var previousConstraintValue: CGFloat?
    
    init() {
        let config = WKWebViewConfiguration()
        if #available(iOS 14.5, *) {
            config.preferences.isTextInteractionEnabled = true
        }
        super.init(frame: .zero, configuration: config)
        
        let gesture = UIPanGestureRecognizer(target: self, action: #selector(didPan(_:)))
        if #available(iOS 13.4, *) {
            gesture.allowedScrollTypesMask = .all
        }
        
        addGestureRecognizer(gesture)
        
        scrollView.isScrollEnabled = false
        
        addGestureRecognizer(UITapGestureRecognizer(target: self, action: #selector(becomeFirstResponder)))
        
        swizzleCaretRectIfNeeded()
        
        inputAssistantItem.leadingBarButtonGroups = []
        inputAssistantItem.trailingBarButtonGroups = []
        
        NotificationCenter.default.addObserver(forName: UIResponder.keyboardDidShowNotification, object: nil, queue: .main) { [weak self] _ in
            self?.inputAssistantItem.leadingBarButtonGroups = []
            self?.inputAssistantItem.trailingBarButtonGroups = []
        }
        
        NotificationCenter.default.addObserver(forName: UIResponder.keyboardDidChangeFrameNotification, object: nil, queue: .main) { [weak self] _ in
            self?.reloadInputViews()
        }
        
        NotificationCenter.default.addObserver(forName: NSNotification.Name.GCKeyboardDidDisconnect, object: nil, queue: .main) { [weak self] _ in
            self?.reloadInputViews()
        }
        
        NotificationCenter.default.addObserver(forName: NSNotification.Name.GCKeyboardDidConnect, object: nil, queue: .main) { [weak self] _ in
            self?.reloadInputViews()
        }
        
        // Boring keyboard stuff
        
        NotificationCenter.default.addObserver(forName: UIResponder.keyboardWillHideNotification, object: nil, queue: .main) { [weak self] _ in
            
            guard let console = self?.console else {
                return
            }
            
            guard console.editorSplitViewController?.superclass?.isSubclass(of: EditorSplitViewController.self) == false else {
                return
            }
            
            if EditorSplitViewController.shouldShowConsoleAtBottom, let previousConstraintValue = self?.previousConstraintValue {
                
                let splitVC = console.editorSplitViewController
                let constraint = (splitVC?.firstViewHeightRatioConstraint?.isActive == true) ? splitVC?.firstViewHeightRatioConstraint : splitVC?.firstViewHeightConstraint
                
                constraint?.constant = previousConstraintValue
                self?.previousConstraintValue = nil
            }
        }
        
        NotificationCenter.default.addObserver(forName: UIResponder.keyboardWillShowNotification, object: nil, queue: .main) { [weak self] notification in
            
            guard let console = self?.console else {
                return
            }
            
            guard let splitVC = console.editorSplitViewController, splitVC.superclass != EditorSplitViewController.self else {
                return
            }
            
            self?.reloadInputViews()
            
            guard !isiOSAppOnMac else {
                return
            }
            
            var isFirstResponder = self?.isFirstResponder ?? false
            for contentView in self?.scrollView.subviews ?? [] {
                if contentView.classForCoder.description() == [
                    "W",
                    "K",
                    "Con",
                    "te",
                    "nt",
                    "View"
                ].joined(separator: "") {
                    if contentView.isFirstResponder {
                        isFirstResponder = true
                    }
                    break
                }
            }
            
            guard !(console.editorSplitViewController is RunModuleViewController) else {
                return
            }
            
            guard let height = (notification.userInfo?["UIKeyboardBoundsUserInfoKey"] as? CGRect)?.height, height > 100 else { // Only software keyboard
                return
            }
            
            if EditorSplitViewController.shouldShowConsoleAtBottom && isFirstResponder {
                
                let splitVC = console.editorSplitViewController
                
                // I don't know what the fuck I'm doing
                splitVC?.firstViewHeightRatioConstraint?.isActive = false
                
                let constraint = (splitVC?.firstViewHeightRatioConstraint?.isActive == true) ? splitVC?.firstViewHeightRatioConstraint : splitVC?.firstViewHeightConstraint
                
                guard constraint?.constant != 0 else {
                    return
                }
                
                self?.previousConstraintValue = constraint?.constant
                constraint?.constant = 0
            }
        }
        
        inputAssistant.frame.size.height = 44
    }
    
    public override var inputAccessoryView: UIView? {
        #if SCREENSHOTS
        UIDevice.current.userInterfaceIdiom == .pad ? nil : inputAssistant
        #else
        (GCKeyboard.coalesced != nil || isiOSAppOnMac) ? nil : inputAssistant
        #endif
    }
    
    public override func didMoveToSuperview() {
        super.didMoveToSuperview()
                
        inputAssistant.leadingActions = [
            InputAssistantAction(image: UIImage()),
            InputAssistantAction(image: UIImage(systemName: "arrow.forward.to.line")?.withConfiguration(UIImage.SymbolConfiguration(scale: .medium)) ?? UIImage(), target: self, action: #selector(insertTab(_:))),
            InputAssistantAction(image: UIImage(systemName: "doc.on.clipboard")?.withConfiguration(UIImage.SymbolConfiguration(scale: .medium)) ?? UIImage(), target: self, action: #selector(paste(_:))),
            InputAssistantAction(image: UIImage(named: "CtrlC")?.withConfiguration(UIImage.SymbolConfiguration(scale: .medium)) ?? UIImage(), target: self, action: #selector(interrupt)),
        ]
        
        inputAssistant.trailingActions = [
            InputAssistantAction(image: UIImage(systemName: "arrow.down")?.withConfiguration(UIImage.SymbolConfiguration(scale: .medium)) ?? UIImage(), target: self, action: #selector(down)),
            InputAssistantAction(image: UIImage(systemName: "arrow.up")?.withConfiguration(UIImage.SymbolConfiguration(scale: .medium)) ?? UIImage(), target: self, action: #selector(up)),
            InputAssistantAction(image: UIImage(systemName: "arrow.left")?.withConfiguration(UIImage.SymbolConfiguration(scale: .medium)) ?? UIImage(), target: self, action: #selector(back)),
            InputAssistantAction(image: UIImage(systemName: "arrow.right")?.withConfiguration(UIImage.SymbolConfiguration(scale: .medium)) ?? UIImage(), target: self, action: #selector(forward)),
            InputAssistantAction(image: UIImage(systemName: "keyboard.chevron.compact.down")?.withConfiguration(UIImage.SymbolConfiguration(scale: .medium)) ?? UIImage(), target: self, action: #selector(resignFirstResponder)),
            InputAssistantAction(image: UIImage()),
        ]
        
        inputAssistant.tintColor = .label
    }
    
    public override func willMove(toWindow newWindow: UIWindow?) {
        super.willMove(toWindow: newWindow)
        
        var isFirstResponder = isFirstResponder
        for contentView in scrollView.subviews {
            if contentView.classForCoder.description() == [
                "W",
                "K",
                "Con",
                "te",
                "nt",
                "View"
            ].joined(separator: "") {
                if contentView.isFirstResponder {
                    isFirstResponder = true
                }
                break
            }
        }
        
        if !isFirstResponder {
            evaluateJavaScript("t.document_.activeElement.blur()")
        }
    }
        
    override init(frame: CGRect, configuration: WKWebViewConfiguration) {
        super.init(frame: frame, configuration: configuration)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
