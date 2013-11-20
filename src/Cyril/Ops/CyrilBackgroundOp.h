//
//  CyrilBackgroundOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilBackgroundOp__
#define __cyril2__CyrilBackgroundOp__

#include "ofMain.h"
#include "CyrilOp.h"
#include "Palette.h"

class CyrilBackgroundOp : public CyrilOp {
public:
  CyrilBackgroundOp(Cyril* _c);
  CyrilBackgroundOp (const CyrilBackgroundOp &other);
  virtual ~CyrilBackgroundOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilBackgroundOp__) */
