//
//  PytoTests.swift
//  PytoTests
//
//  Created by Adrian Labbé on 16-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import XCTest
import Pyto

class PytoTests: XCTestCase {
    
    // Test the Python runtime by importing included libraries and testing other things.
    func testRuntime() throws {
        
        unlock()
        
        let url = Bundle.main.url(forResource: "test_pyto", withExtension: "py")
        XCTAssertNotNil(url)
        
        let keyWindow = UIApplication.shared.connectedScenes
        .filter({$0.activationState == .foregroundActive})
        .map({$0 as? UIWindowScene})
        .compactMap({$0})
        .first?.windows
        .filter({$0.isKeyWindow}).first
        
        let expectation = XCTestExpectation(description: "Run Python unit tests")
        
        (keyWindow?.rootViewController as? DocumentBrowserViewController)?.openDocument(url!, run: true)
        
        DispatchQueue.main.asyncAfter(wallDeadline: .now()+5) {
            _ = Timer.scheduledTimer(withTimeInterval: 1, repeats: true, block: { (timer) in
                if !Python.shared.isScriptRunning(url!.path) {
                    timer.invalidate()
                    
                    let splitVC: EditorSplitViewController?
                    
                    if #available(iOS 14.0, *), let scene = keyWindow?.windowScene {
                        splitVC = EditorView.EditorStore.perScene[scene]?.editor?.viewController as? EditorSplitViewController
                    } else {
                        splitVC = keyWindow?.topViewController as? EditorSplitViewController
                    }
                    
                    XCTAssertNotNil(splitVC)
                    
                    if splitVC!.console?.textView.text.contains("FAILED") == true {
                        XCTFail(splitVC!.console?.textView.text ?? "")
                    }
                    
                    expectation.fulfill()
                }
            })
        }
        
        wait(for: [expectation], timeout: 600)
    }
}

extension PytoTests {
    
    func unlock() {
        isUnlocked = true
        changingUserDefaultsInAppPurchasesValues = true
        isPurchased.boolValue = true
        changingUserDefaultsInAppPurchasesValues = true
        isLiteVersion.boolValue = false
    }
}
