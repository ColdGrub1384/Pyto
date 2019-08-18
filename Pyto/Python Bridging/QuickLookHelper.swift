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
    
    var textView: UITextView?
    
    var verticalOffset: CGFloat = 0.0
    
    convenience init(_ image: UIImage, verticalOffset: CGFloat = 0.0) {
        self.init()
        self.image = image
        self.verticalOffset = verticalOffset
    }
    
    override func attachmentBounds(for textContainer: NSTextContainer?, proposedLineFragment lineFrag: CGRect, glyphPosition position: CGPoint, characterIndex charIndex: Int) -> CGRect {
       
        var rect = super.attachmentBounds(for: textContainer, proposedLineFragment: lineFrag, glyphPosition: position, characterIndex: charIndex)
        
        guard let size = textView?.frame.size else {
            return rect
        }
        
        let width = size.width
        rect.size.height = rect.height/(rect.width/width)
        rect.size.width = width
        
        if rect.height > size.height {
            
            let height = size.height-10
            rect.size.width = rect.width/(rect.height/height)
            rect.size.height = height
        }
        
        return rect
    }
}

/// A class that helps Python scripts to preview a file.
@objc class QuickLookHelper: NSObject, QLPreviewControllerDataSource, QLPreviewControllerDelegate {
    
    private var controller: QLPreviewController?
    
    private var filePaths: [String] {
        didSet {
            DispatchQueue.main.asyncAfter(deadline: .now()+0.1) {
                self.controller?.reloadData()
            }
        }
    }
    
    private init(filePaths: [String]) {
        self.filePaths = filePaths
    }
    
    /// The data source of the currently displaying controller.
    static var visible: QuickLookHelper?
    
    /// Rotation to be used on OpenCV images.
    ///
    /// - Parameters:
    ///     - device: Integer parameter to initialize `cv2.VideoCapture` object.
    ///
    /// - Returns: Rotation to be used on OpenCV images.
    @objc static func openCvRotation(_ device: Int) -> Double {
        var rotation: Double = 0
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.main.async {
                        
            switch UIApplication.shared.statusBarOrientation {
            case .portrait:
                rotation = 0
            case .landscapeLeft:
                if device == 1 {
                    rotation = 90
                } else {
                    rotation = 270
                }
            case .landscapeRight:
                if device == 1 {
                    rotation = 270
                } else {
                    rotation = 90
                }
            default:
                rotation = 0
            }
            
            semaphore.signal()
        }
        
        if !Thread.current.isMainThread {
            semaphore.wait()
        }
        
        return rotation
    }
    
    /// Previews given file.
    ///
    /// - Parameters:
    ///     - data: Base 64 encoded string representing the image.
    ///     - script: The script that previewed the given file. Set to `nil` to show on all the consoles.
    ///     - removePrevious: A boolean indicating whether the previously shown images should be hidden. Used by OpenCV to display real time camera input.
    @objc static func previewFile(_ data: String, script: String?, removePrevious: Bool) {
                
        DispatchQueue.main.async {
            
            guard let data = Data(base64Encoded: data, options: .ignoreUnknownCharacters), let image = UIImage(data: data) else {
                return
            }
            
            let attachment = ImageAttachment()
            attachment.image = image
            let attrString = NSMutableAttributedString(attributedString: NSAttributedString(attachment: attachment))
            #if MAIN
            for console in ConsoleViewController.visibles {
                
                if script != nil {
                    guard console.editorSplitViewController?.editor.document?.fileURL.path == script else {
                        continue
                    }
                }
                
                if removePrevious {
                    let attrString = NSMutableAttributedString(attributedString: console.textView.attributedText)
                    var attachments = [NSRange]()
                    attrString.enumerateAttribute(.attachment, in: NSRange(location: 0, length: attrString.length), options: []) { (_, range, _) in
                        attachments.append(range)
                    }
                    for attachment in attachments {
                        attrString.removeAttribute(.attachment, range: attachment)
                    }
                    console.textView.attributedText = attrString
                }
                
                attachment.textView = console.textView
                
                console.textView.textStorage.insert(attrString, at: console.textView.offset(from: console.textView.beginningOfDocument, to: console.textView.endOfDocument))
                console.textView.scrollToBottom()
            }
            #else
            ConsoleViewController.visibles.first?.textView.textStorage.insert(attrString, at: ConsoleViewController.visibles[0].textView.offset(from: ConsoleViewController.visibles[0].textView.endOfDocument, to: ConsoleViewController.visibles[0].textView.endOfDocument))
            #endif
            
        }
    }
    
    // MARK: - Preview controller data source
    
    func numberOfPreviewItems(in controller: QLPreviewController) -> Int {
        self.controller = controller
        return filePaths.count
    }
    
    func previewController(_ controller: QLPreviewController, previewItemAt index: Int) -> QLPreviewItem {
        return URL(fileURLWithPath: filePaths[index]) as QLPreviewItem
    }
    
    // MARK: - Preview controller delegate
    
    func previewControllerDidDismiss(_ controller: QLPreviewController) {
        QuickLookHelper.visible = nil
    }
}
