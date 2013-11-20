//
//  CyrilLineOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilLineOp__
#define __cyril2__CyrilLineOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilLineOp : public CyrilOp {
public:
  CyrilLineOp(Cyril* _c);
  CyrilLineOp (const CyrilLineOp &other);
  virtual ~CyrilLineOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilLineOp__) */
