GPPFLAGS= -std=gnu++11 -lfl
GPP= g++
YACC= bison
LEX= flex --yylineno
OBJ= lex.yy.c  parser.tab.c  symtable.cc parserhelper.cc

enie: $(OBJ)
	$(GPP) $(OBJ) $(GPPFLAGS)   -o enie

lex.yy.c: lexer.l
	$(LEX) lexer.l

parser.tab.c: parser.y
	$(YACC) parser.y

parser.tab.h: parser.y
	$(YACC) parser.y

clean:
	rm -f  *.tab.c *.tab.h enie *.output lex.yy.c
