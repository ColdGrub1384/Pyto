//
//  SidebarSplitViewController.swift
//  Pyto
//
//  Created by Emma on 10-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit
import SwiftUI
import Dynamic

class SidebarSplitViewController: UISplitViewController, UISplitViewControllerDelegate {
    
    let id = UUID()
    
    init() {
        super.init(style: .tripleColumn)
        delegate = self
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    let fileBrowser = FileBrowserViewController()
    
    var fileBrowserNavVC: SidebarViewController.NavigationController!
    
    let compactFileBrowser = FileBrowserViewController()
    
    var compactFileBrowserNavVC: SidebarViewController.NavigationController!
    
    var sidebar: SidebarViewController? {
        (viewController(for: isCollapsed ? .compact : .primary) as? UINavigationController)?.viewControllers.first as? SidebarViewController
    }
    
    override var childForHomeIndicatorAutoHidden: UIViewController? {
        if isCollapsed {
            return (viewController(for: .compact) as? UINavigationController)?.visibleViewController
        } else {
            return (viewController(for: .secondary) as? UINavigationController)?.visibleViewController
        }
    }
    
    @objc func showSettings() {
        sidebar?.loadViewIfNeeded()
        sidebar?.showSettings()
    }
    
    @objc func openScript() {
        sidebar?.loadViewIfNeeded()
        sidebar?.openScript()
    }
    
    @objc func showExamples() {
        sidebar?.loadViewIfNeeded()
        sidebar?.showExamples()
    }
    
    @objc func showDocumentationOnSplitView() {
        sidebar?.loadViewIfNeeded()
        sidebar?.showDocumentationOnSplitView()
    }
    
    @objc func showPyPI() {
        sidebar?.loadViewIfNeeded()
        sidebar?.showPyPI()
    }
    
    @objc func showREPL() {
        sidebar?.loadViewIfNeeded()
        sidebar?.showREPL()
    }
    
    @objc func newScript() {
        sidebar?.loadViewIfNeeded()
        sidebar?.newScript()
    }
    
    func restore(sceneState: SceneDelegate.SceneState) {
        do {
            var isStale = false
            
            let directory = try URL(resolvingBookmarkData: sceneState.directoryBookmarkData, bookmarkDataIsStale: &isStale)
            fileBrowser.directory = directory
            compactFileBrowser.directory = directory
            sidebar?.loadViewIfNeeded()
            sidebar?.loadWorkingDirectory()
        } catch {
            print(error.localizedDescription)
        }
        
        sidebar?.loadViewIfNeeded()
        
        switch sceneState.section {
        case .editor(let bookmarkData):
            do {
                var isStale = false
                
                let url = try URL(resolvingBookmarkData: bookmarkData, bookmarkDataIsStale: &isStale)
                
                sidebar?.open(url: url)
            } catch {
                print(error.localizedDescription)
            }
        case .fileBrowser:
            if isCollapsed, let browser = compactFileBrowserNavVC {
                sidebar?.show(vc: browser)
            } else {
                sidebar?.showModuleRunner()
            }
        case .terminal:
            sidebar?.showModuleRunner()
        case .examples:
            sidebar?.showExamples()
        case .documentation:
            sidebar?.showDocumentationOnSplitView()
        case .pypi:
            sidebar?.showPyPI()
        case .loadedModules:
            sidebar?.showLoadedModules()
        case nil:
            break
        }
    }
    
    private var previousDisplayMode: UISplitViewController.DisplayMode?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.backgroundColor = .systemBackground
        
        fileBrowser.directory = FileBrowserViewController.defaultDirectory
        
        fileBrowserNavVC = .init(rootViewController: fileBrowser)
        fileBrowserNavVC.navigationBar.prefersLargeTitles = true
        fileBrowserNavVC.view.backgroundColor = .systemBackground
        
        compactFileBrowser.directory = FileBrowserViewController.defaultDirectory
        
        compactFileBrowserNavVC = .init(rootViewController: compactFileBrowser)
        compactFileBrowserNavVC.navigationBar.prefersLargeTitles = true
        compactFileBrowserNavVC.view.backgroundColor = .systemBackground
        
        let sidebar = SidebarViewController(splitViewID: id, compact: false)
        sidebar.makeModuleRunnerIfNecessary()
        setViewController(UINavigationController(rootViewController: sidebar), for: .primary)
        setViewController(fileBrowserNavVC, for: .supplementary)
        setViewController(sidebar.moduleRunner!, for: .secondary)
        setViewController(UINavigationController(rootViewController: SidebarViewController(splitViewID: id, compact: true)), for: .compact)
        
        preferredDisplayMode = .twoOverSecondary
        
        primaryBackgroundStyle = .sidebar
        
        showsSecondaryOnlyButton = true
        
        NotificationCenter.default.addObserver(forName: UIApplication.didEnterBackgroundNotification, object: nil, queue: nil) { [weak self] _ in
            self?.previousDisplayMode = self?.displayMode
        }
        
        NotificationCenter.default.addObserver(forName: UIApplication.willEnterForegroundNotification, object: nil, queue: nil) { [weak self] _ in
            if let previousDisplayMode = self?.previousDisplayMode {
                self!.preferredDisplayMode = previousDisplayMode
            }
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if isiOSAppOnMac {
            Dynamic(view.window?.windowScene).titlebar.titleVisibility = 1
            for window in Dynamic.NSApplication.sharedApplication.windows.asArray ?? [] {
               Dynamic(window).styleMask = 32783
            }
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if !SidebarViewController.splitViews.contains(self) {
            SidebarViewController.splitViews.append(self)
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        if let i = SidebarViewController.splitViews.firstIndex(of: self) {
            SidebarViewController.splitViews.remove(at: i)
        }
    }
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        
        guard let windowScene = view.window?.windowScene, windowScene.activationState == .foregroundActive || windowScene.activationState == .foregroundInactive else {
            return
        }
        
        if traitCollection.horizontalSizeClass == .compact && previousTraitCollection?.horizontalSizeClass != .compact {
            preferredDisplayMode = .secondaryOnly
        } else if traitCollection.horizontalSizeClass == .regular && previousTraitCollection?.horizontalSizeClass != .regular {
            preferredDisplayMode = .oneBesideSecondary
        }
        
        view.backgroundColor = .systemBackground // It's sometimes set to white for some reason?
    }
    
    func splitViewController(_ splitViewController: UISplitViewController, collapseSecondary secondaryViewController: UIViewController, onto primaryViewController: UIViewController) -> Bool {
        true
    }
}
