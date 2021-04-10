//
//  Arguments.m
//  Pyto Intents
//
//  Created by Emma Labbé on 11-01-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

#import "../Python/Python.h"
#import <Foundation/Foundation.h>

void setArgv(NSArray *argv) {
    
    int count = (int)[argv count];
    char **cargs = (char **) malloc(sizeof(char *) * (count + 1));
    //cargs is a pointer to 4 pointers to char

    int i;
    for(i = 0; i < count; i++) {
        NSString *s = [argv objectAtIndex:i];//get a NSString
        const char *cstr = [s cStringUsingEncoding:NSUTF8StringEncoding];//get cstring
        int len = (int)strlen(cstr);//get its length
        char *cstr_copy = (char *) malloc(sizeof(char) * (len + 1));//allocate memory, + 1 for ending '\0'
        strcpy(cstr_copy, cstr);//make a copy
        cargs[i] = cstr_copy;//put the point in cargs
    }
    cargs[i] = NULL;
    
    wchar_t** python_argv = PyMem_RawMalloc(sizeof(wchar_t*) * count);
    i = 0;
    for (i = 0; i < count; i++) {
        python_argv[i] = Py_DecodeLocale(cargs[i], NULL);
    }
    PySys_SetArgv(count, python_argv);
}
