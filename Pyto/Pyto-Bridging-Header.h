//
//  Use this file to import your target's headers that you would like to expose to Swift.
//

#import "../Python/Headers/Python.h"

PyMODINIT_FUNC (*PyInit_multiarray)(void);
PyMODINIT_FUNC (*PyInit_umath)(void);
PyMODINIT_FUNC (*PyInit_fftpack_lite)(void);
PyMODINIT_FUNC (*PyInit__umath_linalg)(void);
PyMODINIT_FUNC (*PyInit_lapack_lite)(void);
PyMODINIT_FUNC (*PyInit_mtrand)(void);
