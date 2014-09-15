//
//  CyrilPixelate.cpp
//  cyril
//
//  Created by Darren Mothersele on 15/09/2014.
//
//

#include "CyrilPixelate.h"

CyrilPixelate::CyrilPixelate (Cyril* _e) : e(_e) {
  s = e->size();
  if (!(s == 2 || s == 1 || s == 0)) {
    // Width, Height - or single argument for same w and h
    yyerror("Pixelate FX command takes 0, 1 or 2 arguments");
    valid = false;
  }
}

CyrilPixelate::CyrilPixelate (const CyrilPixelate &other) {
  e = other.e->clone ();
}
CyrilPixelate::~CyrilPixelate ()
{
}
void CyrilPixelate::print() {
  cout << "CyrilPixelate" << endl;
}
Cyril * CyrilPixelate::clone () {
  return new CyrilPixelate (*this);
}
int CyrilPixelate::size() {
  return 0;
}
void CyrilPixelate::update(CyrilState &_s) {
  // FX_PIXELATE = 2
  _s.post[2]->enable();
}
void CyrilPixelate::eval(CyrilState &_s) {
  float width, height;
  if (s == 2) {
    e->eval(_s);
    height = _s.stk->top();
    _s.stk->pop();
    width = _s.stk->top();
    _s.stk->pop();
  }
  else if (s == 1) {
    e->eval(_s);
    height = _s.stk->top();
    width = height;
    _s.stk->pop();
  }
  else {
    // same defaults as ofxPostProcessing:
    width = 100;
    height = 100;
  }
  _s.pixelate->setResolution(width, height);
}

