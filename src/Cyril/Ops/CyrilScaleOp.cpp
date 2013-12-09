//
//  CyrilScaleOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilScaleOp.h"
#include "CyrilState.h"

CyrilScaleOp::CyrilScaleOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 1 || s == 3)) {
    yyerror("Scale command requires 1 or 3 arguments");
    valid = false;
  }
}

CyrilScaleOp::CyrilScaleOp (const CyrilScaleOp &other) {
  c = other.c->clone ();
}
CyrilScaleOp::~CyrilScaleOp ()
{
  delete c;
}
void CyrilScaleOp::print() {
  c->print();
  cout << "Scale" << endl;
}
Cyril * CyrilScaleOp::clone () {
  return new CyrilScaleOp (*this);
}
int CyrilScaleOp::size() {
  return 0;
}
void CyrilScaleOp::eval(CyrilState &_s) {
  c->eval(_s);
  float x, y, z;
  switch (c->size()) {
    case 3:
      z = _s.stk->top(); _s.stk->pop();
      y = _s.stk->top(); _s.stk->pop();
      x = _s.stk->top(); _s.stk->pop();
      break;
    case 1:
      z = _s.stk->top(); _s.stk->pop();
      y = z;
      x = z;
      break;
  }
  ofScale(x, y, z);
  _s.ms->scale(x, y, z);
}

