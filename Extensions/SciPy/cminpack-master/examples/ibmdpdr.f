c     **********
c
c     this program checks the constants of machine precision and
c     smallest and largest machine representable numbers specified in
c     function dpmpar, against the corresponding hardware-determined
c     machine constants obtained by machar, a subroutine due to
c     w. j. cody.
c
c     data statements in dpmpar corresponding to the machine used must
c     be activated by removing c in column 1.
c
c     the printed output consists of the machine constants obtained by
c     machar and comparisons of the dpmpar constants with their
c     machar counterparts. descriptions of the machine constants are
c     given in the prologue comments of machar.
c
c     subprograms called
c
c       minpack-supplied ... machar,dpmpar
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer ibeta,iexp,irnd,it,machep,maxexp,minexp,negep,ngrd,
     *        nwrite
      double precision dwarf,eps,epsmch,epsneg,giant,xmax,xmin
      double precision rerr(3)
      double precision dpmpar
c
c     logical output unit is assumed to be number 6.
c
      data nwrite /6/
c
c     determine the machine constants dynamically from machar.
c
      call machar(ibeta,it,irnd,ngrd,machep,negep,iexp,minexp,maxexp,
     *            eps,epsneg,xmin,xmax)
c
c     compare the dpmpar constants with their machar counterparts and
c     store the relative differences in rerr.
c
      epsmch = dpmpar(1)
      dwarf = dpmpar(2)
      giant = dpmpar(3)
      rerr(1) = (epsmch - eps)/epsmch
      rerr(2) = (dwarf - xmin)/dwarf
      rerr(3) = (xmax - giant)/giant
c
c     write the machar constants.
c
      write (nwrite,10)
     *      ibeta,it,irnd,ngrd,machep,negep,iexp,minexp,maxexp,eps,
     *      epsneg,xmin,xmax
c
c     write the dpmpar constants and the relative differences.
c
      write (nwrite,20) epsmch,rerr(1),dwarf,rerr(2),giant,rerr(3)
      stop
   10 format (17h1MACHAR constants /// 8h ibeta =, i6 // 8h it    =,
     *        i6 // 8h irnd  =, i6 // 8h ngrd  =, i6 // 9h machep =,
     *        i6 // 8h negep =, i6 // 7h iexp =, i6 // 9h minexp =,
     *        i6 // 9h maxexp =, i6 // 6h eps =, d15.7 // 9h epsneg =,
     *        d15.7 // 7h xmin =, d15.7 // 7h xmax =, d15.7)
   20 format ( /// 42h dpmpar constants and relative differences ///
     *         9h epsmch =, d15.7 / 10h rerr(1) =, d15.7 //
     *         8h dwarf =, d15.7 / 10h rerr(2) =, d15.7 // 8h giant =,
     *         d15.7 / 10h rerr(3) =, d15.7)
c
c     last card of driver.
c
      end
