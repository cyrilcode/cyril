//
//  CyrilPush.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilPush_h
#define cyril2_CyrilPush_h


#include "cmds.h"

class CyrilPush : public Cyril {
  float f;
public:
  CyrilPush(float _f) : f(_f) {
    valid = true;
  }
  CyrilPush (const CyrilPush &other) {
    f = other.f;
  }
  virtual ~CyrilPush ()
  {
  }
  void print() {
    cout << "Push: " << f << endl;
  }
  virtual Cyril *clone () { return new CyrilPush (*this); }
  int size() { return 1; }
  float getValue() { return f; }
  virtual void eval(CyrilState &_s) {
    _s.stk->push(f);
  }
};



#endif
