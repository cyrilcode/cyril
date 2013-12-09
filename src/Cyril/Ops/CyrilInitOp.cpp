//
//  CyrilInitOp.cpp
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#include "CyrilInitOp.h"
#include "CyrilState.h"

CyrilInitOp::CyrilInitOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 0)) {
    yyerror("Init command takes 0 arguments");
    valid = false;
  }
}

CyrilInitOp::CyrilInitOp (const CyrilInitOp &other) {
  c = other.c->clone ();
}
CyrilInitOp::~CyrilInitOp ()
{
  delete c;
}
void CyrilInitOp::print() {
  c->print();
  cout << "Init" << endl;
}
Cyril * CyrilInitOp::clone () {
  return new CyrilInitOp (*this);
}
int CyrilInitOp::size() {
  return 0;
}
void CyrilInitOp::eval(CyrilState &_s) {
  if ((*_s.sym)[REG_FRAME] == 0) {
    c->eval(_s);
  }
}

