//
//  PythonRuntime.swift
//  Pyto
//
//  Created by Adrian Labbé on 13-09-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

@objc protocol PythonRuntime {
    
    @objc func runCode(_ code: String)
    
    @objc func runScript(_ script: String)
    
    @objc func exitScript(_ script: String)
    
    @objc func interruptScript(_ script: String)
    
    @objc func runWidgetWithCode(_ code: String, andID id: String)
}
