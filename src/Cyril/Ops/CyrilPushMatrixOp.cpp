//
//  CyrilPushMatrixOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilPushMatrixOp.h"
#include "CyrilState.h"

CyrilPushMatrixOp::CyrilPushMatrixOp (Cyril* _c) : CyrilOp(_c) {
  if (_c->size() != 0) {
    yyerror("pushMatrix command requires 0 arguments");
    valid = false;
  }
}

CyrilPushMatrixOp::CyrilPushMatrixOp (const CyrilPushMatrixOp &other) {
  c = other.c->clone ();
}
CyrilPushMatrixOp::~CyrilPushMatrixOp ()
{
  delete c;
}
void CyrilPushMatrixOp::print() {
  c->print();
  cout << "PushMatrix" << endl;
}
Cyril * CyrilPushMatrixOp::clone () {
  return new CyrilPushMatrixOp (*this);
}
int CyrilPushMatrixOp::size() {
  return 0;
}
void CyrilPushMatrixOp::eval(CyrilState &_s) {
  ofPushMatrix();
  _s.ms->pushMatrix();
}


int CyrilPushMatrixOp::matchPushPop() { return -1; }

