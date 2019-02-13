//
//  ConsoleTextView.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/13/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa

/// A text view that responds to ^C and ^D.
class ConsoleTextView: NSTextView {

    /// Code called when ^C is pressed.
    var interruptionHandler: (() -> Void)?
    
    /// Code called when ^D is pressed.
    var eofHandler: (() -> Void)?
    
    // MARK: - Text view
    
    override func keyDown(with event: NSEvent) {
        if event.characters?.lowercased() == "\u{03}" {
            interruptionHandler?()
        } else if event.characters?.lowercased() == "\u{04}" {
            eofHandler?()
        } else {
            super.keyDown(with: event)
        }
    }
}
