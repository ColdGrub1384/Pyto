import UIKit
#if MAIN
import SavannaKit
#endif

extension UITextView {
    
    // MARK: - Words
    
    /// Returns the range of the selected word with underscores.
    var currentWordWithUnderscoreRange: UITextRange? {
        guard var range = currentWordRange else {
            return nil
        }
        
        var text = self.text(in: range) ?? ""
        while !text.isEmpty && ![
            "\t",
            " ",
            "(",
            "[",
            "{",
            "\"",
            "\'",
            "\n",
            ",",
            "."
        ].contains(String(text.first ?? Character(""))) {
            guard let newStart = position(from: range.start, offset: -1), let newPos = textRange(from: newStart, to: range.end) else {
                break
            }
            
            range = newPos
            text = self.text(in: range) ?? ""
        }
        
        if let pos = position(from: range.start, offset: 1), let newRange = textRange(from: pos, to: range.end) {
            range = newRange
        }
        
        return range
    }
    
    /// Returns the range of the selected word.
    var currentWordRange: UITextRange? {
        let beginning = beginningOfDocument
        
        if let start = position(from: beginning, offset: selectedRange.location),
            let end = position(from: start, offset: selectedRange.length) {
            
            let textRange = tokenizer.rangeEnclosingPosition(end, with: .word, inDirection: UITextDirection(rawValue: 1))
            
            return textRange ?? selectedTextRange
        }
        return selectedTextRange
    }
    
    /// Returns the current typed word.
    var currentWord : String? {
        if let textRange = currentWordRange {
            return text(in: textRange)
        } else {
            return nil
        }
    }
    
    /// Returns word in given range.
    ///
    /// - Parameters:
    ///     - range: Range contained by the word.
    ///
    /// - Returns: Word in given range.
    func word(in range: NSRange) -> String? {
        
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
    }
    
    // MARK: - Lines
    
    /// Get the entire line range from given range.
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
    
    // MARK: - Other
    
    /// Scrolls to the bottom of the text view.
    func scrollToBottom() {
        let range = NSMakeRange(((text ?? "") as NSString).length - 1, 1)
        scrollRangeToVisible(range)
    }
}
