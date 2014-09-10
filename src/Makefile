GPPFLAGS= -std=c++11 -lfl -Wno-deprecated-register
GPP= clang++ 
YACC= bison -v -yd -o parser.tab.cc
LEX= flex --yylineno -o lex.yy.cc
OBJ=  parser.tab.cc lex.yy.cc  parserhelper.cc sound_type_system/type_system_utils.cc $(SYMTABLE) 
SYMTABLE= $(wildcard symtable/*.cc)

enie: $(OBJ)
	$(GPP) $(OBJ) $(GPPFLAGS)  -o enie

parser.tab.cc: parser.y
	$(YACC) parser.y

lex.yy.cc: lexer.l
	$(LEX) lexer.l 

install:
	cp enie /usr/bin/

clean:
	rm -f  *.tab.c* *.tab.h* enie *.output lex.yy.c*
