include ../../makefile.macro
include ../makefile.macro
include ../../MathUtil/makefile.macro

OBJECTS = 
INCLUDEDIR += ${UTILITY}

tplt_target : test_c test_cpp

test_c: ${OBJECTS} test.c
	${CC} ${CFALGS} test.c -o $@ ${OBJECTS} ${GL_LIBFLAGS} ${addprefix -I, ${INCLUDEDIR}}

test_cpp: ${OBJECTS} test.cpp
	${CXX} ${CXXFLAGS} test.cpp -o $@ ${OBJECTS} ${GL_LIBFLAGS} ${addprefix -I, ${INCLUDEDIR}}
