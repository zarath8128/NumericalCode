INCLUDEDIR := MathUtility OpenGL Utility ${INCLUDEDIR_ADD}
INCLUDEFLAG := ${addprefix -I, ${INCLUDEDIR}}

CFLAGS := -std=c99 ${INCLUDEFLAG} ${CFLAGS_ADD}
CXXFLAGS := -std=c++0x ${INCLUDEFLAG} ${CXXFLAGS_ADD}

DIR=${dir ${TARGET}}

include ${TARGET}



