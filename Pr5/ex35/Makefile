CC=gcc
CFLAGS=-std=c99

main: parent child
child: child.o
parent: parent.o
child.o: child.c
parent.o: parent.c


.PHONY: clean
clean:
	rm -f *~ *.o *.s *.hex
	

	

