#if os(iOS)
import UIKit
typealias TextView = UITextView
typealias Range = UITextRange
#elseif os(macOS)
import Cocoa
typealias TextView = NSTextView
typealias Range = NSRange
#endif

extension TextView {
    
    // MARK: - Words
    
    /// Returns the range of the selected word.
    var currentWordRange: Range? {
        #if os(iOS)
        let beginning = beginningOfDocument
        
        if let start = position(from: beginning, offset: selectedRange.location),
            let end = position(from: start, offset: selectedRange.length) {
            
            let textRange = tokenizer.rangeEnclosingPosition(end, with: .word, inDirection: UITextDirection(rawValue: 1))
            
            return textRange ?? selectedTextRange
        }
        return selectedTextRange
        #elseif os(macOS)
        return selectionRange(forProposedRange: selectedRange(), granularity: .selectByWord)
        #endif
    }
    
    /// Returns the current typed word.
    var currentWord : String? {
        if let textRange = currentWordRange {
            #if os(iOS)
            return text(in: textRange)
            #elseif os(macOS)
            return (string as NSString).substring(with: textRange)
            #endif
        } else {
            return nil
        }
    }
    
    #if os(macOS)
    func rangeExists(_ range: NSRange) -> Bool {
        return range.location != NSNotFound && range.location + range.length <= (string as NSString).length
    }
    #endif
    
    /// Returns word in given range.
    ///
    /// - Parameters:
    ///     - range: Range contained by the word.
    ///
    /// - Returns: Word in given range.
    func word(in range: NSRange) -> String? {
        
        #if os(iOS)
        var wordRange: UITextRange? {
            let beginning = beginningOfDocument
            
            if let start = position(from: beginning, offset: range.location),
                let end = position(from: start, offset: range.length) {
                
                let textRange = tokenizer.rangeEnclosingPosition(end, with: .word, inDirection: UITextDirection(rawValue: 1))
                
                return textRange ?? selectedTextRange
            }
            return selectedTextRange
        }
        
        if let textRange = wordRange {
            return text(in: textRange)
        }
        
        return nil
        #else
        if !rangeExists(range) {
            return nil
        }
        let range_ = selectionRange(forProposedRange: range, granularity: .selectByWord)
        if !rangeExists(range_) {
            return nil
        }
        return (string as NSString).substring(with: range_)
        #endif
    }
    
    // MARK: - Lines
    
    #if os(iOS)
    
    /// Gets the entire line range from given range.
    ///
    /// - Parameters:
    ///     - range: The range contained in returned line.
    ///
    /// - Returns: The entire line range.
    func line(at range: NSRange) -> UITextRange? {
        let beginning = beginningOfDocument
        
        if let start = position(from: beginning, offset: range.location),
            let end = position(from: start, offset: range.length) {
            
            let textRange = tokenizer.rangeEnclosingPosition(end, with: .line, inDirection: UITextDirection(rawValue: 1))
            
            return textRange ?? selectedTextRange
        }
        return selectedTextRange
    }
    
    /// Returns the range of the selected line.
    var currentLineRange: UITextRange? {
        return line(at: selectedRange)
    }
    
    /// Returns the current selected line.
    var currentLine : String? {
        if let textRange = currentLineRange {
            return text(in: textRange)
        } else {
            return nil
        }
    }
    #endif
    
    // MARK: - Other
    
    /// Scrolls to the bottom of the text view.
    func scrollToBottom() {
        
        #if os(iOS)
        let text_ = text
        #elseif os(macOS)
        let text_ = string
        #endif
        
        let range = NSMakeRange(((text_ ?? "") as NSString).length - 1, 1)
        scrollRangeToVisible(range)
    }
}
