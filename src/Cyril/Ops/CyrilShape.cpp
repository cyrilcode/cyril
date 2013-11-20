//
//  CyrilShape.cpp
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#include "CyrilShape.h"

CyrilShape::CyrilShape (Cyril* _e) : e(_e) {
  
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
  ofBeginShape();
  e->eval(_s);
  ofEndShape();
}

