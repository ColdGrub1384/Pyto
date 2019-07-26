//
//  PyAction.swift
//  Pyto
//
//  Created by Adrian Labbé on 30-06-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Foundation

/// This class is used to represent a Python object. This object contains a reference to it.
@objc public class PyValue: NSObject {
    
    /// The name of the object stored in `_values` module.
    @objc public var identifier: String
    
    /// Initialize the value.
    ///
    /// - Parameters:
    ///     - identifier: The name of the object stored in `_values` module.
    @objc public init(identifier: String) {
        
        self.identifier = identifier
        
        super.init()
    }
    
    /// Calls the value as a function.
    ///
    /// - Parameters:
    ///     - parameter: The parameter to pass.
    @objc func call(parameter: PyValue?) {
        
        let code: String
        if let param = parameter {
            code = """
            import _values
            
            param = _values.\(param.identifier)
            func = _values.\(identifier)
            if func.__code__.co_argcount >= 1:
                func(param)
            else:
                func()
            """
        } else {
            code = """
            import _values
            
            _values.\(identifier)()
            """
        }
        
        Python.shared.run(code: code)
    }
}
