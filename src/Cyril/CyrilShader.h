//
//  CyrilShader.h
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#ifndef __cyril__CyrilShader__
#define __cyril__CyrilShader__

#include "ofMain.h"
#include "Cyril.h"

class CyrilState;

class CyrilShader : public ofShader {
  Cyril *progU;
  string vert;
  string frag;
  string name;
public:
  CyrilShader(string _n) : name(_n), ofShader(), progU(new Cyril()) { }
  void setInitProg(Cyril *_p) {
    progU = _p;
  }
  void evalUniforms(int i, CyrilState *_s);
  bool setupShaderFromSource(GLenum type, string source);
  void print();
  string getText(int _t);
  void load(string _s1, string _s2);
};


#endif /* defined(__cyril__CyrilShader__) */
