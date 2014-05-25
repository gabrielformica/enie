%defines
%locations

%code requires {
    #include <iostream>
    #include <string>
    #include <list>
    #include <vector>
    #include <stdlib.h>
    #include <stdio.h>
    #include "symtable/symtable.hh"
    #include "types/exp.hh"
    #include "types/id.hh"
    #include "types/expbin.hh"
    #include "types/ent.hh"
    #include "types/tilde.hh"
    #include "types/flot.hh"
    #include "types/bool.hh"
    #include "types/car.hh"
    #include "types/cadena.hh"
    #include "types/type_error.hh"
    #include "types/type_system_utils.hh"
    #include "types/instruc.hh"
    #include "types/indite.hh"
    #include "types/detite.hh"
    #include "types/asign.hh"
    #include "types/instlist.hh"
    #include "types/instbl.hh"
    #include "types/decl.hh"
    #include "types/selec.hh"
    #include "types/oseleclist.hh"
    #include "types/leer.hh"
    #include "types/escribir.hh"
    #include "types/retorno.hh"
    #include "types/option.hh"
    #include "types/optlist.hh"
    #include "types/arreglo.hh"
    #include "types/indexlist.hh"
    #include "types/multselec.hh"
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
    Id *idType;
    Instbl *instblType;
    Oseleclist *oslType;
    Selec *selecType;
    Retorno *returnType;
    Leer *leerType;
    Escribir *escribirType;
    Indite *indiType;
    Decl *declType;
    Option *optType;
    Optlist *optlistType;
    Multselec *multselType;
    IndexList *inlistType;
    Arreglo *arrType;
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
%token <str> ENT
%token <str> FLOT
%token <str> NADA
%token <str> BOOL
%token VAR
%token <str> CAR
%token <str> CADENA
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
     | multselec // done
     | indite   // done
     | detite   // creada pero no en parser
     | return   // done
     | callfunc
     | LEER exp
        {
            Leer *l = new Leer($<expType>2);
            $<leerType>$ = l;
        }
     | ESCRIBIR exp
        {
            Escribir *e = new Escribir($<expType>2);
            $<escribirType>$ = e;
        }
     ;

checkid : ID
        {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol *s = new Symbol(*$1, currentScope, line, column);
            checkUse(symtable, &errors, s);
            $<symType>$ = s;
        }
        ;

addid   : ID
        {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol *s = new Symbol(*$1,currentScope,line,column);
            tryAddSymbol(symtable, &errors, s);
            $<symType>$ = s;
        }
        ;

asign : checkid EQUAL exp
        {
            Asign *a =  new Asign($<symType>1, $<expType>3);
            $<instType>$ = a;
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

typeid : type addid  { $<symType>2->setType(*$<str>1); }
       ;

type : ENT    { $<str>$ = new std::string("ent"); }
     | CAR    { $<str>$ = new std::string("car"); }
     | FLOT   { $<str>$ = new std::string("flot"); }
     | NADA   { $<str>$ = new std::string("nada"); }
     | BOOL   { $<str>$ = new std::string("bool"); }
     | CADENA { $<str>$ = new std::string("cadena"); }
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
                {
                    Multselec *ms = new Multselec($<symType>2, $<optlistType>5);
                    $<multselType>$ = ms;
                }
          ;

lastoption : sepaux BSLASH QUESTION ARROW instbl
           ;

optionslist : optionslist sepaux option
                {
                    $<optlistType>1->addOption($<optType>3);
                    $<optlistType>$ = $<optlistType>1;
                }
            | option
                {
                    Optlist *ol = new Optlist($<optType>1);
                    $<optlistType>$ = ol;
                }
            ;

option: BSLASH leftsideopt ARROW instbl
            {
                $<optType>2->setBlock($<instblType>4);
                $<optType>$ = $<optType>2;
            }
      ;

leftsideopt : CONSTCAD
                {
                    Option *o = new Option(*$1);
                    $<optType>$ = o;
                }
            | checkid
                {
                    Option *o = new Option($<symType>1);
                    $<optType>$ = o;
                }
            ;

indite : MIENTRAS LPAR exp RPAR enterscope instbl leavescope
            {
                Indite *i = new Indite($<expType>3, $<instblType>6);
                $<indiType>$ = i;
            }
       ;

detite : PARA LPAR enterscope decl SEMICOL exp SEMICOL exp RPAR instbl leavescope
       ;

return : RETORNA
            {
                Retorno *r = new Retorno(NULL);
                $<returnType>$ = r;
            }
       | RETORNA exp
            {
                Retorno *r = new Retorno($<expType>2);
                $<returnType>$ = r;
            }
       ;

exp : term
    | exp PLUS exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "+", l, c);
        }
    | exp MINUS exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "-", l, c);
        }
    | exp MULT exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "*", l, c);
        }
    | exp DIV exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "/", l, c);
        }
    | exp MOD exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "%", l, c);
        }
    | exp POWER exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "^", l, c);
        }
    | exp OR exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "||", l, c);
        }
    | exp AND exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "&&", l, c);
        }
    | exp LTHAN exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "<", l, c);
        }
    | exp GTHAN exp
       {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, ">", l, c);
        }
    | exp LETHAN exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "<=", l, c);
        }
    | exp GETHAN exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, ">=", l, c);
        }
    | exp EQUIV exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "==", l, c);
        }
    | exp INEQUIV exp
        {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            $<expType>$ = get_expbin($<expType>1, $<expType>3, "!=", l, c);
        }
    | exp DOTDOT exp
    | NEGATION exp
        {
            int l = @2.first_line;    //line of the binary expression
            int c = @2.first_column;  //column of the binary expression
            if ($<expType>2->getType() == "bool") {
                $<expType>$ = new Bool();
            }
            else {
                $<expType>$ = new TypeError($<expType>2, l, c);
            }
        }

    | MINUS exp  %prec NEG
        {
            int l = @2.first_line;    //line of the binary expression
            int c = @2.first_column;  //column of the binary expression
            if ($<expType>2->getType() == "ent") {
                $<expType>$ = new Ent();
            }
            else if ($<expType>2->getType() == "flot") {
                $<expType>$ = new Flot();
            }
            else {
                $<expType>$ = new TypeError($<expType>2, l, c);
            }
        }

    | LPAR exp RPAR { $<expType>$ = $<expType>2; }
    ;


