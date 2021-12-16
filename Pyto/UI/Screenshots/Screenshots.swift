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
                    editor?.textView.becomeFirstResponder()
                    editor?.textView.insertText("    pri")
                    editor?.completions = ["nt"]
                    editor?.suggestions = ["print"]
                    
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
        let replText = "Python 3.10.0 (default, Nov 25 2021, 16:45:21) [Clang 13.0.0 (clang-1300.0.29.3)]\nPyto version 17.0 (393) iphonesimulator15.0 03-12-2021 17:34\nType \"help\", \"copyright\", \"credits\" or \"license\" for more information.\nType \"clear()\" to clear the console.\n>>> pint(\u{1B}[38;2;186;33;33m\"\u{1B}[39m\u{1B}[38;2;186;33;33mHello World!\u{1B}[39m\u{1B}[38;2;186;33;33m\"\u{1B}[39m)\n\u{1B}[31mTraceback (most recent call last):\n\u{1B}[0m  File \"\u{1B}[33m<console>\u{1B}[0m\", line 1, in \u{1B}[33m<module>\u{1B}[0m\n\u{1B}[31mNameError\u{1B}[0m: name \'pint\' is not defined. Did you mean \'print\'?\n>>> \u{1B}[38;2;0;128;0mprint\u{1B}[39m(\u{1B}[38;2;186;33;33m\"\u{1B}[39m\u{1B}[38;2;186;33;33mHello World!\u{1B}[39m\u{1B}[38;2;186;33;33m\"\u{1B}[39m)\nHello World!\n>>> \u{1B}[38;2;0;128;0;01mimport\u{1B}[39;00m \u{1B}[38;2;0;0;255;01msys\u{1B}[39;00m\n>>> sys\u{1B}[38;2;102;102;102m.\u{1B}[39mversion\n\u{1B}[32m\'3.10.0 (default, Nov 25 2021, 16:45:21) [Clang 13.0.0 (clang-1300.0.29.3)]\'\n\u{1B}[39m>>> "
        
        
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

// MARK: - Screenshot 4

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
            sceneDelegate.sidebarSplitViewController?.sidebar?.open(url: exampleURL)
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                let console = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.console
                let editor = ((sceneDelegate.sidebarSplitViewController?.sidebar?.editor?.visibleViewController as? EditorSplitViewController) ?? sceneDelegate.sidebarSplitViewController?.sidebar?.navigationController?.visibleViewController as? EditorSplitViewController)?.editor
                editor?.parent?.title = "ndimage"
                
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    editor?.textView.text = try! String(contentsOf: exampleURL)
                    
                    console?.clear()
                    
                    if sceneDelegate.sidebarSplitViewController?.isCollapsed == true {
                        console?.editorSplitViewController?.showConsole {
                            console?.display(image: UIImage(contentsOfFile: Bundle.main.path(forResource: "rotated_panda", ofType: "png")!)!, completionHandler: { _, _ in
                                DispatchQueue.main.asyncAfter(deadline: .now()+4) {
                                    semaphore.signal()
                                }
                            })
                        }
                    } else {
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
        openPyPI(sceneDelegate: sceneDelegate)
        openSciPyExample(sceneDelegate: sceneDelegate)
    }
}
