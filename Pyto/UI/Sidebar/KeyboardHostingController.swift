//
//  KeyboardHostingController.swift
//  Pyto
//
//  Created by Emma on 13-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import SwiftUI

func findFirstResponder(inView view: UIView) -> UIView? {
    for subView in view.subviews {
        if subView.isFirstResponder {
            return subView
        }
        
        if let recursiveSubView = findFirstResponder(inView: subView) {
            return recursiveSubView
        }
    }
    
    return nil
}

class KeyboardHostingController: UIViewController {
    
    /*struct Container: UIViewControllerRepresentable {

        var viewController: UIViewController
                
        struct View: SwiftUI.View {
            
            var viewController: UIViewController
            
            @ObservedObject fileprivate var keyboardStatusManager: KeyboardStatusManager
            
            var body: some SwiftUI.View {
                Container(viewController: viewController).ignoresSafeArea(keyboardStatusManager.isKeyboardShown ? .container : [.container, .keyboard], edges: .all)
            }
        }
        
        func makeUIViewController(context: Context) -> some UIViewController {
            viewController
        }
        
        func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
            
        }
    }*/
    
    let viewController: UIViewController
        
    init(viewController: UIViewController) {
        self.viewController = viewController
        super.init(nibName: nil, bundle: nil)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        viewController.view.frame = view.bounds
        viewController.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        addChild(viewController)
        view.addSubview(viewController.view)
        
        NotificationCenter.default.addObserver(forName: UIResponder.keyboardWillShowNotification, object: nil, queue: .main) { [weak self] notification in
            
            guard let self = self else {
                return
            }
            
            guard let height = (notification.userInfo?["UIKeyboardBoundsUserInfoKey"] as? CGRect)?.height, height > 200 else { // Only software keyboard
                return
            }
            
            self.viewController.view.frame.size.height = self.view.bounds.height-height
        }
        
        NotificationCenter.default.addObserver(forName: UIResponder.keyboardWillHideNotification, object: nil, queue: .main) { [weak self] notification in
            
            guard let self = self else {
                return
            }
            
            self.viewController.view.frame = self.view.bounds
        }
    }
    
    var previousTraitCollection: UITraitCollection?
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {
        super.willTransition(to: newCollection, with: coordinator)
        
        // Save and restore user activity when changing from a compact horizontal size to regular or vice versa
            
        guard let previousTraitCollection = previousTraitCollection else {
            self.previousTraitCollection = newCollection
            return
        }
        
        self.previousTraitCollection = newCollection

        guard let scene = view.window?.windowScene else {
            return
        }
        
        guard scene.activationState == .foregroundActive || scene.activationState == .foregroundInactive else {
            return
        }
        
        if previousTraitCollection.horizontalSizeClass != newCollection.horizontalSizeClass {
            guard let userActivity = scene.delegate?.stateRestorationActivity?(for: scene) else {
                return
            }
            
            coordinator.animate(alongsideTransition: nil) { _ in
                scene.delegate?.scene?(scene, continue: userActivity)
            }
        }
    }
    
    @MainActor @objc required dynamic init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override var childForHomeIndicatorAutoHidden: UIViewController? {
        viewController
    }
}
