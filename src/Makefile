CCFLAGS = -std=gnu++11
CPP= g++
YACC = bison 
OBJ=$(filter-out $(parser.tab.o), $(patsubst %.c, %.o)) parser.tab.o
HEADERS = parser.tab.h symtable.hh

all: enie parser.tab.h 

enie: $(OBJ)
	$(GPP) $(CCFLAGS) $(OBJ)  -o enie

parser.tab.c: parser.y
	$(YACC) parser.y

parser.tab.h: parser.y
	$(YACC) parser.y

%.o: %.c $(HEADERS)
	$(GPP) -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) *.tab.c *.tab.h enie *.output
