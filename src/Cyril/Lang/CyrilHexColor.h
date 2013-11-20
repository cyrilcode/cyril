//
//  CyrilHexColor.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilHexColor_h
#define cyril2_CyrilHexColor_h


#include "cmds.h"


class CyrilHexColor : public Cyril {
  string s;
  float r,g,b;
public:
  CyrilHexColor(const char * _s) : s(_s) {
    string converter(s);
    stringstream sr(converter.substr(0,2));
    stringstream sg(converter.substr(2,2));
    stringstream sb(converter.substr(4,2));
    int ir, ig, ib;
    sr >> hex >> ir;
    sg >> hex >> ig;
    sb >> hex >> ib;
    r = ir; g = ig; b = ib;
    //cout << "Debug color: " << r << "," << g << "," << b << endl;
    valid = true;
  }
  CyrilHexColor (const CyrilHexColor &other) {
    s = other.s;
  }
  virtual ~CyrilHexColor ()
  {
  }
  void print() {
    cout << "Hex: " << s << endl;
  }
  virtual Cyril *clone () { return new CyrilHexColor (*this); }
  virtual int size() { return 3; }
  virtual void eval(CyrilState &_s) {
    _s.stk->push(r);
    _s.stk->push(g);
    _s.stk->push(b);
  }
};


#endif
