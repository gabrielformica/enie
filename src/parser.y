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
    #include "types/exp.hh"
    #include "types/ent.hh"
    #include "types/instruc.hh"
    #include "types/asign.hh"
    #include "types/instlist.hh"
    #include "types/instbl.hh"
    #include "types/selec.hh"
    #include "types/oseleclist.hh"
    #include "types/leer.hh"
    #include "types/retorno.hh"
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
    int intval;
    float floatval;
    Instruc *instType;
    Instlist *instListType;
    Symbol *symType;
    Exp *expType;
    Instbl *instblType;
    Oseleclist *oslType;
    Selec *selecType;
    Retorno *returnType;
    Leer *leerType;
}

/* Tokens de las palabras reservadas */

%token <intval> NUMENT
%token <floatval> NUMFLOT
%token <str> CONSTCAD
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
%token INEQUIV
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
%token QUESTION

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

enie    : begin enterscope funcl end leavescope
        ;

begin   : sepaux
        | /* lambda */
        ;

end     : sepaux
        ;

sepaux  : sepaux SEP
        | SEP
        ;

funcl   : funcl sepaux func leavescope
        | func leavescope
        | error SEP
        ;

func    : header instbl
        | header
        ;


header  : idheader COLCOL enterscope signa
        | ENIE COLCOL enterscope signa
        ;

idheader : addid
         ;

signa   : arglist ARROW type
        | arglist
        | TILDE
        | TILDE ARROW type
        ;

arglist : arglist COMMA declonly
        | declonly
        | VAR declonly
        ;

instlist : instlist sepaux inst
            {
                $<instListType>1->addInst($<instType>3);
                $<instListType>$ = $<instListType>1;
            }
         | inst
            {
                Instlist l($<instType>1);
                $<instListType>$ = &l;
            }
         | error
         ;

instbl : OBRACE sepaux instlist sepaux CBRACE
            {
                Instbl bl($<instListType>3);
                $<instblType>$ = &bl;
            }
        ;

inst : asign
     | decl
     | selec    // done
     | multselec
     | indite   // creada pero no en parser
     | detite   // creada pero no en parser
     | return   // done
     | callfunc
     | LEER exp
        {
            Leer l($<expType>2);
            $<leerType>$ = &l;
        }
     | ESCRIBIR exp
     ;

checkid : ID
        {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol s(*$1,currentScope,line,column);
            checkUse(symtable,&errors,&s);
            $<symType>$ = &s;
        }
        ;

addid   : ID
        {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol s(*$1,currentScope,line,column);
            tryAddSymbol(symtable,&errors,&s);
        }
        ;

asign : checkid EQUAL exp
        {
            Asign a = Asign($<symType>1, $<expType>3);
            $<instType>$ = &a;
        }
      | checkid arr EQUAL arrvalues
        {

        }
      ;

arrvalues : exp
          | OBRACE arrvalueslist CBRACE
          ;

arrvalueslist : arrvalueslist COMMA arrvalues
              | arrvalues
              ;

decl : typeid EQUAL exp
     | typeid arr EQUAL arrvalues
     | declonly
     | declbox
     ;

declonly : typeid
         | typeid arr
         ;

typeid : type addid
       ;

type : ENT
     | FLOT
     | NADA
     | BOOL
     | CAR
     | ARREGLO
     ;

selec : SI LPAR exp RPAR enterscope instbl leavescope oselect sinoselect
        {
            Selec *s = new Selec($<expType>3, $<instblType>6, $<oslType>8);
            $<selecType>$ = s;
        }
      ;

oselect :  oselect OSI LPAR exp RPAR enterscope instbl leavescope
            {
                Oselec *os = new Oselec($<expType>4, $<instblType>7);
                $<oslType>1->addOselec(os);
                $<oslType>$ = $<oslType>1;
            }
        |  OSI LPAR exp RPAR enterscope instbl leavescope
            {
                Oselec *os = new Oselec($<expType>3, $<instblType>6);
                Oseleclist *l = new Oseleclist(os);
                $<oslType>$ = l;
            }
        ;

sinoselect :  SINO enterscope instbl leavescope
           |
           ;


multselec : CASO checkid OBRACE sepaux optionslist lastoption sepaux CBRACE
          ;

lastoption : sepaux BSLASH QUESTION ARROW instbl
           ;

optionslist : optionslist sepaux option
            | option
            ;

option: BSLASH leftsideopt ARROW instbl
      ;

leftsideopt : CONSTCAD
            | checkid
            ;

indite : MIENTRAS LPAR exp RPAR enterscope instbl leavescope
       ;

detite : PARA LPAR enterscope decl SEMICOL exp SEMICOL exp RPAR instbl leavescope
       ;

return : RETORNA
            {
                Retorno r(NULL);
                $<returnType>$ = &r;
            }
       | RETORNA exp
            {
                Retorno r($<expType>2);
                $<returnType>$ = &r;
            }
       ;

exp : term
    | exp PLUS exp
        {
            std::string t1 =  ($<expType>1)->getType();
            std::string t2 =  ($<expType>3)->getType();
            if (t1 == t2) {
                if ((t1 == "ent") || (t1 == "flot")) {
                }
            }

        }
    | exp MINUS exp
    | exp MULT exp
    | exp DIV exp
    | exp MOD exp
    | exp POWER exp
    | exp OR exp
    | exp AND exp
    | exp LTHAN exp
    | exp GTHAN exp
    | exp LETHAN exp
    | exp GETHAN exp
    | exp EQUIV exp
    | exp INEQUIV exp
    | exp DOTDOT exp
    | NEGATION exp
    | MINUS exp  %prec NEG
    | LPAR exp RPAR
    ;


term : checkid     /*ID*/
     | NUMENT
     | NUMFLOT
     | CIERTO
     | FALSO
     | checkid arr  /*ID arr*/
     | callfunc
     | CONSTCAD
     | boxelem
     | error
     ;

arr : arr OBRACK exp CBRACK
    | OBRACK exp CBRACK
    | arr OBRACK TILDE CBRACK
    | OBRACK TILDE CBRACK
    ;

declbox : declboxtypeid OBRACE enterscope declist leavescope CBRACE
        ;

declboxtypeid : UNION addid
              | REGISTRO addid
              ;

declist : declist sepaux decl
        | decl
        ;

callfunc : checkid LPAR explist RPAR
         | checkid LPAR RPAR
         ;

explist : explist COMMA exp
        | exp
        ;

boxelem : term ONEDOT checkid
        ;


enterscope : {symtable->enterScope(); }
leavescope : {symtable->leaveScope(); }

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

    if (! (yyin = fopen(argv[1], "r"))) {
        cerr << "Fallo en la apertura de archivo" << endl;
        return 1;
    }

    yyparse();

    if (! errors.empty()) {
        for (vector<std::string>::iterator it = errors.begin();
            it != errors.end(); ++it) {
            cerr << *it << endl;
        }
        return 1;
    }

    symtable->printTable();

    return 0;
}
