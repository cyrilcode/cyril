//
//  CyrilScaleOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilScaleOp__
#define __cyril2__CyrilScaleOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilScaleOp : public CyrilOp {
public:
  CyrilScaleOp(Cyril* _c);
  CyrilScaleOp (const CyrilScaleOp &other);
  virtual ~CyrilScaleOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilScaleOp__) */
