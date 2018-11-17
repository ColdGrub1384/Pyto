//
//  RelativePathForScript.swift
//  Pyto
//
//  Created by Adrian Labbe on 11/16/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// Get the path for the given script relative to the Documents directory.
///
/// - Parameters:
///     - url: The full script's URL.
///
/// - Returns:
///     - The relative path.
func RelativePathForScript(_ url: URL) -> String {
    var filePath = url.path.replacingFirstOccurrence(of: FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].path, with: "")
    
    if filePath.hasPrefix("/private/") {
        filePath = filePath.replacingFirstOccurrence(of: "/private/", with: "")
    }
    
    if filePath.hasPrefix("/") {
        filePath.removeFirst()
    }
    
    return filePath
}
