//
//  _python.c
//  Python3_ios
//
//  Created by Emma on 25-11-21.
//  Copyright © 2021 Nicolas Holzschuch. All rights reserved.
//

#include "Python3_ios.h"
#include "pycore_long.h"

PyObject* _PyLong_Zero;

#pragma push_macro("_PyObject_FastCallDict")

#undef _PyObject_FastCallDict

PyObject *_PyObject_FastCallDict(PyObject *callable, PyObject *const *args,
                       size_t nargsf, PyObject *kwargs) {
    return _PyObject_FastCallTstate(PyThreadState_Get(), callable, args, nargsf);
}

PyObject *
_Py_Offer_Suggestions(PyObject *exception);

#pragma pop_macro("_PyObject_FastCallDict")

int _Py_CheckRecursionLimit;

const char * _offer_suggestions(PyObject *exception) {
    
    PyObject *suggestions = _Py_Offer_Suggestions(exception);
    if (suggestions) {
        const char *string = PyUnicode_AsUTF8(suggestions);
        Py_DecRef(suggestions);
        return string;
    } else {
        return NULL;
    }
}

void Python_Initialize() {
    _Py_CheckRecursionLimit = 20;
    Py_Initialize();
    _PyLong_Zero = __PyLong_GetSmallInt_internal(0);
}
