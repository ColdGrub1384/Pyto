//
//  setMacMainMenu.swift
//  Pyto
//
//  Created by administrator on 12/13/20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import SwiftUI

/// Shows a window with the given View controller.
func showWindow(vc: UIViewController?) {
    
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

@available(iOS 14.0, *)
fileprivate class OpenProjectViewController: UIViewController, UIDocumentPickerDelegate {
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        let picker = UIDocumentPickerViewController(forOpeningContentTypes: [.folder])
        picker.delegate = self
        present(picker, animated: false, completion: nil)
    }
    
    func documentPickerWasCancelled(_ controller: UIDocumentPickerViewController) {
        dismiss(animated: true, completion: nil)
    }
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        let dir = urls[0]
        _ = dir.startAccessingSecurityScopedResource()
        let browser = ProjectsBrowserViewController()
        browser.open(url: dir, viewController: self)
    }
}

extension UIResponder {
    
    @objc func showDocumentation(_ sender: Any) {
        showWindow(vc: DocumentationViewController())
    }
    
    @objc func showProject(_ sender: Any) {
        if #available(iOS 14.0, *) {
            showWindow(vc: OpenProjectViewController())
        }
    }
    
    @objc func showBrowser(_ sender: Any) {
        if #available(iOS 14.0, *) {
            showWindow(vc: DocumentBrowserViewController(forOpening: [.pythonScript]))
        }
    }
    
    @objc func showREPL(_ sender: Any) {
        if #available(iOS 14.0, *) {
            showWindow(vc: REPLViewController())
        }
    }
    
    @objc func showPyPI(_ sender: Any) {
        if #available(iOS 14.0, *) {
            let navVC = UINavigationController(rootViewController: MenuTableViewController.makePyPiView())
            navVC.navigationBar.prefersLargeTitles = true
            showWindow(vc: navVC)
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
            showWindow(vc: vc)
        }
    }
    
    @objc func showPreferences(_ sender: Any) {
        if #available(iOS 14.0, *), let vc = UIStoryboard(name: "Settings", bundle: .main).instantiateInitialViewController() {
            let navVC = UINavigationController(rootViewController: vc)
            showWindow(vc: navVC)
        }
    }
}

func setupMacMenu(builder: UIMenuBuilder) {
    // Ensure that the builder is modifying the menu bar system.
    guard builder.system == UIMenuSystem.main else { return }

    let run = UIKeyCommand(title: Localizable.MenuItems.run,
                           action: #selector(EditorSplitViewController.runScript(_:)),
                            input: "r",
                            modifierFlags: .command)

    let save = UIKeyCommand(title: NSLocalizedString("Save", bundle: Bundle(for: UIApplication.self), comment: ""),
                            action: #selector(EditorViewController.saveScript(_:)),
                            input: "s",
                            modifierFlags: .command)
    
    let find = UIKeyCommand(title: Localizable.find,
                            action: #selector(EditorSplitViewController.search),
                            input: "f",
                            modifierFlags: .command)
    
    let openScript = UIKeyCommand(title: "Open script",
                            action: #selector(UIResponder.showBrowser(_:)),
                            input: "o",
                            modifierFlags: [.command])
    
    let openProject = UIKeyCommand(title: "Open project",
                            action: #selector(UIResponder.showProject(_:)),
                            input: "o",
                            modifierFlags: [.command, .shift])
    
    let repl = UIKeyCommand(title: Localizable.repl,
                            action: #selector(UIResponder.showREPL(_:)),
                            input: "r",
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
    
    let prefs = UIKeyCommand(title: "Preferences",
                            action: #selector(UIResponder.showPreferences(_:)),
                            input: ",",
                            modifierFlags: [.command])

    let fileMenuTop = UIMenu(title: "", options: .displayInline, children: [openScript, openProject, repl])
    let fileMenu = UIMenu(title: "", options: .displayInline, children: [save, run])
    let editMenu = UIMenu(title: "", options: .displayInline, children: [find])
    
    let windowMenu = UIMenu(title: "", options: .displayInline, children: [docs, examples, pyPI])

    let pytoMenu = UIMenu(title: "", options: .displayInline, children: [prefs])
    
    builder.insertSibling(pytoMenu, afterMenu: .about)
    builder.insertChild(fileMenuTop, atStartOfMenu: .file)
    builder.insertChild(fileMenu, atEndOfMenu: .file)
    builder.insertChild(editMenu, atEndOfMenu: .edit)
    builder.insertChild(windowMenu, atEndOfMenu: .window)
}
