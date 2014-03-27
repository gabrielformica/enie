%{
    #include <iostream>
    #include <string>
    #include "parser.tab.h"
%}

%%
[ \t]+                      /*eat whitespaces*/
[\n]+                       return SEP;
[0-9]+					/*	yylval=strdup(yytext);*/ return NUMBER;
ent							return ENT;
bool						return BOOL;
flot						return FLOT;
car							return CAR;
cadena						return CADENA;
registro					return REGISTRO;
nada                        return NADA;
\{							return OBRACE;
\}							return CBRACE;
\(							return LPAR;
\)							return RPAR;
&&							return AND;
\|\|						return OR;
!                           return NEGATION;
si							return SI;
osi							return OSI;
sino						return SINO;
mientras					return MIENTRAS;
para						return PARA;
::							return COLCOL;
;                           return SEMICOL;
=							return EQUAL;
!=							return INEQUIV;
==							return EQUIV;
\<							return LTHAN;
\>							return GTHAN;
\<=							return LETHAN;
\>=							return GETHAN;
programa					return PROGRAMA;
leer						return LEER;
\[							return OBRACK;
\]							return CBRACK;
->							return ARROW;
retorna						return RETORNA;
,							return COMMA;
\*							return MULT;
\+							return PLUS;
-							return MINUS;
\'							return APOST;
\"							return QUOTA;
\^                          return POWER;
%							return MOD;
\\							return BSLASH;
[a-zA-Z][a-zA-Z0-9_]*	    /*yylval=strdup(yytext);*/ return ID;
\/\*                        return OCOMENT;
\*\/                        return CCOMENT;
%%
