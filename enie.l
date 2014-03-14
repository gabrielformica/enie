%{
#include <stdio.h>
#include <string.h>
%}

%%
[0-9]+						printf("NUMBER");
ent							printf("ENT");
bool						printf("BOOL");
flot						printf("FLOT");
car							printf("CAR");
cadena						printf("CADENA");
registro					printf("REGISTRO");
\{							printf("OBRACE");
\}							printf("EBRACE");
\(							printf("OPAREN");
\)							printf("EPAREN");
&&							printf("AND");
\|\|						printf("OR");
si							printf("SI");
osi							printf("OSI");
sino						printf("SINO");
mientras					printf("MIENTRAS");
para						printf("PARA");
::							printf("COLONCOLON");
=							printf("EQUAL");
==							printf("EQUALEQUAL");
\<							printf("LTHAN");
\>							printf("GTHAN");
\<=							printf("LETHAN");
\>=							printf("GETHAN");
programa					printf("PROGRAMA");
leer						printf("LEER");
\[							printf("OBRACK");
\]							printf("EBRACK");
->							printf("ARROW");
retorna						printf("RETORNA");
,							printf("COMMA");
\*							printf("MULT");
\+							printf("PLUS");
-							printf("MINUS");
\'							printf("APOST");
\"							printf("QUOTA");
%							printf("PERCEN");
\\							printf("BSLASH");
[a-zA-Z][a-zA-Z0-9_]*	    printf("ID");
%%
