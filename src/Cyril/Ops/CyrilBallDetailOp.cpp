//
//  CyrilBallDetailOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilBallDetailOp.h"
#include "CyrilState.h"

CyrilBallDetailOp::CyrilBallDetailOp (Cyril* _c) : CyrilOp(_c) {
  if (_c->size() != 1) {
    yyerror("BallDetail command requires 1 argument");
    valid = false;
  }
}

CyrilBallDetailOp::CyrilBallDetailOp (const CyrilBallDetailOp &other) {
  c = other.c->clone ();
}
CyrilBallDetailOp::~CyrilBallDetailOp ()
{
  delete c;
}
void CyrilBallDetailOp::print() {
  c->print();
  cout << "BallDetail" << endl;
}
Cyril * CyrilBallDetailOp::clone () {
  return new CyrilBallDetailOp (*this);
}
int CyrilBallDetailOp::size() {
  return 0;
}
void CyrilBallDetailOp::eval(CyrilState &_s) {
  c->eval(_s);
  float d = _s.stk->top();
  _s.stk->pop();
  if (d > 5) d = 5;
  ofSetIcoSphereResolution(d);
}

