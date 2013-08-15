FLAGS=-O3 ${addprefix -l, ${LIBRARY}} ${addprefix -L, ${LIBRARYPATH}}
CHLAGS=${FLAGS} -std=c99
CXXFLAGS=${FLAGS} -std=c++0x
LIBRARY=GL GLU glut
LIBRARYPATH=

GLUT_ROOT=keyboard.o display.o reshape.o
OBJECTS=${addprefix GLUT_root/, ${GLUT_ROOT}} N_body_obj.o
TARGET=N_body ${OBJECTS}

.PHONY:all clean force

force:clean
	${MAKE} all
	@./N_body

all:${TARGET}

clean:
	-@rm -r ${TARGET}

N_body:N_body.h ${OBJECTS}
