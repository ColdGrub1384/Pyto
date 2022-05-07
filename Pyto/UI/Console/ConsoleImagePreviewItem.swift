//
//  ConsoleImagePreviewItem.swift
//  Pyto
//
//  Created by Emma on 23-04-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import QuickLook

class ConsoleImagePreviewItem: NSObject, QLPreviewItem {
    
    init?(base64EncodedString: String, title: String) {
        guard let data = Data(base64Encoded: base64EncodedString.components(separatedBy: "base64,").last ?? base64EncodedString) else {
            return nil
        }
        
        previewItemURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(UUID().uuidString).appendingPathExtension("png")
        
        do {
            try data.write(to: previewItemURL!)
        } catch {
            return nil
        }
        
        previewItemTitle = title
    }
    
    deinit {
        if let url = previewItemURL {
            try? FileManager.default.removeItem(at: url)
        }
    }
    
    var previewItemURL: URL?
    
    var previewItemTitle: String?
}
