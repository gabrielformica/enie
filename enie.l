%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}

%%
[0-9]+						yylval=atoi(yytext); return NUMBER;
ent							return ENT;
bool						return BOOL;
flot						return FLOT;
car							return CAR;
cadena						return CADENA;
registro					return REGISTRO;
\{							return OBRACE;
\}							return EBRACE;
\(							return OPAREN;
\)							return EPAREN;
&&							return AND;
\|\|						return OR;
si							return SI;
osi							return OSI;
sino						return SINO;
mientras					return MIENTRAS;
para						return PARA;
::							return COLONCOLON;
=							return EQUAL;
==							return EQUALEQUAL;
\<							return LTHAN;
\>							return GTHAN;
\<=							return LETHAN;
\>=							return GETHAN;
programa					return PROGRAMA;
leer						return LEER;
\[							return OBRACK;
\]							return EBRACK;
->							return ARROW;
retorna						return RETORNA;
,							return COMMA;
\*							return MULT;
\+							return PLUS;
-							return MINUS;
\'							return APOST;
\"							return QUOTA;
%							return PERCEN;
\\							return BSLASH;
[a-zA-Z][a-zA-Z0-9_]*	    yylval=stdup(yytext); return ID;
%%
