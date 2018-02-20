CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = gameoflife.o assignment1.o

SRCS = gameoflife.cpp assignment1.cpp

HEADERS = gameoflife.hpp

assignment1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o assignment1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm -f *.o a.out
