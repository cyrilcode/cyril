//
//  CyrilHsbFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilHsbFun__
#define __cyril2__CyrilHsbFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilHsbFun : public CyrilFun {
public:
  CyrilHsbFun(Cyril* _c);
  CyrilHsbFun(const CyrilHsbFun &other);
  virtual ~CyrilHsbFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilHsbFun__) */
