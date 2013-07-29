CC=icc
CXX=icpc

INCLUDEDIR+=-I../
CFLAGS+=-std=c99 ${INCLUDEDIR}
CXXFLAGS+=-std=c++0x ${INCLUDEDIR}

.c.o:
	${CC} -c ${CFLAGS} $<

.s.o:
	${CC} -c ${CFLAGS} $<

.h.c:
	@touch $@

HEADERFILES=
OBJECTS=EulerMethod.o ../Vector/Vector.o RKMethod.o RK3_8Method.o RKFMethod.o Error.o DPMethod.o I_EulerMethod.o HeunMethod.o

all	:test_c test_cpp
test_c	:test.c ${OBJECTS}
	${CC} ${CFLAGS} test.c -o $@ ${OBJECTS}

test_cpp:test.cpp ${OBJECTS}
	${CXX} ${CXXFLAGS} test.cpp -o $@ ${OBJECTS}

test.c	:${HEADERFILES}
	@touch $@
test.cpp:${HEADERFILES}
	@touch $@

../Vector/Vector.o:
