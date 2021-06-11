//
//  setMacMainMenu.swift
//  Pyto
//
//  Created by administrator on 12/13/20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import SwiftUI
import Zip
import Dynamic

/// Shows a window with the given View controller.
func showWindow(vc: UIViewController?, allowDuplicates: Bool) {
    
    var sceneSession: UISceneSession?
    
    for scene in UIApplication.shared.connectedScenes {
        
        guard let vc = vc else {
            continue
        }
        
        let session = scene.session
        let typeOfVC = type(of: vc)
        if let sceneVC = ((scene as? UIWindowScene)?.windows.first?.rootViewController as? SceneDelegate.ViewController)?.presentedViewController  {
            
            let typeOfSceneVC = type(of: sceneVC)
            if typeOfVC == typeOfSceneVC {
                sceneSession = session
            }
        }
    }
    
    SceneDelegate.viewControllerToShow = vc
    UIApplication.shared.requestSceneSessionActivation(sceneSession, userActivity: nil, options: nil, errorHandler: nil)
}

extension UIResponder {
    
    @objc func installAutomatorAction(_ sender: Any) {
        
        guard isiOSAppOnMac, let zipURL = Bundle.main.url(forResource: "Automator Actions", withExtension: "zip") else {
            return
        }
                
        Dynamic.NSWorkspace.sharedWorkspace.openFile(zipURL.path, withApplication: "Archive Utility")
    }
    
    @objc func showDocumentation(_ sender: Any) {
        showWindow(vc: DocumentationViewController(), allowDuplicates: false)
    }
    
    @objc func newScript(_ sender: Any) {
        if #available(iOS 14.0, *) {
            showWindow(vc: openEmptyScript(onWindow: nil), allowDuplicates: true)
        }
    }
    
    @objc func showBrowser(_ sender: Any) {
        if #available(iOS 14.0, *) {
            showWindow(vc: DocumentBrowserViewController(forOpening: [.pythonScript/*, .init(exportedAs: "ch.ada.pytoui")*/]), allowDuplicates: false)
        }
    }
    
    @objc func showREPL(_ sender: Any) {
        if #available(iOS 14.0, *) {
            showWindow(vc: REPLViewController(), allowDuplicates: true)
        }
    }
    
    @objc func showPyPI(_ sender: Any) {
        if #available(iOS 14.0, *) {
            let navVC = UINavigationController(rootViewController: MenuTableViewController.makePyPiView())
            navVC.navigationBar.prefersLargeTitles = true
            showWindow(vc: navVC, allowDuplicates: false)
        }
    }
    
    @objc func showExamples(_ sender: Any) {
        if #available(iOS 14.0, *) {
            var vc: UIHostingController<SamplesNavigationView>!
            vc = UIHostingController(rootView: SamplesNavigationView(url: Bundle.main.url(forResource: "Samples", withExtension: nil)!,
                                                                               selectScript: { (file) in
                                                                                                               
                guard file.pathExtension.lowercased() == "py" else {
                    return
                }
                                                                               
                guard let editor = DocumentBrowserViewController().openDocument(file, run: false, show: false) else {
                    return
                }
                                                                                                           
                editor.navigationItem.largeTitleDisplayMode = .never
                editor.editor?.alwaysShowBackButton = true
                editor.navigationController?.isNavigationBarHidden = true
            
                SceneDelegate.viewControllerToShow = editor.navigationController
                UIApplication.shared.requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
            }))
            showWindow(vc: vc, allowDuplicates: false)
        }
    }
    
    @objc func showPreferences(_ sender: Any) {
        if #available(iOS 14.0, *), let vc = UIStoryboard(name: "Settings", bundle: .main).instantiateInitialViewController() {
            let navVC = UINavigationController(rootViewController: vc)
            showWindow(vc: navVC, allowDuplicates: false)
        }
    }
}

