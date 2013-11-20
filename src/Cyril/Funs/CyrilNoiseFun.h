//
//  CyrilNoiseFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilNoiseFun__
#define __cyril2__CyrilNoiseFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilNoiseFun : public CyrilFun {
public:
  CyrilNoiseFun(Cyril* _c);
  CyrilNoiseFun(const CyrilNoiseFun &other);
  virtual ~CyrilNoiseFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilNoiseFun__) */
