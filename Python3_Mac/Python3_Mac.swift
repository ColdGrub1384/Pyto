//
//  Python3_Mac.swift
//  Python3_Mac
//
//  Created by Adrian Labbé on 19-06-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Foundation

@_silgen_name("PyRun_SimpleStringFlags")
func PyRun_SimpleStringFlags(_: UnsafePointer<Int8>!, _: UnsafeMutablePointer<Any>!)

@_silgen_name("Py_DecodeLocale")
func Py_DecodeLocale(_: UnsafePointer<Int8>!, _: UnsafeMutablePointer<Int>!) -> UnsafeMutablePointer<wchar_t>

func PyRun(code: String) {
    PyRun_SimpleStringFlags("\(code)", nil)
}
