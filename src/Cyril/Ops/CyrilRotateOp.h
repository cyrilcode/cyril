//
//  CyrilRotateOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilRotateOp__
#define __cyril2__CyrilRotateOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilRotateOp : public CyrilOp {
public:
  CyrilRotateOp(Cyril* _c);
  CyrilRotateOp (const CyrilRotateOp &other);
  virtual ~CyrilRotateOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilRotateOp__) */
