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
    
    @available(iOS 15.0, *)
    struct WarningView: View {
        
        var warnings: [Linter.Warning]
        
        @State var selectedWarning: Linter.Warning?
        
        var textView: EditorTextView
        
        var vc: UIHostingController<AnyView>
        
        @State var isShowingWarnings = false
        
        var body: some View {
            HStack {
                Button {
                    withAnimation {
                        if selectedWarning != nil {
                            selectedWarning = nil
                        } else if warnings.count == 1 {
                            selectedWarning = warnings[0]
                        } else {
                            textView.resignFirstResponder()
                            isShowingWarnings = true
                        }
                    }
                } label: {
                    if (selectedWarning != nil && selectedWarning!.typeDescription.hasSuffix("error")) || (selectedWarning == nil && warnings.contains(where: { $0.typeDescription.hasSuffix("error") })) {
                        Image(systemName: "xmark.octagon.fill").foregroundColor(.red).font(.footnote)
                    } else {
                        Image(systemName: "exclamationmark.triangle.fill").foregroundColor(.yellow).font(.footnote)
                    }
                }.sheet(isPresented: $isShowingWarnings) {
                    NavigationView {
                        List {
                            Linter(editor: textView.next as? EditorViewController, fileURL: (textView.next as? EditorViewController)?.document?.fileURL ?? URL(fileURLWithPath: "/"), code: textView.text, warnings: warnings, showCode: false, language: (textView.next as? EditorViewController)?.document?.fileURL.pathExtension.lowercased() == "py" ? "python" : "objc")
                        }
                            .navigationTitle("Linter")
                            .toolbar {
                                Button {
                                    isShowingWarnings = false
                                } label: {
                                    Text("Done").bold()
                                }
                            }
                    }.navigationViewStyle(.stack)
                }.padding(.trailing, 3)
                
                if let selectedWarning = selectedWarning {
                    Text(selectedWarning.message)
                        .transition(.asymmetric(
                        insertion: .move(edge: .trailing),
                        removal: .identity))
                        .font(.system(size: CGFloat(ThemeFontSize-5)))
                }
            }.onChange(of: selectedWarning) { _ in
                vc.view.sizeToFit()
                vc.view.frame.origin.x = textView.frame.width-vc.view.frame.width
            }
                .padding(2)
                .background((warnings.contains(where: { $0.typeDescription.hasSuffix("error") }) ? Color.red : Color.yellow).opacity(0.3))
                .frame(maxWidth: textView.frame.width-50)
                .fixedSize()
                .transition(.asymmetric(
                    insertion: .move(edge: .trailing),
                    removal: .move(edge: .leading)))
        }
    }
    
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
    
    var warnings = [Any]() {
        didSet {
            placeWarnings()
        }
    }
    
    var warningViews = [UIHostingController<AnyView>]()
    
    func placeWarnings() {
        guard #available(iOS 15.0, *) else {
            return
        }
        
        for vc in warningViews {
            vc.removeFromParent()
            vc.view.removeFromSuperview()
        }
        
        var warnings = [Int: [Linter.Warning]]()
        for warning in (self.warnings as? [Linter.Warning]) ?? [] {
            if warnings[warning.lineno] != nil {
                warnings[warning.lineno]?.append(warning)
            } else {
                warnings[warning.lineno] = [warning]
            }
        }
        
        for warning in warnings {
            let vc = UIHostingController(rootView: AnyView(EmptyView()))
            vc.rootView = AnyView(WarningView(warnings: warning.value, textView: self, vc: vc))
            let view = vc.view!
            view.sizeToFit()
            
            let text = (self.text as NSString)
            var i = 1
            text.enumerateSubstrings(in: NSRange(location: 0, length: text.length), options: .byLines) { line, lineRange, _, stop in
                
                if i == warning.key {
                    stop.pointee = false
                    
                    guard let range = lineRange.toTextRange(textInput: self) else {
                        return
                    }
                    
                    view.frame.origin.y = self.firstRect(for: range).minY
                    view.frame.origin.x = self.frame.width-view.frame.width
                    (self.next as? UIViewController)?.addChild(vc)
                    self.addSubview(view)
                    self.warningViews.append(vc)
                }
                
                i += 1
            }
        }
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
            
            if (next as? EditorViewController)?.numberOfSuggestionsInInputAssistantView() != 0 {
                (next as? EditorViewController)?.nextSuggestion()
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
