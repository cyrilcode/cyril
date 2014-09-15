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
  if (!(s == 3 || s == 0)) {
    // FREQ, AMP, SPEED
    yyerror("Pixelate FX command takes 0 arguments");
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
  // do nothing
}

