#!/usr/bin/make 

# pick up your FORTRAN compiler
#F77=g77
F77=gfortran
FFLAGS=-O3
# uncomment the following for FORTRAN MINPACK
#MINPACK=-lminpack
#F77C=$(F77)
#F77CFLAGS=-g

RANLIB=ranlib

LIB=libminpack.a

OBJS = \
chkder.o  enorm.o   hybrd1.o  hybrj.o   lmdif1.o  lmstr1.o  qrfac.o   r1updt.o \
dogleg.o  fdjac1.o  hybrd.o   lmder1.o  lmdif.o   lmstr.o   qrsolv.o  rwupdt.o \
dpmpar.o  fdjac2.o  hybrj1.o  lmder.o   lmpar.o   qform.o   r1mpyq.o  covar.o

# target dir for install
DESTDIR=/usr/local
#
#  Static library target
#
.PHONY: all clean veryclean install

all: $(LIB)

$(LIB):  $(OBJS)
	$(AR) r $@ $^
	$(RANLIB) $@

%.o: %.f
	${F77} ${FFLAGS} -c -o $@ $<

install: $(LIB)
	cp $(LIB) ${DESTDIR}/lib
	chmod 644 ${DESTDIR}/lib/$(LIB)
	$(RANLIB) -t ${DESTDIR}/lib/$(LIB) # might be unnecessary

clean:
	rm -f $(OBJS) $(LIB)

veryclean: clean
	rm -f *.o *.gcno *.gcda *~ #*#
