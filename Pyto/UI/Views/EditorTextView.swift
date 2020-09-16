//
//  EditorTextView.swift
//  Pyto
//
//  Created by Adrian Labbé on 24-08-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

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
    
    override var keyCommands: [UIKeyCommand]? {
        let undoCommand = UIKeyCommand.command(input: "z", modifierFlags: .command, action: #selector(undo), discoverabilityTitle: Localizable.MenuItems.undo)
        let redoCommand = UIKeyCommand.command(input: "z", modifierFlags: [.command, .shift], action: #selector(redo), discoverabilityTitle: Localizable.MenuItems.redo)
        
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
