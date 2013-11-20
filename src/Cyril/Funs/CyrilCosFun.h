//
//  CyrilCosFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilCosFun__
#define __cyril2__CyrilCosFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilCosFun : public CyrilFun {
public:
  CyrilCosFun(Cyril* _c);
  CyrilCosFun(const CyrilCosFun &other);
  virtual ~CyrilCosFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilCosFun__) */
