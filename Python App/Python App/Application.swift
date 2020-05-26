//
//  Application.swift
//  Python App
//
//  Created by Adrian Labbé on 26-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

@objc class Application: NSObject {
    
    // Methods shared with Python here
    
    @objc func helloWorld() -> String {
        return "Hello World"
    }
}
