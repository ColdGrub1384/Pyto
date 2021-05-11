//
//  EditorViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 2/14/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

extension EditorViewController {
    
    /// Highlights line with given color.
    ///
    /// // Taken from https://stackoverflow.com/a/49332122/7515957
    ///
    /// - Parameters:
    ///     - line: Line to highlight.
    ///     - color: The color used for highlighting.
    func highlight(at line: Int, with color: UIColor?) {
        
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
        
        func setBackgroundColor(_ color: UIColor?, forLine line: Int) {
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
        
        DispatchQueue.main.async { [weak self] in
        
            let errorColor = #colorLiteral(red: 0.6743632277, green: 0.1917540668, blue: 0.1914597603, alpha: 1)
            
            self?.highlight(at: lineNumber-1, with: errorColor.withAlphaComponent(0.5))
        }
    }
}
