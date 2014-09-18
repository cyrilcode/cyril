//
//  CyrilBloom.cpp
//  cyril
//
//  Created by Darren Mothersele on 15/09/2014.
//
//

#include "CyrilBloom.h"

CyrilBloom::CyrilBloom (Cyril* _e) : e(_e) {
  s = e->size();
  if (!(s == 1 || s == 0)) {
    // Width, Height - or single argument for same w and h
    yyerror("Bloom FX command takes 0 or 1 arguments");
    valid = false;
  }
  prevBloom = 0.001953125;
}

CyrilBloom::CyrilBloom (const CyrilBloom &other) {
  e = other.e->clone ();
}
CyrilBloom::~CyrilBloom ()
{
}
void CyrilBloom::print() {
  cout << "CyrilBloom" << endl;
}
Cyril * CyrilBloom::clone () {
  return new CyrilBloom (*this);
}
int CyrilBloom::size() {
  return 0;
}
void CyrilBloom::update(CyrilState &_s) {
  // FX_BLOOM = 3
  _s.post[3]->enable();
}
void CyrilBloom::eval(CyrilState &_s) {
  float bloom;
  if (s == 1) {
    e->eval(_s);
    bloom = (_s.stk->top()) / 1000.0f;
    _s.stk->pop();
  }
  else {
    // same defaults as ofxPostProcessing:
    bloom = 0.001953125;
  }
  if (bloom != prevBloom) {
    prevBloom = bloom;
    _s.bloom->setIncrements(bloom, 0, 0, bloom);
  }
}


