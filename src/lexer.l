%{
    #include <iostream>
    #include <string>
    #include "parser.tab.h"
    #define YY_USER_ACTION loc_track();
    
    extern YYLTYPE yylloc;
    extern std::vector<std::string> errors;

    int yycolumn = 0;
    void loc_track() {
        yylloc.first_line = yylloc.last_line = yylineno;
        yylloc.first_column = yycolumn;
        yylloc.last_column = yycolumn+yyleng-1; 
        yycolumn += yyleng;
    }    
%}

%x comment

%%



[ \t]+                      /*eat whitespaces*/
[\n]+                       { yycolumn = 0; return SEP; }
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
leer                        return LEER;
escribir                    return ESCRIBIR;
\"(\\.|[^\\"])*\"           { return CONTCAD; }
'(\\.|[^\\'])'              { printf("--%s--", yytext); return CONTCAR; }
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
enie                        return ENIE;
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
[a-zA-Z][a-zA-Z0-9_]*	    { 
                            yylval.str = new std::string(yytext); 
                            return ID;  
                            }

"/~"  BEGIN(comment);

<comment>"~/"   BEGIN(INITIAL);

.                           {   
                            /* Regla para caracteres inesperados */

                            std::string error = "Error: Caracter ";
                            error = error + "'" + yytext + "'";
                            error = error + " desconocido en linea ";
                            error = error + std::to_string(yylineno);
                            error = error + ", columna ";
                            error = error + std::to_string(yycolumn); 
                            errors.push_back(error);
                            }

%%
