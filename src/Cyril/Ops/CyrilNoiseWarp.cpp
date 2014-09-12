//
//  CyrilNoiseWarp.cpp
//  cyril
//
//  Created by Darren Mothersele on 12/09/2014.
//
//

#include "CyrilNoiseWarp.h"

CyrilNoiseWarp::CyrilNoiseWarp (Cyril* _e) : e(_e) {
  int s = e->size();
  if (!(s == 3)) {
    // FREQ, AMP, SPEED
    yyerror("NoiseWarp FX command takes 3 arguments");
    valid = false;
  }
}

CyrilNoiseWarp::CyrilNoiseWarp (const CyrilNoiseWarp &other) {
  e = other.e->clone ();
}
CyrilNoiseWarp::~CyrilNoiseWarp ()
{
}
void CyrilNoiseWarp::print() {
  cout << "NoiseWarp" << endl;
}
Cyril * CyrilNoiseWarp::clone () {
  return new CyrilNoiseWarp (*this);
}
int CyrilNoiseWarp::size() {
  return 0;
}
void CyrilNoiseWarp::update(CyrilState &_s) {
  // FX_NOISE_WARP = 1
  _s.post[1]->enable();
}
void CyrilNoiseWarp::eval(CyrilState &_s) {
  e->eval(_s);
  float frequency = _s.stk->top();
  _s.stk->pop();
  float amplitude = _s.stk->top();
  _s.stk->pop();
  float speed = _s.stk->top();
  _s.stk->pop();
  _s.noisewarp->setFrequency(frequency);
  _s.noisewarp->setAmplitude(amplitude);
  _s.noisewarp->setSpeed(speed);
}

