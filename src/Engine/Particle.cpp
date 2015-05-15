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
  
  _sub_state.parent = _s;
  
  shape->eval(_sub_state);
  
  ofPopMatrix();
  
  
}

