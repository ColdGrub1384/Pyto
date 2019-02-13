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
    
    //
    // If you modify this, you should check `AppDelegate.application(_:open:options:)` function.
    //
    
    static let theme = IndexPath(row: 0, section: 0)
    static let indentation = IndexPath(row: 1, section: 0)
    
    static let todayWidget = IndexPath(row: 0, section: 1)
    
    static let help = IndexPath(row: 0, section: 2)
    static let documentation = IndexPath(row: 1, section: 2)
    
    static let acknowledgments = IndexPath(row: 0, section: 3)
    static let sourceCode = IndexPath(row: 1, section: 3)
}

/// A View controller with settings and info.
class AboutTableViewController: UITableViewController, DocumentBrowserViewControllerDelegate {
    
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
    
    /// Called when indentation is set.
    @IBAction func indentationChanged(_ sender: UISegmentedControl) {
        switch sender.selectedSegmentIndex {
        case 0:
            EditorViewController.indentation = "\t"
        case 1:
            EditorViewController.indentation = "  "
        case 2:
            EditorViewController.indentation = "    "
        case 3:
            EditorViewController.indentation = "      "
        case 4:
            EditorViewController.indentation = "        "
        default:
            EditorViewController.indentation = "  "
        }
    }
    
    /// The segmented control managing identation.
    @IBOutlet weak var identationSegmentedControl: UISegmentedControl!
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        switch EditorViewController.indentation {
        case "\t":
            identationSegmentedControl.selectedSegmentIndex = 0
        case "  ":
            identationSegmentedControl.selectedSegmentIndex = 1
        case "    ":
            identationSegmentedControl.selectedSegmentIndex = 2
        case "      ":
            identationSegmentedControl.selectedSegmentIndex = 3
        case "        ":
            identationSegmentedControl.selectedSegmentIndex = 4
        default:
            identationSegmentedControl.selectedSegmentIndex = 0
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = super.tableView(tableView, cellForRowAt: indexPath)
        cell.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        cell.textLabel?.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
        cell.detailTextLabel?.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
        
        if indexPath == .todayWidget {
            cell.detailTextLabel?.text = (UserDefaults.standard.string(forKey: "todayWidgetScriptPath") as NSString?)?.lastPathComponent
        } else if indexPath == .indentation {
            for view in cell.contentView.subviews {
                (view as? UILabel)?.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
            }
        }
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let viewControllerToPresent: UIViewController?
        
        switch indexPath {
        case .theme:
            viewControllerToPresent = UIStoryboard(name: "Theme Chooser", bundle: Bundle.main).instantiateInitialViewController()
        case .todayWidget:
            guard let browser = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "Browser") as? DocumentBrowserViewController else {
                return
            }
            browser.delegate = self
            viewControllerToPresent = browser
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
        
        if indexPath == .theme || indexPath == .todayWidget {
            navigationController?.pushViewController(vc, animated: true)
        } else {
            present(vc, animated: true, completion: nil)
        }
    }
    
    override func tableView(_ tableView: UITableView, titleForFooterInSection section: Int) -> String? {
        
        if section == 4, let version = Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String, let build = Bundle.main.infoDictionary?[kCFBundleVersionKey as String] as? String {
            
            let formatter = DateFormatter()
            formatter.dateStyle = .medium
            formatter.timeStyle = .short
            
            return """
            Pyto version \(version) (\(build)) \(formatter.string(from: buildDate))
            
            Python \(Python.shared.version)
            """
        } else {
            return super.tableView(tableView, titleForFooterInSection: section)
        }
    }
    
    // MARK: - Document browser view controller delegate
    
    func documentBrowserViewController(_ documentBrowserViewController: DocumentBrowserViewController, didPickScriptAtPath path: String) {
        
        navigationController?.popToRootViewController(animated: true)
        
        UserDefaults.standard.set(RelativePathForScript(URL(fileURLWithPath: path)), forKey: "todayWidgetScriptPath")
        UserDefaults.standard.synchronize()
        (UIApplication.shared.delegate as? AppDelegate)?.copyModules()
        
        tableView.reloadData()
    }
}
