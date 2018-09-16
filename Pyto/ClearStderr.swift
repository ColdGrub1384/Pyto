//
//  ClearStderr.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/16/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// Clears the Python stderr file.
func ClearStderr() {
    if FileManager.default.fileExists(atPath: pythonStderrPath) {
        try? FileManager.default.removeItem(atPath: pythonStderrPath)
    }
    FileManager.default.createFile(atPath: pythonStderrPath, contents: nil, attributes: nil)
}
