//
//  CyrilSphereOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilSphereOp.h"

CyrilSphereOp::CyrilSphereOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 0 || s == 1)) {
    yyerror("Sphere command requires 0 or 1 argument");
    valid = false;
  }
}

CyrilSphereOp::CyrilSphereOp (const CyrilSphereOp &other) {
  c = other.c->clone ();
}
CyrilSphereOp::~CyrilSphereOp ()
{
  delete c;
}
void CyrilSphereOp::print() {
  c->print();
  cout << "Sphere" << endl;
}
Cyril * CyrilSphereOp::clone () {
  return new CyrilSphereOp (*this);
}
int CyrilSphereOp::size() {
  return 0;
}
void CyrilSphereOp::eval(CyrilState &_s) {
  c->eval(_s);
  float r;
  if (c->size() == 1) {
    r = _s.stk->top();
    _s.stk->pop();
  }
  else {
    r = 1;
  }
  ofDrawSphere(r);
}

