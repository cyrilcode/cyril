//
//  CyrilBackgroundOp.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilBackgroundOp.h"
#include "CyrilState.h"

CyrilBackgroundOp::CyrilBackgroundOp (Cyril* _c) : CyrilOp(_c) {
  int s = c->size();
  if (!(s == 4 || s == 3 || s == 1)) {
    yyerror("background command requires 1 (palette) or 3 arguments (r,g,b) or a hex color");
    valid = false;
  }
}

CyrilBackgroundOp::CyrilBackgroundOp (const CyrilBackgroundOp &other) {
  c = other.c->clone ();
}
CyrilBackgroundOp::~CyrilBackgroundOp ()
{
  delete c;
}
void CyrilBackgroundOp::print() {
  c->print();
  cout << "Background" << endl;
}
Cyril * CyrilBackgroundOp::clone () {
  return new CyrilBackgroundOp (*this);
}
int CyrilBackgroundOp::size() {
  return 0;
}
void CyrilBackgroundOp::eval(CyrilState &_s) {
  c->eval(_s);
  float r, g, b;
  float a = 255.0;
  if (c->size() == 4) {
    a = _s.stk->top(); _s.stk->pop();
    b = _s.stk->top(); _s.stk->pop();
    g = _s.stk->top(); _s.stk->pop();
    r = _s.stk->top(); _s.stk->pop();
    //ofBackground(r, g, b, a);
    ofClear(r, g, b, a);
    //cout << "Background " << r << "," << g <<  "," << b <<  "," << a << endl;
    //ofPushStyle();
    //ofSetColor(r, g, b, a);
    //ofRect(-(*_s.sym)[REG_X_MID], -(*_s.sym)[REG_Y_MID], (*_s.sym)[REG_X_MAX], (*_s.sym)[REG_Y_MAX]);
    //ofPopStyle();
    
    return;
  }
  if (c->size() == 3) {
    b = _s.stk->top(); _s.stk->pop();
    g = _s.stk->top(); _s.stk->pop();
    r = _s.stk->top(); _s.stk->pop();
    //ofBackground(r, g, b);
    ofClear(r, g, b, a);
    return;
  }
  else {
    b = _s.stk->top(); _s.stk->pop();
    // load palette from b
    (*_s.cs)[b]->drawBackground();
  }
}

