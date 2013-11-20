//
//  CyrilImgOp.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilImgOp__
#define __cyril2__CyrilImgOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilImgOp : public CyrilOp {
public:
  CyrilImgOp(Cyril* _c);
  CyrilImgOp (const CyrilImgOp &other);
  virtual ~CyrilImgOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilImgOp__) */
