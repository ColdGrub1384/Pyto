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
        let url = Bundle.main.url(forResource: "docs_build", withExtension: nil)!
        webView.loadFileURL(url.appendingPathComponent("html/third_party.html"), allowingReadAccessTo: url)
    }
}
