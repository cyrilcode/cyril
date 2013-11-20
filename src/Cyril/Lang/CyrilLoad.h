//
//  CyrilLoad.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilLoad_h
#define cyril2_CyrilLoad_h

#include "cmds.h"


class CyrilLoad : public Cyril {
  int loc;
public:
  CyrilLoad(int _i) : loc(_i) {
    valid = true;
  }
  CyrilLoad (const CyrilLoad &other) {
    loc = other.loc;
  }
  virtual ~CyrilLoad ()
  {
  }
  void print() {
    cout << "Load: " << loc << endl;
  }
  virtual Cyril *clone () { return new CyrilLoad (*this); }
  virtual int size() { return 1; }
  virtual void eval(CyrilState &_s) {
    //cout << "Load " << loc << ": " << (*_s.sym)[loc] << endl;
    //cout << _s.sym->count(loc) << endl;
    _s.stk->push((*_s.sym)[loc]);
  }
};


#endif
