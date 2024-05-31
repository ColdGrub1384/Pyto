//
//  CCodeCompletion.swift
//  Pyto
//
//  Created by Emma on 12-05-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import UIKit
import ios_system

struct CCompletion {
    
    var name: String
    
    var signature: String
}

fileprivate var dylibURL: URL {
    Bundle.main.privateFrameworksURL!.appendingPathComponent("clang_codecompletion.framework/clang_codecompletion")
}

fileprivate var clangURL: URL {
    Bundle.main.privateFrameworksURL!.appendingPathComponent("clang.framework/clang")
}

fileprivate var clang_codecompletion: UnsafeMutableRawPointer?

fileprivate func openClang() -> UnsafeMutableRawPointer? {
    
    guard clang_codecompletion == nil else {
        return clang_codecompletion
    }
    
    clang_codecompletion = dlopen("\(dylibURL.path)", RTLD_NOW)
    let error = dlerror()
    guard error == nil else {
        print(String(utf8String: error!) ?? "")
        return nil
    }
        
    return clang_codecompletion
}

fileprivate var queue = [(url: URL, range: NSRange?, textView: UITextView, completionHandler: Any)]()

fileprivate var isWorking = false

fileprivate func next() {
    if let last = queue.last, let range = last.range, let handler = last.completionHandler as? (([CCompletion]) -> ()) {
        DispatchQueue.global().async {
            isWorking = false
            completeCSource(url: last.url, range: range, textView: last.textView, completionHandler: handler)
            if queue.count > 0 {
                queue.removeLast()
            }
        }
    } else if #available(iOS 15.0, *), let last = queue.last, last.range == nil, let handler = last.completionHandler as? (([Linter.Warning]) -> ()) {
        DispatchQueue.global().async {
            isWorking = false
            lintCSource(url: last.url, textView: last.textView, completionHandler: handler)
            if queue.count > 0 {
                queue.removeLast()
            }
        }
    } else if queue.last == nil {
        isWorking = false
    }
}

func completeCSource(url: URL, range: NSRange, textView: UITextView, completionHandler: @escaping ([CCompletion]) -> ()) {
        
    guard !isWorking else {
        let cur = (url: url, range: range, textView: textView, completionHandler: completionHandler)
        queue = [cur]
        DispatchQueue.main.asyncAfter(deadline: .now()+1) {
            if queue.count == 1 && queue[0].range == cur.range && queue[0].url == cur.url {
                queue = []
                isWorking = false
            }
        }
        return
    }
    
    isWorking = true
        
    guard let clang_codecompletion = openClang() else {
        return next()
    }
    
    guard let completeSym = dlsym(clang_codecompletion, "_Z8completePKcS0_iiP7NSArray") else {
        return next()
    }
    
    let complete = unsafeBitCast(completeSym, to: clang_complete_t.self)
    
    DispatchQueue.main.async {
        guard let wordRange = textView.currentWordWithUnderscoreRange else {
            return next()
        }
        
        guard let word = textView.text(in: wordRange) else {
            return next()
        }
        
        guard !word.isEmpty else {
            next()
            return completionHandler([])
        }
        
        let code = textView.text ?? ""
        DispatchQueue.global().async {
            let isCPP = url.pathExtension == "cpp" || url.pathExtension == "cxx" || url.pathExtension == "hpp"
            
            var includes = []
            
            let additional = [FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].appendingPathComponent("include/python3.10").path, url.deletingLastPathComponent().path]
            for path in (ProcessInfo.processInfo.environment["C\(isCPP ? "PLUS" : "")_INCLUDE_PATH"]?.components(separatedBy: ":") ?? [])+additional {
                includes.append("-I\(path)")
            }
            
            var line = 1
            var column = 0

            for i in 0..<range.location {
                let _range = NSRange(location: i, length: 1)
                
                guard NSString(string: code).length > i else {
                    continue
                }
                
                let char = NSString(string: code).substring(with: _range)
                if char == "\n" {
                    line += 1
                    column = 0
                } else {
                    column += 1
                }
            }
            
            var additionalFlags = ["-fsyntax-only"]
            
            if url.pathExtension == "m" || url.pathExtension == "mm" {
                additionalFlags.append("-mios-version-min=13.0")
            }
            
            // NSArray* complete(const char *path, const char *code, int line, int column, NSArray *argv)
            let results = complete("\(url.path)", NSString(string: code).utf8String, Int32(line), Int32(column), includes+additionalFlags)?.first as? [[String]]
            
            var codeCompletions = [CCompletion]()
            
            for item in results ?? [] {
                
                guard codeCompletions.count < 20 else {
                    break
                }
                
                guard let name = item.first, var signature = item.last else {
                    continue
                }
                
                guard name.lowercased().hasPrefix(word.lowercased()) else {
                    continue
                }
                            
                signature = signature.replacingOccurrences(of: "[#", with: "")
                signature = signature.replacingOccurrences(of: "#]", with: " ")
                signature = signature.replacingOccurrences(of: "<#", with: "")
                signature = signature.replacingOccurrences(of: "#>", with: "")
                
                codeCompletions.append(CCompletion(name: name, signature: signature))
            }
            
            DispatchQueue.main.async {
                completionHandler(codeCompletions)
                next()
            }
        }
    }
}

