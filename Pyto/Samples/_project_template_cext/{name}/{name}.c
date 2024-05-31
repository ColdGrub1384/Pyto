// Created with Pyto

#include <Python.h>

static PyObject* _main(PyObject* self, PyObject* args) {
    printf("Hello World!\n");
    return Py_None;
}

// Our Module's Function Definition struct
// We require this `NULL` to signal the end of our method
// definition
static PyMethodDef {pkg}Methods[] = {
    { "main", _main, METH_NOARGS, "docstring here" },
    { NULL, NULL, 0, NULL }
};

// Our Module Definition struct
static struct PyModuleDef {pkg}Module = {
    PyModuleDef_HEAD_INIT,
    "{pkg}",
    "docstring here",
    -1,
    {pkg}Methods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_{pkg}(void) {
    return PyModule_Create(&{pkg}Module);
}
