//
//  CyrilBoxOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilBoxOp.h"

CyrilBoxOp::CyrilBoxOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 0 || s == 1 || s == 3)) {
    yyerror("Box command requires 0, 1, or 3 arguments");
    valid = false;
  }
}

CyrilBoxOp::CyrilBoxOp (const CyrilBoxOp &other) {
  c = other.c->clone ();
}
CyrilBoxOp::~CyrilBoxOp ()
{
  delete c;
}
void CyrilBoxOp::print() {
  c->print();
  cout << "Box" << endl;
}
Cyril * CyrilBoxOp::clone () {
  return new CyrilBoxOp (*this);
}
int CyrilBoxOp::size() {
  return 0;
}
void CyrilBoxOp::eval(CyrilState &_s) {
  c->eval(_s);
  float x, y, z, w, h, d;
  switch (c->size()) {
    case 3:
      d = _s.stk->top(); _s.stk->pop();
      h = _s.stk->top(); _s.stk->pop();
      w = _s.stk->top(); _s.stk->pop();
      break;
    case 1:
      d = _s.stk->top(); _s.stk->pop();
      h = d;
      w = d;
      break;
    default:
      d = 1;
      h = 1;
      w = 1;
  }
  ofDrawBox(w, h, d);
}

