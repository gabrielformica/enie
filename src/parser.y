%defines
%locations

%code requires {
    #include <iostream>
    #include <string>
    #include <stdio.h>
    extern FILE *yyin;
}

%code {
    void yyerror(char const *);
    int yylex(void);
    using namespace std;
}

/*
%union {
    int num;
    std::string *str;
}
*/
/* Tokens de las palabras reservadas */
%printer { fprintf (yyoutput, "%s", $$); } NUMBER    ; 
%printer { fprintf (yyoutput, "%s", $$); } ID        ;
%printer { fprintf (yyoutput, "%s", $$); } SI       ;   
%printer { fprintf (yyoutput, "%s", $$); } OSI       ;   
%printer { fprintf (yyoutput, "%s", $$); } SINO      ;   
%printer { fprintf (yyoutput, "%s", $$); } MIENTRAS  ;   
%printer { fprintf (yyoutput, "%s", $$); } PARA      ;   
%printer { fprintf (yyoutput, "%s", $$); } CASO      ;   
%printer { fprintf (yyoutput, "%s", $$); } ENT       ;   
%printer { fprintf (yyoutput, "%s", $$); } FLOT      ;   
%printer { fprintf (yyoutput, "%s", $$); } NADA      ;   
%printer { fprintf (yyoutput, "%s", $$); } BOOL      ;   
%printer { fprintf (yyoutput, "%s", $$); } CAR       ;   
%printer { fprintf (yyoutput, "%s", $$); } CADENA    ;   
%printer { fprintf (yyoutput, "%s", $$); } REGISTRO  ;   
%printer { fprintf (yyoutput, "%s", $$); } RETORNO   ;   
%printer { fprintf (yyoutput, "%s", $$); } CIERTO    ;   
%printer { fprintf (yyoutput, "%s", $$); } FALSO     ;   
%printer { fprintf (yyoutput, "%s", $$); } PROGRAMA  ;   
%printer { fprintf (yyoutput, "%s", $$); } LEER      ;  




%token NUMBER
%token ID
%token SI           
%token OSI          
%token SINO         
%token MIENTRAS     
%token PARA         
%token CASO         
%token ENT          
%token FLOT         
%token NADA         
%token BOOL         
%token CAR          
%token CADENA       
%token REGISTRO     
%token RETORNO      
%token CIERTO       
%token FALSO        
%token PROGRAMA     
%token LEER        


/* Tokens para caracteres especiales */

%token OBRACK       
%token CBRACK       
%token OBRACE       
%token CBRACE       
%token LPAR         
%token RPAR         
%token EQUAL        
%token EQUIVALEN    
%token COLCOL       
%token ARROW        
%token SEMICOL      
%token COMA         
%token MINUS        
%token MAS          
%token MULT         
%token DIV          
%token MOD          
%token LTHAN        
%token GTHAN        
%token LETHAN              
%token GETHAN       
%token NEGADO       
%token AND          
%token OR           
%token QUOTA        
%token APOST        
%token BSLASH      
%token OCOMENT     
%token CCOMENT     

/* Precedencias */
%left MINUS MAS
%left MULT DIV
%left NEGADO 

/* La directiva type para el union */
/*
%type<num> exp term NUMBER
%type<str> ID
*/
%% /* Gramatica empieza aqui */

/* A pesar de que las expresiones unarias estan definidas con sus propias reglas
   en la gramatica, esas reglas son inutiles por si solas una vez asignadas
   las reglas de precedencia */ 
s    : all funcl
     ;

all  : funcl all
     | decfunc all
     ;

decfunc : header
        ;

funcl   : func '\n' funcl
        | func
        ;

func    : header instbl
        ;

instbl  : OBRACE instlist CBRACE
        ;

header  : ID COLCOL signa
        ;

signa   : arglist ARROW type
        | arglist
        ;

arglist : type ID ',' arglist
        |  
        ;

instlist : inst '\n' instlist
         | inst
         ;

inst : decl            { $$ = $1; }
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

type : ENT              { $$ = $1; }
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
    cerr << s;
} 

int main (int argc, char **argv) {
    yyin=fopen(argv[1],"r");
    yyparse();
}


