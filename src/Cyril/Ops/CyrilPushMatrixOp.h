//
//  CyrilPushMatrixOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilPushMatrixOp__
#define __cyril2__CyrilPushMatrixOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilPushMatrixOp : public CyrilOp {
public:
  CyrilPushMatrixOp(Cyril* _c);
  CyrilPushMatrixOp (const CyrilPushMatrixOp &other);
  virtual ~CyrilPushMatrixOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual int matchPushPop();
};

#endif /* defined(__cyril2__CyrilPushMatrixOp__) */
