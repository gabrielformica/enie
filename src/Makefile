GPPFLAGS= -g -std=c++11 -lfl -Wno-deprecated-register
CLANG= clang++
CC= clang++
YACC= bison -v -yd -o parser.tab.cc
LEX= flex --yylineno -o lex.yy.cc
OBJ=  parser.tab.cc lex.yy.cc  parserhelper.cc sound_type_system/type_system_utils.cc $(SYMTABLE) $(QUADS) $(MIPS)
SYMTABLE= $(wildcard symtable/*.cc)
QUADS= $(wildcard interm_code/*.cc)
MIPS= $(wildcard assembly/mips/*.cc)

clang: CC=clang++
clang: $(OBJ)
	$(CC) $(OBJ) $(GPPFLAGS) -o enie

gpp: CC=g++
gpp: $(OBJ)
	$(CC) $(OBJ) $(GPPFLAGS) -o enie


parser.tab.cc: parser.y
	$(YACC) parser.y

lex.yy.cc: lexer.l
	$(LEX) lexer.l

install:
	cp enie /usr/bin/

gcc:


clean:
	rm -f  *.tab.c* *.tab.h* enie *.output lex.yy.c*
