##################################
#
# 	makefile for Project 4 Assignment
#
##################################

CXX = g++ -std=c++0x 

OBJECTS = Barbarian.o BlueMen.o Creature.o Games.o HarryPotter.o \
	 Medusa.o Menu.o project4main.o Queue.o Stack.o \
	 ValidInput.o Vampire.o

SRCS = Barbarian.cpp BlueMen.cpp Creature.cpp Games.cpp HarryPotter.cpp \
	 Medusa.cpp Menu.cpp project4main.cpp Queue.cpp Stack.cpp \
	 ValidInput.cpp Vampire.cpp

HEADERS = Barbarian.hpp BlueMen.hpp Creature.hpp Die.hpp Games.hpp  \
	  HarryPotter.hpp Medusa.hpp Menu.hpp Queue.hpp Stack.hpp \
	 ValidInput.hpp Vampire.hpp 

project4main: ${OBJECTS} ${HEADERS}
	${CXX} ${OBJECTS} -o project4main

${OBJECTS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp) 

clean:
	rm *.o project4main  
