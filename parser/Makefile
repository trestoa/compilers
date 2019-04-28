#
# Author: Markus Klein (e11707252@student.tuwien.ac.at)
#
CC = gcc
LEX = flex
YACC = yacc

OBJECTS = y.tab.o 

.PHONY: all clean
all: parser

parser: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

lex.yy.c: scanner.l
	$(LEX) $<

y.tab.o: y.tab.c

y.tab.c: parser.y lex.yy.c
	$(YACC) $<

clean:
	rm -rf *.o lex.yy.c y.tab.c parser

