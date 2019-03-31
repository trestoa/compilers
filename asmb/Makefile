#
# Author: Markus Klein (e11707252@student.tuwien.ac.at)
#
CC = gcc

OBJECTS = asmb.o test.o

.PHONY: all clean
all: asmb.o

asmb.o: asmb.s
	$(CC) -c -o $@ $<

test.o: test.c
	$(CC) -c -o $@ $<

test: $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -rf *.o test