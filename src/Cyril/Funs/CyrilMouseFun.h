//
//  CyrilMouseFun.h
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#ifndef __cyril__CyrilMouseFun__
#define __cyril__CyrilMouseFun__

#include "ofMain.h"
#include "CyrilFun.h"

class CyrilMouseFun : public CyrilFun {
public:
  CyrilMouseFun(Cyril* _c);
  CyrilMouseFun (const CyrilMouseFun &other);
  virtual ~CyrilMouseFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril__CyrilMouseFun__) */
