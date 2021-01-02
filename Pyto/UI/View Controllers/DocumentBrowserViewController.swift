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
import SwiftUI

/// The main file browser used to edit scripts.
@objc public class DocumentBrowserViewController: UIDocumentBrowserViewController, UIDocumentBrowserViewControllerDelegate, ObservableObject {
    
    /// The delegate for the scene where this document browser is contained.
    var sceneDelegate: SceneDelegate? {
        return view.window?.windowScene?.delegate as? SceneDelegate
    }
    
    /// If set, will open the document when the view appears.
    var documentURL: URL?
    
    /// If set, will open the folder when the view appears.
    var folder: URL?
        
    var sceneState: SceneState?
    
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
    @objc func showMore(_ sender: Any) {
        #if Xcode11
        let menu = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "menu")
        present(menu, animated: true, completion: nil)
        #else
        if #available(iOS 14.0, *) {
            
            sceneDelegate?.sceneStateStore.reset()
            
            let sidebar = makeSidebarNavigation(url: nil, run: false, isShortcut: false, restoreSelection: false)
            let vc = SidebarController(rootView: AnyView(sidebar))
            vc.modalTransitionStyle = .crossDissolve
            vc.modalPresentationStyle = .fullScreen
            sidebar.viewControllerStore.vc = vc
            
