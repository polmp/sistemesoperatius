CC=gcc
CFLAGS=-std=c99 

main: parent child
test_matrix: test_matrix.o matrix.o
child: child.o matrix.o -lrt
parent: parent.o matrix.o -lrt
matrix: matrix.o
child.o: child.c 
test_matrix.o: test_matrix.c
matrix.o: matrix.h
parent.o: parent.c


.PHONY: clean
clean:
	rm -f *~ *.o *.s *.hex
	

	

