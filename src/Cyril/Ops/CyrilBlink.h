//
//  CyrilBlink.h
//  cyril2
//
//  Created by Darren Mothersele on 07/11/2013.
//
//

#ifndef __cyril2__CyrilBlink__
#define __cyril2__CyrilBlink__

#include "ofMain.h"
#include "Cyril.h"

class CyrilBlink : public Cyril {
  Cyril* e;
  Cyril* c;
public:
  CyrilBlink(Cyril* _e, Cyril* _c);
  CyrilBlink (const CyrilBlink &other);
  virtual ~CyrilBlink ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual int matchPushPop() { return c->matchPushPop(); }
};

#endif /* defined(__cyril2__CyrilBlink__) */
