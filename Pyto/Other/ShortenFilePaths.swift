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
    
    let docs = FileBrowserViewController.localContainerURL
    
    text = str.replacingOccurrences(of: docs.path, with: "Documents")
    text = text.replacingOccurrences(of: "/privateDocuments", with: "Documents")
    if let iCloudDrive = FileBrowserViewController.iCloudContainerURL {
        text = text.replacingOccurrences(of: iCloudDrive.path, with: "iCloud Drive")
        text = text.replacingOccurrences(of: iCloudDrive.deletingLastPathComponent().lastPathComponent, with: "iCloud Drive")
    }
    
    text = text.replacingOccurrences(of: Bundle.main.bundlePath, with: "Pyto.app")
    text = text.replacingOccurrences(of: "/privatePyto.app", with: "Pyto.app")
        
    text = text.replacingOccurrences(of: (URL(fileURLWithPath: "/private").appendingPathComponent(docs.deletingLastPathComponent().path).path).replacingOccurrences(of: "//", with: "/")+"/", with: "")
    text = text.replacingOccurrences(of: URL(fileURLWithPath: "/private").appendingPathComponent(docs.deletingLastPathComponent().path).path.replacingOccurrences(of: "//", with: "/"), with: "")
    text = text.replacingOccurrences(of: docs.deletingLastPathComponent().path+"/", with: "")
    text = text.replacingOccurrences(of: docs.deletingLastPathComponent().path, with: "")
    
    return text
    #else
    return str
    #endif
}
