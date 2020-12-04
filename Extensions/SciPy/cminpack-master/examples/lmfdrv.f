c     **********
c
c     this program tests codes for the least-squares solution of
c     m nonlinear equations in n variables. it consists of a driver
c     and an interface subroutine fcn. the driver reads in data,
c     calls the nonlinear least-squares solver, and finally prints
c     out information on the performance of the solver. this is
c     only a sample driver, many other drivers are possible. the
c     interface subroutine fcn is necessary to take into account the
c     forms of calling sequences used by the function and jacobian
c     subroutines in the various nonlinear least-squares solvers.
c
c     subprograms called
c
c       user-supplied ...... fcn
c
c       minpack-supplied ... dpmpar,enorm,initpt,lmdif1,ssqfcn
c
c       fortran-supplied ... dsqrt
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer i,ic,info,k,lwa,m,n,nfev,njev,nprob,nread,ntries,nwrite
      integer iwa(40),ma(60),na(60),nf(60),nj(60),np(60),nx(60)
      double precision factor,fnorm1,fnorm2,one,ten,tol
      double precision fnm(60),fvec(65),wa(2865),x(40)
      double precision dpmpar,enorm
      external fcn
      common /refnum/ nprob,nfev,njev
c
c     logical input unit is assumed to be number 5.
c     logical output unit is assumed to be number 6.
c
      data nread,nwrite /5,6/
c
      data one,ten /1.0d0,1.0d1/
      tol = dsqrt(dpmpar(1))
      lwa = 2865
      ic = 0
   10 continue
         read (nread,50) nprob,n,m,ntries
         if (nprob .le. 0) go to 30
         factor = one
         do 20 k = 1, ntries
            ic = ic + 1
            call initpt(n,x,nprob,factor)
            call ssqfcn(m,n,x,fvec,nprob)
            fnorm1 = enorm(m,fvec)
            write (nwrite,60) nprob,n,m
            nfev = 0
            njev = 0
            call lmdif1(fcn,m,n,x,fvec,tol,info,iwa,wa,lwa)
            call ssqfcn(m,n,x,fvec,nprob)
            fnorm2 = enorm(m,fvec)
            np(ic) = nprob
            na(ic) = n
            ma(ic) = m
            nf(ic) = nfev
            njev = njev/n
            nj(ic) = njev
            nx(ic) = info
            fnm(ic) = fnorm2
            write (nwrite,70)
     *            fnorm1,fnorm2,nfev,njev,info,(x(i), i = 1, n)
            factor = ten*factor
   20       continue
         go to 10
   30 continue
      write (nwrite,80) ic
      write (nwrite,90)
      do 40 i = 1, ic
         write (nwrite,100) np(i),na(i),ma(i),nf(i),nj(i),nx(i),fnm(i)
   40    continue
      stop
   50 format (4i5)
   60 format ( //// 5x, 8h problem, i5, 5x, 11h dimensions, 2i5, 5x //
     *         )
   70 format (5x, 33h initial l2 norm of the residuals, d15.7 // 5x,
     *        33h final l2 norm of the residuals  , d15.7 // 5x,
     *        33h number of function evaluations  , i10 // 5x,
     *        33h number of jacobian evaluations  , i10 // 5x,
     *        15h exit parameter, 18x, i10 // 5x,
     *        27h final approximate solution // (5x, 5d15.7))
   80 format (12h1summary of , i3, 16h calls to lmdif1 /)
   90 format (49h nprob   n    m   nfev  njev  info  final l2 norm /)
  100 format (3i5, 3i6, 1x, d15.7)
c
c     last card of driver.
c
      end
      subroutine fcn(m,n,x,fvec,iflag)
      integer m,n,iflag
      double precision x(n),fvec(m)
c     **********
c
c     the calling sequence of fcn should be identical to the
c     calling sequence of the function subroutine in the nonlinear
c     least-squares solver. fcn should only call the testing
c     function subroutine ssqfcn with the appropriate value of
c     problem number (nprob).
c
c     subprograms called
c
c       minpack-supplied ... ssqfcn
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer nprob,nfev,njev
      common /refnum/ nprob,nfev,njev
      call ssqfcn(m,n,x,fvec,nprob)
      if (iflag .eq. 1) nfev = nfev + 1
      if (iflag .eq. 2) njev = njev + 1
      return
c
c     last card of interface subroutine fcn.
c
      end
