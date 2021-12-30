//
//  Screenshots.swift
//  Pyto Screenshots
//
//  Created by Emma on 03-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit

// MARK: - Screenshot 1

/// Opens the `clipboard_manager` project and the `__init__.py` file. Simulates running the script and code completion.
func openProject(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        let url = Bundle.main.url(forResource: "clipboard_manager", withExtension: nil)!
        sceneDelegate.sidebarSplitViewController?.sidebar?.documentPicker(UIDocumentPickerViewController(forOpeningContentTypes: [.folder]), didPickDocumentsAt: [url])
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
            sceneDelegate.sidebarSplitViewController?.sidebar?.open(url: url.appendingPathComponent("__init__.py"))
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                let console = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.console
                let editor = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.editor
                
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    editor?.textView.text = try! String(contentsOf: url.appendingPathComponent("__init__.py"))
                    console?.print("\nSaved text\n>>> ")
                    
                    DispatchQueue.main.asyncAfter(deadline: .now()+12) {
                        semaphore.signal()
                    }
                }
                
                console?.movableTextField?.textField.placeholder = ">>> "
            }
        }
    }
    
    semaphore.wait()
}

// MARK: - Screenshot 2

/// Opens the REPL and the sidebar.
func openREPL(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        let replText = "Python 3.10.0 (default, Nov 25 2021, 16:45:21) [Clang 13.0.0 (clang-1300.0.29.3)]\nPyto version 17.0 (398) iphonesimulator15.0 27-12-2021 22:17\nType \"help\", \"copyright\", \"credits\" or \"license\" for more information.\nType \"clear()\" to clear the console.\n>>> \u{1B}[38;2;50;109;116mpint\u{1B}[39m(\u{1B}[38;2;196;26;22m\"\u{1B}[39m\u{1B}[38;2;196;26;22mHello World!\u{1B}[39m\u{1B}[38;2;196;26;22m\"\u{1B}[39m)\n\u{1B}[31mTraceback (most recent call last):\n\u{1B}[0m  File \"\u{1B}[33m<console>\u{1B}[0m\", line 1, in \u{1B}[33m<module>\u{1B}[0m\n\u{1B}[31mNameError\u{1B}[0m: name \'pint\' is not defined. Did you mean \'print\'?\n>>> \u{1B}[38;2;50;109;116mprint\u{1B}[39m(\u{1B}[38;2;196;26;22m\"\u{1B}[39m\u{1B}[38;2;196;26;22mHello World!\u{1B}[39m\u{1B}[38;2;196;26;22m\"\u{1B}[39m)\nHello World!\n>>> \u{1B}[38;2;155;35;147;01mimport\u{1B}[39;00m \u{1B}[38;2;50;109;116msys\u{1B}[39m\n>>> \u{1B}[38;2;50;109;116msys\u{1B}[39m\u{1B}[38;2;28;0;207m.\u{1B}[39m\u{1B}[38;2;50;109;116mversion\u{1B}[39m\n\u{1B}[32m\'3.10.0 (default, Nov 25 2021, 16:45:21) [Clang 13.0.0 (clang-1300.0.29.3)]\'\u{1B}[39m\n>>> "
        
        
        if sceneDelegate.sidebarSplitViewController?.isCollapsed == true {
            sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.popToRootViewController(animated: true)
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
            sceneDelegate.sidebarSplitViewController?.showREPL()
            DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                ((sceneDelegate.sidebarSplitViewController?.sidebar?.repl?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.console?.print(replText)
                ((sceneDelegate.sidebarSplitViewController?.sidebar?.repl?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.console?.movableTextField?.textField.placeholder = ">>> "
                let fileBrowserNavVC = (sceneDelegate.sidebarSplitViewController?.isCollapsed == true) ? sceneDelegate.sidebarSplitViewController?.compactFileBrowserNavVC : sceneDelegate.sidebarSplitViewController?.fileBrowserNavVC
                
                let browser = FileBrowserViewController()
                browser.navigationItem.largeTitleDisplayMode = .never
                browser.directory = Bundle.main.url(forResource: "clipboard_manager", withExtension: nil)!.appendingPathComponent("history")
                fileBrowserNavVC?.pushViewController(browser, animated: true)
                
                DispatchQueue.main.asyncAfter(deadline: .now()+4) {
                    semaphore.signal()
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

func openShell(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        sceneDelegate.sidebarSplitViewController?.sidebar?.showModuleRunner()
        DispatchQueue.main.asyncAfter(deadline: .now()+3) {
            semaphore.signal()
        }
    }
    semaphore.wait()
}

// MARK: - Screenshot 5

/// Opens PyPI and shows the sidebar.
func openPyPI(sceneDelegate: SceneDelegate) {
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        sceneDelegate.sidebarSplitViewController?.showPyPI()        
        if sceneDelegate.sidebarSplitViewController?.isCollapsed == false {
            sceneDelegate.sidebarSplitViewController?.preferredDisplayMode = .twoOverSecondary
            sceneDelegate.sidebarSplitViewController?.fileBrowserNavVC.popViewController(animated: true)
        } else {
            sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.popToRootViewController(animated: true)
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
            
            if let pypi = UIStoryboard(name: "Main", bundle: .main).instantiateViewController(withIdentifier: "pypi") as? PipViewController {
                DispatchQueue.global().async {
                    let pyPackage = PyPackage(name: "dropbox")
                    
                    DispatchQueue.main.async {
                        
                        pypi.currentPackage = pyPackage
                        if let name = pyPackage?.name {
                            pypi.title = name
                        }
                        
                        (sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController ??  sceneDelegate.sidebarSplitViewController?.sidebar?.pypi)?.pushViewController(pypi, animated: true)
                        
                        DispatchQueue.main.asyncAfter(deadline: .now()+4) {
                            semaphore.signal()
                        }
                    }
                }
            }
        }
    }
    semaphore.wait()
}

// MARK: - Screenshot 6

/// Simulates showing a traceback
func openTracebackExample(sceneDelegate: SceneDelegate) {
    
    let traceback = try! JSONDecoder().decode(Traceback.self, from: try! Data(contentsOf: Bundle.main.url(forResource: "traceback", withExtension: "json")!))
    
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        let url = Bundle.main.url(forResource: "my_app", withExtension: "py")!
        sceneDelegate.sidebarSplitViewController?.sidebar?.open(url: url)
        DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
            let console = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.console
            let editor = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.editor
            
            
            sceneDelegate.sidebarSplitViewController?.preferredDisplayMode = .secondaryOnly
            
            DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                editor?.textView.text = try! String(contentsOf: url)
                console?.clear()
                console?.print(">>> ")
                editor?.traceback = traceback
                editor?.showTraceback()
                
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    if #available(iOS 15.0, *) {
                        editor?.presentedViewController?.sheetPresentationController?.detents = [.large()]
                    }
                }
                
                DispatchQueue.main.asyncAfter(deadline: .now()+12) {
                    editor?.traceback = nil
                    editor?.dismiss(animated: true, completion: {
                        semaphore.signal()
                    })
                }
            }
            
            console?.movableTextField?.textField.placeholder = ">>> "
        }
    }
    
    semaphore.wait()
}

// MARK: - Screenshot 7

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
            let exampleURL = Bundle.main.url(forResource: "Samples/SciPy/ndimage", withExtension: "py")!
            sceneDelegate.sidebarSplitViewController?.sidebar?.editor = nil
            sceneDelegate.sidebarSplitViewController?.sidebar?.open(url: exampleURL)
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                let console = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.console
                let editor = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.editor
                editor?.parent?.title = "ndimage"
                
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    editor?.textView.text = try! String(contentsOf: exampleURL)
                    
                    console?.clear()
                    
                    
                    DispatchQueue.main.asyncAfter(deadline: .now()+2) {
                        console?.display(image: UIImage(contentsOfFile: Bundle.main.path(forResource: "rotated_panda", ofType: "png")!)!, completionHandler: { _, _ in
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
        openShell(sceneDelegate: sceneDelegate)
        openPyPI(sceneDelegate: sceneDelegate)
        openTracebackExample(sceneDelegate: sceneDelegate)
        openSciPyExample(sceneDelegate: sceneDelegate)
    }
}
