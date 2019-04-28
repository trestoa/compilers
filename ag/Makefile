#
# Author: Markus Klein (e11707252@student.tuwien.ac.at)
#
CC = gcc
LEX = flex
YACC = yacc
OX = ox

OBJECTS = y.tab.o lex.yy.o

.PHONY: all clean
all: ag

ag: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

y.tab.o: y.tab.c

lex.yy.o: lex.yy.c y.tab.h

lex.yy.c lex.yy.h: scanner.l
	$(LEX) $<

oxout.y oxout.l: gram.y scanner.l
	$(OX) $^

y.tab.c y.tab.h: oxout.y
	$(YACC) -d $<

clean:
	rm -rf *.o lex.yy.c y.tab.c y.tab.h oxout.y oxout.l ag

