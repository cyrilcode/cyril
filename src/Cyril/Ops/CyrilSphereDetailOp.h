//
//  CyrilSphereDetailOp.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilSphereDetailOp__
#define __cyril2__CyrilSphereDetailOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilSphereDetailOp : public CyrilOp {
public:
  CyrilSphereDetailOp(Cyril* _c);
  CyrilSphereDetailOp (const CyrilSphereDetailOp &other);
  virtual ~CyrilSphereDetailOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilSphereDetailOp__) */
