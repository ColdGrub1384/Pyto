//
//  InspectorTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/23/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller for inspecting variables.
class InspectorTableViewController: UITableViewController {
    
    /// The hierarchy.
    var hierarchy = [String:Any]() {
        didSet {
            var array = [String]()
            for key in hierarchy.keys {
                array.append(key)
            }
            keys = array.sorted {
                if let i1 = Int($0), let i2 = Int($1) {
                    return i1 < i2
                } else {
                    return $0 < $1
                }
            }
            
            tableView.reloadData()
        }
    }
    
    private var keys = [String]()
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        (navigationController ?? self).dismiss(animated: true, completion: nil)
    }
    
    // MARK: - Table view controller
        
    override func tableView(_ tableView: UITableView, accessoryButtonTappedForRowWith indexPath: IndexPath) {
        
        guard let item = hierarchy[keys[indexPath.row]] else {
            return
        }
        
        let font = UIFont(name: "Menlo", size: 17)
        
        let vc = UIViewController()
        let textView = UITextView()
        vc.view = textView
        
        textView.isEditable = false
        textView.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .identifier)
        textView.font = font
        textView.backgroundColor = .clear
        
        if let str = item as? String {
            textView.text = str
            if (str.hasPrefix("'") && str.hasSuffix("'")) || (str.hasPrefix("\"") && str.hasSuffix("\"")) {
                textView.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .string)
            }
        } else if let dict = item as? [String:Any] {
            var str = ""
            if var name = dict["__name__"] as? String {
                if (name.hasPrefix("'") && name.hasSuffix("'")) || (name.hasPrefix("\"") && name.hasSuffix("\"")) {
                    name.removeFirst()
                    name.removeLast()
                }
                str += name+"\n\n"
            }
            var type = String(describing: dict["__class__"] ?? "")
            if type != "''" && type != "" && type != "" {
                if (type.hasPrefix("'") && type.hasSuffix("'")) || (type.hasPrefix("\"") && type.hasSuffix("\"")) {
                    type.removeFirst()
                    type.removeLast()
                }
                str += type+"\n\n"
            }
            var doc = String(describing: dict["__doc__"] ?? "").replacingOccurrences(of: "\\n", with: "\n").replacingOccurrences(of: "\\'", with: "''")
            if doc.hasPrefix("'") && doc.hasSuffix("'") {
                doc.removeFirst()
                doc.removeLast()
            }
            if doc != "''" && doc != "" {
                str += "\n"+doc+"\n\n"
            }
            
            str += "\(NSDictionary(dictionary: dict))"
            
            textView.text = str
        } else {
            let undescore = "_"
            let method = "method"
            let description = "Description"
            let methodDescription = NSSelectorFromString(undescore+method+description)
            if (item as? NSObject)?.responds(to: methodDescription) == true, let description = (item as? NSObject)?.perform(methodDescription)?.takeUnretainedValue() as? String {
                textView.text += "\(description)"
            } else {
                textView.text = "\(item)"
            }
        }
        
        navigationController?.pushViewController(vc, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        if let childHierarchy = hierarchy[keys[indexPath.row]] as? [String:Any], let inspector = storyboard?.instantiateViewController(withIdentifier: "inspector") as? InspectorTableViewController {
            inspector.hierarchy = childHierarchy
            inspector.title = childHierarchy["__name__"] as? String ?? inspector.title
            navigationController?.pushViewController(inspector, animated: true)
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return keys.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let key = keys[indexPath.row]
        
        var value = (hierarchy[key] as? String) ?? ((hierarchy[key] as? [String:Any])?["__name__"] as? String) ?? String(describing: hierarchy[key] ?? "")
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "variable", for: indexPath)
        cell.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        
        cell.textLabel?.text = key
        cell.detailTextLabel?.text = value.replacingOccurrences(of: "\n", with: "")
        
        cell.textLabel?.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
        if (value.hasPrefix("'") && value.hasSuffix("'")) || (value.hasPrefix("\"") && value.hasSuffix("\"")) {
            if !(hierarchy[key] is String) {
                value.removeFirst()
                value.removeLast()
                cell.detailTextLabel?.text = value.replacingOccurrences(of: "\n", with: "")
                cell.detailTextLabel?.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .identifier)
            } else {
                cell.detailTextLabel?.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .string)
            }
        } else {
            cell.detailTextLabel?.textColor = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .identifier)
        }
        
        if hierarchy[key] is [String:Any] {
            cell.accessoryType = .detailDisclosureButton
        } else {
            cell.accessoryType = .detailButton
        }
        
        return cell
    }
}
