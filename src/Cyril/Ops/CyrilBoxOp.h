//
//  CyrilBoxOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilBoxOp__
#define __cyril2__CyrilBoxOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilBoxOp : public CyrilOp {
public:
  CyrilBoxOp(Cyril* _c);
  CyrilBoxOp (const CyrilBoxOp &other);
  virtual ~CyrilBoxOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilBoxOp__) */
