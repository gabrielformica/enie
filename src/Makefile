CCFLAGS = -std=gnu++11 -lfl
GPP= g++
YACC = bison -d -r all
LEX = flex
OBJ=$(filter-out $(parser.tab.o), $(patsubst %.c, %.o, $(wildcard *.c))) parser.tab.o
HEADERS = parser.tab.h symtable.hh

all: parser.tab.h enie 

enie: $(OBJ)
	$(GPP) $(CCFLAGS) $(OBJ)  -o enie

lex.yy.c: lexer.l
	$(LEX) lexer.l

parser.tab.c: parser.y
	$(YACC) parser.y

parser.tab.h: parser.y
	$(YACC) parser.y

%.o: %.c $(HEADERS)
	$(GPP) -c $< $(CCFLAGS)

clean:
	rm -f $(OBJ) *.tab.c *.tab.h enie *.output lex.yy.c
