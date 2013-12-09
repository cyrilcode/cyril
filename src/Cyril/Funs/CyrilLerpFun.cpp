//
//  CyrilLerpFun.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilLerpFun.h"
#include "CyrilState.h"

CyrilLerpFun::CyrilLerpFun(Cyril * _c) : CyrilFun(_c) {
  int s = _c->size();
  if (!(s == 2 || s == 3 || s == 7)) {
    yyerror("Lerp function has 2 or 3 arguments (or 7 with colors)");
    valid = false;
  }
}

CyrilLerpFun::CyrilLerpFun(const CyrilLerpFun &other) {
  c = other.c->clone ();
}
CyrilLerpFun::~CyrilLerpFun () {
  delete c;
}
void CyrilLerpFun::print() {
  c->print();
  cout << "Lerp" << endl;
}
Cyril * CyrilLerpFun::clone () {
  return new CyrilLerpFun (*this);
}
int CyrilLerpFun::size() {
  int sz = c->size();
  if (sz == 2 || sz == 7) {
    return 3;
  }
  return 1;
}
void CyrilLerpFun::eval(CyrilState &_s) {
  c->eval(_s);
  float i, v1, v2, v3;
  ofColor _c;
  switch (c->size()) {
    case 2:
      i = _s.stk->top(); _s.stk->pop();
      v1 = _s.stk->top(); _s.stk->pop();
      if (_s.cs->count(v1)) {
        _c = (*_s.cs)[v1]->lerp(i);
      }
      else if (_s.parent->cs->count(v1)) {
        _c = (*_s.parent->cs)[v1]->lerp(i);
      }
      else {
        //cout << "Error: can't find palette!" << endl;
        _s.stk->push(255);
        _s.stk->push(255);
        _s.stk->push(255);
        break;
      }
      _s.stk->push(_c.r);
      _s.stk->push(_c.g);
      _s.stk->push(_c.b);
      break;
    case 3:
      i = _s.stk->top(); _s.stk->pop();
      v2 = _s.stk->top(); _s.stk->pop();
      v1 = _s.stk->top(); _s.stk->pop();
      _s.stk->push(ofLerp(v1, v2, i));
      break;
    case 7:
      i = _s.stk->top(); _s.stk->pop();
      v3 = _s.stk->top(); _s.stk->pop();
      v2 = _s.stk->top(); _s.stk->pop();
      v1 = _s.stk->top(); _s.stk->pop();
      ofColor source(v1, v2, v3);
      v3 = _s.stk->top(); _s.stk->pop();
      v2 = _s.stk->top(); _s.stk->pop();
      v1 = _s.stk->top(); _s.stk->pop();
      ofColor result = ofColor(v1, v2, v3).lerp(source, i);
      _s.stk->push(result.r);
      _s.stk->push(result.g);
      _s.stk->push(result.b);
  }
}

