//
//  CyrilSinFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilSinFun__
#define __cyril2__CyrilSinFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilSinFun : public CyrilFun {
public:
  CyrilSinFun(Cyril* _c);
  CyrilSinFun(const CyrilSinFun &other);
  virtual ~CyrilSinFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};



#endif /* defined(__cyril2__CyrilSinFun__) */
