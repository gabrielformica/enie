%defines
%locations

%code requires {
    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <stdio.h>
    extern FILE* yyin;
}

%code {
    void yyerror(char const *);
    int yylex(void);
    using namespace std;
}

%union {
    char *str;
}

/* Tokens de las palabras reservadas */

%token NUMENT
%token NUMFLOT
%token <str> ID
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
%token RETORNA      
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
%token EQUIV    
%token COLCOL       
%token ARROW        
%token SEMICOL      
%token COMMA         
%token MINUS        
%token PLUS          
%token MULT         
%token DIV          
%token MOD          
%token LTHAN        
%token GTHAN        
%token LETHAN              
%token GETHAN       
%token NEGATION 
%token AND          
%token OR           
%token QUOTA        
%token APOST        
%token BSLASH      
%token OCOMENT     
%token CCOMENT     
%token SEP

/* Precedencias */
%left OR
%left AND
%left EQUIV INEQUIV
%left LTHAN GTHAN GETHAN LETHAN
%left MINUS PLUS 
%left MULT DIV MOD
%right POWER
%right NEGATION

 /* Gramatica empieza aqui */
%%

enie    : funcl
        ;


funcl   : funcl func
        | func
        ;

func    : header instbl
        ;


header  : ID COLCOL signa
        ;

signa   : arglist ARROW type
        | arglist
        ;

arglist : arglist COMMA type ID
        | type ID
        ;

instlist : instlist SEP inst
         | inst
         ;

instbl  : OBRACE SEP instlist SEP CBRACE
        | OBRACE instlist CBRACE
        ;

inst : asign  
     | exp
     | decl
     | selec
     | indite
     | detite
     | return
     ;



asign : ID EQUAL exp
      ;

decl : type ID
     | type asign 
     ;


type : ENT              
     | FLOT
     | NADA
     | BOOL
     | CAR
     | REGISTRO
     ;


selec : SI LPAR exp RPAR instbl oselect sinoselect
      ;

oselect : OSI LPAR exp RPAR instbl
        | 
        ;

sinoselect : SINO instbl
           | 
           ;

indite : MIENTRAS LPAR exp RPAR instbl
       ;

detite : PARA LPAR decl SEMICOL exp SEMICOL exp RPAR instbl
       ;

return : RETORNA
       | RETORNA exp
       ;

exp : term            
    | exp PLUS exp      
    | exp MINUS exp     
    | exp MULT exp      
    | exp MOD exp
    | exp POWER exp
    | exp OR exp
    | exp AND exp
    | exp LTHAN exp
    | exp GTHAN exp
    | exp LETHAN exp
    | exp GETHAN exp
    | NEGATION exp     
    | MINUS exp        
    | LPAR exp RPAR
    ; 


term : ID            
     | NUMENT
     | NUMFLOT       
     | CIERTO      
     | FALSO      
     | ID OBRACK exp CBRACK   
     ;


%% 

void yyerror (const char *s) {
    cerr << s;
} 

int main (int argc, char **argv) {
    if (! (yyin = fopen(argv[1],"r"))) {
        cout << "Fallo en la apertura de archivo" << endl;
    }
    yyparse();
}

