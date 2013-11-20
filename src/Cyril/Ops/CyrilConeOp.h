//
//  CyrilConeOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilConeOp__
#define __cyril2__CyrilConeOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilConeOp : public CyrilOp {
public:
  CyrilConeOp(Cyril* _c);
  CyrilConeOp (const CyrilConeOp &other);
  virtual ~CyrilConeOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilConeOp__) */
