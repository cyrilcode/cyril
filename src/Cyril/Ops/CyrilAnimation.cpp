//
//  CyrilAnimation.cpp
//  cyril2
//
//  Created by Darren Mothersele on 07/11/2013.
//
//

#include "CyrilAnimation.h"

CyrilAnimation::CyrilAnimation (Cyril* _e) : e(_e) {

}

CyrilAnimation::CyrilAnimation (const CyrilAnimation &other) {
  e = other.e->clone ();
}
CyrilAnimation::~CyrilAnimation ()
{
  delete e;
}
void CyrilAnimation::print() {
  e->print();
  cout << "Animation" << endl;
}
Cyril * CyrilAnimation::clone () {
  return new CyrilAnimation (*this);
}
int CyrilAnimation::size() {
  return 0;
}
void CyrilAnimation::eval(CyrilState &_s) {
  //cout << endl << "Anim start" << endl;
  int total = e->size();
  // Push the total step size and current step time
  _s.stk->push(total);
  _s.stk->push((ofGetElapsedTimeMillis() % total));
  e->eval(_s);
}

