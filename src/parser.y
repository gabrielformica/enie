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
    #include "parserhelper.hh"
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
%token CONTCAD
%token CONTCAR
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
%token ESCRIBIR

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


header  : idheader COLCOL enterscope signa
        | ENIE COLCOL enterscope signa
        ;

idheader : ID
          {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol *s = new Symbol(*$1,currentScope,line,column);
            tryAddSymbol(symtable,&errors,s);  
          }

signa   : arglist ARROW type
        | arglist
        | TILDE
        | TILDE ARROW type
        ;

arglist : arglist COMMA typeid 
        | typeid 
        | VAR typeid 
        ;

instlist : instlist SEP inst
         | inst
         | error
         ;

instbl  : OBRACE SEP instlist SEP CBRACE
        ;

inst : asign  
     | decl
     | selec
     | indite
     | detite
     | return
     | callfunc
     ;

asign : ID EQUAL exp
        {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol *s = new Symbol(*$1,currentScope,line,column);
            checkUse(symtable,&errors,s);
        }
      ;


decl : typeid
     | typeid EQUAL exp
     | typeid arr
     | typeid arr EQUAL exp
     | declbox
     ;

typeid : type ID  
     {
        int currentScope = symtable->getCurrentScope();
        int line = @2.first_line;
        int column = @2.first_column;
        Symbol *s = new Symbol(*$2,currentScope,line,column);
        tryAddSymbol(symtable,&errors,s);  
     } 
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
        {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol *s = new Symbol(*$1,currentScope,line,column);
            checkUse(symtable,&errors,s);
        }
     | NUMENT
     | NUMFLOT       
     | CIERTO      
     | FALSO      
     | ID arr 
        {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol *s = new Symbol(*$1,currentScope,line,column);
            checkUse(symtable,&errors,s);
        }
     | callfunc
     | boxelem
     | error
     ;

arr : arr OBRACK exp CBRACK 
    | OBRACK exp CBRACK 
    ;

declbox : declboxtypeid OBRACE enterscope declist leavescope CBRACE 
        ;

declboxtypeid : declboxtype ID
                {
                  int currentScope = symtable->getCurrentScope();
                  int line = @2.first_line;
                  int column = @2.first_column;
                  Symbol *s = new Symbol(*$2,currentScope,line,column);
                  tryAddSymbol(symtable,&errors,s);  
                }
              ;

declboxtype  : UNION
             | REGISTRO
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
        for (vector<std::string>::iterator it = errors.begin(); 
            it != errors.end(); ++it) {
            cout << *it << endl;
        }
    } 
    cout << "---------TERMINO----------" << endl;
}
