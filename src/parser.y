%defines
%locations

%code requires {
    #include <iostream>
    #include <string>
    #include <list>
    #include <vector>
    #include <stdlib.h>
    #include <stdio.h>
    #include "symtable.hh"
    #define STR_ERROR1 "Variable re-declarada"
    extern FILE* yyin;
    extern std::vector<std::string> errors;
}

%code {
    SymbolTable *symtable = new SymbolTable();
    std::vector<std::string> errors;
    void yyerror(char const *);
    int yylex(void);
    using namespace std;


        
}

%union {
    std::string *str;
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
%token VAR
%token CAR          
%token CADENA       
%token REGISTRO     
%token RETORNA      
%token CIERTO       
%token FALSO        
%token ARREGLO
%token UNION
%token ENIE 
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
%token DOTDOT
%token ONEDOT
%token COLCOL       
%token TILDE
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
%left MINUS PLUS DOTDOT
%left MULT DIV MOD
%right POWER
%left NEG
%right NEGATION


 /* Gramatica empieza aqui */
%%

enie    : enterscope funcl END leavescope 
        ;


END     : SEP
        |
        ;


funcl   : funcl SEP func leavescope 
        | func leavescope
        | error SEP
        ;

func    : header instbl
        ;


header  : ID COLCOL enterscope signa
        | ENIE COLCOL enterscope signa
        ;

signa   : arglist ARROW type
        | arglist
        | TILDE
        | TILDE ARROW type
        ;

arglist : arglist COMMA type ID
        | type ID
        | VAR type ID
        ;

instlist : instlist SEP inst
         | inst
         | error
         ;

instbl  : OBRACE SEP instlist SEP CBRACE
        ;

inst : asign  
/*     | exp */
     | decl
     | selec
     | indite
     | detite
     | return
     ;

asign : ID EQUAL exp
      ;


decl : type ID 
      {
         int currentScope = symtable->getCurrentScope();
         if (! symtable->IdIsInScope(*$2, currentScope)) {
            symtable->addSymbol(new Symbol(*$2,currentScope,0,0));
            cout << "El simbolo " << *$2 << " esta en " << @2.first_line << endl;
         }
         else {
            errors.push_back(STR_ERROR1);
         }
     } 
     | type ID EQUAL exp
     | type ID arr
     | type ID arr EQUAL exp
     | declbox
     ;


type : ENT              
     | FLOT
     | NADA
     | BOOL
     | CAR
     | ARREGLO
     ;

selec : SI LPAR exp RPAR enterscope instbl leavescope oselect sinoselect
      ;

oselect : OSI LPAR exp RPAR enterscope instbl leavescope
        | 
        ;

sinoselect : SINO enterscope instbl leavescope
           | 
           ;

indite : MIENTRAS LPAR exp RPAR enterscope instbl leavescope
       ;

detite : PARA LPAR enterscope decl SEMICOL exp SEMICOL exp RPAR instbl leavescope
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
    | exp DOTDOT exp
    | NEGATION exp     
    | MINUS exp  %prec NEG     
    | LPAR exp RPAR
    ; 


term : ID            
     | NUMENT
     | NUMFLOT       
     | CIERTO      
     | FALSO      
     | ID arr 
     | boxelem
     | callfunc
     | error
     ;

arr : arr OBRACK exp CBRACK 
    | OBRACK exp CBRACK 
    ;

declbox : UNION ID OBRACE enterscope declist leavescope CBRACE 
        | REGISTRO ID OBRACE enterscope declist leavescope CBRACE 
        ;

declist : declist SEP decl
        | decl
        ;

callfunc : ID LPAR explist RPAR
         ;

explist : explist COMMA exp
        | exp
        ;

boxelem : term ONEDOT ID
        ;


enterscope : {symtable->enterScope(); symtable->printStack();}
leavescope : {symtable->leaveScope(); symtable->printStack();}

%% 

void error_handler(std::string err, int line, int col) {
    std::string e;
    e = err + ": linea " + to_string(line) + " columna " + to_string(col);
    errors.push_back(e);
}    

void yyerror (const char *s) {
    error_handler(s, yylloc.first_line, yylloc.first_column);
} 

int main (int argc, char **argv) {
    if (! (yyin = fopen(argv[1],"r"))) {
        cout << "Fallo en la apertura de archivo" << endl;
    }
    yyparse();
    if (! errors.empty()) {
        for (vector<std::string>::reverse_iterator it = errors.rbegin(); 
            it != errors.rend(); ++it) {
            cout << *it << endl;
        }
    } 
}
