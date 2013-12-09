//
//  CyrilImgOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilImgOp.h"
#include "CyrilState.h"

CyrilImgOp::CyrilImgOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 1)) {
    yyerror("Image command requires 1 argument");
    valid = false;
  }
}

CyrilImgOp::CyrilImgOp (const CyrilImgOp &other) {
  c = other.c->clone ();
}
CyrilImgOp::~CyrilImgOp ()
{
  delete c;
}
void CyrilImgOp::print() {
  c->print();
  cout << "Image" << endl;
}
Cyril * CyrilImgOp::clone () {
  return new CyrilImgOp (*this);
}
int CyrilImgOp::size() {
  return 0;
}
void CyrilImgOp::eval(CyrilState &_s) {
  c->eval(_s);
  float i;
  i = _s.stk->top(); _s.stk->pop();
  ofScale(0.01, 0.01, 0.01);
  if (_s.img->count(i)) {
    _s.img->at(i)->draw(0, 0, 0);
  }
  // TODO: recurse up the parent tree
  else if (_s.parent) {
    if (_s.parent->img->count(i)) {
      _s.parent->img->at(i)->draw(0, 0, 0);
    }
  }
  ofScale(100, 100, 100);
}
