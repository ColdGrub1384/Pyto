      subroutine initpt(n,x,nprob,factor)
      integer n,nprob
      double precision factor
      double precision x(n)
c     **********
c
c     subroutine initpt
c
c     this subroutine specifies the standard starting points for the
c     functions defined by subroutine ssqfcn. the subroutine returns
c     in x a multiple (factor) of the standard starting point. for
c     the 11th function the standard starting point is zero, so in
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
      double precision c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,
     *                 c15,c16,c17,five,h,half,one,seven,ten,three,
     *                 twenty,twntf,two,zero
      double precision dfloat
      data zero,half,one,two,three,five,seven,ten,twenty,twntf
     *     /0.0d0,5.0d-1,1.0d0,2.0d0,3.0d0,5.0d0,7.0d0,1.0d1,2.0d1,
     *      2.5d1/
      data c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17
     *     /1.2d0,2.5d-1,3.9d-1,4.15d-1,2.0d-2,4.0d3,2.5d2,3.0d-1,
     *      4.0d-1,1.5d0,1.0d-2,1.3d0,6.5d-1,7.0d-1,6.0d-1,4.5d0,
     *      5.5d0/
      dfloat(ivar) = ivar
c
c     selection of initial point.
c
      go to (10,10,10,30,40,50,60,70,80,90,100,120,130,140,150,170,
     *       190,200), nprob
c
c     linear function - full rank or rank 1.
c
   10 continue
      do 20 j = 1, n
         x(j) = one
   20    continue
      go to 210
c
c     rosenbrock function.
c
   30 continue
      x(1) = -c1
      x(2) = one
      go to 210
c
c     helical valley function.
c
   40 continue
      x(1) = -one
      x(2) = zero
      x(3) = zero
      go to 210
c
c     powell singular function.
c
   50 continue
      x(1) = three
      x(2) = -one
      x(3) = zero
      x(4) = one
      go to 210
c
c     freudenstein and roth function.
c
   60 continue
      x(1) = half
      x(2) = -two
      go to 210
c
c     bard function.
c
   70 continue
      x(1) = one
      x(2) = one
      x(3) = one
      go to 210
c
c     kowalik and osborne function.
c
   80 continue
      x(1) = c2
      x(2) = c3
      x(3) = c4
      x(4) = c3
      go to 210
c
c     meyer function.
c
   90 continue
      x(1) = c5
      x(2) = c6
      x(3) = c7
      go to 210
c
c     watson function.
c
  100 continue
      do 110 j = 1, n
         x(j) = zero
  110    continue
      go to 210
c
c     box 3-dimensional function.
c
  120 continue
      x(1) = zero
      x(2) = ten
      x(3) = twenty
      go to 210
c
c     jennrich and sampson function.
c
  130 continue
      x(1) = c8
      x(2) = c9
      go to 210
c
c     brown and dennis function.
c
  140 continue
      x(1) = twntf
      x(2) = five
      x(3) = -five
      x(4) = -one
      go to 210
c
c     chebyquad function.
c
  150 continue
      h = one/dfloat(n+1)
      do 160 j = 1, n
         x(j) = dfloat(j)*h
  160    continue
      go to 210
c
c     brown almost-linear function.
c
  170 continue
      do 180 j = 1, n
         x(j) = half
  180    continue
      go to 210
c
c     osborne 1 function.
c
  190 continue
      x(1) = half
      x(2) = c10
      x(3) = -one
      x(4) = c11
      x(5) = c5
      go to 210
c
c     osborne 2 function.
c
  200 continue
      x(1) = c12
      x(2) = c13
      x(3) = c13
      x(4) = c14
      x(5) = c15
      x(6) = three
      x(7) = five
      x(8) = seven
      x(9) = two
      x(10) = c16
      x(11) = c17
  210 continue
c
c     compute multiple of initial point.
c
      if (factor .eq. one) go to 260
      if (nprob .eq. 11) go to 230
         do 220 j = 1, n
            x(j) = factor*x(j)
  220       continue
         go to 250
  230 continue
         do 240 j = 1, n
            x(j) = factor
  240       continue
  250 continue
  260 continue
      return
c
c     last card of subroutine initpt.
c
      end
