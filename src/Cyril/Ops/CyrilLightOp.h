//
//  CyrilLightOp.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilLightOp__
#define __cyril2__CyrilLightOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilLightOp : public CyrilOp {
public:
  CyrilLightOp(Cyril* _c);
  CyrilLightOp (const CyrilLightOp &other);
  virtual ~CyrilLightOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilLightOp__) */
