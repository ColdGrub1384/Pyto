//
//  PyNavigationView.swift
//  Pyto
//
//  Created by Emma on 18-06-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import UIKit

class PyNavigationView: PyView {
    
    @objc class func newView(rootView: PyView?) -> PyView {
        
        var navVC: UINavigationController!
        
        let navView = PyNavigationView(managed: get {
            if let rootView = rootView {
                let vc = ConsoleViewController.ViewController()
                vc.view.addSubview(rootView.view)
                rootView.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
                vc.title = rootView.title
                rootView.viewController = vc
                
                navVC = ConsoleViewController.NavigationController(rootViewController: vc)
                return navVC.view
            } else {
                navVC = ConsoleViewController.NavigationController()
                return navVC.view
            }
        })
        
        set {
            navView.viewController = navVC
            navVC.view.backgroundColor = .systemBackground
            navVC.navigationBar.prefersLargeTitles = true
        }
        
        return navView
    }
    
    var navigationController: UINavigationController {
        viewController as! UINavigationController
    }
    
    @objc func pop() {
        set {
            self.navigationController.popViewController(animated: true)
        }
    }
    
    @objc func popToRootViewController() {
        set {
            self.navigationController.popToRootViewController(animated: true)
        }
    }
    
    @objc public func pushView(_ view: PyView) {
        set {
            let vc = ConsoleViewController.ViewController()
            vc.view.addSubview(view.view)
            vc.title = view.title
            self.navigationController.pushViewController(vc, animated: true)
        }
    }
    
    @objc var navigationBarHidden: Bool {
        get {
            get {
                self.navigationController.isNavigationBarHidden
            }
        }
        
        set {
            set {
                self.navigationController.isNavigationBarHidden = newValue
            }
        }
    }
}
