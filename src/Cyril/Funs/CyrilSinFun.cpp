//
//  CyrilSinFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilSinFun.h"
#include "CyrilState.h"

CyrilSinFun::CyrilSinFun(Cyril* _c) : CyrilFun(_c) {
  int s = c->size();
  if (!(s == 1)) {
    yyerror("Sin function 1 argument");
    valid = false;
  }
}

CyrilSinFun::CyrilSinFun(const CyrilSinFun &other) {
  c = other.c->clone ();
}
CyrilSinFun::~CyrilSinFun () {
  delete c;
}
void CyrilSinFun::print() {
  c->print();
  cout << "Sin" << endl;
}
Cyril * CyrilSinFun::clone () {
  return new CyrilSinFun (*this);
}
int CyrilSinFun::size() {
  return 1;
}
void CyrilSinFun::eval(CyrilState &_s) {
  c->eval(_s);
  float result = sin(_s.stk->top());
  _s.stk->pop();
  _s.stk->push(result);
}

