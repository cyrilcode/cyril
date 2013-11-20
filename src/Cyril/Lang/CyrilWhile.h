//
//  CyrilWhile.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilWhile_h
#define cyril2_CyrilWhile_h

#include "cmds.h"

class CyrilWhile : public Cyril {
  Cyril* e;
  Cyril* c;
public:
  CyrilWhile(Cyril* _e, Cyril* _c) : e(_e), c(_c) {
    valid = e->valid && c->valid;
    if (_e->size() != 1) {
      yyerror("Incorrect size of expression in while loop");
      valid = false;
    }
  }
  CyrilWhile (const CyrilWhile &other) {
    e = other.e->clone ();
    c = other.c->clone ();
  }
  virtual ~CyrilWhile ()
  {
    delete e;
    delete c;
  }
  void print() {
    c->print();
    e->print();
    cout << "While: " << endl;
  }
  virtual Cyril *clone () { return new CyrilWhile (*this); }
  virtual int size() { return 0; }
  virtual void eval(CyrilState &_s) {
    float test;
    e->eval(_s);
    test = _s.stk->top();
    _s.stk->pop();
    while (test > 0) {
      c->eval(_s);
      e->eval(_s);
      test = _s.stk->top();
      _s.stk->pop();
    }
  }
  virtual int matchPushPop() { return c->matchPushPop(); }
};



#endif
