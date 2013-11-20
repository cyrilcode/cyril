//
//  CyrilBallDetailOp.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilBallDetailOp__
#define __cyril2__CyrilBallDetailOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilBallDetailOp : public CyrilOp {
public:
  CyrilBallDetailOp(Cyril* _c);
  CyrilBallDetailOp (const CyrilBallDetailOp &other);
  virtual ~CyrilBallDetailOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilBallDetailOp__) */
