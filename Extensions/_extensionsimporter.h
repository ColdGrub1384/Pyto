//
//  _extensionsimporter.h
//  Pyto
//
//  Created by Emma Labbé on 17-11-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

#include <Python.h>
#include <dlfcn.h>
#import <Foundation/Foundation.h>
#import "ios_system.h"
#include <stdlib.h>

#define SET_FILE() PyObject_SetAttrString(module, "__file__", PyUnicode_FromString(binaryURL.path.UTF8String));

#ifndef _extensionsimporter_h
#define _extensionsimporter_h

PyMODINIT_FUNC PyInit__extensionsimporter(void);

#if MAIN
bool is_bitcode_thread(void);
#endif

#endif /* _extensionsimporter_h */
