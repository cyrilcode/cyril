//
//  CyrilInitOp.h
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#ifndef __Cyril__CyrilInitOp__
#define __Cyril__CyrilInitOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilInitOp : public CyrilOp {
public:
  CyrilInitOp(Cyril* _c);
  CyrilInitOp (const CyrilInitOp &other);
  virtual ~CyrilInitOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__Cyril__CyrilInitOp__) */
