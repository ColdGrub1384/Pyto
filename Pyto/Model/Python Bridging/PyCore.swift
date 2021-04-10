//
//  PyCore.swift
//  Pyto
//
//  Created by Emma Labbé on 16-03-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import UIKit

/// Taken from https://marcosantadev.com/swift-arrays-holding-elements-weak-references/
extension NSPointerArray {
    
    @objc func addObject(_ object: AnyObject?) {
        guard let strongObject = object else { return }

        let pointer = Unmanaged.passUnretained(strongObject).toOpaque()
        addPointer(pointer)
    }

    @objc func insertObject(_ object: AnyObject?, at index: Int) {
        guard index < count, let strongObject = object else { return }

        let pointer = Unmanaged.passUnretained(strongObject).toOpaque()
        insertPointer(pointer, at: index)
    }

    @objc func replaceObject(at index: Int, withObject object: AnyObject?) {
        guard index < count, let strongObject = object else { return }

        let pointer = Unmanaged.passUnretained(strongObject).toOpaque()
        replacePointer(at: index, withPointer: pointer)
    }

    @objc func object(at index: Int) -> AnyObject? {
        guard index < count, let pointer = self.pointer(at: index) else { return nil }
        return Unmanaged<AnyObject>.fromOpaque(pointer).takeUnretainedValue()
    }

    @objc func removeObject(at index: Int) {
        guard index < count else { return }

        removePointer(at: index)
    }
}

@objc class PyCore: NSObject {
    
    private static var isScriptExecuted = false
    
    static func runStartupScriptIfNeeded() {
        guard !isScriptExecuted, let _ = startupScript else {
            return
        }
        
        isScriptExecuted = true
        
        func run() {
            Python.shared.run(code: """
            import threading
            try:
                from pyto_core import __py_core__
            except (KeyError, ImportError):
                from time import sleep
                sleep(1)
                from pyto_core import __py_core__

            class Thread(threading.Thread):
            
                plugin_path = None

            script = str(__py_core__.startupScript)

            def run():
                import runpy
                global script

                try:
                    runpy.run_path(script)
                except ImportError:
                    pass

            thread = Thread(target=run)
            thread.plugin_path = script
            thread.start()
            """)
        }
        
        if !Python.shared.isSetup {
            _ = Timer.scheduledTimer(withTimeInterval: 0.3, repeats: true, block: { (timer) in
                if Python.shared.isSetup {
                    timer.invalidate()
                    run()
                }
            })
        } else {
            run()
        }
    }
    
    @objc static var editorViewControllers = NSPointerArray.weakObjects()
    
    @objc static func setTheme(_ data: String) -> Bool {
        
        var value = false
        
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.main.async {
            guard let theme = ThemeFromData(data.data(using: .utf8) ?? Data()) else {
                semaphore.signal()
                return
            }
            
            ConsoleViewController.choosenTheme = theme
            value = true
            
            semaphore.signal()
        }
        
        semaphore.wait()
        return value
    }
    
    @objc static var currentTheme: NSData {
        return NSData(data: ConsoleViewController.choosenTheme.data)
    }
    
    @objc static var themes: NSArray {
        let arr = NSMutableArray()
        
        let semaphore = DispatchSemaphore(value: 0)
        DispatchQueue.main.async {
            for theme in Themes {
                arr.add(NSData(data: theme.value.data))
            }
            semaphore.signal()
        }
        semaphore.wait()
        
        return arr
    }
    
    private static var cachedStartupScript: String {
        
        let url = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent("startupScript.py")
        
        let code = UserDefaults.standard.data(forKey: "startupScriptCode")
        try? code?.write(to: url)
        
        return url.path
    }
    
    @objc static var startupScript: String? {
        get {
            guard let data = UserDefaults.standard.data(forKey: "startupScript") else {
                return nil
            }
            
            var isStale = false
            guard let url = try? URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale) else {
                return cachedStartupScript
            }
            
            _ = url.startAccessingSecurityScopedResource()
            
            if !FileManager.default.fileExists(atPath: url.path) {
                return cachedStartupScript
            }
            
            return url.path
        }
        
        set {
            let url = URL(fileURLWithPath: newValue ?? "")
            UserDefaults.standard.set(try? url.bookmarkData(), forKey: "startupScript")
            UserDefaults.standard.set(try? Data(contentsOf: url), forKey: "startupScriptCode")
        }
    }
}
