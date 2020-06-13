//
//  BackgroundTask.swift
//
//  Created by Yaro on 8/27/16.
//  Copyright © 2016 Yaro. All rights reserved.
//

// https://github.com/yarodevuci/backgroundTask

import AVFoundation
import UIKit

@objc class BackgroundTask: NSObject {
    
    static private var count = 0
    
    // MARK: - Vars
    
    var player = AVAudioPlayer()
    var timer = Timer()
    var isActive = false
    
    @objc var scriptName = "Script"
    
    @objc var sendNotification = true
    
    @objc var delay: Double = 3600*6 // send a notification every 6 hour
    
    // MARK: - Methods
    
    @objc func startBackgroundTask() {
        
        isActive = true
        
        BackgroundTask.count += 1
        NotificationCenter.default.addObserver(self, selector: #selector(interruptedAudio), name: AVAudioSession.interruptionNotification, object: AVAudioSession.sharedInstance())
        
        if BackgroundTask.count == 1 {
            playAudio()
        }
        
        if sendNotification {
            UNUserNotificationCenter.current().getNotificationSettings { (settings) in
                if settings.authorizationStatus == .notDetermined {
                    UNUserNotificationCenter.current().requestAuthorization(options: [.alert, .sound]) { (_, _) in }
                }
            }
        }
        
        var time = 0
        var i = 0
        let formatter = DateComponentsFormatter()
        formatter.unitsStyle = .abbreviated
        formatter.zeroFormattingBehavior = [.pad]
        DispatchQueue.main.async {
            _ = Timer.scheduledTimer(withTimeInterval: 1, repeats: true, block: { (timer) in
                time += 1
                i += 1
                
                for scene in UIApplication.shared.connectedScenes {
                    if scene.activationState == .foregroundActive || scene.activationState == .foregroundInactive {
                        i = 0
                        break
                    }
                }
                
                if !self.isActive {
                    timer.invalidate()
                    return
                }
                                
                if Double(i) >= self.delay {
                    if time >= 3600*24 { // Running since more than a day
                        formatter.allowedUnits = [.day, .hour]
                    } else if time >= 3600 { // Running since more than an hour
                        formatter.allowedUnits = [.hour, .minute]
                    } else if time >= 60 { // Running since more than a minute
                        formatter.allowedUnits = [.minute, .second]
                    } else {
                        formatter.allowedUnits = [.second]
                    }
                    
                    if self.sendNotification, let str = formatter.string(from: TimeInterval(time)) {
                        PyNotificationCenter.scheduleNotification(title: self.scriptName, message: "\(self.scriptName) is running since \(str)", delay: 1)
                        i = 0
                    }
                }
            })
        }
    }
    
    @objc func stopBackgroundTask() {
        
        isActive = false
        
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
