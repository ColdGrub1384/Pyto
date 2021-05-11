//
//  MenuViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 4/17/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import FileBrowser
import SwiftUI

/// A View controller for choosing from `REPL`, `PyPi` and `Settings` from an `UIDocumentBrowserViewController`.
@objc class MenuTableViewController: UITableViewController {
    
    /// The Pyto version.
    @objc static var pytoVersion: String {
        
        var buildDate: Date {
            if let infoPath = Bundle.main.path(forResource: "Info", ofType: "plist"), let infoAttr = try? FileManager.default.attributesOfItem(atPath: infoPath), let infoDate = infoAttr[.creationDate] as? Date {
                return infoDate
            } else {
                return Date()
            }
        }
        
        guard let version = Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String, let build = Bundle.main.infoDictionary?[kCFBundleVersionKey as String] as? String else {
            return ""
        }
        
        let formatter = DateFormatter()
        formatter.dateStyle = .medium
        formatter.timeStyle = .short
        
        return "Pyto version \(version) (\(build)) \(formatter.string(from: buildDate))"
    }
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    /// Opens the REPL.
    func selectREPL() {
        if let repl = self.storyboard?.instantiateViewController(withIdentifier: "repl") {
            present(repl, animated: true, completion: nil)
        }
    }
    
    /// Makes a View Controller for PyPi.
    ///
    /// - Returns: A View Controller (without Navigation Controller).
    static func makePyPiView() -> UIViewController {
        
        class ViewController: UIViewController {
            
            override func viewDidAppear(_ animated: Bool) {
                super.viewDidAppear(animated)
                
                view.window?.windowScene?.title = "PyPI"
            }
            
            @objc func close() {
                dismiss(animated: true, completion: nil)
            }
        }
        
        let vc = ViewController()
        if !isiOSAppOnMac {
            vc.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: vc, action: #selector(vc.close))
        }
        
        func run(command: String) {
            let installer = PipInstallerViewController(command: command)
            let _navVC = ThemableNavigationController(rootViewController: installer)
            _navVC.modalPresentationStyle = .formSheet
            vc.present(_navVC, animated: true, completion: nil)
        }
        
        let view = PyPiView(hostingController: vc) { package, install, remove in
            
            if install {
                run(command: "--verbose install \(package)")
            } else if remove {
                run(command: "--verbose uninstall \(package)")
            } else {
                if let pypi = UIStoryboard(name: "Main", bundle: .main).instantiateViewController(withIdentifier: "pypi") as? PipViewController {
                    DispatchQueue.global().async {
                        let pyPackage = PyPackage(name: package)
                        
                        DispatchQueue.main.async {
                            
                            pypi.currentPackage = pyPackage
                            if let name = pyPackage?.name {
                                pypi.title = name
                            }
                            
                            vc.show(pypi, sender: nil)
                        }
                    }
                }
            }
        }
        
        let hostVC = UIHostingController(rootView: view)
        vc.addChild(hostVC)
        vc.view.addSubview(hostVC.view)
        hostVC.view.frame = vc.view.frame
        hostVC.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        
        vc.title = "PyPI" // TODO: Localization
        
        return vc
    }
    
    /// Opens PyPi.
    @available(iOS 13.0, *)
    func selectPyPi() {
        
        let vc = MenuTableViewController.makePyPiView()
        let navVC = UINavigationController(rootViewController: vc)
        navVC.modalPresentationStyle = .formSheet
        navVC.navigationBar.prefersLargeTitles = true
        
        present(navVC, animated: true, completion: nil)
    }
    
    /// Show samples..
    func selectSamples() {
        guard let samples = Bundle.main.url(forResource: "Samples", withExtension: nil) else {
            return
        }
        
        let presentingVC = presentingViewController
        
        if #available(iOS 13.4, *) {
            let controller = UIHostingController(rootView: SamplesNavigationView(url: samples, selectScript: { _ in }))
            
            let view = SamplesNavigationView(url: samples, selectScript: { (file) in
                
                guard file.pathExtension.lowercased() == "py" else {
                    return
                }
                
                (presentingVC?.view.window?.rootViewController as? DocumentBrowserViewController)?.openDocument(file, run: false, viewController: controller)
                
            }, hostController: controller)
            controller.rootView = view
            present(controller, animated: true, completion: nil)
        } else {
            
            let fileBrowser = FileBrowser(initialPath: samples, allowEditing: false, showCancelButton: true)
            fileBrowser.didSelectFile = { file in
                guard file.filePath.pathExtension.lowercased() == "py" else {
                    return
                }
                
                fileBrowser.presentingViewController?.dismiss(animated: true) {
                    (presentingVC as? DocumentBrowserViewController)?.openDocument(file.filePath, run: false)
                }
            }
            
            present(fileBrowser, animated: true, completion: nil)
        }
    }
    
    /// Opens documentation.
    func selectDocumentation() {
        let documentation = DocumentationViewController()
        present(ThemableNavigationController(rootViewController: documentation), animated: true, completion: nil)
    }
    
    /// Shows loaded modules.
    func selectLoadedModules() {
        present(UINavigationController(rootViewController: ModulesTableViewController(style: .grouped)), animated: true, completion: nil)
    }
    
    /// Opens settings.
    func selectSettings() {
                
        if let settings = UIStoryboard(name: "Settings", bundle: nil).instantiateInitialViewController() {
            let navVC = UINavigationController(rootViewController: settings)
            navVC.navigationBar.prefersLargeTitles = true
            navVC.modalPresentationStyle = .formSheet
            present(navVC, animated: true, completion: nil)
        }
    }
    
    // MARK: - Table view controller
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = super.tableView(tableView, cellForRowAt: indexPath)
        
        guard #available(iOS 13.0, *) else {
            return cell
        }
        
        var image: UIImage?
        switch indexPath {
        case IndexPath(row: 0, section: 0):
            image = UIImage(systemName: "play.fill")
        case IndexPath(row: 1, section: 0):
            image = UIImage(systemName: "doc.fill")
        case IndexPath(row: 0, section: 1):
            image = UIImage(named: "pypi")
        case IndexPath(row: 0, section: 2):
            image = UIImage(systemName: "bookmark.fill")
        case IndexPath(row: 1, section: 2):
            image = UIImage(systemName: "book.fill")
        case IndexPath(row: 0, section: 3):
            image = UIImage(systemName: "info.circle.fill")
        case IndexPath(row: 1, section: 3):
            image = UIImage(systemName: "gear")
        default:
            break
        }
        cell.imageView?.image = image
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath {
        case IndexPath(row: 0, section: 0):
            selectREPL()
        case IndexPath(row: 0, section: 1):
            selectPyPi()
        case IndexPath(row: 0, section: 2):
            selectSamples()
        case IndexPath(row: 1, section: 2):
            selectDocumentation()
        case IndexPath(row: 0, section: 3):
            selectLoadedModules()
        case IndexPath(row: 1, section: 3):
            selectSettings()
        default:
            break
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, titleForFooterInSection section: Int) -> String? {
        
        if section == 3 {
            
            let formatter = DateFormatter()
            formatter.dateStyle = .medium
            formatter.timeStyle = .short
            
            return """
            \n\(MenuTableViewController.pytoVersion)
            
            Python \(Python.shared.version)
            """
        } else {
            return super.tableView(tableView, titleForFooterInSection: section)
        }
    }
}
