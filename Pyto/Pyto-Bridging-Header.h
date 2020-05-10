//
//  Use this file to import your target's headers that you would like to expose to Swift.
//

#import "../Python/Python.h"
#import "Python Bridging/Selectors/BlockBasedSelector.h"
#include <os/proc.h>

PyMODINIT_FUNC (*PyInit__multiarray_umath)(void);
PyMODINIT_FUNC (*PyInit_fftpack_lite)(void);
PyMODINIT_FUNC (*PyInit__umath_linalg)(void);
PyMODINIT_FUNC (*PyInit_lapack_lite)(void);
PyMODINIT_FUNC (*PyInit_mtrand)(void);
