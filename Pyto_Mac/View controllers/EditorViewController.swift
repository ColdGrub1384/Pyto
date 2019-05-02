//
//  ViewController.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 1/26/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa
import SavannaKit
import SourceEditor

fileprivate extension NSTouchBar.CustomizationIdentifier {
    static let candidateListBar = NSTouchBar.CustomizationIdentifier("Pyto.TouchBar.candidateListBar")
}

fileprivate extension NSTouchBarItem.Identifier {
    static let candidateList = NSTouchBarItem.Identifier("Pyto.TouchBar.TouchBarItem.candidateList")
    
    static let run = NSTouchBarItem.Identifier("Pyto.TouchBar.TouchBarItem.run")
    
    static let stop = NSTouchBarItem.Identifier("Pyto.TouchBar.TouchBarItem.stop")
}

/// A View controller for editing and running scripts.
class EditorViewController: NSViewController, SyntaxTextViewDelegate, NSTextViewDelegate, NSCollectionViewDataSource, NSCollectionViewDelegateFlowLayout, NSTouchBarDelegate, NSCandidateListTouchBarItemDelegate {
    
    /// Clears console.
    @objc static func clear() {
        DispatchQueue.main.async {
            for window in NSApp.windows {
                if let editor = window.contentViewController as? EditorViewController, !(editor is REPLViewController) {
                    editor.consoleTextView?.string = ""
                    editor.console = ""
                }
            }
        }
    }
    
    /// Toggles stop and play button.
    @objc static func toggleStopButton() {
        DispatchQueue.main.async {
            for window in NSApp.windows {
                if let editor = window.contentViewController as? EditorViewController, !(editor is REPLViewController) {
                    editor.stopButton?.isEnabled = Python.shared.isScriptRunning
                    editor.runButton?.isEnabled = !Python.shared.isScriptRunning
                    editor.touchBarStopButton?.isEnabled = Python.shared.isScriptRunning
                    editor.touchBarRunButton?.isEnabled = !Python.shared.isScriptRunning
                }
            }
            
            (NSApp.delegate as? AppDelegate)?.runMenuItem.isEnabled = (!Python.shared.isScriptRunning && NSApp.keyWindow?.contentViewController is EditorViewController && !(NSApp.keyWindow?.contentViewController is REPLViewController))
            (NSApp.delegate as? AppDelegate)?.stopMenuItem.isEnabled = Python.shared.isScriptRunning
        }
    }
    
    // MARK: - Instance
    
    /// Console content.
    @objc var console = ""
    
    /// If the document isn't saved, this URL is ran.
    @objc var temporaryFileURL: URL?
    
    // MARK: - Code completion
    
    /// The touch bar item with suggestions.
    var candidateListItem: NSCandidateListTouchBarItem<NSString>!
    
    /// Collection view displaying suggestions.
    @IBOutlet weak var suggestionsCollectionView: NSCollectionView?
    
    /// Completions corresponding to `suggestions`.
    @objc var completions = [String]()
    
    /// Suggestions shown on the suggestions bar.
    @objc var suggestions = [String]() {
        didSet {
            DispatchQueue.main.async {
                guard let suggestionsView = self.suggestionsCollectionView else {
                    return
                }
                if self.collectionView(suggestionsView, numberOfItemsInSection: 0) > 0 {
                    self.candidateListItem?.setCandidates(self.suggestions as [NSString], forSelectedRange: self.textView.contentTextView.selectedRange(), in: nil)
                } else {
                    self.candidateListItem?.setCandidates([], forSelectedRange: self.textView.contentTextView.selectedRange(), in: nil)
                }
            }
        }
    }
    
    /// The identifier of the cell with the completion. Set to `nil` before the cell is registered.
    var codeCompletionCellID: NSUserInterfaceItemIdentifier!
    
    // MARK: - Running
    
    /// The prompt to send.
    var prompt = ""
    
