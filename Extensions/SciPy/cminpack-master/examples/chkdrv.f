c     **********
c
c     this program tests the ability of chkder to detect
c     inconsistencies between functions and their first derivatives.
c     fourteen test function vectors and jacobians are used. eleven of
c     the tests are false(f), i.e. there are inconsistencies between
c     the function vectors and the corresponding jacobians. three of
c     the tests are true(t), i.e. there are no inconsistencies. the
c     driver reads in data, calls chkder and prints out information
c     required by and received from chkder.
c
c     subprograms called
c
c       minpack supplied ... chkder,errjac,initpt,vecfcn
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer i,ldfjac,lnp,mode,n,nprob,nread,nwrite
      integer na(14),np(14)
      logical a(14)
      double precision cp,one
      double precision diff(10),err(10),errmax(14),errmin(14),
     *                 fjac(10,10),fvec1(10),fvec2(10),x1(10),x2(10)
c
c     logical input unit is assumed to be number 5.
c     logical output unit is assumed to be number 6.
c
      data nread,nwrite /5,6/
c
      data a(1),a(2),a(3),a(4),a(5),a(6),a(7),a(8),a(9),a(10),a(11),
     *     a(12),a(13),a(14)
     *     /.false.,.false.,.false.,.true.,.false.,.false.,.false.,
     *      .true.,.false.,.false.,.false.,.false.,.true.,.false./
      data cp,one /1.23d-1,1.0d0/
      ldfjac = 10
   10 continue
         read (nread,60) nprob,n
         if (nprob .le. 0) go to 40
         call initpt(n,x1,nprob,one)
         do 20 i = 1, n
            x1(i) = x1(i) + cp
            cp = -cp
   20       continue
         write (nwrite,70) nprob,n,a(nprob)
         mode = 1
         call chkder(n,n,x1,fvec1,fjac,ldfjac,x2,fvec2,mode,err)
         mode = 2
         call vecfcn(n,x1,fvec1,nprob)
         call errjac(n,x1,fjac,ldfjac,nprob)
         call vecfcn(n,x2,fvec2,nprob)
         call chkder(n,n,x1,fvec1,fjac,ldfjac,x2,fvec2,mode,err)
         errmin(nprob) = err(1)
         errmax(nprob) = err(1)
         do 30 i = 1, n
            diff(i) = fvec2(i) - fvec1(i)
            if (errmin(nprob) .gt. err(i)) errmin(nprob) = err(i)
            if (errmax(nprob) .lt. err(i)) errmax(nprob) = err(i)
   30       continue
         np(nprob) = nprob
         lnp = nprob
         na(nprob) = n
         write (nwrite,80) (fvec1(i), i = 1, n)
         write (nwrite,90) (diff(i), i = 1, n)
         write (nwrite,100) (err(i), i = 1, n)
         go to 10
   40 continue
      write (nwrite,110) lnp
      write (nwrite,120)
      do 50 i = 1, lnp
         write (nwrite,130) np(i),na(i),a(i),errmin(i),errmax(i)
   50    continue
      stop
   60 format (2i5)
   70 format ( /// 5x, 8h problem, i5, 5x, 15h with dimension, i5, 2x,
     *         5h is  , l1)
   80 format ( // 5x, 25h first function vector    // (5x, 5d15.7))
   90 format ( // 5x, 27h function difference vector // (5x, 5d15.7))
  100 format ( // 5x, 13h error vector // (5x, 5d15.7))
  110 format (12h1summary of , i3, 16h tests of chkder /)
  120 format (46h nprob   n    status     errmin         errmax /)
  130 format (i4, i6, 6x, l1, 3x, 2d15.7)
c
c     last card of derivative check test driver.
c
      end
