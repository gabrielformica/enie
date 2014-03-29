#include <iostream>
#include <string>
#include <unordered_map>
#include "symtable.hh" 

using namespace std;


int main(int argc, char **argv) {
  Symbol *s = new Symbol("ola",1,2,3); 
  SymbolTable *st = new SymbolTable();
  st->enterScope();
  int actualScope = st->getActualScope();

  cout << "actual scope : " << actualScope << endl;

  st->addSymbol(s);
  Symbol *otro = st->lookup("ola",1);

  cout << "Este es el id de otro : " << otro->getId() << endl;

}
