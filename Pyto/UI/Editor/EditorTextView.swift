//
//  EditorTextView.swift
//  Pyto
//
//  Created by Emma Labbé on 24-08-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import SwiftUI

/// An `UITextView` to be used on the editor.
class EditorTextView: LineNumberTextView, UITextViewDelegate {
    
    /// Undo.
    @objc func undo() {
        let theDelegate = delegate
        delegate = nil
        undoManager?.undo()
        delegate = theDelegate
    }
    
    /// Redo.
    @objc func redo() {
        let theDelegate = delegate
        delegate = nil
        undoManager?.redo()
        delegate = theDelegate
    }
    
    @objc override func find(_ sender: Any?) {
        var next = self.next
        while !(next is EditorViewController) && next != nil {
            next = next?.next
        }
        
        (next as? EditorViewController)?.search()
    }
        
    override func canPerformAction(_ action: Selector, withSender sender: Any?) -> Bool {
        if action == #selector(undo) {
            return undoManager?.canUndo ?? false
        } else if action == #selector(redo) {
            return undoManager?.canRedo ?? false
        } else {
            return super.canPerformAction(action, withSender: send)
        }
    }
    
    override func pressesBegan(_ presses: Set<UIPress>, with event: UIPressesEvent?) {
        
        if #available(iOS 15.0, *), presses.first?.key?.keyCode == .keyboardTab {
            var next = self.next
            while !(next is EditorViewController) && next != nil {
                next = next?.next
            }
            
            guard let editor = next as? EditorViewController else {
                return super.pressesBegan(presses, with: event)
            }
            
            if editor.numberOfSuggestionsInInputAssistantView() != 0 {
                editor.nextSuggestion()
                return
            }
        }
        
        super.pressesBegan(presses, with: event)
    }
    
    override var keyCommands: [UIKeyCommand]? {
        
        if #available(iOS 15.0, *) {
            return nil
        }
        
        let undoCommand = UIKeyCommand.command(input: "z", modifierFlags: .command, action: #selector(undo), discoverabilityTitle: NSLocalizedString("menuItems.undo", comment: "The 'Undo' menu item"))
        let redoCommand = UIKeyCommand.command(input: "z", modifierFlags: [.command, .shift], action: #selector(redo), discoverabilityTitle: NSLocalizedString("menuItems.redo", comment: "The 'Redo' menu item"))
        
        var commands = [UIKeyCommand]()
        
        if undoManager?.canUndo == true {
            commands.append(undoCommand)
        }
        
        if undoManager?.canRedo == true {
            commands.append(redoCommand)
        }
        
        return commands
    }
    
    override var canBecomeFirstResponder: Bool {
        return true
    }
    
    override func paste(_ sender: Any?) {
        let theDelegate = delegate
        delegate = self
        
        if let range = selectedTextRange, let pasteboard = UIPasteboard.general.string {
            replace(range, withText: pasteboard)
        }
        
        delegate = theDelegate
    }
    
    override func cut(_ sender: Any?) {
        let theDelegate = delegate
        delegate = self
        
        if let range = selectedTextRange {
            let text = self.text(in: range)
            UIPasteboard.general.string = text
            replace(range, withText: "")
        }
        
        delegate = theDelegate
    }
    
    // Fixes a weird bug while cutting
    func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        if text == "" && range.length > 1 {
            textView.replace(range.toTextRange(textInput: textView) ?? UITextRange(), withText: text)
            return false
        } else {
            return true
        }
    }
}
