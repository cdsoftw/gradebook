#***makefile for Homework 2***

#rules
gradebook: main.o func.o
	gcc -o gradebook main.o func.o

main.o: main.c proto.h struct.h
	gcc -c main.c

func.o: func.c proto.h struct.h
	gcc -c func.c

#clean operation
clean:
	rm gradebook main.o func.o
