//
//  IO.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/24/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class for managing input and output.
@available(*, deprecated, message: "ios_system is not supported by Pyto anymore") class IO {
    
    /// The shared and unique instance.
    static let shared = IO()
    private init() {
        ios_stdout = fdopen(outputPipe.fileHandleForWriting.fileDescriptor, "w")
        ios_stderr = ios_stdout
        ios_stdin = fdopen(inputPipe.fileHandleForReading.fileDescriptor, "r")
        outputPipe.fileHandleForReading.readabilityHandler = { handle in
            if let str = String(data: handle.availableData, encoding: .utf8) {
                PyOutputHelper.print(str, script: nil)
            }
        }
    }
    
    /// The stdin file.
    var ios_stdin: UnsafeMutablePointer<FILE>?
    
    /// The stdout file.
    var ios_stdout: UnsafeMutablePointer<FILE>?
    
    /// The stderr file.
    var ios_stderr: UnsafeMutablePointer<FILE>?
    
    private var outputPipe = Pipe()
    private var inputPipe = Pipe()
    
    /// Sends given input for current running `ios_system` command.
    ///
    /// - Parameters:
    ///     - input: Input to send.
    func send(input: String) {
        if let data = input.data(using: .utf8) {
            inputPipe.fileHandleForWriting.write(data)
        }
    }
}
