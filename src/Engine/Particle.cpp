//
//  Particle.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "Particle.h"

Particle::~Particle() {
  delete shape;
}

void Particle::draw(CyrilState * _s) {
  
  ofPushMatrix();
  ofGetCurrentRenderer()->multMatrix(origin);
  ofGetCurrentRenderer()->multMatrix(location);
  
  CyrilState _sub_state;
  _sub_state.stk = new stack<float>;
  _sub_state.ms = new ofMatrixStack(*ofGetWindowPtr());
  _sub_state.ps = new vector<Particle*>;
  _sub_state.sym = new map<int, float>;
  _sub_state.cs = new map<int, Palette *>;
  _sub_state.img = new map<int, ofImage *>;
  (*_sub_state.sym)[REG_PARTICLE_HEALTH] = health;
  (*_sub_state.sym)[REG_PARTICLE_DECAY] = decay;
  _sub_state.parent = _s;
  
  shape->eval(_sub_state);
  
  ofPopMatrix();
  
  
}

