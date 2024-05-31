//
//  PyMenuElement.swift
//  Pyto
//
//  Created by Emma on 01-02-23.
//  Copyright © 2023 Emma Labbé. All rights reserved.
//

import Foundation

@objc public class PyMenuElement: PyWrapper {
    
    var element: UIMenuElement {
        return managed as! UIMenuElement
    }
}
