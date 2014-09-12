//
//  CyrilKaleidoscope.cpp
//  cyril
//
//  Created by Darren Mothersele on 12/09/2014.
//
//

#include "CyrilKaleidoscope.h"

CyrilKaleidoscope::CyrilKaleidoscope (Cyril* _e) : e(_e) {
  int s = e->size();
  if (!(s == 1)) {
    yyerror("Kaleidoscope command takes 1 argument");
    valid = false;
  }
}

CyrilKaleidoscope::CyrilKaleidoscope (const CyrilKaleidoscope &other) {
  e = other.e->clone ();
}
CyrilKaleidoscope::~CyrilKaleidoscope ()
{
}
void CyrilKaleidoscope::print() {
  cout << "Kaleidoscope" << endl;
}
Cyril * CyrilKaleidoscope::clone () {
  return new CyrilKaleidoscope (*this);
}
int CyrilKaleidoscope::size() {
  return 0;
}
void CyrilKaleidoscope::update(CyrilState &_s) {
  // FX_KALEIDOSCOPE = 0
  _s.post[0]->enable();
}
void CyrilKaleidoscope::eval(CyrilState &_s) {
  e->eval(_s);
  float d = _s.stk->top();
  _s.stk->pop();
  _s.kaleido->setSegments(d);
}

