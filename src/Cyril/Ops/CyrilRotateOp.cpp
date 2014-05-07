//
//  CyrilRotateOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilRotateOp.h"

CyrilRotateOp::CyrilRotateOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 0 || s == 1 || s == 3 || s == 4)) {
    yyerror("Rotate command requires 4, 3, 1 or 0 arguments");
    valid = false;
  }
}

CyrilRotateOp::CyrilRotateOp (const CyrilRotateOp &other) {
  c = other.c->clone ();
}
CyrilRotateOp::~CyrilRotateOp ()
{
  delete c;
}
void CyrilRotateOp::print() {
  c->print();
  cout << "Rotate" << endl;
}
Cyril * CyrilRotateOp::clone () {
  return new CyrilRotateOp (*this);
}
int CyrilRotateOp::size() {
  return 0;
}
void CyrilRotateOp::eval(CyrilState &_s) {
  c->eval(_s);
  float w, x, y, z;
  switch (c->size()) {
    case 4:
      z = _s.stk->top(); _s.stk->pop();
      y = _s.stk->top(); _s.stk->pop();
      x = _s.stk->top(); _s.stk->pop();
      w = _s.stk->top(); _s.stk->pop();
      ofRotate(w, x, y, z);
      _s.ms->rotate(w, x, y, z);
      break;
    case 3:
      y = _s.stk->top(); _s.stk->pop();
      x = _s.stk->top(); _s.stk->pop();
      w = _s.stk->top(); _s.stk->pop();
      ofRotateX(x);
      ofRotateY(y);
      ofRotateZ(z);
      _s.ms->rotate(x, 1, 0, 0);
      _s.ms->rotate(y, 0, 1, 0);
      _s.ms->rotate(z, 0, 0, 1);
      break;
    case 1:
      w = _s.stk->top(); _s.stk->pop();
      ofRotateZ(w);
      _s.ms->rotate(w, 0, 0, 1);
      break;
    default:
      w = (*_s.sym)[REG_TIME] / 36.0;
      ofRotate(w, 0, 1, 0.5);
      _s.ms->rotate(w, 0, 1, 0.5);/*
      w = (*_s.sym)[REG_TIME] / 64.0;
      ofRotate(w, 0, 0, 1);
      _s.ms->rotate(w, 0, 0, 1);*/
      break;
  }
}

