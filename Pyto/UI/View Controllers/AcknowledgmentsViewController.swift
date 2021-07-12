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
        DispatchQueue.global().async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            let url = self.docsURL
            DispatchQueue.main.async { [weak self] in
                self?.webView.loadFileURL(url.appendingPathComponent("html/third_party.html"), allowingReadAccessTo: url)
            }
        }
    }
}
