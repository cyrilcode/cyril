//
//  CyrilAnimStep.cpp
//  cyril2
//
//  Created by Darren Mothersele on 07/11/2013.
//
//

#include "CyrilAnimStep.h"

CyrilAnimStep::CyrilAnimStep (float _n, Cyril* _e1, Cyril* _e2) : n(_n), e1(_e1), e2(_e2) {
  
}

CyrilAnimStep::CyrilAnimStep (const CyrilAnimStep &other) {
  n = other.n;
  e1 = other.e1->clone ();
  e2 = other.e2->clone ();
}
CyrilAnimStep::~CyrilAnimStep ()
{
  delete e1;
  delete e2;
}
void CyrilAnimStep::print() {
  e1->print();
  e2->print();
  cout << "AnimStep " << n << endl;
}
Cyril * CyrilAnimStep::clone () {
  return new CyrilAnimStep (*this);
}
int CyrilAnimStep::size() {
  if (!dynamic_cast<CyrilAnimStep*>(e2)) {
    //cout << " " << n << " " << endl;
    // we're last so just report to stack and we're done
    return n;
  }
  //cout << " " << n + e2->size();
  return n + e2->size();
}
void CyrilAnimStep::eval(CyrilState &_s) {
  int step = _s.stk->top(); _s.stk->pop();
  int total = _s.stk->top(); _s.stk->pop();
  //cout << total << ":" << step << endl;
  if ((total - n) < step) {
    e1->eval(_s);
  }
  else {
    _s.stk->push(total - n);
    _s.stk->push(step);
    e2->eval(_s);
  }
}






