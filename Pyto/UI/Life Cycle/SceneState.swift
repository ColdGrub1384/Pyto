//
//  SceneState.swift
//  Pyto
//
//  Created by Emma Labbé on 02-07-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import Foundation

// MARK: - Scene State

/// The state of scene. Can be saved on disk
public struct SceneState: Codable {
    
    /// The selected sidebar item.
    public var selection: SelectedSection?
}

// MARK: - Store

/// An object storing the scene state.
public class SceneStateStore: ObservableObject {
    
    private var _sceneState = SceneState()
    
    /// Resets the scene state.
    public func reset() {
        _sceneState = SceneState()
    }
    
    /// The scene state.
    public var sceneState: SceneState {
        set {
            if newValue.selection != nil {
                objectWillChange.send()
                _sceneState = newValue
            }
        }
        
        get {
            return _sceneState
        }
    }
}
