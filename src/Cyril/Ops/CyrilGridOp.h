//
//  CyrilGridOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilGridOp__
#define __cyril2__CyrilGridOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilGridOp : public CyrilOp {
public:
  CyrilGridOp(Cyril* _c);
  CyrilGridOp (const CyrilGridOp &other);
  virtual ~CyrilGridOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilGridOp__) */
