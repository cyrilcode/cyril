//
//  CyrilMoveOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilMoveOp__
#define __cyril2__CyrilMoveOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilMoveOp : public CyrilOp {
public:
  CyrilMoveOp(Cyril* _c);
  CyrilMoveOp (const CyrilMoveOp &other);
  virtual ~CyrilMoveOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};



#endif /* defined(__cyril2__CyrilMoveOp__) */
