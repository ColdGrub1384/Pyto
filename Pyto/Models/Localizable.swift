//
//  Localizable.swift
//  Pyto
//
//  Created by Adrian Labbe on 10/14/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// Returns a localized string from UIKit with given key.
///
/// - Parameters:
///     - key: The key of the String.
///
/// - Returns: The localized string from UIKit corresponding to the given key.
func UIKitLocalizedString(key: String) -> String {
    return Bundle(for: UIApplication.self).localizedString(forKey: key, value: nil, table: nil)
}

/// A class with an unaccessible initializer.
class Static { private init(){} }

/// A class containing localizable strings.
class Localizable: Static {
    
    /* Title for command for selecting next suggestion */
    static let nextSuggestion = NSLocalizedString("nextSuggestion", comment: "Title for command for selecting next suggestion")
    
    /// Install
    static let install = NSLocalizedString("install", comment: "Install")
    
    /// Button to add script to Siri.
    static let addToSiri = NSLocalizedString("addToSiri", comment: "Button to add script to Siri.")
    
    /// Description for key command for running and setting arguments.
    static let runAndSetArguments = NSLocalizedString("runAndSetArguments", comment: "Description for key command for running and setting arguments.")
    
    /// Description for CTRL+C key command.
    static let interrupt = NSLocalizedString("interrupt", comment: "Description for CTRL+C key command.")
    
    /// 'Close'
    static let close = NSLocalizedString("close", comment: "'Close'")
    
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
    
    /// Action for moving file at current directory
    static let moveHere = NSLocalizedString("moveHere", comment: "Action for moving file at current directory")
    
    /// 'Runtime' button on the editor
    static let runtime = NSLocalizedString("runtime", comment: "'Runtime' button on the editor")
    
    // 'Change'
    static let change = NSLocalizedString("change", comment: "'Change'")
    
    /// View controller simulating a widget on the Notification Center.
    class WidgetSimulator: Static {

        /// The message of the alert displayed when a widget script is set
        static let alertMessage = NSLocalizedString("widget.alertMessage", comment: "Title of the button for collapsing a widget.")
        
        /// The title of the alert displayed when a widget script is set
        static let alertTitle = NSLocalizedString("widget.alertTitle", comment: "The message of the alert displayed when a widget script is set")
        
        /// Title of the button for collapsing a widget.
        static let showLess = NSLocalizedString("widget.showLess", comment: "Title of the button for collapsing a widget.")
        
        /// Title of the button for expanding a widget.
        static let showMore = NSLocalizedString("widget.showMore", comment: "Title of the button for expanding a widget.")
    }
    
    /// Alert for setting current directory.
    class CurrentDirectoryAlert: Static {
        
        /// Message of the alert for setting current directory
        static let message = NSLocalizedString("directoryAlert.message", comment: "Message of the alert for setting current directory")
        
        /// Title of the alert for setting current directory
        static let title = NSLocalizedString("directoryAlert.title", comment: "Title of the alert for current directory")
        
        /// Message shown after the path of a directory that is not readable in the alert for setting the current directory
        static let notReadable = NSLocalizedString("directoryAlert.notReadable", comment: "Message shown after the path of a directory that is not readable in the alert for setting the current directory")
        
        /// Message shown after the path of a directory that is readable in the alert for setting the current directory
        static let readable = NSLocalizedString("directoryAlert.readable", comment: "Message shown after the path of a directory that is readable in the alert for setting the current directory")
    }
    
    /// Strings used by `EditorActionsTableViewController`.
    class EditorActionsTableViewController: Static {
        
        /// The title of the view controller for managing editor actions.
        static let title = NSLocalizedString("editorActionsTableViewController.title", comment: "The title of the view controller for managing editor actions.")
        
        /// The title of the alert for adding an editor action.
        static let createEditorActionAlertTitle = NSLocalizedString("editorActionsTableViewController.createEditorActionAlertTitle", comment: "The title of the alert for adding an editor action.")
        
        /// The message of the alert for adding an editor action.
        static let createEditorActionAlertMessage = NSLocalizedString("editorActionsTableViewController.createEditorActionAlertMessage", comment: "The message of the alert for adding an editor action.")
    }
    
