//
//  CyrilPegOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilPegOp.h"

CyrilPegOp::CyrilPegOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 0 || s == 1 || s == 2)) {
    yyerror("Peg command requires 0, 1 or 2 arguments");
    valid = false;
  }
}

CyrilPegOp::CyrilPegOp (const CyrilPegOp &other) {
  c = other.c->clone ();
}
CyrilPegOp::~CyrilPegOp ()
{
  delete c;
}
void CyrilPegOp::print() {
  c->print();
  cout << "Peg" << endl;
}
Cyril * CyrilPegOp::clone () {
  return new CyrilPegOp (*this);
}
int CyrilPegOp::size() {
  return 0;
}
void CyrilPegOp::eval(CyrilState &_s) {
  c->eval(_s);
  float r, h;
  switch (c->size()) {
    case 2:
      h = _s.stk->top(); _s.stk->pop();
      r = _s.stk->top(); _s.stk->pop();
      break;
    case 1:
      h = _s.stk->top(); _s.stk->pop();
      r = h;
      break;
    case 0:
      h = 1;
      r = 1;
      break;
  }
  ofDrawCylinder(r, h);
}

