//
//  PyPhotosHelper.swift
//  Pyto
//
//  Created by Emma Labbé on 19-01-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import MobileCoreServices

/// A class for accessing the photos library and the camera.
@objc class PyPhotosHelper: NSObject {
    
    private static func pickMedia(_ sourceType: UIImagePickerController.SourceType, scriptPath: String?) -> String? {
        guard UIImagePickerController.isSourceTypeAvailable(.camera) else {
            return nil
        }
        
        class Delegate: NSObject, UINavigationControllerDelegate, UIImagePickerControllerDelegate {
            
            var path: String?
            
            let semaphore = DispatchSemaphore(value: 0)
            
            func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
                
                picker.dismiss(animated: true) {
                    self.path = (info[UIImagePickerController.InfoKey.editedImage] as? UIImage)?.data?.base64EncodedString() ?? (info[UIImagePickerController.InfoKey.originalImage] as? UIImage)?.data?.base64EncodedString()
                    self.semaphore.signal()
                }
            }
            
            func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
                picker.dismiss(animated: true) {
                    self.path = nil
                    self.semaphore.signal()
                }
            }
        }
        
        let delegate = Delegate()
        
        DispatchQueue.main.async {
            let picker = UIImagePickerController()
            picker.delegate = delegate
            picker.allowsEditing = true
            picker.sourceType = sourceType
            picker.mediaTypes = [kUTTypeImage as String]
            
            #if WIDGET
            ConsoleViewController.visible.present(picker, animated: true, completion: nil)
            #elseif !MAIN
            ConsoleViewController.visibles.first?.present(picker, animated: true, completion: nil)
            #else
            for console in ConsoleViewController.visibles {
                
                if scriptPath == nil {
                    (console.presentedViewController ?? console).present(picker, animated: true, completion: nil)
                    break
                }
                
                if console.editorSplitViewController?.editor?.document?.fileURL.path == scriptPath {
                    (console.presentedViewController ?? console).present(picker, animated: true, completion: nil)
                    break
                }
            }
            #endif
        }
        
        delegate.semaphore.wait()
        
        return delegate.path
    }
    
    /// Takes a photo.
    ///
    /// - Parameters:
    ///     - scriptPath: The path of the script that called this function.
    ///
    /// - Returns: A base 64 encoded string representing the data of the image.
    @objc static func takePhoto(scriptPath: String?) -> String? {
        return pickMedia(.camera, scriptPath: scriptPath)
    }
    
    /// Picks a photo.
    ///
    /// - Parameters:
    ///     - scriptPath: The path of the script that called this function.
    ///
    /// - Returns: A base 64 encoded string representing the data of the image.
    @objc static func pickPhoto(scriptPath: String?) -> String? {
        return pickMedia(.photoLibrary, scriptPath: scriptPath)
    }
    
    /// Saves the given image.
    ///
    /// - Parameters:
    ///     - image: The image to save.
    @objc static func saveImage(_ image: UIImage) {
        UIImageWriteToSavedPhotosAlbum(image, nil, nil, nil)
    }
}
