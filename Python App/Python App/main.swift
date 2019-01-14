// main.swift
//
// Created by Pyto

import PytoCore

PythonApplicationMain(Bundle.main.path(forResource: "app/main", ofType: "py")!, CommandLine.argc, CommandLine.unsafeArgv)
