//
//  Localizable.swift
//  Pyto
//
//  Created by Adrian Labbe on 10/14/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class with an unaccessible initializer.
class Static { private init(){} }

/// A class containing localizable strings.
class Localizable: Static {
    
    /// 'Ok' button
    static let ok = NSLocalizedString("ok", comment: "'Ok' button")
    
    /// 'Cancel' button
    static let cancel = NSLocalizedString("cancel", comment: "'Cancel' button")
    
    /// 'Create' button
    static let create = NSLocalizedString("create", comment: "'Create' button")
    
    /// 'Console' tab
    static let console = NSLocalizedString("console", comment: "'Console' tab")
    
    /// 'REPL' tab
    static let repl = NSLocalizedString("repl", comment: "'REPL' tab")
    
    /// Strings for the alert for setting arguments.
    class ArgumentsAlert: Static {
        
        /// Message of the alert for setting arguments
        static let message = NSLocalizedString("argumentsAlert.message", comment: "Message of the alert for setting arguments")
        
        /// Title of the alert for setting arguments
        static let title = NSLocalizedString("argumentsAlert.title", comment: "Title of the alert for setting arguments")
    }
    
    /// Strings shown in the folder views.
    class Folders: Static {
        
        /// The text shown when a folder is empty
        static let noFiles = NSLocalizedString("noFiles", comment: "The text shown when a folder is empty")
        
        /// The text shown when a folder has subdirectories but no files
        static func noFilesButDirs(countOfDirs: Int) -> String {
            return String(format: NSLocalizedString("noFilesButDirs", comment: "The text shown when a folder has subdirectories but no files"), countOfDirs)
        }
    }
    
    /// Strings used by the dialog for renaming a file.
    class Renaming: Static {
        
        // "Please type the new file's name."
        
        /// Title of the alert shown for renaming a file
        static let title = NSLocalizedString("renaming.title", comment: "Title of the alert shown for renaming a file")
        
        /// Message of the alert shown for renaming a file
        static let message = NSLocalizedString("renaming.message", comment: "Message of the alert shown for renaming a file")
        
        /// 'Rename' button
        static let rename = NSLocalizedString("renaming.rename", comment: "'Rename' button")
    }
    
    /// Strings used in the help menu.
    class Help: Static {
        
        /// 'Help' button
        static let help = NSLocalizedString("help.help", comment: "'Help' button")
        
        /// 'Documentation' button
        static let documentation = NSLocalizedString("help.documentation", comment: "'Documentation' button")
        
        /// 'Samples' button
        static let samples = NSLocalizedString("help.samples", comment: "'Samples' button")
        
        /// The message of the alert for selecting a sample
        static let selectSample = NSLocalizedString("help.selectSample", comment: "The message of the alert for selecting a sample")
        
        /// 'Acknowledgments' button
        static let acknowledgments = NSLocalizedString("help.licenses", comment: "'Acknowledgments' button")
        
        /// 'Source code' button
        static let sourceCode = NSLocalizedString("help.sourceCode", comment: "'Source code' button")
    }
    
    /// Strings for errors.
    class Errors: Static {
        
        /// The title of alerts shown when an error occurred while creating a file
        static let errorCreatingFile = NSLocalizedString("errors.errorCreatingFile", comment: "The title of alerts shown when an error occurred while creating a file")
        
        /// The title of alerts shown when an error occurred while creating a folder
        static let errorCreatingFolder = NSLocalizedString("errors.errorCreatingFolder", comment: "The title of alerts shown when an error occurred while creating a folder")
        
        /// Title of the alert shown when an error occurred while moving a file
        static let errorMovingFile = NSLocalizedString("errors.errorMovingFile", comment: "Title of the alert shown when an error occurred while moving a file")
        
        /// Title of the alert shown when an error occurred while removing a file
        static let errorRemovingFile = NSLocalizedString("errors.errorRemovingFile", comment: "Title of the alert shown when an error occurred while removing a file")
        
