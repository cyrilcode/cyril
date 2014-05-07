//
//  CyrilRandFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilRandFun.h"

CyrilRandFun::CyrilRandFun(Cyril * _c) : CyrilFun(_c) {
  int s = _c->size();
  if (!(s == 0 || s == 1 || s == 2)) {
    yyerror("Rand function has 0, 1 or 2 arguments");
    valid = false;
  }
}

CyrilRandFun::CyrilRandFun(const CyrilRandFun &other) {
  c = other.c->clone ();
}
CyrilRandFun::~CyrilRandFun () {
  delete c;
}
void CyrilRandFun::print() {
  c->print();
  cout << "Rand" << endl;
}
Cyril * CyrilRandFun::clone () {
  return new CyrilRandFun (*this);
}
int CyrilRandFun::size() {
  return 1;
}
void CyrilRandFun::eval(CyrilState &_s) {
  c->eval(_s);
  float r, x, y;
  switch (c->size()) {
    case 0:
      r = ofRandomf();
      break;
    case 1:
      x = _s.stk->top(); _s.stk->pop();
      r = ofRandom(x);
      break;
    case 2:
      x = _s.stk->top(); _s.stk->pop();
      y = _s.stk->top(); _s.stk->pop();
      r = ofRandom(x, y);
      break;
  }
  _s.stk->push(r);
}

