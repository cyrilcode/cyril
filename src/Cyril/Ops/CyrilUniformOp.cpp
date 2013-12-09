//
//  CyrilUniformOp.cpp
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#include "CyrilUniformOp.h"

#include "CyrilState.h"

CyrilUniformOp::CyrilUniformOp (string _s, Cyril* _e) : n(_s), e(_e) {
  int s = e->size();
  if (!(s == 1 || s == 2 || s == 3 || s == 4)) {
    yyerror("Uniform command takes 1, 2, 3 or 4 arguments");
    valid = false;
  }
  else {
    valid = e->valid;
  }
}

CyrilUniformOp::CyrilUniformOp (const CyrilUniformOp &other) {
  e = other.e->clone ();
}
CyrilUniformOp::~CyrilUniformOp ()
{
  delete e;
}
void CyrilUniformOp::print() {
  e->print();
  cout << "Uniform" << endl;
}
Cyril * CyrilUniformOp::clone () {
  return new CyrilUniformOp (*this);
}
int CyrilUniformOp::size() {
  return 0;
}
void CyrilUniformOp::eval(CyrilState &_s) {
  // if count of CURRENT_SHADER key then no req shader number so skip
  // else evaluate the e and assign values to uniform in shader
  //cout << (*_s.sym)[REG_CURRENT_SHADER] << endl;
  e->eval(_s);
  float f1,f2,f3,f4;
  switch (e->size()) {
    case 1:
      f1 = _s.stk->top(); _s.stk->pop();
      (*_s.shaders)[(*_s.sym)[REG_CURRENT_SHADER]]->setUniform1f(n, f1);
      break;
    case 2:
      f2 = _s.stk->top(); _s.stk->pop();
      f1 = _s.stk->top(); _s.stk->pop();
      (*_s.shaders)[(*_s.sym)[REG_CURRENT_SHADER]]->setUniform2f(n, f1, f2);
      break;
    case 3:
      f3 = _s.stk->top(); _s.stk->pop();
      f2 = _s.stk->top(); _s.stk->pop();
      f1 = _s.stk->top(); _s.stk->pop();
      (*_s.shaders)[(*_s.sym)[REG_CURRENT_SHADER]]->setUniform3f(n, f1, f2, f3);
      break;
    case 4:
      f4 = _s.stk->top(); _s.stk->pop();
      f3 = _s.stk->top(); _s.stk->pop();
      f2 = _s.stk->top(); _s.stk->pop();
      f1 = _s.stk->top(); _s.stk->pop();
      (*_s.shaders)[(*_s.sym)[REG_CURRENT_SHADER]]->setUniform4f(n, f1, f2, f3, f4);
      break;
  }
}

