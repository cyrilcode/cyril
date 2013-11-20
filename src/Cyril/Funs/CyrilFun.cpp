//
//  CyrilFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilFun.h"

CyrilFun::CyrilFun(Cyril* _c) : c(_c) {
}

CyrilFun::CyrilFun (const CyrilFun &other) {
  c = other.c->clone ();
}
CyrilFun::~CyrilFun () {
  delete c;
}
void CyrilFun::print() {
  c->print();
  cout << "No Fun" << endl;
}
Cyril * CyrilFun::clone () {
  return new CyrilFun (*this);
}
int CyrilFun::size() {
  return 1;
}
void CyrilFun::eval(CyrilState &_state) {
  _state.stk->push(0);
}



