%defines
%locations

%code requires {
    #include <iostream>
    #include <utility>
    #include <string>
    #include <list>
    #include <vector>
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <getopt.h>
    #include "symtable/symbol.hh"
    #include "symtable/symtable.hh"
    #include "parserhelper.hh"
    #include "sound_type_system/type_system_utils.hh"
    #include "sound_type_system/base/ent.hh"
    #include "sound_type_system/base/bool.hh"
    #include "sound_type_system/base/arreglo.hh"
    #include "sound_type_system/base/flot.hh"
    #include "sound_type_system/base/cadena.hh"
    #include "sound_type_system/base/car.hh"
    #include "sound_type_system/base/nada.hh"
    #include "sound_type_system/base/void.hh"
    #include "sound_type_system/base/constructor_type.hh"
    #include "sound_type_system/base/registro.hh"
    #include "sound_type_system/base/function.hh"
    #include "sound_type_system/base/union.hh"
    #include "sound_type_system/base/type_error.hh"
    #include "nodes/node.hh"
    #include "nodes/exp.hh"
    #include "nodes/expsimple.hh"
    #include "nodes/expbin.hh"
    #include "nodes/asign.hh"
    #include "nodes/decl.hh"
    #include "nodes/instlist.hh"
    #include "nodes/error.hh"
    #include "nodes/instruc.hh"
    #include "nodes/selec.hh"
    #include "nodes/osi.hh"
    #include "nodes/para.hh"
    #include "nodes/mientras.hh"
    #include "nodes/retorna.hh"
    #include "nodes/caso.hh"
    #include "nodes/lambda_opt.hh"
    #include "nodes/func_node.hh"
    #include "nodes/funcapp.hh"
    #include "nodes/program.hh"
    #include "interm_code/quad.hh"
    #include "interm_code/quad_asign.hh"
    extern FILE* yyin;
    extern std::vector<std::string> errors;
    extern "C" { int yyparse(void); int yylex(void);}
}

%code {
    SymbolTable *symtable = new SymbolTable();
    int offset = 0;                 // Keeps global count of offset
    std::list<int> *offsetStack = new std::list<int>;     // Tracks current offset for nested blocks

    std::vector<std::string> errors;
    void yyerror(char const *);

    Program *enie;


    Type *nada = new Nada();
    Type *entero = new Ent();
    Type *booleano = new Bool();
    Type *flot = new Flot();
    Type *cadena = new Cadena();
    Type *car = new Car();
    Type *type_void = new Void();
    Node *syntax_error = new Error(new TypeError("Error sintactico"));

    using namespace std;
}

%union {
    std::string *str;
    int intval;
    float floatval;
    Symbol *symType;
    Type *type;
    Node *node;
    Exp *exp;
    SymbolTable *symboltable;
    std::vector<Type*> *typelist;
    std::vector<Exp *> *explist;
    Instruc *instruc;
    InstList *instlist, *sino;
    Selec *selec;
    Osi *osi;
    Asign *asign;
    Decl *decl;
    Para *para;
    Caso *caso;
    Mientras *mientras;
    Retorna *retorna;

    Program *program;

    Header *header;
    FuncNode *func_node;
    std::vector<LambdaOpt *> *optlist;
    LambdaOpt *lambda_opt;
}

/* Tokens de las palabras reservadas */

%token <intval> NUMENT
%token <floatval> NUMFLOT
%token <str> CONSTCAD
%token <str> CONSTCAR
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

/* No terminales */


 /* Gramatica empieza aqui */
%%

enie    : begin enterscope globals end leavescope
            {
                enie = $<program>3;

                //Check if every forward declaration was defined
                std::string str = not_implemented(symtable);
                errors.push_back(str); 
            }
        ;

begin   : sepaux
        | /* lambda */
        ;

end     : sepaux
        ;

sepaux  : sepaux SEP
        | SEP
        ;

globals : globals sepaux global
            {
                $<program>1->append($<node>3);
                $<program>$ = $<program>1;
            }
        | global
            {
                $<program>$ = new Program($<node>1);
            }
        ;

