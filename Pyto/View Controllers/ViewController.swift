//
//  ViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices

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
        additionalLeadingNavigationBarButtonItems = [UIBarButtonItem(barButtonSystemItem: .bookmarks, target: self, action: #selector(help(_:)))]
        delegate = self
    }
    
    /// Open the documentation or samples.
    @objc func help(_ sender: UIBarButtonItem) {
        let sheet = UIAlertController(title: "Help", message: "Choose an option below.", preferredStyle: .actionSheet)
        
        sheet.addAction(UIAlertAction(title: "Documentation", style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://coldgrub1384.github.io/Pyto")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "Samples", style: .default, handler: { _ in
            let samplesSheet = UIAlertController(title: "Samples", message: "Select a sample to preview", preferredStyle: .actionSheet)
            if let samplesURL = Bundle.main.url(forResource: "Samples", withExtension: nil) {
                do {
                    let samples = try FileManager.default.contentsOfDirectory(at: samplesURL, includingPropertiesForKeys: nil, options: .init(rawValue: 0))
                    for sample in samples {
                        samplesSheet.addAction(UIAlertAction(title: sample.deletingPathExtension().lastPathComponent, style: .default, handler: { (_) in
                            self.openDocument(sample, run: false)
                        }))
                    }
                } catch {
                    print(error.localizedDescription)
                }
            }
            samplesSheet.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
            samplesSheet.popoverPresentationController?.barButtonItem = sender
            samplesSheet.view.tintColor = UIView().tintColor
            self.present(samplesSheet, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        sheet.popoverPresentationController?.barButtonItem = sender
        sheet.view.tintColor = UIView().tintColor
        present(sheet, animated: true, completion: nil)
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
