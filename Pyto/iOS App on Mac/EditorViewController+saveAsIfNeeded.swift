//
//  EditorViewController+saveAsIfNeeded.swift
//  Pyto
//
//  Created by Emma on 12/30/20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

extension EditorViewController {
    
    var isScriptInTemporaryLocation: Bool {
        return document?.fileURL.path.hasPrefix(FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].path) == true && isiOSAppOnMac
    }
    
    /// Shows an alert for saving the script if it's in a temporary location.
    func saveAsIfNeeded(close: Bool = false) {
        
        guard isScriptInTemporaryLocation else {
            return
        }
        
        if #available(iOS 14.0, *) {
            let picker = UIDocumentPickerViewController(forExporting: [document!.fileURL], asCopy: false)
            closeAfterSaving = true
            present(picker, animated: true)
            _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: true, block: { [weak self] (timer) in
                if self?.presentedViewController == nil, let session = self?.view.window?.windowScene?.session {
                    UIApplication.shared.requestSceneSessionDestruction(session, options: .none, errorHandler: nil)
                    timer.invalidate()
                }
            })
        }
    }
}
