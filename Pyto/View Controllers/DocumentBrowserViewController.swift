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
    
    /// If set, will open the document when the view appears.
    var documentURL: URL?
    
    /// If set, will open the folder when the view appears.
    var folder: FolderDocument?
    
    /// Opens a folder picker for opening a project.
    @objc func openProject() {
        
        if #available(iOS 13.0, *) {
            let vc = ProjectsBrowserViewController(style: .insetGrouped)
            vc.navigationItem.largeTitleDisplayMode = .always
            let navVC = UINavigationController(rootViewController: vc)
            navVC.modalPresentationStyle = .formSheet
            navVC.navigationBar.prefersLargeTitles = true
            present(navVC, animated: true, completion: nil)
        }
    }
    
    /// Shows more options.
    @objc func showMore(_ sender: UIBarButtonItem) {
        let menu = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "menu")
        present(menu, animated: true, completion: nil)
    }
    
    /// Runs the given code.
    ///
    /// - Parameters:
    ///     - code: Code to run.
    func run(code: String) {
        let url = URL(fileURLWithPath: NSTemporaryDirectory()+"/Temporary.py")
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
    ///     - isShortcut: A boolean indicating if the opened script is a shortcut.
    ///     - folder: If opened from a project, the folder of the project.
    ///     - animated: Set to `true` if the presentation should be animated.
    ///     - completion: Code called after presenting the UI.
    func openDocument(_ documentURL: URL, run: Bool, isShortcut: Bool = false, folder: FolderDocument? = nil, animated: Bool = true, completion: (() -> Void)? = nil) {
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? UIColor(named: "TintColor") ?? .orange
        
        let document = PyDocument(fileURL: documentURL)
        
        guard documentURL.pathExtension.lowercased() == "py" else {
            return
        }
        
        let isPip = (documentURL.path == Bundle.main.path(forResource: "installer", ofType: "py"))
        
        if presentedViewController != nil {
            dismiss(animated: true) {
                self.openDocument(documentURL, run: run, folder: folder, completion: completion)
            }
            return
        }
                
        let editor = EditorViewController(document: document)
        editor.shouldRun = run
        editor.isShortcut = isShortcut
        let contentVC = ConsoleViewController()
        contentVC.view.backgroundColor = .white
        
        let splitVC = EditorSplitViewController()
        splitVC.folder = folder
        
        if isPip {
            splitVC.ratio = 0
        }
        
        if traitCollection.horizontalSizeClass == .compact && !EditorSplitViewController.shouldShowConsoleAtBottom {
            splitVC.ratio = 1
        }
        
        let navVC = EditorSplitViewController.NavigationController(rootViewController: splitVC)
        navVC.modalPresentationStyle = .fullScreen
        navVC.navigationBar.isTranslucent = true
        
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
        
        var vc: UIViewController = navVC
        
        if let folder = folder {
            let uiSplitVC = EditorSplitViewController.ProjectSplitViewController()
            uiSplitVC.editor = splitVC
            uiSplitVC.preferredDisplayMode = .primaryHidden
            if #available(iOS 13.0, *) {
                uiSplitVC.view.backgroundColor = .systemBackground
            }
            uiSplitVC.modalPresentationStyle = .fullScreen
            vc = uiSplitVC
            
            let browser = FileBrowserViewController()
            browser.directory = folder.fileURL
            browser.document = folder
            folder.browser = browser
            let browserNavVC = UINavigationController(rootViewController: browser)
            
            uiSplitVC.viewControllers = [browserNavVC, navVC]
        }
        
        vc.transitioningDelegate = self
        
        document.open { (success) in
            guard success else {
                return
            }
            
            document.checkForConflicts(onViewController: self, completion: {
                self.present(vc, animated: animated, completion: {
                    
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
            additionalTrailingNavigationBarButtonItems = [UIBarButtonItem(image: UIImage(systemName: "folder.fill") ?? UIImage(), style: .plain, target: self, action: #selector(openProject))]
        }
        
        runAction.image = UIImage(named: "play")
        self.customActions = [runAction]
        
        delegate = self
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        PyCore.runStartupScriptIfNeeded()
        
        if let docURL = documentURL {
            openDocument(docURL, run: false, folder: folder, animated: false)
            documentURL = nil
            folder = nil
        }
        
        /*if !Python.shared.isSetup, let view = Bundle.main.loadNibNamed("Loading Python", owner: nil, options: nil)!.first as? UIView {
            self.view.window?.addSubview(view)
        }*/
    }
    
    // MARK: - Document browser view controller delegate
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didPickDocumentsAt documentURLs: [URL]) {
        
        openDocument(documentURLs[0], run: false)
    }
    
    func documentBrowser(_ controller: UIDocumentBrowserViewController, didRequestDocumentCreationWithHandler importHandler: @escaping (URL?, UIDocumentBrowserViewController.ImportMode) -> Void) {
        
        let navVC = UIStoryboard(name: "Template Chooser", bundle: nil).instantiateInitialViewController()!
        ((navVC as? UINavigationController)?.topViewController as? TemplateChooserTableViewController)?.importHandler = importHandler
        
        present(navVC, animated: true, completion: nil)
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
