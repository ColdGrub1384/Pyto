//
//  PySpeech.swift
//  Pyto
//
//  Created by Adrian Labbé on 14-03-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import AVFoundation

@objc class PySpeech: NSObject {

    static var speechSynthesizer = AVSpeechSynthesizer()
    
    @objc static func isSpeaking() -> Bool {
        return speechSynthesizer.isSpeaking
    }
    
    @objc static func wait() {
        while isSpeaking() {
            sleep(UInt32(0.2))
        }
    }
    
    @objc static func availableVoices() -> NSArray {
        let voices = NSMutableArray()
        
        for voice in AVSpeechSynthesisVoice.speechVoices() {
            if !voices.contains(voice.language) {
                voices.add(voice.language)
            }
        }
        
        return voices
    }
    
    @objc static func say(_ text: String, language: String?, rate: Float) {
        
        let speechUtterance: AVSpeechUtterance = AVSpeechUtterance(string: text)
        
        speechUtterance.rate = rate
        
        if let lng = language {
            speechUtterance.voice = AVSpeechSynthesisVoice(language: lng)
        }
                
        speechSynthesizer.speak(speechUtterance)
    }
}
