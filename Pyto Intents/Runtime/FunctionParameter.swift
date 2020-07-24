//
//  FunctionParameter.swift
//  Pyto
//
//  Created by Adrian Labbé on 22-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

@objc class FunctionParameter: NSObject {
    
    @objc var stringValue: String?
    
    @objc var address: String?
    
    init(stringValue: String?, address: String?) {
        self.stringValue = stringValue
        self.address = address
    }
}
