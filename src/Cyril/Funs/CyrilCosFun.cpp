//
//  CyrilCosFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilCosFun.h"

CyrilCosFun::CyrilCosFun(Cyril* _c) : CyrilFun(_c) {
  int s = c->size();
  if (!(s == 1)) {
    yyerror("Cos function 1 argument");
    valid = false;
  }
}

CyrilCosFun::CyrilCosFun(const CyrilCosFun &other) {
  c = other.c->clone ();
}
CyrilCosFun::~CyrilCosFun () {
  delete c;
}
void CyrilCosFun::print() {
  c->print();
  cout << "Cos" << endl;
}
Cyril * CyrilCosFun::clone () {
  return new CyrilCosFun (*this);
}
int CyrilCosFun::size() {
  return 1;
}
void CyrilCosFun::eval(CyrilState &_s) {
  c->eval(_s);
  float result = cos(_s.stk->top());
  _s.stk->pop();
  _s.stk->push(result);
}

