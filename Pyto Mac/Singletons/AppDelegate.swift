//
//  AppDelegate.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 1/26/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa
import SourceEditor
import SavannaKit

/// The app's delegate.
@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate, NSMenuDelegate, SyntaxTextViewDelegate {
    
    // MARK: - Menu
    
    /// The menu item for running script.
    @IBOutlet weak var runMenuItem: NSMenuItem!
    
    /// Runs current editing script.
    @IBAction func run(_ sender: Any) {
        (NSApp.keyWindow?.contentViewController as? EditorViewController)?.run(self)
    }
    
    /// The menu item for stopping current running script.
    @IBOutlet weak var stopMenuItem: NSMenuItem!
    
    /// Stops current running script.
    @IBAction func stop(_ sender: Any) {
        Python.shared.isScriptRunning = false
    }
    
    /// Saves current editing document.
    @IBAction func saveDoc(_ sender: Any) {
        (NSApp.keyWindow?.contentViewController as? EditorViewController)?.document?.save(self)
    }
    
    // MARK: - Application delegate
    
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        
        themeMenu.delegate = self
        themeMenu.autoenablesItems = false
        
        runMenuItem.isEnabled = (!Python.shared.isScriptRunning && NSApp.keyWindow?.contentViewController is EditorViewController && !(NSApp.keyWindow?.contentViewController is REPLViewController))
        stopMenuItem.isEnabled = Python.shared.isScriptRunning
        
        // Track dark mode
        
        var view = NSView()
        var isDark = view.isDarkMode
        DispatchQueue.global().async {
            while true {
                if view.isDarkMode != isDark {
                    isDark = !isDark
                    DispatchQueue.main.async {
                        NotificationCenter.default.post(name: NSView.AppearanceDidChangeNotification, object: isDark)
                    }
                }
                DispatchQueue.main.async {
                    view = NSView()
                }
                Thread.sleep(forTimeInterval: 1)
            }
        }
        
        // Setup themes
        
        for (name, theme) in themes {
            let item = NSMenuItem(title: name, action: #selector(setTheme(_:)), keyEquivalent: "")
            item.target = self
            let size = NSSize(width: 300, height: 100)
            
            let textView = SyntaxTextView()
            textView.frame.size = size
            textView.bounds.size = size
            textView.theme = ReadonlyTheme(theme)
            textView.delegate = self
            textView.text = """
            import time
            
            while True:
            print("Hello World!")
            time.sleep(1)
            """
            
            let image = NSImage(data: textView.dataWithPDF(inside: textView.bounds))
            image?.backgroundColor = theme.backgroundColor
            item.image = image
            
            themeItems.append(item)
        }
    }
    
    // MARK: - Themes
    
    /// Available themes.
    let themes: [(name: String,            value: SourceCodeTheme)] = [
                 (name: "Xcode",           value: XcodeSourceCodeTheme()),
                 (name: "Xcode Dark",      value: XcodeDarkSourceCodeTheme()),
                 (name: "Basic",           value: BasicSourceCodeTheme()),
                 (name: "Dusk",            value: DuskSourceCodeTheme()),
                 (name: "Low Key",         value: LowKeySourceCodeTheme()),
                 (name: "Midnight",        value: MidnightSourceCodeTheme()),
                 (name: "Sunset",          value: SunsetSourceCodeTheme()),
                 (name: "WWDC16",          value: WWDC16SourceCodeTheme()),
                 (name: "Cool Glow",       value: CoolGlowSourceCodeTheme()),
                 (name: "Solarized Light", value: SolarizedLightSourceCodeTheme()),
                 (name: "Solarized Dark",  value: SolarizedDarkSourceCodeTheme()),
    ]
    
    /// Menu items for setting theme.
    var themeItems = [NSMenuItem]()
    
    /// The menu for changing theme.
    @IBOutlet weak var themeMenu: NSMenu!
    
    /// Changes theme from menu item.
    @objc func setTheme(_ sender: NSMenuItem) {
        var theme = ChoosenTheme
        for theme_ in themes {
            if theme_.name == sender.title {
                theme = theme_.value
                break
            }
        }
        ChoosenTheme = theme
    }
    
    // MARK: - Menu delegate
    
    func menuWillOpen(_ menu: NSMenu) {
        var items = themeItems
        if NSView().isDarkMode {
            items.removeFirst()
        } else {
            items.remove(at: 1)
        }
        
        for item in items {
            
            var theme = ChoosenTheme
            for theme_ in themes {
                if theme_.name == item.title {
                    theme = theme_.value
                    break
                }
            }
            
            if type(of: theme) == type(of: ChoosenTheme) {
                item.state = .on
            } else {
                item.state = .off
            }
        }
        menu.items = items
    }
    
    // MARK: - Syntax text view delegate
    
    func didChangeText(_ syntaxTextView: SyntaxTextView) {}
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
    func lexerForSource(_ source: String) -> Lexer { return Python3Lexer() }
}

