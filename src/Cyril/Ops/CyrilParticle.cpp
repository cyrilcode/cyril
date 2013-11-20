//
//  CyrilParticle.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilParticle.h"


CyrilParticle::CyrilParticle (const CyrilParticle &other) {
  e = other.e->clone();
  c = other.c->clone();
}
CyrilParticle::~CyrilParticle () {
  delete e;
  delete c;
}

void CyrilParticle::print() {
  e->print();
  c->print();
  cout << "Particle" << endl;
}

Cyril* CyrilParticle::clone () {
  return new CyrilParticle (*this);
}

int CyrilParticle::size() {
  return 0;
}
  
void CyrilParticle::eval(CyrilState &_s) {
  e->eval(_s);
  float x, y, z, w, h, d;
  
  switch (e->size()) {
    case 1:
      d = 0;
      h = 0;
      w = 0;
      x = _s.stk->top(); _s.stk->pop();
      break;
    case 4:
      d = _s.stk->top(); _s.stk->pop();
      h = _s.stk->top(); _s.stk->pop();
      w = _s.stk->top(); _s.stk->pop();
      x = _s.stk->top(); _s.stk->pop();
      break;
  }
  //cout << "Release particle at " << x << ", " << y << ", " << z << endl;
  //GLfloat matrix[16];
  //glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
  //ofMatrix4x4 m(matrix);
  _s.ps->push_back(new Particle(_s.ms->getCurrentMatrix(), ofVec3f(x,0,0), ofVec3f(w,h,d),
                            (*_s.sym)[REG_PARTICLE_HEALTH], (*_s.sym)[REG_PARTICLE_DECAY], c));
}
