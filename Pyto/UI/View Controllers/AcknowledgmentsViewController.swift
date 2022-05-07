//
//  AcknowledgmentsViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 1/1/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

/// A View controller that shows acknowledgments.
class AcknowledgmentsViewController: DocumentationViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        webView.stopLoading()
        
        Task {
            let _doc = try await Self.getPytoDocumentation()
            await MainActor.run {
                guard var doc = _doc else {
                    return
                }
                doc.pageURL = doc.url.deletingLastPathComponent().appendingPathComponent("third_party.html")
                selectedDocumentation = doc
            }
        }
    }
}
