//
//  CyrilTanFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilTanFun.h"

CyrilTanFun::CyrilTanFun(Cyril* _c) : CyrilFun(_c) {
  int s = c->size();
  if (!(s == 1)) {
    yyerror("Tan function 1 argument");
    valid = false;
  }
}
CyrilTanFun::CyrilTanFun (const CyrilTanFun &other) {
  c = other.c->clone ();
}
CyrilTanFun::~CyrilTanFun () {
  delete c;
}
void CyrilTanFun::print() {
  c->print();
  cout << "Tan" << endl;
}
Cyril * CyrilTanFun::clone () {
  return new CyrilTanFun (*this);
}
int CyrilTanFun::size() {
  return 1;
}
void CyrilTanFun::eval(CyrilState &_s) {
  c->eval(_s);
  float result = tan(_s.stk->top());
  _s.stk->pop();
  _s.stk->push(result);
}

