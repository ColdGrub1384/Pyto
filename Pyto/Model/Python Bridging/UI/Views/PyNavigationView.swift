//
//  PyNavigationView.swift
//  Pyto
//
//  Created by Emma on 18-06-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import UIKit

class PyNavigationView: PyView {
    
    @objc class func newView(rootViewController: UIViewController) -> PyView {
        var navVC: UINavigationController!
        
        let navView = PyNavigationView(managed: get {
            
            let vc = ConsoleViewController.ViewController()
            vc.navigationItem.largeTitleDisplayMode = rootViewController.navigationItem.largeTitleDisplayMode
            rootViewController.view.frame = vc.view.bounds
            rootViewController.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
            vc.addChild(rootViewController)
            vc.view.addSubview(rootViewController.view)
            
            navVC = ConsoleViewController.NavigationController(rootViewController: vc)
            return navVC.view
        })
        
        set {
            navView.viewController = navVC
            
            navVC.navigationBar.prefersLargeTitles = true
            
            guard let view = navView.navigationController.viewControllers.last!.view.subviews.first else {
                return
            }
            var pyView = PyView.view(view)
            if pyView == nil {
                pyView = PyView(managed: view)
                PyView.values[view] = pyView
            }
            pyView?.viewController = navVC
            
            view.leftButtonItems = (rootViewController.navigationItem.leftBarButtonItems as? NSArray) ?? []
            view.rightButtonItems = (rootViewController.navigationItem.rightBarButtonItems as? NSArray) ?? []
            
            pyView?.title = rootViewController.title
            
            (navVC as? ConsoleViewController.NavigationController)?.pyViews = [pyView!]
        }
        
        return navView
    }
    
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
                (navVC as! ConsoleViewController.NavigationController).pyViews = [rootView]
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
    
    @objc var views: [PyView] {
        get {
            get {
                self.navigationController.viewControllers.compactMap({ vc in
                    if let consoleVC = vc as? ConsoleViewController.ViewController, let view = consoleVC.view.subviews.first {
                        return PyView.values[view]
                    } else {
                        return PyView.values[vc.view]
                    }
                })
            }
        }
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
            
            (view.navigationView as? PyNavigationView)?.navigationController.viewControllers.first?.view = UIView()
            (view.navigationView as? PyNavigationView)?.navigationController.viewControllers = []
            
            let vc = ConsoleViewController.ViewController()
            view.view.frame = vc.view.bounds
            view.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
            vc.view.addSubview(view.view)
            vc.title = view.title
            vc.view.backgroundColor = view.view.backgroundColor
            view.viewController = vc
            vc.navigationItem.largeTitleDisplayMode = .never
            (self.navigationController as? ConsoleViewController.NavigationController)?.pyViews.append(view)
            (self.navigationController as? ConsoleViewController.NavigationController)?.setBarColor()
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
