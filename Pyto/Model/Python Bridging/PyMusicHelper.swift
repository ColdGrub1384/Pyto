//
//  PyMusicHelper.swift
//  Pyto
//
//  Created by Adrian Labbé on 16-01-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import MediaPlayer

/// "_MPMusicPlayerMediaItemProxy" has no attribute...
@objc class PyMusicItem: NSObject {
    
    @objc var value: MPMediaItem
    
    @objc init(value: MPMediaItem) {
        self.value = value
    }
    
    @objc var albumArtist: String? {
        return value.albumArtist
    }
    
    @objc var albumArtistPersistentID: MPMediaEntityPersistentID {
        return value.albumArtistPersistentID
    }
    
    @objc var albumPersistentID: MPMediaEntityPersistentID {
        return value.albumPersistentID
    }
    
    @objc var albumTitle: String? {
        return value.albumTitle
    }
    
    @objc var albumTrackCount: Int {
        return value.albumTrackCount
    }
    
    @objc var artist: String? {
        return value.artist
    }
    
    @objc var artistPersistentID: MPMediaEntityPersistentID {
        return value.artistPersistentID
    }
    
    @objc var artwork: MPMediaItemArtwork? {
        return value.artwork
    }
    
    @objc var beatsPerMinute: Int {
        return value.beatsPerMinute
    }
    
    @objc var isCloudItem: Bool {
        return value.isCloudItem
    }
    
    @objc var isCompilation: Bool {
        return value.isCompilation
    }
    
    @objc var composer: String? {
        return value.composer
    }
    
    @objc var composerPersistentID: MPMediaEntityPersistentID {
        return value.composerPersistentID
    }
    
    @objc var dateAdded: Date {
        return value.dateAdded
    }
    
    @objc var discCount: Int {
        return value.discCount
    }
    
    @objc var discNumber: Int {
        return value.discNumber
    }
    
    @objc var isExplicitItem: Bool {
        return value.isExplicitItem
    }
    
    @objc var genre: String? {
        return value.genre
    }
    
    @objc var genrePersistentID: MPMediaEntityPersistentID {
        return value.genrePersistentID
    }
    
    @objc var lastPlayedDate: Date? {
        return value.lastPlayedDate
    }
    
    @objc var lyrics: String? {
        return value.lyrics
    }
    
    @objc var persistentID: MPMediaEntityPersistentID {
        return value.persistentID
    }
    
    @objc var playCount: Int {
        return value.playCount
    }
    
    @objc var playbackDuration: Double {
        return value.playbackDuration
    }
    
    @objc var playbackStoreID: String {
        return value.playbackStoreID
    }
    
    @objc var podcastPersistentID: MPMediaEntityPersistentID {
        return value.podcastPersistentID
    }
    
    @objc var podcastTitle: String? {
        return value.podcastTitle
    }
    
    @objc var hasProtectedAsset: Bool {
        return value.hasProtectedAsset
    }
    
    @objc var rating: Int {
        return value.rating
    }
    
    @objc var releaseDate: Date? {
        return value.releaseDate
    }
    
    @objc var skipCount: Int {
        return value.skipCount
    }
    
    @objc var title: String? {
        return value.title
    }
    
    @objc var userGrouping: String? {
        return value.userGrouping
    }
}

/// A class for helping picking music.
@objc class PyMusicHelper: NSObject {
    
    /// Returns the now playing item.
    @objc static var nowPlayingItem: MPMediaItem? {
        return MPMusicPlayerController.systemMusicPlayer.nowPlayingItem
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
