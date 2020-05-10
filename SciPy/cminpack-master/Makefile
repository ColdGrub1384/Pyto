PACKAGE=cminpack
VERSION=1.3.7

CC=gcc
CFLAGS= -O3 -g -Wall -Wextra

### The default configuration is to compile the double precision version

### configuration for the LAPACK/BLAS (double precision) version:
## make LIBSUFFIX= CFLAGS="-O3 -g -Wall -Wextra -D__cminpack_float__"
#LIBSUFFIX=s
#CFLAGS="-O3 -g -Wall -Wextra -DUSE_CBLAS -DUSE_LAPACK"
CFLAGS_L=$(CFLAGS) -DUSE_CBLAS -DUSE_LAPACK
LDADD_L=-framework Accelerate

### configuration for the long double version:
## make LIBSUFFIX=s CFLAGS="-O3 -g -Wall -Wextra -D__cminpack_long_double__"
#LIBSUFFIX=s
#CFLAGS="-O3 -g -Wall -Wextra -D__cminpack_long_double__"
CFLAGS_LD=$(CFLAGS) -D__cminpack_long_double__

### configuration for the float (single precision) version:
## make LIBSUFFIX=s CFLAGS="-O3 -g -Wall -Wextra -D__cminpack_float__"
#LIBSUFFIX=s
#CFLAGS="-O3 -g -Wall -Wextra -D__cminpack_float__"
CFLAGS_F=$(CFLAGS) -D__cminpack_float__

### configuration for the half (half precision) version:
## make LIBSUFFIX=h CFLAGS="-O3 -g -Wall -Wextra -I/opt/local/include -D__cminpack_half__" LDADD="-L/opt/local/lib -lHalf" CC=g++
#LIBSUFFIX=h
#CFLAGS="-O3 -g -Wall -Wextra -I/opt/local/include -D__cminpack_half__"
#LDADD="-L/opt/local/lib -lHalf"
#CC=g++
CFLAGS_H=$(CFLAGS) -I/opt/local/include -D__cminpack_half__
LDADD_H=-L/opt/local/lib -lHalf
CC_H=$(CXX)

RANLIB=ranlib

LIB=libcminpack$(LIBSUFFIX).a

OBJS = \
$(LIBSUFFIX)chkder.o  $(LIBSUFFIX)enorm.o   $(LIBSUFFIX)hybrd1.o  $(LIBSUFFIX)hybrj.o  \
$(LIBSUFFIX)lmdif1.o  $(LIBSUFFIX)lmstr1.o  $(LIBSUFFIX)qrfac.o   $(LIBSUFFIX)r1updt.o \
$(LIBSUFFIX)dogleg.o  $(LIBSUFFIX)fdjac1.o  $(LIBSUFFIX)hybrd.o   $(LIBSUFFIX)lmder1.o \
$(LIBSUFFIX)lmdif.o   $(LIBSUFFIX)lmstr.o   $(LIBSUFFIX)qrsolv.o  $(LIBSUFFIX)rwupdt.o \
$(LIBSUFFIX)dpmpar.o  $(LIBSUFFIX)fdjac2.o  $(LIBSUFFIX)hybrj1.o  $(LIBSUFFIX)lmder.o \
$(LIBSUFFIX)lmpar.o   $(LIBSUFFIX)qform.o   $(LIBSUFFIX)r1mpyq.o  $(LIBSUFFIX)covar.o $(LIBSUFFIX)covar1.o \
$(LIBSUFFIX)chkder_.o $(LIBSUFFIX)enorm_.o  $(LIBSUFFIX)hybrd1_.o $(LIBSUFFIX)hybrj_.o \
$(LIBSUFFIX)lmdif1_.o $(LIBSUFFIX)lmstr1_.o $(LIBSUFFIX)qrfac_.o  $(LIBSUFFIX)r1updt_.o \
$(LIBSUFFIX)dogleg_.o $(LIBSUFFIX)fdjac1_.o $(LIBSUFFIX)hybrd_.o  $(LIBSUFFIX)lmder1_.o \
$(LIBSUFFIX)lmdif_.o  $(LIBSUFFIX)lmstr_.o  $(LIBSUFFIX)qrsolv_.o $(LIBSUFFIX)rwupdt_.o \
$(LIBSUFFIX)dpmpar_.o $(LIBSUFFIX)fdjac2_.o $(LIBSUFFIX)hybrj1_.o $(LIBSUFFIX)lmder_.o \
$(LIBSUFFIX)lmpar_.o  $(LIBSUFFIX)qform_.o  $(LIBSUFFIX)r1mpyq_.o $(LIBSUFFIX)covar_.o

# target dir for install
DESTDIR=/usr/local
#
#  Static library target
#

all: $(LIB)

double:
	$(MAKE) LIBSUFFIX=

lapack:
	$(MAKE) LIBSUFFIX=l CFLAGS="$(CFLAGS_L)" LDADD="$(LDADD_L)"

longdouble:
	$(MAKE) LIBSUFFIX=ld CFLAGS="$(CFLAGS_LD)"

float:
	$(MAKE) LIBSUFFIX=s CFLAGS="$(CFLAGS_F)"

half:
	$(MAKE) LIBSUFFIX=h CFLAGS="$(CFLAGS_H)" LDADD="$(LDADD_H)" CC="$(CC_H)"

fortran cuda:
	$(MAKE) -C $@

check checkdouble checklapack checklongdouble checkfloat checkhalf checkfail:
	$(MAKE) -C examples $@

$(LIB):  $(OBJS)
	$(AR) r $@ $(OBJS); $(RANLIB) $@

$(LIBSUFFIX)%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

install: $(LIB)
	cp $(LIB) ${DESTDIR}/lib
	chmod 644 ${DESTDIR}/lib/$(LIB)
	$(RANLIB) -t ${DESTDIR}/lib/$(LIB) # might be unnecessary
	cp minpack.h ${DESTDIR}/include
	chmod 644 ${DESTDIR}/include/minpack.h
	cp cminpack.h ${DESTDIR}/include
	chmod 644 ${DESTDIR}/include/cminpack.h

clean:
	rm -f $(OBJS) $(LIB)
	$(MAKE) -C examples clean
	$(MAKE) -C fortran clean

veryclean: clean
	rm -f *.o libcminpack*.a *.gcno *.gcda *~ #*#
	$(MAKE) -C examples veryclean
	$(MAKE) -C examples veryclean LIBSUFFIX=s
	$(MAKE) -C examples veryclean LIBSUFFIX=h
	$(MAKE) -C examples veryclean LIBSUFFIX=l
	$(MAKE) -C fortran veryclean

.PHONY: dist all double lapack longdouble float half fortran cuda check checkhalf checkfail clean veryclean

# COPYFILE_DISABLE=true and COPY_EXTENDED_ATTRIBUTES_DISABLE=true are used to disable inclusion
# of file attributes (._* files) in the tar file on MacOSX
dist:
	mkdir $(PACKAGE)-$(VERSION)
	env COPYFILE_DISABLE=true COPY_EXTENDED_ATTRIBUTES_DISABLE=true tar --exclude-from dist-exclude --exclude $(PACKAGE)-$(VERSION) -cf - . | (cd $(PACKAGE)-$(VERSION); tar xf -)
	tar zcvf $(PACKAGE)-$(VERSION).tar.gz $(PACKAGE)-$(VERSION)
	rm -rf $(PACKAGE)-$(VERSION)