global : func leavescope { $<node>$ = $<node>1; }
       | decl { $<node>$ = $<node>1; }
       | declbox { $<node>$ = new Decl($<symType>1, NULL, $<symType>1->getType()); }
       | error { $<node>$ = syntax_error; }
       ;

func : header instbl
        {
            ((Function *) $<header>1->getType())->unsetForward();      //This set -forward- to false forever!
            $<func_node>$ = new FuncNode($<header>1, $<instlist>2);
        }
     | header
        {
            $<func_node>$ = new FuncNode($<header>1, NULL);
        }
     ;

header  : idheader COLCOL enterscope signa
            {
                $<symType>1->setType($<type>4);
                $<header>$ = new Header($<symType>1->getId(), $<type>4);
            }
        | ENIE COLCOL enterscope signa
            {
                $<header>$ = new Header("enie", $<type>4);
            }
        ;

idheader : ID
            {
                int currentScope = symtable->getCurrentScope();
                int line = @1.first_line;
                int column = @1.first_column;
                std::string id = *$1;
                Symbol *aux = symtable->getSymbolInScope(*$1, currentScope);
                Symbol *s = new Symbol(*$1, NULL, currentScope, line, column);

                if (aux != NULL) {          //Symbol is in this scope
                    if (! aux->getType()->is("function")) {    //In this scope, but not a function!
                        std::string str0 = "(linea "+ to_string(line)+ ", columna ";
                        str0 += to_string(column) + "): ";
                        std::string str = "error "+ str0 + "la funcion '"+ id +"'";
                        str += ", toma el nombre de una variable previamente declara ";
                        str += "en la linea " + to_string(aux->getLine());
                        errors.push_back(str);
                    }
                    else if (! ((Function *) aux->getType())->getForward()) {   //A function, but already defined
                        std::string str0 = "(linea "+ to_string(line)+ ", columna ";
                        str0 += to_string(column) + "): ";
                        std::string str = "error "+ str0 + "la funcion '"+ id +"'";
                        str += " ya ha sido definida";
                        errors.push_back(str);
                    }
                    else {                                                      //A function, but not implemented yet
                        s = aux;                         
                    }
                }
                else {
                    tryAddSymbol(symtable, &errors, s);          //It will add the symbol always
                }

                $<symType>$ = s;
            }
        ;


signa   : arglist ARROW type
            {
                $<type>$ = new Function($<typelist>1, $<type>3);
            }
        | arglist
            {
                $<type>$ = new Function($<typelist>1, nada);
            }
        | TILDE
            {
                std::vector<Type*> *tl = new std::vector<Type*>;
                tl->push_back(nada);
                $<type>$ = new Function(tl, nada);
            }
        | TILDE ARROW type
            {
                std::vector<Type*> *tl = new std::vector<Type*>;
                tl->push_back(nada);
                $<type>$ = new Function(tl, nada);
            }
        ;

arglist : arglist COMMA declonly
            {
                $<typelist>$ =  $<typelist>1;
                $<typelist>$->push_back($<symType>3->getType());
            }
        | declonly
            {
                $<typelist>$ = new std::vector<Type*>;
                $<typelist>$->push_back($<symType>1->getType());
            }
        | arglist COMMA VAR declonly
            {
                $<typelist>$ =  $<typelist>1;
                $<typelist>$->push_back($<symType>4->getType());
            }
        | VAR declonly
            {
                $<typelist>$ = new std::vector<Type*>;
                $<typelist>$->push_back($<symType>1->getType());
            }
        ;

instlist : instlist sepaux inst
            {
                ($<instlist>1)->addInst($<instruc>3);
                $<instlist>$ = $<instlist>1;
            }
         | inst
            {
                    $<instlist>$ = new InstList($<instruc>1, ($<instruc>1)->getType());
            }
         ;

instbl : OBRACE sepaux instlist sepaux CBRACE
            {
                $<instlist>$ = $<instlist>3;
            }
        ;

