//
//  SidebarController.swift
//  Pyto
//
//  Created by Adrian Labbé on 08-09-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 14.0, *)
class SidebarController: UIHostingController<AnyView> {
    
    override var childForHomeIndicatorAutoHidden: UIViewController? {
        guard let scene = view.window?.windowScene else {
            return nil
        }
        
        guard let editor = EditorView.EditorStore.perScene[scene]?.editor else {
            return nil
        }
        
        guard editor.viewController?.view.window != nil else {
            return nil
        }
        
        return editor.viewController
    }
}
