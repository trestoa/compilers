#
# Author: Markus Klein (e11707252@student.tuwien.ac.at)
#
LEX = lex
YACC = yacc
OX = ox
LDFLAGS = -lm
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CC = clang
	BFE = ../tools/bfe
	BURG = /Users/markus/git/iburg/iburg
else
	CC = gcc
	BFE = bfe
	BURG = iburg
endif

OBJECTS = y.tab.o lex.yy.o burgout.o codegen.o

.PHONY: all clean
all: codeb

codeb: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

y.tab.o: y.tab.c
burgout.o: burgout.c

burgout.c: codegen.bfe codegen.h
	$(BFE) $< | $(BURG) > burgout.c

lex.yy.o: lex.yy.c y.tab.h

codegen.o: codegen.c codegen.h

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
	rm -rf ./*.o lex.yy.c y.tab.c y.tab.h oxout.y oxout.l oxout.h burgout.c codeb *.s

