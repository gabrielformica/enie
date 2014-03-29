#include <iostream>
#include <string>
#include <unordered_map>
#include "symtable.hh" 

using namespace std;


int main(int argc, char **argv) {
  int line = 0;
  int column = 0;
  Symbol *s1 = new Symbol("ola1",1,line,column); 
  Symbol *s11 = new Symbol("ola1",2,15,column); 
  Symbol *s2 = new Symbol("ola2",1,16,column); 
  SymbolTable *st = new SymbolTable();

  /*se prueba el scope*/
  st->enterScope();
  int actualScope = st->getActualScope();
  cout << "Aqui se va a probar el getActualScope. Debe ser igual a 1" << endl;
  cout << "Actual Scope  ------>  " << actualScope << endl;
  cout << endl; 
  /*se termina prueba del scope*/

  st->addSymbol(s1);
  st->addSymbol(s2);

  /*se prueba lookup*/
  Symbol *otro = st->lookup("ola1",1);
  cout << "Aqui se va a probar el lookup. " << endl;
  cout << endl; 
  cout << "     El id siguiente debe ser 'ola1'" << endl;
  cout << "     id   ------>  " << otro->getId() << endl;
  cout << endl; 
  cout << "     La linea debe ser igual 0" << endl;
  cout << "     linea -------> " << otro->getLine() << endl;
  cout << endl; 
  cout << "     El scope debe ser 1" << endl;
  cout << "     scope   ------>  " << otro->getScope() << endl;

  st->addSymbol(s11);
  Symbol *otro2 = st->lookup("ola1",2);
  cout << "     El scope debe ser 2" << endl;
  cout << "     scope   ------>  " << otro2->getScope() << endl;
  cout << endl; 
  cout << "     La linea debe ser igual 15" << endl;
  cout << "     linea -------> " << otro2->getLine() << endl;
  cout << endl; 
  /*se termina prueba de lookup*/

}
