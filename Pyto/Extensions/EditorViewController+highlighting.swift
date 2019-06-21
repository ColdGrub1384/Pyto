//
//  EditorViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 2/14/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
typealias Color = UIColor

extension EditorViewController {
    
    /// Highlights line with given color.
    ///
    /// // Taken from https://stackoverflow.com/a/49332122/7515957
    ///
    /// - Parameters:
    ///     - line: Line to highlight.
    ///     - color: The color used for highlighting.
    func highlight(at line: Int, with color: Color?) {
        
        let storage: NSTextStorage? = textView.contentTextView.textStorage
        
        let textStorage = self.textView.contentTextView.textStorage
        
        // Use NSString here because textStorage expects the kind of ranges returned by NSString,
        // not the kind of ranges returned by String.
        let string = textStorage.string
        
        let storageString = string as NSString
        
        var lineRanges = [NSRange]()
        storageString.enumerateSubstrings(in: NSMakeRange(0, storageString.length), options: .byLines, using: { (_, lineRange, _, _) in
            lineRanges.append(lineRange)
        })
        
        func setBackgroundColor(_ color: Color?, forLine line: Int) {
            guard lineRanges.indices.contains(line) else {
                return
            }
            if let color = color {
                storage?.addAttribute(.backgroundColor, value: color, range: lineRanges[line])
            } else {
                storage?.removeAttribute(.backgroundColor, range: lineRanges[line])
            }
        }
        setBackgroundColor(color, forLine: line)
    }
    
    /// Shows an error at given line.
    ///
    /// - Parameters:
    ///     - lineNumber: The number of the line that caused the error.
    @objc func showErrorAtLine(_ lineNumber: Int) {
        
        DispatchQueue.main.async {
        
            let errorColor = #colorLiteral(red: 0.6743632277, green: 0.1917540668, blue: 0.1914597603, alpha: 1)
            
            guard self.parent?.presentedViewController == nil, self.view.window != nil else {
                self.lineNumberError = lineNumber
                return
            }
            
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
            errorVC.view.backgroundColor = errorColor
            errorVC.preferredContentSize = CGSize(width: 300, height: 100)
            errorVC.modalPresentationStyle = .popover
            errorVC.presentationController?.delegate = errorVC
            errorVC.popoverPresentationController?.backgroundColor = errorColor
            
            if let selectedTextRange = self.textView.contentTextView.selectedTextRange {
                errorVC.popoverPresentationController?.sourceView = self.textView.contentTextView
                errorVC.popoverPresentationController?.sourceRect = self.textView.contentTextView.caretRect(for: selectedTextRange.end)
            } else {
                errorVC.popoverPresentationController?.sourceView = self.textView.contentTextView
                errorVC.popoverPresentationController?.sourceRect = self.textView.contentTextView.bounds
            }
            
            self.present(errorVC, animated: true, completion: nil)
            
            self.highlight(at: lineNumber-1, with: errorColor.withAlphaComponent(0.5))
        }
    }
}
