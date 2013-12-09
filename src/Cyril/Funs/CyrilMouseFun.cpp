//
//  CyrilMouseFun.cpp
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#include "CyrilMouseFun.h"

#include "CyrilState.h"

CyrilMouseFun::CyrilMouseFun(Cyril* _c) : CyrilFun(_c) {
  int s = c->size();
  if (!(s == 0 || s == 1)) {
    yyerror("Mouse function take 0 or 1 argument");
    valid = false;
  }
  else {
    valid = c->valid;
  }
}

CyrilMouseFun::CyrilMouseFun(const CyrilMouseFun &other) {
  c = other.c->clone ();
}
CyrilMouseFun::~CyrilMouseFun () {
  delete c;
}
void CyrilMouseFun::print() {
  c->print();
  cout << "Mouse function" << endl;
}
Cyril * CyrilMouseFun::clone () {
  return new CyrilMouseFun (*this);
}
int CyrilMouseFun::size() {
  if (c->size() == 1) {
    return 1;
  }
  return 2;
}
void CyrilMouseFun::eval(CyrilState &_s) {
  switch (c->size()) {
    case 1:
      c->eval(_s);
      if (_s.stk->top() == 0) {
        _s.stk->push(((*_s.sym)[REG_MOUSE_X]) / _s.ms->getCurrentMatrix().getScale().x);
      }
      else {
        _s.stk->push(((*_s.sym)[REG_MOUSE_Y]) / _s.ms->getCurrentMatrix().getScale().y);
      }
      break;
    default:
      _s.stk->push(((*_s.sym)[REG_MOUSE_X]) / _s.ms->getCurrentMatrix().getScale().x);
      _s.stk->push(((*_s.sym)[REG_MOUSE_Y]) / _s.ms->getCurrentMatrix().getScale().y);
  }
}

