//
//  ConsoleTextView.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/18/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A text view containing the output of a Python program.
public class ConsoleTextView: UITextView {

    private func setupView() {
        backgroundColor = .clear
        textColor = .black
        font = UIFont(name: "Courier", size: UIFont.systemFontSize)
        smartQuotesType = .no
        smartDashesType = .no
        autocapitalizationType = .none
        autocorrectionType = .no
    }
    
    public override func caretRect(for position: UITextPosition) -> CGRect {
        
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
    
    public override init(frame: CGRect, textContainer: NSTextContainer?) {
        super.init(frame: frame, textContainer: textContainer)
        
        setupView()
    }
    
    public required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        
        setupView()
    }
}
