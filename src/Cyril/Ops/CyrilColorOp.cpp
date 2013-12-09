//
//  CyrilColorOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilColorOp.h"
#include "CyrilState.h"

CyrilColorOp::CyrilColorOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 1 || s == 2 || s == 3 || s == 4)) {
    yyerror("Color command needs 1, 2, 3 or 4 arguments");
    valid = false;
  }
}

CyrilColorOp::CyrilColorOp (const CyrilColorOp &other) {
  c = other.c->clone ();
}
CyrilColorOp::~CyrilColorOp ()
{
  delete c;
}
void CyrilColorOp::print() {
  c->print();
  cout << "Color" << endl;
}
Cyril * CyrilColorOp::clone () {
  return new CyrilColorOp (*this);
}
int CyrilColorOp::size() {
  return 0;
}
void CyrilColorOp::eval(CyrilState &_s) {
  c->eval(_s);
  float r, g, b, a;
  switch (c->size()) {
    case 4:
      a = _s.stk->top(); _s.stk->pop();
      b = _s.stk->top(); _s.stk->pop();
      g = _s.stk->top(); _s.stk->pop();
      r = _s.stk->top(); _s.stk->pop();
      break;
    case 3:
      a = 255;
      b = _s.stk->top(); _s.stk->pop();
      g = _s.stk->top(); _s.stk->pop();
      r = _s.stk->top(); _s.stk->pop();
      break;
    case 2:
      a = _s.stk->top(); _s.stk->pop();
      b = _s.stk->top(); _s.stk->pop();
      g = b;
      r = b;
      break;
    case 1:
      a = 255;
      b = _s.stk->top(); _s.stk->pop();
      g = b;
      r = b;
      break;
  }
  ofSetColor(r, g, b, a);
}

