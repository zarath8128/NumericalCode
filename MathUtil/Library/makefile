<<<<<<< HEAD
include ../../makefile.macro
include ../makefile.macro

OBJECTS = MathLib.o distance2.o distance4.o xorshift128.o ${UTILITY}/Align.o
=======
include ../makefile.macro

OBJECTS = MathLib.o distance2.o distance4.o xorshift128.o
>>>>>>> 13d816d7697f2d6430cc54c72c38e86de0ed8422

lib_target: test_c test_cpp

test_c: ${OBJECTS}
<<<<<<< HEAD
	${CC} ${CFLAGS} test.c -o $@ ${OBJECTS} ${addprefix -I, ${INCLUDEDIR}}


test_cpp: ${OBJECTS} util_target
	${CXX} ${CXXFLAGS} test.cpp -o $@ ${OBJECTS} ${addprefix -I, ${INCLUDEDIR}}
=======
	${CC} ${CFLAGS} test.c -o $@ ${OBJECTS} -I${MATH_UTIL}


test_cpp: ${OBJECTS} util_target
	${CXX} ${CXXFLAGS} test.cpp -o $@ ${OBJECTS} ${UTILITY}/Align.o -I${MATH_UTIL}
>>>>>>> 13d816d7697f2d6430cc54c72c38e86de0ed8422


util_target:
	cd ${UTILITY} && ${MAKE}

cplx_target:
	cd ${COMPLEX} && ${MAKE}

MathLib.o: MathLib.s MathLib.h
<<<<<<< HEAD
=======
distance2.o: distance2.s
>>>>>>> 13d816d7697f2d6430cc54c72c38e86de0ed8422
