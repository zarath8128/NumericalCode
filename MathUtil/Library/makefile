include ../makefile.macro
OBJECTS = MathLib.o distance2.o distance4.o xorshift128.o

dammy: test_c test_cpp

test_c: ${OBJECTS}
	${CC} test.c -o $@ ${OBJECTS}

test_cpp: ${OBJECTS}
	${CXX} test.cpp -o $@ ${OBJECTS}

.c.o:
	$(CC) -c $<
.cpp.o:
	$(CXX) -c $<

MathLib.h: MathLib.s
