//
//  DocumentationViewController.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/22/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa
import WebKit

/// A View controller containing documentation.
class DocumentationViewController: WebViewController {
    
    override var fileURL: URL? {
        return Bundle.main.url(forResource: "docs/index", withExtension: "html")
    }
}