    /// Runs code.
    @objc func run(_ sender: Any) {
        prompt = ""
        if let fileURL = document?.fileURL {
            temporaryFileURL = nil
            document?.save(to: fileURL, ofType: "py", for: .autosaveAsOperation, completionHandler: { (error) in
                if let error = error {
                    self.consoleTextView?.string += "\(error.localizedDescription)\n"
                } else {
                    Python.shared.runScript(at: fileURL)
                }
            })
        } else {
            let tmpURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent("tmp_script.py")
            temporaryFileURL = tmpURL
            if FileManager.default.fileExists(atPath: tmpURL.path) {
                try? FileManager.default.removeItem(at: tmpURL)
            }
            
            FileManager.default.createFile(atPath: tmpURL.path, contents: textView.text.data(using: .utf8), attributes: nil)
            
            Python.shared.runScript(at: tmpURL)
        }
    }
    
    /// Stops script.
    @objc func stop(_ sender: Any) {
        Python.shared.isScriptRunning = false
    }
    
    // MARK: - UI
    
    /// Button for stopping script.
    var stopButton: NSButton?
    
    /// Button for running script.
    var runButton: NSButton?
    
    /// Button for stopping script from the Touch Bar.
    var touchBarStopButton: NSButton?
    
    /// Button for running script from the Touch Bar.
    var touchBarRunButton: NSButton?
    
    /// A Split view containing the code editor and the console.
    @IBOutlet weak var splitView: NSSplitView?
    
    /// The text view containing the console.
    @IBOutlet var consoleTextView: NSTextView?
    
    // MARK: - Document
    
    /// Text view containing code.
    let textView = SyntaxTextView()
    
    /// Document to be edited.
    var document: PyDocument? {
        didSet {
            textView.text = document?.text ?? ""
        }
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        textView.delegate = self
        textView.theme = ChoosenTheme
        textView.contentTextView.insertionPointColor = NSColor(named: "TintColor") ?? textView.contentTextView.insertionPointColor
        textView.contentTextView.usesFindBar = true
        textView.contentTextView.delegate = self
        
        console = consoleTextView?.string ?? ""
        consoleTextView?.delegate = self
        consoleTextView?.font = NSFont(name: "Menlo", size: 12)
        //consoleTextView?.textColor = ChoosenTheme.color(for: .plain)
        consoleTextView?.isAutomaticQuoteSubstitutionEnabled = false
        consoleTextView?.isAutomaticDashSubstitutionEnabled = false
        consoleTextView?.isAutomaticDataDetectionEnabled = false
        consoleTextView?.isAutomaticTextCompletionEnabled = false
        consoleTextView?.isAutomaticSpellingCorrectionEnabled = false
        
        if let splitView = splitView {
            
            let textEditorSize = splitView.arrangedSubviews[0].frame.size
            
            splitView.removeArrangedSubview(splitView.arrangedSubviews[0])
            splitView.insertArrangedSubview(textView, at: 0)
            textView.frame.size = textEditorSize
        
            suggestionsCollectionView?.enclosingScrollView?.scrollerInsets = NSEdgeInsets(top: 0, left: 0, bottom: 100, right: 0)
        }
        
        NotificationCenter.default.addObserver(forName: NSView.AppearanceDidChangeNotification, object: nil, queue: nil) { (notification) in
            self.textView.theme = ChoosenTheme
        }
        
        NotificationCenter.default.addObserver(forName: ThemeDidChangeNotification, object: nil, queue: nil) { (notification) in
            self.textView.theme = ChoosenTheme
        }
        
        (consoleTextView as? ConsoleTextView)?.interruptionHandler = {
            if Python.shared.isScriptRunning {
                Python.shared.process?.interrupt()
            }
        }
        (consoleTextView as? ConsoleTextView)?.eofHandler = {
            if Python.shared.isScriptRunning {
                Python.shared.inputPipe.fileHandleForReading.closeFile()
                Python.shared.inputPipe.fileHandleForWriting.closeFile()
            }
        }
    }
    
    override func viewWillAppear() {
        super.viewWillAppear()
                
        let touchBar = view.window?.windowController?.touchBar
        textView.contentTextView.touchBar = touchBar
        touchBar?.delegate = self
        touchBar?.customizationIdentifier = .candidateListBar
        touchBar?.defaultItemIdentifiers = [.run , .stop, .candidateList]
        touchBar?.customizationAllowedItemIdentifiers = [.candidateList]
    }
    
