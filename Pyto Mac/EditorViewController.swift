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
class EditorViewController: NSViewController, SyntaxTextViewDelegate, NSTextViewDelegate {
    
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
    
    /// Console content.
    @objc var console = ""
    
    /// Prints text when notification is called.
    @objc static func print(_ notification: Notification) {
        if let str = notification.object as? String {
            
            DispatchQueue.main.async {
                for window in NSApp.windows {
                    if let editor = window.contentViewController as? EditorViewController {
                        editor.consoleTextView.string += str
                        editor.console += str
                    }
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
                Python.shared.inputPipe.fileHandleForWriting.write(data)
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
        }
    }
}

