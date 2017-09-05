#Nathan Greenlaw
#9/30/2016
#Makefile For Linux Machines

CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = main.cpp
SRC2 = player.cpp
SRC3 = room.cpp
SRC4 = #menu.cpp
SRC5 = #linked.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5}

HEADER1 = player.h
HEADER2 = room.h
HEADER3 = #game.h 
HEADER4 = #linked.h
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER}

PROG1 = moose
PROGS = ${PROG1}

DOC = cs162_greenlan_finalproject_design.pdf #add it to target

ZIP = cs162_greenlan_final_project.zip

default: 
	${CXX} ${SRCS} ${HEADERS} -o ${PROGS}

all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROGS}

zip:
	zip ${ZIP} ${SRCS} ${HEADERS} ${DOC} makefile

clean:
	rm -f ${PROGS} *.o *~
