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
    let icons = ["Default", "Dark", "Light", "Stripes", "Type"]
    
    // MARK: - Custom icon table view controller
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return icons.count+1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return section+1 == numberOfSections(in: tableView) ? 0 : 1
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "icon") ?? UITableViewCell(style: .default, reuseIdentifier: nil)
        cell.textLabel?.text = icons[indexPath.section]
        if UIApplication.shared.alternateIconName == icons[indexPath.section] || UIApplication.shared.alternateIconName == nil && indexPath.section == 0 {
            cell.accessoryType = .checkmark
        } else {
            cell.accessoryType = .none
        }
        
        let icon = indexPath.section == 0 ? Bundle.main.icon : UIImage(named: icons[indexPath.section])
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
        
        UIApplication.shared.setAlternateIconName(indexPath.section == 0 ? nil : icons[indexPath.section], completionHandler: { error in
            print(error?.localizedDescription ?? "No error")
        })
        
        tableView.reloadData()
    }
}
