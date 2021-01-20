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
    
    /// Add
    static let add = NSLocalizedString("add", comment: "Add")
    
    /// Error
    static let error = NSLocalizedString("error", comment: "Error")
    
    /// Untitled file name
    static let untitled = NSLocalizedString("untitled", comment: "Untitled")
    
    /// 'Unindent' key command
    static let unindent = NSLocalizedString("unindent", comment: "'Unindent' key command")
    
    /// Title for command for selecting next suggestion
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
    
    /// 'Change'
    static let change = NSLocalizedString("change", comment: "'Change'")
    
    /// 'Replace'
    static let replace = NSLocalizedString("replace", comment: "'Replace'")
    
    /// 'Find'
    static let find = NSLocalizedString("find", comment: "'Find'")
    
    /// The title of the notification shown when the free trial expired
    static let trialExpiredTitle = NSLocalizedString("freetrial.expired.title", comment: "The title of the notification shown when the free trial expired")
    
    /// The body of the notification shown when the free trial expired
    static let trialExpiredMessage = NSLocalizedString("freetrial.expired.message", comment: "The body of the notification shown when the free trial expired")
    
    /// Title of the menu bar item to install the Automator action
    static let installAutomatorAction = NSLocalizedString("automator.install", comment: "Title of the menu bar item to install the Automator action")
    
    /// Strings used in the projects browser.
    class ProjectsBrowser: Static {
        
        /// 'Projects'
        static let title = NSLocalizedString("projectsBrowser.title", comment: "'Projects'")
        
        /// 'Open'
        static let open = NSLocalizedString("projectsBrowser.open", comment: "'Open'")
        
        /// 'Recent'
        static let recent = NSLocalizedString("projectsBrowser.recent", comment: "'Recent'")
    }
    
    /// Strings used when setting input suggestions for Watch.
    class WatchInputSuggestions: Static {
        
        /// The title of the alert for adding a new suggestion
        static let title = NSLocalizedString("watchInputSuggestions.title", comment: "The title of the alert for adding a new suggestion")
        
        /// The message of the alert for adding a new suggestion
        static let message = NSLocalizedString("watchInputSuggestions.message", comment: "The message of the alert for adding a new suggestion")
    }
    
    /// Strings used by the PyPi installer.
    class PyPi: Static {

        /// Select a version
        static let selectVersion = NSLocalizedString("pypi.selectVersion", comment: "Select a version")
        
        /// The placeholder of the search bar
        static let searchBarPlaceholder = NSLocalizedString("pypi.searchBarPlaceholder", comment: "The placeholder of the search bar")
        
        /// The title of the 'Requirements' section
        static let requirements = NSLocalizedString("pypi.requirements", comment: "The title of the 'Requirements' section")
        
        /// The title of the 'Project' section
        static let project = NSLocalizedString("pypi.project", comment: "The title of the 'Project' section")
        
        /// The title of the 'Links' section
        static let links = NSLocalizedString("pypi.links", comment: "The title of the 'Links' section")
        
        /// Version
        static let version = NSLocalizedString("pypi.version", comment: "Version")
        
        /// Author
        static let author = NSLocalizedString("pypi.author", comment: "Author")
        
        /// Maintainer
        static let maintainer = NSLocalizedString("pypi.maintainer", comment: "Maintainer")
        
        /// Package not found
        static let packageNotFound = NSLocalizedString("pypi.packageNotFound", comment: "Package not found")
        
        /// Library is provided by Pyto
        static let providedByPyto = NSLocalizedString("pypi.providedByPyto", comment: "Library is provided by Pyto")
        
        /// Remove (package)
        static func remove(package: String) -> String {
            return NSString(format: NSLocalizedString("pypi.remove", comment: "Remove (package)") as NSString, package) as String
        }
        
        /// Install (package)
        static func install(package: String) -> String {
            return NSString(format: NSLocalizedString("pypi.install", comment: "Install (package)") as NSString, package) as String
        }
    }
    
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
    
    /// Alert shown when setting a current directory not containing the script.
    class CouldNotAccessScriptAlert: Static {
        
        /// Title of the alert shown when setting a current directory not containing the script
        static let title = NSLocalizedString("couldNotAccessScriptAlert.title", comment: "Title of the alert shown when setting a current directory not containing the script")
        
        /// Message of the alert shown when setting a current directory not containing the script
        static let message = NSLocalizedString("couldNotAccessScriptAlert.message", comment: "Message of the alert shown when setting a current directory not containing the script")
        
        /// Use anyway
        static let useAnyway = NSLocalizedString("couldNotAccessScriptAlert.useAnyway", comment: "Use anyway")
        
        /// Select another location
        static let selectAnotherLocation = NSLocalizedString("couldNotAccessScriptAlert.selectAnotherLocation", comment: "Select another location")
        
        /// The current directory is readable
        static let readable = NSLocalizedString("couldNotAccessScriptAlert.readable", comment: "The current directory is readable")
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
        
        /// An error message shown in the Watch when a script is not set
        static let noWatchScript = NSLocalizedString("errors.noWatchScript", comment: "An error message shown in the Watch when a script is not set")
    }
    
    /// Strings used in creating dialogs.
    class Creation: Static {
        
        /// The title of the alert shown for creating a script
        static let createScriptTitle = NSLocalizedString("creation.createScriptTitle", comment: "The title of the button shown for creating a script")
        
        /// The title of the alert shown for creating a file
        static let createFileTitle = NSLocalizedString("creation.createFileTitle", comment: "The title of the button shown for creating a file")
        
        /// The title of the alert shown for creating a folder
        static let createFolderTitle = NSLocalizedString("creation.createFolderTitle", comment: "The title of the button shown for creating a folder")
        
        /// The message of the alert shown for creating a file
        static let typeFileName = NSLocalizedString("creation.typeFileName", comment: "The message of the alert shown for creating a file")
        
        /// The message of the alert shown for creating a folder
        static let typeFolderName = NSLocalizedString("creation.typeFolderName", comment: "The message of the alert shown for creating a folder")
        
        /// A Python script
        static let pythonScript =  NSLocalizedString("creation.pythonScript", comment: "A Python script")
        
        /// A blank file
        static let blankFile =  NSLocalizedString("creation.blankFile", comment: "A blank file")
        
        /// A folder
        static let folder =  NSLocalizedString("creation.folder", comment: "A folder")
        
        /// Import from Files
        static let importFromFiles = NSLocalizedString("creation.importFromFiles", comment: "Import from Files")
    }
    
    /// Strings used by the `Python` class.
    class Python: Static {
        
        /// A message shown in the console while downloading a module (Downloading module 100%)
        static func downloading(module: String, completedPercentage: Int) -> String {
            return NSString(format: NSLocalizedString("python.downloadingModule", comment: "A message shown in the console while downloading a module (Downloading module 100%)") as NSString, module, "\(completedPercentage)%") as String
        }
        
        /// A notification sent to remind that a script is running in background
        static func isRunning(script: String, since time: String) -> String {
            return NSString(format: NSLocalizedString("python.isRunningScript", comment: "A notification sent to remind that a script is running in background") as NSString, script, time) as String
        }
        
        /// The alert shown when a module is being downloaded for the first time
        class DownloadingModuleAlert: Static {
            
            /// I understand
            static let iUnderstand = NSLocalizedString("python.downloadingModuleAlert.iUnderstand", comment: "I understand")
            
            /// The message of the alert shown when a module is being downloaded for the first time
            static func explaination(module: String) -> String {
                return NSString(format: NSLocalizedString("python.downloadingModuleAlert.explaination", comment: "The message of the alert shown when a module is being downloaded for the first time") as NSString, module) as String
            }
        }
    }
    
    /// Titles of items used in menu controllers, key commands or context menus.
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
        
        /// The menu item to share a file
        static let share = NSLocalizedString("menuItems.share", comment: "The menu item to share a file")
               
        /// The menu item to save a file to Files
        static let saveToFiles = NSLocalizedString("menuItems.saveToFiles", comment: "The menu item to save a file to Files")
    }
}
