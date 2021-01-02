//
//  openEmptyScript.swift
//  Pyto
//
//  Created by Emma on 12/29/20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

/// Opens an empty script in a new window.
func openEmptyScript(onWindow window: UIWindow?) {
    
    var url = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent(Localizable.untitled)
    var i = 1
    while FileManager.default.fileExists(atPath: url.appendingPathExtension("py").path) {
        i += 1
        url = url.deletingLastPathComponent().appendingPathComponent(Localizable.untitled+" \(i)")
    }
    
    url = url.appendingPathExtension("py")
    
    FileManager.default.createFile(atPath: url.path, contents: nil, attributes: nil)
    
    guard let editor = DocumentBrowserViewController().openDocument(url, run: false, show: false) else {
        return
    }
    
    editor.editor?.setupToolbarIfNeeded(windowScene: window?.windowScene)
    let navVC = EditorSplitViewController.NavigationController(rootViewController: editor)
    navVC.isNavigationBarHidden = true
    window?.rootViewController = navVC
}
