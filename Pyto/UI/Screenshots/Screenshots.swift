//
//  Screenshots.swift
//  Pyto Screenshots
//
//  Created by Emma on 03-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit
import SwiftUI

// MARK: - Screenshot 1

/// Opens the `ClipboardManager` project and the `__init__.py` file. Simulates running the script and code completion.
func openProject(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        let url = Bundle.main.url(forResource: "Temperature Converter", withExtension: nil)!
        sceneDelegate.sidebarSplitViewController?.sidebar?.documentPicker(UIDocumentPickerViewController(forOpeningContentTypes: [.folder]), didPickDocumentsAt: [url])
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
            sceneDelegate.sidebarSplitViewController?.sidebar?.open(url: url.appendingPathComponent("ui.py"))
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                let console = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.console
                let editor = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.editor
                
                let fileBrowser = sceneDelegate.sidebarSplitViewController?.isCollapsed == true ? sceneDelegate.sidebarSplitViewController?.compactFileBrowser : sceneDelegate.sidebarSplitViewController?.fileBrowser
                
                var snapshot = fileBrowser?.dataSource.snapshot(for: .main)
                snapshot?.expand([url.appendingPathComponent("temperature_converter")])
                snapshot?.append([url.appendingPathComponent("temperature_converter/__init__.py"), url.appendingPathComponent("temperature_converter/__main__.py"), url.appendingPathComponent("temperature_converter/ui.py")], to: url.appendingPathComponent("temperature_converter"))
                fileBrowser?.dataSource.apply(snapshot!, to: .main)
                
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    editor?.textView.text = try! String(contentsOf: url.appendingPathComponent("temperature_converter/ui.py"))
                    editor?.textView.becomeFirstResponder()
                    editor?.textView.selectedRange = NSRange(location: 322, length: 0)
                    editor?.textViewDidChangeSelection(editor!.textView)
                    console?.print("""
                    [iOS] Not implemented: TextInput.clear_error()
                    [iOS] Not implemented: TextInput.set_on_lose_focus()
                    [iOS] Not implemented: TextInput.set_on_gain_focus()
                    [iOS] Not implemented: TextInput.clear_error()
                    [iOS] Not implemented: TextInput.set_on_lose_focus()
                    [iOS] Not implemented: TextInput.set_on_gain_focus()
                    
                    """+">>> ")
                    
                    editor?.codeCompletionManager.completions = [""]
                    
                    editor?.codeCompletionManager.docStrings["Label"] = """
                    A text label.

                    Args:
                        text (str): Text of the label.
                        id (str): An identifier for this widget.
                        style (:obj:`Style`): An optional style object. If no style is provided then a new one will be created for the widget.
                        factory (:obj:`module`): A python module that is capable to return a implementation of this class with the same name. (optional; normally not needed)
                    """
                    editor?.codeCompletionManager.selectedIndex = 0
                    editor?.codeCompletionManager.currentWord = "Label"
                    editor?.codeCompletionManager.signatures["Label"] = "Label(text, id=None, style=None, factory=None)"
                    editor?.codeCompletionManager.definition = CodeCompletionManager.Name(module_name: "toga.widgets.label", module_path: "", line: 4)
                    editor?.suggestions = ["Label"]
                    editor?.completions = [""]
                    
                    DispatchQueue.main.asyncAfter(deadline: .now()+12) {
                        semaphore.signal()
                    }
                }
            }
        }
    }
    
    semaphore.wait()
}

// MARK: - Screenshot 2

/// Opens the terminal
func openREPL(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        
        let url = Bundle.main.url(forResource: "Clipboard Manager", withExtension: nil)!
        sceneDelegate.sidebarSplitViewController?.sidebar?.documentPicker(UIDocumentPickerViewController(forOpeningContentTypes: [.folder]), didPickDocumentsAt: [url])
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
            sceneDelegate.sidebarSplitViewController?.sidebar?.open(url: url.appendingPathComponent("__init__.py"))
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                let fileBrowser = sceneDelegate.sidebarSplitViewController?.isCollapsed == true ? sceneDelegate.sidebarSplitViewController?.compactFileBrowser : sceneDelegate.sidebarSplitViewController?.fileBrowser
                
                if UIDevice.current.userInterfaceIdiom == .pad {
                    var snapshot = sceneDelegate.sidebarSplitViewController?.sidebar?.dataSource.snapshot()
                    snapshot?.deleteSections([.workingDirectory])
                    sceneDelegate.sidebarSplitViewController?.sidebar?.dataSource.apply(snapshot!)
                }
                
                var snapshot = fileBrowser?.dataSource.snapshot(for: .main)
                snapshot?.expand([url.appendingPathComponent("clipboard_manager")])
                snapshot?.append([url.appendingPathComponent("clipboard_manager/history"), url.appendingPathComponent("clipboard_manager/__init__.py"), url.appendingPathComponent("clipboard_manager/__main__.py")], to: url.appendingPathComponent("clipboard_manager"))
                fileBrowser?.dataSource.apply(snapshot!, to: .main)
                
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    let replText = previewConsole
                    
                    if sceneDelegate.sidebarSplitViewController?.isCollapsed == true {
                        sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.popToRootViewController(animated: true)
                    }
                    
                    DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                        sceneDelegate.sidebarSplitViewController?.sidebar?.showModuleRunner()
                        DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                            let terminal = (sceneDelegate.sidebarSplitViewController?.sidebar?.moduleRunner?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? RunModuleViewController
                            terminal?.console?.print(replText)
                            
                            terminal?.title = "Clipboard Manager - python - 88x45"
                            
                            DispatchQueue.main.asyncAfter(deadline: .now()+5) {
                                semaphore.signal()
                            }
                        }
                    }
                }
            }
        }

    }
    semaphore.wait()
}

