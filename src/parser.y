%defines
%locations

%code requires {
    #include <iostream>
    #include <string>
}

%code {
    void yyerror(char const *);
}


/* Tokens de las palabras reservadas */

%token NUMBER
%token ID
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

/* Precedencias */
%left MINUS MAS
%left MULT DIV


%% /* Gramatica empieza aqui */
exp : term              { $$ = $1;} 
    | exp MAS exp       { $$ = $1 + $3;}
    | exp MINUS exp     { $$ = $1 - $3;}
    | exp MULT exp      { $$ = $1 * $3;}
    ; 

term : ID               { $$ = $1; }
     | NUMBER           { $$ = $1; }
     ;


%% /* Epilogo comienza aca */

void main (int argc; char **argv) {
    yyparse();
}
