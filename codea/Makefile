#
# Author: Markus Klein (e11707252@student.tuwien.ac.at)
#
CC = gcc
LEX = lex
YACC = yacc
OX = ox
BFE = ../tools/bfe
BURG = /Users/markus/git/iburg/iburg

OBJECTS = y.tab.o lex.yy.o codegen.o

.PHONY: all clean
all: codea

codea: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

y.tab.o: y.tab.c
codegen.o: codegen.c

codegen.c: codegen.bfe codegen.h
	$(BFE) $< | $(BURG) > codegen.c

lex.yy.o: lex.yy.c y.tab.h

lex.yy.c lex.yy.h: oxout.l
	$(LEX) $<

oxout.y oxout.l: gram.y scanner.l
	$(OX) $^

y.tab.c y.tab.h: oxout.y
	$(YACC) -d $<

test: f.s test.c
	gcc -c f.s
	gcc -c test.c
	gcc -o test test.o f.o

clean:
	rm -rf *.o lex.yy.c y.tab.c y.tab.h oxout.y oxout.l codegen.c codea

