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

// MARK: - Helpers

/// The directory where pip packages will be installed.
let sitePackagesDirectory = FileManager.default.urls(for: .applicationSupportDirectory, in: .allDomainsMask)[0].appendingPathComponent("site-packages").path

/// The Zip file containing mac specific modules.
let zippedSitePackages = Bundle.main.path(forResource: "mac-site-packages", ofType: "zip")

fileprivate class MenuItem: NSMenuItem {
    
    var value: String?
}

// MARK: - App delegate

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
    
    /// Show pip installer.
    @IBAction func showPip(_ sender: Any) {
        let repl = (NSStoryboard(name: "Main", bundle: nil).instantiateController(withIdentifier: "repl") as? NSWindowController)
        (repl?.contentViewController as? REPLViewController)?.pip = true
        repl?.window?.title = "Installer"
        repl?.showWindow(nil)
    }
    
    // MARK: - Application delegate
    
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        
        setenv("SSL_CERT_FILE", Bundle.main.path(forResource: "cacert", ofType: "pem"), 1)
        
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
            from time import sleep
            
            name = input("What's your name? ")
            print("Hello "+name+"!")
            
            sleep(1)
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
    
    private func themeMenuWillOpen(_ menu: NSMenu) {
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
    
    // MARK: - Python version
    
    /// The menu for choosing Python version.
    @IBOutlet weak var pythonExecutableMenu: NSMenu!
    
    /// Changes the Python executable from a menu item.
    @objc func changePythonExecutable(_ sender: NSMenuItem) {
        if let path = (sender as? MenuItem)?.value {
            Python.shared.pythonExecutable = URL(fileURLWithPath: path)
        }
    }
    
    private func pythonExecutableMenuWillOpen(_ menu: NSMenu) {
        
        var executables = [String : URL]()
        
        let bundledPythonPipe = Pipe()
        let checkForBundledPython = Process()
        checkForBundledPython.environment = [
            "PYTHONHOME" : Bundle.main.resourcePath ?? ""
        ]
        checkForBundledPython.standardError = bundledPythonPipe
        checkForBundledPython.standardOutput = bundledPythonPipe
        checkForBundledPython.executableURL = Python.shared.bundledPythonExecutable
        checkForBundledPython.arguments = ["--version"]
        try? checkForBundledPython.run()
        checkForBundledPython.waitUntilExit()
        
        let bundledPythonVersion = (String(data: bundledPythonPipe.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8) ?? "")+" (Bundled)"
        
        executables[bundledPythonVersion] = Python.shared.bundledPythonExecutable
        
        var systemPythonVersion: String?
        
        var python2BrewVersion: String?
        
        var python3BrewVersion: String?
        
        let systemPythonURL = URL(fileURLWithPath: "/usr/bin/python")
        if FileManager.default.fileExists(atPath: systemPythonURL.path) {
            let systemPythonPipe = Pipe()
            let checkForSystemPython = Process()
            checkForSystemPython.standardOutput = systemPythonPipe
            checkForSystemPython.standardError = systemPythonPipe
            checkForSystemPython.executableURL = URL(fileURLWithPath: "/usr/bin/env")
            checkForSystemPython.arguments = [systemPythonURL.path, "--version"]
            try? checkForSystemPython.run()
            checkForSystemPython.waitUntilExit()
            
            if checkForSystemPython.terminationStatus == 0 {
                systemPythonVersion = (String(data: systemPythonPipe.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8) ?? "")+" (/usr/bin)"
                executables[systemPythonVersion!] = systemPythonURL
            }
        }
        
        // Brew installed Python versions shouldn't work on sandbox, but may be useful if the app is ran as root.
        // Returns "Ilegal Instruction: 4", but if the user finds a way to disable the sandbox... 🤷‍♂️
        // Maybe if the Desktop is ran by root, it would work.
        
        let python2BrewURL = URL(fileURLWithPath: "/usr/local/bin/python2")
        if FileManager.default.fileExists(atPath: python2BrewURL.path) {
            let python2BrewPipe = Pipe()
            let checkForPython2Brew = Process()
            checkForPython2Brew.standardError = python2BrewPipe
            checkForPython2Brew.standardOutput = python2BrewPipe
            checkForPython2Brew.executableURL = URL(fileURLWithPath: "/usr/bin/env")
            checkForPython2Brew.arguments = [python2BrewURL.path, "--version"]
            try? checkForPython2Brew.run()
            checkForPython2Brew.waitUntilExit()
            
            if checkForPython2Brew.terminationStatus == 0 {
                python2BrewVersion = (String(data: python2BrewPipe.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8) ?? "")+" (/usr/local/bin)"
                executables[python2BrewVersion!] = python2BrewURL
            }
        }
        
        let python3BrewURL = URL(fileURLWithPath: "/usr/local/bin/python3")
        if FileManager.default.fileExists(atPath: python3BrewURL.path) {
            let python3BrewPipe = Pipe()
            let checkForPython3Brew = Process()
            checkForPython3Brew.standardError = python3BrewPipe
            checkForPython3Brew.standardOutput = python3BrewPipe
            checkForPython3Brew.executableURL = URL(fileURLWithPath: "/usr/bin/env")
            checkForPython3Brew.arguments = [python3BrewURL.path, "--version"]
            try? checkForPython3Brew.run()
            checkForPython3Brew.waitUntilExit()
            
            if checkForPython3Brew.terminationStatus == 0 {
                python3BrewVersion = (String(data: python3BrewPipe.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8) ?? "")+" (/usr/local/bin)"
                executables[python3BrewVersion!] = python3BrewURL
            }
        }
        
        menu.items = []
        
        for pythonVersion in [bundledPythonVersion, systemPythonVersion, python2BrewVersion, python3BrewVersion] {
            if let version = pythonVersion {
                let menuItem = MenuItem(title: version, action: #selector(changePythonExecutable(_:)), keyEquivalent: "")
                menuItem.target = self
                menuItem.value = executables[version]?.path
                
                if executables[version] == Python.shared.pythonExecutable {
                    menuItem.state = .on
                } else {
                    menuItem.state = .off
                }
                
                menu.items.append(menuItem)
            }
        }
    }
    
    // MARK: - Menu delegate
    
    func menuWillOpen(_ menu: NSMenu) {
        if menu == themeMenu {
            themeMenuWillOpen(menu)
        } else if menu == pythonExecutableMenu {
            pythonExecutableMenuWillOpen(menu)
        }
    }
    
    // MARK: - Syntax text view delegate
    
    func didChangeText(_ syntaxTextView: SyntaxTextView) {}
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
    func lexerForSource(_ source: String) -> Lexer { return Python3Lexer() }
}

