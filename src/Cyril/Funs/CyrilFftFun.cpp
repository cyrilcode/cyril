//
//  CyrilFftFun.cpp
//  Cyril
//
//  Created by Darren Mothersele on 15/11/2013.
//
//

#include "CyrilFftFun.h"

CyrilFftFun::CyrilFftFun(Cyril * _c) : CyrilFun(_c) {
  int s = _c->size();
  if (!(s == 1)) {
    yyerror("FFT function has 1 argument");
    valid = false;
  }
}

CyrilFftFun::CyrilFftFun(const CyrilFftFun &other) {
  c = other.c->clone ();
}
CyrilFftFun::~CyrilFftFun () {
  delete c;
}
void CyrilFftFun::print() {
  c->print();
  cout << "Palette" << endl;
}
Cyril * CyrilFftFun::clone () {
  return new CyrilFftFun (*this);
}
int CyrilFftFun::size() {
  return 1;
}
void CyrilFftFun::eval(CyrilState &_s) {
  c->eval(_s);
  int d = _s.stk->top(); _s.stk->pop();
  //cout << "FFT of " << (d % 32) << endl;
  //float f = fftSubbands[d % 32];

  _s.stk->push((*_s.sym)[REG_BEAT_FFT_START + (d % 32)]);
}



