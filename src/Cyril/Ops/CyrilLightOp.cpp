//
//  CyrilLightOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilLightOp.h"
#include "CyrilState.h"

CyrilLightOp::CyrilLightOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 3 || s == 6)) {
    yyerror("Light command requires 3 or 6 arguments");
    valid = false;
  }
}

CyrilLightOp::CyrilLightOp (const CyrilLightOp &other) {
  c = other.c->clone ();
}
CyrilLightOp::~CyrilLightOp ()
{
  delete c;
}
void CyrilLightOp::print() {
  c->print();
  cout << "Light" << endl;
}
Cyril * CyrilLightOp::clone () {
  return new CyrilLightOp (*this);
}
int CyrilLightOp::size() {
  return 0;
}
void CyrilLightOp::eval(CyrilState &_s) {
  if (_s.light != NULL) {
    c->eval(_s);
    float x, y, z, a;
    switch (c->size()) {
      case 3:
        z = _s.stk->top(); _s.stk->pop();
        y = _s.stk->top(); _s.stk->pop();
        x = _s.stk->top(); _s.stk->pop();
        _s.light->setPosition(x, y, z);
        break;
      case 6:
        z = _s.stk->top(); _s.stk->pop();
        y = _s.stk->top(); _s.stk->pop();
        x = _s.stk->top(); _s.stk->pop();
        //_s.light->setAmbientColor(ofColor(x, y, z));
        _s.light->setDiffuseColor(ofColor(x, y, z));
        //_s.light->setAmbientColor(ofColor(x, y, z));
        z = _s.stk->top(); _s.stk->pop();
        y = _s.stk->top(); _s.stk->pop();
        x = _s.stk->top(); _s.stk->pop();
        //_s.light->setSpecularColor(ofColor(x, y, z));
        _s.light->setAmbientColor(ofColor(x, y, z));
        break;
    }
  }
}

