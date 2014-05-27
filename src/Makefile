GPPFLAGS= -std=gnu++11 -lfl
GPP= g++ 
YACC= bison -v
LEX= flex --yylineno
OBJ= lex.yy.c  parser.tab.c parserhelper.cc $(SYMTABLE) #types/type_system_utils.cc $(TYPES2) $(SYMTABLE) #$(TYPES)
#TYPES2= types/function.cc types/arglist.cc types/signa.cc types/header.cc
#TYPES= $(wildcard types/*.cc)
SYMTABLE= $(wildcard symtable/*.cc)

enie: $(OBJ)
	$(GPP) $(OBJ) $(GPPFLAGS)   -o enie

lex.yy.c: lexer.l
	$(LEX) lexer.l

parser.tab.c: parser.y
	$(YACC) parser.y

parser.tab.h: parser.y
	$(YACC) parser.y

install:
	cp enie /usr/bin/ 
clean:
	rm -f  *.tab.c *.tab.h enie *.output lex.yy.c
