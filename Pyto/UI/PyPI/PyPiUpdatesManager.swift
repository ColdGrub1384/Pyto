//
//  PyPiUpdatesManager.swift
//  Pyto
//
//  Created by Emma on 06-04-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import Foundation

struct PyPiUpdate: Codable, Equatable {
    
    var name: String
    
    var version: String
}

class PyPiUpdatesManager: ObservableObject {
    
    @Published var updatablePackages = [PyPiUpdate]() {
        didSet {
            if updatablePackages != oldValue {
                objectWillChange.send()
            }
            
            if let json = try? JSONEncoder().encode(updatablePackages) {
                UserDefaults.standard.set(json, forKey: "pypiUpdates")
            }
        }
    }
    
    func fetchUpdates() {
        if let cached = UserDefaults.standard.data(forKey: "pypiUpdates"), let list = try? JSONDecoder().decode([PyPiUpdate].self, from: cached) {
            updatablePackages = list
        }
        
        #if !PREVIEW
        
        DispatchQueue.global().async {
            let updatesJSON = runPip(arguments: ["list", "--outdated", "--format", "json"]).data(using: .utf8) ?? Data()
            guard var updates = try? JSONDecoder().decode([PyPiUpdate].self, from: updatesJSON) else {
                return
            }
            updates = updates.filter({ !PipViewController.bundled.contains($0.name) })
            DispatchQueue.main.async {
                self.updatablePackages = updates
            }
        }
        
        #endif
    }
}
