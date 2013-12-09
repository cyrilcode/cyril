//
//  CyrilRectOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilRectOp.h"
#include "CyrilState.h"

CyrilRectOp::CyrilRectOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 0 || s == 1 || s == 2)) {
    yyerror("Rect command requires 0, 1 or 2 arguments");
    valid = false;
  }
}

CyrilRectOp::CyrilRectOp (const CyrilRectOp &other) {
  c = other.c->clone ();
}
CyrilRectOp::~CyrilRectOp ()
{
  delete c;
}
void CyrilRectOp::print() {
  c->print();
  cout << "Rect" << endl;
}
Cyril * CyrilRectOp::clone () {
  return new CyrilRectOp (*this);
}
int CyrilRectOp::size() {
  return 0;
}
void CyrilRectOp::eval(CyrilState &_s) {
  c->eval(_s);
  float w, h;
  switch (c->size()) {
    case 2:
      h = _s.stk->top(); _s.stk->pop();
      w = _s.stk->top(); _s.stk->pop();
      break;
    case 1:
      h = _s.stk->top(); _s.stk->pop();
      w = h;
      break;
    case 0:
      h = 1;
      w = 1;
      break;
  }
  ofDrawBox(w, h, 1);
}

