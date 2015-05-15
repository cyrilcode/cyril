//
//  Particle.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_Particle_h
#define cyril2_Particle_h

#include "ofMain.h"
#include "cmds.h"
#include "Cyril.h"
#include "CyrilState.h"

class Particle {
public:
  ofMatrix4x4 origin;
  ofMatrix4x4 location;
  ofVec3f velocity;
  ofVec3f acceleration;
  float health;
  float decay;
    Cyril* shape;
    CyrilState _sub_state;
  
  Particle (ofMatrix4x4 _o, ofVec3f _v, ofVec3f _a, float _h, float _d, Cyril* _s) :
  origin(_o), velocity(_v), acceleration(_a), health(_h), decay(_d), shape(_s) {
      
      _sub_state.stk = new stack<float>;
      _sub_state.ms = new ofMatrixStack(*ofGetWindowPtr());
      _sub_state.ps = new vector<Particle*>;
      _sub_state.sym = new map<int, float>;
      _sub_state.cs = new map<int, Palette *>;
      _sub_state.img = new map<int, ofImage *>;
      (*_sub_state.sym)[REG_PARTICLE_HEALTH] = health;
      (*_sub_state.sym)[REG_PARTICLE_DECAY] = decay;
  }
  ~Particle();
  void update() {
    velocity += acceleration;
    location.translate(velocity);
    health -= decay;
  }
  void draw(CyrilState * _s);
  static bool isDead(Particle *&p) {
    return p->health <= 0;
  }
};



#endif
