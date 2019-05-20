//
//  QuickLookHelper.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/30/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import QuickLook

fileprivate class ImageAttachment: NSTextAttachment {
    
    var verticalOffset: CGFloat = 0.0
    
    convenience init(_ image: UIImage, verticalOffset: CGFloat = 0.0) {
        self.init()
        self.image = image
        self.verticalOffset = verticalOffset
    }
    
    override func attachmentBounds(for textContainer: NSTextContainer?, proposedLineFragment lineFrag: CGRect, glyphPosition position: CGPoint, characterIndex charIndex: Int) -> CGRect {
       
        var rect = super.attachmentBounds(for: textContainer, proposedLineFragment: lineFrag, glyphPosition: position, characterIndex: charIndex)
        
        guard let size = textContainer?.size else {
            return rect
        }
        
        let width: CGFloat
        #if MAIN
        width = EditorSplitViewController.shouldShowConsoleAtBottom ? 400 : size.width
        #else
        width = size.width
        #endif
        
        rect.size.height = rect.height/(rect.width/width)
        rect.size.width = width
        
        /*
 
         w500 h300
         
         h300 xxx
         
        */
        
        return rect
    }
}

/// A class that helps Python scripts to preview a file.
@objc class QuickLookHelper: NSObject {
    
    /// Previews given file.
    ///
    /// - Parameters:
    ///     - file: The path of the file.
    @objc static func previewFile(_ file: String) {
        
        DispatchQueue.main.async {
            if let image = UIImage(contentsOfFile: file) {
                let attachment = ImageAttachment()
                attachment.image = image
                let attrString = NSMutableAttributedString(attributedString: NSAttributedString(attachment: attachment))
                attrString.append(NSAttributedString(string: "\n"))
                ConsoleViewController.visible.textView.textStorage.insert(attrString, at: ConsoleViewController.visible.textView.offset(from: ConsoleViewController.visible.textView.endOfDocument, to: ConsoleViewController.visible.textView.endOfDocument))
            }
        }
    }
}
