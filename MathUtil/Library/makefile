include ../makefile.macro

OBJECTS = MathLib.o distance2.o distance4.o xorshift128.o

lib_target: test_c test_cpp

test_c: ${OBJECTS}
	${CC} test.c -o $@ ${OBJECTS} -I${MATH_UTIL}


test_cpp: ${OBJECTS} util_target
	${CXX} test.cpp -o $@ ${OBJECTS} ${UTILITY}/Align.o -I${MATH_UTIL}


util_target:
	cd ${UTILITY} && ${MAKE}

cplx_target:
	cd ${COMPLEX} && ${MAKE}

MathLib.h: MathLib.s

