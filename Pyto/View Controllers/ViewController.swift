//
//  ViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// The main file browser used to edit scripts.
class ViewController: UIDocumentBrowserViewController, UIDocumentBrowserViewControllerDelegate {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        browserUserInterfaceStyle = .dark
        allowsDocumentCreation = true
        allowsPickingMultipleItems = false
        customActions = [UIDocumentBrowserAction(identifier: "run", localizedTitle: "Run", availability: .menu, handler: { (urls) in
            self.openDocument(urls[0], run: true)
        })]
        delegate = self
    }
    
    /// Opens the given script.
    ///
    /// - Parameters:
    ///     - document: The URL of the script.
    ///     - run: Set to `true` to run the script inmediately.
    func openDocument(_ document: URL, run: Bool) {
        Py_SetProgramName(document.lastPathComponent.cWchar_t)
        
        let doc = PyDocument(fileURL: document)
        let editor = EditorViewController(document: doc)
        let navVC = UINavigationController(rootViewController: editor)
        navVC.navigationBar.barStyle = .black
        navVC.tabBarItem = UITabBarItem(title: "Code", image: UIImage(named: "fileIcon"), tag: 0)
        let contentVC = PyContentViewController()
        contentVC.tabBarItem = UITabBarItem(tabBarSystemItem: .more, tag: 1)
        let tabBarVC = UITabBarController()
        tabBarVC.viewControllers = [navVC, contentVC]
        tabBarVC.tabBar.barStyle = .black
        present(tabBarVC, animated: true, completion: {
            if run {
                editor.run()
            }
        })
    }
    
    // MARK: - Browser
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didPickDocumentsAt documentURLs: [URL]) {
        
        openDocument(documentURLs[0], run: false)
    }
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didRequestDocumentCreationWithHandler importHandler: @escaping (URL?, UIDocumentBrowserViewController.ImportMode) -> Void) {
        
        guard let template = Bundle.main.url(forResource: "Untitled", withExtension: "py") else {
            importHandler(nil, .none)
            return
        }
        importHandler(template, .copy)
    }
}