term : checkid
        {
            Id *id = new Id($<symType>1->getId);
            $<expType>$ = id;
        }
     | NUMENT      {$<expType>$ = new Ent();}
     | NUMFLOT     {$<expType>$ = new Flot();}
     | CIERTO      {$<expType>$ = new Bool();}
     | FALSO       {$<expType>$ = new Bool();}
     | checkid arr  /*ID arr*/
        {
            Id *id = new Id($<symType>1->getId());
            $<arrType>$ = new Arreglo(id, $<inlistType>2);
        }
     | callfunc
     | CONSTCAD    {$<expType>$ = new Cadena();}
     | boxelem
     | error
     ;

arr : arr OBRACK exp CBRACK
        {
            $<inlistType>1->addExp($<expType>3);
            $<inlistType>$ = $<inlistType>1;
        }
    | OBRACK exp CBRACK
        {
            Indexlist *a = new Indexlist(Exp *e);
            $<inlistType>$ = a;
        }
    | arr OBRACK TILDE CBRACK
        {
            Tilde *t = new Tilde();
            $<inlistType>1->addExp(t);
            $<inlistType>$ = $<inlistType>1;
        }
    | OBRACK TILDE CBRACK
        {
            Tilde *t = new Tilde();
            Indexlist *a = new Indexlist(t);
            $<inlistType>$ = a;
        }
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
