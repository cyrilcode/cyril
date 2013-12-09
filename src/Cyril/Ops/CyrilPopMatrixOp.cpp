//
//  CyrilPopMatrix.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilPopMatrixOp.h"
#include "CyrilState.h"

CyrilPopMatrixOp::CyrilPopMatrixOp (Cyril* _c) : CyrilOp(_c) {
  if (_c->size() != 0) {
    yyerror("popMatrix command requires 0 arguments");
    valid = false;
  }
}

CyrilPopMatrixOp::CyrilPopMatrixOp (const CyrilPopMatrixOp &other) {
  c = other.c->clone ();
}
CyrilPopMatrixOp::~CyrilPopMatrixOp ()
{
  delete c;
}
void CyrilPopMatrixOp::print() {
  c->print();
  cout << "PopMatrix" << endl;
}
Cyril * CyrilPopMatrixOp::clone () {
  return new CyrilPopMatrixOp (*this);
}
int CyrilPopMatrixOp::size() {
  return 0;
}
void CyrilPopMatrixOp::eval(CyrilState &_s) {
  ofPopMatrix();
  _s.ms->popMatrix();
}
int CyrilPopMatrixOp::matchPushPop() { return 1; }
