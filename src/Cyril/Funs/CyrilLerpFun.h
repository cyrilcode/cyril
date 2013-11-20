//
//  CyrilLerpFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilLerpFun__
#define __cyril2__CyrilLerpFun__

#include "ofMain.h"
#include "CyrilFun.h"
#include "Palette.h"

class CyrilLerpFun : public CyrilFun {
public:
  CyrilLerpFun(Cyril* _c);
  CyrilLerpFun(const CyrilLerpFun &other);
  virtual ~CyrilLerpFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilLerpFun__) */
