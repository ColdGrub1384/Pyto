//
//  runPip.swift
//  Pyto
//
//  Created by Emma on 06-04-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import Foundation

fileprivate var queue = [DispatchSemaphore]()

fileprivate var isRunning = false

/// Runs pip with the given arguments.
///
/// - Parameters:
///     - arguments: The arguments without the program name.
///
/// - Returns: The standard ouput.
func runPip(arguments: [String]) -> String {
    
    if isRunning {
        let semaphore = DispatchSemaphore(value: 0)
        queue.append(semaphore)
        semaphore.wait()
    }
    
    isRunning = true
    
    let result = Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: """
    import runpy
    import sys
    import io
    from contextlib import redirect_stdout
            
    output = ""
            
    argv = sys.argv
    sys.argv = ["pip"]+\(arguments)
            
    with io.StringIO() as buf, redirect_stdout(buf):
        try:
            runpy.run_module("pip", run_name="__main__")
        except SystemExit:
            pass
        finally:
            sys.argv = []
            output = buf.getvalue()
            
    s = output
    """)
    
    if let lastQueue = queue.last {
        lastQueue.signal()
        queue.removeLast()
    }
    
    isRunning = false
    
    if let str = result?.takeUnretainedValue() as? String {
        return str
    } else {
        return ""
    }
}
