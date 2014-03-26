%defines
%locations

%code requires {
    #include <iostream>
    #include <string>
}

%code {
    void yyerror(char const *s);
    int yylex(void);
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
%token PROGRAMA     "programa"
%token LEER         "leer"


/* Tokens para caracteres especiales */

%token OBRACK       "["
%token CBRACK       "]"
%token OBRACE       "{"
%token CBRACE       "}"
%token LPAR         "("
%token RPAR         ")"
%token EQUAL        "="
%token EQUIVALEN    "=="
%token COLCOL       "::"
%token ARROW        "->"
%token SEMICOL      ";"
%token COMA         ","
%token MINUS        "-"
%token MAS          "+"
%token MULT         "*"
%token DIV          "/"
%token MOD          "%"
%token LTHAN        "<"
%token GTHAN        ">"
%token LETHAN       "<="       
%token GETHAN       ">="
%token NEGADO       "!"
%token AND          "&&"
%token OR           "||"
%token QUOTA        "\""
%token APOST        "\'"
%token BSLASH       "\\"
%token OCOMENT     "\\*"
%token CCOMENT     "*/"

/* Precedencias */
%left MINUS MAS
%left MULT DIV
%left NEGADO 


%% /* Gramatica empieza aqui */

/* A pesar de que las expresiones unarias estan definidas con sus propias reglas
   en la gramatica, esas reglas son inutiles por si solas una vez asignadas
   las reglas de precedencia */ 


inst : decl
     | asign
     | selec
     | indite
     | detite
     ;

exp : term              { $$ = $1; } 
    | exp MAS exp       { $$ = $1 + $3; }
    | exp MINUS exp     { $$ = $1 - $3; }
    | exp MULT exp      { $$ = $1 * $3; }
    | NEGADO exp        { $$ = $2; } /* hay que hacer el negado */
    | MINUS exp         { $$ = (-1)*($2); }
    ; 

term : ID               { $$ = $1; }
     | NUMBER           { $$ = $1; }
     ;

type : ENT
     | FLOT
     | NADA
     | BOOL
     | CAR
     | REGISTRO
     ;

/* Reglas para instrucciones */

decl : type ID
     ;

asign : ID EQUAL exp
     ;

selec : SI LPAR exp RPAR inst oselect sinoselect
      ;

oselect : OSI LPAR exp RPAR inst
        | 
        ;

sinoselect : SINO inst
           | 
           ;

indite : MIENTRAS LPAR exp RPAR inst
       ;

detite : PARA LPAR decl SEMICOL exp SEMICOL exp RPAR inst
       ;

%% /* Epilogo comienza aca */

void yyerror (const char *s) {
    std::cout << s;
} 

int main (int argc, char **argv) {
    yyparse();
}
