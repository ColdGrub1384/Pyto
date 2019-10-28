
#include "Python.h"

#ifndef PLATFORM
#define PLATFORM "ios"
#endif

const char *
Py_GetPlatform(void)
{
    return PLATFORM;
}