inst : asign           { $<node>$ = $<node>1; }
     | decl            { $<node>$ = $<node>1; }
     | selec           { $<node>$ = $<node>1; }
     | multselec       { $<node>$ = $<node>1; }
     | indite          { $<node>$ = $<node>1; }
     | detite          { $<node>$ = $<node>1; }
     | ereturn         { $<node>$ = $<node>1; }
     | callfunc        { $<node>$ = $<node>1; }
     | LEER checkid
        {
            Exp *exp = new ExpSimple($<symType>2->getId(), $<symType>2->getType());
            std::vector<Exp *> *params = new std::vector<Exp *>;
            params->push_back(exp);
            $<node>$ = new FuncApp("leer", params, type_void);
        }
     | ESCRIBIR exp
        {
            if ($<exp>2->getType()->is("cadena")) {
                std::vector<Exp *> *params = new std::vector<Exp *>;
                params->push_back($<exp>2);
                $<node>$ = new FuncApp("escribir", params, type_void);
            }
            else {
                $<node>$ = new FuncApp("escribir", NULL, new TypeError("leer no esta recibiendo una cadena de caracteres"));
            }
        }
     | error
        {
            $<node>$ = syntax_error;
        }
     ;

checkid : ID
            {
                int line = @1.first_line;
                int column = @1.first_column;

                Symbol *s = NULL;

                if (! symtable->isActive(*$1)) {  //syntax error
                    std::string id = *$1;
                    int line = @1.first_line;
                    int column = @1.first_column;
                    std::string str0 = "(linea "+ to_string(line)+ ", columna ";
                    str0 += to_string(column) + "): ";
                    std::string str = "error "+ str0 + "variable '"+ id +"'";
                    str += ", no ha sido declarada";
                    errors.push_back(str);
                }
                else {
                    s = symtable->lookup(*$1);
                }

                $<symType>$ = s;

            }
        ;


asign : asignid EQUAL exp
        {
            if ($<exp>1->getType() == $<exp>3->getType()) {
                $<asign>$ = new Asign($<exp>1, $<exp>3, type_void) ;
            }
            else {
                $<asign>$ = new Asign($<exp>1, $<exp>3, new TypeError(""));
            }

        }
      | arrasign EQUAL exp
        {
            Type *lhs = $<exp>1->getType();
            Type *rhs = $<exp>3->getType();

            if (lhs == rhs) {
                $<asign>$ = new Asign($<exp>1, $<exp>3, type_void);
            } else {
                $<asign>$ = new Asign($<exp>1, $<exp>3, new TypeError(""));
            }
        }
      ;

asignid : idlist
            {
                if ($<symType>1 == NULL) {
                    $<exp>$ = new ExpSimple("", new TypeError(""));
                } else {
                    $<exp>$ = new ExpSimple($<symType>1->getId(), $<symType>1->getType());
                }
            }
        ;

arrasign : checkid arrasignaux
            {

                std::string str = $<symType>1->getId();

                bool badarray = false;
                int i;
                for (i = 0; i < $<explist>2->size(); i++) {
                    //str = str + "[" +  ((Exp *) (*$<explist>2)[i])->getElem() + "]";
                    if (! (((Exp *) (*$<explist>2)[i])->getType()->is("ent")))
                        badarray = true;
                }

                Type *type = $<symType>1->getType();
                int dimensions = ((Arreglo *) type)->getDimensions();
                int size_arrlist = $<explist>2->size();

                Type *new_type;
                if ((! badarray) && ($<symType>1->getType()->is("arreglo")) && (dimensions == size_arrlist))
                    new_type = ((Arreglo *) $<symType>1->getType())->getRootType();
                else
                    new_type = new TypeError("");

                $<exp>$ = new ExpSimple(str, new_type);
            }
        ;

