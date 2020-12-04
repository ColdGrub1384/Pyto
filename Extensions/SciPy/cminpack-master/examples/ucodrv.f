c     **********
c
c     this program tests codes for the unconstrained optimization of
c     a nonlinear function of n variables. it consists of a driver
c     and an interface subroutine fcn. the driver reads in data,
c     calls the unconstrained optimizer, and finally prints out
c     information on the performance of the optimizer. this is
c     only a sample driver, many other drivers are possible. the
c     interface subroutine fcn is necessary to take into account the
c     forms of calling sequences used by the function subroutines
c     in the various unconstrained optimizers.
c
c     subprograms called
c
c       user-supplied ...... fcn
c
c       minpack-supplied ... dpmpar,drvcr1,enorm,grdfcn,initpt,objfcn
c
c       fortran-supplied ... dsqrt
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer i,ic,info,k,lwa,n,nfev,nprob,nread,ntries,nwrite
      integer na(120),nf(120),np(120),nx(120)
      double precision factor,f1,f2,gnorm1,gnorm2,one,ten,tol
      double precision fval(120),gvec(100),gnm(120),wa(6130),x(100)
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
      lwa = 6130
      ic = 0
   10 continue
         read (nread,50) nprob,n,ntries
         if (nprob .le. 0) go to 30
         factor = one
         do 20 k = 1, ntries
            ic = ic + 1
            call initpt(n,x,nprob,factor)
            call objfcn(n,x,f1,nprob)
            call grdfcn(n,x,gvec,nprob)
            gnorm1 = enorm(n,gvec)
            write (nwrite,60) nprob,n
            nfev = 0
            call drvcr1(fcn,n,x,f2,gvec,tol,info,wa,lwa)
            call objfcn(n,x,f2,nprob)
            call grdfcn(n,x,gvec,nprob)
            gnorm2 = enorm(n,gvec)
            np(ic) = nprob
            na(ic) = n
            nf(ic) = nfev
            nx(ic) = info
            fval(ic) = f2
            gnm(ic) = gnorm2
            write (nwrite,70)
     *            f1,f2,gnorm1,gnorm2,nfev,info,(x(i), i = 1, n)
            factor = ten*factor
   20       continue
         go to 10
   30 continue
      write (nwrite,80) ic
      write (nwrite,90)
      do 40 i = 1, ic
         write (nwrite,100) np(i),na(i),nf(i),nx(i),fval(i),gnm(i)
   40    continue
      stop
   50 format (3i5)
   60 format ( //// 5x, 8h problem, i5, 5x, 10h dimension, i5, 5x //)
   70 format (5x, 23h initial function value, d15.7 // 5x,
     *        23h final function value  , d15.7 // 5x,
     *        23h initial gradient norm , d15.7 // 5x,
     *        23h final gradient norm   , d15.7 // 5x,
     *        33h number of function evaluations  , i10 // 5x,
     *        15h exit parameter, 18x, i10 // 5x,
     *        27h final approximate solution // (5x, 5d15.7))
   80 format (12h1summary of , i3, 16h calls to drvcr1 /)
   90 format (25h nprob   n    nfev  info ,
     *        42h final function value  final gradient norm /)
  100 format (i4, i6, i7, i6, 5x, d15.7, 6x, d15.7)
c
c     last card of driver.
c
      end
      subroutine fcn(n,x,f,gvec,iflag)
      integer n,iflag
      double precision f
      double precision x(n),gvec(n)
c     **********
c
c     the calling sequence of fcn should be identical to the
c     calling sequence of the function subroutine in the
c     unconstrained optimizer. fcn should only call the testing
c     function and gradient subroutines objfcn and grdfcn with
c     the appropriate value of problem number (nprob).
c
c     subprograms called
c
c       minpack-supplied ... grdfcn,objfcn
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer nprob,nfev
      common /refnum/ nprob,nfev
      call objfcn(n,x,f,nprob)
      call grdfcn(n,x,gvec,nprob)
      nfev = nfev + 1
      return
c
c     last card of interface subroutine fcn.
c
      end
