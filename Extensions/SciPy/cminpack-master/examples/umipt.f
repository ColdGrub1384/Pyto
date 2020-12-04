      subroutine initpt(n,x,nprob,factor)
      integer n,nprob
      double precision factor
      double precision x(n)
c     **********
c
c     subroutine initpt
c
c     this subroutine specifies the standard starting points for the
c     functions defined by subroutine objfcn. the subroutine returns
c     in x a multiple (factor) of the standard starting point. for
c     the seventh function the standard starting point is zero, so in
c     this case, if factor is not unity, then the subroutine returns
c     the vector  x(j) = factor, j=1,...,n.
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
c         number of the problem. nprob must not exceed 18.
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
      double precision c1,c2,c3,c4,five,h,half,one,ten,three,twenty,
     *                 twntf,two,zero
      double precision dfloat
      data zero,half,one,two,three,five,ten,twenty,twntf
     *     /0.0d0,0.5d0,1.0d0,2.0d0,3.0d0,5.0d0,1.0d1,2.0d1,2.5d1/
      data c1,c2,c3,c4 /4.0d-1,2.5d0,1.5d-1,1.2d0/
      dfloat(ivar) = ivar
c
c     selection of initial point.
c
      go to (10,20,30,40,50,60,80,100,120,140,150,160,170,190,210,230,
     *       240,250), nprob
c
c     helical valley function.
c
   10 continue
      x(1) = -one
      x(2) = zero
      x(3) = zero
      go to 270
c
c     biggs exp6 function.
c
   20 continue
      x(1) = one
      x(2) = two
      x(3) = one
      x(4) = one
      x(5) = one
      x(6) = one
      go to 270
c
c     gaussian function.
c
   30 continue
      x(1) = c1
      x(2) = one
      x(3) = zero
      go to 270
c
c     powell badly scaled function.
c
   40 continue
      x(1) = zero
      x(2) = one
      go to 270
c
c     box 3-dimensional function.
c
   50 continue
      x(1) = zero
      x(2) = ten
      x(3) = twenty
      go to 270
c
c     variably dimensioned function.
c
   60 continue
      h = one/dfloat(n)
      do 70 j = 1, n
         x(j) = one - dfloat(j)*h
   70    continue
      go to 270
c
c     watson function.
c
   80 continue
      do 90 j = 1, n
         x(j) = zero
   90    continue
      go to 270
c
c     penalty function i.
c
  100 continue
      do 110 j = 1, n
         x(j) = dfloat(j)
  110    continue
      go to 270
c
c     penalty function ii.
c
  120 continue
      do 130 j = 1, n
         x(j) = half
  130    continue
      go to 270
c
c     brown badly scaled function.
c
  140 continue
      x(1) = one
      x(2) = one
      go to 270
c
c     brown and dennis function.
c
  150 continue
      x(1) = twntf
      x(2) = five
      x(3) = -five
      x(4) = -one
      go to 270
c
c     gulf research and development function.
c
  160 continue
      x(1) = five
      x(2) = c2
      x(3) = c3
      go to 270
c
c     trigonometric function.
c
  170 continue
      h = one/dfloat(n)
      do 180 j = 1, n
         x(j) = h
  180    continue
      go to 270
c
c     extended rosenbrock function.
c
  190 continue
      do 200 j = 1, n, 2
         x(j) = -c4
         x(j+1) = one
  200    continue
      go to 270
c
c     extended powell singular function.
c
  210 continue
      do 220 j = 1, n, 4
         x(j) = three
         x(j+1) = -one
         x(j+2) = zero
         x(j+3) = one
  220    continue
      go to 270
c
c     beale function.
c
  230 continue
      x(1) = one
      x(2) = one
      go to 270
c
c     wood function.
c
  240 continue
      x(1) = -three
      x(2) = -one
      x(3) = -three
      x(4) = -one
      go to 270
c
c     chebyquad function.
c
  250 continue
      h = one/dfloat(n+1)
      do 260 j = 1, n
         x(j) = dfloat(j)*h
  260    continue
  270 continue
c
c     compute multiple of initial point.
c
      if (factor .eq. one) go to 320
      if (nprob .eq. 7) go to 290
         do 280 j = 1, n
            x(j) = factor*x(j)
  280       continue
         go to 310
  290 continue
         do 300 j = 1, n
            x(j) = factor
  300       continue
  310 continue
  320 continue
      return
c
c     last card of subroutine initpt.
c
      end
