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
class DocumentBrowserViewController: UIDocumentBrowserViewController, UIDocumentBrowserViewControllerDelegate, UIViewControllerRestoration, UIViewControllerTransitioningDelegate {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        browserUserInterfaceStyle = .dark
        view.tintColor = UIColor(named: "TintColor")
        allowsDocumentCreation = true
        allowsPickingMultipleItems = false
        customActions = [UIDocumentBrowserAction(identifier: "run", localizedTitle: "Run", availability: .menu, handler: { (urls) in
            self.openDocument(urls[0], run: true)
        })]
        additionalLeadingNavigationBarButtonItems = [UIBarButtonItem(barButtonSystemItem: .bookmarks, target: self, action: #selector(help(_:)))]
        delegate = self
        restorationClass = DocumentBrowserViewController.self
        restorationIdentifier = "Browser"
    }
    
    /// Transition controller for presenting and dismissing View controllers.
    var transitionController: UIDocumentBrowserTransitionController?
    
    /// Open the documentation or samples.
    @objc func help(_ sender: UIBarButtonItem) {
        let sheet = UIAlertController(title: "Pyto", message: Python.shared.version, preferredStyle: .actionSheet)
        
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
            self.present(samplesSheet, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "REPL", style: .default, handler: { _ in
            guard let replURL = Bundle.main.url(forResource: "REPL", withExtension: "py") else {
                return
            }
            if Python.shared.isREPLRunning {
                let contentVC = PyContentViewController()
                contentVC.modalPresentationStyle = .overCurrentContext
                contentVC.view.tintColor = UIColor(named: "TintColor")
                UIApplication.shared.keyWindow?.topViewController?.present(contentVC, animated: true, completion: {
                    if !Python.shared.isScriptRunning {
                        PyInputHelper.userInput = "import os; import PytoClasses; os.system = PytoClasses.Python.shared.system; import code; code.interact()"
                    } else {
                        PyOutputHelper.print("An instance of a module is already running and two scripts cannot run at the same time, to kill it, quit the app. This can be caused by an inifite loop.")
                    }
                })
            } else { // Start the REPL
                self.openDocument(replURL, run: true)
            }
        }))
        sheet.addAction(UIAlertAction(title: "Acknowledgments", style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://coldgrub1384.github.io/Pyto/Licenses")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "Source code", style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://github.com/ColdGrub1384/Pyto")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        sheet.popoverPresentationController?.barButtonItem = sender
        present(sheet, animated: true, completion: nil)
    }
    
    func run(code: String) {
        let url = URL(fileURLWithPath: NSTemporaryDirectory()+"/Temporary")
        if FileManager.default.fileExists(atPath: url.path) {
            try? FileManager.default.removeItem(at: url)
        }
        FileManager.default.createFile(atPath: url.path, contents: code.data(using: .utf8), attributes: nil)
        openDocument(url, run: true, isApp: true)
    }
    
    /// Opens the given script.
    ///
    /// - Parameters:
    ///     - document: The URL of the script.
    ///     - run: Set to `true` to run the script inmediately.
    ///     - isApp: Should be set to `true` if the script is ran from the Home Screen.
    ///     - completion: Code called after presenting the UI.
    func openDocument(_ document: URL, run: Bool, isApp: Bool = false, completion: (() -> Void)? = nil) {
        
        Python.shared.isAppRunning = isApp
        
        if presentedViewController != nil {
            (((presentedViewController as? UITabBarController)?.viewControllers?.first as? UINavigationController)?.viewControllers.first as? EditorViewController)?.save()
            dismiss(animated: true) {
                self.openDocument(document, run: run, completion: completion)
            }
        }
        
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
        tabBarVC.view.tintColor = UIColor(named: "TintColor")
        tabBarVC.view.backgroundColor = .clear
        if !isApp {
            tabBarVC.modalPresentationStyle = .overCurrentContext
        }
        
        if #available(iOS 12.0, *) {
            transitionController = transitionController(forDocumentAt: document)
            transitionController?.targetView = tabBarVC.view
            tabBarVC.transitioningDelegate = self
        }
        
        UIApplication.shared.keyWindow?.topViewController?.present(tabBarVC, animated: true, completion: {
            if run {
                editor.run()
            }
            completion?()
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
    
    // MARK: - State restoration
    
    override func encodeRestorableState(with coder: NSCoder) {
        
        if let tabBarVC = presentedViewController as? UITabBarController, let editor = (tabBarVC.viewControllers?.first as? UINavigationController)?.viewControllers.first as? EditorViewController, let url = editor.document?.fileURL, let bookmark = try? url.bookmarkData() {
            
            editor.save()
            coder.encode(bookmark, forKey: "bookmark")
            if let console = (PyContentViewController.shared?.viewController as? UINavigationController)?.viewControllers.first as? ConsoleViewController {
                coder.encode(console.textView.text, forKey: "console")
            }
        }
        
        super.encodeRestorableState(with: coder)
    }
    
    override func decodeRestorableState(with coder: NSCoder) {
        super.decodeRestorableState(with: coder)
        
        var bookmarkDataIsStale = false
        if let bookmark = coder.decodeObject(forKey: "bookmark") as? Data, let url = try? URL(resolvingBookmarkData: bookmark, bookmarkDataIsStale: &bookmarkDataIsStale) {
            _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in // TODO: Anyway to do it without a timer?
                self.openDocument(url, run: false, completion: {
                    ((PyContentViewController.shared?.viewController as? UINavigationController)?.viewControllers.first as? ConsoleViewController)?.textView.text = (coder.decodeObject(forKey: "console") as? String) ?? ""
                })
            })
        }
        
        super.decodeRestorableState(with: coder)
    }
    
    // MARK: - View controller restoration
    
    static func viewController(withRestorationIdentifierPath identifierComponents: [String], coder: NSCoder) -> UIViewController? {
        return DocumentBrowserViewController()
    }
    
    // MARK: - View controller transition delegate
    
    func animationController(forDismissed dismissed: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return transitionController
    }
    
    func animationController(forPresented presented: UIViewController, presenting: UIViewController, source: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return transitionController
    }
}
