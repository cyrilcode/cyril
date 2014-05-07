//
//  CyrilWaveFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilWaveFun.h"

CyrilWaveFun::CyrilWaveFun(Cyril* _c) : CyrilFun(_c) {
  int s = c->size();
  if (!(s == 1)) {
    yyerror("Wave function 1 argument");
    valid = false;
  }
}

CyrilWaveFun::CyrilWaveFun(const CyrilWaveFun &other) {
  c = other.c->clone ();
}
CyrilWaveFun::~CyrilWaveFun () {
  delete c;
}
void CyrilWaveFun::print() {
  c->print();
  cout << "Wave" << endl;
}
Cyril * CyrilWaveFun::clone () {
  return new CyrilWaveFun (*this);
}
int CyrilWaveFun::size() {
  return 1;
}
void CyrilWaveFun::eval(CyrilState &_s) {
  c->eval(_s);
  float result = (sin(((*_s.sym)[REG_TIME] / _s.stk->top())) * 0.5) + 0.5;
  _s.stk->pop();
  _s.stk->push(result);
}

