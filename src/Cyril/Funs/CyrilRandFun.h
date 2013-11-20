//
//  CyrilRandFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilRandFun__
#define __cyril2__CyrilRandFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilRandFun : public CyrilFun {
public:
  CyrilRandFun(Cyril* _c);
  CyrilRandFun(const CyrilRandFun &other);
  virtual ~CyrilRandFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilRandFun__) */