            present(vc, animated: true, completion: nil)
        } else {
            let menu = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "menu")
            present(menu, animated: true, completion: nil)
        }
        #endif
    }
    
    /// Runs the given code.
    ///
    /// - Parameters:
    ///     - code: Code to run.
    func run(code: String) {
        let url = URL(fileURLWithPath: NSTemporaryDirectory()+"/Script.py")
        if FileManager.default.fileExists(atPath: url.path) {
            try? FileManager.default.removeItem(at: url)
        }
        FileManager.default.createFile(atPath: url.path, contents: code.data(using: .utf8), attributes: nil)
        openDocument(url, run: true)
    }
    
    #if !Xcode11
    
    private var sidebar: Any?
    
    /// Makes a SwiftUI view for the navigation.
    ///
    /// - Parameters:
    ///     - url: The URL of the file to edit.
    ///     - run: A boolean indicating whether `url` should run.
    ///     - isShortcut: A boolean indicating whether `url` is launched from a Shortcut.
    ///     - restoreSelection: If set to `true`, will restore the selection saved from state restoration.
    @available(iOS 14.0, *)
    func makeSidebarNavigation(url: URL?, run: Bool, isShortcut: Bool, restoreSelection: Bool) -> SidebarNavigation {
        var navView: SidebarNavigation!
        navView = SidebarNavigation(
            url: url,
            scene: view.window?.windowScene,
            sceneStateStore: sceneDelegate?.sceneStateStore ?? SceneStateStore(),
            restoreSelection: restoreSelection,
            pypiViewController: MenuTableViewController.makePyPiView(),
            samplesView: SamplesNavigationView(url: Bundle.main.url(forResource: "Samples", withExtension: nil)!,
            selectScript: { (file) in
                                            
                guard file.pathExtension.lowercased() == "py" else {
                    return
                }
            
                guard let editor = self.openDocument(file, run: false, show: false) else {
                    return
                }
                                        
                editor.navigationItem.largeTitleDisplayMode = .never
                editor.editor?.alwaysShowBackButton = true
                                        
                navView.viewControllerStore.vc?.present(editor.navigationController ?? editor, animated: true, completion: nil)
            }),
            documentationViewController: DocumentationViewController(),
            modulesViewController: ModulesTableViewController(style: .grouped),
            makeEditor: { _url in
                                        
                let _run: Bool
                let _shortcut: Bool
                                        
                if _url == url {
                    _run = run
                    _shortcut = isShortcut
                } else {
                    _run = false
                    _shortcut = false
                }
                                        
                return self.openDocument(_url, run: _run, isShortcut: _shortcut, show: false) ?? UIViewController()
        })
        
        return navView
    }
    #endif
    
    /// Opens the given file.
    ///
    /// - Parameters:
    ///     - documentURL: The URL of the file or directory.
    ///     - run: Set to `true` to run the script inmediately.
    ///     - viewController: The view controller where the editor will be presented.
    ///     - isShortcut: A boolean indicating if the opened script is a shortcut.
    ///     - folder: If opened from a project, the folder of the project.
    ///     - animated: Set to `true` if the presentation should be animated.
    ///     - show: Set to `false` to not present the editor and just return it.
    ///     - completion: Code called after presenting the UI.
    @discardableResult public func openDocument(_ documentURL: URL, run: Bool, viewController: UIViewController? = nil, isShortcut: Bool = false, folder: URL? = nil, animated: Bool = true, show: Bool = true, completion: (() -> Void)? = nil) -> EditorSplitViewController? {
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? UIColor(named: "TintColor") ?? .orange
        
        let document = PyDocument(fileURL: documentURL)
        
        guard documentURL.pathExtension.lowercased() == "py" else {
            return nil
        }
        
        let isPip = (documentURL.path == Bundle.main.path(forResource: "installer", ofType: "py"))
        
        if presentedViewController != nil && viewController == nil && show {
            dismiss(animated: true) { [weak self] in
                self?.openDocument(documentURL, run: run, folder: folder, completion: completion)
            }
            return nil
        }
        
        #if !Xcode11
        if #available(iOS 14.0, *), let scene = view.window?.windowScene {
            let traitCollection = scene.windows.first?.traitCollection ?? self.traitCollection
            let size = (traitCollection.horizontalSizeClass, traitCollection.verticalSizeClass)
            if run || (size != (EditorView.EditorStore.perScene[scene]?.sizeClass ?? size)) {
                EditorView.EditorStore.perScene[scene] = nil
            }
        }
        #endif
                
        let editor = EditorViewController(document: document)
        editor.shouldRun = run
        editor.isShortcut = isShortcut
        
        if show {
            editor.setupToolbarIfNeeded(windowScene: view.window?.windowScene)
        }
        
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
        if isiOSAppOnMac {
            navVC.setNavigationBarHidden(true, animated: false)
        }
        
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
        
        var vc: UIViewController = navVC
        
        if let folder = folder {
            let uiSplitVC = EditorSplitViewController.ProjectSplitViewController()
            
            uiSplitVC.editor = splitVC
            #if Xcode11
            uiSplitVC.preferredDisplayMode = .primaryHidden
            #else
            uiSplitVC.preferredDisplayMode = .allVisible
            #endif
            if #available(iOS 13.0, *) {
                uiSplitVC.view.backgroundColor = .systemBackground
            }
            uiSplitVC.modalPresentationStyle = .fullScreen
            vc = uiSplitVC
            
            let browser = FileBrowserViewController()
            browser.directory = folder
            let browserNavVC = UINavigationController(rootViewController: browser)
            
            uiSplitVC.viewControllers = [browserNavVC, navVC]
        } else if #available(iOS 14.0, *), !isiOSAppOnMac, show {
            
            #if !Xcode11
            let navView = makeSidebarNavigation(url: documentURL, run: run, isShortcut: isShortcut, restoreSelection: false)
            
            vc = SidebarController(rootView: AnyView(navView))
            vc.modalPresentationStyle = .fullScreen
            
            navView.viewControllerStore.vc = vc as? UIHostingController<AnyView>
            #else
            print("Built with Xcode 11")
            #endif
        }
        
        #if !Xcode11
        if #available(iOS 14.0, *) {
            if !run && !isShortcut && show {
                RecentDataSource.shared.recent.append(documentURL)
            }
        }
        #endif
        
        vc.modalTransitionStyle = .crossDissolve
        if show {
            let window = view.window
            document.open { [weak self] (success) in
                guard success, self != nil else {
                    return
                }
                
                if !run {
                    document.checkForConflicts(onViewController: self!, completion: { [weak self] in
                        
                        guard self != nil else {
                            return
                        }
                        
                        (viewController ?? (self!.view.window != nil ? self! : window?.rootViewController))?.present(vc, animated: !run, completion: {
                            #if !Xcode11
                            UIView.animate(withDuration: 0.15) {
                                (vc.children.first as? UISplitViewController)?.preferredDisplayMode = .secondaryOnly
                            }
                            #endif
                            
                            NotificationCenter.default.removeObserver(splitVC)
                            completion?()
                        })
                    })
                } else {
                    (viewController ?? self)?.present(vc, animated: true, completion: nil)
                }
            }
        }
        
        return splitVC
    }
    
    // MARK: - Paths
    
    /// Returns the URL for iCloud Drive folder.
    @objc static let iCloudContainerURL = FileManager.default.url(forUbiquityContainerIdentifier: nil)?.appendingPathComponent("Documents")
    
    /// Returns the URL for local folder.
    @objc static let localContainerURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0]
    
    // MARK: - Document browser view controller
    
    public override func viewDidLoad() {
        super.viewDidLoad()
        
        let menuImage: UIImage
        if #available(iOS 14.0, *) {
            menuImage = UIImage(systemName: "list.bullet.rectangle") ?? UIImage()
        } else {
            menuImage = EditorSplitViewController.threeDotsImage
        }
        
        additionalLeadingNavigationBarButtonItems = [UIBarButtonItem(image: menuImage, style: .plain, target: self, action: #selector(showMore(_:)))]
        let runAction = UIDocumentBrowserAction(identifier: "run", localizedTitle: Localizable.MenuItems.run, availability: [.menu, .navigationBar], handler: { (urls) in
            self.openDocument(urls[0], run: true)
        })
        runAction.supportedContentTypes = ["public.python-script"]
        
        if #available(iOS 13.0, *) {
            additionalTrailingNavigationBarButtonItems = [UIBarButtonItem(image: UIImage(systemName: "folder.fill") ?? UIImage(), style: .plain, target: self, action: #selector(openProject))]
        }
        
        runAction.image = UIImage(named: "play")
        self.customActions = [runAction]
        
        delegate = self
    }
    
    public override func viewDidAppear(_ animated: Bool) {
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
    
    public func documentBrowser(_ controller: UIDocumentBrowserViewController, failedToImportDocumentAt documentURL: URL, error: Error?) {
        print(error?.localizedDescription ?? "")
    }
    
    public func documentBrowser(_ controller: UIDocumentBrowserViewController, didPickDocumentsAt documentURLs: [URL]) {
        
        openDocument(documentURLs[0], run: false)
    }
    
    public func documentBrowser(_ controller: UIDocumentBrowserViewController, didRequestDocumentCreationWithHandler importHandler: @escaping (URL?, UIDocumentBrowserViewController.ImportMode) -> Void) {
        
        let navVC = UIStoryboard(name: "Template Chooser", bundle: nil).instantiateInitialViewController()!
        ((navVC as? UINavigationController)?.topViewController as? TemplateChooserTableViewController)?.importHandler = importHandler
        
        present(navVC, animated: true, completion: nil)
    }
    
    public func documentBrowser(_ controller: UIDocumentBrowserViewController, didImportDocumentAt sourceURL: URL, toDestinationURL destinationURL: URL) {
        
        openDocument(destinationURL, run: false)
    }
}
