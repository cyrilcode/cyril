//
//  CyrilState.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilState__
#define __cyril2__CyrilState__

#include "ofMain.h"
#include "cmds.h"
#include "EditorBuffer.h"
#include "ofxBeat.h"

#include "CyrilShader.h"
//class CyrilShader;

class Particle;
class Palette;

class CyrilState : public EditorState {
public:
  void init();
  void setDefaults();
  void update(bool _reset, ofxBeat &beat);
  void resize(int w, int h);
  void lightsOn();
  void lightsOff();
  
  void printState();
  void printShaders();
  
  map<int, float> * sym;
  stack<float> * stk;
  ofMatrixStack * ms;
  vector<Particle*> * ps;
  map<int, Palette*> * cs;
  map<int, ofImage*> * img;
  CyrilState * parent;
  ofLight * light;
  map<int, CyrilShader*> * shaders;
  
  CyrilState(map<int, float> * _t,
             stack<float> * _s, ofMatrixStack * _m, vector<Particle*> * _p,
             map<int, Palette*> * _c,  map<int, ofImage*> * _i, CyrilState *);
  CyrilState();
  ~CyrilState ();
  //CyrilState (const CyrilState &other);
  //CyrilState *clone ();
  
  void evaluateShaderUniforms(CyrilState *_global);
};

#endif /* defined(__cyril2__CyrilState__) */
