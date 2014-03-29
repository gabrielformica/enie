%option noyywrap
%{
    #include <iostream>
    #include <string>
    #include "parser.tab.hh"

    typedef yy::parser::token token;
%}

%%
[ \t]+                      /*eat whitespaces*/
[\n]+                       return SEP;
[0-9]+				        return NUMENT;
[0-9]+.[0-9]+               return NUMFLOT;
arreglo                     return ARREGLO;
union                       return UNION;
ent							return ENT;
bool						return BOOL;
cierto                      return CIERTO;
falso                       return FALSO;
flot						return FLOT;
var                         return VAR;
car							return CAR;
cadena						return CADENA;
registro					return REGISTRO;
nada                        return NADA;
\.\.                        return DOTDOT;
\.                          return ONEDOT;
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
~                           return TILDE;
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
[a-zA-Z][a-zA-Z0-9_]*	    yylval.str=strdup(yytext); return ID;
\/\*                        return OCOMENT;
\*\/                        return CCOMENT;
%%
