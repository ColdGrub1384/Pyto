//
//  CodeCompletionViewItem.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/10/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa

/// A Collection view item representing a code completion.
class CodeCompletionViewItem: NSCollectionViewItem {

    /// The label containing the title of the suggestion.
    @IBOutlet weak var titleLabel: NSTextField!
    
    /// Code called when the item is selected.
    var selectionHandler: (() -> Void)?
    
    @IBAction private func didSelect(_ sender: Any) {
        selectionHandler?()
    }
    
}