@available(iOS 15.0, *)
func lintCSource(url: URL, textView: UITextView, completionHandler: @escaping ([Linter.Warning]) -> ()) {
    
    guard !isWorking else {
        queue.append((url: url, range: nil, textView: textView, completionHandler: completionHandler))
        return
    }
    
    isWorking = true
        
    guard let clang_codecompletion = openClang() else {
        return next()
    }
    
    guard let completeSym = dlsym(clang_codecompletion, "_Z8completePKcS0_iiP7NSArray") else {
        return next()
    }
    
    let complete = unsafeBitCast(completeSym, to: clang_complete_t.self)
    
    DispatchQueue.main.async {
        let code = textView.text ?? ""
        let range = NSRange(location: (code as NSString).length-1, length: (code as NSString).length)
        
        DispatchQueue.global().async {
            let isCPP = url.pathExtension == "cpp" || url.pathExtension == "cxx" || url.pathExtension == "hpp"
            
            var includes = []
            
            let additional = [FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].appendingPathComponent("include/python3.10").path, url.deletingLastPathComponent().path]
            for path in (ProcessInfo.processInfo.environment["C\(isCPP ? "PLUS" : "")_INCLUDE_PATH"]?.components(separatedBy: ":") ?? [])+additional {
                includes.append("-I\(path)")
            }
            
            var line = 1
            var column = 0

            guard range.location > -1 else {
                return
            }
            
            for i in 0..<range.location {
                let char = NSString(string: code).substring(with: NSRange(location: i, length: 1))
                if char == "\n" {
                    line += 1
                    column = 0
                } else {
                    column += 1
                }
            }
            
            // NSArray* complete(const char *path, const char *code, int line, int column, NSArray *argv)
            let results = complete("\(url.path)", NSString(string: code).utf8String, Int32(line), Int32(column), []+includes)?.last as? [String]
            
            var diagnostics = [Linter.Warning]()
            for diagnostic in results ?? [] {
                var comp = diagnostic.components(separatedBy: ":")
                
                guard comp.count >= 5 else {
                    continue
                }
                
                let filePath = comp[0]
                
                guard let line = Int(comp[1]) else {
                    continue
                }
                
                let type = comp[3].replacingOccurrences(of: " ", with: "")
                
                for _ in 0..<4 {
                    comp.removeFirst()
                }
                
                let message = comp.joined(separator: ":")
                
                diagnostics.append(Linter.Warning(type: type, typeDescription: type, message: message, lineno: line, url: URL(fileURLWithPath: filePath)))
            }
            
            DispatchQueue.main.async {
                completionHandler(diagnostics)
                next()
            }
        }
    }
}
