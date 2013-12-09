//
//  CyrilNoiseFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilNoiseFun.h"
#include "CyrilState.h"

CyrilNoiseFun::CyrilNoiseFun(Cyril* _c) : CyrilFun(_c) {
  int s = c->size();
  if (!(s == 1 || s == 2 || s == 3)) {
    yyerror("Noise function has 1, 2 or 3 arguments");
    valid = false;
  }
}

CyrilNoiseFun::CyrilNoiseFun(const CyrilNoiseFun &other) {
  c = other.c->clone ();
}

CyrilNoiseFun::~CyrilNoiseFun () {
  delete c;
}

void CyrilNoiseFun::print() {
  c->print();
  cout << "Noise" << endl;
}
Cyril * CyrilNoiseFun::clone () {
  return new CyrilNoiseFun (*this);
}
int CyrilNoiseFun::size() {
  return 1;
}
void CyrilNoiseFun::eval(CyrilState &_s) {
  c->eval(_s);
  float r, x, y, z;
  switch (c->size()) {
    case 1:
      x = _s.stk->top(); _s.stk->pop();
      r = ofNoise(x);
      break;
    case 2:
      x = _s.stk->top(); _s.stk->pop();
      y = _s.stk->top(); _s.stk->pop();
      r = ofNoise(x, y);
      break;
    case 3:
      x = _s.stk->top(); _s.stk->pop();
      y = _s.stk->top(); _s.stk->pop();
      z = _s.stk->top(); _s.stk->pop();
      r = ofNoise(x, y, z);
      break;
  }
  _s.stk->push(r);
}