        /// Title of the alert shown when an error occurred while renaming a file
        static let errorRenamingFile = NSLocalizedString("errors.errorRenamingFIle", comment: "Title of the alert shown when an error occurred while renaming a file")
        
        /// Message shown when the user typed an empty name
        static let emptyName = NSLocalizedString("errors.emptyName", comment: "Message shown when the user typed an empty name")
        
        /// The title of the alert shown when a script cannot be read
        static let errorReadingFile = NSLocalizedString("errors.errorReadingFile", comment: "The title of the alert shown when a script cannot be read")
        
        /// Title of the alert shown when code cannot be written
        static let errorWrittingToScript = NSLocalizedString("errors.errorWrittingToScript", comment: "Title of the alert shown when code cannot be written")
    }
    
    /// Strings used in creating dialogs.
    class Creation: Static {
        
        /// The title of the alert shown for creating a script
        static let createScript = NSLocalizedString("creation.createScript", comment: "The title of the alert shown for creating a script")
        
        /// The message of the alert shown for creating a script
        static let typeScriptName = NSLocalizedString("creation.typeScriptName", comment: "The message of the alert shown for creating a script")
        
        /// The title of the alert shown for creating a folder
        static let createFolder = NSLocalizedString("creation.createFolder", comment: "The title of the alert shown for creating a folder")
        
        /// The message of the alert shown for creating a folder
        static let typeFolderName = NSLocalizedString("creation.typeFolderName", comment: "The message of the alert shown for creating a folder")
    }
    
    /// Strings used by the `Python` class.
    class Python: Static {
                
        /// The message shown when a script is already running when the user tries to run another one
        static let alreadyRunning = NSLocalizedString("py.alreadyRunning", comment: "The message shown when a script is already running when the user tries to run another one")
        
        /// Message shown if Startup.py failed to load
        static let errorLoadingStartup = NSLocalizedString("py.startupError", comment: "Message shown if Startup.py failed to load")
    }
    
    /// Strings for handling Objective-C exceptions.
    class ObjectiveC: Static {
        
        /// Message explaining that an Objective-C exception occurred. Takes 2 arguments: The exception name and the reason
        static let exception = NSLocalizedString("objc.exception", comment: "Message explaining that an Objective-C exception occurred. Takes 2 arguments: The exception name and the reason")
        
        /// A message telling the user to press enter to quit Pyto
        static let quit = NSLocalizedString("objc.quit", comment: "A message telling the user to press enter to quit Pyto")
        
        /// The message shown when a script is already running when the user tries to run another one
        static let alreadyRunning = NSLocalizedString("py.alreadyRunning", comment: "The message shown when a script is already running when the user tries to run another one")
    }
    
    /// Strings for the alert promoting Pisth.
    class Pisth: Static {
        
        /// Pisth app name
        static let title = NSLocalizedString("pisth.title", comment: "Pisth app name")
        
        /// A message for promoting Pisth
        static let message = NSLocalizedString("pisth.message", comment: "A message for promoting Pisth")
        
        /// View Pisth on the App Store
        static let view = NSLocalizedString("pisth.install", comment: "View Pisth on the App Store")
    }
    
    /// Titles of items in `UIMenuController`.
    class MenuItems: Static {
        
        /// The 'Open' menu item
        static let open = NSLocalizedString("menuItems.open", comment: "The 'Open' menu item")
        
        /// The 'Run' menu item
        static let run = NSLocalizedString("menuItems.run", comment: "The 'Run' menu item")
        
        /// The 'Rename' menu item
        static let rename = NSLocalizedString("menuItems.rename", comment: "The 'Rename' menu item")
        
        /// The 'Remove' menu item
        static let remove = NSLocalizedString("menuItems.remove", comment: "The 'Remove' menu item")
        
        /// The 'Copy' menu item
        static let copy = NSLocalizedString("menuItems.copy", comment: "The 'Copy' menu item")
        
        /// The 'Move' menu item
        static let move = NSLocalizedString("menuItems.move", comment: "The 'Move' menu item")
    }
}
