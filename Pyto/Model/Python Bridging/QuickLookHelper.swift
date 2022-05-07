//
//  QuickLookHelper.swift
//  Pyto
//
//  Created by Emma Labbé on 1/30/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import QuickLook
#if MAIN
import WatchConnectivity
#endif

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
            DispatchQueue.main.asyncAfter(deadline: .now()+0.1) { [weak self] in
                self?.controller?.reloadData()
            }
        }
    }
    
    private var semaphore: Python.Semaphore?
    
    private init(filePaths: [String]) {
        self.filePaths = filePaths
    }
    
    /// The data source of the currently displaying controller.
    static var visible: QuickLookHelper?
        
    /// Images displayed for the last executed script.
    static var images = NSMutableArray()
    
    /// Rotation to be used on OpenCV images.
    ///
    /// - Parameters:
    ///     - device: Integer parameter to initialize `cv2.VideoCapture` object.
    ///
    /// - Returns: Rotation to be used on OpenCV images.
    @objc static func openCvRotation(_ device: Int) -> Double {
        var rotation: Double = 0
        let semaphore = Python.Semaphore(value: 0)
        
        DispatchQueue.main.async {
            switch UIApplication.shared.orientation {
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
        let semaphore = DispatchSemaphore(value: 0)
        DispatchQueue.main.async {
            
            guard let data = Data(base64Encoded: data, options: .ignoreUnknownCharacters), let image = UIImage(data: data) else {
                semaphore.signal()
                return
            }
            
            if !removePrevious {
                QuickLookHelper.images.add(image)
            }
            
            #if MAIN
            
            if script == Python.watchScriptURL.path {
                let letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
                let str = String((0..<10).map{ _ in letters.randomElement()! })
                
                let url = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(str)
                try? data.write(to: url)
                
                WCSession.default.transferFile(url, metadata: [:])
                semaphore.signal()
                return
            }
            
            for console in ConsoleViewController.visibles {
                
                if script != nil {
                    guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
                        continue
                    }
                }
                
                console.display(image: image, completionHandler: { _, _ in
                    
                    semaphore.signal()
                })
            }
                        
            #endif
        }
        
        semaphore.wait()
    }
    
    /// Quick looks the given files.
    @objc static func quickLook(_ path: [String], scriptPath: String?) {
        let semaphore = Python.Semaphore(value: 0)
        
        let helper = QuickLookHelper(filePaths: path)
        
        DispatchQueue.main.async {
            let vc = QLPreviewController()
            vc.dataSource = helper
            vc.delegate = helper
            helper.semaphore = semaphore
            
            for console in ConsoleViewController.visibles {
                
                if scriptPath != nil {
                    guard console.editorSplitViewController?.editor?.document?.fileURL.path == scriptPath else {
                        continue
                    }
                }
                
                console.present(vc, animated: true, completion: nil)
            }
        }
        
        semaphore.wait()
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
        semaphore?.signal()
    }
}
