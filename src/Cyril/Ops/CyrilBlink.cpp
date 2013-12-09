//
//  CyrilBlink.cpp
//  cyril2
//
//  Created by Darren Mothersele on 07/11/2013.
//
//

#include "CyrilBlink.h"
#include "CyrilState.h"

CyrilBlink::CyrilBlink (Cyril* _e, Cyril* _c) : e(_e), c(_c) {
  if (_e->size() != 2) {
    yyerror("Blink command requires on and off times");
    valid = false;
  }
}

CyrilBlink::CyrilBlink (const CyrilBlink &other) {
  e = other.e->clone ();
  c = other.c->clone ();
}
CyrilBlink::~CyrilBlink ()
{
  delete e;
  delete c;
}
void CyrilBlink::print() {
  e->print();
  c->print();
  cout << "Blink" << endl;
}
Cyril * CyrilBlink::clone () {
  return new CyrilBlink (*this);
}
int CyrilBlink::size() {
  return 0;
}
void CyrilBlink::eval(CyrilState &_s) {
  e->eval(_s);
  float v2 = _s.stk->top();
  _s.stk->pop();
  float v1 = _s.stk->top();
  _s.stk->pop();
  //float t = (ofGetElapsedTimeMillis() / 1000.0);
  if ((v1 + v2) == 0) {
    cout << "Mod by 0 error in blink" << endl;
    return;
  }
  if ((ofGetElapsedTimeMillis() % int(v1 + v2)) < v1) {
    c->eval(_s);
  }
}

