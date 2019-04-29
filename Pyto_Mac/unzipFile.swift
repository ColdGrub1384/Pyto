//
//  unzipFile.swift
//  Pyto
//
//  Created by Adrian Labbé on 4/28/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Foundation

/// Unzips a file to a given destination
///
/// - Parameters:
///     - sourcePath: The zip file to extract,
///     - destinationPath: The path where the file will be extracted.
///
/// - Returns: `true` if the file is successfully extracted.
@discardableResult func unzipFile(at sourcePath: String, to destinationPath: String) -> Bool {
    let process = Process.launchedProcess(launchPath: "/usr/bin/unzip", arguments: ["-o", sourcePath, "-d", destinationPath])
    process.waitUntilExit()
    return process.terminationStatus <= 1
}
