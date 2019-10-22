/* Generated automatically from ./Modules/config.c.in by makesetup. */
/* -*- C -*- ***********************************************
Copyright (c) 2000, BeOpen.com.
Copyright (c) 1995-2000, Corporation for National Research Initiatives.
Copyright (c) 1990-1995, Stichting Mathematisch Centrum.
All rights reserved.

See the file "Misc/COPYRIGHT" for information on usage and
redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.
******************************************************************/

/* Module configuration */

/* !!! !!! !!! This file is edited by the makesetup script !!! !!! !!! */

/* This file contains the table of built-in modules.
   See create_builtin() in import.c. */

#include "Python.h"

#ifdef __cplusplus
extern "C" {
#endif

PyMODINIT_FUNC PyInit_pyexpat(void);

PyMODINIT_FUNC PyInit_posix(void);
PyMODINIT_FUNC PyInit_errno(void);
PyMODINIT_FUNC PyInit_pwd(void);
PyMODINIT_FUNC PyInit__sre(void);
PyMODINIT_FUNC PyInit__codecs(void);
PyMODINIT_FUNC PyInit__weakref(void);
PyMODINIT_FUNC PyInit__functools(void);
PyMODINIT_FUNC PyInit__operator(void);
PyMODINIT_FUNC PyInit__collections(void);
PyMODINIT_FUNC PyInit__abc(void);
PyMODINIT_FUNC PyInit_itertools(void);
PyMODINIT_FUNC PyInit_atexit(void);
PyMODINIT_FUNC PyInit__signal(void);
PyMODINIT_FUNC PyInit__stat(void);
PyMODINIT_FUNC PyInit_time(void);
PyMODINIT_FUNC PyInit__thread(void);
PyMODINIT_FUNC PyInit__locale(void);
PyMODINIT_FUNC PyInit__io(void);
PyMODINIT_FUNC PyInit_faulthandler(void);
PyMODINIT_FUNC PyInit__tracemalloc(void);
PyMODINIT_FUNC PyInit__symtable(void);
PyMODINIT_FUNC PyInit_xxsubtype(void);

/* -- ADDMODULE MARKER 1 -- */

PyMODINIT_FUNC PyMarshal_Init(void);
PyMODINIT_FUNC PyInit__imp(void);
PyMODINIT_FUNC PyInit_gc(void);
PyMODINIT_FUNC PyInit__ast(void);
PyMODINIT_FUNC _PyWarnings_Init(void);
PyMODINIT_FUNC PyInit__string(void);
    
/* Distribution standard modules -- auto generated from make.log */
/* Standard distribution modules, embedded for iOS */
PyMODINIT_FUNC PyInit__struct(void);
PyMODINIT_FUNC PyInit_array(void);
PyMODINIT_FUNC PyInit__contextvars(void);
PyMODINIT_FUNC PyInit_cmath(void);
PyMODINIT_FUNC PyInit_math(void);
PyMODINIT_FUNC PyInit__datetime(void);
PyMODINIT_FUNC PyInit__random(void);
PyMODINIT_FUNC PyInit__bisect(void);
PyMODINIT_FUNC PyInit__heapq(void);
PyMODINIT_FUNC PyInit__pickle(void);
PyMODINIT_FUNC PyInit__json(void);
PyMODINIT_FUNC PyInit__testbuffer(void);
PyMODINIT_FUNC PyInit__testimportmultiple(void);
PyMODINIT_FUNC PyInit__testmultiphase(void);
PyMODINIT_FUNC PyInit__lsprof(void);
PyMODINIT_FUNC PyInit_unicodedata(void);
PyMODINIT_FUNC PyInit__opcode(void);
PyMODINIT_FUNC PyInit__asyncio(void);
PyMODINIT_FUNC PyInit__queue(void);
PyMODINIT_FUNC PyInit_fcntl(void);
PyMODINIT_FUNC PyInit_grp(void);
PyMODINIT_FUNC PyInit_select(void);
PyMODINIT_FUNC PyInit_parser(void);
PyMODINIT_FUNC PyInit_mmap(void);
PyMODINIT_FUNC PyInit_syslog(void);
PyMODINIT_FUNC PyInit__xxtestfuzz(void);
PyMODINIT_FUNC PyInit_audioop(void);
// PyMODINIT_FUNC PyInit_readline(void); // not compatible with AppStore
PyMODINIT_FUNC PyInit__crypt(void);
PyMODINIT_FUNC PyInit__csv(void);
PyMODINIT_FUNC PyInit__posixsubprocess(void);
PyMODINIT_FUNC PyInit__socket(void);
PyMODINIT_FUNC PyInit__ssl(void);
PyMODINIT_FUNC PyInit__hashlib(void);
PyMODINIT_FUNC PyInit__sha256(void);
PyMODINIT_FUNC PyInit__sha512(void);
PyMODINIT_FUNC PyInit__md5(void);
PyMODINIT_FUNC PyInit__sha1(void);
PyMODINIT_FUNC PyInit__blake2(void);
PyMODINIT_FUNC PyInit__sha3(void);
PyMODINIT_FUNC PyInit_termios(void);
PyMODINIT_FUNC PyInit_resource(void);
// PyMODINIT_FUNC PyInit__curses(void); // not compatible with AppStore
// PyMODINIT_FUNC PyInit__curses_panel(void); // Library not loaded: /usr/lib/libpanel.5.4.dylib
PyMODINIT_FUNC PyInit_binascii(void);
PyMODINIT_FUNC PyInit__bz2(void);
// PyMODINIT_FUNC PyInit__lzma(void);  // not compatible with AppStore
PyMODINIT_FUNC PyInit__elementtree(void);
PyMODINIT_FUNC PyInit__multibytecodec(void);
PyMODINIT_FUNC PyInit__codecs_kr(void);
PyMODINIT_FUNC PyInit__codecs_jp(void);
PyMODINIT_FUNC PyInit__codecs_cn(void);
PyMODINIT_FUNC PyInit__codecs_tw(void);
PyMODINIT_FUNC PyInit__codecs_hk(void);
PyMODINIT_FUNC PyInit__codecs_iso2022(void);
PyMODINIT_FUNC PyInit__decimal(void);
PyMODINIT_FUNC PyInit__multiprocessing(void);
// PyMODINIT_FUNC PyInit__scproxy(void);
// PyMODINIT_FUNC PyInit__tkinter(void);
PyMODINIT_FUNC PyInit_xxlimited(void);
PyMODINIT_FUNC PyInit__ctypes(void);
// Not included by configure, but required anyway:
PyMODINIT_FUNC PyInit_zlib(void);
PyMODINIT_FUNC PyInit__sqlite3(void);
// New in Python3.7:
PyMODINIT_FUNC PyInit__uuid(void);
// For Jupyter:
PyMODINIT_FUNC PyInit_libzmq(void);
PyMODINIT_FUNC PyInit__cffi_ext(void);

struct _inittab _PyImport_Inittab[] = {

    {"posix", PyInit_posix},
    {"errno", PyInit_errno},
    {"pwd", PyInit_pwd},
    {"_sre", PyInit__sre},
    {"_codecs", PyInit__codecs},
    {"_weakref", PyInit__weakref},
    {"_functools", PyInit__functools},
    {"_operator", PyInit__operator},
    {"_collections", PyInit__collections},
    {"_abc", PyInit__abc},
    {"itertools", PyInit_itertools},
    {"atexit", PyInit_atexit},
    {"_signal", PyInit__signal},
    {"_stat", PyInit__stat},
    {"time", PyInit_time},
    {"_thread", PyInit__thread},
    {"_locale", PyInit__locale},
    {"_io", PyInit__io},
    {"faulthandler", PyInit_faulthandler},
    {"_tracemalloc", PyInit__tracemalloc},
    {"_symtable", PyInit__symtable},
    {"xxsubtype", PyInit_xxsubtype},

/* -- ADDMODULE MARKER 2 -- */

    /* This module lives in marshal.c */
    {"marshal", PyMarshal_Init},

    /* This lives in import.c */
    {"_imp", PyInit__imp},

    /* This lives in Python/Python-ast.c */
    {"_ast", PyInit__ast},

    /* These entries are here for sys.builtin_module_names */
    {"builtins", NULL},
    {"sys", NULL},

    /* This lives in gcmodule.c */
    {"gc", PyInit_gc},

    /* This lives in _warnings.c */
    {"_warnings", _PyWarnings_Init},

    /* This lives in Objects/unicodeobject.c */
    {"_string", PyInit__string},

    /* Standard distribution modules, embedded for iOS */
    {"_struct", PyInit__struct},
    {"array", PyInit_array},
    {"_contextvars", PyInit__contextvars},
    {"cmath", PyInit_cmath},
    {"math", PyInit_math},
    {"_datetime", PyInit__datetime},
    {"_random", PyInit__random},
    {"_bisect", PyInit__bisect},
    {"_heapq", PyInit__heapq},
    {"_pickle", PyInit__pickle},
    {"_json", PyInit__json},
    {"_testbuffer", PyInit__testbuffer},
    {"_testimportmultiple", PyInit__testimportmultiple},
    {"_testmultiphase", PyInit__testmultiphase},
    {"_lsprof", PyInit__lsprof},
    {"unicodedata", PyInit_unicodedata},
    {"_opcode", PyInit__opcode},
    {"_asyncio", PyInit__asyncio},
    {"_queue", PyInit__queue},
    {"fcntl", PyInit_fcntl},
    {"grp", PyInit_grp},
    {"select", PyInit_select},
    {"parser", PyInit_parser},
    {"mmap", PyInit_mmap},
    {"syslog", PyInit_syslog},
    {"_fuzz", PyInit__xxtestfuzz},
    {"audioop", PyInit_audioop},
    // {"readline", PyInit_readline}, // not compatible with AppStore
    {"_crypt", PyInit__crypt},
    {"_csv", PyInit__csv},
    {"_posixsubprocess", PyInit__posixsubprocess},
    {"_socket", PyInit__socket},
    {"_ssl", PyInit__ssl},
    {"_hashlib", PyInit__hashlib},
    {"_sha256", PyInit__sha256},
    {"_sha512", PyInit__sha512},
    {"_md5", PyInit__md5},
    {"_sha1", PyInit__sha1},
    {"_blake2", PyInit__blake2},
    {"_sha3", PyInit__sha3},
    {"termios", PyInit_termios},
    {"resource", PyInit_resource},
    // {"_curses", PyInit__curses},  // Not compatible with AppStore
    // {"_curses_panel", PyInit__curses_panel}, // Library not loaded: /usr/lib/libpanel.5.4.dylib
    {"binascii", PyInit_binascii},
    {"_bz2", PyInit__bz2},
    // {"_lzma", PyInit__lzma},  // not compatible with AppStore
    {"_elementtree", PyInit__elementtree},
    {"_multibytecodec", PyInit__multibytecodec},
    {"_codecs_kr", PyInit__codecs_kr},
    {"_codecs_jp", PyInit__codecs_jp},
    {"_codecs_cn", PyInit__codecs_cn},
    {"_codecs_tw", PyInit__codecs_tw},
    {"_codecs_hk", PyInit__codecs_hk},
    {"_codecs_iso2022", PyInit__codecs_iso2022},
    {"_decimal", PyInit__decimal},
    {"_multiprocessing", PyInit__multiprocessing},
    // {"_scproxy", PyInit__scproxy},
    // {"_tkinter", PyInit__tkinter},
    {"xxlimited", PyInit_xxlimited},
    {"_ctypes", PyInit__ctypes},
    // Not included by configure, but required anyway:
    {"zlib", PyInit_zlib},
    {"_sqlite3", PyInit__sqlite3},
    {"_uuid", PyInit__uuid},
    
    {"pyexpat", PyInit_pyexpat},
    
    {0, 0}
};


#ifdef __cplusplus
}
#endif
