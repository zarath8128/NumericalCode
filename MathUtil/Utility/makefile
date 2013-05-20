include ../makefile.macro

OBJECTS= Align.o

util_target: test_c test_cpp

test_c: ${OBJECTS} test.c
	${CC} ${CFLAGS} test.c -o $@ ${OBJECTS} -I${MATH_UTIL}


test_cpp: ${OBJECTS} test.cpp BufferManager.hpp
	${CXX} ${CXXFLAGS} test.cpp -o $@ ${OBJECTS} -I${MATH_UTIL}

lib_target:
	cd ${LIBRARY} && ${MAKE}

cplx_target:
	cd ${COMPLEX} && ${MAKE}


