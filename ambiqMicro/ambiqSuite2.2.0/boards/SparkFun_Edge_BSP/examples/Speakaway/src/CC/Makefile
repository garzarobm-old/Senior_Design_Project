CC  ?= gcc
CXX ?= g++

CFLAGS = -O0 -g -Wall -pedantic 
CXXFLAGS = -O0 -g -Wall -pedantic

OBJ	= main practiceCall
OBJS  = $(addsuffix .o,$(OBJ))
all:
	make compile

compile:
	make $(OBJS)
	make fooexe

fooexe: $(OBJS) 
	$(CXX) -o fooexe $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

practicecall.o: practiceCall.cc
	$(CXX) $(CXXFLAGS) -c -o practiceCall.o practiceCall.cc

clean:
	rm -rf $(OBJS) fooexe *.dSYM

