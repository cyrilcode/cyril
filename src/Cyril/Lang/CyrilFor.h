//
//  CyrilFor.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilFor_h
#define cyril2_CyrilFor_h
#include "CyrilState.h"

#include "cmds.h"

class CyrilFor : public Cyril {
  int loc;
  Cyril* e1;
  Cyril* e2;
  Cyril* e3;
  float step;
  Cyril* c;
public:
  CyrilFor(int _i, Cyril* _e1, Cyril* _e2, Cyril* _e3, Cyril* _c)
  : loc(_i), e1(_e1), e2(_e2), e3(_e3), c(_c) {
    valid = e1->valid && e2->valid && e3->valid && c->valid;
    if (_e1->size() != 1 || _e2->size() != 1 || _e3->size() != 1) {
      yyerror("Incorrect size of expression in for loop");
      valid = false;
    }
    CyrilPush *sC = dynamic_cast<CyrilPush*>(e3);
    if (sC == NULL) {
      yyerror("Step of FOR loop must be a number");
      valid = false;
    }
    else {
      step = sC->getValue();
    }
  }
  CyrilFor (const CyrilFor &other) {
    loc = other.loc;
    e1 = other.e1->clone ();
    e2 = other.e2->clone ();
    e3 = other.e3->clone ();
    c = other.c->clone ();
  }
  virtual ~CyrilFor ()
  {
    delete e1;
    delete e2;
    delete e3;
    delete c;
  }
  void print() {
    e1->print();
    e2->print();
    e3->print();
    c->print();
    cout << "For: " << loc << endl;
  }
  virtual Cyril *clone () { return new CyrilFor (*this); }
  virtual int size() { return 0; }
  virtual void eval(CyrilState &_s) {    e1->eval(_s);
    (*_s.sym)[loc] = _s.stk->top();
    _s.stk->pop();
    float limit;
    e2->eval(_s);
    limit = _s.stk->top();
    _s.stk->pop();
    while ((*_s.sym)[loc] < limit) {
      c->eval(_s);
      (*_s.sym)[loc] += step;
    }
  }
  virtual int matchPushPop() { return c->matchPushPop(); }
};

#endif
