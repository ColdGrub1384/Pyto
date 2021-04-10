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
    
    deinit {
        print("Deallocated \(self)")
    }
    
    /// The name of the object stored in `_values` module.
    @objc public var identifier: String
    
    /// The path of the script that created the value.
    @objc public var scriptPath: String?
    
    @objc private static var scriptPath: String?
    
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
    ///     - onMainThread: If set to `true`, will execute the function on the main thread.
    @objc func call(parameter: PyValue?, onMainThread: Bool = false) {
        
        var code = "import threading\n"
        
        if let path = scriptPath {
            PyValue.scriptPath = path
            code += """
            from _Pyto import PyValue

            script_path = str(PyValue.scriptPath)
            """
        } else {
            code += """
            script_path = None
            """
        }
        
        if let param = parameter {
            code += """

            code = '''import _values
                        
            if "\(param.identifier)" in dir(_values) and "\(identifier)" in dir(_values):
            
                param = _values.\(param.identifier)
                func = _values.\(identifier)
                if func.__code__.co_argcount == 1 and "__self__" in dir(func):
                    func()
                elif func.__code__.co_argcount >= 1:
                    func(param)
                else:
                    func()'''

            """
        } else {
            code += """

            code = '''import _values
            
            if "\(identifier)" in dir(_values):
                _values.\(identifier)()'''

            """
        }
        if onMainThread {
            
            code += "\nexec(code)"
            
            DispatchQueue.main.async {
                Python.pythonShared?.performSelector(inBackground: #selector(PythonRuntime.runCode(_:)), with: code)
            }
        } else {

            code += """
            thread = threading.Thread(target=exec, args=(code,))
            if script_path is not None:
                thread.script_path = script_path
            thread.start()
            """

            Python.shared.run(code: code)
        }
    }
}
