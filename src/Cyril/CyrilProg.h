//
//  CyrilProg.h
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#ifndef __cyril__CyrilProg__
#define __cyril__CyrilProg__

#include "cmds.h"
#include "Cyril.h"

class CyrilProg : public Cyril {
  Cyril* c;
public:
  CyrilProg(Cyril* _c) : c(_c) {
    valid = c->valid;
  }
  CyrilProg (const CyrilProg &other) {
    c = other.c->clone ();
  }
  virtual ~CyrilProg ()
  {
    delete c;
  }
  void print() {
    c->print();
  }
  virtual Cyril *clone () { return new CyrilProg (*this); }
  virtual int size() { return c->size(); }
  virtual void eval(CyrilState &_s);
  virtual int matchPushPop() {
    return c->matchPushPop();
  }
};

#endif /* defined(__cyril__CyrilProg__) */
