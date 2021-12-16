//
//  ThreadSafeDictionary.swift
//
//  Created by Shashank on 29/10/20.
//

import Foundation

class ThreadSafeDictionary<V: Hashable,T>: Collection {

    private var dictionary: [V: T]
    private let concurrentQueue = DispatchQueue(label: "Dictionary Barrier Queue",
                                                attributes: .concurrent)
    var startIndex: Dictionary<V, T>.Index {
        self.concurrentQueue.sync {
            return self.dictionary.startIndex
        }
    }

    var endIndex: Dictionary<V, T>.Index {
        self.concurrentQueue.sync {
            return self.dictionary.endIndex
        }
    }

    init(dict: [V: T] = [V:T]()) {
        self.dictionary = dict
    }
    // this is because it is an apple protocol method
    // swiftlint:disable identifier_name
    func index(after i: Dictionary<V, T>.Index) -> Dictionary<V, T>.Index {
        self.concurrentQueue.sync {
            return self.dictionary.index(after: i)
        }
    }
    // swiftlint:enable identifier_name

    subscript(key: V) -> T? {
        set(newValue) {
            self.concurrentQueue.async(flags: .barrier) {[weak self] in
                self?.dictionary[key] = newValue
            }
        }
        get {
            self.concurrentQueue.sync {
                return self.dictionary[key]
            }
        }
    }

    // has implicity get
    subscript(index: Dictionary<V, T>.Index) -> Dictionary<V, T>.Element {
        self.concurrentQueue.sync {
            return self.dictionary[index]
        }
    }
    
    func removeValue(forKey key: V) {
        self.concurrentQueue.async(flags: .barrier) {[weak self] in
            self?.dictionary.removeValue(forKey: key)
        }
    }

    func removeAll() {
        self.concurrentQueue.async(flags: .barrier) {[weak self] in
            self?.dictionary.removeAll()
        }
    }

}
