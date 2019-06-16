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
    
    /// The visible instance.
    /*@available(*, deprecated, message: "Use scenes APIs instead.") static var visible: DocumentBrowserViewController? {
        return UIApplication.shared.keyWindow?.rootViewController as? DocumentBrowserViewController
    }*/
    
    /// Store here `EditorSplitViewController`s because it crashes on dealloc. RIP memory
    private static var splitVCs = [UIViewController?]()
    
    /// If set, will open the document when the view appeared.
    var documentURL: URL?
    
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
    ///     - animated: Set to `true` if the presentation should be animated.
    ///     - completion: Code called after presenting the UI.
    func openDocument(_ documentURL: URL, run: Bool, animated: Bool = true, completion: (() -> Void)? = nil) {
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? UIColor(named: "TintColor") ?? .orange
        
        let document = PyDocument(fileURL: documentURL)
        
        guard documentURL.pathExtension.lowercased() == "py" else {
            return
        }
        
        let isPip = (documentURL.path == Bundle.main.path(forResource: "installer", ofType: "py"))
        
        if presentedViewController != nil {
            dismiss(animated: true) {
                self.openDocument(documentURL, run: run, completion: completion)
            }
            return
        }
                
        let editor = EditorViewController(document: document)
        editor.shouldRun = run
        let contentVC = ConsoleViewController()
        contentVC.view.backgroundColor = .white
        
        let splitVC = EditorSplitViewController()
        
        if isPip {
            splitVC.ratio = 0
        }
        
        if traitCollection.horizontalSizeClass == .compact && !EditorSplitViewController.shouldShowConsoleAtBottom {
            splitVC.ratio = 1
        }
        
        DocumentBrowserViewController.splitVCs.append(splitVC)
        let navVC = UINavigationController(rootViewController: splitVC)
        navVC.modalPresentationStyle = .fullScreen
        
        if EditorSplitViewController.shouldShowSeparator {
            splitVC.separatorColor = tintColor
        } else {
            splitVC.separatorColor = .clear
        }
        splitVC.separatorSelectedColor = tintColor
        splitVC.editor = editor
        splitVC.console = contentVC
        if EditorSplitViewController.shouldShowConsoleAtBottom { // Please, don't remove this condition :)
            splitVC.firstChild = editor
            splitVC.secondChild = contentVC
        }
        splitVC.view.backgroundColor = .white
        
        splitVC.arrangement = .horizontal
        
        transitionController = transitionController(forDocumentAt: documentURL)
        transitionController?.loadingProgress = document.progress
        transitionController?.targetView = navVC.view
        
        navVC.transitioningDelegate = self
        
        document.open { (success) in
            guard success else {
                return
            }
            
            document.checkForConflicts(completion: {
                self.present(navVC, animated: animated, completion: {
                    
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
        
        additionalLeadingNavigationBarButtonItems = [UIBarButtonItem(image: EditorSplitViewController.threeDotsImage, style: .plain, target: self, action: #selector(showMore(_:)))]
        let runAction = UIDocumentBrowserAction(identifier: "run", localizedTitle: Localizable.MenuItems.run, availability: [.menu, .navigationBar], handler: { (urls) in
            self.openDocument(urls[0], run: true)
        })
        if #available(iOS 13.0, *) {
            runAction.image = UIImage(systemName: "play.fill")
        }
        self.customActions = [runAction]
        
        delegate = self
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if let docURL = documentURL {
            openDocument(docURL, run: false, animated: false)
            documentURL = nil
        }
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
