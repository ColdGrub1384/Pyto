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
        
        var doc = Documentation.pyto
        doc.pageURL = doc.url.deletingLastPathComponent().appendingPathComponent("third_party.html")
        selectedDocumentation = doc
    }
}
