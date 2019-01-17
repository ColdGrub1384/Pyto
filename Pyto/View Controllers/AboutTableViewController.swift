//
//  AboutTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices

fileprivate extension IndexPath {
    
    static let theme = IndexPath(row: 0, section: 0)
    
    static let help = IndexPath(row: 0, section: 1)
    static let documentation = IndexPath(row: 1, section: 1)
    
    static let acknowledgments = IndexPath(row: 0, section: 2)
    static let sourceCode = IndexPath(row: 1, section: 2)
}

/// A View controller with settings and info.
class AboutTableViewController: UITableViewController {
    
    /// The date of the build.
    var buildDate: Date {
        if let infoPath = Bundle.main.path(forResource: "Info", ofType: "plist"), let infoAttr = try? FileManager.default.attributesOfItem(atPath: infoPath), let infoDate = infoAttr[.creationDate] as? Date {
            return infoDate
        } else {
            return Date()
        }
    }
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    // MARK: - Table view controller
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = super.tableView(tableView, cellForRowAt: indexPath)
        cell.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        cell.textLabel?.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let viewControllerToPresent: UIViewController?
        
        switch indexPath {
        case .theme:
            viewControllerToPresent = UIStoryboard(name: "Theme Chooser", bundle: Bundle.main).instantiateInitialViewController()
        case .help:
            dismiss(animated: true) {
                if let help = Bundle.main.url(forResource: "Help", withExtension: "py") {
                    DocumentBrowserViewController.visible?.openDocument(help, run: false)
                }
            }
            return
        case .documentation:
            viewControllerToPresent = ThemableNavigationController(rootViewController: DocumentationViewController())
        case .acknowledgments:
            viewControllerToPresent = ThemableNavigationController(rootViewController: AcknowledgmentsViewController())
        case .sourceCode:
            viewControllerToPresent = SFSafariViewController(url: URL(string: "https://github.com/ColdGrub1384/Pyto")!)
        default:
            viewControllerToPresent = nil
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
        
        guard let vc = viewControllerToPresent else {
            return
        }
        
        if indexPath == .theme {
            navigationController?.pushViewController(vc, animated: true)
        } else {
            present(vc, animated: true, completion: nil)
        }
    }
    
    override func tableView(_ tableView: UITableView, titleForFooterInSection section: Int) -> String? {
        
        if section == 3, let version = Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String, let build = Bundle.main.infoDictionary?[kCFBundleVersionKey as String] as? String {
            
            let formatter = DateFormatter()
            formatter.dateStyle = .medium
            formatter.timeStyle = .short
            
            return """
            Pyto version \(version) (\(build)) \(formatter.string(from: buildDate))
            
            Python \(Python.shared.version)
            """
        } else {
            return nil
        }
    }
}
