//
//  CyrilIf.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilIf_h
#define cyril2_CyrilIf_h

#include "cmds.h"


class CyrilIf : public Cyril {
  Cyril* e;
  Cyril* c;
public:
  CyrilIf(Cyril* _e, Cyril* _c) : e(_e), c(_c) {
    valid = e->valid && c->valid;
    if (_e->size() != 1) {
      yyerror("Incorrect size of expression in if condition");
      valid = false;
    }
  }
  CyrilIf (const CyrilIf &other) {
    e = other.e->clone ();
    c = other.c->clone ();
  }
  virtual ~CyrilIf ()
  {
    delete e;
    delete c;
  }
  void print() {
    c->print();
    e->print();
    cout << "If: " << endl;
  }
  virtual Cyril *clone () { return new CyrilIf (*this); }
  virtual int size() { return 0; }
  virtual void eval(CyrilState &_s) {
    e->eval(_s);
    float b = _s.stk->top();
    _s.stk->pop();
    if (b > 0) {
      c->eval(_s);
    }
  }
  virtual int matchPushPop() { return c->matchPushPop(); }
};

#endif
