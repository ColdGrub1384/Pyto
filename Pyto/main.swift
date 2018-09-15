//
//  main.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/15/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

// MARK: - Initialize Python

/// The path of the Python home directory.
guard let pythonHome = Bundle.main.path(forResource: "Library/Python.framework/Resources", ofType: "") else {
    fatalError("python: python home directory doesn't exist")
}

putenv("PYTHONOPTIMIZE=".cValue)
putenv("PYTHONDONTWRITEBYTECODE=1".cValue)
putenv("TMP=\(NSTemporaryDirectory())".cValue)
putenv("PYTHONHOME=\(pythonHome)".cValue)

Py_SetPythonHome(pythonHome.cWchar_t)
Py_Initialize()

// MARK: - Stderr

/// The path of the file where errors are printed.
let pythonStderrPath = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("errors").path

if FileManager.default.fileExists(atPath: pythonStderrPath) {
    try? FileManager.default.removeItem(atPath: pythonStderrPath)
}
FileManager.default.createFile(atPath: pythonStderrPath, contents: nil, attributes: nil)

DispatchQueue.global().async {
    var output = ""
    while true {
        do {
            let newOutput = try String(contentsOfFile: pythonStderrPath)
            if output != newOutput {
                NotificationCenter.default.post(name: .init(rawValue: "DidReceiveOutput"), object: newOutput.replacingFirstOccurrence(of: output, with: ""))
                output = newOutput
            }
        } catch {
            print(error.localizedDescription)
        }
    }
}

// MARK: - Initialize the UI

_ = UIApplicationMain(CommandLine.argc, CommandLine.unsafeArgv, nil, NSStringFromClass(AppDelegate.self))
