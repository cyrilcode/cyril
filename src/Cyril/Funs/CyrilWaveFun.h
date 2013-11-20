//
//  CyrilWaveFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilWaveFun__
#define __cyril2__CyrilWaveFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilWaveFun : public CyrilFun {
public:
  CyrilWaveFun(Cyril* _c);
  CyrilWaveFun (const CyrilWaveFun &other);
  virtual ~CyrilWaveFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilWaveFun__) */
