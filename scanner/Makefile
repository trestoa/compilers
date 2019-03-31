#
# Author: Markus Klein (e11707252@student.tuwien.ac.at)
#
CC = gcc
LEX = flex
LDFLAGS = -ll

OBJECTS = lex.yy.o

.PHONY: all clean
all: scanner

scanner: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

lex.yy.o: lex.yy.c

lex.yy.c: scanner.l
	$(LEX) $<

clean:
	rm -rf *.o lex.yy.c scanner

