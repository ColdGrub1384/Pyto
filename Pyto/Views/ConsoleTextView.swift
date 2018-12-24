//
//  ConsoleTextView.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/18/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A text view containing the output of a Python program.
class ConsoleTextView: UITextView {

    private func setupView() {
        backgroundColor = .clear
        textColor = .black
        font = UIFont(name: "Courier", size: UIFont.systemFontSize)
        smartQuotesType = .no
        autocapitalizationType = .none
        autocorrectionType = .no
    }
    
    /// Scrolls to the bottom of the text view.
    func scrollToBottom() {
        let range = NSMakeRange((text as NSString).length - 1, 1)
        scrollRangeToVisible(range)
    }
    
    override func caretRect(for position: UITextPosition) -> CGRect {
        
        if position != endOfDocument {
            if selectedRange.length == 0 {
                return CGRect.zero
            } else {
                return super.caretRect(for: position)
            }
        }
        
        var rect = super.caretRect(for: position)
        rect.size.width = 10
        
        return rect
    }
    
    override init(frame: CGRect, textContainer: NSTextContainer?) {
        super.init(frame: frame, textContainer: textContainer)
        
        setupView()
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        
        setupView()
    }
    
    @discardableResult override func becomeFirstResponder() -> Bool {
        defer {
            (window?.topViewController as? REPLViewController)?.navigationItem.rightBarButtonItem?.isEnabled = true
        }
        return super.becomeFirstResponder()
    }
    
    @discardableResult override func resignFirstResponder() -> Bool {
        defer {
            (window?.topViewController as? REPLViewController)?.navigationItem.rightBarButtonItem?.isEnabled = false
        }
        return super.resignFirstResponder()
    }
}
