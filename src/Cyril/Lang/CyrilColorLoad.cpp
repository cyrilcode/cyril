//
//  CyrilColorLoad.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilColorLoad.h"


CyrilColorLoad::CyrilColorLoad(int _i) : loc(_i) {
  valid = true;
}
CyrilColorLoad::CyrilColorLoad (const CyrilColorLoad &other) {
  loc = other.loc;
}
CyrilColorLoad::~CyrilColorLoad ()
{
}
void CyrilColorLoad::print() {
  cout << "Color Load: " << loc << endl;
}
Cyril * CyrilColorLoad::clone () { return new CyrilColorLoad (*this); }
int CyrilColorLoad::size() {
  return 3;
}
void CyrilColorLoad::eval(CyrilState &_s) {
  ofColor c = ofColor::fromHex((*_s.sym)[loc]);
  //cout << "Load color: " << c << endl;
  _s.stk->push(float(c.r));
  _s.stk->push(float(c.g));
  _s.stk->push(float(c.b));
}

