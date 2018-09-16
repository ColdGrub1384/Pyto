
//
//  Python.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class for interacting with `Cpython`
@objc class Python: NSObject {
    
    /// The shared and unique instance
    @objc static let shared = Python()
    
    private override init() {}
    
    /// The path where the stderr is redirected.
    @objc var stderrPath: String? {
        didSet {
            DispatchQueue.global().async { // Read stderr
                var output = ""
                while true {
                    do {
                        guard let stderrPath = self.stderrPath else {
                            continue
                        }
                        let newOutput = try String(contentsOfFile: stderrPath)
                        if output != newOutput {
                            NotificationCenter.default.post(name: .init(rawValue: "DidReceiveOutput"), object: newOutput.replacingFirstOccurrence(of: output, with: ""))
                            output = newOutput
                        }
                    } catch {
                        print(error.localizedDescription)
                    }
                }
            }
        }
    }
    
    /// The queue running scripts.
    @objc let queue = DispatchQueue.global()
    
    /// Run script at given URL. The only argument passed will be the file path.
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc func runScript(at url: URL) {
        queue.async {
            let file = fopen(url.path.cValue, "r")
            PyRun_AnyFileFlags(file, url.path.cValue, nil)
        }
    }
}
