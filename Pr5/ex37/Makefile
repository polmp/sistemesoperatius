CC=gcc
CFLAGS=-std=c99 -lrt

main: parent child
child: child.o
parent: parent.o -lrt
matrix: matrix.o
child.o: child.c
matrix.o: matrix.h matrix.c
parent.o: parent.c


.PHONY: clean
clean:
	rm -f *~ *.o *.s *.hex
	

	

