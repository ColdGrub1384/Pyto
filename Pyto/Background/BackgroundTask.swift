//
//  BackgroundTask.swift
//
//  Created by Yaro on 8/27/16.
//  Copyright © 2016 Yaro. All rights reserved.
//

// https://github.com/yarodevuci/backgroundTask

import AVFoundation

@objc class BackgroundTask: NSObject {
    
    static private var count = 0
    
    // MARK: - Vars
    
    var player = AVAudioPlayer()
    var timer = Timer()
    
    // MARK: - Methods
    
    @objc func startBackgroundTask() {
        BackgroundTask.count += 1
        NotificationCenter.default.addObserver(self, selector: #selector(interruptedAudio), name: AVAudioSession.interruptionNotification, object: AVAudioSession.sharedInstance())
        
        if BackgroundTask.count == 1 {
            playAudio()
        }
    }
    
    @objc func stopBackgroundTask() {
        BackgroundTask.count -= 1
        NotificationCenter.default.removeObserver(self, name: AVAudioSession.interruptionNotification, object: nil)
        
        if BackgroundTask.count == 0 {
            player.stop()
        }
    }
    
    @objc fileprivate func interruptedAudio(_ notification: Notification) {
        if notification.name == AVAudioSession.interruptionNotification && notification.userInfo != nil {
            let info = notification.userInfo!
            var intValue = 0
            (info[AVAudioSessionInterruptionTypeKey]! as AnyObject).getValue(&intValue)
            if intValue == 1 { playAudio() }
        }
    }
    
    fileprivate func playAudio() {
        do {
            let bundle = Bundle.main.path(forResource: "blank", ofType: "wav")
            let alertSound = URL(fileURLWithPath: bundle!)
            let session = AVAudioSession.sharedInstance()
            try session.setCategory(.playback, options: .mixWithOthers)
            try session.setActive(true, options: .notifyOthersOnDeactivation)
            try self.player = AVAudioPlayer(contentsOf: alertSound)
            // Play audio forever by setting num of loops to -1
            self.player.numberOfLoops = -1
            self.player.volume = 0.01
            self.player.prepareToPlay()
            self.player.play()
        } catch { print(error.localizedDescription) }
    }
}
