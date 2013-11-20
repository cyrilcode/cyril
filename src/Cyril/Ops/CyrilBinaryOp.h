//
//  CyrilBinaryOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilBinaryOp_h
#define cyril2_CyrilBinaryOp_h

#include "cmds.h"


class CyrilBinaryOp : public Cyril {
  string o;
  int op;
  Cyril* e1;
  Cyril* e2;
public:
  CyrilBinaryOp(string _o, Cyril* _e1, Cyril* _e2) : o(_o), e1(_e1), e2(_e2) {
    valid = e1->valid && e2->valid;
    if ("+" == o) {
      op = OP_PLUS;
      if (e1->size() != 1) {
        yyerror("Left operand to + should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to + should be 1 value");
        valid = false;
      }
    }
    else if ("-" == o) {
      op = OP_MINUS;
      if (e1->size() != 1) {
        yyerror("Left operand to - should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to - should be 1 value");
        valid = false;
      }
    }
    else if ("/" == o) {
      op = OP_DIV;
      if (e1->size() != 1) {
        yyerror("Left operand to / should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to / should be 1 value");
        valid = false;
      }
    }
    else if ("*" == o) {
      op = OP_MULT;
      if (e1->size() != 1) {
        yyerror("Left operand to * should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to * should be 1 value");
        valid = false;
      }
    }
    else if ("%" == o) {
      op = OP_MOD;
      if (e1->size() != 1) {
        yyerror("Left operand to % should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to % should be 1 value");
        valid = false;
      }
    }
    else if ("==" == o) {
      op = OP_EQ;
      if (e1->size() != 1) {
        yyerror("Left operand to == should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to == should be 1 value");
        valid = false;
      }
    }
    else if ("!=" == o) {
      op = OP_NOTEQ;
      if (e1->size() != 1) {
        yyerror("Left operand to != should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to != should be 1 value");
        valid = false;
      }
    }
    else if ("<" == o) {
      op = OP_LESS;
      if (e1->size() != 1) {
        yyerror("Left operand to < should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to < should be 1 value");
        valid = false;
      }
    }
    else if ("<=" == o) {
      op = OP_LESSEQ;
      if (e1->size() != 1) {
        yyerror("Left operand to <= should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to <= should be 1 value");
        valid = false;
      }
    }
    else if (">" == o) {
      op = OP_GR;
      if (e1->size() != 1) {
        yyerror("Left operand to > should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to > should be 1 value");
        valid = false;
      }
    }
    else if (">=" == o) {
      op = OP_GREQ;
      if (e1->size() != 1) {
        yyerror("Left operand to >= should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to >= should be 1 value");
        valid = false;
      }
    }
    else if ("&" == o) {
      op = OP_AND;
      if (e1->size() != 1) {
        yyerror("Left operand to AND should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to AND should be 1 value");
        valid = false;
      }
    }
    else if ("|" == o) {
      op = OP_OR;
      if (e1->size() != 1) {
        yyerror("Left operand to OR should be 1 value");
        valid = false;
      }
      if (e2->size() != 1) {
        yyerror("Right operand to OR should be 1 value");
        valid = false;
      }
    }
    else {
      yyerror("Unknown operation");
      valid = false;
    }
  }
  CyrilBinaryOp (const CyrilBinaryOp &other) {
    o = other.o;
    e1 = other.e1->clone ();
    e2 = other.e2->clone ();
  }
  virtual ~CyrilBinaryOp ()
  {
    delete e1;
    delete e2;
  }
  void print() {
    e1->print();
    e2->print();
    cout << "Binary: " << o << endl;
  }
  virtual Cyril *clone () { return new CyrilBinaryOp (*this); }
  virtual int size() { return 1; }
  virtual void eval(CyrilState &_s) {
    e1->eval(_s);
    float v1 = _s.stk->top();
    _s.stk->pop();
    e2->eval(_s);
    float v2 = _s.stk->top();
    _s.stk->pop();
    switch (op) {
      case OP_MINUS:
        _s.stk->push(v1 - v2);
        break;
      case OP_PLUS:
        _s.stk->push(v1 + v2);
        break;
      case OP_MULT:
        _s.stk->push(v1 * v2);
        break;
      case OP_DIV:
        if (v2 == 0) {
          cout << "Warning: divide by 0" << endl;
          _s.stk->push(0);
        }
        else {
          _s.stk->push(v1 / v2);
        }
        break;
      case OP_MOD:
        if (v2 == 0) {
          cout << "Warning: divide(mod) by 0" << endl;
          _s.stk->push(0);
        }
        else {
          _s.stk->push(int(v1) % int(v2));
        }
        break;
      case OP_EQ:
        if (v1 == v2) {
          _s.stk->push(1);
        }
        else {
          _s.stk->push(0);
        }
        break;
      case OP_NOTEQ:
        if (v1 != v2) {
          _s.stk->push(1);
        }
        else {
          _s.stk->push(0);
        }
        break;
      case OP_LESS:
        if (v1 < v2) {
          _s.stk->push(1);
        }
        else {
          _s.stk->push(0);
        }
        break;
      case OP_LESSEQ:
        if (v1 <= v2) {
          _s.stk->push(1);
        }
        else {
          _s.stk->push(0);
        }
        break;
      case OP_GR:
        if (v1 > v2) {
          _s.stk->push(1);
        }
        else {
          _s.stk->push(0);
        }
        break;
      case OP_GREQ:
        if (v1 >= v2) {
          _s.stk->push(1);
        }
        else {
          _s.stk->push(0);
        }
        break;
      case OP_AND:
        if (v1 > 0 && v2 > 0) {
          _s.stk->push(1);
        }
        else {
          _s.stk->push(0);
        }
        break;
      case OP_OR:
        if (v1 > 0 || v2 > 0) {
          _s.stk->push(1);
        }
        else {
          _s.stk->push(0);
        }
        break;
      default:
        _s.stk->push(0);
        cout << "Warning unknown operator " << op << endl;
    }
  }
};


#endif
