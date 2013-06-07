include ../../makefile.macro
include ../makefile.macro

OBJECTS = MathLib.o distance2.o distance4.o xorshift128.o ${UTILITY}/Align.o

lib_target: test_c test_cpp

test_c: ${OBJECTS}
	${CC} ${CFLAGS} test.c -o $@ ${OBJECTS} ${addprefix -I, ${INCLUDEDIR}}


test_cpp: ${OBJECTS} util_target
	${CXX} ${CXXFLAGS} test.cpp -o $@ ${OBJECTS} ${addprefix -I, ${INCLUDEDIR}}


util_target:
	cd ${UTILITY} && ${MAKE}

cplx_target:
	cd ${COMPLEX} && ${MAKE}

MathLib.o: MathLib.s MathLib.h
