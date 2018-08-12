CXX = g++
CXXFLAGS = -std=c++0x

OBJS = Animal.o libraryFunctions.o main.o Penguin.o Tiger.o Turtle.o Zoo.o

SRCS = Animal.cpp libraryFunctions.cpp main.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp

HEADERS = Animal.hpp globalConstants.hpp libraryFunctions.hpp Penguin.hpp Tiger.hpp Turtle.hpp Zoo.hpp

zooTycoon: ${OBJS} ${HEADERS}
	${CXX} ${SRCS} -o zooTycoon
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm ${OBJS}