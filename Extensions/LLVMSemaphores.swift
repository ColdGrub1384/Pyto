//
//  LLVMSemaphores.swift
//  Pyto
//
//  Created by Emma on 12-01-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import Foundation

typealias thread = pthread_t

@objc class LLVMSemaphores: NSObject {
    
    @objc var function: DispatchSemaphore?
    @objc var waiter: DispatchSemaphore?
    @objc var moduleThread: UnsafeRawPointer?
    
    @objc override init() {
        
        self.function = DispatchSemaphore(value: 0)
        self.waiter = DispatchSemaphore(value: 0)
        
        super.init()
    }
    
    static var semaphores = [UnsafeMutablePointer<PyObject>:LLVMSemaphores]()
    
    @objc static var objcSemaphores: [LLVMSemaphores] {
        Array<LLVMSemaphores>(semaphores.values)
    }
    
    @objc static func semaphores(for object: UnsafeMutablePointer<PyObject>) -> LLVMSemaphores {
        if let semaphores = self.semaphores[object] {
            return semaphores
        } else {
            let semaphores = LLVMSemaphores()
            if Thread.isMainThread {
                self.semaphores[object] = semaphores
            } else {
                let semaphore = DispatchSemaphore(value: 0)
                DispatchQueue.main.async {
                    self.semaphores[object] = semaphores
                    semaphore.signal()
                }
                semaphore.wait()
            }
            
            return semaphores
        }
    }
}
