.SUFFIXES:.d

TARGET= ${CURDIR}makefile
target= ctest.d cpptest.d

all:${addprefix ${DIR}, ${target}}

.c.d:
	${CC} -MM -o $@ $^ ${CFLAGS}
.cpp.d:
	${CXX} -MM -o $@ $^ ${CXXFLAGS}

include ${wildcard *.d}