func setupMenu(builder: UIMenuBuilder) {
    // Ensure that the builder is modifying the menu bar system.

    guard #available(iOS 14.0, *) else {
        return
    }
    
    guard builder.system == UIMenuSystem.main else { return }

    let run = UIKeyCommand(title: Localizable.MenuItems.run,
                           action: #selector(EditorSplitViewController.runScript(_:)),
                            input: "r",
                            modifierFlags: .command)
    
    let runWithArguments = UIKeyCommand(title: Localizable.runAndSetArguments,
                           action: #selector(EditorSplitViewController.runWithArguments),
                            input: "r",
                            modifierFlags: [.shift, .command])
    
    let stop = UIKeyCommand(title: Localizable.stop,
                           action: #selector(EditorSplitViewController.stopScript(_:)),
                            input: "x",
                            modifierFlags: [.shift, .command])

    let save = UIKeyCommand(title: NSLocalizedString("Save", bundle: Bundle(for: UIApplication.self), comment: ""),
                            action: #selector(EditorViewController.saveScript(_:)),
                            input: "s",
                            modifierFlags: .command)
    
    let find = UIKeyCommand(title: Localizable.find,
                            action: NSSelectorFromString("search"),
                            input: "f",
                            modifierFlags: .command)
    
    let openScript = UIKeyCommand(title: NSLocalizedString("Open", tableName: "SavePanel", bundle: Bundle(for: NSClassFromString("NSApplication") ?? UIApplication.self), value: "Open", comment: ""),
                            action: #selector(UIResponder.showBrowser(_:)),
                            input: "o",
                            modifierFlags: [.command])
    
    let repl = UIKeyCommand(title: Localizable.repl,
                            action: #selector(UIResponder.showREPL(_:)),
                            input: "e",
                            modifierFlags: [.command, .shift])
    
    let docs = UIKeyCommand(title: Localizable.Help.documentation,
                            action: #selector(UIResponder.showDocumentation(_:)),
                            input: "0",
                            modifierFlags: [.command, .shift])
    
    let examples = UIKeyCommand(title: Localizable.Help.samples,
                            action: #selector(UIResponder.showExamples(_:)),
                            input: "1",
                            modifierFlags: [.command, .shift])
        
    let pyPI = UIKeyCommand(title: "PyPI",
                            action: #selector(UIResponder.showPyPI(_:)),
                            input: "2",
                            modifierFlags: [.command, .shift])
    
    var prefsString = NSLocalizedString("%@ Preferences", tableName: "Preferences", bundle: Bundle(for: NSClassFromString("NSApplication") ?? UIApplication.self), value: " Preferences", comment: "").replacingOccurrences(of: "%@", with: "")
    if prefsString.hasPrefix(" ") {
        prefsString.removeFirst()
    }
    let prefs = UIKeyCommand(title: prefsString,
                            action: #selector(UIResponder.showPreferences(_:)),
                            input: ",",
                            modifierFlags: [.command])

    let automator = UIKeyCommand(title: Localizable.installAutomatorAction,
                                 action: #selector(UIResponder.installAutomatorAction(_:)),
                                 input: "",
                                 modifierFlags: [])
    
    let new = UIKeyCommand(title: NSLocalizedString("New Document", tableName: "Document", bundle: Bundle(for: NSClassFromString("NSApplication") ?? UIApplication.self), value: "New Document", comment: ""),
                           action: #selector(UIResponder.newScript),
                           input: "n",
                           modifierFlags: [.command])
    
    let toggleComment = UIKeyCommand.command(input: "c", modifierFlags: [.command, .shift], action: #selector(EditorViewController.toggleComment), discoverabilityTitle: Localizable.MenuItems.toggleComment)
    let setBreakpoint = UIKeyCommand.command(input: "b", modifierFlags: [.command, .shift], action: #selector(EditorViewController.setBreakpoint(_:)), discoverabilityTitle: Localizable.MenuItems.breakpoint)
    let unindent = UIKeyCommand.command(input: "t", modifierFlags: [.alternate], action: #selector(EditorViewController.unindent), discoverabilityTitle: Localizable.unindent)
    
    let undo = UIKeyCommand.command(input: "z", modifierFlags: [.command], action: #selector(EditorTextView.undo), discoverabilityTitle: Localizable.unindent)
    
    let redo = UIKeyCommand.command(input: "z", modifierFlags: [.command, .shift], action: #selector(EditorTextView.redo), discoverabilityTitle: Localizable.MenuItems.redo)
    
    let fileMenuTop = UIMenu(title: "", options: .displayInline, children: ProcessInfo.processInfo.isiOSAppOnMac ? [new, openScript, repl] : [repl])
    let fileMenu = UIMenu(title: "", options: .displayInline, children: [save, stop, run, runWithArguments])
    let editMenu = UIMenu(title: "", options: .displayInline, children: [redo, undo, find, toggleComment, setBreakpoint, unindent])
    
    let windowMenu = UIMenu(title: "", options: .displayInline, children: [docs, examples, pyPI])

    let pytoMenu = UIMenu(title: "", options: .displayInline, children: [automator, prefs])
    
    builder.remove(menu: .newScene)
    builder.remove(menu: .preferences)
    if ProcessInfo.processInfo.isiOSAppOnMac {
        builder.insertSibling(pytoMenu, afterMenu: .about)
        builder.insertChild(windowMenu, atEndOfMenu: .window)
        
    }
    
    builder.insertChild(fileMenu, atEndOfMenu: .file)
    builder.insertChild(fileMenuTop, atStartOfMenu: .file)
    builder.insertChild(editMenu, atEndOfMenu: .edit)
}
