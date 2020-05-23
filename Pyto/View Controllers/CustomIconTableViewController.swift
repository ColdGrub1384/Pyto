//
//  CustomIconTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 12-12-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

fileprivate extension Bundle {
    
    var icon: UIImage? {
        if let icons = infoDictionary?["CFBundleIcons"] as? [String: Any],
            let primaryIcon = icons["CFBundlePrimaryIcon"] as? [String: Any],
            let iconFiles = primaryIcon["CFBundleIconFiles"] as? [String],
            let lastIcon = iconFiles.last {
            return UIImage(named: lastIcon)
        }
        return nil
    }
}

/// A View controller for setting a custom icon.
class CustomIconTableViewController: UITableViewController {
    
    /// A list of icons names.
    var icons = ["Default", "Dark", "Light", "Stripes", "Type"]
    
    // MARK: - Custom icon table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Fix localized string for the text view
        if let tv = tableView.tableFooterView as? UITextView, let ident = tv.restorationIdentifier {
            tv.text = NSLocalizedString("\(ident).text", tableName: "Settings", comment: "")
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidLoad()
        
        tableView.reloadData()
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return icons.count+1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return section+1 == numberOfSections(in: tableView) ? 0 : 1
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "icon") ?? UITableViewCell(style: .default, reuseIdentifier: nil)
        cell.textLabel?.text = icons[indexPath.section]
        if UIApplication.shared.alternateIconName == icons[indexPath.section] || UIApplication.shared.alternateIconName == nil && icons[indexPath.section] == "Default" {
            cell.accessoryType = .checkmark
        } else if (icons[indexPath.section] == "Dark" || icons[indexPath.section] == "Light") && icons.contains("Default") {
            cell.accessoryType = .disclosureIndicator
        } else {
            cell.accessoryType = .none
        }
        
        let icon = icons[indexPath.section] == "Default" ? Bundle.main.icon : UIImage(named: icons[indexPath.section])
        cell.imageView?.image = icon
        cell.imageView?.layer.cornerRadius = 16
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 60
    }
    
    override func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 5
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        let name: String?
        if icons[indexPath.section] == "Default" {
            name = nil
        } else {
            name = icons[indexPath.section]
        }
        
        let vc = storyboard?.instantiateViewController(withIdentifier: "icon") as? CustomIconTableViewController
        var present = false
        if name == "Dark" && icons.contains("Default") {
            vc?.icons = ["Dark", "Dark 2", "Dark 3", "Dark 4", "Dark 5", "Dark 6", "Dark 7"]
            present = true
        } else if name == "Light" && icons.contains("Default") {
            vc?.icons = ["Light", "Light 2", "Light 3", "Light 4", "Light 5", "Light 6"]
            present = true
        }
        if present, let vc = vc {
            navigationController?.pushViewController(vc, animated: true)
            return
        }
        
        UIApplication.shared.setAlternateIconName(name, completionHandler: { error in
            print(error?.localizedDescription ?? "No error")
        })
        
        tableView.reloadData()
    }
}
