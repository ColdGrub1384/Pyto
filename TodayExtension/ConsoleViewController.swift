//
//  TodayViewController.swift
//  Pyto Widget
//
//  Created by Adrian Labbé on 2/3/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import CoreLocation
import NotificationCenter

fileprivate var isPythonSetup = false

/// View controller with console content on the Today widget.
@objc class ConsoleViewController: UIViewController, NCWidgetProviding, CLLocationManagerDelegate {
    
    /// The visible instance.
    @objc static var visible: ConsoleViewController!
    
    /// Set to `true` to start the script.
    @objc static var startScript = true
    
    /// Set to `true` when a script is running.
    @objc static var isScriptRunning = false {
        didSet {
            DispatchQueue.main.async {
                self.visible.playButton.isEnabled = !self.isScriptRunning
            }
        }
    }
    
    /// The shared location manager.
    static let locationManager = CLLocationManager()
    
    /// The shared directory path to be passed to Python.
    @objc static var sharedDirectoryPath: String?
    
    /// Text view containing the console.
    let textView = UITextView()
    
    /// A button for running script.
    let playButton = UIButton()
    
    /// Adds given text to the text view.
    ///
    /// - Parameters:
    ///     - text: Text to be added.
    @objc func print(_ text: String) {
        Swift.print(text, terminator: "")
        DispatchQueue.main.async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            self.textView.text += text
            self.textView.scrollToBottom()
        }
    }
    
    /// Clears screen.
    @objc func clear() {
        DispatchQueue.main.async { [weak self] in
            self?.textView.text = ""
        }
    }
    
    /// Runs script.
    @objc func run() {
        if ConsoleViewController.isScriptRunning {
            ConsoleViewController.startScript = false
        } else {
            ConsoleViewController.startScript = true
            ConsoleViewController.visible.textView.text = ""
        }
    }
    
    // MARK: - UI Presentation
    
    @available(iOSApplicationExtension 13.0, *)
    private class ViewController: UIViewController {
        
        var pyView: PyView?
        
        override func viewDidLoad() {
            super.viewDidLoad()
            
            edgesForExtendedLayout = []
        }
        
        override func viewDidDisappear(_ animated: Bool) {
            super.viewDidDisappear(animated)
            
            pyView?.isPresented = false
            pyView = nil
        }
        
        override func viewWillAppear(_ animated: Bool) {
            super.viewWillAppear(animated)
            
            view.subviews.first?.frame = view.safeAreaLayoutGuide.layoutFrame
        }
        
        override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
            super.viewWillTransition(to: size, with: coordinator)
            
            coordinator.animate(alongsideTransition: { (_) in
                self.view.subviews.first?.frame.size = size
            }) { (_) in
                self.view.subviews.first?.frame = self.view.safeAreaLayoutGuide.layoutFrame
            }
        }
    }
    
    /// Shows a given view initialized from Python.
    ///
    /// - Parameters:
    ///     - view: The view to present.
    ///     - path: The path of the script that called this method.
    @available(iOS 13.0, *) @objc public static func showView(_ view: Any, onConsoleForPath path: String?) {
        
        (view as? PyView)?.isPresented = true
        
        DispatchQueue.main.async {
            let vc = self.viewController((view as? PyView) ?? PyView(managed: view as! UIView), forConsoleWithPath: path)
            self.showViewController(vc, scriptPath: path, completion: nil)
        }
    }
    
    /// Shows a view controller from Python code.
    ///
    /// - Parameters:
    ///     - viewController: View controller to present.
    ///     - completion: Code called to setup the interface.
    @objc static func showViewController(_ viewController: UIViewController, scriptPath: String? = nil, completion: (() -> Void)?) {
        ConsoleViewController.visible.addChild(viewController)
        viewController.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        viewController.view.frame = ConsoleViewController.visible.view.frame
        ConsoleViewController.visible.textView.isHidden = true
        ConsoleViewController.visible.playButton.isHidden = true
        ConsoleViewController.visible.view.addSubview(viewController.view)
    }
    
    /// Creates a View controller to present
    ///
    /// - Parameters:
    ///     - view: The View to present initialized from Python.
    ///
    /// - Returns: A ready to present View controller.
    @available(iOS 13.0, *) @objc public static func viewController(_ view: PyView, forConsoleWithPath path: String?) -> UIViewController {
        
        let vc = ViewController()
        vc.pyView = view
        view.viewController = vc
        vc.view.addSubview(view.view)
        
        return vc
    }
    
    /// Set to `true` to make the widget able to expand.
    @objc var canBeExpanded = false {
        didSet {
            DispatchQueue.main.async { [weak self] in
                if self?.canBeExpanded == true {
                    self?.extensionContext?.widgetLargestAvailableDisplayMode = .expanded
                } else {
                    self?.extensionContext?.widgetLargestAvailableDisplayMode = .compact
                }
            }
        }
    }
    
    /// The widget's maximum height.
    @objc var maximumHeight: Double = 280 {
        didSet {
            DispatchQueue.main.async {  [weak self] in
                if self?.extensionContext?.widgetActiveDisplayMode == .expanded {
                    self?.preferredContentSize = CGSize(width: 0, height: CGFloat(self?.maximumHeight ?? 0))
                }
            }
        }
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view from its nib.
        
        ConsoleViewController.locationManager.delegate = self
        ConsoleViewController.sharedDirectoryPath = FileManager.default.sharedDirectory?.path
        
        /*if #available(iOSApplicationExtension 13.0, *) {
            let memory = MemoryManager()
            memory.memoryLimitAlmostReached = {
                exit(0)
            }
            memory.startListening()
        }*/
        
        if !isPythonSetup {
            setup_python()
            isPythonSetup = true
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if ConsoleViewController.visible != self {
            ConsoleViewController.visible = self
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        textView.frame = view.safeAreaLayoutGuide.layoutFrame
        textView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        textView.backgroundColor = .clear
        textView.font = UIFont(name: "Menlo", size: 14)
        textView.isEditable = false
        view.addSubview(textView)
        
        if #available(iOSApplicationExtension 13.0, *) {
            playButton.addTarget(self, action: #selector(run), for: .touchUpInside)
            playButton.setImage(UIImage(systemName: "play.fill"), for: .normal)
            playButton.sizeToFit()
            playButton.frame.origin = CGPoint(x: view.safeAreaLayoutGuide.layoutFrame.width-(playButton.frame.width*1.5), y: view.safeAreaLayoutGuide.layoutFrame.height-(playButton.frame.height*1.5))
            playButton.autoresizingMask = [.flexibleTopMargin, .flexibleBottomMargin, .flexibleLeftMargin, .flexibleRightMargin]
            view.addSubview(playButton)
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        exit(0)
    }
    
    // MARK: - Widget providing
    
    func widgetActiveDisplayModeDidChange(_ activeDisplayMode: NCWidgetDisplayMode, withMaximumSize maxSize: CGSize) {
        if activeDisplayMode == .expanded {
            preferredContentSize = CGSize(width: 0, height: CGFloat(maximumHeight))
        } else {
            preferredContentSize = maxSize
        }
    }
    
    func widgetPerformUpdate(completionHandler: (@escaping (NCUpdateResult) -> Void)) {
        // Perform any setup necessary in order to update the view.
        
        // If an error is encountered, use NCUpdateResult.Failed
        // If there's no update required, use NCUpdateResult.NoData
        // If there's an update, use NCUpdateResult.NewData
        
        textView.text = ""
        if !ConsoleViewController.isScriptRunning {
            ConsoleViewController.startScript = true
        } else {
            ConsoleViewController.startScript = false
        }
        
        let main = """
        import traceback

        try:
            import importlib.util
            from time import sleep
            import sys
            from outputredirector import *
            from extensionsimporter import PillowImporter
            import pyto
            import io
            import threading
            import os
            import ssl
            import runpy
        except Exception as e:
            ex_type, ex, tb = sys.exc_info()
            traceback.print_tb(tb)

        os.environ["widget"] = "1"

        # MARK: - SSL
        
        ssl._create_default_https_context = ssl._create_unverified_context

        # MARK: - Output

        def read(text):
            pyto.ConsoleViewController.visible.print(text)
        
        standardOutput = Reader(read)
        standardOutput._buffer = io.BufferedWriter(standardOutput)
        
        standardError = Reader(read)
        standardError._buffer = io.BufferedWriter(standardError)
        
        sys.stdout = standardOutput
        sys.stderr = standardError

        # MARK: - Pillow

        sys.meta_path.insert(0, PillowImporter())
        sys.builtin_module_names += ('__PIL__imaging',)

        # MARK: - Run script

        directory = pyto.ConsoleViewController.sharedDirectoryPath

        script_path = directory+"/main.py"

        try:
            del PillowImporter
            del sys.modules["outputredirector"]
            del io
            del sys.modules["io"]
            del ssl
            del sys.modules["ssl"]
            del standardOutput
            del standardError
        except Exception as e:
            print(e)

        def check_for_code():
            while True:
                if pyto.Python.shared.codeToRun is not None:
                    code = str(pyto.Python.shared.codeToRun)
                    pyto.Python.shared.codeToRun = None
                
                    exec(code)

                sleep(0.2)

        threading.Thread(target=check_for_code).start()

        def run_loop():
            pyto.ConsoleViewController.startScript = False
            
            if "pyto_ui" in sys.modules:
                del sys.modules["pyto_ui"]

            if "_values" in sys.modules:
                del sys.modules["_values"]

            if "ui_constants" in sys.modules:
                del sys.modules["ui_constants"]

            pyto.ConsoleViewController.isScriptRunning = True

            os.chdir(directory)
            if not directory in sys.path:
                sys.path.append(directory)

            try:
                runpy.run_path(str(script_path))
            except FileNotFoundError:
                print("A script can be executed from this widget. To to that, go to Pyto's settings and select a script in 'Today Widget'.")
            except Exception as e:
                print(e.__class__.__name__, e)

            pyto.ConsoleViewController.isScriptRunning = False
            
            while not pyto.ConsoleViewController.startScript:
                sleep(0.2)

            run_loop()
        
        run_loop()

        print("WTF")
        """
        
        if Python.shared.runningScripts.count == 0, let newScriptURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask).first?.appendingPathComponent("main.py") {
            
            do {
                if FileManager.default.fileExists(atPath: newScriptURL.path) {
                    try FileManager.default.removeItem(at: newScriptURL)
                }
                _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: true, block: { (timer) in
                    if FileManager.default.createFile(atPath: newScriptURL.path, contents: main.data(using: .utf8), attributes: nil) {
                        Python.shared.runScriptAt(newScriptURL)
                        timer.invalidate()
                    } // The file may not be created on the lock screen, so we try create the file each 0.5 seconds
                })
            } catch {
                print(error.localizedDescription)
            }
        }
        
        if let bundleID = Bundle.main.bundleIdentifier, let dir = ConsoleViewController.sharedDirectoryPath {
            let scriptExists = FileManager.default.fileExists(atPath: (dir as NSString).appendingPathComponent("main.py"))
            NCWidgetController().setHasContent(scriptExists, forWidgetWithBundleIdentifier: bundleID)
        }
        
        completionHandler(NCUpdateResult.noData)
    }
    
    // MARK: - Location manager delegate
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let location = locations.last else {
            return
        }
        
        PyLocationHelper.altitude = Float(location.altitude)
        PyLocationHelper.longitude = Float(location.coordinate.longitude)
        PyLocationHelper.latitude = Float(location.coordinate.latitude)
    }
}
