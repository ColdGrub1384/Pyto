
SOURCES = $(wildcard t*.cu)
TEST_PROGRAMS = $(SOURCES:.cu=)

CC=nvcc
CFLAGS=  -I.. -I../..

all:
	@echo    make cudatest, make clean
	@echo $(TEST_PROGRAMS)


cudatest: clean $(TEST_PROGRAMS)

%:%.cu
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o run.* $(TEST_PROGRAMS)
