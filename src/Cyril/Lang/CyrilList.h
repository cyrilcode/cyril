//
//  CyrilList.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilList_h
#define cyril2_CyrilList_h

#include "cmds.h"

class CyrilList : public Cyril {
  Cyril* c1;
  Cyril* c2;
public:
  CyrilList(Cyril* _c1, Cyril* _c2) : c1(_c1), c2(_c2) {
    valid = c1->valid && c2->valid;
  }
  CyrilList (const CyrilList &other) {
    c1 = other.c1->clone ();
    c2 = other.c2->clone ();
  }
  virtual ~CyrilList ()
  {
    delete c1;
    delete c2;
  }
  void print() {
    c1->print();
    c2->print();
  }
  virtual Cyril *clone () { return new CyrilList (*this); }
  virtual int size() { return c1->size() + c2->size(); }
  virtual void update(CyrilState &_s) {
    c1->update(_s);
    c2->update(_s);
  }
  virtual void eval(CyrilState &_s) {
    c1->eval(_s);
    c2->eval(_s);
  }
  virtual int matchPushPop() {
    return c1->matchPushPop() + c2->matchPushPop();
  }
};


#endif
