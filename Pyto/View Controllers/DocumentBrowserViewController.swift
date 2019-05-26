//
//  ViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices
import CoreSpotlight
import SplitKit
import SavannaKit

/// The main file browser used to edit scripts.
@objc class DocumentBrowserViewController: UIDocumentBrowserViewController, UIDocumentBrowserViewControllerDelegate, UIViewControllerTransitioningDelegate {
    
    /// The visible instance
    static var visible: DocumentBrowserViewController? {
        return UIApplication.shared.keyWindow?.rootViewController as? DocumentBrowserViewController
    }
    
    /// Store here `EditorSplitViewController`s because it crashes on dealloc. RIP memory
    private static var splitVCs = [UIViewController?]()
    
    /// Shows more options.
    @objc func showMore(_ sender: UIBarButtonItem) {
        let menu = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "menu")
        menu.modalPresentationStyle = .popover
        menu.popoverPresentationController?.barButtonItem = sender
        menu.view.backgroundColor = .white
        present(menu, animated: true, completion: nil)
    }
    
    /// Runs the given code.
    ///
    /// - Parameters:
    ///     - code: Code to run.
    func run(code: String) {
        let url = URL(fileURLWithPath: NSTemporaryDirectory()+"/Temporary")
        if FileManager.default.fileExists(atPath: url.path) {
            try? FileManager.default.removeItem(at: url)
        }
        FileManager.default.createFile(atPath: url.path, contents: code.data(using: .utf8), attributes: nil)
        openDocument(url, run: true)
    }
    
    /// Opens the given file.
    ///
    /// - Parameters:
    ///     - documentURL: The URL of the file or directory.
    ///     - run: Set to `true` to run the script inmediately.
    ///     - completion: Code called after presenting the UI.
    func openDocument(_ documentURL: URL, run: Bool, completion: (() -> Void)? = nil) {
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? UIColor(named: "TintColor") ?? .orange
        
        let document = PyDocument(fileURL: documentURL)
        
        guard documentURL.pathExtension.lowercased() == "py" else {
            return
        }
        
        let isPip = (documentURL.path == Bundle.main.path(forResource: "installer", ofType: "py"))
        
        if presentedViewController != nil {
            (((presentedViewController as? UITabBarController)?.viewControllers?.first as? UINavigationController)?.viewControllers.first as? EditorViewController)?.save()
            dismiss(animated: true) {
                self.openDocument(documentURL, run: run, completion: completion)
            }
        }
                
        let editor = EditorViewController(document: document)
        editor.shouldRun = run
        let contentVC = ConsoleViewController.visible
        contentVC.view.backgroundColor = .white
        
        let splitVC = EditorSplitViewController()
        
        if isPip {
            splitVC.ratio = 0
        }
        
        DocumentBrowserViewController.splitVCs.append(EditorSplitViewController.visible)
        EditorSplitViewController.visible = splitVC
        let navVC = ThemableNavigationController(rootViewController: splitVC)
        
        splitVC.separatorColor = .clear
        splitVC.separatorSelectedColor = tintColor
        splitVC.editor = editor
        splitVC.console = contentVC
        splitVC.firstChild = editor
        splitVC.secondChild = contentVC
        splitVC.view.backgroundColor = .white
        
        splitVC.arrangement = .horizontal
        
        transitionController = transitionController(forDocumentAt: documentURL)
        transitionController?.loadingProgress = document.progress
        transitionController?.targetView = navVC.view
        
        navVC.toolbar.setShadowImage(UIImage(), forToolbarPosition: .any)
        navVC.navigationBar.shadowImage = UIImage()
        navVC.navigationBar.isTranslucent = false
        navVC.transitioningDelegate = self
        
        document.open { (success) in
            guard success else {
                return
            }
            
            document.checkForConflicts(completion: {
                UIApplication.shared.keyWindow?.topViewController?.present(navVC, animated: true, completion: {
                    
                    splitVC.firstChild = editor
                    splitVC.secondChild = contentVC
                    
                    NotificationCenter.default.removeObserver(splitVC)
                    completion?()
                })
            })
        }
    }
    
    // MARK: - Paths
    
    /// Returns the URL for iCloud Drive folder.
    @objc static let iCloudContainerURL = FileManager.default.url(forUbiquityContainerIdentifier: nil)?.appendingPathComponent("Documents")
    
    /// Returns the URL for local folder.
    @objc static let localContainerURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0]
    
    // MARK: - Document browser view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        additionalLeadingNavigationBarButtonItems = [UIBarButtonItem(image: UIImage(named: "more"), style: .plain, target: self, action: #selector(showMore(_:)))]
        
        delegate = self
    }
    
    // MARK: - Document browser view controller delegate
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didPickDocumentsAt documentURLs: [URL]) {
        
        openDocument(documentURLs[0], run: false)
    }
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didRequestDocumentCreationWithHandler importHandler: @escaping (URL?, UIDocumentBrowserViewController.ImportMode) -> Void) {
        
        let docURL = Bundle.main.url(forResource: "Untitled", withExtension: "py")
        return importHandler(docURL, docURL != nil ? .copy : .none)
    }
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didImportDocumentAt sourceURL: URL, toDestinationURL destinationURL: URL) {
        
        openDocument(destinationURL, run: false)
    }
    
    // MARK: - Animation
    
    /// Transition controller for presenting and dismissing View controllers.
    var transitionController: UIDocumentBrowserTransitionController?
    
    // MARK: - View controller transition delegate
    
    func animationController(forDismissed dismissed: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return transitionController
    }
    
    func animationController(forPresented presented: UIViewController, presenting: UIViewController, source: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return transitionController
    }
}
