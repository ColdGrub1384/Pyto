//
//  RuntimeCommunicator.swift
//  Pyto
//
//  Created by Adrian Labbé on 09-10-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import BackgroundTasks

@available(iOS 14.0, *)
class RuntimeCommunicator {
    
    static let runScriptNotificationName = "pyto.runScript" as CFString
    static let isAppRunningNotificationName = "pyto.isAppRunning" as CFString
    
    static let shared = RuntimeCommunicator()
    private init() {
    }
    
    var widgetsToBeReloaded: [String]? {
        get {
            return UserDefaults.shared?.stringArray(forKey: "widgetsToBeReloaded")
        }
        
        set {
            UserDefaults.shared?.setValue(newValue, forKey: "widgetsToBeReloaded")
        }
    }
    
    #if MAIN || WIDGET
    private var isListening = false
    
    private var isAppRunning: Bool {
        get {
            return UserDefaults.shared?.bool(forKey: "isAppRunning") ?? false
        }
        
        set {
            UserDefaults.shared?.setValue(newValue, forKey: "isAppRunning")
        }
    }
    
    let notificationCenter = CFNotificationCenterGetDarwinNotifyCenter()
    
    var isContainerAppRunning: Bool {
        let notificationName = CFNotificationName(RuntimeCommunicator.isAppRunningNotificationName)
        let notificationCenter = CFNotificationCenterGetDarwinNotifyCenter()
        
        isAppRunning = false
        
        CFNotificationCenterPostNotification(notificationCenter, notificationName, nil, nil, true)
        
        var i = 0
        while i <= 5 {
            
            if isAppRunning {
                break
            } else {
                sleep(UInt32(0.5))
            }
            
            i += 1
        }
        
        let isRunning = isAppRunning
        isAppRunning = false
        return isRunning
    }
    
    var passedScript: IntentScript? {
        get {
            guard let data = UserDefaults.shared?.data(forKey: "passedScript") else {
                return nil
            }
            
            do {
                let entry = try JSONDecoder().decode(IntentScript.self, from: data)
                return entry
            } catch {
                print(error.localizedDescription)
                return nil
            }
        }
        
        set {
            do {
                UserDefaults.shared?.setValue(try JSONEncoder().encode(newValue), forKey: "passedScript")
            } catch {
                print(error.localizedDescription)
            }
        }
    }
    
    var scriptEntry: ScriptEntry? {
        get {
            guard let data = UserDefaults.shared?.data(forKey: "passedEntry") else {
                return nil
            }
            
            do {
                let entry = try JSONDecoder().decode(ScriptEntry.self, from: data)
                return entry
            } catch {
                print(error.localizedDescription)
                return nil
            }
        }
        
        set {
            do {
                UserDefaults.shared?.setValue(try JSONEncoder().encode(newValue), forKey: "passedEntry")
            } catch {
                print(error.localizedDescription)
            }
        }
    }
    
    func runScript(entry: IntentScript, completion: @escaping ((ScriptEntry) -> Void)) {
        passedScript = entry
        
        scriptEntry = nil
        
        let notificationName = CFNotificationName(RuntimeCommunicator.runScriptNotificationName)
        CFNotificationCenterPostNotification(notificationCenter, notificationName, nil, nil, true)
        
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.global().async {
            _ = Timer.scheduledTimer(withTimeInterval: 0.2, repeats: true, block: { [weak self] (timer) in
                if let entry = self?.scriptEntry {
                    completion(entry)
                    semaphore.signal()
                    timer.invalidate()
                }
            })
            RunLoop.current.run()
        }
        
        semaphore.wait()
    }
    #endif
    
    private var isRunning = false
    
    #if MAIN
    func listen() {
        
        guard !isListening else {
            return
        }
        
        isListening = true
                
        BackgroundTask().startBackgroundTask()
        
        CFNotificationCenterAddObserver(notificationCenter, nil, { (center: CFNotificationCenter?, observer: UnsafeMutableRawPointer?, name: CFNotificationName?, object: UnsafeRawPointer?, userInfo: CFDictionary?) in
            
            guard let entry = RuntimeCommunicator.shared.passedScript else {
                return
            }
            
            func run() {
                do {
                    var isStale = false
                    let url = try URL(resolvingBookmarkData: entry.bookmarkData, bookmarkDataIsStale: &isStale)
                    
                    var scriptEntry: ScriptEntry?
                                    
                    PyOutputHelper.output = ""
                    
                    func send() {
                        RuntimeCommunicator.shared.scriptEntry = scriptEntry ?? .init(date: Date(), output: PyOutputHelper.output)
                        RuntimeCommunicator.shared.isRunning = false
                    }
                    
                    if let id = entry.widgetID {
                        
                        Python.shared.run(code: "import console; console.__widget_id__ = '\(id)'")
                        
                        DispatchQueue.global().asyncAfter(deadline: .now()+1) {
                            PyWidget.completionHandlers[id] = { entry in
                                scriptEntry = entry
                                send()
                            }
                            
                            Python.shared.run(script: Python.Script(path: url.path, debug: false, runREPL: false))
                        }
                    }
                } catch {
                    print(error.localizedDescription)
                }
            }
            
            if RuntimeCommunicator.shared.isRunning {
                _ = Timer.scheduledTimer(withTimeInterval: 0.2, repeats: true, block: { (timer) in
                    if !RuntimeCommunicator.shared.isRunning {
                        run()
                        timer.invalidate()
                    }
                })
            } else {
                run()
            }
            
        }, RuntimeCommunicator.runScriptNotificationName, nil, CFNotificationSuspensionBehavior.deliverImmediately)
        
        CFNotificationCenterAddObserver(notificationCenter, nil, { (center: CFNotificationCenter?, observer: UnsafeMutableRawPointer?, name: CFNotificationName?, object: UnsafeRawPointer?, userInfo: CFDictionary?) in
            
            RuntimeCommunicator.shared.isAppRunning = true
            
        }, RuntimeCommunicator.isAppRunningNotificationName, nil, CFNotificationSuspensionBehavior.deliverImmediately)
    }
    #endif
}
