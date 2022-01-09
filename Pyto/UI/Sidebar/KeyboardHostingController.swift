//
//  KeyboardHostingController.swift
//  Pyto
//
//  Created by Emma on 13-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import SwiftUI

class KeyboardHostingController: UIHostingController<KeyboardHostingController.Container.View> {
    
    struct Container: UIViewControllerRepresentable {

        var viewController: UIViewController
        
        struct View: SwiftUI.View {
            
            var viewController: UIViewController
            
            var body: some SwiftUI.View {
                Container(viewController: viewController).ignoresSafeArea(.container, edges: .all)
            }
        }
        
        func makeUIViewController(context: Context) -> some UIViewController {
            viewController
        }
        
        func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
            
        }
    }
    
    let viewController: UIViewController
    
    init(viewController: UIViewController) {
        self.viewController = viewController
        super.init(rootView: Container.View(viewController: viewController))
    }
    
    @MainActor @objc required dynamic init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override var childForHomeIndicatorAutoHidden: UIViewController? {
        viewController
    }
}
