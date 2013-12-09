//
//  CyrilShape.cpp
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#include "CyrilShape.h"


/*OF_POLY_WINDING_ODD - OF_POLY_WINDING_NONZERO - OF_POLY_WINDING_POSITIVE - OF_POLY_WINDING_NEGATIVE - OF_POLY_WINDING_ABS_GEQ_TWO -*/

CyrilShape::CyrilShape (string _m, Cyril* _e) : e(_e) {
  if (_m == "odd") {
    polyMode = OF_POLY_WINDING_ODD;
  }
  else if (_m == "non") {
    polyMode = OF_POLY_WINDING_NONZERO;
  }
  else if (_m == "pos") {
    polyMode = OF_POLY_WINDING_POSITIVE;
  }
  else if (_m == "neg") {
    polyMode = OF_POLY_WINDING_NEGATIVE;
  }
  else if (_m == "abs") {
    polyMode = OF_POLY_WINDING_ABS_GEQ_TWO;
  }
  else {
    polyMode = OF_POLY_WINDING_ODD;
  }
  valid = e->valid;
}

CyrilShape::CyrilShape (const CyrilShape &other) {
  e = other.e->clone ();
}
CyrilShape::~CyrilShape ()
{
  delete e;
}
void CyrilShape::print() {
  e->print();
  cout << "Shape" << endl;
}
Cyril * CyrilShape::clone () {
  return new CyrilShape (*this);
}
int CyrilShape::size() {
  return 0;
}
void CyrilShape::eval(CyrilState &_s) {
  ofSetPolyMode(polyMode);
  ofBeginShape();
  e->eval(_s);
  ofEndShape();
}

