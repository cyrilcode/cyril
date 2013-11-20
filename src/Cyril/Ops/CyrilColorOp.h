//
//  CyrilColorOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilColorOp__
#define __cyril2__CyrilColorOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilColorOp : public CyrilOp {
public:
  CyrilColorOp(Cyril* _c);
  CyrilColorOp (const CyrilColorOp &other);
  virtual ~CyrilColorOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilColorOp__) */
