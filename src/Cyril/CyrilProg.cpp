//
//  CyrilProg.cpp
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#include "CyrilProg.h"
#include "CyrilState.h"


void CyrilProg::eval(CyrilState &_s) {
  
  ofPushMatrix();
  ofPushStyle();
  ofTranslate((*_s.sym)[REG_X_MID], (*_s.sym)[REG_Y_MID]);
  _s.ms->pushMatrix();
  _s.ms->translate((*_s.sym)[REG_X_MID], (*_s.sym)[REG_Y_MID]);
  
  ofScale((*_s.sym)[REG_X_SCALE], (*_s.sym)[REG_Y_SCALE], (*_s.sym)[REG_Z_SCALE]);
  _s.ms->scale((*_s.sym)[REG_X_SCALE], (*_s.sym)[REG_Y_SCALE], (*_s.sym)[REG_Z_SCALE]);
  
  c->eval(_s);
  
  _s.ms->popMatrix();
  ofPopStyle();
  ofPopMatrix();

}
