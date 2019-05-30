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
    
    /// Previews given file.
    ///
    /// - Parameters:
    ///     - file: The path of the file.
    @objc static func previewFile(_ file: String) {
        DispatchQueue.main.async {
            
            func showOnConsole() {
                guard let image = UIImage(contentsOfFile: file) else {
                    return
                }
                let attachment = ImageAttachment()
                attachment.image = image
                let attrString = NSMutableAttributedString(attributedString: NSAttributedString(attachment: attachment))
                attrString.append(NSAttributedString(string: "\n"))
                ConsoleViewController.visible.textView.textStorage.insert(attrString, at: ConsoleViewController.visible.textView.offset(from: ConsoleViewController.visible.textView.endOfDocument, to: ConsoleViewController.visible.textView.endOfDocument))
            }
            
            #if MAIN
            if !EditorSplitViewController.shouldShowConsoleAtBottom {
                showOnConsole()
            } else {
                DispatchQueue.main.async {
                    guard visible == nil else {
                        visible?.filePaths.append(file)
                        return
                    }
                    
                    for fileURL in ((try? FileManager.default.contentsOfDirectory(at: URL(fileURLWithPath: NSTemporaryDirectory()), includingPropertiesForKeys: nil, options: .skipsHiddenFiles)) ?? []) {
                        if fileURL.path != file {
                            try? FileManager.default.removeItem(at: fileURL)
                        }
                    }
                    
                    let dataSource = QuickLookHelper(filePaths: [file])
                    
                    let controller = QLPreviewController()
                    controller.dataSource = dataSource
                    controller.delegate = dataSource
                    
                    #if MAIN || WIDGET
                    var vc: UIViewController?
                    if ConsoleViewController.visible.view.window != nil {
                        vc = ConsoleViewController.visible
                    }
                    #if MAIN
                    if vc == nil, let browser = DocumentBrowserViewController.visible {
                        vc = browser
                    }
                    
                    if vc == nil {
                        return
                    }
                    #endif
                    #else
                    let vc = UIApplication.shared.keyWindow?.topViewController
                    #endif
                    
                    visible = dataSource
                    
                    vc?.present(controller, animated: true, completion: nil)
                }
            }
            #else
            showOnConsole()
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
