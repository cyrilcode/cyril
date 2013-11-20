//
//  CyrilNoNoFillOp.h
//  Cyril
//
//  Created by Darren Mothersele on 14/11/2013.
//
//

#ifndef __Cyril__CyrilNoNoFillOp__
#define __Cyril__CyrilNoNoFillOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilNoFillOp : public CyrilOp {
public:
  CyrilNoFillOp(Cyril* _c);
  CyrilNoFillOp (const CyrilNoFillOp &other);
  virtual ~CyrilNoFillOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__Cyril__CyrilNoNoFillOp__) */
