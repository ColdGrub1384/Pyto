C/C++ Minpack [![Build Status](https://api.travis-ci.org/devernay/cminpack.png?branch=master)](https://travis-ci.org/devernay/cminpack) [![Build Status](https://ci.appveyor.com/api/projects/status/github/devernay/cminpack)](https://ci.appveyor.com/project/devernay/cminpack) [![Coverage Status](https://coveralls.io/repos/devernay/cminpack/badge.png?branch=master)](https://coveralls.io/r/devernay/cminpack?branch=master)  [![Coverity Scan Build Status](https://scan.coverity.com/projects/2942/badge.svg)](https://scan.coverity.com/projects/2942 "Coverity Badge")
==========

This is a C version of the minpack minimization package.
It has been derived from the fortran code using f2c and
some limited manual editing. Note that you need to link
against libf2c to use this version of minpack. Extern "C"
linkage permits the package routines to be called from C++.
Check ftp://netlib.bell-labs.com/netlib/f2c for the latest
f2c version. For general minpack info and test programs, see
the accompanying readme.txt and http://www.netlib.org/minpack/.

Type `make` to compile and `make install` to install in /usr/local
or modify the makefile to suit your needs.

This software has been tested on a RedHat 7.3 Linux machine -
usual 'use at your own risk' warnings apply.

Manolis Lourakis -- lourakis at ics forth gr, July 2002
	Institute of Computer Science,
	Foundation for Research and Technology - Hellas
	Heraklion, Crete, Greece

Repackaging by Frederic Devernay -- frederic dot devernay at m4x dot org

The project home page is at http://devernay.github.io/cminpack

History
------

* version 1.3.7 (//):
  - Makefile cleanups #11
  - Cmake-related fixes #20 #21 #23 #27 #28
  - Add Appveyor CI #24
  - Add support for single-precision CBLAS and LAPACK #40

* version 1.3.6 (24/02/2017):
 - Fix FreeBSD build #6
 - CMake: install CMinpackConfig.cmake rather than FindCMinpack.cmake #8
 - CMake: add option USE_BLAS to compile with blas #9

* version 1.3.5 (28/05/2016):
 - Add support for compiling a long double version (Makefile only).
 - CMake: static libraries now have the suffix _s.

* version 1.3.4 (28/05/2014):
 - Add FindCMinpack.cmake cmake module. If you use the cmake install,
   finding CMinpack from your `CMakeLists.txt` is as easy as
   `find_package(CMinpack)`.

* version 1.3.3 (04/02/2014):
 - Add documentation and examples abouts how to add box constraints to the variables.
 - continuous integration https://travis-ci.org/devernay/cminpack

* version 1.3.2 (27/10/2013):
 - Minor change in the CMake build: also set SOVERSION.

* version 1.3.1 (02/10/2013):
 - Fix CUDA examples compilation, and remove non-free files.

* version 1.3.0 (09/06/2012):
 - Optionally use LAPACK and CBLAS in lmpar, qrfac, and qrsolv. Added
  "make lapack" to build the LAPACK-based cminpack and "make
  checklapack" to test it (results of the test may depend on the
  underlying LAPACK and BLAS implementations).
  On 64-bits architectures, the preprocessor symbol __LP64__ must be
  defined (see cminpackP.h) if the LAPACK library uses the LP64
  interface (i.e. 32-bits integer, vhereas the ILP interface uses 64
  bits integers).

* version 1.2.2 (16/05/2012):
 - Update Makefiles and documentation (see "Using CMinpack" above) for
  easier building and testing.

* version 1.2.1 (15/05/2012):
 - The library can now be built as double, float or half
  versions. Standard tests in the "examples" directory can now be
  lauched using "make check" (to run common tests, including against
  the float version), "make checkhalf" (to test the half version) and
  "make checkfail" (to run all the tests, even those that fail).

* version 1.2.0 (14/05/2012):
- Added original FORTRAN sources for better testing (type "make" in
  directory fortran, then "make" in examples and follow the
  instructions). Added driver tests lmsdrv, chkdrv, hyjdrv,
  hybdrv. Typing "make alltest" in the examples directory will run all
  possible test combinations (make sure you have gfortran installed).

* version 1.1.5 (04/05/2012):
 - cminpack now works in CUDA, thanks to Jordi Bataller Mascarell, type
   "make" in the "cuda" subdir (be careful, though: this is a
   straightforward port from C, and each problem is solved using a
   single thread). cminpack can now also be compiled with
   single-precision floating point computation (define
   __cminpack_real__ to float when compiling and using the
   library). Fix cmake support for CMINPACK_LIB_INSTALL_DIR. Update the
   reference files for tests.

* version 1.1.4 (30/10/2011):
 - Translated all the Levenberg-Marquardt code (lmder, lmdif, lmstr,
     lmder1, lmdif1, lmstr1, lmpar, qrfac, qrsolv, fdjac2, chkder) to use
     C-style indices.

* version 1.1.3 (16/03/2011):
  - Minor fix: Change non-standard strnstr() to strstr() in
     genf77tests.c.

* version 1.1.2 (07/01/2011):
   - Fix Windows DLL building (David Graeff) and document covar in
     cminpack.h.

* version 1.1.1 (04/12/2010):
 - Complete rewrite of the C functions (without trailing underscore in
   the function name). Using the original FORTRAN code, the original
   algorithms structure was recovered, and many goto's were converted
   to if...then...else. The code should now be both more readable and
   easier to optimize, both for humans and for compilers. Added lmddrv
   and lmfdrv test drivers, which test a lot of difficult functions
   (these functions are explained in Testing Unconstrained Optimization
   Software by Moré et al.). Also added the pkg-config files to the
   cmake build, as well as an "uninstall" target, contributed by
   Geoffrey Biggs.

* version 1.0.4 (18/10/2010):
 - Support for shared library building using CMake, thanks to Goeffrey
   Biggs and Radu Bogdan Rusu from Willow Garage. Shared libraries can be
   enabled using cmake options, as in;
 cmake -DUSE_FPIC=ON -DSHARED_LIBS=ON -DBUILD_EXAMPLES=OFF path_to_sources

* version 1.0.3 (18/03/2010):
 - Added CMake support.
 - XCode build is now Universal.
 - Added tfdjac2_ and tfdjac2c examples, which test the accuracy of a
   finite-differences approximation of the Jacobian.
 - Bug fix in tlmstr1 (signaled by Thomas Capricelli).

* version 1.0.2 (27/02/2009):
 - Added Xcode and Visual Studio project files

* version 1.0.1 (17/12/2007):
 - bug fix in covar() and covar_(), the computation of tolr caused a
   segfault (signaled by Timo Hartmann).

* version 1.0.0 (24/04/2007):
 - Added fortran and C examples
 - Added documentation from Debian man pages
 - Wrote pure C version
 - Added covar() and covar_(), and use it in tlmdef/tlmdif
