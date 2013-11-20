//
//  CyrilFillOp.h
//  Cyril
//
//  Created by Darren Mothersele on 14/11/2013.
//
//

#ifndef __Cyril__CyrilFillOp__
#define __Cyril__CyrilFillOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilFillOp : public CyrilOp {
public:
  CyrilFillOp(Cyril* _c);
  CyrilFillOp (const CyrilFillOp &other);
  virtual ~CyrilFillOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__Cyril__CyrilFillOp__) */
