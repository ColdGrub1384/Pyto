//
//  SetupPython.swift
//  WidgetExtension
//
//  Created by Adrian Labbé on 11-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

var isPythonSetup = false

func SetupPython() {
    
    guard !isPythonSetup else {
        return
    }
    
    isPythonSetup = true
    
    init_python()
    
    Python.shared.runScript(at: Bundle.main.url(forResource: "Startup", withExtension: "py")!)
}