    override func viewDidAppear() {
        super.viewDidAppear()
        
        for item in view.window?.toolbar?.items ?? [] {
            let button = item.view as? NSButton
            if item.tag == 1 {
                button?.action = #selector(run(_:))
                button?.target = self
                runButton = button
            } else if item.tag == 2 {
                button?.action = #selector(stop(_:))
                button?.target = self
                stopButton = button
            }
        }
        
        EditorViewController.toggleStopButton()
    }
    
    override func viewDidDisappear() {
        super.viewDidDisappear()
        
        EditorViewController.toggleStopButton()
    }
    
    // MARK: - Syntax text view
    
    func didChangeText(_ syntaxTextView: SyntaxTextView) {
        document?.text = syntaxTextView.text
    }
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {
        
    }
    
    func lexerForSource(_ source: String) -> Lexer {
        return Python3Lexer()
    }
    
    // MARK: - Text view delegate
    
    func textView(_ textView: NSTextView, shouldChangeTextIn affectedCharRange: NSRange, replacementString: String?) -> Bool {
        
        if textView == self.textView.contentTextView {
            
            if !self.textView.textView(textView, shouldChangeTextIn: affectedCharRange, replacementString: replacementString) {
                return false
            }
            
            if replacementString == "\t" {
                textView.insertText("  ", replacementRange: affectedCharRange)
                return false
            } else if replacementString == "(" {
                
                defer {
                    let range = textView.selectedRange()
                    textView.insertText(")", replacementRange: range)
                    textView.setSelectedRange(range)
                }
                
                return true
            } else if replacementString == "\"" {
                
                defer {
                    let range = textView.selectedRange()
                    textView.replaceCharacters(in: range, with: "\"")
                    textView.setSelectedRange(range)
                }
                
                return true
            } else if replacementString == "[" {
                
                defer {
                    let range = textView.selectedRange()
                    textView.insertText("]", replacementRange: range)
                    textView.setSelectedRange(range)
                }
                
                return true
            } else {
                return true
            }
        } else if textView == consoleTextView {
            
            let allConsoleRange = ((console+prompt) as NSString).range(of: (console+prompt))
            if affectedCharRange.location < allConsoleRange.length {
                // Only allow inserting text from the end
                if prompt.isEmpty {
                    return false
                }
                if !((replacementString == "" || replacementString == nil) && affectedCharRange.length == 1 && affectedCharRange.location+1 == allConsoleRange.length) { // Is not backspace
                    return false
                }
            }
            
            if (replacementString == "" || replacementString == nil) && affectedCharRange.length > 0 {
                if !prompt.isEmpty {
                    prompt.removeLast()
                }
            } else if replacementString == "\n", let data = (prompt+"\n").data(using: .utf8) {
                console += prompt+"\n"
                prompt = ""
                if Python.shared.isScriptRunning && !(self is REPLViewController) {
                    Python.shared.inputPipe.fileHandleForWriting.write(data)
                } else {
                    (self as? REPLViewController)?.inputPipe.fileHandleForWriting.write(data)
                }
            } else {
                prompt += replacementString ?? ""
            }
            
            return true
        } else {
            return true
        }
    }
    
    func textDidChange(_ notification: Notification) {
        if (notification.object as? TextView) == textView.contentTextView {
            textView.textDidChange(notification)
        }
    }
    
    func textViewDidChangeSelection(_ notification: Notification) {
        if (notification.object as? TextView) == textView.contentTextView {
            textView.textViewDidChangeSelection(notification)
            completeCode()
        } else if (notification.object as? NSTextView) == consoleTextView {
            completions = []
            suggestions = []
        }
    }
    
    // MARK: - Collection view data source
    
