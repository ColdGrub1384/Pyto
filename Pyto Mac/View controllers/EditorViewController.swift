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

/// A View controller for editing and running scripts.
class EditorViewController: NSViewController, SyntaxTextViewDelegate, NSTextViewDelegate, NSCollectionViewDataSource, NSCollectionViewDelegateFlowLayout {
    
    /// Clears console.
    @objc static func clear() {
        DispatchQueue.main.async {
            for window in NSApp.windows {
                if let editor = window.contentViewController as? EditorViewController {
                    editor.consoleTextView.string = ""
                    editor.console = ""
                }
            }
        }
    }
    
    /// Toggles stop and play button.
    @objc static func toggleStopButton() {
        DispatchQueue.main.async {
            for window in NSApp.windows {
                if let editor = window.contentViewController as? EditorViewController {
                    editor.stopButton.isEnabled = Python.shared.isScriptRunning
                    editor.runButton.isEnabled = !Python.shared.isScriptRunning
                }
            }
        }
    }
    
    // MARK: - Instance
    
    /// Console content.
    @objc var console = ""
    
    // MARK: - Code completion
    
    /// Collection view displaying suggestions.
    @IBOutlet weak var suggestionsCollectionView: NSCollectionView!
    
    /// Completions corresponding to `suggestions`.
    @objc var completions = [String]()
    
    /// Suggestions shown on the suggestions bar.
    @objc var suggestions = [String]()
    
    /// The identifier of the cell with the completion. Set to `nil` before the cell is registered.
    var codeCompletionCellID: NSUserInterfaceItemIdentifier!
    
    // MARK: - Running
    
    /// The prompt to send.
    var prompt = ""
    
    /// Runs code.
    @objc func run(_ sender: Any) {
        prompt = ""
        if let fileURL = document?.fileURL {
            document?.save(to: fileURL, ofType: "py", for: .autosaveAsOperation, completionHandler: { (error) in
                if let error = error {
                    self.consoleTextView.string += "\(error.localizedDescription)\n"
                } else {
                    Python.shared.runScript(at: fileURL)
                }
            })
        } else if !(sender is PyDocument) {
            document?.save(withDelegate: self, didSave: #selector(run(_:)), contextInfo: nil)
        }
    }
    
    /// Stops script.
    @objc func stop(_ sender: Any) {
        Python.shared.isScriptRunning = false
    }
    
    // MARK: - UI
    
    /// Button for stopping script.
    var stopButton: NSButton!
    
    /// Button for running script.
    var runButton: NSButton!
    
    /// A Split view containing the code editor and the console.
    @IBOutlet weak var splitView: NSSplitView!
    
    /// The text view containing the console.
    @IBOutlet var consoleTextView: NSTextView!
    
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
        
        consoleTextView.delegate = self
        consoleTextView.font = NSFont(name: "Menlo", size: 12)
        consoleTextView.isAutomaticQuoteSubstitutionEnabled = false
        consoleTextView.isAutomaticDashSubstitutionEnabled = false
        consoleTextView.isAutomaticDataDetectionEnabled = false
        consoleTextView.isAutomaticTextCompletionEnabled = false
        consoleTextView.isAutomaticSpellingCorrectionEnabled = false
        
        let textEditorSize = splitView.arrangedSubviews[0].frame.size
        
        splitView.removeArrangedSubview(splitView.arrangedSubviews[0])
        splitView.insertArrangedSubview(textView, at: 0)
        textView.frame.size = textEditorSize
        
        suggestionsCollectionView.enclosingScrollView?.scrollerInsets = NSEdgeInsets(top: 0, left: 0, bottom: 100, right: 0)
    }
    
    override func viewDidAppear() {
        super.viewDidAppear()
        
        for item in view.window?.toolbar?.items ?? [] {
            let button = item.view as? NSButton
            if item.tag == 1 {
                button?.action = #selector(run(_:))
                button?.target = self
                button?.isEnabled = !Python.shared.isScriptRunning
                runButton = button
            } else if item.tag == 2 {
                button?.action = #selector(stop(_:))
                button?.target = self
                button?.isEnabled = Python.shared.isScriptRunning
                stopButton = button
            }
        }
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
            } else {
                return true
            }
        } else if textView == consoleTextView {
            
            if let swiftRange = console.range(of: console), affectedCharRange.location < NSRange(swiftRange, in: console).length {
                // Only allow inserting text from the end
                return false
            }
            
            if (replacementString == "" || replacementString == nil) && affectedCharRange.length > 0 {
                if !prompt.isEmpty {
                    prompt.removeLast()
                }
            } else if replacementString == "\n", let data = (prompt+"\n").data(using: .utf8) {
                console += prompt+"\n"
                prompt = ""
                if Python.shared.isScriptRunning {
                    Python.shared.inputPipe.fileHandleForWriting.write(data)
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
        }
    }
    
    // MARK: - Collection view data source
    
    func collectionView(_ collectionView: NSCollectionView, numberOfItemsInSection section: Int) -> Int {
        
        func rangeExists(_ range: NSRange, inString string: String) -> Bool {
            return range.location != NSNotFound && range.location + range.length <= (string as NSString).length
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
            if let word = textView.contentTextView.word(in: range), let last = word.last, String(last) != substring(with: range, in: textView.text) {
                return 0
            }
            
            range.location += 2
            if let word = textView.contentTextView.word(in: range), let first = word.first, String(first) != substring(with: range, in: textView.text) {
                return 0
            }
        }
        
        return suggestions.count
    }
    
    func collectionView(_ collectionView: NSCollectionView, itemForRepresentedObjectAt indexPath: IndexPath) -> NSCollectionViewItem {
        
        if codeCompletionCellID == nil {
            codeCompletionCellID = NSUserInterfaceItemIdentifier("CodeCompletionViewItem")
            collectionView.register(NSNib(nibNamed: "CodeCompletionViewItem", bundle: nil), forItemWithIdentifier: codeCompletionCellID)
        }
        
        let item = collectionView.makeItem(withIdentifier: codeCompletionCellID, for: indexPath)
        (item as? CodeCompletionViewItem)?.titleLabel?.stringValue = suggestions[indexPath.item]
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
}

