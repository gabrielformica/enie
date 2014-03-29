%option noyywrap
%{
    #include <iostream>
    #include <string>
    #include "parser.tab.hh"

    typedef yy::parser::token token;
%}

%%
[ \t]+                      /*eat whitespaces*/
[\n]+                       return token::SEP;
[0-9]+				        return token::NUMENT;
[0-9]+.[0-9]+               return token::NUMFLOT;
ent							return token::ENT;
bool						return token::BOOL;
cierto                      return token::CIERTO;
falso                       return token::FALSO;
flot						return token::FLOT;
car							return token::CAR;
cadena						return token::CADENA;
registro					return token::REGISTRO;
nada                        return token::NADA;
\{							return token::OBRACE;
\}							return token::CBRACE;
\(							return token::LPAR;
\)							return token::RPAR;
&&							return token::AND;
\|\|						return token::OR;
!                           return token::NEGATION;
si							return token::SI;
osi							return token::OSI;
sino						return token::SINO;
mientras					return token::MIENTRAS;
para						return token::PARA;
::							return token::COLCOL;
;                           return token::SEMICOL;
=							return token::EQUAL;
!=							return token::INEQUIV;
==							return token::EQUIV;
\<							return token::LTHAN;
\>							return token::GTHAN;
\<=							return token::LETHAN;
\>=							return token::GETHAN;
programa					return token::PROGRAMA;
leer						return token::LEER;
\[							return token::OBRACK;
\]							return token::CBRACK;
->							return token::ARROW;
retorna						return token::RETORNA;
,							return token::COMMA;
\*							return token::MULT;
\+							return token::PLUS;
-							return token::MINUS;
\'							return token::APOST;
\"							return token::QUOTA;
\^                          return token::POWER;
%							return token::MOD;
\\							return token::BSLASH;
[a-zA-Z][a-zA-Z0-9_]*	    yylval.str=strdup(yytext); return token::ID;
\/\*                        return token::OCOMENT;
\*\/                        return token::CCOMENT;
%%
