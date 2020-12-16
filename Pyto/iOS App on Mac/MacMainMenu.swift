//
//  setMacMainMenu.swift
//  Pyto
//
//  Created by administrator on 12/13/20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

fileprivate func showWindow(selection: SelectedSection) {
    let activity = NSUserActivity(activityType: "openWindow")
    
    let data: Data
    do {
        let state = SceneState(selection: selection)
        data = try JSONEncoder().encode(state)
    } catch {
        print(error)
        return
    }
    
    activity.addUserInfoEntries(from: ["sceneState": data])
    UIApplication.shared.requestSceneSessionActivation(nil, userActivity: activity, options: nil, errorHandler: nil)
}

extension UIResponder {
    
    @objc func showDocumentation(_ sender: Any) {
        showWindow(selection: .documentation)
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
    
    let docs = UIKeyCommand(title: Localizable.Help.documentation,
                            action: #selector(UIResponder.showDocumentation(_:)),
                            input: "d",
                            modifierFlags: .command)

    let fileMenu = UIMenu(title: "", options: .displayInline, children: [save, run])
    let editMenu = UIMenu(title: "", options: .displayInline, children: [find])
    
    let windowMenu = UIMenu(title: "", options: .displayInline, children: [docs])

    builder.insertChild(fileMenu, atEndOfMenu: .file)
    builder.insertChild(editMenu, atEndOfMenu: .edit)
    builder.insertChild(windowMenu, atEndOfMenu: .window)
}
