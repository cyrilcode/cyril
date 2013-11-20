//
//  CyrilOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilOp.h"

CyrilOp::CyrilOp (Cyril* _c) : c(_c) {
  
}

CyrilOp::CyrilOp (const CyrilOp &other) {
  c = other.c->clone ();
}
CyrilOp::~CyrilOp ()
{
  delete c;
}
void CyrilOp::print() {
  c->print();
  cout << "No Op" << endl;
}
Cyril * CyrilOp::clone () { return new CyrilOp (*this); }
int CyrilOp::size() { return 0; }
void CyrilOp::eval(CyrilState &_s) {
  
}