arrasignaux : arrasignaux OBRACK exp CBRACK
                {
                    $<explist>1->push_back($<exp>3);
                    $<explist>$ = $<explist>1;
                }
            | OBRACK exp CBRACK
                {
                    std::vector<Exp *> *arrl = new std::vector<Exp *>;
                    arrl->push_back($<exp>2);
                    $<explist>$ = arrl;
                }
            ;

arrvalues : exp
          | OBRACE arrvalueslist CBRACE
          ;

arrvalueslist : arrvalueslist COMMA arrvalues
              | arrvalues
              ;

decl : typeid EQUAL exp
        {
            if ($<symType>1->getType()->typeString() == $<exp>3->getType()->typeString()) {
                $<symType>1->setOffset(offset);     // Setting offset
                offset += $<symType>1->getType()->getWidth();
                $<node>$ = new Decl($<symType>1, $<exp>3, type_void);
            }
            else {
                $<node>$ = new Decl($<symType>1, $<exp>3, new TypeError(""));
            }
        }
     | arrid EQUAL arrvalues
        {
            if ($<symType>1->getType() == $<exp>3->getType()) {
                $<symType>1->setOffset(offset);     // Setting offset
                offset += $<symType>1->getType()->getWidth();
                $<node>$ = new Decl($<symType>1, $<exp>3, type_void);
            }
            else {
                $<node>$ = new Decl($<symType>1, $<exp>3, new TypeError(""));
            }

        }
     | declonly
        {
            $<symType>1->setOffset(offset);     // Setting offset
            offset += $<symType>1->getType()->getWidth();
            $<node>$ = new Decl($<symType>1, NULL, new TypeError(""));
        }
        ;





declonly : typeid  { $<symType>$ = $<symType>1; }
         | arrid   { $<symType>$ = $<symType>1; }
         ;

arrid : typeid arr
        {
            ((Arreglo *) $<type>2)->setRootTypeElem($<symType>1->getType());
            $<symType>1->setType($<type>2);   //linking types
            $<symType>1->getType()->setWidth();
            $<symType>$ = $<symType>1;
        }
      ;

typeid : type ID
           {
               int currentScope = symtable->getCurrentScope();
               int line = @2.first_line;
               int column = @2.first_column;
               Symbol *s = new Symbol(*$2, $<type>1, currentScope, line, column);
               tryAddSymbol(symtable, &errors, s);
               $<symType>$ = s;  //return the symbol
           }
       ;

type : ENT     { $<type>$ = entero; }
     | CAR     { $<type>$ = car; }
     | FLOT    { $<type>$ = flot; }
     | NADA    { $<type>$ = nada; }
     | BOOL    { $<type>$ = booleano; }
     | CADENA  { $<type>$ = cadena; }
     | ID
        {
            Symbol *s = symtable->lookup(*$1);
            if (s == NULL) {
                $<type>$ = new TypeError("");
            }
            else {
                $<type>$ = s->getType();
            }
        }
     ;

selec : pushoffset SI LPAR exp RPAR enterscope instbl leavescope oselect sinoselect popoffset
        {

            $<selec>$ = new Selec($<exp>4,  $<instlist>7, $<osi>9, $<sino>10);
        }
      ;

oselect : pushoffset OSI LPAR exp RPAR enterscope instbl leavescope oselect popoffset
            {
                $<osi>$ = new Osi($<exp>4, $<instlist>7, $<osi>9);
            }
        | /* lambda */
            {
                $<osi>$ = NULL;
            } 
        ;

sinoselect : pushoffset SINO enterscope instbl leavescope popoffset
               {
                    $<sino>$ = $<instlist>4;
               }
           |   { $<sino>$ = NULL; }  /* lambda */
           ;

multselec : CASO checkid OBRACE sepaux optionslist lastoption sepaux CBRACE
              {
                  ExpSimple *var = new ExpSimple($<symType>2->getId(), $<symType>2->getType());
                  $<caso>$ = new Caso(var, $<optlist>5, $<lambda_opt>6);
              }
          ;

lastoption : sepaux BSLASH QUESTION ARROW instbl
                {
                    $<lambda_opt>$ = new LambdaOpt(new ExpSimple("?", new Car()), $<instlist>5);
                }
           ;

