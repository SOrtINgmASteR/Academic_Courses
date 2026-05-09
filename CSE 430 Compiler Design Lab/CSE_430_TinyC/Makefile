CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -g

LEX := flex
YACC := bison

.PHONY: all clean

all: tinyc_lexer tinyc_parser

parser.tab.c parser.tab.h: parser.y
	$(YACC) -d -o parser.tab.c parser.y

lex.yy.c: lexer.l parser.tab.h
	$(LEX) -o lex.yy.c lexer.l

tinyc_parser: parser.tab.c lex.yy.c ast.c symbol_table.c main.c ast.h symbol_table.h
	$(CC) $(CFLAGS) -o $@ parser.tab.c lex.yy.c ast.c symbol_table.c main.c

tinyc_lexer: lex.yy.c lexer_main.c
	$(CC) $(CFLAGS) -o $@ lex.yy.c lexer_main.c

clean:
	rm -f tinyc_parser tinyc_lexer parser.tab.c parser.tab.h lex.yy.c *.o
