//
//  AcknowledgmentsViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 1/1/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller that shows acknowledgments.
class AcknowledgmentsViewController: DocumentationViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        webView.stopLoading()
        if let url = Bundle.main.url(forResource: "docs/html", withExtension: "") {
            webView.loadFileURL(url.appendingPathComponent("third_party.html"), allowingReadAccessTo: url)
        }
    }
}