optionslist : optionslist sepaux option
                {
                   $<optlist>$ = $<optlist>1;
                   $<optlist>$->push_back($<lambda_opt>3);
                }
            | option
                {
                   $<optlist>$ = new std::vector<LambdaOpt *>;
                   $<optlist>$->push_back($<lambda_opt>1);
                }
            ;

option: BSLASH leftsideopt ARROW instbl
        {
            $<lambda_opt>$ = new LambdaOpt($<exp>2, $<instlist>4);
        }
      ;

leftsideopt : term
                {
                    $<exp>$ = $<exp>1;
                }
            ;


indite : pushoffset MIENTRAS LPAR exp RPAR enterscope instbl leavescope popoffset
            {
                $<mientras>$ = new Mientras($<exp>4, $<instlist>7);
            }
       ;

detite : pushoffset PARA LPAR enterscope decl SEMICOL exp SEMICOL exp RPAR instbl leavescope popoffset
            {
                if ($<decl>4 != NULL) {
                    $<para>$ = new Para($<decl>5, $<exp>7, $<exp>9, $<instlist>11);
                }
                else {
                    $<para>$ = new Para(NULL, $<exp>7, $<exp>9, $<instlist>11);
                }
            }
       ;

ereturn : RETORNA
            {
                $<retorna>$ = new Retorna(type_void);
            }
        | RETORNA exp
            {
                $<retorna>$ = new Retorna($<exp>2, type_void);
            }
        ;

