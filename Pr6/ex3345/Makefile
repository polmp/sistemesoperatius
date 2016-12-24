CC=gcc
CFLAGS=-std=c99
LDFLAGS=-pthread

pollgraph: pollgraph.o shrtbl.o -lrt
poll: shrtbl.o poll.o -lrt
shrtbl.o: shrtbl.c 
poll.o: poll.c shrtbl.c 

.PHONY: clean
clean:
	rm -f *~ *.o *.s *.hex
	

	

