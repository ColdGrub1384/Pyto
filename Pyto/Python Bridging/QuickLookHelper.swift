//
//  QuickLookHelper.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/30/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import QuickLook

/// A class that helps Python scripts to preview a file.
@objc class QuickLookHelper: NSObject, QLPreviewControllerDataSource {
    
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
        
        guard Thread.current.isMainThread else {
            return DispatchQueue.main.sync {
                self.previewFile(file)
            }
        }
        
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
    
    // MARK: - Preview controller data source
    
    func numberOfPreviewItems(in controller: QLPreviewController) -> Int {
        self.controller = controller
        return filePaths.count
    }
    
    func previewController(_ controller: QLPreviewController, previewItemAt index: Int) -> QLPreviewItem {
        return URL(fileURLWithPath: filePaths[index]) as QLPreviewItem
    }
}
