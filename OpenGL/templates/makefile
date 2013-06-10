include ../../makefile.macro
include ../makefile.macro
<<<<<<< HEAD
include ../../MathUtil/makefile.macro

OBJECTS = 
INCLUDEDIR += ${UTILITY}
=======

OBJECTS = 
>>>>>>> 13d816d7697f2d6430cc54c72c38e86de0ed8422

tplt_target : test_c test_cpp

test_c: ${OBJECTS} test.c
<<<<<<< HEAD
	${CC} ${CFALGS} test.c -o $@ ${OBJECTS} ${GL_LIBFLAGS} ${addprefix -I, ${INCLUDEDIR}}

test_cpp: ${OBJECTS} test.cpp
	${CXX} ${CXXFLAGS} test.cpp -o $@ ${OBJECTS} ${GL_LIBFLAGS} ${addprefix -I, ${INCLUDEDIR}}
=======
	${CC} ${CFALGS} test.c -o $@ ${OBJECTS} ${GL_LIBFLAGS}

test_cpp: ${OBJECTS} test.cpp
	${CXX} ${CXXFLAGS} test.cpp -o $@ ${OBJECTS} ${GL_LIBFLAGS}
>>>>>>> 13d816d7697f2d6430cc54c72c38e86de0ed8422
