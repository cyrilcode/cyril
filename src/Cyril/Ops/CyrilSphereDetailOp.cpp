//
//  CyrilSphereDetailOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilSphereDetailOp.h"

CyrilSphereDetailOp::CyrilSphereDetailOp (Cyril* _c) : CyrilOp(_c) {
  if (_c->size() != 1) {
    yyerror("SphereDetail command requires 1 argument");
    valid = false;
  }
}

CyrilSphereDetailOp::CyrilSphereDetailOp (const CyrilSphereDetailOp &other) {
  c = other.c->clone ();
}
CyrilSphereDetailOp::~CyrilSphereDetailOp ()
{
  delete c;
}
void CyrilSphereDetailOp::print() {
  c->print();
  cout << "SphereDetail" << endl;
}
Cyril * CyrilSphereDetailOp::clone () {
  return new CyrilSphereDetailOp (*this);
}
int CyrilSphereDetailOp::size() {
  return 0;
}
void CyrilSphereDetailOp::eval(CyrilState &_s) {
  c->eval(_s);
  float d = _s.stk->top();
  _s.stk->pop();
  ofSetSphereResolution(d);
}

