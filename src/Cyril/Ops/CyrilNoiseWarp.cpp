//
//  CyrilNoiseWarp.cpp
//  cyril
//
//  Created by Darren Mothersele on 12/09/2014.
//
//

#include "CyrilNoiseWarp.h"

CyrilNoiseWarp::CyrilNoiseWarp (Cyril* _e) : e(_e) {
  s = e->size();
  if (!(s == 3 || s == 0)) {
    // FREQ, AMP, SPEED
    yyerror("NoiseWarp FX command takes 0 or 3 arguments");
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
  float frequency, amplitude, speed;
  if (s == 3) {
    e->eval(_s);
    frequency = _s.stk->top();
    _s.stk->pop();
    amplitude = _s.stk->top();
    _s.stk->pop();
    speed = _s.stk->top();
    _s.stk->pop();
  }
  else {
    // same defaults as ofxPostProcessing:
    frequency = 4.0;
    amplitude = 0.1;
    speed = 0.1;
  }
  _s.noisewarp->setFrequency(frequency);
  _s.noisewarp->setAmplitude(amplitude);
  _s.noisewarp->setSpeed(speed);
}

