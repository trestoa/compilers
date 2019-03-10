#
# Author: Markus Klein (e11707252@student.tuwien.ac.at)
#
CC = gcc

OBJECTS = asma.o test.o

.PHONY: all clean
all: asma.o

asma.o: asma.s
	$(CC) -c -o $@ $<

test.o: test.c
	$(CC) -c -o $@ $<

test: $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -rf *.o test