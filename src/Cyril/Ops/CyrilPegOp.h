//
//  CyrilPegOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilPegOp__
#define __cyril2__CyrilPegOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilPegOp : public CyrilOp {
public:
  CyrilPegOp(Cyril* _c);
  CyrilPegOp (const CyrilPegOp &other);
  virtual ~CyrilPegOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilPegOp__) */
