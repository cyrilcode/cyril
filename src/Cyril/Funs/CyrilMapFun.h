//
//  CyrilMapFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilMapFun__
#define __cyril2__CyrilMapFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilMapFun : public CyrilFun {
public:
  CyrilMapFun(Cyril* _c);
  CyrilMapFun(const CyrilMapFun &other);
  virtual ~CyrilMapFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilMapFun__) */
