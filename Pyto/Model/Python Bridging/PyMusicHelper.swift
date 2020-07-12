//
//  PyMusicHelper.swift
//  Pyto
//
//  Created by Adrian Labbé on 16-01-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import MediaPlayer

/// A class for helping picking music.
@objc class PyMusicHelper: NSObject {
    
    /// Returns the now playing item.
    @objc static var nowPlayingItem: MPMediaItem? {
        if let item = MPMusicPlayerController.systemMusicPlayer.nowPlayingItem {
            let query = MPMediaQuery(filterPredicates: [MPMediaPropertyPredicate(value: item.persistentID, forProperty: MPMediaItemPropertyPersistentID)])
            return query.items?.first ?? item
        } else {
            return nil
        }
    }
    
    #if !WIDGET
    /// Picks music.
    ///
    /// - Parameters:
    ///     - scriptPath: The path of the script that called this function.
    ///
    /// - Returns: An array of picked items.
    @objc static func pickMusic(scriptPath: String?) -> NSArray {
        
        class Delegate: NSObject, MPMediaPickerControllerDelegate {
            
            var semaphore: DispatchSemaphore?
            
            var picked = NSMutableArray()
                        
            func mediaPickerDidCancel(_ mediaPicker: MPMediaPickerController) {
                mediaPicker.dismiss(animated: true, completion: {
                    self.semaphore?.signal()
                })
            }
            
            func mediaPicker(_ mediaPicker: MPMediaPickerController, didPickMediaItems mediaItemCollection: MPMediaItemCollection) {
                picked.addObjects(from: mediaItemCollection.items)
            }
        }
        
        if MPMediaLibrary.authorizationStatus() == .denied || MPMediaLibrary.authorizationStatus() == .restricted {
            return [] 
        }
        
        let semaphore = DispatchSemaphore(value: 0)
        let delegate = Delegate()
        delegate.semaphore = semaphore
        
        DispatchQueue.main.async {
            let picker = MPMediaPickerController(mediaTypes: .music)
            picker.delegate = delegate
            
            #if !MAIN
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
        
        semaphore.wait()
        
        return delegate.picked
    }
    #endif
}
