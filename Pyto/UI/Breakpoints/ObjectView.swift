//
//  ObjectView.swift
//  Pyto
//
//  Created by Emma on 23-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import SwiftUI

struct ObjectView: View {

    enum Object {
        enum Namespace {
            case locals
            case globals
        }
        
        case namespace(String, Namespace)
        case evaluate(String)
    }
    
    var object: Object
    
    @State var objects = [String:String]()
    
    func object(for key: String) -> Object {
        switch object {
        case .namespace(let id, let namespace):
            return .evaluate("get_object(console.namespaces['\(id)']().\(namespace == .locals ? "local" : "_global"))['\(key)']")
        case .evaluate(let string):
            return .evaluate("get_object(\(string))['\(key)']")
        }
    }
    
    var body: some View {
        if objects == [:] {
            Text("").onAppear {
                #if !SCREENSHOTS
                let obj: String
                
                switch object {
                case .namespace(let id, let namespace):
                    obj = "console.namespaces['\(id)']().\(namespace == .locals ? "local" : "_global")"
                case .evaluate(let code):
                    obj = "\(code)"
                }
                
                let code = """
                import console
                import json
                
                def get_object(obj):
                    if isinstance(obj, list):
                        array = {}
                        i = 0
                        for item in obj:
                            array[str(i)] = item
                            i += 1
                        return array
                    elif not isinstance(obj, dict):
                        _dict = {}
                        
                        for item in dir(obj):
                            _dict[item] = getattr(obj, item)
                
                        return _dict
                    else:
                        return obj
                
                objects = {}
                namespace = get_object(\(obj))
                
                for (key, value) in namespace.items():
                    if key == "__namespace__":
                        continue
                
                    objects[key] = repr(value)
                
                s = json.dumps(objects)
                """
                
                if let json = Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: code)?.takeUnretainedValue() as? String {
                    do {
                        objects = (try JSONSerialization.jsonObject(with: json.data(using: .utf8) ?? Data(), options: []) as? [String:String]) ?? objects
                    } catch {
                        print(error.localizedDescription)
                    }
                }
                #else
                switch object {
                case .namespace(_, let namespace):
                    if namespace == .locals {
                        objects = ["name": "'Emma'"]
                    } else {
                        objects = [
                            "__builtins__": "{'__name__': 'builtins', '__doc__': '', '__package__': '', '__loader__': <class '_frozen_importlib.BuiltinImporter'>, '__spec__': ModuleSpec(name='builtins', loader=",
                            "__cached__": "'iCloud/test/__pycache__/main.cpython-310.pyc'",
                            "__doc__": "None",
                            "__file__": "'iCloud/test/main.py'",
                            "__loader__": "<_frozen_importlib_external.SourceFileLoader object at 0x12102b400>",
                            "__name__": "'__main__'",
                            "__package__": "''",
                            "__spec__": "ModuleSpec(name='__main__', loader=<_frozen_importlib_external.SourceFileLoader object at 0x12102b400>, origin='iCloud/test/main.py')",
                            "main": "<function main at 0x11f3f3910>",
                        ]
                    }
                case .evaluate(_):
                    break
                }
                #endif
            }
        } else if Array(objects.keys) != [""] {
            ForEach(Array(objects.keys).sorted(by: { a, b in
                if let a = Int(a), let b = Int(b) {
                    return a < b
                } else {
                    return a < b
                }
            }), id: \.self) { key in
                NavigationLink {
                    VStack {
                        HStack {
                            Spacer()
                            Text(ShortenFilePaths(in: objects[key] ?? "")).lineLimit(1)
                            Spacer()
                        }.padding()
                        List {
                            ObjectView(object: object(for: key))
                        }
                    }.navigationBarTitle(key)
                } label: {
                    HStack {
                        Text(ShortenFilePaths(in: key)).lineLimit(1)
                        Spacer()
                        Text(ShortenFilePaths(in: objects[key] ?? "")).lineLimit(1).foregroundColor(.secondary)
                    }
                }
            }
        } else {
            EmptyView()
        }
    }
}

struct ObjectView_Previews: PreviewProvider {
    static var previews: some View {
        ObjectView(object: .namespace("", .locals))
    }
}
