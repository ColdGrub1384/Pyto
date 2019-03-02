//
//  LicensesViewController.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/22/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa

/// A View controller containing licenses.
class LicensesViewController: WebViewController {
    
    override var fileURL: URL? {
        return Bundle.main.url(forResource: "docs/Licenses", withExtension: "html")
    }
}