    /// Strings used in the View controller that displays loaded modules.
    class ModulesTableViewController: Static {
        
        /// The subtitle of the view controller for displaying modules
        static let subtitle = NSLocalizedString("modulesTableViewController.subtitle", comment: "The subtitle of the view controller for displaying modules")
        
        /// The title of the view controller for displaying modules
        static let title = NSLocalizedString("modulesTableViewController.title", comment: "The title of the view controller for displaying modules")
    }
    
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
        
        /// The text shown for previewing a folder
        static func numberOfFiles(_ countOfFiles: Int) -> String {
            if countOfFiles > 1 {
                return String(format: NSLocalizedString("numberOfFiles", comment: "The text shown when a folder has subdirectories but no files"), countOfFiles)
            } else if countOfFiles == 0 {
                return noFiles
            } else {
                return NSLocalizedString("oneFile", comment: "1 file")
            }
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
        
        /// 'Theme' button
        static let theme = NSLocalizedString("help.theme", comment: "'Theme' button")
    }
    
    /// Strings for errors.
    class Errors: Static {
        
        /// The title of the alert shown when a widget is set
        static let errorSettingWidget = NSLocalizedString("errors.errorSettingWidget", comment: "The title of the alert shown when a widget is set")
        
        /// The title of alerts shown when an error occurred while creating a file
        static let errorCreatingFile = NSLocalizedString("errors.errorCreatingFile", comment: "The title of alerts shown when an error occurred while creating a file")
        
        /// The title of alerts shown when an error occurred while creating a folder
        static let errorCreatingFolder = NSLocalizedString("errors.errorCreatingFolder", comment: "The title of alerts shown when an error occurred while creating a folder")
        
        /// Title of the alert shown when an error occurred while moving a file
        static let errorMovingFile = NSLocalizedString("errors.errorMovingFile", comment: "Title of the alert shown when an error occurred while moving a file")
        
        /// Title of the alert shown when an error occurred while removing a file
        static let errorRemovingFile = NSLocalizedString("errors.errorRemovingFile", comment: "Title of the alert shown when an error occurred while removing a file")
        
        /// Title of the alert shown when an error occurred while renaming a file
        static let errorRenamingFile = NSLocalizedString("errors.errorRenamingFile", comment: "Title of the alert shown when an error occurred while renaming a file")
        
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
        static let createFileTitle = NSLocalizedString("creation.createFileTitle", comment: "The title of the button shown for creating a file")
        
        /// The title of the button for creating a markdown file
        static let createMarkdown = NSLocalizedString("creation.createMarkdown", comment: "The title of the button for creating a markdown file")
        
        /// The title of the button for creating a script
        static let createScript = NSLocalizedString("creation.createScript", comment: "The title of the button for creating a script")
        
        /// The message of the alert shown for creating a script
        static let typeScriptName = NSLocalizedString("creation.typeScriptName", comment: "The message of the alert shown for creating a script")
        
        /// The title of the alert shown for creating a folder
        static let createFolder = NSLocalizedString("creation.createFolder", comment: "The title of the alert shown for creating a folder")
        
        /// The title of the button shown for creating a plain text file
        static let createPlainText = NSLocalizedString("creation.createPlainText", comment: "The title of the button shown for creating a plain text file")
        
        /// The placeholder of the text field for typing file extension
        static let fileExtension = NSLocalizedString("creation.extension", comment: "The placeholder of the text field for typing file extension")
        
        /// The placeholder of the text field for typing file name
        static let fileName = NSLocalizedString("creation.name", comment: "The placeholder of the text field for typing file name")
        
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
        
        /// The 'Undo' menu item
        static let undo = NSLocalizedString("menuItems.undo", comment: "The 'Undo' menu item")
        
        /// The 'Redo' menu item
        static let redo = NSLocalizedString("menuItems.redo", comment: "The 'Redo' menu item")
        
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
        
        /// The menu item for setting breakpoint
        static let breakpoint = NSLocalizedString("menuItems.breakpoint", comment: "The menu item for setting breakpoint")
        
        /// The menu item for setting breakpoint
        static let toggleComment = NSLocalizedString("menuItems.toggleComment", comment: "The 'Toggle Comment' menu item")        
    }
}
