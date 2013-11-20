//
//  CyrilUnaryOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilUnaryOp_h
#define cyril2_CyrilUnaryOp_h

#include "cmds.h"


class CyrilUnaryOp : public Cyril {
  string o;
  int op;
  Cyril* e;
public:
  CyrilUnaryOp(string _o, Cyril* _e) : o(_o), e(_e) {
    valid = e->valid;
    if ("!" == o) {
      op = OP_NOT;
      if (e->size() != 1) {
        yyerror("Operand to ! should be 1 value");
        valid = false;
      }
    }
    else {
      yyerror("Unknown operation");
      valid = false;
    }
  }
  CyrilUnaryOp (const CyrilUnaryOp &other) {
    o = other.o;
    e = other.e->clone ();
  }
  virtual ~CyrilUnaryOp ()
  {
    delete e;
  }
  void print() {
    e->print();
    cout << "Unary: " << o << endl;
  }
  virtual Cyril *clone () { return new CyrilUnaryOp (*this); }
  virtual int size() { return 1; }
  virtual void eval(CyrilState &_s) {
    e->eval(_s);
    float v1 = _s.stk->top();
    _s.stk->pop();
    switch (op) {
      case OP_NOT:
        if (v1 > 0) {
          _s.stk->push(0);
        }
        else {
          _s.stk->push(1);
        }
        break;
      default:
        _s.stk->push(0);
        cout << "Warning unknown unary operator " << op << endl;
    }
  }
};

#endif
