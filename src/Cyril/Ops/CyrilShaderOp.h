//
//  CyrilShaderOp.h
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#ifndef __cyril__CyrilShaderOp__
#define __cyril__CyrilShaderOp__

#include "Cyril.h"

class CyrilShaderOp : public Cyril {
protected:
  int n;
  Cyril* c;
public:
  CyrilShaderOp(int _i, Cyril* _c);
  CyrilShaderOp (const CyrilShaderOp &other);
  virtual ~CyrilShaderOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual int matchPushPop() { return c->matchPushPop(); }
};


#endif /* defined(__cyril__CyrilShaderOp__) */
