//
//  ScriptSettingsViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 13-04-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import IntentsUI

class ScriptSettingsViewController: UIViewController, UITextFieldDelegate, UIDocumentPickerDelegate, INUIAddVoiceShortcutButtonDelegate, INUIAddVoiceShortcutViewControllerDelegate, INUIEditVoiceShortcutViewControllerDelegate {
    
    @IBOutlet weak var argumentsTextField: UITextField!
    
    @IBOutlet weak var currentDirectoryTextField: UITextField!
    
    @IBOutlet weak var currentDirectoryStatusLabel: UILabel!
    
    @IBOutlet weak var siriButtonContainerView: UIView!
    
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    var editor: EditorViewController!
    
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
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        argumentsTextField.text = editor.args
        currentDirectoryTextField.text = FileManager.default.displayName(atPath: editor.currentDirectory.path)
        
        title = FileManager.default.displayName(atPath: editor.document!.fileURL.path)
        
        if let activity = editor.userActivity {
            let button: INUIAddVoiceShortcutButton
            if #available(iOS 13.0, *) {
                button = INUIAddVoiceShortcutButton(style: .automatic)
            } else {
                button = INUIAddVoiceShortcutButton(style: .whiteOutline)
            }
            button.shortcut = INShortcut(userActivity: activity)
            button.delegate = self
            button.autoresizingMask = [.flexibleTopMargin, .flexibleBottomMargin, .flexibleLeftMargin, .flexibleRightMargin]
            button.center = siriButtonContainerView.center
            
            siriButtonContainerView.addSubview(button)
        }
    }
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        let success = urls.first?.startAccessingSecurityScopedResource()
        
        let url = urls.first ?? editor.currentDirectory
        
        func doChange() {
            editor.currentDirectory = url
            currentDirectoryTextField.text = FileManager.default.displayName(atPath: editor.currentDirectory.path)
            if !FoldersBrowserViewController.accessibleFolders.contains(editor.currentDirectory.resolvingSymlinksInPath()) {
                FoldersBrowserViewController.accessibleFolders.append(editor.currentDirectory.resolvingSymlinksInPath())
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
            
            let alert = UIAlertController(title: "Couldn't access script", message: "The selected directory doesn't contain this script.", preferredStyle: .alert)
            
            alert.addAction(UIAlertAction(title: "Use anyway", style: .destructive, handler: { (_) in
                doChange()
            }))
            
            alert.addAction(UIAlertAction(title: "Select another location", style: .default, handler: { (_) in
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
        
        dismiss(animated: true) {
            addVoiceShortcutViewController.delegate = self
            self.present(addVoiceShortcutViewController, animated: true, completion: nil)
        }
    }
    
    func present(_ editVoiceShortcutViewController: INUIEditVoiceShortcutViewController, for addVoiceShortcutButton: INUIAddVoiceShortcutButton) {
        
        editVoiceShortcutViewController.delegate = self
        
        dismiss(animated: true) {
            self.present(editVoiceShortcutViewController, animated: true, completion: nil)
        }
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
