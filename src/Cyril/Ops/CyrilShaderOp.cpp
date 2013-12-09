//
//  CyrilShaderOp.cpp
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#include "CyrilShaderOp.h"
#include "CyrilState.h"

CyrilShaderOp::CyrilShaderOp (int _i, Cyril* _c) : n(_i), c(_c) {
  valid = c->valid;
}

CyrilShaderOp::CyrilShaderOp (const CyrilShaderOp &other) {
  n = other.n;
  c = other.c->clone ();
}
CyrilShaderOp::~CyrilShaderOp ()
{
  delete c;
}
void CyrilShaderOp::print() {
  c->print();
  cout << "Shader " << n << endl;
}
Cyril * CyrilShaderOp::clone () {
  return new CyrilShaderOp (*this);
}
int CyrilShaderOp::size() {
  return 0;
}
void CyrilShaderOp::eval(CyrilState &_s) {
  if ((*_s.shaders)[n]->isLoaded()) {
    (*_s.shaders)[n]->begin();
    
    // Evaluate any Shader uniform requirements
    (*_s.shaders)[n]->evalUniforms(n, &_s);
    
    // Evaluate program inside shader
    c->eval(_s);
    
    (*_s.shaders)[n]->end();
  }
  else {
    c->eval(_s);
  }
}

//(*_s.shaders)[(*_s.sym)[REG_CURRENT_SHADER]]->setUniform1f(n, f1);
