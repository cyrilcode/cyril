//
//  CyrilDebugOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilDebugOp__
#define __cyril2__CyrilDebugOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilDebugOp : public CyrilOp {
public:
  CyrilDebugOp(Cyril* _c);
  CyrilDebugOp (const CyrilDebugOp &other);
  virtual ~CyrilDebugOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};
#endif /* defined(__cyril2__CyrilDebugOp__) */
