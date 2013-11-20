//
//  CyrilBallOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilBallOp__
#define __cyril2__CyrilBallOp__

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilBallOp : public CyrilOp {
public:
  CyrilBallOp(Cyril* _c);
  CyrilBallOp (const CyrilBallOp &other);
  virtual ~CyrilBallOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};
#endif /* defined(__cyril2__CyrilBallOp__) */
