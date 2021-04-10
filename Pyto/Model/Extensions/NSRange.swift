//
//  NSRange.swift
//  Pyto
//
//  Created by Emma Labbé on 1/23/19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
//

import UIKit

// Taken from https://stackoverflow.com/a/46268900/7515957

extension NSRange {
    
    func toTextRange(textInput:UITextInput) -> UITextRange? {
        if let rangeStart = textInput.position(from: textInput.beginningOfDocument, offset: location),
            let rangeEnd = textInput.position(from: rangeStart, offset: length) {
            return textInput.textRange(from: rangeStart, to: rangeEnd)
        }
        return nil
    }
}