    func collectionView(_ collectionView: NSCollectionView, numberOfItemsInSection section: Int) -> Int {
        
        func rangeExists(_ range: NSRange, inString string: String) -> Bool {
            return range.location >= 0 && range.location != NSNotFound && range.location + range.length <= (string as NSString).length
        }
     
        func substring(with range: NSRange, in string: String) -> String? {
            if rangeExists(range, inString: string) {
                return (string as NSString).substring(with: range)
            } else {
                return nil
            }
        }
        
        var range = textView.contentTextView.selectedRange()
        
        if range.length > 1 {
            return 0
        }
        
        if substring(with: range, in: textView.text) == "" {
            
            range.length += 1
            
            if substring(with: range, in: textView.text) == "_" {
                return 0
            }
            
            range.location -= 1
            if rangeExists(range, inString: textView.text), let word = textView.contentTextView.word(in: range), let last = word.last, String(last) != substring(with: range, in: textView.text) {
                return 0
            }
            
            range.location += 2
            if rangeExists(range, inString: textView.text), let word = textView.contentTextView.word(in: range), let first = word.first, String(first) != substring(with: range, in: textView.text) {
                return 0
            }
        }
        
        return suggestions.count
    }
    
    func collectionView(_ collectionView: NSCollectionView, itemForRepresentedObjectAt indexPath: IndexPath) -> NSCollectionViewItem {
        
        guard suggestions.indices.contains(indexPath.item) else {
            return collectionView.makeItem(withIdentifier: codeCompletionCellID, for: indexPath)
        }
        
        let suggestion = suggestions[indexPath.item]
        
        if codeCompletionCellID == nil {
            codeCompletionCellID = NSUserInterfaceItemIdentifier("CodeCompletionViewItem")
            collectionView.register(NSNib(nibNamed: "CodeCompletionViewItem", bundle: nil), forItemWithIdentifier: codeCompletionCellID)
        }
        
        let item = collectionView.makeItem(withIdentifier: codeCompletionCellID, for: indexPath)
        (item as? CodeCompletionViewItem)?.titleLabel?.stringValue = suggestion
        (item as? CodeCompletionViewItem)?.selectionHandler = {
                        
            let index = indexPath.item
            
            guard self.completions.indices.contains(index), self.suggestions.indices.contains(index) else {
                return
            }
            
            if self.completions[index] != "" {
                self.textView.insertText(self.completions[index])
            }
        }
        
        return item
    }
    
    // MARK: - Collection view delegate flow layout
    
    func collectionView( _ collectionView: NSCollectionView, layout collectionViewLayout: NSCollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> NSSize {
        var width = CGFloat(suggestions[indexPath.item].count)*(NSFont(name: "Menlo", size: 17)?.pointSize ?? 17)
        if width <= 80 {
            width = 100
        }
        
        return CGSize(width: width, height: 30)
    }
    
    // MARK: - Touch bar delegate
    
    func touchBar(_ touchBar: NSTouchBar, makeItemForIdentifier identifier: NSTouchBarItem.Identifier) -> NSTouchBarItem? {
        
        if identifier == .candidateList {
            candidateListItem = NSCandidateListTouchBarItem<NSString>(identifier: identifier)
            candidateListItem.delegate = self
            candidateListItem.customizationLabel = "Completions"
            
            candidateListItem.attributedStringForCandidate = { (candidate, index) -> NSAttributedString in
                return NSAttributedString(string: candidate as String)
            }
            
            return candidateListItem
        } else if identifier == .run {
            let runItem = NSCustomTouchBarItem(identifier: identifier)
            touchBarRunButton = NSButton(image: NSImage(named: "NSTouchBarPlayTemplate") ?? NSImage(), target: self, action: #selector(run(_:)))
            touchBarRunButton?.isEnabled = !Python.shared.isScriptRunning
            runItem.view = touchBarRunButton ?? runItem.view
            return runItem
        } else if identifier == .stop {
            let stopItem = NSCustomTouchBarItem(identifier: identifier)
            touchBarStopButton = NSButton(image: NSImage(named: "NSTouchBarRecordStopTemplate") ?? NSImage(), target: self, action: #selector(stop(_:)))
            touchBarStopButton?.isEnabled = Python.shared.isScriptRunning
            stopItem.view = touchBarStopButton ?? stopItem.view
            return stopItem
        }
        
        return nil
    }
    
    // MARK: - Candidate list touch bar item delegate
    
    func candidateListTouchBarItem(_ anItem: NSCandidateListTouchBarItem<AnyObject>, endSelectingCandidateAt index: Int) {
        
        guard completions.indices.contains(index), suggestions.indices.contains(index) else {
            return
        }
        
        if completions[index] != "" {
            textView.insertText(self.completions[index])
        }
    }
}
