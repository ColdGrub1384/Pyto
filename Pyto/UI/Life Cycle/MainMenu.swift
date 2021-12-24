//
//  MainMenu.swift
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
    
    @objc func openNewWindow(_ sender: Any) {
        UIApplication.shared.requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
    }
}

func setupMenu(builder: UIMenuBuilder) {
    // Ensure that the builder is modifying the menu bar system.

    guard #available(iOS 14.0, *) else {
        return
    }
    
    guard builder.system == UIMenuSystem.main else { return }

    let newWindow = UIKeyCommand(title: NSLocalizedString("New window", comment: "A menu bar item to open a new window"),
                                 action: #selector(UIResponder.openNewWindow(_:)),
                                  input: "n",
                                 modifierFlags: [.command, .shift])
    
    let run = UIKeyCommand(title: NSLocalizedString("menuItems.run", comment: "The 'Run' menu item"),
                           action: #selector(EditorSplitViewController.runScript(_:)),
                            input: "r",
                            modifierFlags: .command)
    
    let runWithArguments = UIKeyCommand(title: NSLocalizedString("runAndSetArguments", comment: "Description for key command for running and setting arguments."),
                           action: #selector(EditorSplitViewController.runWithArguments),
                            input: "r",
                            modifierFlags: [.shift, .command])
    
    let stop = UIKeyCommand(title: NSLocalizedString("stop", comment: "Stop the execution of a script"),
                           action: #selector(EditorSplitViewController.stopScript(_:)),
                            input: "x",
                            modifierFlags: [.shift, .command])

    let save = UIKeyCommand(title: NSLocalizedString("Save", bundle: Bundle(for: UIApplication.self), comment: ""),
                            action: #selector(EditorViewController.saveScript(_:)),
                            input: "s",
                            modifierFlags: .command)
    
    let find = UIKeyCommand(title: NSLocalizedString("find", comment: "'Find'"),
                            action: NSSelectorFromString("search"),
                            input: "f",
                            modifierFlags: .command)
    
    let openScript = UIKeyCommand(title: NSLocalizedString("Open", tableName: "SavePanel", bundle: Bundle(for: NSClassFromString("NSApplication") ?? UIApplication.self), value: "Open", comment: ""),
                                  action: #selector(SidebarSplitViewController.openScript),
                            input: "o",
                            modifierFlags: [.command])
    
    let repl = UIKeyCommand(title: NSLocalizedString("repl", comment: "The REPL"),
                            action: #selector(SidebarSplitViewController.showREPL),
                            input: "e",
                            modifierFlags: [.command, .shift])
    
    let docs = UIKeyCommand(title: NSLocalizedString("help.documentation", comment: "'Documentation' button"),
                            action: #selector(SidebarSplitViewController.showDocumentationOnSplitView),
                            input: "d",
                            modifierFlags: [.command])

    let pyPI = UIKeyCommand(title: "PyPI",
                            action: #selector(SidebarSplitViewController.showPyPI),
                            input: "p",
                            modifierFlags: [.command, .shift])
    
    var prefsString = NSLocalizedString("%@ Preferences", tableName: "Preferences", bundle: Bundle(for: NSClassFromString("NSApplication") ?? UIApplication.self), value: " Preferences", comment: "").replacingOccurrences(of: "%@", with: "")
    if prefsString.hasPrefix(" ") {
        prefsString.removeFirst()
    }
    let prefs = UIKeyCommand(title: prefsString,
                             action: #selector(SidebarSplitViewController.showSettings),
                            input: ",",
                            modifierFlags: [.command])

    let automator = UIKeyCommand(title: NSLocalizedString("automator.install", comment: "Title of the menu bar item to install the Automator action"),
                                 action: #selector(UIResponder.installAutomatorAction(_:)),
                                 input: "",
                                 modifierFlags: [])
    
    let new = UIKeyCommand(title: NSLocalizedString("New Document", tableName: "Document", bundle: Bundle(for: NSClassFromString("NSApplication") ?? UIApplication.self), value: "New Document", comment: ""),
                           action: #selector(SidebarSplitViewController.newScript),
                           input: "n",
                           modifierFlags: [.command])
    
    let toggleComment = UIKeyCommand.command(input: "c", modifierFlags: [.command, .shift], action: #selector(EditorViewController.toggleComment), discoverabilityTitle: NSLocalizedString("menuItems.toggleComment", comment: "The 'Toggle Comment' menu item"))
    let unindent = UIKeyCommand.command(input: "t", modifierFlags: [.alternate], action: #selector(EditorViewController.unindent), discoverabilityTitle: NSLocalizedString("unindent", comment: "'Unindent' key command"))
    
    let undo = UIKeyCommand.command(input: "z", modifierFlags: [.command], action: #selector(EditorTextView.undo), discoverabilityTitle: NSLocalizedString("unindent", comment: "'Unindent' key command"))
    
    let redo = UIKeyCommand.command(input: "z", modifierFlags: [.command, .shift], action: #selector(EditorTextView.redo), discoverabilityTitle: NSLocalizedString("menuItems.redo", comment: "The 'Redo' menu item"))
    
    var fileMenuTopItems = [new, openScript]
    if isiOSAppOnMac {
        fileMenuTopItems.insert(newWindow, at: 0)
    }
    let fileMenuTop = UIMenu(title: "", options: .displayInline, children: fileMenuTopItems)
    let fileMenu = UIMenu(title: "", options: .displayInline, children: [save, stop, run, runWithArguments])
    let editMenu = UIMenu(title: "", options: .displayInline, children: [redo, undo, find, toggleComment, unindent])
    
    let windowMenu = UIMenu(title: "", options: .displayInline, children: [repl, docs, pyPI])

    var pytoMenuItems = [automator, prefs]
    if !isiOSAppOnMac {
        pytoMenuItems.remove(at: 0)
    }
    let pytoMenu = UIMenu(title: "", options: .displayInline, children: pytoMenuItems)
    
    builder.remove(menu: .newScene)
    builder.remove(menu: .preferences)
    
    builder.insertSibling(pytoMenu, afterMenu: .about)
    builder.insertChild(windowMenu, atEndOfMenu: .window)
    
    builder.insertChild(fileMenu, atEndOfMenu: .file)
    builder.insertChild(fileMenuTop, atStartOfMenu: .file)
    builder.insertChild(editMenu, atEndOfMenu: .edit)
}
