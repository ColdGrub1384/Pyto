//
//  EditorScript.swift
//  Pyto
//
//  Created by Emma Labbé on 5/7/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

/// Some scripts that take scripts as arguments can be executed directly from the code editor. This type represents a script and its argument including the path of the file being edited by the editor.
/// An usage example of this is `2to3` script that acts on a script.
struct EditorScript: Codable, Equatable {
    
    /// Arguments of the script, including the name of the script in `$PATH` and the script being edited (`"$SCRIPT_PATH"`).
    var arguments: [String]
    
    /// Get arguments ready to send to `python -m`.
    ///
    /// - Parameters:
    ///     - scriptURL: The URL of the script being passed to the script.
    func argv(for scriptURL: URL) -> [String] {
        var arguments = [String]()
        
        for arg in self.arguments {
            if arg != "$SCRIPT" {
                arguments.append(arg)
            } else {
                arguments.append("'"+scriptURL.path+"'")
            }
        }
        
        return arguments
    }
    
    /// Creates a Table view cell for this script to be displayed in `EditorActionsTableViewController`.
    ///
    /// - Parameters:
    ///     - scriptURL: The URL of the script being passed to the script.
    ///
    /// - Returns: A ready to use Table view cell with information about this command.
    func tableViewCell(for scriptURL: URL) -> UITableViewCell {
        let cell = UITableViewCell(style: .subtitle, reuseIdentifier: nil)
        
        cell.textLabel?.text = arguments.first ?? ""
        
        var displayedArguments = [String]()
        for arg in self.arguments {
            if arg != "$SCRIPT" {
                displayedArguments.append(arg)
            } else {
                displayedArguments.append("'"+scriptURL.lastPathComponent+"'")
            }
        }
        
        cell.detailTextLabel?.text = displayedArguments.joined(separator: " ")
        
        cell.accessoryType = .disclosureIndicator
        
        return cell
    }
    
    /// Initializes an editor script.
    ///
    /// - Parameters:
    ///     - argv: Arguments of the script, including the name of the script in `$PATH` and the script being edited (`"$SCRIPT_PATH"`).
    init(argv: [String]) {
        arguments = argv
    }
    
    // MARK: - Equatable
    
    
}

/// MARK: - Global constants

/// `2to3` script.
let k2to3Script = EditorScript(argv: ["2to3", "-w", "$SCRIPT"])

/// `black` script.
let kBlackScript = EditorScript(argv: ["black", "$SCRIPT"])
