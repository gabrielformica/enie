%{
    #include <iostream>
    #include <string>
    #include "parser.tab.h"
/*    [a-zA-Z][a-zA-Z0-9_]*	    yylval=stdup(yytext); return ID; */ 
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
\}							return CBRACE;
\(							return LPAR;
\)							return RPAR;
&&							return AND;
\|\|						return OR;
!                           return NEGADO;
si							return SI;
osi							return OSI;
sino						return SINO;
mientras					return MIENTRAS;
para						return PARA;
::							return COLCOL;
=							return EQUAL;
==							return EQUIVALEN;
\<							return LTHAN;
\>							return GTHAN;
\<=							return LETHAN;
\>=							return GETHAN;
programa					return PROGRAMA;
leer						return LEER;
\[							return OBRACK;
\]							return CBRACK;
->							return ARROW;
retorna						return RETORNO;
,							return COMA;
\*							return MULT;
\+							return MAS;
-							return MINUS;
\'							return APOST;
\"							return QUOTA;
%							return MOD;
\\							return BSLASH;
[a-zA-Z][a-zA-Z0-9_]*	    return ID;
\/\*                        return OCOMENT;
\*\/                        return CCOMENT;
%%
