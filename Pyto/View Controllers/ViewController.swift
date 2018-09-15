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
        delegate = self
    }
    
    // MARK: - Browser
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didPickDocumentsAt documentURLs: [URL]) {
        
        Py_SetProgramName(documentURLs[0].lastPathComponent.cWchar_t)
        
        let doc = PyDocument(fileURL: documentURLs[0])
        let navVC = UINavigationController(rootViewController: EditorViewController(document: doc))
        navVC.navigationBar.barStyle = .black
        navVC.tabBarItem = UITabBarItem(title: "Code", image: UIImage(named: "fileIcon"), tag: 0)
        let contentVC = PyContentViewController()
        contentVC.tabBarItem = UITabBarItem(tabBarSystemItem: .more, tag: 1)
        let tabBarVC = UITabBarController()
        tabBarVC.viewControllers = [navVC, contentVC]
        tabBarVC.tabBar.barStyle = .black
        present(tabBarVC, animated: true, completion: nil)
    }
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didRequestDocumentCreationWithHandler importHandler: @escaping (URL?, UIDocumentBrowserViewController.ImportMode) -> Void) {
        
        guard let template = Bundle.main.url(forResource: "Untitled", withExtension: "py") else {
            importHandler(nil, .none)
            return
        }
        importHandler(template, .copy)
    }
}
