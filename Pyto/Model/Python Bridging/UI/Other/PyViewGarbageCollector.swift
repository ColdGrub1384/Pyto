//
//  PyViewGarbageCollector.swift
//  Pyto
//
//  Created by Emma Labbé on 26-03-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import Foundation

fileprivate func randomString(length: Int) -> String {
    let letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    return String((0..<length).map{ _ in letters.randomElement()! })
}


@objc class PyViewGarbageCollector: NSObject {
        
    @objc static func setCollectedItems(_ items: NSArray) {
        
        for item in (items as? [NSObject]) ?? [] {
            DispatchQueue.global().sync {
                Thread.current.name = randomString(length: 10)
                //Python.shared.ignoredCrashOnThreads.append(Thread.current)
                if item.responds(to: NSSelectorFromString("releaseReference")) {
                    item.perform(NSSelectorFromString("releaseReference"))
                }
                item.perform(NSSelectorFromString("release"))
            }
        }
    }
}
