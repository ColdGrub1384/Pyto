c     **********
c
c     this program tests codes for the solution of n nonlinear
c     equations in n variables. it consists of a driver and an
c     interface subroutine fcn. the driver reads in data, calls the
c     nonlinear equation solver, and finally prints out information
c     on the performance of the solver. this is only a sample driver,
c     many other drivers are possible. the interface subroutine fcn
c     is necessary to take into account the forms of calling
c     sequences used by the function subroutines in the various
c     nonlinear equation solvers.
c
c     subprograms called
c
c       user-supplied ...... fcn
c
c       minpack-supplied ... dpmpar,enorm,hybrd1,initpt,vecfcn
c
c       fortran-supplied ... dsqrt
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer i,ic,info,k,lwa,n,nfev,nprob,nread,ntries,nwrite
      integer na(60),nf(60),np(60),nx(60)
      double precision factor,fnorm1,fnorm2,one,ten,tol
      double precision fnm(60),fvec(40),wa(2660),x(40)
      double precision dpmpar,enorm
      external fcn
      common /refnum/ nprob,nfev
c
c     logical input unit is assumed to be number 5.
c     logical output unit is assumed to be number 6.
c
      data nread,nwrite /5,6/
c
      data one,ten /1.0d0,1.0d1/
      tol = dsqrt(dpmpar(1))
      lwa = 2660
      ic = 0
   10 continue
         read (nread,50) nprob,n,ntries
         if (nprob .le. 0) go to 30
         factor = one
         do 20 k = 1, ntries
            ic = ic + 1
            call initpt(n,x,nprob,factor)
            call vecfcn(n,x,fvec,nprob)
            fnorm1 = enorm(n,fvec)
            write (nwrite,60) nprob,n
            nfev = 0
            call hybrd1(fcn,n,x,fvec,tol,info,wa,lwa)
            fnorm2 = enorm(n,fvec)
            np(ic) = nprob
            na(ic) = n
            nf(ic) = nfev
            nx(ic) = info
            fnm(ic) = fnorm2
            write (nwrite,70) fnorm1,fnorm2,nfev,info,(x(i), i = 1, n)
            factor = ten*factor
   20       continue
         go to 10
   30 continue
      write (nwrite,80) ic
      write (nwrite,90)
      do 40 i = 1, ic
         write (nwrite,100) np(i),na(i),nf(i),nx(i),fnm(i)
   40    continue
      stop
   50 format (3i5)
   60 format ( //// 5x, 8h problem, i5, 5x, 10h dimension, i5, 5x //)
   70 format (5x, 33h initial l2 norm of the residuals, d15.7 // 5x,
     *        33h final l2 norm of the residuals  , d15.7 // 5x,
     *        33h number of function evaluations  , i10 // 5x,
     *        15h exit parameter, 18x, i10 // 5x,
     *        27h final approximate solution // (5x, 5d15.7))
   80 format (12h1summary of , i3, 16h calls to hybrd1 /)
   90 format (39h nprob   n    nfev  info  final l2 norm /)
  100 format (i4, i6, i7, i6, 1x, d15.7)
c
c     last card of driver.
c
      end
      subroutine fcn(n,x,fvec,iflag)
      integer n,iflag
      double precision x(n),fvec(n)
c     **********
c
c     the calling sequence of fcn should be identical to the
c     calling sequence of the function subroutine in the nonlinear
c     equation solver. fcn should only call the testing function
c     subroutine vecfcn with the appropriate value of problem
c     number (nprob).
c
c     subprograms called
c
c       minpack-supplied ... vecfcn
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer nprob,nfev
      common /refnum/ nprob,nfev
      call vecfcn(n,x,fvec,nprob)
      nfev = nfev + 1
      return
c
c     last card of interface subroutine fcn.
c
      end
