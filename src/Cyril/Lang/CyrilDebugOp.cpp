//
//  CyrilDebugOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilDebugOp.h"

CyrilDebugOp::CyrilDebugOp (Cyril* _c) : CyrilOp(_c) {

}

CyrilDebugOp::CyrilDebugOp (const CyrilDebugOp &other) {
  c = other.c->clone ();
}
CyrilDebugOp::~CyrilDebugOp ()
{
  delete c;
}
void CyrilDebugOp::print() {
  c->print();
  cout << "Debug" << endl;
}
Cyril * CyrilDebugOp::clone () {
  return new CyrilDebugOp (*this);
}
int CyrilDebugOp::size() {
  return 0;
}
void CyrilDebugOp::eval(CyrilState &_s) {
  c->eval(_s);
  cout << "DEBUG:";
  int sz = c->size();
  for (int i = 0; i < sz; i++) {
    cout << " " << _s.stk->top();
    _s.stk->pop();
  }
  cout << endl;
}

