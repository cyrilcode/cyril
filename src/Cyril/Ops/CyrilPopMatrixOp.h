//
//  CyrilPopMatrix.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilPopMatrix__
#define __cyril2__CyrilPopMatrix__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilPopMatrixOp : public CyrilOp {
public:
  CyrilPopMatrixOp(Cyril* _c);
  CyrilPopMatrixOp (const CyrilPopMatrixOp &other);
  virtual ~CyrilPopMatrixOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual int matchPushPop();
};

#endif /* defined(__cyril2__CyrilPopMatrix__) */