exp : term   { $<exp>$ = $<exp>1; } /*{ $<expType>$ = $<expType>1; } */
    | exp PLUS exp
    {
        Exp *exp = NULL;
        exp = get_expbin($<exp>1, $<exp>3, "+");



         //constructing binary expression with type error
        if (exp == NULL) {
            int l = @1.first_line;    //line of the binary expression
            int c = @1.first_column;  //column of the binary expression
            TypeError *t = new TypeError("");
            $<exp>$ = new ExpBin($<exp>1, $<exp>3, "+", t);
         }
         else {
             $<exp>$ = exp;
         }
    }
    | exp MINUS exp
        {
            Exp *exp = NULL;
            exp = get_expbin($<exp>1, $<exp>3, "-");
            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "-", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp MULT exp
       {
            Exp *exp = NULL;
            exp = get_expbin($<exp>1, $<exp>3, "*");

             //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "*", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp DIV exp
       {
            Exp *exp = NULL;
            exp = get_expbin($<exp>1, $<exp>3, "/");

             //constructing binary expression with type error
             if (exp == NULL) {
                int l = @1.first_line;    //line of the binary expression
                int c = @1.first_column;  //column of the binary expression
                TypeError *t = new TypeError("");
                $<exp>$ = new ExpBin($<exp>1, $<exp>3, "/", t);
             }
             else {
                 $<exp>$ = exp;
             }
        }
    | exp MOD exp
       {
            Exp *exp = NULL;
            exp = get_expbin($<exp>1, $<exp>3, "%");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "%", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp POWER exp
        {
             Exp *exp = NULL;
             exp = get_expbin($<exp>1, $<exp>3, "^");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "^", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp OR exp
        {
             Exp *exp = NULL;
             exp = get_expbin($<exp>1, $<exp>3, "|");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "|", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp AND exp
        {
             Exp *exp = NULL;
             exp = get_expbin($<exp>1, $<exp>3, "&");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "&", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp LTHAN exp
        {
             Exp *exp = NULL;
             exp = get_expbin($<exp>1, $<exp>3, "<");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "<", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp GTHAN exp
        {
             Exp *exp = NULL;
             exp = get_expbin($<exp>1, $<exp>3, ">");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, ">", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp LETHAN exp
        {
            Exp *exp = NULL;
            exp = get_expbin($<exp>1, $<exp>3, "<=");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "<=", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp GETHAN exp
        {
            Exp *exp = NULL;
            exp = get_expbin($<exp>1, $<exp>3, ">=");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, ">=", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp EQUIV exp
        {
            Exp *exp = NULL;
            exp = get_expbin($<exp>1, $<exp>3, "==");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "==", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp INEQUIV exp
        {
            Exp *exp = NULL;
            exp = get_expbin($<exp>1, $<exp>3, "!=");

            //constructing binary expression with type error
            if (exp == NULL) {
               int l = @1.first_line;    //line of the binary expression
               int c = @1.first_column;  //column of the binary expression
               TypeError *t = new TypeError("");
               $<exp>$ = new ExpBin($<exp>1, $<exp>3, "!=", t);
            }
            else {
                $<exp>$ = exp;
            }
        }
    | exp DOTDOT exp
        {
            $<exp>$ = new ExpBin($<exp>1, $<exp>3, "..", entero);
           // exp = get_expbin($<exp>1, $<exp>3, "..");

           // //constructing binary expression with type error
           // if (exp == NULL) {
           //    int l = @1.first_line;    //line of the binary expression
           //    int c = @1.first_column;  //column of the binary expression
           //    //std::string str = "expresion binaria ->" + $<node>1->toString() + "+" $<node>3->toString();
           //    TypeError *t = new TypeError("");
           //    $<exp>$ = new ExpBin($<exp>1, $<exp>3, "..", t);
           // }
           // else {
           //     $<exp>$ = exp;
           // }
        }
    | NEGATION exp  { $<exp>$ = $<exp>2; }
    | MINUS exp  %prec NEG { $<exp>$ = $<exp>2; }
    | LPAR exp RPAR  { $<exp>$ = $<exp>2; }
    ;


term : idlist
        {
            if ($<symType>1 == NULL) {
                $<exp>$ = new ExpSimple("", new TypeError(""));
            } else {
                $<exp>$ = new ExpSimple($<symType>1->getId(), $<symType>1->getType());
            }
        }
     | NUMENT   { $<exp>$ = new ExpSimple(to_string($1), entero); }
     | NUMFLOT  { $<exp>$ = new ExpSimple(to_string($1), flot); }
     | CIERTO   { $<exp>$ = new ExpSimple("cierto", booleano) ; }
     | FALSO    { $<exp>$ = new ExpSimple("falso", booleano) ; }
     /* | checkid arr  ID arr */
     | callfunc    { $<exp>$ = $<exp>1; }
     | CONSTCAD    { $<exp>$ = new ExpSimple(*$1, new Cadena()); }
     | CONSTCAR    { $<exp>$ = new ExpSimple(*$1, new Car()); }
     | arrasign
     | error
        {
            $<node>$ = syntax_error;
        }
     ;

idlist : idlist ONEDOT ID
            {
                if ($<symType>1 == NULL || ! $<symType>1->getType()->is("constructor")) {
                    $<symType>$ = NULL;
                } else {
                    SymbolTable *st = ((ConstructorType *) $<symType>1->getType())->getSymbolTable();

                    if (st->isActive(*$3)) {
                        $<symType>$ = st->lookup(*$3);
                    } else {
                        $<symType>$ = NULL;
                    }
                }
            }

       | checkid   { $<symType>$ = $<symType>1; }
       ;

arr : OBRACK exp CBRACK arr
        {
            if ($<type>4->typeString() == "error") {
                $<type>$ = $<type>4;
            }
            else {
                ExpSimple *left = (ExpSimple *) ((ExpBin *) $<exp>2)->getLeft();
                ExpSimple *right = (ExpSimple *) ((ExpBin *) $<exp>2)->getRight();
                std::string ope = ((ExpBin *) $<exp>2)->getOperator();

                if ((left->getType() == entero) && (right->getType() == entero) && (ope == "..")) {
                    int first_index = std::stoi(left->getElem());
                    int last_index = std::stoi(right->getElem());
                    if (first_index  >= last_index) {
                        $<type>$ = new TypeError("");
                    }
                    else {
                        $<type>$ = new Arreglo($<type>4, first_index, last_index);
                    }
                }
                else {
                    $<type>$ = new TypeError("");
                }
            }
        }
    | OBRACK exp CBRACK
        {
            ExpSimple *left = (ExpSimple *) ((ExpBin *) $<exp>2)->getLeft();
            ExpSimple *right = (ExpSimple *)  ((ExpBin *) $<exp>2)->getRight();
            std::string ope = ((ExpBin *) $<exp>2)->getOperator();

            if ((left->getType() == entero) && (right->getType() == entero) && (ope == "..")) {
                int first_index = std::stoi(left->getElem());
                int last_index = std::stoi(right->getElem());
                if (first_index  >= last_index) {
                    $<type>$ = new TypeError("");
                }
                else {
                    $<type>$ = new Arreglo(NULL, first_index, last_index);
                }
            }
            else {
                $<type>$ = new TypeError("");
            }
        }
    ;

declbox : declboxtypeid enterscope OBRACE sepaux declist sepaux CBRACE leavescope
            {
                //Constructor object
                ConstructorType *type = (ConstructorType *) $<symType>1->getType();

                //Linking types
                type->setSymbolTable($<symboltable>5);
                $<symType>$ = $<symType>1;

                //Setting width
                type->setWidth();

            }
        ;


constructortype : UNION
                    {
                        $<type>$ = new Union();
                    }
                | REGISTRO
                    {
                        $<type>$ = new Registro();
                    }
                ;

declboxtypeid : constructortype ID
                  {
                      int currentScope = symtable->getCurrentScope();
                      int line = @2.first_line;
                      int column = @2.first_column;
                      Symbol *s = new Symbol(*$2, $<type>1, currentScope, line, column);
                      tryAddSymbol(symtable, &errors, s);
                      $<symType>$ = s;  //return the symbol
                  }
              ;

declist : declist sepaux declpritype
            {
                Symbol *s = $<symType>3;
                tryAddSymbol($<symboltable>1, &errors, s);
            }
        | declpritype
            {
                Symbol *s = $<symType>1;
                $<symboltable>$ = new SymbolTable();
                tryAddSymbol($<symboltable>$, &errors, s);
            }
        ;


declpritype : type ID EQUAL exp
                {
                    int scope = 0;   //Unique scope for constructors type
                    int line = @2.first_line;
                    int column = @2.first_column;
                    Symbol *s = new Symbol(*$2, $<type>1, scope, line, column);
                    $<symType>$ = s;
                }
            | type ID arr EQUAL arrvalues
                {
                    int scope = 0;   //Unique scope for constructors type
                    int line = @2.first_line;
                    int column = @2.first_column;
                    Symbol *s = new Symbol(*$2, $<type>1, scope, line, column);

                    ((Arreglo *) $<type>3)->setRootTypeElem($<type>1);
                    s->setType($<type>3);  //linking types with arr type
                    $<symType>$ = s;
                }
            | type ID //simple declaration
                {
                    int scope = 0;   //Unique scope for constructors type
                    int line = @2.first_line;
                    int column = @2.first_column;
                    Symbol *s = new Symbol(*$2, $<type>1, scope, line, column);
                    $<symType>$ = s;
                }
            | type ID arr //simple declaration
                {
                    int scope = 0;   //Unique scope for constructors type
                    int line = @2.first_line;
                    int column = @2.first_column;
                    Symbol *s = new Symbol(*$2, $<type>1, scope, line, column);

                    ((Arreglo *) $<type>3)->setRootTypeElem($<type>1);
                    s->setType($<type>3);  //linking types with arr type
                    $<symType>$ = s;
                }
            ;

callfunc : ID funcargs
            {
                int line = @1.first_line;
                int column = @1.first_column;

                Symbol *s = NULL;
                bool semantic_errors = false;

                if (! symtable->isActive(*$1)) {  //syntax error
                    std::string id = *$1;
                    int line = @1.first_line;
                    int column = @1.first_column;
                    std::string str0 = "(linea "+ to_string(line)+ ", columna ";
                    str0 += to_string(column) + "): ";
                    std::string str = "error "+ str0 + "variable '"+ id +"'";
                    str += ", no ha sido declarada";
                    errors.push_back(str);
                } else {
                    s = symtable->lookup(*$1);
                    std::vector<Type *> *passed_types = getTypesFromExps($<explist>2);
                    std::vector<Type *> *formal_types;

                    formal_types = ((Function *) s->getType())->getParams();
                    if (formal_types->size() == passed_types->size() ) {
                        int i;
                        for (i = 0; i < formal_types->size(); i++) {
                            if ( (*formal_types)[i]->typeString() != (*passed_types)[i]->typeString() ) {
                                semantic_errors = true;
                                break;
                            }
                        }
                    } else {
                        semantic_errors = true;
                    }
                }

                if (semantic_errors) {
                    $<exp>$ = new FuncApp(*$1, $<explist>2, new TypeError(""));
                }
                else {
                    $<exp>$ =  new FuncApp(*$1, $<explist>2, ((Function *) s->getType())->getRetType());
                }
            }

         ;

funcargs : LPAR explist RPAR { $<explist>$ = $<explist>2; }
         | LPAR RPAR
            {
                std::vector<Exp *> *exps = new std::vector<Exp *>;
                exps->push_back(new ExpSimple("", nada));
                $<explist>$ = exps;
            }
         ;

explist : explist COMMA exp
            {
                $<explist>$ = $<explist>1;
                $<explist>$->push_back($<exp>3);
            }
        | exp
            {
                $<explist>$ = new std::vector<Exp *>;
                $<explist>$->push_back($<exp>1);
            }
        ;

enterscope : {symtable->enterScope(); }
leavescope : {symtable->leaveScope(); }

pushoffset : { offsetStack->push_back(offset); }
popoffset  : {
                offset = offsetStack->back();
                offsetStack->pop_back();
             }

%%

void error_handler(std::string err, int line, int col) {
    std::string e;
    e = err + ": linea " + to_string(line) + " columna " + to_string(col);
    errors.push_back(e);
}

void yyerror(const char *s) {
    error_handler(s, yylloc.first_line, yylloc.first_column);
}

int main (int argc, char **argv) {

    static struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"file", required_argument, 0, 'f'},
            {"symtable", no_argument, 0, 's'},
            {"tree", no_argument, 0, 't'},
            {0,0,0,0}
    };

    //Parser of CLI
    int opt, option_index;
    char file_name[100];
    bool f_flag = false;
    bool s_flag = false;
    bool t_flag = false;

    while (1) {
        opt = getopt_long(argc, argv, "hf:st", long_options, &option_index);
        if (opt == -1)
            break;

        switch (opt) {
        case 0: break;
        case 'h':
            std::cout << std::endl;
            std::cout << "-h\t\tprint this help, genius" << std::endl;
            std::cout << "-s\t\tprint symbol table"  << std::endl;
            std::cout << "-t\t\tprint abstract syntax tree" << std::endl;
            exit(EXIT_SUCCESS);
        case 's':
            s_flag = true;
            break;
        case 't':
            t_flag = true;
            break;
        case 'f':
            if (strlen(optarg) >= 100) {
                cerr << "Nombre de archivo muy largo" << endl;
                exit(1);
            }
            strcpy(file_name, optarg);
            f_flag = true;
            break;
        case '?':
            printf("nop");
            break;
        }
    }

    if (f_flag) {
        if (! (yyin = fopen(file_name, "r"))) {
            cerr << "Fallo en la apertura de archivo" << endl;
            exit(1);
        }

        yyparse();

        if (! errors.empty()) {
            for (vector<std::string>::iterator it = errors.begin();
                it != errors.end(); ++it) {
                cerr << *it << endl;
            }
            exit(1);
        }
    }

    if ((f_flag) && (s_flag))
        symtable->printTable();

    if ((f_flag) && (t_flag))
        std::cout << enie->toString() << std::endl;

    return 0;
}
