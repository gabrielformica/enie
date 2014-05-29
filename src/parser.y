%defines
%locations

%code requires {
    #include <iostream>
    #include <utility>
    #include <string>
    #include <list>
    #include <vector>
    #include <stdlib.h>
    #include <stdio.h>
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
    #include "nodes/expbin.hh"
    /*
    #include "symtable/func_symbol.hh"
    #include "types/exp.hh"
    #include "types/expbin.hh"
    #include "types/ent.hh"
    #include "types/flot.hh"
    #include "types/bool.hh"
    #include "types/car.hh"
    #include "types/nada.hh"
    #include "types/cadena.hh"
    #include "types/type_error.hh"
    #include "types/type_system_utils.hh"
    */
    /*primitivos*/
    /*
    #include "types/arglist.hh"
    #include "types/signa.hh"
    #include "types/header.hh"
    #include "types/function.hh"
    #include "types/instruc.hh"
    #include "types/indite.hh"
    #include "types/detite.hh"
    #include "types/asign.hh"
    #include "types/instlist.hh"
    #include "types/function.hh"
    #include "types/function_list.hh"
    */
    extern FILE* yyin;
    extern std::vector<std::string> errors;
}

%code {
    SymbolTable *symtable = new SymbolTable();
    std::vector<std::string> errors;
    void yyerror(char const *);
    int yylex(void);

    Type *entero = new Ent();
    Type *booleano = new Bool();
    Type *flot = new Flot();
    Type *nada = new Nada();
    Type *cadena = new Cadena();
    Type *car = new Car();
    Type *type_void = new Void();

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
    /*
    Instruc *instType;
    Instlist *instListType;
    Exp *expType;
    ArgList *argList;
    Signa *signa;
    Header *header;
    Function *function;
    Instbl *instblType;
    FunctionList *functionlist;
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
    */
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

/* No terminales */


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
            {
                $<symType>1->setType($<type>4);
                std::cout << "TIPO DE FUNCION: " << $<symType>1->getType()->typeString() << std::endl;
            }
        | ENIE COLCOL enterscope signa
        ;

idheader : ID    /* It will change to ID */
        {
            int currentScope = symtable->getCurrentScope();
            int line = @1.first_line;
            int column = @1.first_column;
            Symbol *s = new Symbol(*$1, NULL, currentScope, line, column);
            tryAddSymbol(symtable, &errors, s);
            $<symType>$ = s;
        }
        ;


signa   : arglist ARROW type
            {
                $<type>$ = new Function($<typelist>1, $<type>3);
            }
        | arglist
            {
                $<type>$ = new Function($<typelist>1, new Nada());
            }
        | TILDE
            {
                std::vector<Type*> *tl = new std::vector<Type*>;
                tl->push_back(new Nada());
                $<type>$ = new Function(tl, new Nada());
            }
        | TILDE ARROW type
            {
                std::vector<Type*> *tl = new std::vector<Type*>;
                tl->push_back(new Nada());
                $<type>$ = new Function(tl, new Nada());
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
         | inst
         | error
         ;

instbl : OBRACE sepaux instlist sepaux CBRACE
        ;

inst : asign        { $<node>$ = $<node>1; }
     | decl         { $<node>$ = $<node>1; }
     | selec        { $<node>$ = $<node>1; }
     | multselec    { $<node>$ = $<node>1; }
     | indite       { $<node>$ = $<node>1; }
     | detite       { $<node>$ = $<node>1; }
     | ereturn      { $<node>$ = $<node>1; }
     | callfunc     { $<node>$ = $<node>1; }
     | LEER exp     { $<node>$ = $<node>1; }
     | ESCRIBIR exp { $<node>$ = $<node>1; }
     ;

checkid : ID
            {
                int line = @1.first_line;
                int column = @1.first_column;

                Symbol *s = NULL;

                if (! symtable->isActive(*$1)) {  //syntax error
                    std::string id = s->getId();
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
        /*
            if ($<symType>1->getType()->is($<exp>3->getType()->typeString())) {
                $<node>$ = new Asign($<symType>1->getId(), $<exp>3); 
            }
        */
        }
      | arrasign EQUAL exp
        {
        std::cout << "------> " << $<exp>1->getElem() << std::endl;
        /*
            if ($<symType>1->getType()->is("arreglo")) {
                
            }
            else {
                $<node>$ = new Asign($<symType>1->getId(), new TypeError()); 
            }
        */
        }
      ;

asignid : idlist     
        ;

arrasign : checkid arrasignaux
            {
                Type *type = $<symType>1->getType();
                

                int i;
                std::string str = $<symType>1->getId();
                bool badarray = false;
                for (i = 0; i < $<explist>2->size(); i++) {
                    str = str + "[" +  ((Exp *) (*$<explist>2)[i])->getElem() + "]";
                    if (! (((Exp *) (*$<explist>2)[i])->getType()->is("ent")))
                        badarray = true;
                }

                Type *new_type;
                int dimensions = ((Arreglo *) type)->getDimensions();
                int size_arrlist = $<explist>2->size();

                if ((! badarray) && ($<symType>1->getType()->is("arreglo")) && (dimensions == size_arrlist))
                    new_type = ((Arreglo *) $<symType>1->getType())->getRootType();
                else 
                    new_type = new TypeError("");

                $<exp>$ = new Exp(str, new_type);
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
            $<symType>1->getType()->setBytes();
            $<symType>$ = $<symType>1;
        }
     | arrid EQUAL arrvalues
        {
            $<symType>1->getType()->setBytes();
            $<symType>$ = $<symType>1;
        }
     | declonly
        {
            $<symType>1->getType()->setBytes();
            $<symType>$ = $<symType>1;
        }
     | declbox
        {
            $<symType>1->getType()->setBytes();
            $<symType>$ = $<symType>1;
        }
     ;

declonly : typeid  { $<symType>$ = $<symType>1; }
         | arrid   { $<symType>$ = $<symType>1; }
         ;

arrid : typeid arr
        {
            ((Arreglo *) $<type>2)->setRootTypeElem($<symType>1->getType());
            $<symType>1->setType($<type>2);   //linking types
            $<symType>1->getType()->setBytes();
            $<symType>$ = $<symType>1;
            std::cout << "-----> " <<  $<type>2->getBytes() << std::endl;
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

selec : SI LPAR exp RPAR enterscope instbl leavescope oselect sinoselect
      ;

oselect :  oselect OSI LPAR exp RPAR enterscope instbl leavescope
        | /* lambda */
        ;

sinoselect :  SINO enterscope instbl leavescope
           | /* lambda */
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

ereturn : RETORNA
        | RETORNA exp
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
                $<exp>$ = new Exp("", new TypeError(""));
            } else {
                $<exp>$ = new Exp("", $<symType>1->getType());
            }
        }
     | NUMENT   { $<exp>$ = new Exp(to_string($1), entero) ; }
     | NUMFLOT  { $<exp>$ = new Exp(to_string($1), flot) ; }
     | CIERTO   { $<exp>$ = new Exp("cierto", booleano) ; }
     | FALSO    { $<exp>$ = new Exp("falso", booleano) ; }
     /* | checkid arr  ID arr */
     | callfunc    { $<exp>$ = new Exp("", new TypeError("")); }  //this will going to be change
     | CONSTCAD   // {$<expType>$ = new Exp(); }
     | error
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
                Exp *left = ((ExpBin *) $<exp>2)->getLeft();
                Exp *right = ((ExpBin *) $<exp>2)->getRight();
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
            Exp *left = ((ExpBin *) $<exp>2)->getLeft();
            Exp *right = ((ExpBin *) $<exp>2)->getRight();
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
                //constructor object
                ConstructorType *type = (ConstructorType *) $<symType>1->getType();

                type->setSymbolTable($<symboltable>5);   //linking types
                $<symType>$ = $<symType>1;
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

                if (! symtable->isActive(*$1)) {  //syntax error
                    std::string id = s->getId();
                    int line = @1.first_line;
                    int column = @1.first_column;
                    std::string str0 = "(linea "+ to_string(line)+ ", columna ";
                    str0 += to_string(column) + "): ";
                    std::string str = "error "+ str0 + "variable '"+ id +"'";
                    str += ", no ha sido declarada";
                    errors.push_back(str);
                } else {
                    s = symtable->lookup(*$1);
                    std::vector<Type *>* tl;
                    tl =  ((Function *) s->getType())->getParams();
                    if ($<typelist>2->size() == tl->size() ) {
                        int i;
                        for (i = 0; i < tl->size(); i++) {
                            if ( (*$<typelist>2)[i]->typeString() == (*tl)[i]->typeString() ) {
                                s = NULL;
                                break;
                            }
                        }
                    } else {
                        s = NULL;
                    }
                }


                $<symType>$ = s;

            }

         ;

funcargs : LPAR explist RPAR
            {
                $<typelist>$ = $<typelist>1;
            }
         | LPAR RPAR
            {
                std::vector<Type *> *tl = new std::vector<Type *>;
                tl->push_back(new Nada());
                $<typelist>$ = $<typelist>1;
            }
         ;

explist : explist COMMA exp
            {
                $<typelist>$ =  $<typelist>1;
                $<typelist>$->push_back($<exp>3->getType());
            }
        | exp
            {
                $<typelist>$ = new std::vector<Type*>;
                $<typelist>$->push_back($<exp>1->getType());
            }
        ;

enterscope : {symtable->enterScope(); }
leavescope : {symtable->leaveScope(); }

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
