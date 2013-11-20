//
//  CyrilNamedColor.h
//  Cyril
//
//  Created by Darren Mothersele on 18/11/2013.
//
//

#ifndef Cyril_CyrilNamedColor_h
#define Cyril_CyrilNamedColor_h


#include "cmds.h"

extern map < string, ofColor > colorNameMap;


class CyrilNamedColor : public Cyril {
  string s;
  float r,g,b;
public:
  
  CyrilNamedColor(const char * _s) : s(_s) {
    
    ofColor c = colorNameMap[s];
    
    r = c.r;
    g = c.g;
    b = c.b;
    //cout << "Debug color: " << r << "," << g << "," << b << endl;
    valid = true;
  }
  CyrilNamedColor (const CyrilNamedColor &other) {
    s = other.s;
  }
  virtual ~CyrilNamedColor ()
  {
  }
  void print() {
    cout << "Named color: " << s << endl;
  }
  virtual Cyril *clone () { return new CyrilNamedColor (*this); }
  virtual int size() { return 3; }
  virtual void eval(CyrilState &_s) {
    _s.stk->push(r);
    _s.stk->push(g);
    _s.stk->push(b);
  }
};


#endif
