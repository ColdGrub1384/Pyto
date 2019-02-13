//
//  NSImage+init.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/12/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa

extension NSImage {
    
    /// Return a image with text drawn on top of it.
    ///
    /// - Parameters:
    ///   - text: The text to draw on image.
    ///   - attributes: Attributes of the text.
    ///   - backgroundColor: The background color of the image.
    /// - Returns: The image with text.
    func image(withCenterDrawnText text: String, attributes: [NSAttributedString.Key: Any], backgroundColor: NSColor) -> NSImage {
        let image = self
        let text = text as NSString
        let options: NSString.DrawingOptions = [.usesLineFragmentOrigin, .usesFontLeading]
        
        let textSize = text.boundingRect(with: image.size, options: options, attributes: attributes).size
        
        let x = (image.size.width - textSize.width) / 2
        let y = (image.size.height - textSize.height) / 2
        let point = NSMakePoint(x, y)
        
        image.lockFocus()
        backgroundColor.setFill()
        CGRect(x: 0, y: 0, width: size.width, height: size.height).fill()
        text.draw(at: point, withAttributes: attributes)
        image.unlockFocus()
        
        return image
    }
}
