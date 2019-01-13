// main.swift
//
// Created by Pyto

import PytoCore

PythonApplicationMain(Bundle.main.path(forResource: "main", ofType: "py")!, CommandLine.argc, CommandLine.unsafeArgv)
