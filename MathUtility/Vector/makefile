CC=gcc-4.7.3
CXX=g++-4.7.3

CFLAGS+=-std=c99
CXXFLAGS+=-std=c++0x

HEADERFILES=AbstractVectorSpace.hpp NumericalVectorSpace.hpp UnrolledVectorD.hpp

all	:test_c test_cpp
test_c	:test.c VectorD.s UnrolledVectorD.s
	${CC} ${CFLAGS} test.c VectorD.s UnrolledVectorD.s -o $@ -I.. ../Utility/Align.o

test_cpp:test.cpp VectorD.s
	${CXX} ${CXXFLAGS} test.cpp VectorD.s -o $@ -I.. ../Utility/Align.o

test.c	:${HEADERFILES}
	@touch $@
test.cpp:${HEADERFILES}
	@touch $@