// MARK: - Screenshot 3

/// Opens the debugger.
func openDebuggerExample(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        let mainURL = Bundle.main.url(forResource: "main", withExtension: "py")!
        let breakpoint = try! Breakpoint(url: mainURL, lineno: 3, isEnabled: true)
        BreakpointsStore.set(breakpoints: [breakpoint], for: mainURL)
        
        if sceneDelegate.sidebarSplitViewController?.isCollapsed == false {
            sceneDelegate.sidebarSplitViewController?.preferredDisplayMode = .secondaryOnly
            sceneDelegate.sidebarSplitViewController?.fileBrowserNavVC.popViewController(animated: true)
        }
        
        if sceneDelegate.sidebarSplitViewController?.isCollapsed == true {
            sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.popToRootViewController(animated: true)
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
            sceneDelegate.sidebarSplitViewController?.sidebar?.editor = nil
            sceneDelegate.sidebarSplitViewController?.sidebar?.open(url: mainURL)
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                let editor = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.editor
                editor?.parent?.title = "main"
                
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    editor?.textView.text = try! String(contentsOf: mainURL)
                                        
                    
                    DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                        editor?.showDebugger(filePath: mainURL.path, lineno: 3, tracebackJSON: "{}", id: "r4iue")
                        
                        DispatchQueue.main.asyncAfter(deadline: .now()+5) {
                            semaphore.signal()
                        }
                    }
                }
            }
        }
    }
    
    semaphore.wait()
}

// MARK: - Screenshot 4

/// Opens PyPI and shows the sidebar.
func openPyPI(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        sceneDelegate.sidebarSplitViewController?.showPyPI()        
        if sceneDelegate.sidebarSplitViewController?.isCollapsed == false {
            sceneDelegate.sidebarSplitViewController?.preferredDisplayMode = .twoOverSecondary
        } else {
            sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.popToRootViewController(animated: true)
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
            
            let pypi = PipViewController()
            DispatchQueue.global().async {
                let pyPackage = PyPackage(name: "rich")
                
                DispatchQueue.main.async {
                    
                    pypi.package = pyPackage
                    if let name = pyPackage?.name {
                        pypi.title = name
                    }
                    
                    (sceneDelegate.sidebarSplitViewController?.sidebar?.pypi ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController)?.pushViewController(pypi, animated: true)
                    
                    DispatchQueue.main.asyncAfter(deadline: .now()+4) {
                        semaphore.signal()
                    }
                }
            }
        }
    }
    semaphore.wait()
}

// MARK: - Screenshot 5

/// Shows and simulates running the SciPy panda image example.
func openSciPyExample(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        
        if sceneDelegate.sidebarSplitViewController?.isCollapsed == false {
            sceneDelegate.sidebarSplitViewController?.preferredDisplayMode = .oneBesideSecondary
            sceneDelegate.sidebarSplitViewController?.fileBrowserNavVC.popViewController(animated: true)
        }
        
        let url = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0]
        
        if sceneDelegate.sidebarSplitViewController?.isCollapsed == false {
            sceneDelegate.sidebarSplitViewController?.sidebar?.documentPicker(UIDocumentPickerViewController(forOpeningContentTypes: [.folder]), didPickDocumentsAt: [url])
        } else {
            sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.popToRootViewController(animated: true)
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
            let exampleURL = Bundle.main.url(forResource: "Samples/Matplotlib/surface3d", withExtension: "py")!
            sceneDelegate.sidebarSplitViewController?.sidebar?.editor = nil
            sceneDelegate.sidebarSplitViewController?.sidebar?.open(url: exampleURL)
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                let console = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.console
                let editor = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.editor
                editor?.parent?.title = "surface3d"
                
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    editor?.textView.text = try! String(contentsOf: exampleURL)
                    
                    console?.clear()
                    
                    
                    DispatchQueue.main.asyncAfter(deadline: .now()+2) {
                        console?.display(image: UIImage(contentsOfFile: Bundle.main.path(forResource: "surface3d", ofType: "png")!)!, completionHandler: { _, _ in
                            DispatchQueue.main.asyncAfter(deadline: .now()+4) {
                                semaphore.signal()
                            }
                        })
                    }
                }
                
                console?.movableTextField?.textField.placeholder = ">>> "
            }
        }
    }
    
    semaphore.wait()
}


// MARK: - takeScreenshots

func takeScreenshots(sceneDelegate: SceneDelegate) {
    DispatchQueue.global().async {
        openProject(sceneDelegate: sceneDelegate)
        openREPL(sceneDelegate: sceneDelegate)
        openDebuggerExample(sceneDelegate: sceneDelegate)
        openPyPI(sceneDelegate: sceneDelegate)
        openSciPyExample(sceneDelegate: sceneDelegate)
    }
}
