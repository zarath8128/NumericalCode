include ../makefile.macro


OBJECTS=Complex.o

cplx_target:test_c test_cpp

test_c:${OBJECTS}
	${CC} test.c -o $@ ${OBJECTS} -I${MATH_UTIL}

test_cpp:${OBJECTS} util_target
	${CXX} test.cpp -o $@ ${OBJECTS} -I${MATH_UTIL} ${UTILITY}/Align.o


util_target:
	cd ${UTILITY} && ${MAKE}

lib_target:
	cd ${LIBRARY} && ${MAKE}

