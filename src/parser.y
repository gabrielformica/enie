%defines
%locations

%code requires {
    #include <iostream>
    #include <string>
}

/* Tokens de las palabras reservadas */

%token SI           "si"
%token OSI          "osi"
%token SINO         "sino"
%token MIENTRAS     "mientras"
%token PARA         "para"
%token CASO         "caso"
%token ENT          "ent"
%token FLOT         "flot"
%token NADA         "nada"
%token BOOL         "bool"
%token CAR          "car"
%token CADENA       "cadena"
%token REGISTRO     "registro"
%token RETORNO      "retorno"
%token CIERTO       "cierto"
%token FALSO        "falso"



/* Tokens para caracteres especiales */

%token OBRACK       "["
%token CBRACK       "]"
%token OBRACE       "{"
%token CBRACE       "}"
%token LPAR         "("
%token RPAR         ")"
%token EQUAL        "="
%token COLCOL       "::"
%token ARROW        "->"
%token SEMICOL      ";"
%token MINUS        "-"
%token MAS          "+"
%token MULT         "*"
%token DIV          "/"
%token MOD          "%"
%token LTHAN        "<"
%token GTHAN        ">"
%token LETHAN       "<="       
%token GETHAN       ">="

/* Segun documentacion, el caracter de newline se deja especificado asi */
%token SEP                   

void main (int argc, char **argv) {
    yyparse();
}
