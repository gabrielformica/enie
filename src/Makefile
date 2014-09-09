GPPFLAGS= -std=c++11 -lfl
GPP= clang++
YACC= bison -v -o parser.tab.cc
LEX= flex --yylineno -o lex.yy.cc
OBJ= lex.yy.cc  parser.tab.cc parserhelper.cc $(SYMTABLE) sound_type_system/type_system_utils.cc #$(TYPES2) $(SYMTABLE) #$(TYPES)
NODES= nodes/{asign,decl,inslist,instruc}.hh
#TYPES2= types/function.cc types/arglist.cc types/signa.cc types/header.cc
#TYPES= $(wildcard types/*.cc)
SYMTABLE= $(wildcard symtable/*.cc)

enie: $(OBJ)
	$(GPP) $(OBJ) $(GPPFLAGS)   -o enie

lex.yy.cc: lexer.l
	$(LEX) lexer.l

parser.tab.cc: parser.y
	$(YACC) parser.y

parser.tab.h: parser.y
	$(YACC) parser.y

install:
	cp enie /usr/bin/
clean:
	rm -f  *.tab.c *.tab.h enie *.output lex.yy.c
