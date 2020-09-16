//
//  MemoryManager.swift
//  Pyto
//
//  Created by Adrian Labbé on 10-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class that listens for memory usage. When the limit is almost reached, a block is called.
///
/// I don't use the app's memory warnings because it's sent too soon for scripts to stop when the memory doesn't stop to increase. When the usable memory is equal or smaller than 300MB, the listener calls the cleanup function.
@available(iOS 13.0, *) class MemoryManager {
    
    /// Code to execute when the memory limit is almost reached.
    var memoryLimitAlmostReached: (() -> Void)?
    
    /// The available memory.
    var memoryBudget: Float {
        return Float(os_proc_available_memory())/(1024*1024)
    }
    
    /// Starts listening for memory.
    func startListening() {
        // Yes, a timer. But it does not seem to slow down the app.
        _ = Timer.scheduledTimer(withTimeInterval: 0.01, repeats: true, block: { (_) in
            
            #if WIDGET
            let leftLimit: Float = 0.0
            #else
            let leftLimit: Float = 300
            #endif
            
            #if !SCREENSHOTS
            if self.memoryBudget <= leftLimit {
                self.memoryLimitAlmostReached?()
            }
            #endif
        })
    }
}
