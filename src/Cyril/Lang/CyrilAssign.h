//
//  CyrilAssign.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilAssign_h
#define cyril2_CyrilAssign_h

#include "cmds.h"

class CyrilAssign : public Cyril {
  int loc;
  Cyril* c;
public:
  CyrilAssign(int _i, Cyril* _c) : loc(_i), c(_c) {
    valid = c->valid;
    int sz = _c->size();
    if (!(sz == 1 || sz == 3)) {
      yyerror("Assignment requires 1 argument (or 3 for color)");
      valid = false;
    }
  }
  CyrilAssign (const CyrilAssign &other) {
    loc = other.loc;
    c = other.c->clone ();
  }
  virtual ~CyrilAssign ()
  {
    delete c;
  }
  void print() {
    c->print();
    cout << "Assign: " << loc << endl;
  }
  virtual Cyril *clone () { return new CyrilAssign (*this); }
  virtual int size() { return 0; }
  virtual void eval(CyrilState &_s) {
    c->eval(_s);
    switch (c->size()) {
      case 1:
        (*_s.sym)[loc] = _s.stk->top();
        _s.stk->pop();
        break;
      case 3:
        float b = _s.stk->top(); _s.stk->pop();
        float g = _s.stk->top(); _s.stk->pop();
        float r = _s.stk->top(); _s.stk->pop();
        (*_s.sym)[loc] = ofColor(r, g, b).getHex();
        break;
    }
  }
  virtual int matchPushPop() { return c->matchPushPop(); }
};

#endif
