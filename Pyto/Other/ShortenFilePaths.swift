//
//  ShortenFilePaths.swift
//  Pyto
//
//  Created by Emma Labbé on 5/14/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation

/// Shortens file paths accesable from the app.
///
/// - Parameters:
///     - str: The string containing paths.
///
/// - Returns: The given string with shortened file paths.
func ShortenFilePaths(in str: String) -> String {
    
    #if MAIN
    var text = str
    
    let home = FileBrowserViewController.localContainerURL.deletingLastPathComponent()
    
    text = str.replacingOccurrences(of: home.path, with: "~")
    text = text.replacingOccurrences(of: "/private~", with: "~")
    if let iCloudDrive = FileBrowserViewController.iCloudContainerURL {
        text = text.replacingOccurrences(of: iCloudDrive.path, with: "$ICLOUD")
        text = text.replacingOccurrences(of: iCloudDrive.deletingLastPathComponent().lastPathComponent, with: "$ICLOUD")
    }
    
    text = text.replacingOccurrences(of: Bundle.main.bundlePath, with: "$APP")
    text = text.replacingOccurrences(of: "/privatePyto.app", with: "$APP")
        
    text = text.replacingOccurrences(of: (URL(fileURLWithPath: "/private").appendingPathComponent(home.deletingLastPathComponent().path).path).replacingOccurrences(of: "//", with: "/")+"/", with: "")
    text = text.replacingOccurrences(of: URL(fileURLWithPath: "/private").appendingPathComponent(home.deletingLastPathComponent().path).path.replacingOccurrences(of: "//", with: "/"), with: "")
    text = text.replacingOccurrences(of: home.deletingLastPathComponent().path+"/", with: "")
    text = text.replacingOccurrences(of: home.deletingLastPathComponent().path, with: "")
    
    return text
    #else
    return str
    #endif
}
