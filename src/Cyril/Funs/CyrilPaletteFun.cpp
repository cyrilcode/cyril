//
//  CyrilPaletteFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilPaletteFun.h"
#include "CyrilState.h"

CyrilPaletteFun::CyrilPaletteFun(Cyril * _c) : CyrilFun(_c) {
  int s = _c->size();
  if (!(s == 1 || s == 2)) {
    yyerror("Palette function has 1 or 2 arguments");
    valid = false;
  }
}

CyrilPaletteFun::CyrilPaletteFun(const CyrilPaletteFun &other) {
  c = other.c->clone ();
}
CyrilPaletteFun::~CyrilPaletteFun () {
  delete c;
}
void CyrilPaletteFun::print() {
  c->print();
  cout << "Palette" << endl;
}
Cyril * CyrilPaletteFun::clone () {
  return new CyrilPaletteFun (*this);
}
int CyrilPaletteFun::size() {
  return 3;
}
void CyrilPaletteFun::eval(CyrilState &_s) {
  c->eval(_s);
  float p, d;
  if (c->size() == 2) {
    d = _s.stk->top(); _s.stk->pop();
  }
  else {
    d = ofRandomuf();
  }
  p = _s.stk->top(); _s.stk->pop();
  ofColor _c = (*_s.cs)[p]->getColorAt(d);
  _s.stk->push(_c.r);
  _s.stk->push(_c.g);
  _s.stk->push(_c.b);
}



