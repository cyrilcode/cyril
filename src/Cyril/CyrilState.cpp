//
//  CyrilState.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilState.h"
#include "Particle.h"
#include "Palette.h"
#include "CyrilParser.h"
#include "cyrilApp.h"

CyrilState::CyrilState(map<int, float> * _t,
                       stack<float> * _s, ofMatrixStack * _m, vector<Particle*> * _p, map<int, Palette*> * _c,
                        map<int, ofImage*> * _i, CyrilState * _pr)
: sym(_t), stk(_s), ms(_m), ps(_p), cs(_c), img(_i), parent(_pr)
{
  
}

CyrilState::CyrilState() {
  
}


void CyrilState::setDefaults() {
  (*sym)[REG_X_MAX] = 640;
  (*sym)[REG_Y_MAX] = 480;
  (*sym)[REG_X_MID] = (*sym)[REG_X_MAX] / 2.0;
  (*sym)[REG_Y_MID] = (*sym)[REG_Y_MAX] / 2.0;
  
  (*sym)[REG_X_SCALE] = 100;
  (*sym)[REG_Y_SCALE] = 100;
  (*sym)[REG_Z_SCALE] = 100;
  
  (*sym)[REG_PI] = PI;
  (*sym)[REG_TWO_PI] = TWO_PI;
  
  (*sym)[REG_PARTICLE_HEALTH] = 1;
  (*sym)[REG_PARTICLE_DECAY] = 0.1;
  
  (*sym)[REG_FRAME] = 0;
}

void CyrilState::init() {
  stk = new stack<float>;
  
  // Initialise our own matrix stack
  // TODO: replace with call to get from current renderer?
  ms = new ofMatrixStack(*ofGetWindowPtr());
  
  // Initialise empty paticle system
  ps = new vector<Particle*>;
  
  // Initialise empty variable/register map
  sym = new map<int, float>;
  
  // Initialise palettes
  cs = new map<int, Palette *>;
  
  // Initialise sprites
  img = new map<int, ofImage *>;
  
  parent = NULL;
  light = new ofLight();
  //_state.light = NULL;
  
  shaders = new map<int, CyrilShader*>;
  
  (*shaders)[0] = new CyrilShader("noise");
  (*shaders)[0]->load("shaders/noise.vert", "shaders/noise.frag");
  (*shaders)[0]->setInitProg(CyrilParser::parseFile("shaders/noise.cy"));
  
  //shaders[0] = new CyrilShader();
  
}

void CyrilState::evaluateShaderUniforms(CyrilState *_global) {
  for (map<int, CyrilShader*>::iterator i = shaders->begin(); i != shaders->end(); ++i) {
    (*i).second->evalUniforms((*i).first, _global);
  }
}

void CyrilState::printShaders() {
  for (map<int, CyrilShader*>::iterator i = shaders->begin(); i != shaders->end(); ++i) {
    cout << (*i).first << ": ";
    (*i).second->print();
    cout << endl;
  }
}

void CyrilState::printState() {
  cout << sym->size() << " symbols" << endl;
  cout << shaders->size() << " shaders" << endl;
}

void CyrilState::update(bool _reset, ofxBeat &beat) {
  
  // If passed the reset signal then reset timers
  if (_reset) {
    (*sym)[REG_FRAME] = 0;
    ofResetElapsedTimeCounter();
  }
  else {
    (*sym)[REG_FRAME]++;
  }
  
  // Update timing registers
  (*sym)[REG_TIME] = ofGetElapsedTimeMillis();
  (*sym)[REG_SECS] = ofGetElapsedTimef();
  (*sym)[REG_FAST] = ofGetElapsedTimef() * 10;
  (*sym)[REG_SLOW] = ofGetElapsedTimef() * 2;
  
  // For beat detection
  beat.update((*sym)[REG_TIME]);
  (*sym)[REG_BEAT_MAGNITUDE] = beat.getMagnitude();
  (*sym)[REG_BEAT_KICK] = beat.kick();
  (*sym)[REG_BEAT_SNARE] = beat.snare();
  (*sym)[REG_BEAT_HIHAT] = beat.hihat();
  for (int i = REG_BEAT_FFT_START; i < REG_BEAT_FFT_MAX; ++i) {
    (*sym)[i] = beat.getBand(i - REG_BEAT_FFT_START);
  }
  
  // Update mouse position
  (*sym)[REG_MOUSE_X] = (ofGetAppPtr()->mouseX - (*sym)[REG_X_MID]);
  (*sym)[REG_MOUSE_Y] = (ofGetAppPtr()->mouseY - (*sym)[REG_Y_MID]);
  (*sym)[REG_MOUSE_ON] = ((cyrilApp *)ofGetAppPtr())->mouseOn;
}

void CyrilState::resize(int w, int h) {
  (*sym)[REG_X_MAX] = w;
  (*sym)[REG_Y_MAX] = h;
  (*sym)[REG_X_MID] = w / 2.0;
  (*sym)[REG_Y_MID] = h / 2.0;
}

void CyrilState::lightsOn() {
  light->enable();
  // The default position of the light (apply z-scale)
  light->setPosition(0,0,1000);
}
void CyrilState::lightsOff() {
  light->disable();
}

CyrilState::~CyrilState () {
  delete sym;
  delete stk;
  delete ms;
  while(!ps->empty()) delete ps->back(), ps->pop_back();
  delete ps;
  for(map<int, Palette*>::iterator it = cs->begin(); it != cs->end(); ++it){
    delete (*it).second;
  }
  delete cs;
  for(map<int, ofImage*>::iterator it = img->begin(); it != img->end(); ++it){
    delete (*it).second;
  }
  delete img;
  /*
  if (light != NULL)
    delete light;
  */
}
/*
CyrilState::CyrilState (const CyrilState &other) {
  
}
CyrilState::CyrilState *clone () {
  
}
*/