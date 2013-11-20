//
//  CyrilTanFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilTanFun__
#define __cyril2__CyrilTanFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilTanFun : public CyrilFun {
public:
  CyrilTanFun(Cyril* _c);
  CyrilTanFun(const CyrilTanFun &other);
  virtual ~CyrilTanFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilTanFun__) */
