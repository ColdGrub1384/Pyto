//
//  ScriptSettingsViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 13-04-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import UIKit
import IntentsUI

/// A View controller for scripts settings.
class ScriptSettingsViewController: UIViewController, UITextFieldDelegate, UIDocumentPickerDelegate, INUIAddVoiceShortcutButtonDelegate, INUIAddVoiceShortcutViewControllerDelegate, INUIEditVoiceShortcutViewControllerDelegate {
    
    /// The text field for setting arguments.
    @IBOutlet weak var argumentsTextField: UITextField!
    
    /// The text field for setting current directory.
    @IBOutlet weak var currentDirectoryTextField: UITextField!
    
    /// The status of the current directory.
    @IBOutlet weak var currentDirectoryStatusLabel: UILabel!
    
    /// The view containing the Add to Siri button.
    @IBOutlet weak var siriButtonContainerView: UIView!
    
    /// Closes the View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    /// The editor that presented this vc.
    var editor: EditorViewController!
    
    // MARK: - Text field delegate
    
    func textFieldShouldBeginEditing(_ textField: UITextField) -> Bool {
        if textField == currentDirectoryTextField {
            
            let picker = UIDocumentPickerViewController(documentTypes: ["public.folder"], in: .open)
            picker.delegate = self
            if #available(iOS 13.0, *) {
                picker.directoryURL = editor.currentDirectory
            } else {
                picker.allowsMultipleSelection = true
            }
            present(picker, animated: true, completion: nil)
            
            return false
        } else {
            return true
        }
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        if textField == argumentsTextField {
            editor.args = textField.text ?? ""
        }
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        argumentsTextField.text = editor.args
        currentDirectoryTextField.text = FileManager.default.displayName(atPath: editor.currentDirectory.path)
        
        if FileManager.default.isReadableFile(atPath: editor.currentDirectory.path) {
            currentDirectoryStatusLabel.text = Localizable.CouldNotAccessScriptAlert.readable
            currentDirectoryStatusLabel.textColor = .systemGreen
        } else {
            currentDirectoryStatusLabel.textColor = .systemRed
        }
        
        title = FileManager.default.displayName(atPath: editor.document!.fileURL.path)
        
        if let url = editor.document?.fileURL, !isiOSAppOnMac {
            
            (UIApplication.shared.delegate as? AppDelegate)?.addURLToShortcuts(url)
            
            let button: INUIAddVoiceShortcutButton
            
            if #available(iOS 13.0, *) {
                button = INUIAddVoiceShortcutButton(style: .automatic)
            } else {
                button = INUIAddVoiceShortcutButton(style: .whiteOutline)
            }
            
            if #available(iOS 13.0, *) {
                let intent = editor.runScriptIntent
                intent.suggestedInvocationPhrase = url.deletingPathExtension().lastPathComponent
                button.shortcut = INShortcut(intent: intent)
            } else if let activity = editor.userActivity {
                button.shortcut = INShortcut(userActivity: activity)
            }
            button.delegate = self
            
            button.translatesAutoresizingMaskIntoConstraints = false
            
            siriButtonContainerView.addSubview(button)
            
            siriButtonContainerView.addSubview(button)
            siriButtonContainerView.centerXAnchor.constraint(equalTo: button.centerXAnchor).isActive = true
            siriButtonContainerView.centerYAnchor.constraint(equalTo: button.centerYAnchor).isActive = true
        }
    }
    
    // MARK: - Document picker delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        let success = urls.first?.startAccessingSecurityScopedResource()
        
        let url = urls.first ?? editor.currentDirectory
        
        func doChange() {
            editor.currentDirectory = url
            currentDirectoryTextField.text = FileManager.default.displayName(atPath: url.path)
            if !FoldersBrowserViewController.accessibleFolders.contains(editor.currentDirectory.resolvingSymlinksInPath()) {
                FoldersBrowserViewController.accessibleFolders.append(editor.currentDirectory.resolvingSymlinksInPath())
            }
            
            if FileManager.default.isReadableFile(atPath: editor.currentDirectory.path) {
                currentDirectoryStatusLabel.text = Localizable.CouldNotAccessScriptAlert.readable
                currentDirectoryStatusLabel.textColor = .systemGreen
            }
            
            if success == true {
                for item in (parent?.toolbarItems ?? []).enumerated() {
                    if item.element.action == #selector(editor.setCwd(_:)) {
                        parent?.toolbarItems?.remove(at: item.offset)
                        break
                    }
                }
            }
        }
        
        if let file = editor.document?.fileURL,
            url.appendingPathComponent(file.lastPathComponent).resolvingSymlinksInPath() == file.resolvingSymlinksInPath() {
            
            doChange()
        } else {
            
            let alert = UIAlertController(title: Localizable.CouldNotAccessScriptAlert.title, message: Localizable.CouldNotAccessScriptAlert.message, preferredStyle: .alert)
            
            alert.addAction(UIAlertAction(title: Localizable.CouldNotAccessScriptAlert.useAnyway, style: .destructive, handler: { (_) in
                doChange()
            }))
            
            alert.addAction(UIAlertAction(title: Localizable.CouldNotAccessScriptAlert.selectAnotherLocation, style: .default, handler: { (_) in
                let picker = UIDocumentPickerViewController(documentTypes: ["public.folder"], in: .open)
                picker.delegate = self
                if #available(iOS 13.0, *) {
                    picker.directoryURL = self.editor.currentDirectory
                } else {
                    picker.allowsMultipleSelection = true
                }
                self.present(picker, animated: true, completion: nil)
            }))
            
            alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: { (_) in
                urls.first?.stopAccessingSecurityScopedResource()
            }))
            
            present(alert, animated: true, completion: nil)
        }
    }
    
    // MARK: - Add voice shortcut button delegate
    
    func present(_ addVoiceShortcutViewController: INUIAddVoiceShortcutViewController, for addVoiceShortcutButton: INUIAddVoiceShortcutButton) {
        
        addVoiceShortcutViewController.delegate = self
        present(addVoiceShortcutViewController, animated: true, completion: nil)
    }
    
    func present(_ editVoiceShortcutViewController: INUIEditVoiceShortcutViewController, for addVoiceShortcutButton: INUIAddVoiceShortcutButton) {
        
        editVoiceShortcutViewController.delegate = self
        
        present(editVoiceShortcutViewController, animated: true, completion: nil)
    }
    
    // MARK: - Add voice shortcut view controller delegate
    
    func addVoiceShortcutViewController(_ controller: INUIAddVoiceShortcutViewController, didFinishWith voiceShortcut: INVoiceShortcut?, error: Error?) {
        controller.dismiss(animated: true, completion: nil)
    }
    
    func addVoiceShortcutViewControllerDidCancel(_ controller: INUIAddVoiceShortcutViewController) {
        controller.dismiss(animated: true, completion: nil)
    }
    
    // MARK: - Edit voice shortcut view controller delegate
    
    func editVoiceShortcutViewController(_ controller: INUIEditVoiceShortcutViewController, didUpdate voiceShortcut: INVoiceShortcut?, error: Error?) {
        controller.dismiss(animated: true, completion: nil)
    }
    
    func editVoiceShortcutViewController(_ controller: INUIEditVoiceShortcutViewController, didDeleteVoiceShortcutWithIdentifier deletedVoiceShortcutIdentifier: UUID) {
        controller.dismiss(animated: true, completion: nil)
    }
    
    func editVoiceShortcutViewControllerDidCancel(_ controller: INUIEditVoiceShortcutViewController) {
        controller.dismiss(animated: true, completion: nil)
    }
}
