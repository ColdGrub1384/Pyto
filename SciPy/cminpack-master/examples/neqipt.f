      subroutine initpt(n,x,nprob,factor)
      integer n,nprob
      double precision factor
      double precision x(n)
c     **********
c
c     subroutine initpt
c
c     this subroutine specifies the standard starting points for
c     the functions defined by subroutine vecfcn. the subroutine
c     returns in x a multiple (factor) of the standard starting
c     point. for the sixth function the standard starting point is
c     zero, so in this case, if factor is not unity, then the
c     subroutine returns the vector  x(j) = factor, j=1,...,n.
c
c     the subroutine statement is
c
c       subroutine initpt(n,x,nprob,factor)
c
c     where
c
c       n is a positive integer input variable.
c
c       x is an output array of length n which contains the standard
c         starting point for problem nprob multiplied by factor.
c
c       nprob is a positive integer input variable which defines the
c         number of the problem. nprob must not exceed 14.
c
c       factor is an input variable which specifies the multiple of
c         the standard starting point. if factor is unity, no
c         multiplication is performed.
c
c     argonne national laboratory. minpack project. march 1980.
c     burton s. garbow, kenneth e. hillstrom, jorge j. more
c
c     **********
      integer ivar,j
      double precision c1,h,half,one,three,tj,zero
      double precision dfloat
      data zero,half,one,three,c1 /0.0d0,5.0d-1,1.0d0,3.0d0,1.2d0/
      dfloat(ivar) = ivar
c
c     selection of initial point.
c
      go to (10,20,30,40,50,60,80,100,120,120,140,160,180,180), nprob
c
c     rosenbrock function.
c
   10 continue
      x(1) = -c1
      x(2) = one
      go to 200
c
c     powell singular function.
c
   20 continue
      x(1) = three
      x(2) = -one
      x(3) = zero
      x(4) = one
      go to 200
c
c     powell badly scaled function.
c
   30 continue
      x(1) = zero
      x(2) = one
      go to 200
c
c     wood function.
c
   40 continue
      x(1) = -three
      x(2) = -one
      x(3) = -three
      x(4) = -one
      go to 200
c
c     helical valley function.
c
   50 continue
      x(1) = -one
      x(2) = zero
      x(3) = zero
      go to 200
c
c     watson function.
c
   60 continue
      do 70 j = 1, n
         x(j) = zero
   70    continue
      go to 200
c
c     chebyquad function.
c
   80 continue
      h = one/dfloat(n+1)
      do 90 j = 1, n
         x(j) = dfloat(j)*h
   90    continue
      go to 200
c
c     brown almost-linear function.
c
  100 continue
      do 110 j = 1, n
         x(j) = half
  110    continue
      go to 200
c
c     discrete boundary value and integral equation functions.
c
  120 continue
      h = one/dfloat(n+1)
      do 130 j = 1, n
         tj = dfloat(j)*h
         x(j) = tj*(tj - one)
  130    continue
      go to 200
c
c     trigonometric function.
c
  140 continue
      h = one/dfloat(n)
      do 150 j = 1, n
         x(j) = h
  150    continue
      go to 200
c
c     variably dimensioned function.
c
  160 continue
      h = one/dfloat(n)
      do 170 j = 1, n
         x(j) = one - dfloat(j)*h
  170    continue
      go to 200
c
c     broyden tridiagonal and banded functions.
c
  180 continue
      do 190 j = 1, n
         x(j) = -one
  190    continue
  200 continue
c
c     compute multiple of initial point.
c
      if (factor .eq. one) go to 250
      if (nprob .eq. 6) go to 220
         do 210 j = 1, n
            x(j) = factor*x(j)
  210       continue
         go to 240
  220 continue
         do 230 j = 1, n
            x(j) = factor
  230       continue
  240 continue
  250 continue
      return
c
c     last card of subroutine initpt.
c
      end
