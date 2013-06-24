CC=gcc-4.7.3
CXX=g++-4.7.3

CFLAGS+=-std=c99
CXXFLAGS+=-std=c++0x

.c.o:
	${CC} -c ${CFLAGS} $<

.s.o:
	${CC} -c ${CFLAGS} $<

.h.c:
	@touch $@

HEADERFILES=AbstractVectorSpace.hpp NumericalVectorSpace.hpp UnrolledVectorD.hpp
OBJECTS=Vector.o VectorD.o UnrolledVectorD.o ../Utility/Align.o

all	:test_c test_cpp
test_c	:test.c ${OBJECTS}
	${CC} ${CFLAGS} test.c -o $@ -I.. ${OBJECTS}

test_cpp:test.cpp ${OBJECTS} 
	${CXX} ${CXXFLAGS} test.cpp -o $@ -I.. ${OBJECTS}

test.c	:${HEADERFILES}
	@touch $@
test.cpp:${HEADERFILES}
	@touch $@

../Utility/Align.o:
	
