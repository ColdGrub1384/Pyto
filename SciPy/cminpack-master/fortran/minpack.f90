
module minpack

! F90 interface to minpack

  implicit none

  ! set to .true. for debug prints
  logical, parameter, private :: dbg = .true.

  ! precision for double real
  integer, parameter, private :: r8 = selected_real_kind(15)

  interface

     subroutine chkder(m,n,x,fvec,fjac,ldfjac,xp,fvecp,mode,err)
       integer, parameter :: r8 = selected_real_kind(15)
       integer, intent(in) :: m,n,ldfjac,mode
       real(r8) :: x(n),fvec(m),fjac(ldfjac,n),xp(n),fvecp(m),err(m)
     end subroutine chkder

     subroutine covar(n,r,ldr,ipvt,tol,wa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer, intent(in) ::  n,ldr
       integer::  ipvt(n)
       real(r8) :: tol
       real(r8) :: r(ldr,n),wa(n)
     end subroutine covar

     subroutine dmchar(ibeta,it,irnd,ngrd,machep,negep,iexp,minexp, &
          maxexp,eps,epsneg,xmin,xmax)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: i,ibeta,iexp,irnd,it,iz,j,k,machep,maxexp,minexp, &
            mx,negep,ngrd
       real(r8) :: a,b,beta,betain,betam1,eps,epsneg,one,xmax, &
            xmin,y,z,zero
     end subroutine dmchar

     subroutine dogleg(n,r,lr,diag,qtb,delta,x,wa1,wa2)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,lr
       real(r8) :: delta
       real(r8) :: r(lr),diag(n),qtb(n),x(n),wa1(n),wa2(n)
     end subroutine dogleg

     function dpmpar(i)
       integer, parameter :: r8 = selected_real_kind(15)
       real(r8) :: dpmpar
       integer, intent(in) :: i
     end function dpmpar
     
     function enorm(n,x)
       integer, parameter :: r8 = selected_real_kind(15)
       integer, intent(in) :: n
       real(r8) :: enorm,x(n)
     end function enorm

     subroutine errjac(n,x,fjac,ldfjac,nprob)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldfjac,nprob
       real(r8) :: x(n),fjac(ldfjac,n)
     end subroutine errjac

     subroutine fdjac1(fcn,n,x,fvec,fjac,ldfjac,iflag,ml,mu,epsfcn,wa1,wa2)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldfjac,iflag,ml,mu
       real(r8) :: epsfcn
       real(r8) :: x(n),fvec(n),fjac(ldfjac,n),wa1(n),wa2(n)
       interface
          subroutine fcn(n,x,fvec,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: n,iflag
            real(r8) :: x(n),fvec(n)
          end subroutine fcn
       end interface
     end subroutine fdjac1

     subroutine fdjac2(fcn,m,n,x,fvec,fjac,ldfjac,iflag,epsfcn,wa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,ldfjac,iflag
       real(r8) :: epsfcn
       real(r8) :: x(n),fvec(m),fjac(ldfjac,n),wa(m)
       interface
          subroutine fcn(m,n,x,fvec,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: m,n,iflag
            real(r8) :: x(n),fvec(m)
          end subroutine fcn
       end interface
     end subroutine fdjac2

     subroutine grdfcn(n,x,g,nprob)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,nprob
       real(r8) :: x(n),g(n)
     end subroutine grdfcn

     subroutine hesfcn(n,x,h,ldh,nprob)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldh,nprob
       real(r8) :: x(n),h(ldh,n)
     end subroutine hesfcn

     subroutine initpt(n,x,nprob,factor)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,nprob
       real(r8) :: factor
       real(r8) :: x(n)
     end subroutine initpt

     subroutine hybrd(fcn,n,x,fvec,xtol,maxfev,ml,mu,epsfcn,diag, &
          mode,factor,nprint,info,nfev,fjac,ldfjac,r,lr, &
          qtf,wa1,wa2,wa3,wa4)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,maxfev,ml,mu,mode,nprint,info,nfev,ldfjac,lr
       real(r8) :: xtol,epsfcn,factor
       real(r8) :: x(n),fvec(n),diag(n),fjac(ldfjac,n),r(lr), &
            qtf(n),wa1(n),wa2(n),wa3(n),wa4(n)
       interface
          subroutine fcn(n,x,fvec,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: n,iflag
            real(r8) :: x(n),fvec(n)
          end subroutine fcn
       end interface
     end subroutine hybrd

     subroutine hybrd1(fcn,n,x,fvec,tol,info,wa,lwa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,info,lwa
       real(r8) :: tol
       real(r8) :: x(n),fvec(n),wa(lwa)
       interface
          subroutine fcn(n,x,fvec,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: n,iflag
            real(r8) :: x(n),fvec(n)
          end subroutine fcn
       end interface
     end subroutine hybrd1

     subroutine hybrj(fcn,n,x,fvec,fjac,ldfjac,xtol,maxfev,diag,mode, &
          factor,nprint,info,nfev,njev,r,lr,qtf,wa1,wa2, &
          wa3,wa4)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldfjac,maxfev,mode,nprint,info,nfev,njev,lr
       real(r8) :: xtol,factor
       real(r8) :: x(n),fvec(n),fjac(ldfjac,n),diag(n),r(lr), &
            qtf(n),wa1(n),wa2(n),wa3(n),wa4(n)
       interface
          subroutine fcn(n,x,fvec,fjac,ldfjac,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: n,ldfjac,iflag
            real(r8) :: x(n),fvec(n),fjac(ldfjac,n)
          end subroutine fcn
       end interface
     end subroutine hybrj

     subroutine hybrj1(fcn,n,x,fvec,fjac,ldfjac,tol,info,wa,lwa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldfjac,info,lwa
       real(r8) :: tol
       real(r8) :: x(n),fvec(n),fjac(ldfjac,n),wa(lwa)
       interface
          subroutine fcn(n,x,fvec,fjac,ldfjac,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: n,ldfjac,iflag
            real(r8) :: x(n),fvec(n),fjac(ldfjac,n)
          end subroutine fcn
       end interface
     end subroutine hybrj1
     
     subroutine lmder(fcn,m,n,x,fvec,fjac,ldfjac,ftol,xtol,gtol, &
          maxfev,diag,mode,factor,nprint,info,nfev,njev, &
          ipvt,qtf,wa1,wa2,wa3,wa4)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,ldfjac,maxfev,mode,nprint,info,nfev,njev
       integer :: ipvt(n)
       real(r8) :: ftol,xtol,gtol,factor
       real(r8) :: x(n),fvec(m),fjac(ldfjac,n),diag(n),qtf(n), &
            wa1(n),wa2(n),wa3(n),wa4(m)
       interface
          subroutine fcn(m,n,x,fvec,fjac,ldfjac,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: m,n,ldfjac,iflag
            real(r8) :: x(n),fvec(m),fjac(ldfjac,n)
          end subroutine fcn
       end interface
     end subroutine lmder

     subroutine lmder1(fcn,m,n,x,fvec,fjac,ldfjac,tol,info,ipvt,wa,lwa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,ldfjac,info,lwa
       integer :: ipvt(n)
       real(r8) :: tol
       real(r8) :: x(n),fvec(m),fjac(ldfjac,n),wa(lwa)
       interface
          subroutine fcn(m,n,x,fvec,fjac,ldfjac,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: m,n,ldfjac,iflag
            real(r8) :: x(n),fvec(m),fjac(ldfjac,n)
          end subroutine fcn
       end interface
     end subroutine lmder1
 
     subroutine lmdif(fcn,m,n,x,fvec,ftol,xtol,gtol,maxfev,epsfcn, &
          diag,mode,factor,nprint,info,nfev,fjac,ldfjac, &
          ipvt,qtf,wa1,wa2,wa3,wa4)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,maxfev,mode,nprint,info,nfev,ldfjac
       integer :: ipvt(n)
       real(r8) :: ftol,xtol,gtol,epsfcn,factor
       real(r8) :: x(n),fvec(m),diag(n),fjac(ldfjac,n),qtf(n), &
            wa1(n),wa2(n),wa3(n),wa4(m)
       interface
          subroutine fcn(m,n,x,fvec,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: m,n,iflag
            real(r8) :: x(n),fvec(m)
          end subroutine fcn
       end interface
     end subroutine lmdif

     subroutine lmdif1(fcn,m,n,x,fvec,tol,info,iwa,wa,lwa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,info,lwa
       integer :: iwa(n)
       real(r8) :: tol
       real(r8) :: x(n),fvec(m),wa(lwa)
       interface
          subroutine fcn(m,n,x,fvec,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: m,n,iflag
            real(r8) :: x(n),fvec(m)
          end subroutine fcn
       end interface
     end subroutine lmdif1
     
     subroutine lmpar(n,r,ldr,ipvt,diag,qtb,delta,par,x,sdiag,wa1,wa2)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldr
       integer :: ipvt(n)
       real(r8) :: delta,par
       real(r8) :: r(ldr,n),diag(n),qtb(n),x(n),sdiag(n),wa1(n),wa2(n)
     end subroutine lmpar

     subroutine lmstr(fcn,m,n,x,fvec,fjac,ldfjac,ftol,xtol,gtol, &
          maxfev,diag,mode,factor,nprint,info,nfev,njev, &
          ipvt,qtf,wa1,wa2,wa3,wa4)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,ldfjac,maxfev,mode,nprint,info,nfev,njev
       integer :: ipvt(n)
       logical :: sing
       real(r8) :: ftol,xtol,gtol,factor
       real(r8) :: x(n),fvec(m),fjac(ldfjac,n),diag(n),qtf(n), &
            wa1(n),wa2(n),wa3(n),wa4(m)
       interface
          subroutine fcn(m,n,x,fvec,fjrow,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer :: m,n,iflag
            real(r8) :: x(n),fvec(m),fjrow(n)
          end subroutine fcn
       end interface
     end subroutine lmstr

     subroutine lmstr1(fcn,m,n,x,fvec,fjac,ldfjac,tol,info,ipvt,wa,lwa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,ldfjac,info,lwa
       integer :: ipvt(n)
       real(r8) :: tol
       real(r8) :: x(n),fvec(m),fjac(ldfjac,n),wa(lwa)
       interface
          subroutine fcn(m,n,x,fvec,fjrow,iflag)
            integer, parameter :: r8 = selected_real_kind(15)
            integer m,n,iflag
            real(r8) x(n),fvec(m),fjrow(n)
          end subroutine fcn
       end interface
     end subroutine lmstr1

     subroutine objfcn(n,x,f,nprob)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,nprob
       real(r8) :: f
       real(r8) :: x(n)
     end subroutine objfcn

     subroutine qform(m,n,q,ldq,wa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,ldq
       real(r8) :: q(ldq,m),wa(m)
     end subroutine qform

     subroutine qrfac(m,n,a,lda,pivot,ipvt,lipvt,rdiag,acnorm,wa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,lda,lipvt
       integer :: ipvt(lipvt)
       logical :: pivot
       real(r8) :: a(lda,n),rdiag(n),acnorm(n),wa(n)
     end subroutine qrfac

     subroutine qrsolv(n,r,ldr,ipvt,diag,qtb,x,sdiag,wa)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldr
       integer :: ipvt(n)
       real(r8) :: r(ldr,n),diag(n),qtb(n),x(n),sdiag(n),wa(n)
     end subroutine qrsolv

     subroutine r1mpyq(m,n,a,lda,v,w)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,lda
       real(r8) :: a(lda,n),v(n),w(n)
     end subroutine r1mpyq

     subroutine r1updt(m,n,s,ls,u,v,w,sing)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,ls
       logical :: sing
       real(r8) :: s(ls),u(m),v(n),w(m)
     end subroutine r1updt

     subroutine rwupdt(n,r,ldr,w,b,alpha,cos,sin)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldr
       real(r8) :: alpha
       real(r8) :: r(ldr,n),w(n),b(n),cos(n),sin(n)
     end subroutine rwupdt

     subroutine ssqfcn(m,n,x,fvec,nprob)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,nprob
       real(r8) :: x(n),fvec(m)
     end subroutine ssqfcn

     subroutine ssqjac(m,n,x,fjac,ldfjac,nprob)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: m,n,ldfjac,nprob
       real(r8) :: x(n),fjac(ldfjac,n)
     end subroutine ssqjac

     subroutine vecfcn(n,x,fvec,nprob)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,nprob
       real(r8) :: x(n),fvec(n)
     end subroutine vecfcn

     subroutine vecjac(n,x,fjac,ldfjac,nprob)
       integer, parameter :: r8 = selected_real_kind(15)
       integer :: n,ldfjac,nprob
       real(r8) :: x(n),fjac(ldfjac,n)
     end subroutine vecjac

  end interface


contains

  !----------------------------------------------------------------------
  !
  ! add-ons 
  !
  !----------------------------------------------------------------------

    subroutine qrinv(m,n,a,a1,lda,diag)

      ! compute inverse matrix in least-quare sense by the use
      ! of the QR factorisation

      ! implementation is reference, no effective, test for different
      ! m and n are sparse
      
      implicit none

      integer :: m,n,lda
      real(r8) :: a(lda,n),a1(lda,n), diag(n)
      real(r8) :: r(m,n), q(m,n), qtb(m,n)
      integer :: i,ipvt(n)
      real(r8) :: rdiag(n),acnorm(n),wa(n),x(n),b(n),sdiag(n)
      character(len=10) :: fmt = '(xxf17.7)'

      if(dbg) then
         write(*,*) 'qrinv:'
         write(fmt(2:3),'(i2.2)') n
         write(*,fmt) a
      endif

      ! form the r matrix, r is upper trinagle (without diagonal)
      ! of the factorized a, diagonal is presented in rdiag 

      call qrfac(m,n,a,lda,.true.,ipvt,n,rdiag,acnorm,wa)
      if(dbg) then
         write(*,*) 'qrfac:'
         write(*,fmt) a,rdiag,acnorm
      end if

      r = a
      do i = 1, n
         r(i,i) = rdiag(i)
      end do

      if(dbg) then
         write(*,*) 'r:'
         write(*,fmt) r
      endif

    ! form the q matrix 

      call qform(m,n,a,lda,wa)

      if(dbg) then 
         write(*,*) 'qform:'
         write(*,fmt) a,rdiag,acnorm
         write(*,*) 'ipvt:'
         write(*,*) ipvt
      end if
    
      q = a
      qtb = transpose(q)
      do i = 1, n
         b = 0
         b(i) = 1.0
         b = matmul(qtb,b)
         call qrsolv(n,r,m,ipvt,diag,b,x,sdiag,wa)
         a1(i,:) = x
      enddo

    end subroutine qrinv


  !---------------------------------------------------------------------
  !
  ! Fortran 90 interfaces
  !
  !---------------------------------------------------------------------

!    subroutine chkder_8(x,fvec,fjac,xp,fvecp,mode,err)
!      integer, intent(in) :: mode
!      real(r8) :: x(:),fvec(:),fjac(:,:),xp(:),fvecp(:),err(:)
!      integer :: m,n,ldfjac
!      
!      m = size(fvec)
!      n = size(x)
!      ldfjac = size(fjac,1)
!      
!      call chkder(m,n,x,fvec,fjac,ldfjac,xp,fvecp,mode,err)
!    end subroutine chkder_8

  

end module minpack
