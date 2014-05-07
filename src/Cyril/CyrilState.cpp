//
//  CyrilState.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilState.h"

CyrilState::CyrilState(map<int, float> * _t,
                       stack<float> * _s, ofMatrixStack * _m, vector<Particle*> * _p, map<int, Palette*> * _c,
                        map<int, ofImage*> * _i, CyrilState * _pr)
: sym(_t), stk(_s), ms(_m), ps(_p), cs(_c), img(_i), parent(_pr)
{
  
}

CyrilState::CyrilState() {
  
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