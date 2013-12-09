//
//  CyrilUniformOp.h
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#ifndef __cyril__CyrilUniformOp__
#define __cyril__CyrilUniformOp__

#include "Cyril.h"

class CyrilUniformOp : public Cyril {
protected:
  string n;
  Cyril* e;
public:
  CyrilUniformOp(string _s, Cyril* _e);
  CyrilUniformOp (const CyrilUniformOp &other);
  virtual ~CyrilUniformOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual int matchPushPop() { return 0; }
};

#endif /* defined(__cyril__CyrilUniformOp__) */
